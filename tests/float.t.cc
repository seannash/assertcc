#include <assertcc/assertcc.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

using namespace testing;

TEST(Float, IsNan) {
  float number0 = std::numeric_limits<float>::quiet_NaN();
  assertThat(number0).isNan();
  float number1 = std::numeric_limits<float>::signaling_NaN();
  assertThat(number1).isNan();
  EXPECT_FATAL_FAILURE(assertThat(2.2).isNan(), "");
}

TEST(Float, IsNotNan) {
  float number0 = 1.2;
  assertThat(number0).isNotNan();
  EXPECT_FATAL_FAILURE(assertThat(std::numeric_limits<float>::signaling_NaN()).isNotNan(), "");
}

TEST(Float, IsFinite) {
  float number0 = 2.3;
  assertThat(number0).isFinite();
  EXPECT_FATAL_FAILURE(assertThat(std::numeric_limits<float>::signaling_NaN()).isFinite(), "");
}

TEST(Float, IsNotFinite) {
  float number0 = std::numeric_limits<float>::signaling_NaN();
  assertThat(number0).isNotFinite();
  EXPECT_FATAL_FAILURE(assertThat(1.2).isNotFinite(), "");
}

TEST(Float, IsPositiveInfinity) {
  float number0 = 1.0 / 0.0;
  assertThat(number0).isPositiveInfinity();
}

TEST(Float, isNegativeInfinity) {
  float number0 = (-1.0) / 0.0;
  assertThat(number0).isNegativeInfinity();
}

TEST(Float, isZero) {
  float number0 = 0.0;
  assertThat(number0).isZero();
}

TEST(Float, isNotZero) {
  float number0 = 0.3;
  assertThat(number0).isNotZero();
}

TEST(Float, EqualTo) {
  float a = 1.0;
  float b = 1.0;
  assertThat(a).isEqualTo(1).isEqualTo(b);
}

TEST(Float, ExpectEqualTo) {
  float a = 1.0;
  float b = 1.0;
  expectThat(a).isEqualTo(1).isEqualTo(b);
}

TEST(Float, IsWithIn) {
  float a = 1.0;
  float b = 2.0;
  assertThat(a).isWithin(1.0).isEqualTo(b);
}

TEST(Float, NotEqualTo) {
  float a = 1.0;
  float b = 2.0;
  assertThat(a).isNotEqualTo(3).isNotEqualTo(b);
  EXPECT_FATAL_FAILURE(assertThat(1).isNotEqualTo(1), "");
}

TEST(Float, IsIn) {
  float a = 1.0;
  assertThat(a).isIn({1.0, 2.0, 3.0});
  std::vector<float> v{1.0, 2.0, 3.0};
  assertThat(a).isIn(v);
}

TEST(Float, IsNotIn) {
  float a = 12.0;
  assertThat(a).isNotIn({1.0, 2.0, 3.0});
  std::vector<float> v{1.0, 2.0, 3.0};
  assertThat(a).isNotIn(v);
}

TEST(Float, GreaterThan) {
  float a = 10;
  assertThat(a).isGreaterThan(5.0);
  assertThat(11.0).isGreaterThan(5.0);
}

TEST(Float, LessThan) {
  float a = 1;
  assertThat(a).isLessThan(5);
  assertThat(2).isLessThan(5);
}

TEST(Float, IsAtLeast) {
  int a = 10;
  assertThat(a).isAtLeast(5).isAtLeast(10);
  assertThat(11).isAtLeast(5).isAtLeast(11);
}

TEST(Float, isAtMost) {
  float a = 1.2;
  assertThat(a).isAtMost(10.0).isAtMost(1.3);
  assertThat(3.0).isAtMost(5.0).isAtMost(3.5);
}