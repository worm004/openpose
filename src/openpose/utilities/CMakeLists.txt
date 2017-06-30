cmake_minimum_required(VERSION 3.6)
set (CMAKE_CXX_STANDARD 11)
project(utilities)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
include_directories(${CUDA_INCLUDE_DIRS})
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})
include_directories(/home/guanyue/openpose/include)

file(GLOB cpp *.cpp)
add_library(utilities STATIC ${cpp})
