cmake_minimum_required(VERSION 3.6)
set (CMAKE_CXX_STANDARD 11)
project(openpose)

include_directories(/home/guanyue/openpose/include)
add_executable(1_openpose_read_and_display 1_openpose_read_and_display.cpp)
add_executable(2_user_processing_function 2_user_processing_function.cpp)
add_executable(3_user_input_processing_and_output 3_user_input_processing_and_output.cpp)
add_executable(4_user_input_processing_output_and_datum 4_user_input_processing_output_and_datum.cpp)

set(LINK_LIBS 
	gui 
	utilities 
	filesystem 
	pose pose_cu 
	hand hand_cu
	face face_cu
	thread 
	core core_cu 
	wrapper
	producer
	caffe)

target_link_libraries(1_openpose_read_and_display 
	${LINK_LIBS} ${LINK_LIBS})
target_link_libraries(2_user_processing_function 
	${LINK_LIBS} ${LINK_LIBS})
target_link_libraries(3_user_input_processing_and_output 
	${LINK_LIBS} ${LINK_LIBS})
target_link_libraries(4_user_input_processing_output_and_datum 
	${LINK_LIBS} ${LINK_LIBS})
