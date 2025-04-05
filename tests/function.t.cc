#include <assertcc/assertcc.h>
#include <gtest/gtest.h>

#include <memory>
#include <functional>

using namespace testing;

int foo(int a, int b) {
  return a + b;
}

void bar()
{}

TEST(FunctionTests, IsNull) {
  std::function<int(int, int)> func(nullptr);
  assertThat(func).isNull();
}

TEST(FunctionTests, IsNotEmpty) {
  std::function<int(int, int)> func(foo);
  assertThat(func).isNotNull();
}
