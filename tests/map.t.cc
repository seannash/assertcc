#include <assertcc/assertcc.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

#include <map>
#include <string>

using namespace testing;

TEST(MapTests, IsEmpty) {
  std::map<int, int> x{};
  assertThat(x).isEmpty();
}

TEST(MapTests, IsNotEmpty) {
  std::map<int, int> x{{1, 2}, {2, 3}};
  assertThat(x).isNotEmpty();
}

TEST(MapTests, IsEqual) {
  std::map<int, int> x{{1, 2}, {2, 3}};
  std::map<int, int> y{{1, 2}, {2, 3}};
  assertThat(x).isEqualTo(y);
}

TEST(MapTests, IsNotEqual) {
  std::map<int, int> x{{1, 2}, {2, 4}};
  std::map<int, int> y{{1, 2}, {2, 3}};
  assertThat(x).isNotEqualTo(y);
}

TEST(MapTests, HasSize) {
  std::map<int, int> x{{1, 2}, {2, 4}};
  assertThat(x).hasSizeThat().isEqualTo(2);
}

TEST(MapTests, ContainsEntry) {
  std::map<std::string, int> x{{"a", 1}, {"b", 2}};
  assertThat(x).containsEntry("a", 1).containsEntry("b", 2);
}

TEST(MapTests, DoesNotContainsEntry) {
  std::map<std::string, int> x{{"a", 1}, {"b", 2}};
  assertThat(x).doesNotContainEntry("a", 2).doesNotContainEntry("c", 3);
}

TEST(MapTests, ContainsKey) {
  std::map<std::string, int> x{{"a", 1}, {"b", 2}};
  assertThat(x).containsKey("a").containsKey("b");
}

TEST(MapTests, DoesNotContainsKey) {
  std::map<std::string, int> x{{"a", 1}, {"b", 2}};
  assertThat(x).doesNotContainKey("d");
}
