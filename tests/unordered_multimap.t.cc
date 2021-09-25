#include <assertcc/assertcc.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

#include <unordered_map>

using namespace testing;

TEST(UnorderedMultiMapSubjectTests, isEmpty) {
  std::unordered_multimap<int, int> x{};
  assertThat(x).isEmpty();
}

TEST(UnorderedMultiMapSubjectTests, ExpectisEmpty) {
  std::unordered_multimap<int, int> x{};
  expectThat(x).isEmpty();
}

TEST(UnorderedMultiMapSubjectTests, IsNotEmpty) {
  std::unordered_multimap<int, int> x{{1, 2}, {2, 3}};
  assertThat(x).isNotEmpty();
}

TEST(UnorderedMultiMapSubjectTests, IsEqual) {
  std::unordered_multimap<int, int> x{{1, 2}, {2, 3}};
  std::unordered_multimap<int, int> y{{1, 2}, {2, 3}};
  assertThat(x).isEqualTo(y);
}

TEST(UnorderedMultiMapSubjectTests, IsNotEqual) {
  std::unordered_multimap<int, int> x{{1, 2}, {2, 4}};
  std::unordered_multimap<int, int> y{{1, 2}, {2, 3}};
  assertThat(x).isNotEqualTo(y);
}

TEST(UnorderedMultiMapSubjectTests, HasSize) {
  std::unordered_multimap<int, int> x{{1, 2}, {2, 4}};
  assertThat(x).hasSizeThat().isEqualTo(2);
}
