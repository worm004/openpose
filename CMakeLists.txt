project(openpose)
cmake_minimum_required(VERSION 2.8)
set (CMAKE_CXX_STANDARD 11)

set(USE_VCA_OPENCV)
set(USE_VCA_BOOST)
include(/home/guanyue/lib/cmake/Dependencies.cmake)
set(Caffe_DIR "/home/guanyue/openpose/3rdparty/caffe/build/install/share/Caffe")
find_package(OpenCV REQUIRED)
find_package(Caffe REQUIRED)
find_package(CUDA REQUIRED)
find_package(Boost REQUIRED)

set( CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS}; -std=c++11 -O2 -gencode arch=compute_50,code=sm_50 
	-gencode arch=compute_30,code=sm_30
		-gencode arch=compute_35,code=sm_35 
		-gencode arch=compute_50,code=sm_50 
		-gencode arch=compute_52,code=sm_52
		-gencode arch=compute_52,code=sm_61)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

add_subdirectory(src/openpose)
add_subdirectory(examples)
