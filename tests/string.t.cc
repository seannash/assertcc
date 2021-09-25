#include <assertcc/assertcc.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

#include <string>

using namespace testing;

TEST(StringTests, isEmpty) {
  std::string x{""};
  assertThat(x).isEmpty();
}

TEST(StringTests, ExpectisEmpty) {
  std::string x{""};
  expectThat(x).isEmpty();
}

TEST(StringTests, isNotEmpty) {
  std::string x{"hello"};
  assertThat(x).isNotEmpty();
}

TEST(StringTests, isEqual) {
  std::string x{"hello"};
  std::string y{"hello"};
  assertThat(x).isEqualTo(y);
  assertThat(x).isEqualTo("hello");
}

TEST(StringTests, isNotEqual) {
  std::string x{"hello"};
  std::string y{"sdgfifgh"};
  assertThat(x).isNotEqualTo(y);
}

TEST(StringTests, HasSize) {
  std::string str{"hello"};
  assertThat(str).hasSize(5);
}

TEST(StringTests, HasSizeThat) {
  std::string str{"hello"};
  assertThat(str).hasSizeThat().isEqualTo(5);
}

TEST(StringTests, Contains) {
  std::string str{"hello"};
  assertThat(str).contains("el");
}

TEST(StringTests, DoesNotContain) {
  std::string str{"hello"};
  assertThat(str).doesNotContain("ABC");
}

TEST(StringTests, StartsWith) {
  std::string str{"hello"};
  assertThat(str).startsWith("hel");
}

TEST(StringTests, EndsWith) {
  std::string str{"hello"};
  assertThat(str).endsWith("llo");
}

TEST(StringTests, ContainsMatch) {
  std::string str{"hello"};
  assertThat(str).containsMatch("l.o");
}

TEST(StringTests, DoesNotContainsMatch) {
  std::string str{"hello"};
  assertThat(str).doesNotContainMatch("z.o");
}

TEST(StringTests, Matches) {
  std::string str{"hello"};
  assertThat(str).matches("hel.o");
}

TEST(StringTests, DoesNotMatch) {
  std::string str{"hello"};
  assertThat(str).doesNotMatch("z.o");
}
