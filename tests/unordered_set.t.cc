#include <assertcc/assertcc.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

#include <unordered_set>

using namespace testing;

TEST(UnordredSetTests, IsEmpty) {
  std::unordered_set<int> x{};
  assertThat(x).isEmpty();
}

TEST(UnordredSetTests, ExpectisEmpty) {
  std::unordered_set<int> x{};
  expectThat(x).isEmpty();
}

TEST(UnordredSetTests, IsNotEmpty) {
  std::unordered_set<int> x{1, 2, 3};
  assertThat(x).isNotEmpty();
}

TEST(UnordredSetTests, IsEqual) {
  std::unordered_set<int> x{1, 2, 3};
  std::unordered_set<int> y{1, 2, 3};
  assertThat(x).isEqualTo(y);
}

TEST(UnordredSetTests, IsNotEqual) {
  std::unordered_set<int> x{1, 2, 3};
  std::unordered_set<int> y{11, 22, 33};
  assertThat(x).isNotEqualTo(y);
}

TEST(UnordredSetTests, HasSize) {
  std::unordered_set<int> x{1, 2, 3};
  assertThat(x).hasSizeThat().isEqualTo(3);
}
