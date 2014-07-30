#ifndef ____SolvePoseAnalytic__
#define ____SolvePoseAnalytic__

#include "common.h"
#include "PoseEstimate.h"
#include <iostream>
#include <omp.h>

/** Pose estimation using analytic solutions to optimization problems over the 
convex hull of SO(3). Unfortunately, analytic solutions are only available for 
the point to point metric and in the absence of outlier rejection.

Parallelization is achieved by splitting the data over a number of cores and
using ADMM to achieve consensus over the different computation units.

\author Matanya Horowitz
\date July 28, 2014
*/

class SolvePoseAnalytic : public PoseEstimate
{
public:
    SolvePoseAnalytic();
    ~SolvePoseAnalytic();
    void estimatePose();
    void setDecomposition( int method ); //0 ADMM, 1 dual decomposition
    void setup();
private:
    void singleSolver();
    void multiSolvers();
    int decomp_method;
    void ADMMIter(Eigen::Matrix4f & dadj, Eigen::Matrix4f & Zn, Eigen::Matrix4f & Y, Eigen::Matrix4f & Z0 ,float ainv);
    void DualIter();
    void adjoint( Eigen::Matrix3f & D, Eigen::Matrix4f & Dadj );
    void z2so( Eigen::Matrix4f & z, Eigen::Matrix3f & r );
    void projFreeSpectra(Eigen::Vector4f & v);
};

#endif /* defined(____SolvePoseAnalytic__) */
