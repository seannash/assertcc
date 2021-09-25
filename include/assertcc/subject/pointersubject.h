#pragma once

#include <assertcc/proposition/hasvaluethatpropositions.h>
#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/proposition/isnullpropositions.h>
#include <assertcc/subject/base.h>

#include <sstream>
#include <string>
#include <type_traits>

namespace assertcc {

namespace subject {
template <typename T>
class PointerSubject : public virtual Base,
                       public proposition::HasValueThatPropositions<T>,
                       public proposition::IsEqualToPropositions<PointerSubject<T>, T>,
                       public proposition::IsNullPropositions<PointerSubject<T>, T> {
  const T d_value;

 protected:
  const T* getValue() const override { return &d_value; }

 public:
  PointerSubject(const bool failOnError, const char* file, int line, const T v)
      : Base(failOnError, file, line), d_value(v) {}
};

}  // namespace subject

}  // namespace assertcc