ar -x ../build/src/openpose/producer/libproducer.a
ar -x ../build/src/openpose/utilities/libutilities.a
ar -x ../build/src/openpose/hand/libhand_cu.a
ar -x ../build/src/openpose/hand/libhand.a
ar -x ../build/src/openpose/pose/libpose_cu.a
ar -x ../build/src/openpose/pose/libpose.a
ar -x ../build/src/openpose/gui/libgui.a
ar -x ../build/src/openpose/thread/libthread.a
ar -x ../build/src/openpose/face/libface.a
ar -x ../build/src/openpose/face/libface_cu.a
ar -x ../build/src/openpose/wrapper/libwrapper.a
ar -x ../build/src/openpose/core/libcore_cu.a
ar -x ../build/src/openpose/core/libcore.a
ar -x ../build/src/openpose/filestream/libfilesystem.a
ar -qc libopenpose.a  *.o
