#include <assertcc/assertcc.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

#if __cpp_lib_flat_set

#include <flat_set>

/*
TODO: No library support for flat_set yet so used this to fake it in order to test the tests.
      Need to remove the check for __cpp_lib_flat_set to use this.
#include <set>
namespace std {
template <typename T>
using flat_set = set<T>;
}
*/

using namespace testing;

TEST(FlatSetTests, IsEmpty) {
  std::flat_set<int> x{};
  assertThat(x).isEmpty();
}

TEST(FlatSetTests, ExpectisEmpty) {
  std::flat_set<int> x{};
  expectThat(x).isEmpty();
}

TEST(FlatSetTests, IsNotEmpty) {
  std::flat_set<int> x{1, 2, 3};
  assertThat(x).isNotEmpty();
}

TEST(FlatSetTests, IsEqual) {
  std::flat_set<int> x{1, 2, 3};
  std::flat_set<int> y{1, 2, 3};
  assertThat(x).isEqualTo(y);
}

TEST(FlatSetTests, IsNotEqual) {
  std::flat_set<int> x{1, 2, 3};
  std::flat_set<int> y{11, 22, 33};
  assertThat(x).isNotEqualTo(y);
}

TEST(FlatSetTests, Size) {
  std::flat_set<int> x{1, 2, 3};
  assertThat(x).hasSizeThat().isEqualTo(3);
}

#endif
