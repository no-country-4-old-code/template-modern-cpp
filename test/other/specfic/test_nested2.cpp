#include <gtest/gtest.h>

TEST(TestNested, LookAtMe) {
    std::cout << "RUN A TEST";
    EXPECT_EQ(1 + 1, 2);
    EXPECT_TRUE(true);
}
