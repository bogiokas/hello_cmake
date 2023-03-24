project(HelloCmake)

add_library(helloworld helloworld.cpp)

target_include_directories(helloworld
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/../include)
