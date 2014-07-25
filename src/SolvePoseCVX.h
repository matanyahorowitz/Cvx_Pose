//
//  SolvePoseCVX.h
//  
//
//  Created by Matanya Horowitz on 7/17/14.
//
//

#ifndef ____SolvePoseCVX__
#define ____SolvePoseCVX__

#include <iostream>
#include "PoseEstimate.h"
#include "common.h"
#include <sdpa_call.h>

class SolvePoseCVX : public PoseEstimate
{
public:
    SolvePoseCVX();
    ~SolvePoseCVX();
    void estimatePose();
    void setDecomposition( int method ); //0 ADMM
    //void setModel(pcl::PointCloud<PointT>::Ptr model);
private:
   void singleSolver();
   void multiSolvers();
   void initializeSolver();
   int decomp_method;
   void initSDPAConsMatrix( int k, int l );
   SDPA sdpa;
   void setupQuadraticObjective();
   void setupRConstraint();
   void setupLinearObjective();
};

#endif /* defined(____SolvePoseCVX__) */
