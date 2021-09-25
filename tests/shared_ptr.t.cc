#include <assertcc/assertcc.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

#include <memory>

using namespace testing;

TEST(SharedPtr, IsNull) {
  std::shared_ptr<int> p;
  assertThat(p).isNull();
}

TEST(SharedPtr, ExpectIsNull) {
  std::shared_ptr<int> p;
  expectThat(p).isNull();
}

TEST(SharedPtr, IsNotNull) {
  auto p = std::make_shared<int>(2);
  assertThat(p).isNotNull();
}

TEST(SharedPtr, Value) {
  auto p = std::make_shared<int>(2);
  assertThat(p).hasValueThat().isEqualTo(2);
}

TEST(SharedPtr, NotEqual) {
  auto p = std::make_shared<int>(1);
  auto q = std::make_shared<int>(1);
  assertThat(p).isNotEqualTo(q);
}

TEST(SharedPtr, IsEqualTo) {
  auto p = std::make_shared<int>(1);
  assertThat(p).isEqualTo(p);
}
