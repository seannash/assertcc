#pragma once

#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/proposition/isinpropositions.h>
#include <assertcc/subject/base.h>

#include <complex>

namespace assertcc::subject {

template <typename T>
class ComplexSubject : public virtual Base<T>,
                       public proposition::IsEqualToPropositions<ComplexSubject<T>, T>,
                       public proposition::IsInPropositions<ComplexSubject<T>, T> {
  const T d_value;

 protected:
  const T* getObject() const override { return &d_value; }
  const std::string getObjectAsString(const T& other) const override {
    std::stringstream ss;
    ss << other.real() << " + " << other.imag() << "i";
    return ss.str();
  }

 public:
  ComplexSubject(const bool failOnError, const char* file, int line, const T v)
      : Base<T>(failOnError, file, line), d_value(v) {}
};

}  // namespace assertcc::subject
