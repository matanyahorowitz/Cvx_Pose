//
//  SolvePoseAnalytic.h
//  
//
//  Created by Matanya Horowitz on 7/17/14.
//
//

#ifndef ____SolvePoseAnalytic__
#define ____SolvePoseAnalytic__

#include "common.h"
#include "PoseEstimate.h"
#include <iostream>

class SolvePoseAnalytic : public PoseEstimate
{
public:
    SolvePoseAnalytic();
    ~SolvePoseAnalytic();
    void estimatePose();
    void setDecomposition( int method ); //0 ADMM, 1 dual decomposition
private:
    void singleSolver();
    void multiSolvers();
    int decomp_method;
    void ADMMIter();
    void DualIter();
    void adjoint( Eigen::Matrix3f & D, Eigen::Matrix4f & Dadj );
    void z2so( Eigen::Matrix4f & z, Eigen::Matrix3f & r );
};

#endif /* defined(____SolvePoseAnalytic__) */
