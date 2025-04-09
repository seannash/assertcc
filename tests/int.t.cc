#include <assertcc/assertcc.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

#include <vector>

using namespace testing;

TEST(IntTests, IsEqualTo) {
  int a = 1;
  int b = 1;
  assertThat(a).isEqualTo(1).isEqualTo(b);
}

TEST(IntTests, IsNotEqualTo) {
  int a = 1;
  int b = 2;
  assertThat(a).isNotEqualTo(3).isNotEqualTo(b);
  EXPECT_FATAL_FAILURE(assertThat(1).isNotEqualTo(1), "");
}

TEST(IntTests, IsIn) {
  int a = 1;
  assertThat(a).isIn({1, 2, 3});
  std::vector<int> v{1, 2, 3};
  assertThat(a).isIn(v);
}

TEST(IntTests, IsNotIn) {
  int a = 10;
  assertThat(a).isNotIn({1, 2, 3});
  std::vector<int> v{1, 2, 3};
  assertThat(a).isNotIn(v);
}

TEST(IntTests, IsGreaterThan) {
  int a = 10;
  assertThat(a).isGreaterThan(5);
  assertThat(11).isGreaterThan(5);
}

TEST(IntTests, IsLessThan) {
  int a = 1;
  assertThat(a).isLessThan(5);
  assertThat(2).isLessThan(5);
}

TEST(IntTests, IsAtLeast) {
  int a = 10;
  assertThat(a).isAtLeast(5).isAtLeast(10);
  assertThat(11).isAtLeast(5).isAtLeast(11);
}

TEST(IntTests, isAtMost) {
  int a = 1;
  assertThat(a).isAtMost(10).isAtMost(1);
  assertThat(3).isAtMost(5).isAtMost(3);
}
