// test/test_calc.cpp
#include <gtest/gtest.h>
#include "lab/calc.hpp"

// 浮点精确相等是陷阱，见第 4 章
TEST(CalcClamp, InRangeReturnsInput) {
  EXPECT_NEAR(lab::clamp(0.5, 0.0, 1.0), 0.5, 1e-12);
}

TEST(CalcClamp, BelowLoReturnsLo) {
  EXPECT_NEAR(lab::clamp(-3.0, 0.0, 1.0), 0.0, 1e-12);
}

TEST(CalcClamp, AboveHiReturnsHi) {
  EXPECT_NEAR(lab::clamp(9.0, 0.0, 1.0), 1.0, 1e-12);
}

// 非法区间是"设计决策"，用测试把它固定下来
TEST(CalcClamp, InvertedRangeIsNoOp) {
  EXPECT_NEAR(lab::clamp(9.0, 1.0, 0.0), 9.0, 1e-12);
}

TEST(CalcMean, EmptyIsZero) {
  EXPECT_DOUBLE_EQ(lab::mean({}), 0.0);
}

TEST(CalcMean, BasicAverage) {
  EXPECT_NEAR(lab::mean({1.0, 2.0, 3.0}), 2.0, 1e-12);
}