#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>
#include <memory.h>

// IWYU pragma: private, include <assertcc/assertcc.h>

namespace assertcc {

namespace proposition {

template <typename T, typename U>
class IsFunctionEqualToPropositions : public virtual subject::Base<U> {
 public:
  T& isEqualTo(const U& other) {
    if (!(*this->getObject() == other)) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("Functions are not equal")
          .build();
    }
    return *dynamic_cast<T*>(this);
  }

  T& isNotEqualTo(const U& other) {
    if (*getObject() == other) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("Functions are equal")
          .build();
    }
    return *dynamic_cast<T*>(this);
  }
};

}  // namespace proposition

}  // namespace assertcc
