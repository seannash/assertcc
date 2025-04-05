#pragma once

#include <assertcc/assertcc.h>
#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>

#include <memory>

namespace assertcc::subject {

template <typename T>
class WeakPtrSubject {
  const char* d_file;
  const int d_line;
  const T d_value;
  const bool d_failOnError;

  void fail(const std::string msg) {
    FAIL() << "Expected: " << msg << "\nGot: "
           << "blah blah";
  }

 public:
  WeakPtrSubject(const bool failOnError, const char* file, int line, const T& v)
      : d_file(file), d_line(line), d_value(v), d_failOnError(failOnError) {}

  WeakPtrSubject<T>& isExpired() {
    if (!d_value.expired()) {
      util::FailMessage::create()
          .failOnError(d_failOnError)
          .file(d_file)
          .line(d_line)
          .fact("Expected the weak_ptr to be expired")
          .fact("Got", d_value);
    }
    return *this;
  }

  WeakPtrSubject<T>& isNotExpired() {
    if (d_value.expired()) {
      util::FailMessage::create()
          .failOnError(d_failOnError)
          .file(d_file)
          .line(d_line)
          .fact("Expected the weak_ptr to not be expired")
          .fact("Got", d_value);
    }
    return *this;
  }

  auto value() {
    auto sp = d_value.lock();
    return assert_that_internal(assertcc::Adl(), d_failOnError, d_file, d_line, *sp);
  }
};

}  // namespace assertcc::subject