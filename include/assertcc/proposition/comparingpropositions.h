#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>
#include <memory.h>

namespace assertcc::proposition {

template <typename T, typename U>
class ComparisonPropositions : public virtual subject::Base<U> {

 public:

  T& isLessThan(const U& other) {
    if (*this->getObject() >= other) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("value is not finite", other)
          .fact("Got", this->getObjectAsString())
          .build();
    }
    return *dynamic_cast<T*>(this);
  }

  T& isAtMost(const U& other) {
    if (!(*this->getObject() <= other)) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("less than or equal to", other)
          .fact("Got", this->getObjectAsString())
          .build();
    }
    return *dynamic_cast<T*>(this);
  }

  T& isGreaterThan(const U& other) {
    if (!(*this->getObject() > other)) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("greater than", other)
          .fact("Got", this->getObjectAsString())
          .build();
    }
    return *dynamic_cast<T*>(this);
  }

  T& isAtLeast(const U& other) {
    if (!(*this->getObject() >= other)) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("greater than or equal to", other)
          .fact("Got", this->getObjectAsString())
          .build();
    }
    return *dynamic_cast<T*>(this);
  }
};

}  // namespace assertcc::proposition
