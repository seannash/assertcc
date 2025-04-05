#pragma once

#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/subject/base.h>

#include <optional>
#include <sstream>
#include <string>
#include <vector>

namespace assertcc::subject {

template <typename T>
class GenericSubject : public virtual Base<T>,
                       public proposition::IsEqualToPropositions<GenericSubject<T>, T> {
  const T& d_value;

 protected:
  const T* getObject() const override { return &d_value; }
  const std::string getObjectAsString() const override {
    std::stringstream ss;
    ss << d_value;
    return ss.str();
  }
  const std::string getObjectAsString(const T& other) const override {
    std::stringstream ss;
    ss << other;
    return ss.str();
  }

 public:
  GenericSubject(const bool failOnError, const char* file, int line, const T& v)
      : Base<T>(failOnError, file, line), d_value(v) {}

};

}  // namespace assertcc::subject
