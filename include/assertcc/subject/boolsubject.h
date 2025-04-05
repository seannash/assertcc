#pragma once

#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>

namespace assertcc::subject {

class BoolSubject : virtual public Base<bool>,
                    public proposition::IsEqualToPropositions<BoolSubject, bool> {
  const bool d_value;

 protected:
  const bool* getObject() const override { return &d_value; }
  const std::string getObjectAsString(const bool& other) const override  {
    return other ? "true" : "false";
  }

 public:
  BoolSubject(const bool failOnError, const char* file, int line, const bool v)
      : Base<bool>(failOnError, file, line), d_value(v) {}

  BoolSubject& isTrue() {
    if (d_value != true) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("expected boolean to have the value of true")
          .fact("value was ", getObjectAsString(d_value))
          .build();
    }
    return *this;
  }

  BoolSubject& isFalse() {
    if (d_value != false) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("expected boolean to have the value of false")
          .fact("value was ", getObjectAsString(d_value))
          .build();
    }
    return *this;
  }
};

}  // namespace assertcc::subject
