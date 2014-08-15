//  Created by Matanya Horowitz on 7/17/14.

#include "SolvePoseCVX.h"

//Todo: Get rid of these
#include <cstdio>
#include <cstdlib>

/** Constructor, which sets default solution parameters */
SolvePoseCVX::SolvePoseCVX() : PoseEstimate()
{
}

/** Destructor, which isn't currently implemented. [Todo] There may be memory leaks. */
SolvePoseCVX::~SolvePoseCVX()
{
    //PoseEstimate::~PoseEstimate();
}

void SolvePoseCVX::setModel( pcl::PointCloud<PointT>::Ptr model ) {
   PoseEstimate::setModel( model );
   
   if( settings.metric == 2 )
   {
      //pcl::NormalEstimationOMP<PointT, pcl::Normal> ne;
      pcl::NormalEstimation<PointT, pcl::Normal> ne;

      ne.setInputCloud( model );
      pcl::search::KdTree<PointT>::Ptr tree (new pcl::search::KdTree<PointT> () );
      ne.setSearchMethod( tree );

      pcl::PointCloud<pcl::Normal>::Ptr cloud_normals(new pcl::PointCloud<pcl::Normal>);

      //set vertex neighborhood size
      ne.setRadiusSearch(0.03); //3cm
      ne.compute(*cloud_normals);

      model_normals = cloud_normals->getMatrixXfMap( 3, 4, 0 );
   }
}

/** Overwrites PoseEstimate function to add solver initialization 
@param[in] set The desired solver settings. 
**/
void SolvePoseCVX::setSettings( SolverSettings & set ) {
   PoseEstimate::setSettings( set );
}

void SolvePoseCVX::setup() {
   initializeSolver();
}
/** Initialize the convex solver and parameters. The presence of outlier rejection 
    requires different initialization (there are many more optimization variables).
*/
void SolvePoseCVX::initializeSolver()
{
   SDPA::printSDPAVersion(stdout);
   sdpa.setParameterType(SDPA::PARAMETER_DEFAULT);
   sdpa.printParameters(stdout);
   sdpa.setDisplay(stdout);
   
   //This is in the SDPA "standard (not dual-standard)" form

   if( settings.metric == 2 )
   {
      if( settings.outlierRejection )
      {
         dbg( "Settings: Point to plane with outlier rejection" );
         sdpa.inputConstraintNumber( 2*num_pts + 13 );
         sdpa.inputBlockNumber( 3 );
         sdpa.inputBlockSize( 1, 4 );
         sdpa.inputBlockSize( 2, num_pts + 1 );
         sdpa.inputBlockSize( 3, -2*num_pts );
          
         sdpa.inputBlockType( 1, SDPA::SDP );
         sdpa.inputBlockType( 2, SDPA::SDP );
         sdpa.inputBlockType( 3, SDPA::LP );
      } 
      else 
      {
         dbg( "Settings: Point to plane w/out outlier rejection" );
         sdpa.inputConstraintNumber( 13 );
         sdpa.inputBlockNumber( 2 );
         sdpa.inputBlockSize( 1, 4 );
         sdpa.inputBlockSize( 2, num_pts + 1 );
         sdpa.inputBlockType( 1, SDPA::SDP );
         sdpa.inputBlockType( 2, SDPA::SDP );
      }
      sdpa.initializeUpperTriangleSpace();
      setupRConstraint();
      setupPointToPlane();

   }
   else if( settings.outlierRejection == 0)
   {
      dbg( "Settings: Point to point w/ outlier rejection" );
      sdpa.inputConstraintNumber(num_pts*6 + 13);
      sdpa.inputBlockNumber(3);
      sdpa.inputBlockSize(1,4);
      sdpa.inputBlockSize(2,3*num_pts+1);
      sdpa.inputBlockSize(3,-6*num_pts);
      sdpa.inputBlockType(1,SDPA::SDP);
      sdpa.inputBlockType(2,SDPA::SDP);
      sdpa.inputBlockType(3,SDPA::LP);
      sdpa.initializeUpperTriangleSpace();
      setupRConstraint();
      setupQuadraticObjective();
   }
   else
   {
      dbg( "Settings: Point to point w/out outlier rejection" );
      sdpa.inputConstraintNumber(9);
      sdpa.inputBlockNumber(1);
      sdpa.inputBlockSize(1,4);
      sdpa.inputBlockType(1,SDPA::SDP);
      sdpa.initializeUpperTriangleSpace();
      setupRConstraint();
      setupLinearObjective();
   }

   dbg( "Beginning SDPA initialization" );
   sdpa.initializeUpperTriangle();
   sdpa.initializeSolve();

   dbg( "SDPA initialization complete" );
}

void SolvePoseCVX::setupPointToPlane()
{
   dbg ("Setting up point to plane metric" );
   int R[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

   for( int i=0; i<num_pts; i++ )
   {
      Eigen::Vector3f n = model_normals.col(i);
      //Identity on second block along diagonal
      sdpa.inputElement( 0, 2, i, i, 1 );

      //Observation offset
      sdpa.inputElement( 0, 2, i, num_pts+1, obs.col(i).transpose()*n );
      sdpa.inputElement( 0, 2, num_pts+1, i, obs.col(i).transpose()*n );
      
      //Rotation of model
      for( int j=0; j<3; j++ )
      {
         for( int k=0; k<3; k++ )
         {
            sdpa.inputElement( R[j][k], 2, i, num_pts+1, n(j) * model(k,i) );
            sdpa.inputElement( R[j][k], 2, num_pts+1, i, n(j) * model(k,i) );
         }
      }

      //Translation of model
      int T[3] = {10, 11, 12};
      sdpa.inputElement( T[0], 2, i, num_pts+1, n(0) );
      sdpa.inputElement( T[1], 2, i, num_pts+1, n(1) );
      sdpa.inputElement( T[2], 2, i, num_pts+1, n(2) );

      sdpa.inputElement( T[0], 2, num_pts+1, i, n(0) );
      sdpa.inputElement( T[1], 2, num_pts+1, i, n(1) );
      sdpa.inputElement( T[2], 2, num_pts+1, i, n(2) );

      //Outlier relaxation
      if( settings.outlierRejection )
      {
         int zp = 13 + i;
         int zn = 13 + num_pts + i;

         sdpa.inputElement( zp, 2, i, num_pts+1, 1 );
         sdpa.inputElement( zn, 2, i, num_pts+1, -1 );

         sdpa.inputElement( zp, 2, num_pts+1, i, 1 );
         sdpa.inputElement( zn, 2, num_pts+1, i, -1 );

         //Penalize outliers in objective
         sdpa.inputCVec( zp, 1 );
         sdpa.inputCVec( zn, 1 );

         //Outlier slack variable constraints (absolute value)
         //Third block
         sdpa.inputElement( zp, 3, i, i, 1 );
         sdpa.inputElement( zn, 3, i+num_pts, i+num_pts, 1 );
      }
   }

   //Setup objective slack factor
   int g = 13;
   sdpa.inputElement( g, 2, num_pts+1, num_pts+1, 1 );


   //Set objective weighting vs the L1 penalty (which has weight one)
   float objWeight = 1.0f*num_pts;

   sdpa.inputCVec(13, objWeight); //gamma
   
}


/** Sets up the optimization with a quadratic objective. This is necessary when there is an L1 penalty or the point to plane metric is used. Note that the quadratic objective does not guarantee the solution will be an element of SO(3). */
void SolvePoseCVX::setupQuadraticObjective()
{
   dbg( "Setting up quadratic objective" );
   int R[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
   
   //First block setup by setupRConstraint()   

   for( int i=0; i<num_pts; i++ )
   {
      int xi = i*3 + 1;
      int yi = i*3 + 2;
      int zi = i*3 + 3;
   
      //Second block
   
      //Identity on second block in F_0
      sdpa.inputElement( 0, 2, xi, xi, 1 );
      sdpa.inputElement( 0, 2, yi, yi, 1 );
      sdpa.inputElement( 0, 2, zi, zi, 1 );

      //Observation offset on second block in F_0
      sdpa.inputElement( 0, 2, xi, 3*num_pts+1, obs(0,i) );
      sdpa.inputElement( 0, 2, yi, 3*num_pts+1, obs(1,i) );
      sdpa.inputElement( 0, 2, zi, 3*num_pts+1, obs(2,i) );

      sdpa.inputElement( 0, 2, 3*num_pts+1, xi, obs(0,i) );
      sdpa.inputElement( 0, 2, 3*num_pts+1, yi, obs(1,i) );
      sdpa.inputElement( 0, 2, 3*num_pts+1, zi, obs(2,i) );

      //Rotation of model on second block
      for( int j=0; j<3; j++ ) {
         for( int k=0; k<3; k++ ) {
            sdpa.inputElement( R[j][k], 2, i*3 + k + 1, 3*num_pts+1, -model(k,i) );
            sdpa.inputElement( R[j][k], 2, 3*num_pts+1, i*3 + k + 1, -model(k,i) );
         }
      }

      //Translation of model on second block
      int T1 = 10, T2 = 11, T3 = 12;
      sdpa.inputElement( T1, 2, xi, 3*num_pts+1, 1 );
      sdpa.inputElement( T2, 2, yi, 3*num_pts+1, 1 );
      sdpa.inputElement( T3, 2, zi, 3*num_pts+1, 1 );
      sdpa.inputElement( T1, 2, 3*num_pts+1, xi, 1 );
      sdpa.inputElement( T2, 2, 3*num_pts+1, yi, 1 );
      sdpa.inputElement( T3, 2, 3*num_pts+1, zi, 1 );

      //Objective slack variable gamma
      int g = 13;
      sdpa.inputElement( g, 2, 3*num_pts+1, 3*num_pts+1, 1 );

      //Outlier component
      int zp = 14 + 3*i, zm = 14 + num_pts*3 + 3*i;
      
      for( int j=0; j<3; j++ )
      {
         sdpa.inputElement( zp+j, 2, i*3 + j + 1, 3*num_pts+1, -1 );
         sdpa.inputElement( zm+j, 2, i*3 + j + 1, 3*num_pts+1, 1 );
         
         sdpa.inputElement( zp+j, 2, 3*num_pts+1, i*3 + j + 1, -1 );
         sdpa.inputElement( zm+j, 2, 3*num_pts+1, i*3 + j + 1, 1 );
      }

      int zcp = 3*i + 1;
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

   sdpa.inputCVec(13, objWeight); //gamma
}

/** Sets up the CO(SO(3)) constraint.
*/
void SolvePoseCVX::setupRConstraint()
{
   dbg( "Setting R SDP constraint" );
   //\sum{i,j =1...3} A_ij X_ij \preceq I_4
   //F_{i,j} = -A_ij X_ij
   for( int k=0; k<3; k++ )
      for( int l=0; l<3; l++ )
         initSDPAConsMatrix(k,l);

   dbg( "Done with R" );
   //Set F_0 = Id
   sdpa.inputElement( 0, 1, 1, 1, -1.f );
   sdpa.inputElement( 0, 1, 2, 2, -1.f );
   sdpa.inputElement( 0, 1, 3, 3, -1.f );
   sdpa.inputElement( 0, 1, 4, 4, -1.f );

   dbg( "done with R constant piece" );
}

/** Utility function to encode the A_{i,j} constraints.

\sa setupRConstraint()
*/
void SolvePoseCVX::initSDPAConsMatrix( int k, int l )
{
   dbg( "Setting up piece of R constraint" );
   for( int i=0; i<4; i++ )
   {
      for( int j=0; j<4; j++ )
      {   
         //if( A[k][l](i,j) != 0 )
            sdpa.inputElement(1 + k*3 + l, 1, 1+i, 1+j, A[k][l](i,j) );
      }
   }
}

/** Sets up the linear objective. Note that this objective produces solutions
guaranteed to be elements of SO(3), but does not allow for the point to plane
metric or outlier rejection to be incorporated.
*/
void SolvePoseCVX::setupLinearObjective()
{
   dbg( "Setting linear objective" );
   Eigen::Matrix3f data = -obs*model.transpose();

   std::cout << "Data matrix is: \n" << data << "\n";
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
  dbg( "Executing CVX solve" );
   sdpa.solve();
  dbg( "SDP computation complete"); 
   double* solution = sdpa.getResultXVec();
   for( int i=0; i<3; i++ )
   {
      for( int j=0; j<3; j++ )
      {
         R(i,j) = solution[j*3 + i];
      }
   }
}

/** Performs the pose estimation using an SDP */
void SolvePoseCVX::estimatePose()
{
   dbg( "Beginning pose estimation process" );
   this->initializeSolver();

   T = obs_center - model_center;
   std::cout << "calculated T: \n" << T << "\n";
   if( settings.cores == 1 )
      this->singleSolver();
   else
      this->multiSolvers();

   std::cout << "Calculated R: \n" << R << "\n";
}

/** Unimplemented [Todo] parallelization of the SDP using ADMM and OpenMP. */
void SolvePoseCVX::multiSolvers()
{
   dbg( "Error: In multisolvers, which is unimplemented" );
}

/** Set the decomposition. I don't remember what this is for [Todo]. */
void SolvePoseCVX::setDecomposition( int method )
{
   this->decomp_method = method;
}
