//
//  PoseEstimate.h
//  
//
//  Created by Matanya Horowitz on 7/17/14.
//
//

#ifndef ____PoseEstimate__
#define ____PoseEstimate__

#include <iostream>
#include "common.h"

class PoseEstimate {
private:
    DMat model, obs;
    Matrix3f R, i_R;
    Vector3f T, i_T;
    int cores;
public:
    virtual void estimatePose() =0;
    void getPose();
    void setInitialPose();
    void setModel(PointCloud<PointT>::Ptr model);
    void setObservation(PointCloud<PointT>::Ptr model);
    void permuteData( Eigen::SparseMatrix<float> P );
    void setInitialPose(Eigen::Matrix3f rot, Eigen::Matrix3f trans);
    void getPose( Eigen::Matrix3f &rot, Eigen::Vector3f &trans );
    void setCores( int num );
};

#endif /* defined(____PoseEstimate__) */
