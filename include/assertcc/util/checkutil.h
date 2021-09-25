#pragma once

#include <initializer_list>

namespace assertcc {

namespace util {

struct CheckUtil {
  template <template <typename...> typename List, typename T>
  static bool checkIsInRange(List<T>& r, const T& value) {
    for (const auto& e : r) {
      if (value == e) return true;
    }
    return false;
  }

  template <typename T>
  static bool checkIsInRange(std::initializer_list<T> r, const T& value) {
    for (const auto& e : r) {
      if (value == e) return true;
    }
    return false;
  }
};

}  // namespace util

}  // namespace assertcc