#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>
#include <memory.h>

namespace assertcc::proposition {

template <typename T, typename U>
class IsInPropositions : public virtual subject::Base {
 private:
  template <typename List, typename I>
  bool checkIsInRange(List& r, const I& value) {
    for (const auto& e : r) {
      if (value == e) return true;
    }
    return false;
  }

  template <typename I>
  static bool checkIsInRange(std::initializer_list<I> r, const I& value) {
    for (const auto& e : r) {
      if (value == e) return true;
    }
    return false;
  }

 protected:
  virtual const U* getValue() const = 0;

 public:
  T& isIn(std::initializer_list<U> r) {
    if (!checkIsInRange(r, *getValue())) {
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("is in range", r.begin(), r.end())
          .fact("Got", *getValue());
    }
    return *dynamic_cast<T*>(this);
  }

  T& isNotIn(std::initializer_list<U> r) {
    if (checkIsInRange(r, *getValue())) {
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("is not in range", r.begin(), r.end())
          .fact("Got", *getValue());
    }
    return *dynamic_cast<T*>(this);
  }

  template <typename List>
  T& isIn(List r) {
    if (!checkIsInRange(r, *getValue())) {
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("is in range", r.begin(), r.end())
          .fact("Got", *getValue());
    }
    return *dynamic_cast<T*>(this);
  }

  template <template <typename...> typename List>
  T& isNotIn(List<U> r) {
    if (checkIsInRange(r, *getValue())) {
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("is not in range", r.begin(), r.end())
          .fact("Got", *getValue());
    }
    return *dynamic_cast<T*>(this);
  }
};

}  // namespace assertcc::proposition