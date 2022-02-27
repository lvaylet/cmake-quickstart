#include <gtest/gtest.h>
#include "max_value.h"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}

TEST(HelloTest, AnotherTest) {
    // Expect inequality.
    EXPECT_FALSE(3 == 4);
}

TEST(MaxValue, Test00) {
    EXPECT_EQ(maxValue({ 4, 13, 8 }), 13);
}
