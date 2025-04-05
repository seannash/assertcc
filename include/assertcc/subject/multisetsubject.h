#pragma once

#include <assertcc/proposition/hassizepropositions.h>
#include <assertcc/proposition/isemptypropositions.h>
#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/subject/base.h>

#include <map>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

// IWYU pragma: private, include <assertcc/assertcc.h>

namespace assertcc::subject {

template <typename T>
class MultiSetSubject : public virtual Base<T>,
                        public proposition::HasSizePropositions<MultiMapSubject<T>, T>,
                        public proposition::IsEmptyPropositions<MultiMapSubject<T>, T>,
                        public proposition::IsEqualToPropositions<MultiMapSubject<T>, T> {
  const T d_value;

 protected:
  const T* getObject() const override { return &d_value; }

  const std::string getObjectAsString() const override {
    std::stringstream ss;
    ss << "[";
    bool isFirst = true;
    for (const auto& elem : d_value) {
      if (!isFirst) {
        ss << ", ";
      }
      ss << elem;
      isFirst = false;
    }
    ss << "]";
    return ss.str();
  }

 public:
  MultiSetSubject(const bool failOnError, const char* file, int line, const T& v)
      : Base<T>(failOnError, file, line), d_value(v) {}
};

}  // namespace assertcc::subject