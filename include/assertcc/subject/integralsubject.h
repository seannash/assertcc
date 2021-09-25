#pragma once

#include <assertcc/proposition/comparingpropositions.h>
#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/proposition/isinpropositions.h>
#include <assertcc/subject/base.h>

namespace assertcc {

namespace subject {

template <typename T>
class IntegralSubject : public virtual Base,
                        public proposition::IsEqualToPropositions<IntegralSubject<T>, T>,
                        public proposition::IsInPropositions<IntegralSubject<T>, T>,
                        public proposition::ComparisonPropositions<IntegralSubject<T>, T> {
  const T d_value;

 protected:
  const T* getValue() const override { return &d_value; }

 public:
  IntegralSubject(const bool failOnError, const char* file, int line, const T& v)
      : Base(failOnError, file, line), d_value(v) {}
};

}  // namespace subject

}  // namespace assertcc