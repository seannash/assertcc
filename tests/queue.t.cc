#include <assertcc/assertcc.h>
#include <gtest/gtest.h>

#include <queue>

using namespace testing;

TEST(QueueTests, isEmpty) {
  std::queue<int> x{};
  assertThat(x).isEmpty();
}

TEST(QueueTests, isNotEmpty) {
  std::queue<int> x;
  x.push(1);
  assertThat(x).isNotEmpty();
}

TEST(QueueTests, hasSize) {
  std::queue<int> x;
  x.push(1);
  x.push(2);
  x.push(3);
  assertThat(x).hasSize(3);
}

TEST(QueueTests, hasSizeThat) {
  std::queue<int> x;
  x.push(1);
  x.push(2);
  x.push(3);
  assertThat(x).hasSizeThat().isEqualTo(3);
}

TEST(QueueTests, hasFrontThat) {
  std::queue<int> x;
  x.push(1);
  x.push(2);
  assertThat(x).hasFrontThat().isEqualTo(1);
}

TEST(QueueTests, hasFrontThatWithString) {
  std::queue<std::string> x;
  x.push("hello");
  x.push("world");
  assertThat(x).hasFrontThat().isEqualTo("hello");
}

TEST(QueueTests, hasBackThat) {
  std::queue<int> x;
  x.push(1);
  x.push(2);
  assertThat(x).hasBackThat().isEqualTo(2);
}

TEST(QueueTests, hasBackThatWithString) {
  std::queue<std::string> x;
  x.push("hello");
  x.push("world");
  assertThat(x).hasBackThat().isEqualTo("world");
}

TEST(QueueTests, frontAndBackWithSingleElement) {
  std::queue<int> x;
  x.push(42);
  assertThat(x).hasFrontThat().isEqualTo(42);
  assertThat(x).hasBackThat().isEqualTo(42);
}






