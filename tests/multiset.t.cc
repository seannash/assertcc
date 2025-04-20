#include <assertcc/assertcc.h>
#include <gtest/gtest.h>

#include <set>

using namespace testing;

TEST(MultiSetTests, IsEmpty) {
  std::multiset<int> x{};
  assertThat(x).isEmpty();
}

TEST(MultiSetTests, ExpectisEmpty) {
  std::multiset<int> x{};
  expectThat(x).isEmpty();
}

TEST(MultiSetTests, IsNotEmpty) {
  std::multiset<int> x{1, 2, 3};
  assertThat(x).isNotEmpty();
}

TEST(MultiSetTests, IsEqual) {
  std::multiset<int> x{1, 2, 3};
  std::multiset<int> y{1, 2, 3};
  assertThat(x).isEqualTo(y);
}

TEST(MultiSetTests, IsNotEqual) {
  std::multiset<int> x{1, 2, 3};
  std::multiset<int> y{11, 22, 33};
  assertThat(x).isNotEqualTo(y);
}

TEST(MultiSetTests, Size) {
  std::multiset<int> x{1, 2, 3};
  assertThat(x).hasSizeThat().isEqualTo(3);
}

TEST(MultiSetTests, Contains) {
  std::multiset<int> x{1, 2, 3};
  assertThat(x).contains(1);
  assertThat(x).contains(2);
  assertThat(x).contains(3);
}

TEST(MultiSetTests, DoesNotContain) {
  std::multiset<int> x{1, 2, 3};
  assertThat(x).doesNotContain(4);
}


