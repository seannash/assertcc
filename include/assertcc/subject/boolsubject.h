#pragma once

#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>

namespace assertcc {

namespace subject {
class BoolSubject : public virtual Base,
                    public proposition::IsEqualToPropositions<BoolSubject, bool> {
  const bool d_value;

 protected:
  const bool* getValue() const override { return &d_value; }

 public:
  BoolSubject(const bool failOnError, const char* file, int line, const bool v)
      : Base(failOnError, file, line), d_value(v) {}

  BoolSubject& isTrue() {
    if (d_value != true) {
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("expected boolean to have the value of true")
          .fact("value was ", d_value);
    }
    return *this;
  }

  BoolSubject& isFalse() {
    if (d_value != false) {
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("expected boolean to have the value of false")
          .fact("value was ", d_value);
    }
    return *this;
  }
};

}  // namespace subject

}  // namespace assertcc