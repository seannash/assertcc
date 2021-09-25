#define GTEST
#include <assertcc/assertcc.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

#include <unordered_map>

using namespace testing;

TEST(UnorderedMapSubjectTests, isEmpty) {
  std::unordered_map<int, int> x{};
  assertThat(x).isEmpty();
}

TEST(UnorderedMapSubjectTests, ExpectisEmpty) {
  std::unordered_map<int, int> x{};
  expectThat(x).isEmpty();
}

TEST(UnorderedMapSubjectTests, isNotEmpty) {
  std::unordered_map<int, int> x{{1, 2}, {2, 3}};
  assertThat(x).isNotEmpty();
}

TEST(UnorderedMapSubjectTests, isEqual) {
  std::unordered_map<int, int> x{{1, 2}, {2, 3}};
  std::unordered_map<int, int> y{{1, 2}, {2, 3}};
  assertThat(x).isEqualTo(y);
}

TEST(UnorderedMapSubjectTests, isNotEqual) {
  std::unordered_map<int, int> x{{1, 2}, {2, 4}};
  std::unordered_map<int, int> y{{1, 2}, {2, 3}};
  assertThat(x).isNotEqualTo(y);
}

TEST(UnorderedMapSubjectTests, Size) {
  std::unordered_map<int, int> x{{1, 2}, {2, 4}};
  assertThat(x).hasSizeThat().isEqualTo(2);
}
