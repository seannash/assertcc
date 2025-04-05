#include <assertcc/assertcc.h>
#include <gtest/gtest.h>

#include <memory>
#include <utility>

using namespace testing;


TEST(PairTests, IsEqualTo) {
  std::pair<int, int> x{1, 2};
  std::pair<int, int> y{1, 2};
  assertThat(x).isEqualTo(y);
}

TEST(PairTests, IsNotEqualTo) {
  std::pair<int, int> x{1, 2};
  std::pair<int, int> y{3, 2};
  assertThat(x).isNotEqualTo(y);
}
