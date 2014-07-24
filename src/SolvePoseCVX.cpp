//
//
//  SolvePoseCVX.cpp
//  
//
//  Created by Matanya Horowitz on 7/17/14.
//
//

#include "SolvePoseCVX.h"

//Todo: Get rid of these
#include <cstdio>
#include <cstdlib>

SolvePoseCVX::SolvePoseCVX() : PoseEstimate()
{
   this->decomp_method = 0;
   this->cores = 1;

   this->initializeSolver();
}

SolvePoseCVX::~SolvePoseCVX()
{
    //PoseEstimate::~PoseEstimate();
}

void SolvePoseCVX::initializeSolver()
{
   int m=9; //number of primal variables x_i
   int nBlock=1; //number of blocks
   int blockStruct = 4;

   SDPA::printSDPAVersion(stdout);
   sdpa.setParameterType(SDPA::PARAMETER_DEFAULT);
   sdpa.printParameters(stdout);
   
   //This is in the SDPA "standard (not dual-standard)" form.
   
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

void SolvePoseCVX::initSDPAConsMatrix( int k, int l )
{
   for( int i=0; i<4; i++ )
      for( int j=0; j<4; j++ )
         if( A[i][j](k,l) != 0 )
            sdpa.inputElement( 1 + k*3 + l, 1, i, j, -A[i][j](k,l) );
}

void SolvePoseCVX::singleSolver()
{
   Eigen::Matrix3f data = obs*model.transpose();
   sdpa.inputCVec(1, data(1,1));
   sdpa.inputCVec(2, data(2,1));
   sdpa.inputCVec(3, data(3,1));  
   sdpa.inputCVec(4, data(1,2));  
   sdpa.inputCVec(5, data(2,2));  
   sdpa.inputCVec(6, data(3,2));  
   sdpa.inputCVec(7, data(1,3));  
   sdpa.inputCVec(8, data(2,3));  
   sdpa.inputCVec(9, data(3,3));

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

void SolvePoseCVX::estimatePose()
{
   T = obs_center - model_center;

   if( this->cores == 1 )
      this->singleSolver();
   else
      this->multiSolvers();
}

void SolvePoseCVX::multiSolvers()
{
}

void SolvePoseCVX::setDecomposition( int method )
{
   this->decomp_method = method;
}
