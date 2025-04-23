#include <assertcc/adl.h>
#include <assertcc/assertcc.h>
#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

#include <sstream>

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

class FooSubject : public virtual assertcc::subject::Base<Foo>,
                   public assertcc::proposition::IsEqualToPropositions<FooSubject, Foo> {
  const Foo& d_value;

 protected:
  const Foo* getObject() const override { return &d_value; }
  const std::string getObjectAsString() const override { return getObjectAsString(*getObject()); }
  const std::string getObjectAsString(const Foo& other) const override {
    std::stringstream ss;
    ss << other;
    return ss.str();
  }

 public:
  FooSubject(const bool failOnError, const char* file, int line, const Foo& v)
      : Base<Foo>(failOnError, file, line), d_value(v) {}
  FooSubject& contains42() {
    if (getObject()->x != 42) {
      assertcc::util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("Expected the value to be equal to 42")
          .fact("Got", this->getObjectAsString())
          .build();
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
