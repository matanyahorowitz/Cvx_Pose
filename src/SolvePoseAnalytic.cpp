//  Created by Matanya Horowitz on 7/17/14.

#include "SolvePoseAnalytic.h"
#include <iostream>

/** Constructor, sets default parameters. */
SolvePoseAnalytic::SolvePoseAnalytic() : PoseEstimate()
{ 
    this->decomp_method = 0;
}

/** Destructor, currently not implemented. [Todo]: Memory leaks are possible. */
SolvePoseAnalytic::~SolvePoseAnalytic()
{
    //PoseEstimate::~PoseEstimate();
}

/** Implementation of the analytic pose estimation algorithm. */
void SolvePoseAnalytic::estimatePose()
{
    dbg("estimate pose");
    
    //First, move over by the centroid
    T = obs_center - model_center;

    //The problem is now an estimation over SO(3)
    
    if( settings.cores == 1 )
    {
        this->singleSolver();
    } else {
        this->multiSolvers();
    }
}

/** Analytic solution to pose estimation when only a single computational unit is
active. 

\sa multiSolvers() */
void SolvePoseAnalytic::singleSolver()
{
    Eigen::Matrix3f data = obs*model.transpose();
    std::cout << "data matrix:\n" << data << "\n";
    Eigen::Matrix4f data_adj;
    this->adjoint(data,data_adj);
    std::cout << "data adjoint:\n" << data_adj << "\n";
    Eigen::EigenSolver<Eigen::Matrix4f> eig(data_adj);
    std::cout << "Eigenvectors calculated\n";
    Eigen::Vector4f eigVals = eig.eigenvalues().real();
    Eigen::Vector4f::Index maxEigLoc;
    std::cout << "Getting max eigenvalue\n";
    eigVals.maxCoeff(&maxEigLoc);
    
    std::cout << "max location: " << maxEigLoc << ", getting max eigenvector\n";
    Eigen::Vector4f maxVec = eig.eigenvectors().real().block<4,1>(0,maxEigLoc);
    std::cout << "Eigen values:\n" << eigVals << "\nmaximal eigenvector: \n" << maxVec << "\n";
    Eigen::Matrix4f z = maxVec*maxVec.transpose();
    std::cout << "z: \n" << z << "\n";
    this->z2so(z,R);
    std::cout << "R: \n" << R << "\n";
}

/** Transformation from 4D representation of SO(3) convex hull to element in SO(3).
@param[in] z Object in lifted co[SO(3)] representation.
@param[out] r Element in co(SO)
*/

void SolvePoseAnalytic::z2so( Eigen::Matrix4f & z, Eigen::Matrix3f & r )
{
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            r(i,j) = (A[i][j].transpose() * z).trace();
        }
    }
}

/** Pose estimation with multiple computation units. OpenMP allows for estimation to
be done over subsets of the data. At each iteration the local estimates are combined
via an ADMM update over relaxation parameters. See "A Convex Approach to Consensus on SO(n)" by Matni and Horowitz for details.
*/
void SolvePoseAnalytic::multiSolvers()
{
   int max_iter = 100;
   float alpha = 1.5f;
   float alphainv = 1.0f/alpha;

   Eigen::Matrix4f Z[settings.cores], Y[settings.cores], 
                   Zn[settings.cores], Yn[settings.cores], 
                   Z0, Z0n;

   //Initialize variables
   Eigen::Matrix4f sdata[settings.cores];
   Eigen::VectorXf split;
   split.setLinSpaced( settings.cores, 0, num_pts );
   
   omp_set_num_threads(settings.cores);

   #pragma omp parallel for
   for( int i=0; i < settings.cores; i++ )
   {
      DMat sobs = obs.block(3, split(i+1) - split(i),0,split(i));
      DMat smodel = model.block(3, split(i+1) - split(i),0,split(i));
      
      Eigen::Matrix3f rdata = sobs*smodel.transpose();
      adjoint(rdata, sdata[i]);
   
      Y[i].setZero(); Z[i].setZero();
      Yn[i].setZero(); Zn[i].setZero();
   }

   Z0.setZero(); Z0n.setZero();

   for( int i=0; i < max_iter; i++ )
   {
      //Update Zn
      #pragma omp parallel for
      for( int k=0; k<settings.cores; k++ )
      {
         ADMMIter( sdata[i], Zn[k], Y[k], Z0, alphainv );
      }

      //Gather and update Z0
      Eigen::Matrix4f Q0;
      Q0.setZero();

      for(int k=0; k<settings.cores; k++)
      {
         Q0 = Q0 + alphainv * Y[k] + Zn[k];
      }

      Eigen::EigenSolver<Eigen::Matrix4f> eig(Q0);
      Eigen::Vector4f eigVals = eig.eigenvalues().real();
      Eigen::Matrix4f eigVecs = eig.eigenvectors().real();
      projFreeSpectra(eigVals);
      Z0n = eigVecs * eigVals.asDiagonal() * eigVecs.transpose();

      //Update the dual Yn's
      for( int k=0; k<settings.cores; k++ )
      {
         Yn[k] = Y[k] + alpha*(Zn[k] - Z0n);

         Y[k] = Yn[k];
         Z[k] = Zn[k];
      }
      Z0 = Z0n;

      if( (Z0 - Z0n).squaredNorm() < settings.tolerance )
         break;
   }
}

/** Single local ADMM pose estimation step.

[Todo] Make inline for speed.

@param[in]  dadj The adjoint of the local data matrix
@param[out] Zn The local Z optimization variable
@param[in]  Y The local dual price variable
@param[in]  Z0 Centralized fusion variable
@param[in]  ainv The inverse of the ADMM gradient variable.
*/
void SolvePoseAnalytic::ADMMIter(Eigen::Matrix4f & dadj, Eigen::Matrix4f & Zn, Eigen::Matrix4f & Y, Eigen::Matrix4f & Z0 ,float ainv) {
    Eigen::Matrix4f Q = ainv * (dadj - Y) + Z0;
    Eigen::EigenSolver<Eigen::Matrix4f> eig(Q);
    Eigen::Vector4f eigVals = eig.eigenvalues().real();
    Eigen::Matrix4f eigVecs = eig.eigenvectors().real();
    projFreeSpectra(eigVals);
    Zn = eigVecs * eigVals.asDiagonal() * eigVecs.transpose();
}

/** Projection onto the free spectrahedra.
@param[in,out] v Vector to be projected. Overwritten with the result.
*/
void SolvePoseAnalytic::projFreeSpectra(Eigen::Vector4f & v)
{
   Eigen::Vector4f s = v;
   bool bget = false;
   std::sort(s.data(), s.data() + s.size());
   float tmpsum = 0.f;
   float tmax;

   for( int i=0; i<3; i++ ) {
      tmpsum = tmpsum + s(i);
      tmax = (tmpsum - 1)/i;
      if( tmax >= s(i+1) ) {
         bget = true;
         break;
      }
   }

   if( !bget )
      tmax = (tmpsum + s(3) - 1)/4;

   s.setConstant(-tmax);
   v += s;
   v.cwiseMax(s.setZero());
}

/** In the future, dual ascent may be implemented as an alternative to ADMM.
*/
void SolvePoseAnalytic::DualIter() {
   //Dual ascent would go here.   
}

/** Calculate the adjoint of the mapping between SO(3) and its four dimensional lift.
@param[in] D Data matrix to be adjointed.
@param[out] Dadj The adjoint of the data matrix.
*/
void SolvePoseAnalytic::adjoint( Eigen::Matrix3f & D, Eigen::Matrix4f & Dadj )
{
    Dadj.setZero();
    
    for( int i=0; i<3; i++ ) {
        for( int j=0; j<3; j++ ) {
            Dadj += A[i][j] * D(i,j);
        }
    }
}
