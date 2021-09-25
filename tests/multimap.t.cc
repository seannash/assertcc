#include <assertcc/assertcc.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

#include <map>
#include <string>

using namespace testing;

TEST(MultiMapTests, isEmpty) {
  std::multimap<int, int> x{};
  assertThat(x).isEmpty();
}

TEST(MultiMapTests, IsNotEmpty) {
  std::multimap<int, int> x{{1, 2}, {2, 3}};
  assertThat(x).isNotEmpty();
}

TEST(MultiMapTests, IsEqual) {
  std::multimap<int, int> x{{1, 2}, {2, 3}};
  std::multimap<int, int> y{{1, 2}, {2, 3}};
  assertThat(x).isEqualTo(y);
}

TEST(MultiMapTests, IsNotEqual) {
  std::multimap<int, int> x{{1, 2}, {2, 4}};
  std::multimap<int, int> y{{1, 2}, {2, 3}};
  assertThat(x).isNotEqualTo(y);
}

TEST(MultiMapTests, HasSize) {
  std::multimap<int, int> x{{1, 2}, {2, 4}};
  assertThat(x).hasSizeThat().isEqualTo(2);
}
