#include <assertcc/assertcc.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

#include <stack>

using namespace testing;

TEST(StackTests, IsEmpty) {
  std::stack<int, std::deque<int>> x{};
  assertThat(x).isEmpty();
}

TEST(StackTests, ExpectIsEmpty) {
  std::stack<int, std::deque<int>> x{};
  assertThat(x).isEmpty();
}

TEST(StackTests, IsNotEmpty) {
  std::deque<int> q{1, 2, 3};
  std::stack<int, std::deque<int>> x{q};
  assertThat(x).isNotEmpty();
}

TEST(StackTests, IsEqual) {
  std::deque<int> q1{1, 2, 3};
  std::stack<int, std::deque<int>> x{q1};
  std::deque<int> q2{1, 2, 3};
  std::stack<int, std::deque<int>> y{q2};
  assertThat(x).isEqualTo(y);
}

TEST(StackTests, IsNotEqual) {
  std::deque<int> q1{1, 2, 3, 4};
  std::stack<int, std::deque<int>> x{q1};
  std::deque<int> q2{1, 2, 3};
  std::stack<int, std::deque<int>> y{q2};
  assertThat(x).isNotEqualTo(y);
}

TEST(StackTests, Size) {
  std::deque<int> q1{1, 2, 3, 4};
  std::stack<int, std::deque<int>> x{q1};
  assertThat(x).hasSizeThat().isEqualTo(4);
}
