#pragma once

#include <string>

namespace assertcc::subject {

/**
    Base class that holds shared information between the subject classes and the
   propositoin mixins.

    The subject class will intilize the Base superclass and the proposition
   classes will use the functions to retrive the data. Virtual inheritance is
   used to avoid the diamond issue.
*/
template <typename T>
class Base {
 private:
  /** The source file of the assert_that statement was called in. */
  const char* d_file;
  /// The line number in the file the assert_that statement is on.
  const int d_line;
  /// A flag to determine whether a test stops at the error or continues.
  const bool d_failOnError;

 protected:
  const char* getFile() const { return d_file; }
  int getLine() const { return d_line; }
  bool getFailOnError() const { return d_failOnError; }
  virtual const T* getObject() const = 0;
  virtual const std::string getObjectAsString() const { return getObjectAsString(*getObject()); }
  virtual const std::string getObjectAsString(const T& other) const = 0;

 public:
  Base(const bool failOnError, const char* file, int line)
      : d_file(file), d_line(line), d_failOnError(failOnError) {}
};

}  // namespace assertcc::subject