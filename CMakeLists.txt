cmake_minimum_required(VERSION 3.17)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenGL)

add_executable(untitled1 main.cpp testt.cpp testt.h)
target_link_libraries(untitled1 -lOpenGL32 -lfreeGLUT ${OPENGL_LIBRARIES})