#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>
#include <memory.h>

namespace assertcc::proposition {

template <typename T, typename U>
class IsNullPropositions : public virtual subject::Base<U> {

 public:
  T& isNull() {
    if (*this->getObject()) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("pointer to be null")
          .fact("Got", this->getObjectAsString())
          .build();
    }
    return *dynamic_cast<T*>(this);
  }

  T& isNotNull() {
    if (!*this->getObject()) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("pointer to not be null")
          .fact("Got", this->getObjectAsString())
          .build();
    }
    return *dynamic_cast<T*>(this);
  }
};

}  // namespace assertcc::proposition
