#pragma once

#include <assertcc/proposition/hasvaluethatpropositions.h>
#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/proposition/isnullpropositions.h>
#include <assertcc/subject/base.h>

#include <memory>

namespace assertcc::subject {

template <typename T>
class SharedPtrSubject : public virtual Base<T>,
public proposition::HasValueThatPropositions<T>,
                         public proposition::IsEqualToPropositions<SharedPtrSubject<T>, T>,
                         public proposition::IsNullPropositions<SharedPtrSubject<T>, T> {
  const T d_value;

 protected:
  const T* getObject() const override { return &d_value; }
  const std::string getObjectAsString() const override {
    return getObjectAsString(d_value);
  }
  const std::string getObjectAsString(const T& other) const override {
    if (other == nullptr) {
      return "nullptr";
    }
    std::stringstream ss;
    ss << "a pointer to address " << d_value;
    return ss.str();
  }

 public:
  SharedPtrSubject(const bool failOnError, const char* file, int line, const T v)
      : Base<T>(failOnError, file, line), d_value(v) {}

};

}  // namespace assertcc::subject
