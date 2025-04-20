#include <assertcc/assertcc.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

#include <set>

using namespace testing;

TEST(SetTests, IsEmpty) {
  std::set<int> x{};
  assertThat(x).isEmpty();
}

TEST(SetTests, ExpectisEmpty) {
  std::set<int> x{};
  expectThat(x).isEmpty();
}

TEST(SetTests, IsNotEmpty) {
  std::set<int> x{1, 2, 3};
  assertThat(x).isNotEmpty();
}

TEST(SetTests, IsEqual) {
  std::set<int> x{1, 2, 3};
  std::set<int> y{1, 2, 3};
  assertThat(x).isEqualTo(y);
}

TEST(SetTests, IsNotEqual) {
  std::set<int> x{1, 2, 3};
  std::set<int> y{11, 22, 33};
  assertThat(x).isNotEqualTo(y);
}

TEST(SetTests, Size) {
  std::set<int> x{1, 2, 3};
  assertThat(x).hasSizeThat().isEqualTo(3);
}

TEST(SetTests, Contains) {
  std::set<int> x{1, 2, 3};
  assertThat(x).contains(1);
  assertThat(x).contains(2);
  assertThat(x).contains(3);
}

TEST(SetTests, DoesNotContain) {
  std::set<int> x{1, 2, 3};
  assertThat(x).doesNotContain(4);
}
