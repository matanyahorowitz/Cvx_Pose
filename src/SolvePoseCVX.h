//
//  SolvePoseCVX.h
//  
//
//  Created by Matanya Horowitz on 7/17/14.
//
//

#ifndef ____SolvePoseCVX__
#define ____SolvePoseCVX__

#include <iostream>
#include "PoseEstimate.h"
#include "common.h"

class SolvePoseCVX : public PoseEstimate
{
public:
    SolvePoseCVX();
    ~SolvePoseCVX();
    void estimatePose();
    void setModel(pcl::PointCloud<PointT>::Ptr model);
private:
};

#endif /* defined(____SolvePoseCVX__) */
