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
    std::cout << "Bunny pose estimation example. Option -h for help.\n";
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
       } else if (strcmp(argv[i], "-o")) {
          settings.outlierRejection = atoi(argv[i+1]);
       } else if (strcmp(argv[i], "-m")) {
          settings.metric = atoi(argv[i+1]);
       } else if (strcmp(argv[i], "-p")) {
          settings.cores = atoi(argv[i+1]);
       }
    }
    std::cout << "Initializing ICP\n";
    ICP icp;

    icp.setSolver( settings );
    
    //Import model and observation...
    //from http://www.cplusplus.com/forum/beginner/26993/
    
    std::cout << "Opening bunny file\n";
    
    std::ifstream fin;
    std::string input;
    fin.open("../examples/data/bunny/bunny_vertices.txt");
    
    std::cout << "Bunny file opened\n";
    if( !fin.good() )
    {
        std::cout << "Error reading in file. Quitting.\n";
        return 0;
    }
    float x,y,z,ia,ib;
    bool error = false;
    pcl::PointCloud<PointT>::Ptr model_cloud( new pcl::PointCloud<PointT> );
    
    std::cout << "Reading in point cloud data\n";
    int line_num = 0;
    while( true ) {
        if( line_num % 10 == 0 )
            std::cout << "Reading in line " << line_num << "\n";
        
        std::getline(fin, input);
        if( !fin ) { //end of line?
            std::cout << "End of file reached.\n";
            break;
        }
        
        std::istringstream buffer(input);
        buffer >> x >> y >> z >> ia >> ib;
        
        pcl::PointXYZ pt;
        pt.x = x;
        pt.y = y;
        pt.z = z;
        
        model_cloud->push_back(pt);
        
        if (!buffer)
        {
            std::cout<<"Error reading line " << line_num << "\n";
            error=true;
            break;
        }
        line_num++;
    }
    
    if( error ) {
        std::cout << "Error reading in bunny vertices. Quitting.\n";
        return 0;
    }
    
    std::cout << "Creating corruption\n";
    
    //Corrupt the observation...
    Eigen::Affine3f corruption = Eigen::Affine3f::Identity();
    corruption.translation() << .1, .2, .3;
    corruption.rotate(Eigen::AngleAxisf(.2,Eigen::Vector3f::UnitZ()));
    
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
