cmake_minimum_required(VERSION 3.6)
set (CMAKE_CXX_STANDARD 11)
project(openpose)

include_directories(/home/guanyue/openpose/include)
add_executable(openpose openpose.cpp)

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

target_link_libraries(openpose 
	${LINK_LIBS} ${LINK_LIBS})
