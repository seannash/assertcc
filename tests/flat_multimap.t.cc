#include <assertcc/assertcc.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

#if __cpp_lib_flat_map
#include <flat_map>

using namespace testing;

TEST(FlatMultiMapTests, isEmpty) {
  std::flat_multimap<int, int> x{};
  assertThat(x).isEmpty();
}

TEST(FlatMultiMapTests, IsNotEmpty) {
  std::flat_multimap<int, int> x{{1, 2}, {2, 3}};
  assertThat(x).isNotEmpty();
}

TEST(FlatMultiMapTests, IsEqual) {
  std::flat_multimap<int, int> x{{1, 2}, {2, 3}};
  std::flat_multimap<int, int> y{{1, 2}, {2, 3}};
  assertThat(x).isEqualTo(y);
}

TEST(FlatMultiMapTests, IsNotEqual) {
  std::flat_multimap<int, int> x{{1, 2}, {2, 4}};
  std::flat_multimap<int, int> y{{1, 2}, {2, 3}};
  assertThat(x).isNotEqualTo(y);
}

TEST(FlatMultiMapTests, HasSize) {
  std::flat_multimap<int, int> x{{1, 2}, {2, 4}};
  assertThat(x).hasSizeThat().isEqualTo(2);
}

TEST(FlatMultiMapTests, ContainsEntry) {
  std::flat_multimap<std::string, int> x{{"a", 1}, {"b", 2}};
  assertThat(x).containsEntry("a", 1).containsEntry("b", 2);
}

TEST(FlatMultiMapTests, DoesNotContainsEntry) {
  std::flat_multimap<std::string, int> x{{"a", 1}, {"b", 2}};
  assertThat(x).doesNotContainEntry("a", 2).doesNotContainEntry("c", 3);
}

TEST(FlatMultiMapTests, ContainsKey) {
  std::flat_multimap<std::string, int> x{{"a", 1}, {"b", 2}};
  assertThat(x).containsKey("a").containsKey("b");
}

TEST(FlatMultiMapTests, DoesNotContainsKey) {
  std::flat_multimap<std::string, int> x{{"a", 1}, {"b", 2}};
  assertThat(x).doesNotContainKey("d");
}

#endif