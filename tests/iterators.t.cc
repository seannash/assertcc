#include <assertcc/assertcc.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <vector>

using namespace testing;

TEST(IteratorsTests, IsEmpty) {
  std::vector<int> v0;
  assertThat(v0).isEmpty();
  std::list<int> l0;
  assertThat(l0).isEmpty();
  std::array<int, 0> a0;
  assertThat(a0).isEmpty();
  std::deque<int> d0{};
  assertThat(a0).isEmpty();
  std::forward_list<int> fl{};
  assertThat(fl).isEmpty();
}

TEST(IteratorsTests, IsExpectIsEmpty) {
  std::vector<int> v0;
  expectThat(v0).isEmpty();
  std::list<int> l0;
  expectThat(l0).isEmpty();
  std::array<int, 0> a0;
  expectThat(a0).isEmpty();
  std::deque<int> d0{};
  expectThat(a0).isEmpty();
  std::forward_list<int> fl{};
  expectThat(fl).isEmpty();
}

TEST(IteratorsTests, IsNotEmpty) {
  std::vector<int> v0{1, 2};
  assertThat(v0).isNotEmpty();
  std::list<int> l0{3, 4};
  assertThat(l0).isNotEmpty();
  std::array<int, 10> a0;
  assertThat(a0).isNotEmpty();
  std::deque<int> d0{1, 2, 3};
  assertThat(d0).isNotEmpty();
  std::forward_list<int> fl{1, 2, 3};
  assertThat(fl).isNotEmpty();
}

TEST(IteratorsTests, IsNotEqualTo) {
  std::vector<int> v0{1, 2};
  std::vector<int> v1{1, 3};
  assertThat(v0).isNotEqualTo(v1.begin(), v1.end());
}

TEST(IteratorsTests, IsEqualTo) {
  std::vector<int> v0{1, 2};
  std::vector<int> v1{1, 2};
  assertThat(v0).isEqualTo(v1.begin(), v1.end());
}

TEST(IteratorsTests, Contains) {
  std::vector<int> v0{1, 2};
  assertThat(v0).contains(2);
}

TEST(IteratorsTests, HasSize) {
  std::vector<int> v0{1, 2};
  assertThat(v0).hasSizeThat().isEqualTo(2);
}
