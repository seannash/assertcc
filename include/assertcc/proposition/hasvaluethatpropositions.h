#pragma once

#include <assertcc/adl.h>
#include <assertcc/assertcc.h>
#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>
#include <memory.h>

namespace assertcc::proposition {

template <typename U>
class HasValueThatPropositions : public virtual subject::Base {
 protected:
  virtual const U* getValue() const = 0;

 public:
  auto hasValueThat() {
    return assert_that_internal(
        assertcc::Adl(), getFailOnError(), getFile(), getLine(), **getValue());
  }
};

}  // namespace assertcc::proposition