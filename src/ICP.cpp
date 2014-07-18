//
//  ICP.cpp
//  
//
//  Created by Matanya Horowitz on 7/17/14.
//
//

#include "ICP.h"

ICP::ICP()
{
    i_R = Matrix4f::Identity();
    i_T << 0,0,0;
}

ICP::~ICP()
{
}

void ICP::setSolver(SolverSettings s)
{
    this->settings = s;
}

void ICP::setModel( PointCloud<PointT>::Ptr m )
{
    this->num_pts = m->size();
    this->model = *m;
    //Model is target, because I believe it's the one the pcl::Correspondences creates a KDTree for, so we don't want to update it on every ICP iteration.
    est.setInputTarget( this->model );
    pose.setModel( m );
}

void ICP::setObservation( PointCloud<PointT>::Ptr o )
{
    this->observation = *o;
    pose.setObservation( o );
}

void ICP::estPose()
{
    c_R = i_R;
    c_T = i_T;
    
    //Todo: First do a coarse alignment.
    
    //Second, do a fine alignment.
    
    float error = settings.tolerance*100;
    while( error > settings.tolerance )
    {
        singleIteration();
    }
}


void ICP::singleIteration()
{
    //First, transform according to current pose estimate
    Eigen::Matrix4f transform = Eigen::Matrix4f::Identity();
    transform<3,3>(0,0) = c_R;
    transform<3,1>(0,4) = c_T;
    PointCloud<PointT> aligned, permuted;
    pcl::transformPointCloud( observation, aligned, transform );
    
    est.setInputSource( data );
    pcl::Correspondences cor;
    est.determineReciprocalCorrespondences(cor);
    
    //Permute the data matrix in line with the correspondence
    
    Eigen::SparseMatrix<float> P(num_pts, num_pts);
    for( std::vector<pcl::Correspondence>::iterator it = cor.begin(); it != cor.end(); ++it)
    {
        P(it->index_query, cor->index_match) = 1;
    }
    
    //Permute the solver's model. For now, also permute the ICP model
    //Todo: This permutation may be backwards
    pose.permuteData( P );
    
    pcl::transformPointCloud( observation, permuted, P );//Redo so we can get rid of this extra operation
    observation = permuted;
}
