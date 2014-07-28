#ifndef _common_h
#define _common_h
#include <Eigen/Dense>
#include <Eigen/Core>
#include <Eigen/SparseCore>
#include <Eigen/Sparse>

#include "pcl/kdtree/impl/kdtree_flann.hpp" 

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

/** Common type for point cloud data, a 3xnum_pts matrix. */
typedef Eigen::Matrix<float,3,Eigen::Dynamic> DMat;

/** Common type for point cloud data, currently depth only with no color. */
typedef pcl::PointXYZ PointT;

/** The settings used by all solvers. Shared by ICP and PoseEstimate.
*/
struct SolverSettings {
    int metric; //P2P Analytic, P2P CVX, P2Plane CVX
    bool outlierRejection;
    float tolerance;
    int cores;
    int parallelSolvers;
    //Todo: Pass a function for evaluating correspondence metric (for keypoints).
    int options; //For analytic solution: 0 - ADMM, 1 - dual decomposition
                 //For Cvx solution:
};

#endif
