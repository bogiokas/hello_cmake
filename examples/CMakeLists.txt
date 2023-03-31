project(HelloCmake)

add_executable(ex1 example1.cpp)
target_link_libraries(ex1 helloworld)

find_package(CGAL REQUIRED COMPONENTS Core Qt5)

add_executable(ex2 example2.cpp)
target_link_libraries(ex2 helloworld CGAL::CGAL CGAL::CGAL_Basic_viewer)

add_executable(ex3 example3.cpp)
target_link_libraries(ex3 CGAL::CGAL CGAL::CGAL_Basic_viewer)
