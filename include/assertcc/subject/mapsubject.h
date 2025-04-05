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
#include <functional>

namespace assertcc::subject {

template <typename T>
class MapSubject : public virtual Base<T>,
public proposition::ContainsKeyPropositions<MapSubject<T>, T>,
                   public proposition::HasSizePropositions<MapSubject<T>, T>,
                   public proposition::IsEmptyPropositions<MapSubject<T>, T>,
                   public proposition::IsEqualToPropositions<MapSubject<T>, T> {
  const T d_value;

 protected:
  const T* getObject() const override { return &d_value; }
  const std::string getObjectAsString() const override {
    std::stringstream ss;
    ss << "[";
    bool isFirst = true;
    for (const auto& pair : d_value) {
      if (!isFirst) {
        ss << ", ";
      }
      ss << pair.first << "->" << pair.second;
      isFirst = false;
    }
    ss << "]";
    return ss.str();
  }
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

  template <typename Key, typename Value>
  auto& containsEntry(Key key, Value value) {
    auto iter = getObject()->find(key);
    if (iter == getObject()->end() || iter->second != value) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("map to contain entry", key)
          .fact("with value", value)
          .fact("Got", getObjectAsString());
    }
    return *this;
  }

  template <typename Key, typename Value>
  auto& doesNotContainEntry(Key key, Value value) {
    auto iter = getObject()->find(key);
    if (iter != getObject()->end() && iter->second == value) {
      std::stringstream ss;
      ss << "(" << key << ", " << value << ")";
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("map does not contain entry", key)
          .fact("with value", value)
          .fact("Got", getObjectAsString());
    }
    return *this;
  }

};

}  // namespace assertcc::subject
