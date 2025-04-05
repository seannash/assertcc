#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>

namespace assertcc::proposition {

template <typename T>
class BooleanPropositions : public virtual subject::Base<bool> {

 public:
  T& isTrue() {
    if (*this->getObject() != true) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("expected boolean to have the value of true")
          .fact("value was ", this->getObjectAsString())
          .build();
    }
    return *dynamic_cast<T*>(this);
  }

  T& isFalse() {
    if (*this->getObject() != false) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("expected boolean to have the value of false")
          .fact("value was ", this->getObjectAsString())
          .build();
    }
    return *dynamic_cast<T*>(this);
  }
};

}  // namespace assertcc::proposition 