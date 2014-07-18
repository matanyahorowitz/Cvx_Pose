//
//  PoseEstimate.cpp
//  
//
//  Created by Matanya Horowitz on 7/17/14.
//
//

#include "PoseEstimate.h"

PoseEstimate::PoseEstimate()
{
    this->i_R = Matrix4f::Identity();
    this->i_T << 0,0,0;
}

PoseEstimate::~PoseEstimate()
{
    
}

void PoseEstimate::setModel( PointCloud<PointT>::Ptr model )
{
    //Convert point cloud to Eigen::Matrix type
    this->model = model::getMatrixXfMap( 3, 4, 0 );
}

void PoseEstimate::setObservation( PointCloud<PointT>::Ptr obs )
{
    this->obs = model::getMatrixXfMap( 3, 4, 0 );
}

void PoseEstimate::PermuteData( Eigen::SparseMatrix<float> P )
{
    this->obs = this->obs*P;
}

void PoseEstimate::setInitialPose(Eigen::Matrix3f rot, Eigen::Matrix3f trans)
{
    this->i_R = rot;
    this->i_T = trans;
}

void PoseEstimate::getPose( Eigen::Matrix3f &rot, Eigen::Vector3f &trans )
{
    rot = this->R;
    trans = this->T;
}