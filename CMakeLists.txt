cmake_minimum_required(VERSION 3.0.0)
project(space_invader VERSION 0.1.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)



add_library(
    server 
    server.h
    server.cpp
)

find_package(OpenGL REQUIRED)
# Find GLFW package
find_package(glfw3 REQUIRED)
#include_directories(${GLFW_INCLUDE_DIRS})

# Find GLEW package
find_package(GLEW REQUIRED)
#include_directories(${GLEW_INCLUDE_DIRS})
include_directories(/usr/include/mysql-cppconn-8/jdbc)
# Add executable target and link libraries
add_executable(space_invader main.cpp)
target_link_libraries(space_invader glfw ${GLEW_LIBRARIES} mysqlcppconn server ${OPENGL_LIBRARIES})



