#include <assertcc/assertcc.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

using namespace testing;

TEST(BoolSubjectTests, IsTrue) {
  bool b = true;
  assertThat(b).isTrue();
  assertThat(true).isTrue();
}

TEST(BoolSubjectTests, ExpectIsTrue) {
  bool b = true;
  expectThat(b).isTrue();
  expectThat(true).isTrue();
}

TEST(BoolSubjectTests, IsFalse) {
  bool b = false;
  assertThat(b).isFalse();
  assertThat(false).isFalse();
}

TEST(BoolSubjectTests, CanAssertTrueAndFalse) {
  bool b0 = true;
  assertThat(b0).isTrue();
  bool b1 = false;
  assertThat(b1).isFalse();
  assertThat(true).isTrue();
  assertThat(false).isFalse();
}

TEST(BoolSubjectTests, NotEqualTo) {
  bool b0 = true;
  bool b1 = false;
  assertThat(b0).isNotEqualTo(b1).isNotEqualTo(false);
  assertThat(b1).isNotEqualTo(b0).isNotEqualTo(true);
}

TEST(BoolSubjectTests, EqualTo) {
  bool b0 = true;
  bool b1 = true;
  assertThat(b0).isEqualTo(b1).isEqualTo(true);
  assertThat(b1).isEqualTo(b1).isEqualTo(true);
  assertThat(true).isEqualTo(true);
  assertThat(false).isEqualTo(false);
}
