cmake_minimum_required(VERSION 3.5)
project(HelloCmake)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_BUILD_TYPE Release)

add_subdirectory(include)


set(CGAL_VERSION v5.5.2)
include(FetchContent)
FetchContent_Declare(CGAL
    GIT_REPOSITORY  https://github.com/CGAL/cgal.git
    GIT_TAG ${CGAL_VERSION})
message(STATUS "Populating CGAL ${CGAL_VERSION}...")
FetchContent_MakeAvailable(CGAL)
set(CGAL_DIR "${CGAL_SOURCE_DIR}")

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

