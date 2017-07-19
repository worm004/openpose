cmake_minimum_required(VERSION 3.6)
set (CMAKE_CXX_STANDARD 11)
project(pose)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})


file(GLOB cu *.cu)
cuda_add_library(pose_cu STATIC ${cu})
target_link_libraries(pose_cu caffe)

file(GLOB cpp *.cpp)
add_library(pose STATIC ${cpp})
target_link_libraries(pose caffe)
