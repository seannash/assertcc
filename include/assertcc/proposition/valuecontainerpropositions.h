#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>
#include <memory.h>
#include <functional>

namespace assertcc::proposition {

template <typename T, typename U>
class ValueContainsPropositions : public virtual subject::Base<U> {

 public:
  T& contains(const U& other) {
    if (!this->getObject()->value() == other) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("contains ", this->getObjectAsString(other))
          .fact("Got", this->getObjectAsString());
    }
    return *dynamic_cast<T*>(this);
  }

  T& doesNotContain(const U& other) {
    if (this->getObject()->value() == other) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("does not contain ", this->getObjectAsString(other))
          .fact("Got", this->getObjectAsString())
          .build();
    }
    return *dynamic_cast<T*>(this);
  }

};

}  // namespace assertcc::proposition
