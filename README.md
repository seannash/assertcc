# AssertCC

AssertCC is a fluent assertions library for C++ for use with Google Test.

This library draws influence from [AssertJ](https://assertj.github.io/doc/) and [Google Truth](http://truth.dev).

## Installation

To build and install from source

```bash
mkdir build
cd build
cmake ..
make
make install
```

## Usage

AssertCC is a header only library so it only needs to be included in the project for use.

```cpp
#include <optional>

#inlcude <gtest/gtest.h>
#include <assertcc/assertcc.h>

std::optional<int> calculate() {
    return std::optional(42);
}

TEST(Calculate)
{
  auto answer = calculate();
  assertThat(answer)
      .isPresent()
      .hasValueThat()
      .isEqualTo(42);
}
```

## Controlling the failure of assertions

There are two provided functions assert_that and expect_that. The former will stop a test on
the first failure while the later will continue.

## Supported Types

## Extending To New Types

### assert_that_internal function

There are two macros, assert_that and expect_that, which call assert_that_internal. These are macros
so they can grab the current file and line number to show in error messages with the preprocessor macros
__LINE__ and __FILE__. The difference between these functions is that a boolean is passed to assert_that_internal
on whether to continue on errors or stop the test. The first parameter to assert_that_internal
is a dummy parameter of type assertcc::Adl. This serves the compiler to find the function by argument
dependent lookup when called from other namespaces such in the value() method of assertcc::propistion::ValueProposition.

### Subjects And Propositions

A subject class serves to hold propositions, the checks that are to be done. The function assert_that_internal creates
different subject classes depending on its argument. 

### Example using GenericSubject

The file [user_class.cc](tests/user_class.cc) serves as a minimal example of how to add a new assert_that. This example
uses the GenericSubject that supports isEqualTo and isNotEqualTo propositions.

### Propositions

The classes in assertcc::proposition are for adding groups of propositions to subject. The subject classes can inherit from them to add propositions.
The iterator subject and weak_ptr subject classes implement propositions directly but the other subjects tend to use the shared classes. The template parameters for the propositions is the return type and the type of the object being acted on.

### Example creating a new subject

The file [user_subject.cc](tests/user_subject.cc) serves as an example of how to add a new subject and an assertThat. This example
supports isEqualTo and isNotEqualTo propositions using the mixin and has an inline propositions to check if the Foo class contains
the number 42.

## License
[BSD 3 Clause](LICENSE.md)