#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>
#include <memory.h>

// IWYU pragma: private, include <assertcc/assertcc.h>

namespace assertcc::proposition {

template <typename T, typename U>
class IsWrapperEmptyPropositions : public virtual subject::Base<U> {

 public:
  T& isEmpty() {
    if (*this->getObject()) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("object to have a value")
          .fact("Got", "object without a value")
          .build();
    }
    return *dynamic_cast<T*>(this);
  }

};

}  // namespace assertcc::proposition