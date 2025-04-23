#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>
#include <memory.h>

// IWYU pragma: private, include <assertcc/assertcc.h>

namespace assertcc::proposition {

template <typename T, typename U>
class ExpiredPropositions : public virtual subject::Base<U> {
 public:
  T& isExpired() {
    if (!this->getObject()->expired()) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("Expected the weak_ptr to be expired")
          .fact("Got non-expired weak_ptr")
          .build();
    }
    return *dynamic_cast<T*>(this);
  }

  T& isNotExpired() {
    if (this->getObject()->expired()) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("Expected the weak_ptr to not be expired")
          .fact("Got expired weak_ptr")
          .build();
    }
    return *dynamic_cast<T*>(this);
  }
};

}  // namespace assertcc::proposition