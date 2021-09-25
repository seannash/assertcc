#pragma once

#include <assertcc/proposition/hassizepropositions.h>
#include <assertcc/proposition/isemptypropositions.h>
#include <assertcc/subject/base.h>

#include <stack>

namespace assertcc {

namespace subject {

template <typename T>
class PriorityQueueSubject : public virtual Base,
                             public proposition::HasSizePropositions<PriorityQueueSubject<T>, T>,
                             public proposition::IsEmptyPropositions<PriorityQueueSubject<T>, T> {
  const T d_value;

 protected:
  const T* getValue() const override { return &d_value; }

 public:
  PriorityQueueSubject(const bool failOnError, const char* file, int line, const T& v)
      : Base(failOnError, file, line), d_value(v) {}
};

}  // namespace subject

}  // namespace assertcc