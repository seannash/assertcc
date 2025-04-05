#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>
#include <memory.h>
#include <vector>
#include <set>

namespace assertcc::proposition {

template <typename T, typename U>
class ContainsKeyPropositions : public virtual subject::Base<U> {

 public:
  template <typename Key>
  T& containsKey(const Key key) {
    if (this->getObject()->find(key) == this->getObject()->end()) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("contains key", key)
          .fact("Got", this->getObjectAsString());
    }
    return *dynamic_cast<T*>(this);
  }

  template <typename Key>
  T& doesNotContainKey(const Key key) {
    auto iter = this->getObject()->find(key);
    if (iter != this->getObject()->end()) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("to not contain the key ", key)
          .fact("Got", this->getObjectAsString())
          .build();
    }
    return *dynamic_cast<T*>(this);
  }

};

}  // namespace assertcc::proposition
