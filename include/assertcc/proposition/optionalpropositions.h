#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>

namespace assertcc::proposition {

template <typename T, typename U>
class OptionalPropositions : public virtual subject::Base<U> {
 public:
  T& isPresent() {
    if (!*this->getObject()) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("optional to have a value")
          .fact("Got", this->getObjectAsString());
    }
    return *dynamic_cast<T*>(this);
  }

  T& isEmpty() {
    if (*this->getObject()) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .expected("Expected the optional to be empty.")
          .fact("Got", this->getObjectAsString())
          .build();
    }
    return *dynamic_cast<T*>(this);
  }
};

}  // namespace assertcc::proposition 