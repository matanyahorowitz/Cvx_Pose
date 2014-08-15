/** Example pose estimation problem for the Stanford Bunny. Settings allow for the testing of all pose estimation techniques.

\author Matanya Horowitz
\date July 18 2013
*/

#include "../src/common.h"
#include "../src/ICP.h"

#include <iostream>
#include <fstream>
#include <sstream>


int main(int argc, char * argv[]) {
    std::cout << "Freiburg pose estimation example. Option -h for help.\n";
    SolverSettings settings;
    
    settings.tolerance = .001;
    settings.metric = 0;
    settings.outlierRejection = false;
    settings.cores = 1;

    for( int i=1; i<argc; i++ )
    {
       if( strcmp(argv[i], "-h") == 0 )
       {
          std::cout << "options:\n" <<
                        "\t-o Outlier rejection. 0 yes, 1 no\n" <<
                        "\t-m Metric. 0 Point to point analytic, 1 Point to point CVX, 2 point to plane CVX\n" <<
                        "\t-p Parallel units. \n";
          return -1;
       } else if (strcmp(argv[i], "-o") == 0) {
          settings.outlierRejection = atoi(argv[i+1]);
       } else if (strcmp(argv[i], "-m") == 0) {
          settings.metric = atoi(argv[i+1]);
          std::cout << "Setting metric to " << settings.metric << "\n";
       } else if (strcmp(argv[i], "-p") == 0) {
          settings.cores = atoi(argv[i+1]);
       }
    }
    std::cout << "Initializing ICP\n";
    ICP icp;

    icp.setSolver( settings );
    
    //Import model and observation...
    //from http://www.cplusplus.com/forum/beginner/26993/
    
   pcl::PointCloud<PointT>::Ptr model_cloud( new pcl::PointCloud<PointT> );
    
   int error = read_freiburg("examples/data/bunny/bunny_vertices.txt", 25, 4000, model_cloud);
   
    if( error ) {
        std::cout << "Error reading in bunny vertices. Quitting.\n";
        return 0;
    }
    
    std::cout << "Creating corruption\n";
    
    //Corrupt the observation...
    Eigen::Affine3f corruption = Eigen::Affine3f::Identity();
    corruption.translation() << .1, .2, .3;
    corruption.rotate(Eigen::AngleAxisf(.2,Eigen::Vector3f::UnitZ()));
   
    std::cout << "Corruption:\n" << corruption.matrix() << "\n";
     
    std::cout << "Creating observation\n";
    pcl::PointCloud<PointT>::Ptr obs_cloud(new pcl::PointCloud<PointT>);
    pcl::transformPointCloud(*model_cloud,*obs_cloud,corruption);
    
    std::cout << "Setting model and observation in ICP\n";
    icp.setModel( model_cloud );
    icp.setObservation( obs_cloud );
    
    std::cout << "Performing estimation\n";
    icp.estPose();
    std::cout << "Estimation complete\n";
    
    Eigen::Matrix3f rot;
    Eigen::Vector3f trans;
    icp.getPose(rot, trans);
    
    std::cout << "Calculated solution:\n";
    std::cout << rot << "\n";
    std::cout << trans << "\n";
                      
    std::cout << "True solution:\n";
    std::cout << corruption.matrix() << "\n";
}
