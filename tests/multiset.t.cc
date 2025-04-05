#include <assertcc/assertcc.h>
#include <gtest/gtest.h>

#include <set>

using namespace testing;

TEST(MultiSetTests, IsEmpty) {
  std::set<int> x{};
  assertThat(x).isEmpty();
}

TEST(MultiSetTests, ExpectisEmpty) {
  std::set<int> x{};
  expectThat(x).isEmpty();
}

TEST(MultiSetTests, IsNotEmpty) {
  std::set<int> x{1, 2, 3};
  assertThat(x).isNotEmpty();
}

TEST(MultiSetTests, IsEqual) {
  std::set<int> x{1, 2, 3};
  std::set<int> y{1, 2, 3};
  assertThat(x).isEqualTo(y);
}

TEST(MultiSetTests, IsNotEqual) {
  std::set<int> x{1, 2, 3};
  std::set<int> y{11, 22, 33};
  assertThat(x).isNotEqualTo(y);
}

TEST(MultiSetTests, Size) {
  std::set<int> x{1, 2, 3};
  assertThat(x).hasSizeThat().isEqualTo(3);
}
