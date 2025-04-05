#pragma once

#include <assertcc/proposition/comparingpropositions.h>
#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/proposition/isinpropositions.h>
#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>

namespace assertcc::subject {

template <typename T>
class IntegralSubject : public virtual Base<T>,
public proposition::IsEqualToPropositions<IntegralSubject<T>, T>,
                        public proposition::IsInPropositions<IntegralSubject<T>, T>,
                        public proposition::ComparisonPropositions<IntegralSubject<T>, T> {
  const T d_value;

 protected:
  const T* getObject() const override { return &d_value; }
  const std::string getObjectAsString() const override { return std::to_string(d_value); }
  const std::string getObjectAsString(const T& other) const override {
    return std::to_string(other);
  }

 public:
  IntegralSubject(const bool failOnError, const char* file, int line, const T& v)
      : Base<T>(failOnError, file, line), d_value(v) {}

};

}  // namespace assertcc::subject
