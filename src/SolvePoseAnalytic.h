//
//  SolvePoseAnalytic.h
//  
//
//  Created by Matanya Horowitz on 7/17/14.
//
//

#ifndef ____SolvePoseAnalytic__
#define ____SolvePoseAnalytic__

#include <iostream>
class SolvePoseAnalytic : public PoseEstimate
{
public:
    void estimatePose();
    void setDecomposition( int method ); //0 ADMM, 1 dual decomposition
private:
    void singleSolver();
    void multiSolver();
    Eigen::Matrix3f A[3][3];
    int decomp_method;
    void ADMMIter();
    void DualIter();
};

#endif /* defined(____SolvePoseAnalytic__) */
