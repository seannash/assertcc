#pragma once

#include <assertcc/proposition/hasvaluethatpropositions.h>
#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/proposition/isnullpropositions.h>
#include <assertcc/subject/base.h>

#include <memory>

namespace assertcc::subject {

template <typename T>
class SharedPtrSubject : public virtual Base,
                         public proposition::HasValueThatPropositions<T>,
                         public proposition::IsEqualToPropositions<SharedPtrSubject<T>, T>,
                         public proposition::IsNullPropositions<SharedPtrSubject<T>, T> {
  const T d_value;

 protected:
  const T* getValue() const override { return &d_value; }

 public:
  SharedPtrSubject(const bool failOnError, const char* file, int line, const T v)
      : Base(failOnError, file, line), d_value(v) {}
};

}  // namespace assertcc::subject