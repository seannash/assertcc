#include <assertcc/assertcc.h>
#include <gtest/gtest-spi.h>
#include <gtest/gtest.h>

#include <complex>

using namespace testing;

TEST(ComplexTests, IsEqualTo) {
  std::complex<int> a(1, 2);
  std::complex<int> b(1, 2);
  assertThat(a).isEqualTo(b);
}

TEST(ComplexTests, IsNotEqualTo) {
  std::complex<int> a(1, 2);
  std::complex<int> b(3, 2);
  expectThat(a).isNotEqualTo(b);
}

TEST(ComplexTests, IsNotEqualTo_Failure) {
  std::complex<int> a(1, 2);
  std::complex<int> b(1, 23);
  assertThat(a).isNotEqualTo(3).isNotEqualTo(b);
  EXPECT_FATAL_FAILURE(assertThat(std::complex<int>(1, 2)).isNotEqualTo(std::complex<int>(1, 2)),
                       "");
}

TEST(ComplexTestsTests, IsIn) {
  std::complex<int> a(1, 2);
  assertThat(a).isIn({std::complex<int>(1, 2), std::complex<int>(2, 3)});
  std::vector<std::complex<int>> v{
      std::complex<int>(1, 2), std::complex<int>(2, 2), std::complex<int>(2, 3)};
  assertThat(a).isIn(v);
}

TEST(ComplexTests, IsNotIn) {
  int a = 10;
  assertThat(a).isNotIn({1, 2, 3});
  std::vector<int> v{1, 2, 3};
  assertThat(a).isNotIn(v);
}
