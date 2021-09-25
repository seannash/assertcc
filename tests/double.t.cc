#include <assertcc/assertcc.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

using namespace testing;

TEST(DoubleTests, IsNan) {
  double number0 = std::numeric_limits<double>::quiet_NaN();
  assertThat(number0).isNan();
  double number1 = std::numeric_limits<double>::signaling_NaN();
  assertThat(number1).isNan();
  EXPECT_FATAL_FAILURE(assertThat(2.2).isNan(), "");
}

TEST(DoubleTests, IsNotNan) {
  double number0 = 1.2;
  assertThat(number0).isNotNan();
  EXPECT_FATAL_FAILURE(assertThat(std::numeric_limits<double>::signaling_NaN()).isNotNan(), "");
}

TEST(DoubleTests, IsFinite) {
  double number0 = 2.3;
  assertThat(number0).isFinite();
  EXPECT_FATAL_FAILURE(assertThat(std::numeric_limits<double>::signaling_NaN()).isFinite(), "");
}

TEST(DoubleTests, IsNotFinite) {
  double number0 = std::numeric_limits<double>::signaling_NaN();
  assertThat(number0).isNotFinite();
  EXPECT_FATAL_FAILURE(assertThat(1.2).isNotFinite(), "");
}

TEST(DoubleTests, IsPositiveInfinity) {
  double number0 = 1.0 / 0.0;
  assertThat(number0).isPositiveInfinity();
}

TEST(DoubleTests, isNegativeInfinity) {
  double number0 = (-1.0) / 0.0;
  assertThat(number0).isNegativeInfinity();
}

TEST(DoubleTests, isZero) {
  double number0 = 0.0;
  assertThat(number0).isZero();
}

TEST(DoubleTests, isNotZero) {
  double number0 = 0.3;
  assertThat(number0).isNotZero();
}

TEST(DoubleTests, IsEqualTo) {
  double a = 1.0;
  double b = 1.0;
  assertThat(a).isEqualTo(1).isEqualTo(b);
}

TEST(DoubleTests, IsExpectEqualTo) {
  double a = 1.0;
  double b = 1.0;
  expectThat(a).isEqualTo(1).isEqualTo(b);
}

TEST(DoubleTests, IsWithIn) {
  double a = 1.0;
  double b = 2.0;
  assertThat(a).isWithin(1.0).isEqualTo(b);
}

TEST(DoubleTests, IsNotEqualTo) {
  double a = 1.0;
  double b = 2.0;
  assertThat(a).isNotEqualTo(3).isNotEqualTo(b);
  EXPECT_FATAL_FAILURE(assertThat(1).isNotEqualTo(1), "");
}

TEST(DoubleTests, IsIn) {
  double a = 1.0;
  assertThat(a).isIn({1.0, 2.0, 3.0});
  std::vector<double> v{1.0, 2.0, 3.0};
  assertThat(a).isIn(v);
}

TEST(DoubleTests, IsNotIn) {
  double a = 12.0;
  assertThat(a).isNotIn({1.0, 2.0, 3.0});
  std::vector<double> v{1.0, 2.0, 3.0};
  assertThat(a).isNotIn(v);
}

TEST(DoubleTests, IsGreaterThan) {
  double a = 10;
  assertThat(a).isGreaterThan(5.0);
  assertThat(11.0).isGreaterThan(5.0);
}

TEST(DoubleTests, IsLessThan) {
  double a = 1;
  assertThat(a).isLessThan(5);
  assertThat(2).isLessThan(5);
}

TEST(DoubleTests, IsAtLeast) {
  int a = 10;
  assertThat(a).isAtLeast(5).isAtLeast(10);
  assertThat(11).isAtLeast(5).isAtLeast(11);
}

TEST(DoubleTests, IsAtMost) {
  double a = 1.2;
  assertThat(a).isAtMost(10.0).isAtMost(1.3);
  assertThat(3.0).isAtMost(5.0).isAtMost(3.5);
}