#include <assertcc/assertcc.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

#ifdef __cpp_lib_flat_map

#include <flat_map>
#include <string>

using namespace testing;

TEST(FlatMapTests, IsEmpty) {
  std::flat_map<int, int> x{};
  assertThat(x).isEmpty();
}

TEST(FlatMapTests, IsNotEmpty) {
  std::flat_map<int, int> x{{1, 2}, {2, 3}};
  assertThat(x).isNotEmpty();
}

TEST(FlatMapTests, IsEqual) {
  std::flat_map<int, int> x{{1, 2}, {2, 3}};
  std::flat_map<int, int> y{{1, 2}, {2, 3}};
  assertThat(x).isEqualTo(y);
}

TEST(FlatMapTests, IsNotEqual) {
  std::flat_map<int, int> x{{1, 2}, {2, 4}};
  std::flat_map<int, int> y{{1, 2}, {2, 3}};
  assertThat(x).isNotEqualTo(y);
}

TEST(FlatMapTests, HasSize) {
  std::flat_map<int, int> x{{1, 2}, {2, 4}};
  assertThat(x).hasSizeThat().isEqualTo(2);
}

TEST(FlatMapTests, ContainsEntry) {
  std::flat_map<std::string, int> x{{"a", 1}, {"b", 2}};
  assertThat(x).containsEntry("a", 1).containsEntry("b", 2);
}

TEST(FlatMapTests, DoesNotContainsEntry) {
  std::flat_map<std::string, int> x{{"a", 1}, {"b", 2}};
  assertThat(x).doesNotContainEntry("a", 2).doesNotContainEntry("c", 3);
}

TEST(FlatMapTests, ContainsKey) {
  std::flat_map<std::string, int> x{{"a", 1}, {"b", 2}};
  assertThat(x).containsKey("a").containsKey("b");
}

TEST(FlatMapTests, DoesNotContainsKey) {
  std::flat_map<std::string, int> x{{"a", 1}, {"b", 2}};
  assertThat(x).doesNotContainKey("d");
} 

#endif