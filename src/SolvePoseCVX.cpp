//
//  SolvePoseCVX.cpp
//  
//
//  Created by Matanya Horowitz on 7/17/14.
//
//

#include "SolvePoseCVX.h"

SolvePoseCVX::SolvePoseCVX() : PoseEstimate()
{
    
}

SolvePoseCVX::~SolvePoseCVX()
{
    PoseEstimate::~PoseEstimate();
}

void SolvePoseCVX::estimatePose()
{
    
}

void setModel(pcl::PointCloud<PointT>::Ptr model)
{
 //   PoseEstimate::setModel( model );
}