#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>
#include <sstream>

namespace assertcc::proposition {

template <typename T, typename U, typename Key, typename Value>
class MapPropositions : public virtual subject::Base<U> {
 public:

  T& containsEntry(Key key, Value value) {
    auto iter = this->getObject()->find(key);
    if (iter == this->getObject()->end() || iter->second != value) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("map to contain entry", key)
          .fact("with value", value)
          .fact("Got", this->getObjectAsString());
    }
    return *dynamic_cast<T*>(this);
  }

  T& doesNotContainEntry(Key key, Value value) {
    auto iter = this->getObject()->find(key);
    if (iter != this->getObject()->end() && iter->second == value) {
      std::stringstream ss;
      ss << "(" << key << ", " << value << ")";
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("map does not contain entry", key)
          .fact("with value", value)
          .fact("Got", this->getObjectAsString());
    }
    return *dynamic_cast<T*>(this);
  }
};

}  // namespace assertcc::proposition 