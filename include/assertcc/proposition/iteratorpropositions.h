#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>

#include <type_traits>

// IWYU pragma: private, include <assertcc/assertcc.h>

namespace assertcc::proposition {

template <typename T, typename U>
class IteratorPropositions : public virtual subject::Base<U> {
 private:
  using value_t = typename std::iterator_traits<U>::value_type;

 protected:
  virtual const U* getBegin() const = 0;
  virtual const U* getEnd() const = 0;

 public:
  T& isEmpty() {
    if (*getBegin() != *getEnd()) {
      util::FailMessage::create()
          .failOnError(getFailOnError())
          .file(getFile())
          .line(getLine())
          .fact("Expected the collection to be empty")
          .fact("Got", getObjectAsString())
          .build();
    }
    return *dynamic_cast<T*>(this);
  }

  T& isNotEmpty() {
    if (*getBegin() == *getEnd()) {
      util::FailMessage::create()
          .failOnError(getFailOnError())
          .file(getFile())
          .line(getLine())
          .fact("Expected the collection to not be empty.")
          .fact("Got an empty collection.")
          .build();
    }
    return *dynamic_cast<T*>(this);
  }

  template <typename A>
  T& isNotEqualTo(const A& ob, const A& oe) {
    if (std::equal(*getBegin(), *getEnd(), ob, oe)) {
      util::FailMessage::create()
          .failOnError(getFailOnError())
          .file(getFile())
          .line(getLine())
          .fact("Expected the collection not to be equal to", ob, oe)
          .fact("Got", *getBegin(), *getEnd())
          .build();
    }
    return *dynamic_cast<T*>(this);
  }

  template <typename A>
  T& isEqualTo(const A& ob, const A& oe) {
    if (!std::equal(*getBegin(), *getEnd(), ob, oe)) {
      util::FailMessage::create()
          .failOnError(getFailOnError())
          .file(getFile())
          .line(getLine())
          .fact("Expected the collection is equal to", ob, oe)
          .fact("Got", *getBegin(), *getEnd())
          .build();
    }
    return *dynamic_cast<T*>(this);
  }

  T& contains(value_t r) {
    auto iter = std::find(*getBegin(), *getEnd(), r);
    if (iter == *getEnd()) {
      util::FailMessage::create()
          .failOnError(getFailOnError())
          .file(getFile())
          .line(getLine())
          .fact("Expected collection to contain", r)
          .fact("Got", *getBegin(), *getEnd())
          .build();
    }
    return *dynamic_cast<T*>(this);
  }
};

}  // namespace assertcc::proposition