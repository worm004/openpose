add_definitions(-DUSE_CAFFE)

include_directories(../../include)
add_subdirectory(core)
add_subdirectory(filestream)
add_subdirectory(gui)
add_subdirectory(hand)
add_subdirectory(pose)
add_subdirectory(producer)
add_subdirectory(thread)
add_subdirectory(utilities)
add_subdirectory(wrapper)
add_subdirectory(face)

