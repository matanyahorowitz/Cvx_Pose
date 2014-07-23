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
    i_R = Eigen::Matrix3f::Identity();
    i_T << 0,0,0;
    pose = new SolvePoseAnalytic();
    debug = true;
    
}

ICP::~ICP()
{
    //dbg( "Destructing ICP" );
    //delete pose;
}

void ICP::setSolver(SolverSettings s)
{
    this->settings = s;
}

void ICP::setModel( pcl::PointCloud<PointT>::Ptr m )
{
    this->num_pts = m->size();
    this->model = *m;
    pcl::PointCloud<PointT>::Ptr mod_ptr(&(this->model));
    this->permutation.resize(num_pts, num_pts);
    
    //Set identity is apparently not available in this version of Eigen
    //this->permutation.setIdentity();
    this->permutation.setZero();
    for( int i=0; i<num_pts; i++ )
        this->permutation.insert(i,i) = 1;
    
    //Model is target, because I believe it's the one the pcl::Correspondences creates a KDTree for, so we don't want to update it on every ICP iteration.
    this->est.setInputTarget( mod_ptr );
    pose->setModel( m );
}

void ICP::setObservation( pcl::PointCloud<PointT>::Ptr o )
{
    this->observation = *o;
    this->pose->setObservation( o );
}

void ICP::estPose()
{
    c_R = i_R;
    c_T = i_T;
    
    //Todo: First do a coarse alignment.
    
    //Second, do a fine alignment.
    
    float error = settings.tolerance*100;
    //while( error > settings.tolerance )
        singleIteration();
}

void ICP::getPose( Eigen::Matrix3f &rot, Eigen::Vector3f &trans )
{
    rot = this->c_R;
    trans = this->c_T;
}

void ICP::dbg( std::string msg )
{
    if( debug )
        std::cout << msg << "\n";
}

void ICP::singleIteration()
{
    dbg("Beginning iteration");
    //First, transform according to current pose estimate
    Eigen::Matrix4f transform = Eigen::Matrix4f::Identity();
    //pcl::PointCloud<PointT> aligned, permuted;
    pcl::PointCloud<PointT> aligned;
    
    transform.block<3,3>(0,0) = c_R;
    transform.block<3,1>(0,3) = c_T;
    
    dbg("Transforming according to current guess");
    
    pcl::transformPointCloud( observation, aligned, transform );
    
    dbg("Performing correspondence");
    
    pcl::PointCloud<PointT>::Ptr al_ptr(&aligned);
    dbg("a");
    this->est.setInputCloud( al_ptr );
    dbg("b");
    pcl::Correspondences cor;
    dbg("c");
    est.determineReciprocalCorrespondences(cor);
    
    //Permute the data matrix in line with the correspondence
    dbg("Setting up permutation matrix");
    Eigen::SparseMatrix<float> P(num_pts, num_pts);
    for( std::vector<pcl::Correspondence>::iterator it = cor.begin(); it != cor.end(); ++it)
    {
        P.insert(it->index_query, it->index_match) = 1;
    }
    
    dbg("Performing permutation");
    //Permute the solver's model. For now, also permute the ICP model
    //Todo: This permutation may be backwards
    Eigen::SparseMatrix<float> newP = (permutation.transpose()) * (P);
    dbg("yum");
    //pose->permuteData( newP );
    dbg("blarg");
    permutation = P;
    
    //dbg("Permute ICP model");
    //pcl::transformPointCloud( observation, permuted, P );//Redo so we can get rid of this extra operation
    //dbg("blabla");
    //observation = permuted;
    
    dbg("Doing pose estimate");
    pose->estimatePose();
    
    dbg("Extracting estimate");
    pose->getPose(c_R, c_T);
}
