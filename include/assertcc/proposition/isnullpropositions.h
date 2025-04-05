#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>
#include <memory.h>

namespace assertcc::proposition {

template <typename T, typename U>
class IsNullPropositions : public virtual subject::Base {
 protected:
  virtual const U* getValue() const = 0;

 public:
  T& isNull() {
    if (*getValue()) {
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("pointer to be null")
          .fact("Got", *getValue());
    }
    return *dynamic_cast<T*>(this);
  }

  T& isNotNull() {
    if (!*getValue()) {
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("pointer to not be null")
          .fact("Got", *getValue());
    }
    return *dynamic_cast<T*>(this);
  }
};

}  // namespace assertcc::proposition