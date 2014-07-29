#include "ICP.h"

/** ICP default constructor. Initializes pose and translation estimate to identity and the origin
*/

ICP::ICP()
{
    i_R = Eigen::Matrix3f::Identity();
    i_T << 0,0,0;
    pose = new SolvePoseAnalytic();
    debug = true;
    
}

/** ICP destructor. [Todo] Currently, this is unimplemented and may be leaking memory.
*/
ICP::~ICP()
{
    //dbg( "Destructing ICP" );
    //delete pose;
}

/** Set the solver settings.
@param[in] s Complete specification of problem settings.
*/
void ICP::setSolver(SolverSettings & s)
{
    this->settings = s;
    pose->setSettings(s);
}

/** Set the model which ICP will use to estimate pose.
@param[in] m PCL pointer to the model.
*/
void ICP::setModel( pcl::PointCloud<PointT>::Ptr m )
{
    this->num_pts = m->size();
    this->model = m;
    this->permutation.resize(num_pts, num_pts);
    
    //Set identity is apparently not available in this version of Eigen
    //this->permutation.setIdentity();
    this->permutation.setZero();
    for( int i=0; i<num_pts; i++ )
        this->permutation.insert(i,i) = 1;
    
    //Model is target, because I believe it's the one the pcl::Correspondences creates a KDTree for, so we don't want to update it on every ICP iteration.
    this->est.setInputTarget( this->model );
    pose->setModel( this->model );
}

/** Set the observation which ICP will try to match with its model.
*/
void ICP::setObservation( pcl::PointCloud<PointT>::Ptr o )
{
    this->observation = o;
    this->pose->setObservation( o );
}

/** Perform the pose estimation iteration until convergence. 

[Todo] In the future, a coarse alignment will first be performed with a down sampled model, or using depth features.

[Todo] In the future, there will be an option to begin with multiple pose initial conditions

*/

void ICP::estPose()
{
    c_R = i_R;
    c_T = i_T;
    
    //Todo: First do a coarse alignment.
    
    //Second, do a fine alignment.
    
    float error = pose->calculateResidual();
    std::cout << "Iteration 0 residual: " << error << "\n";
    int count = 0;
    while( error > settings.tolerance ) {
        singleIteration();
        error = pose->calculateResidual();
        count++;
        std::cout << "Iteration " << count << " residual: " << error << "\n";
        
        if( count > 20 )
            break;
    }
}

/** Retrieve the estimated pose.
@param[out] rot The rotation matrix
@param[out] trans The translation vector
*/
void ICP::getPose( Eigen::Matrix3f &rot, Eigen::Vector3f &trans )
{
    rot = this->c_R;
    trans = this->c_T;
}

/** Debug output. Very rough for now, simply prints or not depending on the debug flag.
@param[in] msg The debug message
*/
void ICP::dbg( std::string msg )
{
    if( debug )
        std::cout << msg << "\n";
}

/** Single iteration of ICP: correspondence then pose estimate.
*/
void ICP::singleIteration()
{
    dbg("Beginning iteration");
    //First, transform according to current pose estimate
    Eigen::Matrix4f transform = Eigen::Matrix4f::Identity();
    pcl::PointCloud<PointT>::Ptr aligned(new pcl::PointCloud<PointT>);
    
    transform.block<3,3>(0,0) = c_R;
    transform.block<3,1>(0,3) = c_T;
    
    dbg("Transforming according to current guess");
    
    pcl::transformPointCloud( *observation, *aligned, transform );
    
    dbg("Performing correspondence");
    
    this->est.setInputSource( aligned );
    pcl::Correspondences cor;
    //est.determineReciprocalCorrespondences(cor);
    est.determineCorrespondences(cor);

    //Permute the data matrix in line with the correspondence
    dbg("Setting up permutation matrix");
    Eigen::SparseMatrix<float> P(num_pts, num_pts);
    for( pcl::Correspondences::iterator it = cor.begin(); it != cor.end(); ++it)
    {
        P.insert(it->index_query, it->index_match) = 1;
    }
    
    dbg("Performing permutation");
    //Permute the solver's model. For now, also permute the ICP model
    //Todo: This permutation may be backwards
    Eigen::SparseMatrix<float> newP = (permutation.transpose()) * (P);
    //pose->permuteData( newP );
    permutation = P;
    
    dbg("Doing pose estimate");
    pose->estimatePose();
    
    dbg("Extracting estimate");
    pose->getPose(c_R, c_T);
}
