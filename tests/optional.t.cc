#include <assertcc/assertcc.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

#include <optional>

using namespace testing;

TEST(OptionalTests, isPresent) {
  std::optional<int> o{1};
  assertThat(o).isPresent();
}

TEST(OptionalTests, ExpectIsPresent) {
  std::optional<int> o{1};
  expectThat(o).isPresent();
}

TEST(OptionalTests, IsEmpty) {
  std::optional<int> o{};
  assertThat(o).isEmpty();
}

TEST(OptionalTests, Contains) {
  std::optional<int> o{1};
  assertThat(o).contains(1);
}

TEST(OptionalTests, DoesNotContain) {
  std::optional<int> o{1};
  assertThat(o).doesNotContain(2);
}

TEST(OptionalTests, Value) {
  std::optional<int> o{1};
  assertThat(o).hasValueThat().isEqualTo(1);
}

TEST(OptionalTests, IsEqualTo) {
  std::optional<int> x{1};
  std::optional<int> y{1};
  assertThat(x).isEqualTo(y);
}

TEST(OptionalTests, IsNotEqualTo) {
  std::optional<int> x{1};
  std::optional<int> y{3};
  assertThat(x).isNotEqualTo(y);
}
