#include <assertcc/assertcc.h>
#include <gtest/gtest.h>

#include <queue>

using namespace testing;

TEST(QueueTests, isEmpty) {
  std::queue<int> x{};
  assertThat(x).isEmpty();
}


