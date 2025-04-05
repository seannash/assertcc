#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>
#include <memory.h>

namespace assertcc::proposition {

template <typename T, typename U>
class ValueContainsPropositions : public virtual subject::Base {
 protected:
  virtual const U* getValue() const = 0;

 public:
  T& contains(const U& other) {
    if (!getValue()->value() == other) {
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("contains ", other)
          .fact("Got", *getValue());
    }
    return *dynamic_cast<T*>(this);
  }

  T& doesNotContain(const U& other) {
    if (getValue()->value() == other) {
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("does not contain ", other)
          .fact("Got", *getValue());
    }
    return *dynamic_cast<T*>(this);
  }
};

}  // namespace assertcc::proposition