#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>
#include <memory.h>

// IWYU pragma: private, include <assertcc/assertcc.h>

namespace assertcc::proposition {

template <typename T, typename U>
class ContainsMapEntryPropositions : public virtual subject::Base<U> {
 public:
  template <typename Key, typename Value>
  T& containsEntry(Key key, Value value) {
    auto iter = this->getObject()->find(key);
    if (iter == this->getObject()->end() || iter->second != value) {
      std::stringstream ss;
      ss << "(" << key << ", " << value << ")";
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("Expected the map contains the entry: ", ss.str())
          .fact("Collection did not contain the entry")
          .build();
    }
    return *dynamic_cast<T*>(this);
  }

  template <typename Key, typename Value>
  T& doesNotContainEntry(Key key, Value value) {
    auto iter = this->getObject()->find(key);
    if (iter != this->getObject()->end() && iter->second == value) {
      std::stringstream ss;
      ss << "(" << key << ", " << value << ")";
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("Expected the map does not contains the entry: ", ss.str())
          .fact("The collection does contain the entry")
          .build();
    }
    return *dynamic_cast<T*>(this);
  }
};

}  // namespace assertcc::proposition