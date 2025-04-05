#include <assertcc/assertcc.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

#include <string>

using namespace testing;

TEST(StringView, isEmpty) {
  std::string_view sv;
  assertThat(sv).isEmpty();
}
/*
TEST(StringView, ExpectIsEmpty) {
  std::string_view sv;
  expectThat(sv).isEmpty();
}

TEST(StringView, isNotEmpty) {
  std::string str{"Hello World!"};
  std::string_view sv(str);
  assertThat(sv).isNotEmpty();
}

TEST(StringView, Size) {
  std::string str{"123456"};
  std::string_view sv(str);
  assertThat(sv).hasSizeThat().isEqualTo(6);
}

TEST(StringView, HasSize) {
  std::string str{"hello"};
  std::string_view sv(str);
  assertThat(sv).hasLength(5);
}
*/