#pragma once

#include <assertcc/proposition/hasvaluethatpropositions.h>
#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/proposition/isnullpropositions.h>
#include <assertcc/subject/base.h>

#include <sstream>
#include <string>
#include <type_traits>

namespace assertcc::subject {
template <typename T>
class PointerSubject : public virtual Base<T>,
                       public proposition::HasValueThatPropositions<T>,
                       public proposition::IsEqualToPropositions<PointerSubject<T>, T>,
                       public proposition::IsNullPropositions<PointerSubject<T>, T> {
  const T d_value;

 protected:
  const T* getObject() const override { return &d_value; }
  const std::string getObjectAsString(const T& other) const override {
    if (other == nullptr) {
      return "nullptr";
    }
    std::stringstream ss;
    ss << "a pointer to " << other;
    return ss.str();
  }

 public:
  PointerSubject(const bool failOnError, const char* file, int line, const T v)
      : Base<T>(failOnError, file, line), d_value(v) {}
};

}  // namespace assertcc::subject
