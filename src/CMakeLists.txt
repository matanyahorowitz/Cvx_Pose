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

#link_directories(/usr/lib)
#link_directories(/usr/include)
link_directories(/usr/lib/atlas-base/atlas/)
#link_directories(/usr/lib/atlas-base/atlas/)
#link_directories(/usr/lib/atlas-base/)

target_link_libraries(ICP 
	${PCL_COMMON_LIBRARIES} 
	${PCL_KDTREE_LIBRARIES} 
	${PCL_SAMPLE_CONSENSUS_LIBRARIES}
	${PCL_SURFACE_LIBRARIES}
	${PCL_REGISTRATION_LIBRARIES}
   ${PCL_SEARCH_LIBRARIES}
   libsdpa.a
   dmumps_seq
   liblapack.a
   ${BLAS_LIBRARIES}
   #${LIBS}
)

# add_library(PoseEstimate ...
