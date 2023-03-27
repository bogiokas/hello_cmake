cmake_minimum_required(VERSION 3.5)
project(HelloCmake)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(include)

option(BUILD_TESTS "Whether to build the tests" ON)
option(BUILD_EXAMPLES "Whether to build the examples" ON)

if(BUILD_TESTS)
    message(STATUS "Building tests...")
    add_subdirectory(tests)
endif()

if(BUILD_EXAMPLES)
    message(STATUS "Building examples...")
    add_subdirectory(examples)
endif()

