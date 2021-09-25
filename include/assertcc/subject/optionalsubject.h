#pragma once

#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/proposition/valuecontainerpropositions.h>
#include <assertcc/proposition/hasvaluethatpropositions.h>
#include <assertcc/subject/base.h>

#include <optional>

namespace assertcc {

namespace subject {

template <typename T>
class OptionalSubject : public virtual Base,
                        public proposition::HasValueThatPropositions<T>,
                        public proposition::IsEqualToPropositions<OptionalSubject<T>, T>,
                        public proposition::ValueContainsPropositions<OptionalSubject<T>, T> {
  const T d_value;

 protected:
  const T* getValue() const override { return &d_value; }

 public:
  OptionalSubject(const bool failOnError, const char* file, int line, const T& v)
      : Base(failOnError, file, line), d_value(v) {}

  OptionalSubject<T>& isPresent() {
    if (!*getValue()) {
      util::FailMessage::create()
          .failOnError(getFailOnError())
          .file(getFile())
          .line(getLine())
          .fact("Expected the optional to contain a value.")
          .fact("The optional does not contain a value.");
    }
    return *this;
  }

  OptionalSubject<T>& isEmpty() {
    if (*getValue()) {
      util::FailMessage::create()
          .failOnError(getFailOnError())
          .file(getFile())
          .line(getLine())
          .expected("Expected the optional to be empty.")
          .fact("Got", *getValue());
    }
    return *this;
  }
};

}  // namespace subject

}  // namespace assertcc