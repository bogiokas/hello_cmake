#include "gtest/gtest.h"
#include<iostream>

#include "hellocmake/helloworld.hpp"


class TestHelloWorld : public ::testing::Test {
protected:
    void RedirectCoutToTemp() {
        tempBuffer = tempStream.rdbuf();
        backupBuffer = std::cout.rdbuf();
        std::cout.rdbuf(tempBuffer);
    }
    void RedirectBackupToCout() {
        std::cout.rdbuf(backupBuffer);
    }
    std::stringstream tempStream;
    std::streambuf *tempBuffer, *backupBuffer;
};

TEST_F(TestHelloWorld, EmptyInput) {
    RedirectCoutToTemp();

    helloworld("");
    EXPECT_EQ(tempStream.str(),"Hello !\n");

    RedirectBackupToCout();
}

TEST_F(TestHelloWorld, SimpleInput) {
    RedirectCoutToTemp();

    helloworld("you");
    EXPECT_EQ(tempStream.str(),"Hello you!\n");

    RedirectBackupToCout();
}

