//
//  ICP.h
//  
//
//  Created by Matanya Horowitz on 7/17/14.
//
//

#ifndef ____ICP__
#define ____ICP__

#include <iostream>
struct SolverSettings {
    int metric; //P2P CVX, P2P Analytic, P2Plane CVX
    bool outlierRejection;
    int parallelSolvers;
    //Todo: Pass a function for evaluating correspondence metric (for keypoints).
};

class ICP {
    
};
#endif /* defined(____ICP__) */
