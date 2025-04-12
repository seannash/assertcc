#include <assertcc/assertcc.h>
#include <gtest/gtest.h>

#ifdef __cpp_lib_mdspan

#include <mdspan>
#include <vector>

using namespace testing;

TEST(MdspanTests, isEmpty) {
  std::mdspan<int, std::extents<size_t, std::dynamic_extent>> empty_mdspan;
  assertThat(empty_mdspan).isEmpty();
}

TEST(MdspanTests, ExpectIsEmpty) {
 std::mdspan<int, std::extents<size_t, std::dynamic_extent>> nonempty_span;
 expectThat(nonempty_span).isEmpty();
}

TEST(MdspanTests, isNotEmpty) {
  std::vector<int> data = {
     1, 2, 3, 4,
     5, 6, 7, 8,
     9, 10, 11, 12
  };
  std::mdspan<int, std::extents<size_t, 3, 4>> matrix(data.data());
  assertThat(matrix).isNotEmpty();
}

TEST(MdspanTests, Size) {
  std::vector<int> data = {
     1, 2, 3, 4,
     5, 6, 7, 8,
     9, 10, 11, 12
  };
  std::mdspan<int, std::extents<size_t, 3, 4>> matrix(data.data());
  assertThat(matrix).hasSizeThat().isEqualTo(12);
}

#endif