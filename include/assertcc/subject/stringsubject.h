#pragma once

#include <assertcc/proposition/haslengthpropositions.h>
#include <assertcc/proposition/hassizepropositions.h>
#include <assertcc/proposition/isemptypropositions.h>
#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/proposition/isnullpropositions.h>
#include <assertcc/proposition/stringpropositions.h>
#include <assertcc/subject/base.h>

#include <string>

namespace assertcc::subject {

template <typename T>
class StringSubject : public virtual Base<T>,
                      public proposition::HasLengthPropositions<StringSubject<T>, T>,
                      public proposition::HasSizePropositions<StringSubject<T>, std::string>,
                      public proposition::IsEqualToPropositions<StringSubject<T>, T>,
                      public proposition::IsEmptyPropositions<StringSubject<T>, T>,
                      public proposition::StringPropositions<StringSubject<T>, T> {
  const T d_value;

 protected:
  const T* getObject() const override { return &d_value; }
  const T getObjectAsString(const T& other) const override { return d_value; }

 public:
  StringSubject(const bool failOnError, const char* file, int line, const T& v)
      : Base<T>(failOnError, file, line), d_value(v) {}
};

}  // namespace assertcc::subject
