cmake_minimum_required(VERSION 3.6)
set (CMAKE_CXX_STANDARD 11)
project(openpose)

add_executable(my_test my_test.cpp)

set(LINK_LIBS 
	gui 
	filesystem 
	pose pose_cu 
	hand hand_cu
	face face_cu
	thread 
	core core_cu 
	wrapper
	producer
	caffe
	utilities 
)

target_link_libraries(my_test ${LINK_LIBS} ${LINK_LIBS} ${Caffe_LIBRARIES})

