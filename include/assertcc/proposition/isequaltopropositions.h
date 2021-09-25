#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>
#include <memory.h>

namespace assertcc {

namespace proposition {

template <typename T, typename U>
class IsEqualToPropositions : public virtual subject::Base {
 protected:
  virtual const U* getValue() const = 0;

 public:
  T& isEqualTo(const U& other) {
    if (!(*getValue() == other)) {
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("not equal to", other)
          .fact("Got", *getValue());
    }
    return *dynamic_cast<T*>(this);
  }

  T& isNotEqualTo(const U& other) {
    if (*getValue() == other) {
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("not equal to", other)
          .fact("Got", *getValue());
    }
    return *dynamic_cast<T*>(this);
  }
};

}  // namespace proposition

}  // namespace assertcc
