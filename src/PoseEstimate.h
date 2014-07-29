#ifndef ____PoseEstimate__
#define ____PoseEstimate__

#include "common.h"
#include <iostream>

/** Class for performing pose estimation.
 * 
 * Abstract class for the different implementations of pose estimation. The class manages
 * the storage and manipulation of the data, such as when the data is permuted, and
 * calculates error measurements. Details of the actual pose estimation are handled
 * by subclasses.
 * 
 * \author Matanya Horowitz
 * \date July 28, 2014
*/

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
    float calculateResidual();
    void setSettings( SolverSettings & set );
protected:
   /** Model data */
   DMat model;

   /** Observation data */
   DMat obs;

   /** Convex hull A_{i,j} matrices. Necessary for the parameterization of the
   convex hull. See http://arxiv.org/pdf/1403.4914.pdf for details. */
   Eigen::Matrix4f A[3][3];

   /** Current estimate of rotation matrix. */
   Eigen::Matrix3f R;

   /** Initial estimate of rotation matrix. */
   Eigen::Matrix3f i_R;

   /** Current estimate of translation vector. */
   Eigen::Vector3f T;

   /** Initial estimate of translation vector. */
   Eigen::Vector3f i_T;

   /** Whether or not to display debug messages. */
   bool debug;

   /** Number of points in observation and model point clouds. */
   int num_pts;

   /** Centroid of model */
   Eigen::Vector3f model_center;

   /** Centroid of observation */
   Eigen::Vector3f obs_center;

   /** Settings used in solving. Shared with ICP. */
   SolverSettings settings;
private:
    
};

#endif /* defined(____PoseEstimate__) */
