#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/subject/genericsubject.h>

namespace assertcc::proposition {

template <typename T, typename U>
class HasBackThatPropositions : virtual public subject::Base<U> {
 public:
  auto hasBackThat() {
    return assert_that_internal(assertcc::Adl(),
                                this->getFailOnError(),
                                this->getFile(),
                                this->getLine(),
                                this->getObject()->back());
  }
};

}  // namespace assertcc::proposition