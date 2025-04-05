#pragma once

#include <assertcc/proposition/containskeypropositions.h>
#include <assertcc/proposition/hassizepropositions.h>
#include <assertcc/proposition/isemptypropositions.h>
#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/subject/base.h>

#include <map>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

namespace assertcc::subject {

template <typename T>
class MapSubject : public virtual Base,
                   public proposition::ContainsKeyPropositions<MapSubject<T>, T>,
                   public proposition::HasSizePropositions<MapSubject<T>, T>,
                   public proposition::IsEmptyPropositions<MapSubject<T>, T>,
                   public proposition::IsEqualToPropositions<MapSubject<T>, T> {
  const T d_value;

 protected:
  const T* getValue() const override { return &d_value; }

 public:
  MapSubject(const bool failOnError, const char* file, int line, const T& v)
      : Base(failOnError, file, line), d_value(v) {}

  template <typename Key, typename Value>
  auto& containsEntry(Key key, Value value) {
    auto iter = getValue()->find(key);
    if (iter == getValue()->end() || iter->second != value) {
      std::stringstream ss;
      ss << "(" << key << ", " << value << ")";
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("Expected the map contains the entry: ", ss.str())
          .fact("Collection did not contain the entry");
    }
    return *this;
  }

  template <typename Key, typename Value>
  auto& doesNotContainEntry(Key key, Value value) {
    auto iter = getValue()->find(key);
    if (iter != getValue()->end() && iter->second == value) {
      std::stringstream ss;
      ss << "(" << key << ", " << value << ")";
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("Expected the map does not contains the entry: ", ss.str())
          .fact("The collection does contain the entry");
    }
    return *this;
  }
};

}  // namespace assertcc::subject