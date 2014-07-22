# Source CMake

add_library(ICP common.h 
    ICP.cpp         
    ICP.h                   
    PoseEstimate.cpp
    PoseEstimate.h 
    SolvePoseAnalytic.cpp   
    SolvePoseAnalytic.h
    SolvePoseCVX.cpp 
    SolvePoseCVX.h)

target_link_libraries(ICP 
	${PCL_COMMON_LIBRARIES} 
	${PCL_KDTREE_LIBRARIES} 
	${PCL_SAMPLE_CONSENSUS_LIBRARIES}
	${PCL_SURFACE_LIBRARIES}
	${PCL_REGISTRATION_LIBRARIES}
)

# add_library(PoseEstimate ...