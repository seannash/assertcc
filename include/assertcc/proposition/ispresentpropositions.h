#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>
#include <memory.h>

// IWYU pragma: private, include <assertcc/assertcc.h>

namespace assertcc::proposition {

template <typename T, typename U>
class IsPresentPropositions : public virtual subject::Base<U> {

 public:
  T& isPresent() {
    if (!this->getObject()->present()) {
      util::FailMessage::create()
          .file(this->getFile())
          .line(this->getLine())
          .fact("map to be empty")
          .fact("Got", this->getObjectAsString())
          .build();
    }
    return *dynamic_cast<T*>(this);
  }
};

}  // namespace assertcc::proposition