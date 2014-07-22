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
    this->i_R = Eigen::Matrix3f::Identity();
    this->i_T << 0,0,0;
}

PoseEstimate::~PoseEstimate()
{
    
}

void PoseEstimate::setModel( pcl::PointCloud<PointT>::Ptr model )
{
    //Convert point cloud to Eigen::Matrix type
    this->model = model->getMatrixXfMap( 3, 4, 0 );
}

void PoseEstimate::setObservation( pcl::PointCloud<PointT>::Ptr obs )
{
    this->obs = obs->getMatrixXfMap( 3, 4, 0 );
}

void PoseEstimate::permuteData( Eigen::SparseMatrix<float> P )
{
    this->obs = this->obs*P;
}

void PoseEstimate::setInitialPose(Eigen::Matrix3f rot, Eigen::Vector3f trans)
{
    this->i_R = rot;
    this->i_T = trans;
}

void PoseEstimate::getPose( Eigen::Matrix3f &rot, Eigen::Vector3f &trans )
{
    rot = this->R;
    trans = this->T;
}

void PoseEstimate::setCores( int num )
{
    this->cores = num;
}