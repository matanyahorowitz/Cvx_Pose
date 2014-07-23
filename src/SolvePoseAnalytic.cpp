//
//  SolvePoseAnalytic.cpp
//  
//
//  Created by Matanya Horowitz on 7/17/14.
//
//

#include "SolvePoseAnalytic.h"
#include <iostream>

SolvePoseAnalytic::SolvePoseAnalytic() : PoseEstimate()
{
    A[0][0] <<   1, 0, 0, 0,
                 0,-1, 0, 0,
                 0, 0,-1, 0,
                 0, 0, 0, 1;
    A[0][1] <<   0, 0,-1, 0,
                 0, 0, 0,-1,
                -1, 0, 0, 0,
                 0,-1, 0, 0;
    A[0][2] <<   0,-1, 0, 0,
                -1, 0, 0, 0,
                 0, 0, 0, 1,
                 0, 0, 1, 0;
    A[1][0] <<   0, 0, 1, 0,
                 0, 0, 0,-1,
                 1, 0, 0, 0,
                 0,-1, 0, 0;
    A[1][1] <<   1, 0, 0, 0,
                 0, 1, 0, 0,
                 0, 0,-1, 0,
                 0, 0, 0,-1;
    A[1][2] <<   0, 0, 0,-1,
                 0, 0,-1, 0,
                 0,-1, 0, 0,
                -1, 0, 0, 0;
    A[2][0] <<   0, 1, 0, 0,
                 1, 0, 0, 0,
                 0, 0, 0, 1,
                 0, 0, 1, 0;
    A[2][1] <<   0, 0, 0, 1,
                 0, 0,-1, 0,
                 0,-1, 0, 0,
                 1, 0, 0, 0;
    A[2][2] <<   1, 0, 0, 0,
                 0,-1, 0, 0,
                 0, 0, 1, 0,
                 0, 0, 0,-1;
    
    this->decomp_method = 0;
    this->cores = 1;
}

SolvePoseAnalytic::~SolvePoseAnalytic()
{
    PoseEstimate::~PoseEstimate();
}

void SolvePoseAnalytic::estimatePose()
{
    dbg("estimate pose");
    //First, move over by the centroid
    Eigen::Vector3f model_center, obs_center;
    dbg("calculating model centroid");
    calculateCentroid( model, model_center );
    dbg("calculating observation centroid");
    calculateCentroid( obs, obs_center );
    dbg("calculating translation");
    T = obs_center - model_center;
    std::cout << "Translation calculated\n";
    std::cout << "obs_center:\n" << obs_center << "\n";
    std::cout << "model_center:\n" << model_center << "\n";
    std::cout << "translation:\n" << T << "\n";
    
    std::cout << "Number of points " << num_pts << "\n";
    
    //Translate the data we have
    Eigen::MatrixXf obs_trans(3,num_pts), model_trans(3,num_pts);
    for( int i=0; i<num_pts; i++ )
    {
        obs_trans.col(i) = obs_center;
        model_trans.col(i) = model_center;
    }
    
    obs = obs - obs_trans;
    model = model - model_trans;
    
    std::cout << "First several columns of obs: \n" << obs.block<3,4>(0,0) << "\n";
    std::cout << "First several columns of model: \n" << model.block<3,4>(0,0) << "\n";
    //The problem is now an estimation over SO(3)
    
    if( this->cores == 1 )
    {
        this->singleSolver();
    } else {
        this->multiSolvers();
    }
}

void SolvePoseAnalytic::singleSolver()
{
    //Need to move over by the centroid
    
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

void SolvePoseAnalytic::z2so( Eigen::Matrix4f & z, Eigen::Matrix3f & r )
{
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            r(i,j) = (A[i][j].transpose() * z).trace();
        }
    }
}

void SolvePoseAnalytic::multiSolvers()
{
    
}

void SolvePoseAnalytic::ADMMIter() {
    
}

void SolvePoseAnalytic::DualIter() {
    
}

void SolvePoseAnalytic::adjoint( Eigen::Matrix3f & D, Eigen::Matrix4f & Dadj )
{
    Dadj.setZero();
    
    for( int i=0; i<3; i++ ) {
        for( int j=0; j<3; j++ ) {
            Dadj += A[i][j] * D(i,j);
        }
    }
}