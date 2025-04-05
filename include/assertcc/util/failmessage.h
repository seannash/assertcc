#pragma once

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace assertcc::util {

class FailMessage {
 private:
  std::string d_file;
  int d_line;
  std::stringstream d_buffer;
  bool d_failOnError;

  FailMessage() : d_file(""), d_line(), d_buffer(), d_failOnError(true) {}

 public:
  static FailMessage create() { return FailMessage(); }

  FailMessage& file(std::string file) {
    d_file = file;
    return *this;
  }

  FailMessage& line(int line) {
    d_line = line;
    return *this;
  }

  template<typename T>
  FailMessage& fact(const std::string& key, const T& value) {
    d_buffer << key << ": " << value << "\n";
    return *this;
  }

  template <typename T, typename std::enable_if<std::is_same<T, bool>::value>::type* = nullptr>
  FailMessage& fact(const std::string& key, bool value) {
    d_buffer << key << ": " << (value ? "true" : "false") << "\n";
    return *this;
  }

  FailMessage& fact(const std::string& key) {
    d_buffer << key << "\n";
    return *this;
  }

  FailMessage& expected(std::string msg) {
    fact(msg);
    return *this;
  }

  template <typename T>
  FailMessage& fact(std::string msg, const T begin, const T end) {
    d_buffer << msg << " [";
    for (auto iter = begin; iter != end; iter++) {
      d_buffer << " " << *iter;
    }
    d_buffer << " ]";
    return *this;
  }

  FailMessage& failOnError(bool failOnError) {
    d_failOnError = failOnError;
    return *this;
  }

  void build() {
    auto fatality = ::testing::TestPartResult::kFatalFailure;
    if (!d_failOnError) {
      fatality = ::testing::TestPartResult::kNonFatalFailure;
    }
    GTEST_MESSAGE_AT_(d_file.c_str(), d_line, d_buffer.str().c_str(), fatality);
  }

  ~FailMessage() {}
};

}  // namespace assertcc::util
