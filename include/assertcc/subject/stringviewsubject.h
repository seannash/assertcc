#pragma once

#include <assertcc/proposition/hassizepropositions.h>
#include <assertcc/proposition/isemptypropositions.h>
#include <assertcc/subject/base.h>

#include <string_view>

namespace assertcc::subject {

template <typename T>
class StringViewSubject : public virtual Base,
                          public proposition::HasLengthPropositions<StringViewSubject<T>, T>,
                          public proposition::HasSizePropositions<StringViewSubject<T>, T>,
                          public proposition::IsEmptyPropositions<StringViewSubject<T>, T> {
  const T d_value;

 protected:
  const T* getValue() const override { return &d_value; }

 public:
  StringViewSubject(const bool failOnError, const char* file, int line, const T& v)
      : Base(failOnError, file, line), d_value(v) {}
};

}  // namespace assertcc::subject