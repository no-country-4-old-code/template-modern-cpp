#include <gtest/gtest.h>
#include <fizzbuzz.h>

TEST(TestFizzBuzz, CheckNotDividable) {
    EXPECT_EQ(map_to_fizz_buzz(1), "1");
    EXPECT_EQ(map_to_fizz_buzz(2), "2");
    EXPECT_EQ(map_to_fizz_buzz(4), "4");
    EXPECT_EQ(map_to_fizz_buzz(7), "7");
    EXPECT_EQ(map_to_fizz_buzz(8), "8");
    EXPECT_EQ(map_to_fizz_buzz(11), "11");
    EXPECT_EQ(map_to_fizz_buzz(101), "101");    
}

TEST(TestFizzBuzz, CheckFizzDividable) {
    EXPECT_EQ(map_to_fizz_buzz(3), "FIZZ");
    EXPECT_EQ(map_to_fizz_buzz(6), "FIZZ");
    EXPECT_EQ(map_to_fizz_buzz(9), "FIZZ");
    EXPECT_EQ(map_to_fizz_buzz(12), "FIZZ");
}

TEST(TestFizzBuzz, CheckBuzzDividable) {
    EXPECT_EQ(map_to_fizz_buzz(5), "BUZZ");
    EXPECT_EQ(map_to_fizz_buzz(10), "BUZZ");
    EXPECT_EQ(map_to_fizz_buzz(20), "BUZZ");
}

TEST(TestFizzBuzz, CheckFizzBuzzDividable) {
    EXPECT_EQ(map_to_fizz_buzz(0), "FIZZBUZZ");
    EXPECT_EQ(map_to_fizz_buzz(15), "FIZZBUZZ");
    EXPECT_EQ(map_to_fizz_buzz(30), "FIZZBUZZ");
    EXPECT_EQ(map_to_fizz_buzz(45), "FIZZBUZZ");
}




