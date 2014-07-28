#ifndef ____ICP__
#define ____ICP__

#include "common.h"
#include "PoseEstimate.h"
#include "SolvePoseAnalytic.h"

#include <iostream>

#include <pcl/registration/correspondence_estimation.h>
#include <pcl/common/transforms.h>

#include <boost/shared_ptr.hpp>

/**
 * Iterative Closest Point
 *
 * Class that manages the ICP algorithm. It relies on a PCL class for 
 * performing correspondence, and a PoseEstimate instance for calculating
 * the pose. ICP iterates betweeen these two functions to find a pose and
 * correspondence between a model and an observation of that model.
 *
 * \author Matanya Horowitz
 * \version 1.0
 * \date July 28, 2014
*/

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
   /** Stores the ICP settings. Shared with PoseEstimate. */
   SolverSettings settings;

   /** Member for performing pose estimation. */
   PoseEstimate * pose;

   /** Current rotation estimate. */
   Eigen::Matrix3f c_R;

   /** Initial rotation estimate supplied by user. */
   Eigen::Matrix3f i_R;

   /** Current translation estimate. */
   Eigen::Vector3f c_T;
   
   /** Initial translation estimate supplied by user. */
   Eigen::Vector3f i_T;

   /** Internal model of the object whose pose is to be estimated. */
   pcl::PointCloud<PointT> model;

   /** Internal copy of an object observation. */
   pcl::PointCloud<PointT> observation;

   /** PCL class for estimating correspondence between model and observation points. */
   pcl::registration::CorrespondenceEstimation<PointT, PointT> est;
   
   /** Count of number of points in observation and model (which should be equal, for now). */
   int num_pts;

   /** Setting for printing (or not) of debug messages. */
   bool debug;
    
};
#endif /* defined(____ICP__) */
