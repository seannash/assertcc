#pragma once

#include <assertcc/proposition/hasvaluethatpropositions.h>
#include <assertcc/proposition/isequaltopropositions.h>
//#include <assertcc/proposition/ispresentpropositions.h>
#include <assertcc/proposition/valuecontainerpropositions.h>
#include <assertcc/proposition/optionalpropositions.h>
#include <assertcc/subject/base.h>

#include <optional>
#include <sstream>
#include <string>

namespace assertcc::subject {

template <typename T>
class OptionalSubject : public virtual Base<T>,
                        public proposition::HasValueThatPropositions<T>,
                        public proposition::IsEqualToPropositions<OptionalSubject<T>, T>,
                        public proposition::ValueContainsPropositions<OptionalSubject<T>, T>,
                        public proposition::OptionalPropositions<OptionalSubject<T>, T> {
  const T d_value;

 protected:
  const T* getObject() const override { return &d_value; }
  const std::string getObjectAsString(const T& other) const override {
    std::stringstream ss;
    if (other) {
      ss << "Optional(" << *other << ")";
    } else {
      ss << "Optional.empty";
    }
    return ss.str();
  }

 public:
  OptionalSubject(const bool failOnError, const char* file, int line, const T& v)
      : Base<T>(failOnError, file, line), d_value(v) {}

};

}  // namespace assertcc::subject
