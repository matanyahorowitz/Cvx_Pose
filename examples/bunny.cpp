//
//  bunny.cpp
//  
//
//  Created by Matanya Horowitz on 7/18/14.
//
//

#include <iostream>
#include "ICP.h"

int main() {
    ICP icp;
    
    SolverSettings settings;
    settings.tolerance = .001;
    settings.metric = 0;
    settings.outlierRejection = false;
    settings.parallelSolvers = 1;
    
    icp.setSolver( settings );
    
    //Import model and observation...
    
    //Corrupt the observation...
    
    icp.setObservation( obs );
    icp.setModel( mod );
    
    icp.estPose();
    
    Eigen::Matrix3f rot;
    Eigen::Vector3f trans;
    icp.getPose(rot, trans);
    
    std::cout << rot;
    std::cout << trans;
}