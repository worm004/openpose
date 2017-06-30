cmake_minimum_required(VERSION 3.6)
set (CMAKE_CXX_STANDARD 11)
project(openpose)

include_directories(/home/guanyue/openpose/include)
add_executable(1_extract_from_image 
	1_extract_from_image.cpp)
add_executable(2_extract_pose_or_heatmat_from_image 
	2_extract_pose_or_heatmat_from_image.cpp)

target_link_libraries(1_extract_from_image 
	filesystem 
	pose pose_cu 
	thread 
	utilities 
	core core_cu 
	gui 
	caffe)

target_link_libraries(2_extract_pose_or_heatmat_from_image 
	filesystem 
	pose pose_cu 
	thread 
	utilities 
	core 
	core_cu 
	gui 
	caffe)

