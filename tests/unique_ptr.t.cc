#include <assertcc/assertcc.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

#include <memory>

using namespace testing;

TEST(UniquePtrSubjectTests, IsNull) {
  std::unique_ptr<int> p;
  assertThat(p).isNull();
}

TEST(UniquePtrSubjectTests, ExpectIsNull) {
  std::unique_ptr<int> p;
  expectThat(p).isNull();
}

TEST(UniquePtrSubjectTests, IsNotNull) {
  auto p = std::make_unique<int>(3);
  assertThat(p).isNotNull();
  assertThat(p).isNotNull();
}

TEST(UniquePtrSubjectTests, Value) {
  auto p = std::make_unique<int>(3);
  assertThat(p).hasValueThat().isEqualTo(3);
  assertThat(p).isNotNull();
}

TEST(UniquePtrSubjectTests, NotEqual) {
  auto p = std::make_unique<int>(1);
  auto q = std::make_unique<int>(1);
  assertThat(p).isNotEqualTo(q);
  assertThat(p).isNotEqualTo(q);
}

TEST(UniquePtrSubjectTests, EqualTo) {
  auto p = std::make_unique<int>(1);
  assertThat(p).isEqualTo(p);
}

TEST(UniquePtrSubjectTests, ExpectEqualTo) {
  auto p = std::make_unique<int>(1);
  expectThat(p).isEqualTo(p);
}
