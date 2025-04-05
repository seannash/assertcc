#pragma once

#include <assertcc/proposition/hassizepropositions.h>
#include <assertcc/proposition/isemptypropositions.h>
#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/subject/base.h>

#include <stack>

namespace assertcc::subject {

template <typename T>
class StackSubject : public virtual Base,
                     public proposition::HasSizePropositions<StackSubject<T>, T>,
                     public proposition::IsEmptyPropositions<StackSubject<T>, T>,
                     public proposition::IsEqualToPropositions<StackSubject<T>, T> {
  const T d_value;

 protected:
  const T* getValue() const override { return &d_value; }

 public:
  StackSubject(const bool failOnError, const char* file, int line, const T& v)
      : Base(failOnError, file, line), d_value(v) {}
};

}  // namespace assertcc::subject