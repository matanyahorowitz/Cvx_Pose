//
//  PoseEstimate.h
//  
//
//  Created by Matanya Horowitz on 7/17/14.
//
//

#ifndef ____PoseEstimate__
#define ____PoseEstimate__

#include "common.h"
#include <iostream>

class PoseEstimate {
public:
    PoseEstimate();
    ~PoseEstimate();
    virtual void estimatePose() =0;
    virtual void setModel(pcl::PointCloud<PointT>::Ptr model);
    void setObservation(pcl::PointCloud<PointT>::Ptr obs);
    void permuteData( Eigen::SparseMatrix<float> & P );
    void setInitialPose(Eigen::Matrix3f & rot, Eigen::Vector3f & trans);
    void getPose( Eigen::Matrix3f &rot, Eigen::Vector3f &trans );
    void setCores( int num );
    void dbg( std::string );
    void calculateCentroid( DMat & data, Eigen::Vector3f & center );
protected:
    DMat model, obs;
    Eigen::Matrix3f R, i_R;
    Eigen::Vector3f T, i_T;
    int cores;
    bool debug;
    int num_pts;
private:
    
};

#endif /* defined(____PoseEstimate__) */
