//
//  ICP.h
//  
//
//  Created by Matanya Horowitz on 7/17/14.
//
//

#ifndef ____ICP__
#define ____ICP__

#include "common.h"
#include "PoseEstimate.h"
#include "SolvePoseAnalytic.h"

#include <iostream>

#include <pcl/registration/correspondence_estimation.h>
#include <pcl/common/transforms.h>

#include <boost/shared_ptr.hpp>

class ICP {
public:
    ICP();
    ~ICP();
    void setSolver(SolverSettings s);
    void setModel( pcl::PointCloud<PointT>::Ptr m );
    void setObservation( pcl::PointCloud<PointT>::Ptr o );
    void estPose();
    void singleIteration();
    void getPose( Eigen::Matrix3f &rot, Eigen::Vector3f &trans );
protected:
    void dbg( std::string );
    Eigen::SparseMatrix<float> permutation;
private:
    SolverSettings settings;
    PoseEstimate * pose;
    Eigen::Matrix3f c_R, i_R; //current, initial rotation
    Eigen::Vector3f c_T, i_T; //translation
    pcl::PointCloud<PointT> model;
    pcl::PointCloud<PointT> observation;
    pcl::registration::CorrespondenceEstimation<PointT, PointT> est;
    int num_pts;
    bool debug;
    
};
#endif /* defined(____ICP__) */
