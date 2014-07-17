//
//  PoseEstimate.h
//  
//
//  Created by Matanya Horowitz on 7/17/14.
//
//

#ifndef ____PoseEstimate__
#define ____PoseEstimate__

#include <iostream>

class PoseEstimate {
private:
public:
    virtual void estimatePose();
    void getPose();
    void setInitialPose();
    void setModel();
    void setObservation();
};

#endif /* defined(____PoseEstimate__) */
