cmake_minimum_required(VERSION 3.6)
set (CMAKE_CXX_STANDARD 11)
project(core)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})


file(GLOB cu *.cu)
cuda_add_library(core_cu STATIC ${cu})
target_link_libraries(core_cu caffe)

file(GLOB cpp *.cpp)
add_library(core STATIC ${cpp})
target_link_libraries(core caffe)
