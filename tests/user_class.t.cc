#include <assertcc/adl.h>
#include <assertcc/assertcc.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

#include <ostream>

using namespace testing;

class A {
 public:
  int x;
  bool operator==(const A& rhs) const { return x == rhs.x; }
};

std::ostream& operator<<(std::ostream& os, const A& a) {
  os << "[A " << a.x << " ]";
  return os;
}

namespace assertcc {
auto assert_that_internal(
    Adl dummy, const bool failOnError, const char* file, int line, const A& v) {
  // v needs to be a reference otherwise UserClassTests
  // will store a reference to a temporary
  return assertcc::subject::GenericSubject(false, file, line, v);
}
}  // namespace assertcc

TEST(UserClassTests, IsEqual) {
  A a{1};
  A b{1};
  assertThat(a).isEqualTo(b);
}

TEST(UserClassTests, ExpectIsEqual) {
  A a{1};
  A b{1};
  expectThat(a).isEqualTo(b);
}

TEST(UserClassTests, IsNotEqual) {
  A a{1};
  A b{2};
  assertThat(a).isNotEqualTo(b);
}
