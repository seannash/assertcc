#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/subject/integralsubject.h>
#include <assertcc/util/failmessage.h>

#include <limits>
#include <memory>

namespace assertcc::proposition {

template <typename T, typename U>
class HasLengthPropositions : public virtual subject::Base<U> {
 public:
  T& hasLength(const std::size_t length) {
    if (this->getObject()->length() != length) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("length is equal to", length)
          .fact("Got", this->getObjectAsString());
    }
    return *dynamic_cast<T*>(this);
  }

  subject::IntegralSubject<std::size_t> hasLengthThat() {
    return subject::IntegralSubject<std::size_t>(
        this->getFailOnError(), this->getFile(), this->getLine(), this->getObject()->length());
  }
};

}  // namespace assertcc::proposition
