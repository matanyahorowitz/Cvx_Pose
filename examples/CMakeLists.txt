# Examples CMake

include_directories(${CVX_CV_SOURCE_DIR/src})
link_directories(${CVX_CV_BINARY_DIR/src})

add_executable(bunny bunny.cpp)

target_link_libraries(bunny 
	${PCL_COMMON_LIBRARIES} 
	${PCL_IO_LIBRARIES} 
	ICP)
