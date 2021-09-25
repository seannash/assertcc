#pragma once

#include <assertcc/proposition/hassizepropositions.h>
#include <assertcc/proposition/isemptypropositions.h>
#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/subject/base.h>

#include <map>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

namespace assertcc {

namespace subject {

template <typename T>
class MultiMapSubject : public virtual Base,
                        public proposition::HasSizePropositions<MultiMapSubject<T>, T>,
                        public proposition::IsEmptyPropositions<MultiMapSubject<T>, T>,
                        public proposition::IsEqualToPropositions<MultiMapSubject<T>, T> {
  const T d_value;

 protected:
  const T* getValue() const override { return &d_value; }

 public:
  MultiMapSubject(const bool failOnError, const char* file, int line, const T& v)
      : Base(failOnError, file, line), d_value(v) {}
};

}  // namespace subject

}  // namespace assertcc