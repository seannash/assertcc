#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>
#include <memory.h>

namespace assertcc {

namespace proposition {

template <typename T, typename U>
class IsEmptyPropositions : public virtual subject::Base {
 protected:
  virtual const U* getValue() const = 0;

 public:
  T& isEmpty() {
    if (!getValue()->empty()) {
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("map to be empty")
          .fact("Got", *getValue());
    }
    return *dynamic_cast<T*>(this);
  }

  T& isNotEmpty() {
    if (getValue()->empty()) {
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("map to not be empty")
          .fact("Got", *getValue());
    }
    return *dynamic_cast<T*>(this);
  }
};

}  // namespace proposition

}  // namespace assertcc