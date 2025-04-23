#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>

#include <regex>
#include <sstream>

// IWYU pragma: private, include <assertcc/assertcc.h>

namespace assertcc::proposition {

template <typename T, typename U>
class StringPropositions : public virtual subject::Base<U> {
 public:
  T& contains(const U& other) {
    if (this->getObject()->find(other) == std::string::npos) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("Expected the string to contain the subsequence", other)
          .fact("Got", this->getObjectAsString())
          .build();
      ;
    }
    return *dynamic_cast<T*>(this);
  }

  T& doesNotContain(const U& other) {
    if (this->getObject()->find(other) != std::string::npos) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("Expected the string to contain the subsequence", this->getObjectAsString(other))
          .fact("Got", this->getObjectAsString())
          .build();
      ;
    }
    return *dynamic_cast<T*>(this);
  }

  T& startsWith(const U& other) {
    std::stringstream ss;
    ss << "^" << other;
    std::regex re(ss.str());
    if (!std::regex_search(*this->getObject(), re)) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("Expected the string to start with", this->getObjectAsString(other))
          .fact("Got", this->getObjectAsString())
          .build();
      ;
    }
    return *dynamic_cast<T*>(this);
  }

  T& endsWith(const U& other) {
    std::stringstream ss;
    ss << other << "$";
    std::regex re(ss.str());
    if (!std::regex_search(*this->getObject(), re)) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("The string to end with", this->getObjectAsString(other))
          .fact("Got", this->getObjectAsString())
          .build();
      ;
    }
    return *dynamic_cast<T*>(this);
  }

  T& containsMatch(const std::string& str) {
    std::regex re(str);
    if (!std::regex_search(*this->getObject(), re)) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("The string to contain the regex", str)
          .fact("Got", this->getObjectAsString())
          .build();
      ;
    }
    return *dynamic_cast<T*>(this);
  }

  T& doesNotContainMatch(const std::string& str) {
    std::regex re(str);
    if (std::regex_search(*this->getObject(), re)) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("Expected the string to not contain regex", str)
          .fact("Got", this->getObjectAsString())
          .build();
      ;
    }
    return *dynamic_cast<T*>(this);
  }

  T& matches(const std::string& str) {
    std::regex re(str);
    if (!std::regex_match(*this->getObject(), re)) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("The string to match", str)
          .fact("Got", this->getObjectAsString())
          .build();
    }
    return *dynamic_cast<T*>(this);
  }

  T& doesNotMatch(const std::string& str) {
    std::regex re(str);
    if (std::regex_match(*this->getObject(), re)) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("Expected the string to not match ", str)
          .fact("Got", this->getObjectAsString())
          .build();
      ;
    }
    return *dynamic_cast<T*>(this);
  }
};

}  // namespace assertcc::proposition