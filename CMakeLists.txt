cmake_minimum_required(VERSION 3.5)
project(HelloCmake)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(include)
add_subdirectory(src)

option(BUILD_EXAMPLES "Whether to build the examples" ON)
if(BUILD_EXAMPLES)
    message(STATUS "Building examples...")
    add_subdirectory(examples)
endif()

