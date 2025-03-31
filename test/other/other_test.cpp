#include <gtest/gtest.h>

TEST(TestSuiteInOtherFile, Wuhhhaaa) {
    std::cout << "RUN A TEST";
    EXPECT_EQ(1 + 1, 2);
    EXPECT_TRUE(true);
}

TEST(TestSuiteInOtherFile, Wuhhhaaa2) {
    std::cout << "RUN A TEST";
    EXPECT_EQ(1 + 1, 2);
    EXPECT_TRUE(true);
}
