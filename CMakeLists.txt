# CMake root
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(CVX_CV)
find_package(PCL 1.3 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

find_package(OpenMP)
if (OPENMP_FOUND)
   set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
   set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

# list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
# set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
# INCLUDE_DIRECTORIES ( "/opt/local/include/eigen3" )
# find_package(Eigen REQUIRED)
# include_directories(${Eigen_INCLUDE_DIRS})

add_subdirectory(src)
add_subdirectory(examples)

# add_definitions(“-w”)
set(CMAKE_CXX_FLAGS “${CMAKE_CXX_FLAGS} -w”)
