//
//  bunny.cpp
//  
//
//  Created by Matanya Horowitz on 7/18/14.
//
//

#include "../src/common.h"
#include "../src/ICP.h"

#include <iostream>
#include <fstream>
#include <sstream>


int main() {
    ICP icp;
    
    SolverSettings settings;
    settings.tolerance = .001;
    settings.metric = 0;
    settings.outlierRejection = false;
    settings.parallelSolvers = 1;
    
    icp.setSolver( settings );
    
    //Import model and observation...
    //from http://www.cplusplus.com/forum/beginner/26993/
    
    std::ifstream fin;
    std::string input;
    fin.open("data/bunny/bunny_vertices.txt");
    
    float x,y,z,ia,ib;
    bool error = false;
    pcl::PointCloud<PointT>::Ptr model_cloud( new pcl::PointCloud<PointT> );
    
    while( true ) {
        std::getline(fin, input);
        if( !fin ) break; //end of line?
        
        std::istringstream buffer(input);
        buffer >> x >> y >> z >> ia >> ib;
        
        pcl::PointXYZ pt;
        pt.x = x;
        pt.y = y;
        pt.z = z;
        
        model_cloud->push_back(pt);
        
        if (!buffer || !buffer.eof())
        {
            error=true;
            break;
        }
    }
    
    if( error )
        std::cout << "Error reading in bunny vertices.\n";
    
    //Corrupt the observation...
    Eigen::Affine3f corruption = Eigen::Affine3f::Identity();
    corruption.translation() << .01, .02, .03;
    corruption.rotate(Eigen::AngleAxisf(.2,Eigen::Vector3f::UnitZ()));
    
    pcl::PointCloud<PointT>::Ptr obs_cloud(new pcl::PointCloud<PointT>);
    pcl::transformPointCloud(*model_cloud,*obs_cloud,corruption);
    
    icp.setObservation( obs_cloud );
    icp.setModel( model_cloud );
    
    icp.estPose();
    
    Eigen::Matrix3f rot;
    Eigen::Vector3f trans;
    icp.getPose(rot, trans);
    
    std::cout << rot;
    std::cout << trans;
                      
    std::cout << "True solution:\n";
    std::cout << corruption.matrix();
}