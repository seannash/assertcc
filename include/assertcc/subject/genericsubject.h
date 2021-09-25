#pragma once

#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/subject/base.h>

#include <optional>
#include <sstream>
#include <string>
#include <vector>

namespace assertcc {

namespace subject {

template <typename T>
class GenericSubject : public proposition::IsEqualToPropositions<GenericSubject<T>, T> {
  const T& d_value;

 protected:
  const T* getValue() const override { return &d_value; }

 public:
  GenericSubject(const bool failOnError, const char* file, int line, const T& v)
      : Base(failOnError, file, line), d_value(v) {}
};

}  // namespace subject

}  // namespace assertcc