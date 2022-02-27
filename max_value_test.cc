#include <gtest/gtest.h>
#include "max_value.h"

TEST(MaxValueTest, Test00) {
    std::vector<float> numbers{ 4, 7, 2, 8, 10, 9 };
    EXPECT_EQ(maxValue(numbers), 10);
}

TEST(MaxValueTest, Test01) {
    std::vector<float> numbers{ 10, 5, 40, 40.3 };
    EXPECT_NEAR(maxValue(numbers), 40.3, 0.001);
}

TEST(MaxValueTest, Test02) {
    std::vector<float> numbers{ -5, -2, -1, -11 };
    EXPECT_EQ(maxValue(numbers), -1);
}

TEST(MaxValueTest, Test03) {
    std::vector<float> numbers{ 42 };
    EXPECT_EQ(maxValue(numbers), 42);
}

TEST(MaxValueTest, Test04) {
    std::vector<float> numbers{ 1000, 8 };
    EXPECT_EQ(maxValue(numbers), 1000);
}

TEST(MaxValueTest, Test05) {
    std::vector<float> numbers{ 1000, 8, 9000 };
    EXPECT_EQ(maxValue(numbers), 9000);
}

TEST(MaxValueTest, Test06) {
    std::vector<float> numbers{ 2, 5, 1, 1, 4 };
    EXPECT_EQ(maxValue(numbers), 5);
}
