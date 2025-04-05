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
class StringSubject : public virtual Base,
                      public proposition::HasLengthPropositions<StringSubject<T>, T>,
                      public proposition::HasSizePropositions<StringSubject<T>, std::string>,
                      public proposition::IsEqualToPropositions<StringSubject<T>, T>,
                      public proposition::IsEmptyPropositions<StringSubject<T>, T> {
  const T d_value;

 protected:
  const T* getValue() const override { return &d_value; }

 public:
  StringSubject(const bool failOnError, const char* file, int line, const T& v)
      : Base(failOnError, file, line), d_value(v) {}

  StringSubject<T>& contains(const T& other) {
    if (getValue()->find(other) == std::string::npos) {
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("Expected the string to contain the subsequence", other)
          .fact("Got", *getValue());
    }
    return *this;
  }

  StringSubject<T>& doesNotContain(const T& other) {
    if (getValue()->find(other) != std::string::npos) {
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("Expected the string to contain the subsequence", other)
          .fact("Got", *getValue());
    }
    return *this;
  }

  StringSubject<T>& startsWith(const T& other) {
    std::stringstream ss;
    ss << "^" << other;
    std::regex re(ss.str());
    if (!std::regex_search(*getValue(), re)) {
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("Expected the string to start with", other)
          .fact("Got", *getValue());
    }
    return *this;
  }

  StringSubject<T>& endsWith(const T& other) {
    std::stringstream ss;
    ss << other << "$";
    std::regex re(ss.str());
    if (!std::regex_search(*getValue(), re)) {
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("The string to end with", other)
          .fact("Got", getValue());
    }
    return *this;
  }

  StringSubject<T>& containsMatch(const std::string& str) {
    std::regex re(str);
    if (!std::regex_search(*getValue(), re)) {
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("The string to contain the regex", str)
          .fact("Got", *getValue());
    }
    return *this;
  }

  StringSubject<T>& doesNotContainMatch(const std::string& str) {
    std::regex re(str);
    if (std::regex_search(*getValue(), re)) {
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("Expected the string to not contain regex", str)
          .fact("Got", *getValue());
    }
    return *this;
  }

  StringSubject<T>& matches(const std::string& str) {
    std::regex re(str);
    if (!std::regex_match(*getValue(), re)) {
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("The string to match", str)
          .fact("Got", *getValue());
    }
    return *this;
  }

  StringSubject<T>& doesNotMatch(const std::string& str) {
    std::regex re(str);
    if (std::regex_match(*getValue(), re)) {
      util::FailMessage::create()
          .file(getFile())
          .line(getLine())
          .fact("Expected the string to not match ", str)
          .fact("Got", *getValue());
    }
    return *this;
  }
};

}  // namespace assertcc::subject