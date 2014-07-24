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
    debug = true;
    num_pts = 0;

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
 
}

PoseEstimate::~PoseEstimate()
{
    
}

void PoseEstimate::dbg( std::string msg )
{
    if( debug )
        std::cout << msg << "\n";
}

void PoseEstimate::setModel( pcl::PointCloud<PointT>::Ptr model )
{
    this->num_pts = model->size();
    //Convert point cloud to Eigen::Matrix type
    this->model = model->getMatrixXfMap( 3, 4, 0 );
    calculateCentroid( this->model, model_center );
    
    //Translate the data we have
    Eigen::MatrixXf obs_trans(3,num_pts), model_trans(3,num_pts);
    for( int i=0; i<num_pts; i++ )
    {
        model_trans.col(i) = model_center;
    }
    this->model = this->model - model_trans;
}

void PoseEstimate::setObservation( pcl::PointCloud<PointT>::Ptr obs )
{
    this->obs = obs->getMatrixXfMap( 3, 4, 0 );
    calculateCentroid( this->obs, obs_center );
    
    //Translate the data we have
    Eigen::MatrixXf obs_trans(3,num_pts);
    for( int i=0; i<num_pts; i++ )
    {
        obs_trans.col(i) = obs_center;
    }
    this->obs = this->obs - obs_trans;
}

void PoseEstimate::calculateCentroid( DMat & data, Eigen::Vector3f & center )
{
    center = data.rowwise().mean();
}

void PoseEstimate::permuteData( Eigen::SparseMatrix<float> & P )
{
    this->obs = this->obs*P;
}

void PoseEstimate::setInitialPose(Eigen::Matrix3f & rot, Eigen::Vector3f & trans)
{
    this->i_R = rot;
    this->i_T = trans;
}

void PoseEstimate::getPose( Eigen::Matrix3f &rot, Eigen::Vector3f &trans )
{
    rot = this->R;
    trans = this->T;
}

float PoseEstimate::calculateResidual()
{
    Eigen::MatrixXf move_center(3,num_pts), model_center(3,num_pts);
    for( int i=0; i<num_pts; i++ )
    {
        move_center.col(i) = this->T;
    }
    
    Eigen::MatrixXf residual = (this->R * this->model)  - this->obs;
    return residual.squaredNorm();
}

void PoseEstimate::setCores( int num )
{
    this->cores = num;
}
