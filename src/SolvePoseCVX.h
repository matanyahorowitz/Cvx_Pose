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

class SolvePoseCVX : public PoseEstimate
{
    void estimatePose();
    void setModel(PointCloud<PointT>::Ptr model);
};

#endif /* defined(____SolvePoseCVX__) */
