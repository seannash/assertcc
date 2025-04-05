#pragma once

#include <assertcc/adl.h>
#include <assertcc/assertcc.h>
#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>
#include <memory.h>

namespace assertcc::proposition {

template <typename U>
class HasValueThatPropositions : public virtual subject::Base<U> {

 public:
  auto hasValueThat() {
    return assert_that_internal(
        assertcc::Adl(),
        this->getFailOnError(),
        this->getFile(),
        this->getLine(),
        **this->getObject());
  }
};

}  // namespace assertcc::proposition
