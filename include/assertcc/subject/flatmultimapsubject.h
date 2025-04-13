#pragma once

#include <assertcc/proposition/hassizepropositions.h>
#include <assertcc/proposition/isemptypropositions.h>
#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/subject/base.h>

#include <flat_map>
#include <optional>
#include <sstream>
#include <string>
#include <vector>
#include <set>

namespace assertcc::subject {

template <typename T>
class FlatMultiMapSubject : public virtual Base<T>,
                           public proposition::ContainsKeyPropositions<FlatMultiMapSubject<T>, T>,
                           public proposition::ContainsMapEntryPropositions<FlatMultiMapSubject<T>, T>,
                           public proposition::HasSizePropositions<FlatMultiMapSubject<T>, T>,
                           public proposition::IsEmptyPropositions<FlatMultiMapSubject<T>, T>,
                           public proposition::IsEqualToPropositions<FlatMultiMapSubject<T>, T> {
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
  FlatMultiMapSubject(const bool failOnError, const char* file, int line, const T& v)
      : Base<T>(failOnError, file, line), d_value(v) {}

};

}  // namespace assertcc::subject
