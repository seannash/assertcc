#pragma once

#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/proposition/valuecontainerpropositions.h>
#include <assertcc/proposition/hasvaluethatpropositions.h>
#include <assertcc/subject/base.h>

#include <optional>

namespace assertcc::subject {

template <typename T>
class OptionalSubject : public virtual Base<T>,
                        public proposition::HasValueThatPropositions<T>,
                        public proposition::IsEqualToPropositions<OptionalSubject<T>, T>,
                        public proposition::ValueContainsPropositions<OptionalSubject<T>, T> {
  const T d_value;

 protected:
  const T* getObject() const override { return &d_value; }
  const std::string getObjectAsString() const override {
    return d_value ? "a non-empty optional" : "an empty optional";
  }
  const std::string getObjectAsString(const T& other) const override {
    return other ? "a non-empty optional" : "an empty optional";
  }

 public:
  OptionalSubject(const bool failOnError, const char* file, int line, const T& v)
      : Base<T>(failOnError, file, line), d_value(v) {}

  OptionalSubject<T>& isPresent() {
    if (!*this->getObject()) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("optional to have a value")
          .fact("Got", this->getObjectAsString());
    }
    return *this;
  }

  OptionalSubject<T>& isEmpty() {
    if (*this->getObject()) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .expected("Expected the optional to be empty.")
          .fact("Got", this->getObjectAsString())
          .build();
    }
    return *this;
  }

};

}  // namespace assertcc::subject
