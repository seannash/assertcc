#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>
#include <memory.h>

#include <set>
#include <vector>

namespace assertcc::proposition {

template <typename T, typename U>
class ContainsPropositions : public virtual subject::Base<U> {
 public:
  template <typename Value>
  T& contains(const Value& value) {
    if (this->getObject()->find(value) == this->getObject()->end()) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("contains value", value)
          .fact("Got", this->getObjectAsString());
    }
    return *dynamic_cast<T*>(this);
  }

  template <typename Value>
  T& doesNotContain(const Value& value) {
    auto iter = this->getObject()->find(value);
    if (iter != this->getObject()->end()) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("to not contain the value ", value)
          .fact("Got", this->getObjectAsString())
          .build();
    }
    return *dynamic_cast<T*>(this);
  }
};

}  // namespace assertcc::proposition