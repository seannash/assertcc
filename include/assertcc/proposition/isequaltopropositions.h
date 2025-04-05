#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>
#include <memory.h>

namespace assertcc::proposition {

template <typename T, typename U>
class IsEqualToPropositions : public virtual subject::Base<U> {

 public:
 
  T& isEqualTo(const U& other) {
    if (!(*this->getObject() == other)) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("not equal to", this->getObjectAsString(other))
          .fact("Got", this->getObjectAsString())
          .build();
    }
    return *dynamic_cast<T*>(this);
  }

  T& isNotEqualTo(const U& other) {
    if (*this->getObject() == other) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("not equal to", this->getObjectAsString(other))
          .fact("Got", this->getObjectAsString())
          .build();
    }
    return *dynamic_cast<T*>(this);
  }
};

}  // namespace assertcc::proposition
