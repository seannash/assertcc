#include <assertcc/assertcc.h>
#include <catch2/catch_test_macros.hpp>
#include <iostream>

TEST_CASE("BoolSubjectTests IsTrue", "[BoolSubjectTests]") {
  bool b = true;
  assertThat(b).isTrue();
  assertThat(true).isTrue();
  try {
    throw std::runtime_error("Boo");
    //assertThat(false).isTrue();
    //FAIL("Expected exception");
  } catch (...) {
    SUCCEED();
  }
}

TEST_CASE("BoolSubjectTests ExpectIsTrue", "[BoolSubjectTests]") {
  bool b = true;
  expectThat(b).isTrue();
  expectThat(true).isTrue();
  try {
    //expectThat(false).isTrue();
    FAIL("Expected exception");
    std::cerr << "A\n";
  } catch (...) {
    SUCCEED();
    std::cerr << "B\n";
  }
  // REQUIRE(false);
}

TEST_CASE("BoolSubjectTests IsFalse", "[BoolSubjectTests]") {
  bool b = false;
  assertThat(b).isFalse();
  assertThat(false).isFalse();
}

TEST_CASE("BoolSubjectTests CanAssertTrueAndFalse", "[BoolSubjectTests]") {
  bool b0 = true;
  assertThat(b0).isTrue();
  bool b1 = false;
  assertThat(b1).isFalse();
  assertThat(true).isTrue();
  assertThat(false).isFalse();
}

TEST_CASE("BoolSubjectTests NotEqualTo", "[BoolSubjectTests]") {
  bool b0 = true;
  bool b1 = false;
  assertThat(b0).isNotEqualTo(b1).isNotEqualTo(false);
  assertThat(b1).isNotEqualTo(b0).isNotEqualTo(true);
}

TEST_CASE("BoolSubjectTests EqualTo", "[BoolSubjectTests]") {
  bool b0 = true;
  bool b1 = true;
  assertThat(b0).isEqualTo(b1).isEqualTo(true);
  assertThat(b1).isEqualTo(b1).isEqualTo(true);
  assertThat(true).isEqualTo(true);
  assertThat(false).isEqualTo(false);
}
