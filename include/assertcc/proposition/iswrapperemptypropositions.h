#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>
#include <memory.h>

// IWYU pragma: private, include <assertcc/assertcc.h>

namespace assertcc::proposition {

template <typename T, typename U>
class IsWrapperEmptyPropositions : public virtual subject::Base {

 public:
  T& isEmpty() {
    if (*getObject()) {
      util::FailMessage::create()
          .failOnError(getFailOnError())
          .file(getFile())
          .line(getLine())
          .fact("object to have a value")
          .fact("Got", "object without a value")
          .build();
    }
    return *dynamic_cast<T*>(this);
  }

  T& isNotEmpty() {
    if (!*getObject()) {
      util::FailMessage::create()
          .failOnError(getFailOnError())
          .file(getFile())
          .line(getLine())
          .fact("object to not have a value")
          .fact("Got", getObjectAsString())
          .build();
    }
    return *dynamic_cast<T*>(this);
  }
};

}  // namespace assertcc::proposition