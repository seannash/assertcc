#include <assertcc/adl.h>
#include <assertcc/assertcc.h>
#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

using namespace testing;

class Foo {
 public:
  int x;
  bool operator==(const Foo& rhs) const { return x == rhs.x; }
};

std::ostream& operator<<(std::ostream& os, const Foo& foo) {
  os << "[Foo " << foo.x << " ]";
  return os;
}

class FooSubject : public virtual assertcc::subject::Base,
                   public assertcc::proposition::IsEqualToPropositions<FooSubject, Foo> {
  const Foo& d_value;

 protected:
  const Foo* getValue() const override { return &d_value; }

 public:
  FooSubject(const bool failOnError, const char* file, int line, const Foo& v)
      : Base(failOnError, file, line), d_value(v) {}
  FooSubject& contains42() {
    if (getValue()->x != 42) {
      assertcc::util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("Expected the value to be equal to 42")
          .fact("Got", *getValue());
    }
    return *this;
  }
};

namespace assertcc {
auto assert_that_internal(
    Adl dummy, const bool failOnError, const char* file, int line, const Foo& foo) {
  // v needs to be a reference otherwise GenericSubject
  // will store a reference to a temporary
  return FooSubject(false, file, line, foo);
}
}  // namespace assertcc

TEST(UserSubjectTests, isEqual) {
  Foo a{1};
  Foo b{1};
  assertThat(a).isEqualTo(b);
}

TEST(UserSubjectTests, ExpectIsEqual) {
  Foo a{1};
  Foo b{1};
  expectThat(a).isEqualTo(b);
}

TEST(UserSubjectTests, isNotEqual) {
  Foo a{1};
  Foo b{2};
  assertThat(a).isNotEqualTo(b);
}

TEST(UserSubjectTests, Contains42) {
  Foo a{42};
  assertThat(a).contains42();
}
