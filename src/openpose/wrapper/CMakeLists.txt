cmake_minimum_required(VERSION 3.6)
set (CMAKE_CXX_STANDARD 11)
project(wrapper)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
include_directories(${CUDA_INCLUDE_DIRS})
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})

file(GLOB cpp *.cpp)
add_library(wrapper STATIC ${cpp})
target_link_libraries(wrapper caffe)
