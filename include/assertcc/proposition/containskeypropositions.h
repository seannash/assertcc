#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>
#include <memory.h>

namespace assertcc::proposition {

template <typename T, typename U>
class ContainsKeyPropositions : public virtual subject::Base {
 protected:
  virtual const U* getValue() const = 0;

 public:
  template <typename Key>
  T& containsKey(const Key key) {
    auto iter = getValue()->find(key);
    if (iter == getValue()->end()) {
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("to contain the key ", key)
          .fact("Got", *getValue());
    }
    return *dynamic_cast<T*>(this);
  }

  template <typename Key>
  T& doesNotContainKey(const Key key) {
    auto iter = getValue()->find(key);
    if (iter != getValue()->end()) {
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("to not contain the key ", key)
          .fact("Got", *getValue());
    }
    return *dynamic_cast<T*>(this);
  }
};

}  // namespace assertcc::proposition