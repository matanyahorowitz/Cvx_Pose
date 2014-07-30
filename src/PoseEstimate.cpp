#include "PoseEstimate.h"

/** Constructor for PoseEstimate. Initializes the initial guess of rotation and translation,
   and also the A_{i,j} matrices.
*/
PoseEstimate::PoseEstimate()
{
    this->i_R = Eigen::Matrix3f::Identity();
    this->i_T << 0,0,0;
    debug = true;
    num_pts = 0;

A[0][0] << 1, 0, 0, 0,
           0, 1, 0, 0,
           0, 0, -1, 0,
           0, 0, 0, -1;

A[0][1] << 0, 0, 0, -1,
           0, 0, 1, 0,
           0, 1, 0, 0,
           -1,0, 0, 0;

A[0][2] << 0, 0, 1, 0,
           0, 0, 0, 1,
           1, 0, 0, 0,
           0, 1, 0, 0;

A[1][0] << 0, 0, 0, 1,
           0, 0, 1, 0,
           0, 1, 0, 0,
           1, 0, 0, 0;

A[1][1] << 1, 0, 0, 0,
           0, -1, 0, 0,
           0, 0, 1, 0,
           0, 0, 0,-1;

A[1][2] << 0, -1, 0, 0,
           -1, 0, 0, 0,
           0, 0, 0, 1,
           0, 0, 1, 0;

A[2][0] << 0, 0, -1, 0,
           0, 0, 0, 1,
           -1, 0, 0, 0,
           0, 1, 0, 0;

A[2][1] << 0, 1, 0, 0,
           1, 0, 0, 0,
           0, 0, 0, 1,
           0, 0, 1, 0;

A[2][2] << 1, 0, 0, 0,
           0, -1, 0, 0,
           0, 0, -1, 0,
           0, 0, 0, 1;

/*    A[0][0] <<   1, 0, 0, 0,
                 0,-1, 0, 0,
                 0, 0,-1, 0,
                 0, 0, 0, 1;

    A[0][1] <<   0, 0,-1, 0,
                 0, 0, 0,-1,
                -1, 0, 0, 0,
                 0,-1, 0, 0;

    A[0][2] <<   0,-1, 0, 0,
                -1, 0, 0, 0,
                 0, 0, 0, 1,
                 0, 0, 1, 0;

    A[1][0] <<   0, 0, 1, 0,
                 0, 0, 0,-1,
                 1, 0, 0, 0,
                 0,-1, 0, 0;

    A[1][1] <<   1, 0, 0, 0,
                 0, 1, 0, 0,
                 0, 0,-1, 0,
                 0, 0, 0,-1;

    A[1][2] <<   0, 0, 0,-1,
                 0, 0,-1, 0,
                 0,-1, 0, 0,
                -1, 0, 0, 0;

    A[2][0] <<   0, 1, 0, 0,
                 1, 0, 0, 0,
                 0, 0, 0, 1,
                 0, 0, 1, 0;
//From Parrilo paper
    A[2][1] <<   0, 0, 0, -1,
                 0, 0,1, 0,
                 0,1, 0, 0,
                 -1, 0, 0, 0;

    A[2][2] <<   -1, 0, 0, 0,
                 0,1, 0, 0,
                 0, 0, -1, 0,
                 0, 0, 0,1;

//Original from Matlab script
    A[2][1] <<   0, 0, 0, 1,
                 0, 0,-1, 0,
                 0,-1, 0, 0,
                 1, 0, 0, 0;

    A[2][2] <<   1, 0, 0, 0,
                 0,-1, 0, 0,
                 0, 0, 1, 0,
                 0, 0, 0,-1;
 */
}

/** Destructor has not been implemented. There are possible memory leaks. */
PoseEstimate::~PoseEstimate()
{
    
}

void PoseEstimate::setSettings(SolverSettings & set)
{
   settings = set;
}
/** Display debug message if debug flag is active.
@param[in] msg The message to be displayed.
*/
void PoseEstimate::dbg( std::string msg )
{
    if( debug )
        std::cout << msg << "\n";
}


/** Set the internal model used for pose estimation. Once received, the model is
transformed to a Eigen DMat data matrix. The model is also aligned so that its
centroid is located at the origin, while its translation is stored in model_trans.
@param[in] model Point cloud of the model
*/

void PoseEstimate::setModel( pcl::PointCloud<PointT>::Ptr model )
{
    this->num_pts = model->size();
    //Convert point cloud to Eigen::Matrix type
    this->model = model->getMatrixXfMap( 3, 4, 0 );
    calculateCentroid( this->model, model_center );
    
    //Translate the data we have
    Eigen::MatrixXf obs_trans(3,num_pts), model_trans(3,num_pts);
    for( int i=0; i<num_pts; i++ )
    {
        model_trans.col(i) = model_center;
    }
    this->model = this->model - model_trans;
}

/** Set the observation to be matched by the pose estimation. The data is transferred
from a point cloud to an Eigen DMat matrix. The observation's centroid is also aligned
to the origin, with the translation stored in obs_trans.
@param[in] obs Point cloud of the observation
*/

void PoseEstimate::setObservation( pcl::PointCloud<PointT>::Ptr obs )
{
    this->obs = obs->getMatrixXfMap( 3, 4, 0 );
    calculateCentroid( this->obs, obs_center );
    
    //Translate the data we have
    Eigen::MatrixXf obs_trans(3,num_pts);
    for( int i=0; i<num_pts; i++ )
    {
        obs_trans.col(i) = obs_center;
    }
    this->obs = this->obs - obs_trans;
}

/** Utility to calculate the centroid of point cloud data.
@param[in] data The point cloud whose centroid to calculate.
@param[out] center The translation vector to overwrite with the result.
*/
void PoseEstimate::calculateCentroid( DMat & data, Eigen::Vector3f & center )
{
    center = data.rowwise().mean();
}

/** Permute the observation model using a permutation matrix.
@param[in] P Permutation matrix
*/
void PoseEstimate::permuteData( Eigen::SparseMatrix<float> & P )
{
    this->obs = this->obs*P;
}

/** Set the initial guess for the pose estimation.
@param[in] rot Rotation matrix
@param[in] trans Translation vector
*/
void PoseEstimate::setInitialPose(Eigen::Matrix3f & rot, Eigen::Vector3f & trans)
{
    this->i_R = rot;
    this->i_T = trans;
}

/** Retrive the estimated pose.
@param[out] rot Rotation matrix
@param[out] trans Translation vector
*/

void PoseEstimate::getPose( Eigen::Matrix3f &rot, Eigen::Vector3f &trans )
{
    rot = this->R;
    trans = this->T;
}

/** Calculate the residual using the current rotation and translation R, T.
*/
float PoseEstimate::calculateResidual()
{
    //Eigen::MatrixXf move_center(3,num_pts), model_center(3,num_pts);
    //for( int i=0; i<num_pts; i++ )
    //{
    //    move_center.col(i) = this->T;
    //}
    
    Eigen::MatrixXf residual = (this->R * this->model) - this->obs;
    std::cout << "residual R \n" << this->R << "\n";
    return residual.squaredNorm();
}

