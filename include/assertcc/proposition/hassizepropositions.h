#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/subject/integralsubject.h>
#include <assertcc/util/failmessage.h>
#include <memory.h>

namespace assertcc::proposition {

template <typename T, typename U>
class HasSizePropositions : public virtual subject::Base<U> {
 public:
  T& hasSize(std::size_t size) {
    if (this->getObject()->size() != size) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("size is equal to", size)
          .fact("Got", this->getObjectAsString());
    }
    return *dynamic_cast<T*>(this);
  }

  subject::IntegralSubject<std::size_t> hasSizeThat() {
    return subject::IntegralSubject<std::size_t>(
        this->getFailOnError(), this->getFile(), this->getLine(), this->getObject()->size());
  }
};

}  // namespace assertcc::proposition
