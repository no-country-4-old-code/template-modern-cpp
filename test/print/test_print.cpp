#include <gtest/gtest.h>

#include "pprint.h"

// .\Test.exe --gtest_print_time --gtest_color=yes
// --gtest_output=json:test2.json

// Example test case
TEST(TestSuiteHelloWorld, BasicAssertions) {
    std::cout << "RUN A TEST";
    EXPECT_EQ(1 + 1, 2);
    EXPECT_TRUE(true);
}

TEST(TestBad, BasicAssertions) {
    std::cout << "RUN A TEST";
    EXPECT_TRUE(true);
}

TEST(LibTest, BasicAssertions) {
    EXPECT_EQ(factorial(1), 1);
    EXPECT_EQ(factorial(2), 2);
    EXPECT_EQ(factorial(3), 6);
    EXPECT_EQ(factorial(4), 24);
}
/*

TEST(LibTest, NegativeCheck) {
    EXPECT_EQ(Factorial(-1), -1);
    EXPECT_EQ(Factorial(-2), 2);
    EXPECT_EQ(Factorial(-3), -6);
    EXPECT_EQ(Factorial(-4), 24);
}

TEST(LibTest, FalseCheck) {
    EXPECT_EQ(Factorial(-1), 15);
}

TEST(LibTest, NullCheck) {
    EXPECT_EQ(Factorial(0), 0);
}
*/

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}