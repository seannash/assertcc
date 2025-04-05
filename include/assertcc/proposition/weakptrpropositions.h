#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>
#include <memory>

namespace assertcc::proposition {

template <typename T, typename U>
class WeakPtrPropositions : public virtual subject::Base<std::weak_ptr<U>> {

 public:
  T& isExpired() {
    if (!this->getObject()->expired()) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("weak_ptr to be expired")
          .fact("Got", this->getObjectAsString());
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
          .fact("Got", this->getObjectAsString())
          .build();
    }
    return *dynamic_cast<T*>(this);
  }
};

}  // namespace assertcc::proposition 