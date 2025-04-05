#pragma once

#include <assertcc/proposition/hasvaluethatpropositions.h>
#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/proposition/iswrapperemptypropositions.h>
#include <assertcc/proposition/valuecontainerpropositions.h>
#include <assertcc/subject/base.h>

#include <optional>

// IWYU pragma: private, include <assertcc/assertcc.h>

namespace assertcc::subject {

template <typename T>
class PairSubject : public virtual Base<T>,
                    public proposition::IsEqualToPropositions<PairSubject<T>, T> {
  const T d_value;

 protected:
  const T* getObject() const override { return &d_value; }
  const std::string getObjectAsString(const T& other) const override {
    std::stringstream ss;
    ss << "pair with " << other.first << " and " << other.second;
    return ss.str();
  }

 public:
  PairSubject(const bool failOnError, const char* file, int line, const T& v)
      : Base<T>(failOnError, file, line), d_value(v) {}
};

}  // namespace assertcc::subject