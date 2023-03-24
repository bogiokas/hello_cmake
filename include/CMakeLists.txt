project(HelloCmake)

add_library(helloworld
    INTERFACE)

target_include_directories(helloworld
    INTERFACE
    ${CMAKE_CURRENT_LIST_DIR})

