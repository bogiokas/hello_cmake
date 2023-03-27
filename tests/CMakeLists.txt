project(HelloCmake)

set(GTEST_VERSION release-1.12.1)

include(FetchContent)

FetchContent_Declare(googletest
GIT_REPOSITORY https://github.com/google/googletest.git
GIT_TAG ${GTEST_VERSION})

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
    message(STATUS "Downloading googletest ${GTEST_VERSION}")
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

enable_testing()

add_executable(test1 test1.cpp)
target_link_libraries(test1 GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test1)
