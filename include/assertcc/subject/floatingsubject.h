#pragma once

#include <assertcc/proposition/comparingpropositions.h>
#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/proposition/isinpropositions.h>
#include <assertcc/proposition/stdfloatingpropositions.h>
#include <assertcc/subject/base.h>

namespace assertcc::subject {

template <typename T>
class FloatingSubject : public virtual Base<T>,
                        public proposition::FloatingPropositions<FloatingSubject<T>, T>,
                        public proposition::IsInPropositions<FloatingSubject<T>, T>,
                        public proposition::ComparisonPropositions<FloatingSubject<T>, T> {
  const T d_value;
  T d_tolerance;

 protected:
  const T* getObject() const override { return &d_value; }
  const std::string getObjectAsString(const T& other) const override {
    return std::to_string(other);
  }
  const T* getTolerance() const override { return &d_tolerance; }

 public:
  FloatingSubject(const bool failOnError, const char* file, int line, const T v)
      : Base<T>(failOnError, file, line),
        d_value(v),
        d_tolerance(std::numeric_limits<T>::epsilon()) {}

  FloatingSubject& isWithin(const T& tolerance) {
    d_tolerance = tolerance;
    return *this;
  }
};

}  // namespace assertcc::subject
