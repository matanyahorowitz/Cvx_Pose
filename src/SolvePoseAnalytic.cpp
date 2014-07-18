//
//  SolvePoseAnalytic.cpp
//  
//
//  Created by Matanya Horowitz on 7/17/14.
//
//

#include "SolvePoseAnalytic.h"

SolvePoseAnalytic::SolvePoseAnalytic()
{
    PoseEstimate::PoseEstimate();
    
    A[1][1] <<   1, 0, 0, 0,
                 0,-1, 0, 0,
                 0, 0,-1, 0,
                 0, 0, 0, 1;
    A[1][2] <<   0, 0,-1, 0,
                 0, 0, 0,-1,
                -1, 0, 0, 0,
                 0,-1, 0, 0;
    A[1][3] <<   0,-1, 0, 0,
                -1, 0, 0, 0,
                 0, 0, 0, 1,
                 0, 0, 1, 0;
    A[2][1] <<   0, 0, 1, 0,
                 0, 0, 0,-1,
                 1, 0, 0, 0,
                 0,-1, 0, 0;
    A[2][2] <<   1, 0, 0, 0,
                 0, 1, 0, 0,
                 0, 0,-1, 0,
                 0, 0, 0,-1;
    A[2][3] <<   0, 0, 0,-1,
                 0, 0,-1, 0,
                 0,-1, 0, 0,
                -1, 0, 0, 0;
    A[3][1] <<   0, 1, 0, 0,
                 1, 0, 0, 0,
                 0, 0, 0, 1,
                 0, 0, 1, 0;
    A[3][2] <<   0, 0, 0, 1,
                 0, 0,-1, 0,
                 0,-1, 0, 0,
                 1, 0, 0, 0;
    A[3][3] <<   1, 0, 0, 0,
                 0,-1, 0, 0,
                 0, 0, 1, 0,
                 0, 0, 0,-1;
    
    this->decomp_method = 0;
}

SolvePoseAnalytic::~SolvePoseAnalytic()
{
    PoseEstimate::~PoseEstimate();
}

void SolvePoseAnalytic::estimatePose()
{
    if( this->cores == 1 )
    {
        this->singleSolver();
    } else {
        this->multiSolver();
    }
}

private void SolvePoseAnalytic::singleSolver()
{
    Eigen::Matrix3f data = obs*model.transpose();
    Eigen::Matrix4f data_adj;
    this->adjoint(data,data_adj);
    EigenSolver<Matrix4f> eig(data_adj);
    
    Eigen::Vector4f eigVals = eig.eigenvalues();
    Eigen::Vector4f::Index maxEigLoc;
    eigVals.maxCoeff(&maxEigLoc);
    
    Eigen::Vector4f maxVec = eig.eigenvectors().block<4,1>(1,maxEigLoc);
    
    Eigen::Matrix4f z = maxVec*maxVec.transpose();
    this->z2so(z,R);
}

private void z2so( Eigen::Matrix4f z, Eigen::Matrix4f r )
{
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            r(i,j) = (A[i][j].transpose() * z).trace();
        }
    }
}

private void SolvePoseAnalytic::multiSolvers()
{
    
}

private void SolvePoseAnalytic::ADMMIter() {
    
}

private void SolvePoseAnalytic::DualIter() {
    
}

private void SolvePoseAnalytic::adjoint( Eigen::Matrix3f D, Eigen::Matrix4f & Dadj )
{
    Dadj.setZero();
    
    for( int i=0; i<3; i++ ) {
        for( int j=0; j<3; j++ ) {
            Dadj += D(i,j)*A[i,j];
        }
    }
}