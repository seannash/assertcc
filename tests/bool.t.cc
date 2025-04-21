#include <assertcc/assertcc.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

using namespace testing;

TEST(BoolSubjectTests, IsTrue) {
  bool b = true;
  assertThat(b).isTrue();
  assertThat(true).isTrue();
  EXPECT_FATAL_FAILURE(assertThat(false).isTrue(), "");
}

TEST(BoolSubjectTests, ExpectIsTrue) {
  bool b = true;
  expectThat(b).isTrue();
  expectThat(true).isTrue();
  EXPECT_NONFATAL_FAILURE(expectThat(false).isTrue(), "");
}

TEST(BoolSubjectTests, IsFalse) {
  bool b = false;
  assertThat(b).isFalse();
  assertThat(false).isFalse();
}

TEST(BoolSubjectTests, CanAssertTrueAndFalse) {
  bool b0 = true;
  assertThat(b0).isTrue();
  bool b1 = false;
  assertThat(b1).isFalse();
  assertThat(true).isTrue();
  assertThat(false).isFalse();
}

TEST(BoolSubjectTests, NotEqualTo) {
  bool b0 = true;
  bool b1 = false;
  assertThat(b0).isNotEqualTo(b1).isNotEqualTo(false);
  assertThat(b1).isNotEqualTo(b0).isNotEqualTo(true);
}

TEST(BoolSubjectTests, EqualTo) {
  bool b0 = true;
  bool b1 = true;
  assertThat(b0).isEqualTo(b1).isEqualTo(true);
  assertThat(b1).isEqualTo(b1).isEqualTo(true);
  assertThat(true).isEqualTo(true);
  assertThat(false).isEqualTo(false);
}

TEST(BoolSubjectTests, MethodChaining) {
  bool b = true;
  assertThat(b)
      .isTrue()
      .isEqualTo(true)
      .isNotEqualTo(false)
      .isTrue();
}

TEST(BoolSubjectTests, ExplicitBooleanConversion) {
  bool b = true;
  assertThat(static_cast<bool>(b)).isTrue();
  assertThat(static_cast<bool>(false)).isFalse();
}

TEST(BoolSubjectTests, BooleanExpressions) {
  bool b1 = true;
  bool b2 = false;
  assertThat(b1 && b2).isFalse();
  assertThat(b1 || b2).isTrue();
  assertThat(!b1).isFalse();
  assertThat(!b2).isTrue();
}

TEST(BoolSubjectTests, ComparisonWithExpressions) {
  int x = 5;
  int y = 10;
  assertThat(x < y).isTrue();
  assertThat(x > y).isFalse();
  assertThat(x == y).isFalse();
  assertThat(x != y).isTrue();
}
