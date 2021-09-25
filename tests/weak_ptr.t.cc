#include <assertcc/assertcc.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

#include <memory>

using namespace testing;

TEST(WeakPtrSubjectTests, IsExpired) {
  std::weak_ptr<int> p;
  assertThat(p).isExpired();
}

TEST(WeakPtrSubjectTests, IsNotExpired) {
  auto sp = std::make_shared<int>(1);
  std::weak_ptr<int> p = sp;
  assertThat(p).isNotExpired();
}

TEST(WeakPtrSubjectTests, Value) {
  auto p = std::make_unique<int>(3);
  assertThat(p).hasValueThat().isEqualTo(3);
  assertThat(p).isNotNull();
}

TEST(WeakPointer, Value) {
  std::shared_ptr<int> p0 = std::make_shared<int>(5);
  std::weak_ptr<int> wp = p0;
  assertThat(wp).isNotExpired().value().isEqualTo(5);
}
