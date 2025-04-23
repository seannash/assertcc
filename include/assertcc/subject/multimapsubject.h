#pragma once

#include <assertcc/proposition/hassizepropositions.h>
#include <assertcc/proposition/isemptypropositions.h>
#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/subject/base.h>

#include <map>
#include <optional>
#include <set>
#include <sstream>
#include <string>
#include <vector>

namespace assertcc::subject {

template <typename T>
class MultiMapSubject : public virtual Base<T>,
                        public proposition::ContainsKeyPropositions<MultiMapSubject<T>, T>,
                        public proposition::ContainsMapEntryPropositions<MultiMapSubject<T>, T>,
                        public proposition::HasSizePropositions<MultiMapSubject<T>, T>,
                        public proposition::IsEmptyPropositions<MultiMapSubject<T>, T>,
                        public proposition::IsEqualToPropositions<MultiMapSubject<T>, T> {
  const T d_value;

 protected:
  const T* getObject() const override { return &d_value; }
  const std::string getObjectAsString(const T& other) const override {
    std::stringstream ss;
    ss << "[";
    bool isFirst = true;
    for (const auto& pair : other) {
      if (!isFirst) {
        ss << ", ";
      }
      ss << pair.first << "->" << pair.second;
      isFirst = false;
    }
    ss << "]";
    return ss.str();
  }

 public:
  MultiMapSubject(const bool failOnError, const char* file, int line, const T& v)
      : Base<T>(failOnError, file, line), d_value(v) {}
};

}  // namespace assertcc::subject