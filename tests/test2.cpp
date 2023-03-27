#include "gtest/gtest.h"
#include<iostream>

#include "hellocmake/helloworld.hpp"



TEST(TestHelloWorld, EmptyInput) {
    std::stringstream newStream;
    std::streambuf *newBuffer = newStream.rdbuf();
    std::streambuf *backupBuffer = std::cout.rdbuf();
    std::cout.rdbuf(newBuffer);

    helloworld("");

    EXPECT_EQ(newStream.str(),"Hello !\n");

    std::cout.rdbuf(backupBuffer);
}
