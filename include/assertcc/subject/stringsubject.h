#pragma once

#include <assertcc/proposition/haslengthpropositions.h>
#include <assertcc/proposition/hassizepropositions.h>
#include <assertcc/proposition/isemptypropositions.h>
#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/proposition/isnullpropositions.h>
#include <assertcc/subject/base.h>

#include <regex>
#include <sstream>
#include <string>

namespace assertcc::subject {

template <typename T>
class StringSubject : public virtual Base<T>,
                      public proposition::HasLengthPropositions<StringSubject<T>, T>,
                      public proposition::HasSizePropositions<StringSubject<T>, std::string>,
                      public proposition::IsEqualToPropositions<StringSubject<T>, T>,
                      public proposition::IsEmptyPropositions<StringSubject<T>, T> {
  const T d_value;

 protected:
  const T* getObject() const override { return &d_value; }
  const T getObjectAsString(const T& other) const override { return d_value; }

 public:
  StringSubject(const bool failOnError, const char* file, int line, const T& v)
      : Base<T>(failOnError, file, line), d_value(v) {}

  StringSubject<T>& contains(const T& other) {
    if (getObject()->find(other) == std::string::npos) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("Expected the string to contain the subsequence", other)
          .fact("Got", *getObject())
          .build();
    }
    return *this;
  }

  StringSubject<T>& doesNotContain(const T& other) {
    if (getObject()->find(other) != std::string::npos) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("Expected the string to contain the subsequence", other)
          .fact("Got", *this->getObject())
          .build();
    }
    return *this;
  }

  StringSubject<T>& startsWith(const T& other) {
    std::stringstream ss;
    ss << "^" << other;
    std::regex re(ss.str());
    if (!std::regex_search(*getObject(), re)) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("Expected the string to start with", other)
          .fact("Got", *this->getObject())
          .build();
    }
    return *this;
  }

  StringSubject<T>& endsWith(const T& other) {
    std::stringstream ss;
    ss << other << "$";
    std::regex re(ss.str());
    if (!std::regex_search(*getObject(), re)) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("The string to end with", other)
          .fact("Got", *this->getObject())
          .build();
    }
    return *this;
  }

  StringSubject<T>& containsMatch(const std::string& str) {
    std::regex re(str);
    if (!std::regex_search(*this->getObject(), re)) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("The string to contain the regex", str)
          .fact("Got", *this->getObject())
          .build();
    }
    return *this;
  }

  StringSubject<T>& doesNotContainMatch(const std::string& str) {
    std::regex re(str);
    if (std::regex_search(*getObject(), re)) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("Expected the string to not contain regex", str)
          .fact("Got", *this->getObject());
    }
    return *this;
  }

  StringSubject<T>& matches(const std::string& str) {
    std::regex re(str);
    if (!std::regex_match(*getObject(), re)) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("The string to match", str)
          .fact("Got", *this->getObject());
    }
    return *this;
  }

  StringSubject<T>& doesNotMatch(const std::string& str) {
    std::regex re(str);
    if (std::regex_match(*getObject(), re)) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("Expected the string to not match ", str)
          .fact("Got", *this->getObject());
    }
    return *this;
  }
};

}  // namespace assertcc::subject