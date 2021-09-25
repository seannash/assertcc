#include <assertcc/assertcc.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

#include <memory>

using namespace testing;

TEST(PointerTests, IsNull) {
  const char* p = nullptr;
  assertThat(p).isNull();
}

TEST(PointerTests, ExpectIsNull) {
  const char* p = nullptr;
  expectThat(p).isNull();
}

TEST(PointerTests, IsNotNull) {
  const char* p = "Message";
  assertThat(p).isNotNull();
}

TEST(PointerTests, Value) {
  const char* p = "a";
  assertThat(p).hasValueThat().isEqualTo('a');
}

TEST(PointerTests, IsNotEqual) {
  auto p = std::make_unique<int>(1);
  auto q = std::make_unique<int>(1);
  assertThat(p.get()).isNotEqualTo(q.get());
}

TEST(PointerTests, IsEqualTo) {
  const char* p = "a";
  assertThat(p).isEqualTo(p);
}
