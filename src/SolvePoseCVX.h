
#ifndef ____SolvePoseCVX__
#define ____SolvePoseCVX__

#include <iostream>
#include "PoseEstimate.h"
#include "common.h"
#include <sdpa_call.h>

/** Pose estimation using the convex hull of SO(3) via a semidefinite program. The semidefinite formulation allows us to include the point to plane metric as well as outlier rejection using a LASSO penalty. Currently, the publicly available SDPA package is used as our semidefinite solver.

\author Matanya Horowitz
\date July 28 2014
*/

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
   void setupQuadraticObjective();
   void setupRConstraint();
   void setupLinearObjective();
   
   /** SDPA interface for numerically solving the convex problem */
   SDPA sdpa;
};

#endif /* defined(____SolvePoseCVX__) */
