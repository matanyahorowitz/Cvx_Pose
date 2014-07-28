//  Created by Matanya Horowitz on 7/17/14.

#include "SolvePoseCVX.h"

//Todo: Get rid of these
#include <cstdio>
#include <cstdlib>

/** Constructor, which sets default solution parameters */
SolvePoseCVX::SolvePoseCVX() : PoseEstimate()
{
   this->decomp_method = 0;
   this->cores = 1;
}

/** Destructor, which isn't currently implemented. [Todo] There may be memory leaks. */
SolvePoseCVX::~SolvePoseCVX()
{
    //PoseEstimate::~PoseEstimate();
}

/** Initialize the convex solver and parameters. The presence of outlier rejection requires different initialization (there are many more optimization variables).
*/
void SolvePoseCVX::initializeSolver()
{

   SDPA::printSDPAVersion(stdout);
   sdpa.setParameterType(SDPA::PARAMETER_DEFAULT);
   sdpa.printParameters(stdout);
   
   //This is in the SDPA "standard (not dual-standard)" form

   if( settings.outlierRejection )
   {
      sdpa.inputConstraintNumber(num_pts*6 + 13);
      sdpa.inputBlockNumber(3);
      sdpa.inputBlockSize(1,4);
      sdpa.inputBlockSize(2,3*num_pts+1);
      sdpa.inputBlockSize(3,-6*num_pts);
      sdpa.inputBlockType(1,SDPA::SDP);
      sdpa.inputBlockType(2,SDPA::SDP);
      sdpa.inputBlockType(3,SDPA::SDP);
      sdpa.initializeUpperTriangleSpace();
      setupRConstraint();
      setupQuadraticObjective();
   }
   else
   {
      sdpa.inputConstraintNumber(3);
      sdpa.inputBlockNumber(1);
      sdpa.inputBlockSize(1,4);
      sdpa.inputBlockType(1,SDPA::SDP);
      sdpa.initializeUpperTriangleSpace();
      setupRConstraint();
      setupLinearObjective();
   }
}

/** Sets up the optimization with a quadratic objective. This is necessary when there is an L1 penalty or the point to plane metric is used. Note that the quadratic objective does not guarantee the solution will be an element of SO(3). */
void SolvePoseCVX::setupQuadraticObjective()
{
   int R[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
   
   //First block setup by setupRConstraint()   
   
   for( int i=0; i<num_pts; i++ )
   {
      int xi = i*3;
      int yi = i*3 + 1;
      int zi = i*3 + 2;
   
      //Second block
   
      //Identity on second block in F_0
      sdpa.inputElement( 0, 2, xi, xi, 1 );
      sdpa.inputElement( 0, 2, yi, yi, 1 );
      sdpa.inputElement( 0, 2, zi, zi, 1 );

      //Observation offset on second block in F_0
      sdpa.inputElement( 0, 2, xi, num_pts+1, obs(0,i) );
      sdpa.inputElement( 0, 2, yi, num_pts+1, obs(1,i) );
      sdpa.inputElement( 0, 2, zi, num_pts+1, obs(2,i) );

      sdpa.inputElement( 0, 2, num_pts+1, xi, obs(0,i) );
      sdpa.inputElement( 0, 2, num_pts+1, yi, obs(1,i) );
      sdpa.inputElement( 0, 2, num_pts+1, zi, obs(2,i) );

      //Rotation of model on second block
      for( int j=0; j<3; j++ ) {
         for( int k=0; k<3; k++ ) {
            sdpa.inputElement( R[j][k], 2, i*3 + k, num_pts+1, -model(k,i) );
            sdpa.inputElement( R[j][k], 2, num_pts+1, i*3 + k, -model(k,i) );
         }
      }

      //Translation of model on second block
      int T1 = 10, T2 = 11, T3 = 12;
      sdpa.inputElement( T1, 2, xi, num_pts+1, 1 );
      sdpa.inputElement( T2, 2, yi, num_pts+1, 1 );
      sdpa.inputElement( T3, 2, zi, num_pts+1, 1 );
      sdpa.inputElement( T1, 2, num_pts+1, xi, 1 );
      sdpa.inputElement( T2, 2, num_pts+1, yi, 1 );
      sdpa.inputElement( T3, 2, num_pts+1, zi, 1 );

      //Objective slack variable gamma
      int g = 13;
      sdpa.inputElement( g, 2, num_pts+1, num_pts+1, 1 );

      //Outlier component
      int zp = 14 + 3*i, zm = 14 + num_pts*3 + 3*i;
      
      for( int j=0; j<3; j++ )
      {
         sdpa.inputElement( zp+j, 2, i*3 + j, num_pts+1, -1 );
         sdpa.inputElement( zm+j, 2, i*3 + j, num_pts+1, 1 );
         
         sdpa.inputElement( zp+j, 2, num_pts+1, i*3 + j, -1 );
         sdpa.inputElement( zm+j, 2, num_pts+1, i*3 + j, 1 );
      }

      int zcp = -1 + 4 + 3*num_pts + 1;
      int zcm = zcp + 3*num_pts;

      //Third block
      for( int j=0; j<3; j++ )
      {
         sdpa.inputElement( zp+j, 3, zcp + j, zcp + j, 1 );
         sdpa.inputElement( zm+j, 3, zcm + j, zcm + j, 1 );
      }

      //L1 penalty in objective
      for( int j=0; j<3; j++ )
      {
         sdpa.inputCVec( zp+j, 1 );
         sdpa.inputCVec( zm+j, 1 );
      }
   }

   //Set objective weighting vs the L1 penalty (which has weight one)
   float objWeight = 1.0f*num_pts;

   sdpa.inputCVec(13, 1); //gamma
}

/** Sets up the CO(SO(3)) constraint.
*/
void SolvePoseCVX::setupRConstraint()
{
   //\sum{i,j =1...3} A_ij X_ij \preceq I_4
   //F_{i,j} = -A_ij X_ij
   for( int k=0; k<3; k++ )
      for( int l=0; l<3; l++ )
         initSDPAConsMatrix(k,l);

   //Set F_0 = Id
   sdpa.inputElement( 0, 1, 1, 1, 1 );
   sdpa.inputElement( 0, 1, 2, 2, 1 );
   sdpa.inputElement( 0, 1, 3, 3, 1 );
   sdpa.inputElement( 0, 1, 4, 4, 1 );
}

/** Utility function to encode the A_{i,j} constraints.

\sa setupRConstraint()
*/
void SolvePoseCVX::initSDPAConsMatrix( int k, int l )
{
   for( int i=0; i<4; i++ )
      for( int j=0; j<4; j++ )
         if( A[i][j](k,l) != 0 )
            sdpa.inputElement( 1 + k*3 + l, 1, i, j, -A[i][j](k,l) );
}

/** Sets up the linear objective. Note that this objective produces solutions
guaranteed to be elements of SO(3), but does not allow for the point to plane
metric or outlier rejection to be incorporated.
*/
void SolvePoseCVX::setupLinearObjective()
{
   Eigen::Matrix3f data = obs*model.transpose();
   sdpa.inputCVec(1, data(0,0));
   sdpa.inputCVec(2, data(1,0));
   sdpa.inputCVec(3, data(2,0));  
   sdpa.inputCVec(4, data(0,1));  
   sdpa.inputCVec(5, data(1,1));  
   sdpa.inputCVec(6, data(2,1));  
   sdpa.inputCVec(7, data(0,2));  
   sdpa.inputCVec(8, data(1,2));  
   sdpa.inputCVec(9, data(2,2));
}

/** Solve the SDP with only a single computation element.

[Todo] Initial guesses are currently ignored (no warm start).
*/
void SolvePoseCVX::singleSolver()
{
     //Todo: Setup initial guess
  
   sdpa.solve();
   
   double* solution = sdpa.getResultXVec();
   for( int i=0; i<3; i++ )
   {
      for( int j=0; j<3; j++ )
      {
         R(i,j) = solution[i*3 + j];
      }
   }
}

/** Performs the pose estimation using an SDP */
void SolvePoseCVX::estimatePose()
{
   this->initializeSolver();

   T = obs_center - model_center;

   if( this->cores == 1 )
      this->singleSolver();
   else
      this->multiSolvers();
}

/** Unimplemented [Todo] parallelization of the SDP using ADMM and OpenMP. */
void SolvePoseCVX::multiSolvers()
{
}

/** Set the decomposition. I don't remember what this is for [Todo]. */
void SolvePoseCVX::setDecomposition( int method )
{
   this->decomp_method = method;
}
