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
#include <Eigen/Dense>
#include <pcl/registration/correspondence_estimation.h>

typedef Matrix<float,3,dynamic> DMat;
typedef pcl::PointXYZ PointT;

struct SolverSettings {
    int metric; //P2P CVX, P2P Analytic, P2Plane CVX
    bool outlierRejection;
    int parallelSolvers;
    //Todo: Pass a function for evaluating correspondence metric (for keypoints).
};

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
