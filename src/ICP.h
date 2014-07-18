//
//  ICP.h
//  
//
//  Created by Matanya Horowitz on 7/17/14.
//
//

#ifndef ____ICP__
#define ____ICP__

#include <iostream>
#include <pcl/registration/correspondence_estimation.h>
#include "common.h"

class ICP {
public:
    ICP();
    ~ICP();
    void setModel();
private:
    SolverSettings settings;
    PoseEstimate pose;
    Matrix3f c_R, i_R; //current, initial rotation
    Vector3f c_T, i_T; //translation
    PointCloud<PointT> model;
    PointCloud<PointT> observation;
    pcl::CorespondenceEstimation<PointT, PointT> est;
};
#endif /* defined(____ICP__) */
