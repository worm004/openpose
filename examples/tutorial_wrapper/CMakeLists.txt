cmake_minimum_required(VERSION 3.6)
set (CMAKE_CXX_STANDARD 11)
project(openpose)

include_directories(/home/guanyue/openpose/include)
add_executable(1_user_asynchronous
	1_user_asynchronous.cpp)

add_executable(2_user_synchronous
	2_user_synchronous.cpp)

target_link_libraries(1_user_asynchronous
	filesystem 
	pose pose_cu 
	hand hand_cu
	face face_cu
	thread 
	utilities 
	core core_cu 
	wrapper
	producer
	gui 
	caffe)

target_link_libraries(2_user_synchronous
	filesystem 
	pose pose_cu 
	hand hand_cu
	face face_cu
	thread 
	utilities 
	core core_cu 
	wrapper
	producer
	gui 
	caffe)
