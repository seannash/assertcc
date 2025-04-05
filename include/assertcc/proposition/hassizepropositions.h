#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/subject/integralsubject.h>
#include <assertcc/util/failmessage.h>
#include <memory.h>

namespace assertcc::proposition {

template <typename T, typename U>
class HasSizePropositions : public virtual subject::Base {
 protected:
  virtual const U* getValue() const = 0;

 public:
  T& hasSize(std::size_t size) {
    if (getValue()->size() != size) {
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("size is equal to", size)
          .fact("Got", *getValue());
    }
    return *dynamic_cast<T*>(this);
  }

  subject::IntegralSubject<std::size_t> hasSizeThat() {
    return subject::IntegralSubject<std::size_t>(
        getFailOnError(), getFile(), getLine(), (std::size_t)getValue()->size());
  }

};

}  // namespace assertcc::proposition