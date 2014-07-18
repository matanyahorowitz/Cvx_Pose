//
//  common.h
//  
//
//  Created by Matanya Horowitz on 7/18/14.
//
//

#ifndef _common_h
#define _common_h
#include <Eigen/Dense>

typedef Matrix<float,3,dynamic> DMat;
typedef pcl::PointXYZ PointT;

struct SolverSettings {
    int metric; //P2P Analytic, P2P CVX, P2Plane CVX
    bool outlierRejection;
    float tolerance;
    int parallelSolvers;
    //Todo: Pass a function for evaluating correspondence metric (for keypoints).
};

#endif
