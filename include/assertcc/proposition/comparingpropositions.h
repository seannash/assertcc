#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>
#include <memory.h>

namespace assertcc {

namespace proposition {

template <typename T, typename U>
class ComparisonPropositions : public virtual subject::Base {
 protected:
  virtual const U* getValue() const = 0;

 public:
  T& isLessThan(const U& other) {
    if (*getValue() >= other) {
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("value is not finite", other)
          .fact("Got", getValue());
    }
    return *dynamic_cast<T*>(this);
  }

  T& isAtMost(const U& other) {
    if (!(*getValue() <= other)) {
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("less than or equal to", other)
          .fact("Got", *getValue());
    }
    return *dynamic_cast<T*>(this);
  }

  T& isGreaterThan(const U& other) {
    if (!(*getValue() > other)) {
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("greater than", other)
          .fact("Got", *getValue());
    }
    return *dynamic_cast<T*>(this);
  }

  T& isAtLeast(const U& other) {
    if (!(*getValue() >= other)) {
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("greater than or equal to", other)
          .fact("Got", *getValue());
    }
    return *dynamic_cast<T*>(this);
  }
};

}  // namespace proposition

}  // namespace assertcc