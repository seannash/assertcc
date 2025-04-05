#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/subject/integralsubject.h>
#include <assertcc/util/failmessage.h>

#include <limits>
#include <memory>

namespace assertcc::proposition {

template <typename T, typename U>
class HasLengthPropositions : public virtual subject::Base {
 protected:
  virtual const U* getValue() const = 0;

 public:
  T& hasLength(const std::size_t length) {
    if (getValue()->length() != length) {
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("length is equal to", length)
          .fact("Got", getValue()->length());
    }
    return *dynamic_cast<T*>(this);
  }

  subject::IntegralSubject<std::size_t> hasLengthThat() {
    return subject::IntegralSubject<std::size_t>(
        getFailOnError(), getFile(), getLine(), (std::size_t)getValue()->length());
  }
};

}  // namespace assertcc::proposition