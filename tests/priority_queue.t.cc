#include <assertcc/assertcc.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

#include <deque>

using namespace testing;

TEST(PriorityQueueTests, IsEmpty) {
  std::priority_queue<int, std::vector<int>, std::less<int>> x{};
  assertThat(x).isEmpty();
}

TEST(PriorityQueueTests, ExpectIsEmpty) {
  std::priority_queue<int, std::vector<int>, std::less<int>> x{};
  expectThat(x).isEmpty();
}

TEST(PriorityQueueTests, IsNotEmpty) {
  std::vector<int> v1{1, 2, 3, 4};
  std::priority_queue<int, std::vector<int>, std::less<int>> x(v1.begin(), v1.end());
  assertThat(x).isNotEmpty();
}

TEST(PriorityQueueTests, HasSize) {
  std::vector<int> v1{1, 2, 3, 4, 5};
  std::priority_queue<int, std::vector<int>, std::less<int>> x(v1.begin(), v1.end());
  assertThat(x).hasSizeThat().isEqualTo(5);
}