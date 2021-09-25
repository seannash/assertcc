#pragma once

namespace assertcc {

/**
    This class serves for the compiler to locate the assert_that_internal
   functions using argument dependent lookup.

    Without this currently Clang 10 will not compile the code. GCC 10 will
   compile the code due to a bug.

    https://clang.llvm.org/compatibility.html#dep_lookup
*/
class Adl {};

}  // namespace assertcc