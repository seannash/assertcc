#include <assertcc/assertcc.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

#include <span>
#include <vector>

using namespace testing;

TEST(SpanTests, isEmpty) {
  std::vector<int> data{};
  std::span<int> view(data);
  assertThat(view).isEmpty();
}

TEST(SpanTests, ExpectIsEmpty) {
  std::vector<int> data{};
  std::span<int> view(data);
  expectThat(view).isEmpty();
}

TEST(SpanTests, isNotEmpty) {
  std::vector<int> data{1, 2, 3};
  std::span<int> view(data);
  assertThat(view).isNotEmpty();
}

TEST(SpanTests, Size) {
  std::vector<int> data{1, 2, 3};
  std::span<int> view(data);
  assertThat(view).hasSizeThat().isEqualTo(3);
}
