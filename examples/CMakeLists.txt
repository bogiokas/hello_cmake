project(HelloCmake)

add_executable(ex1 example1.cpp)
target_link_libraries(ex1 helloworld)

add_executable(ex2 example2.cpp)
target_link_libraries(ex2 helloworld)
