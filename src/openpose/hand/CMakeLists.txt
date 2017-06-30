cmake_minimum_required(VERSION 3.6)
set (CMAKE_CXX_STANDARD 11)
project(hand)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})
include_directories(/home/guanyue/openpose/include)


file(GLOB cu *.cu)
cuda_add_library(hand_cu STATIC ${cu})
target_link_libraries(hand_cu caffe)

file(GLOB cpp *.cpp)
add_library(hand STATIC ${cpp})
target_link_libraries(hand caffe)
