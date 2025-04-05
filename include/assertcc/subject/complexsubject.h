#pragma once

#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/proposition/isinpropositions.h>
#include <assertcc/subject/base.h>

#include <complex>

namespace assertcc::subject {

template <typename T>
class ComplexSubject
    : public virtual Base<std::complex<T>>,
      public proposition::IsEqualToPropositions<ComplexSubject<T>, std::complex<T>>,
      public proposition::IsInPropositions<ComplexSubject<T>, std::complex<T>> {
  const std::complex<T> d_value;

 protected:
  const std::complex<T>* getObject() const override { return &d_value; }
  const std::string getObjectAsString(const std::complex<T>& other) const override {
    std::stringstream ss;
    ss << other.real() << " + " << other.imag() << "i";
    return ss.str();
  }

 public:
  ComplexSubject(const bool failOnError, const char* file, int line, const std::complex<T> v)
      : Base<std::complex<T>>(failOnError, file, line), d_value(v) {}

};

}  // namespace assertcc::subject
