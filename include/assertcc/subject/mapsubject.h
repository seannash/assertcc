#pragma once

#include <assertcc/proposition/containskeypropositions.h>
#include <assertcc/proposition/hassizepropositions.h>
#include <assertcc/proposition/isemptypropositions.h>
#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/proposition/mappropositions.h>
#include <assertcc/subject/base.h>

#include <map>
#include <optional>
#include <sstream>
#include <string>
#include <vector>
#include <functional>

namespace assertcc::subject {

template <typename T>
class MapSubject : public virtual Base<T>,
                   public proposition::ContainsKeyPropositions<MapSubject<T>, T>,
                   public proposition::HasSizePropositions<MapSubject<T>, T>,
                   public proposition::IsEmptyPropositions<MapSubject<T>, T>,
                   public proposition::IsEqualToPropositions<MapSubject<T>, T>,
                   public proposition::MapPropositions<MapSubject<T>, T, typename T::key_type, typename T::mapped_type> {
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
    MapSubject(const bool failOnError, const char* file, int line, const T& v)
      : Base<T>(failOnError, file, line), d_value(v) {}

};

}  // namespace assertcc::subject
