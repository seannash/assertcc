#pragma once

#include <assertcc/adl.h>
#include <assertcc/subject/boolsubject.h>
#include <assertcc/subject/complexsubject.h>
#include <assertcc/subject/floatingsubject.h>
#include <assertcc/subject/genericsubject.h>
#include <assertcc/subject/integralsubject.h>
#include <assertcc/subject/iteratorssubject.h>
#include <assertcc/subject/mapsubject.h>
#include <assertcc/subject/multimapsubject.h>
#include <assertcc/subject/multisetsubject.h>
#include <assertcc/subject/optionalsubject.h>
#include <assertcc/subject/pairsubject.h>
#include <assertcc/subject/pointersubject.h>
#include <assertcc/subject/priorityqueuesubject.h>
#include <assertcc/subject/queuesubject.h>
#include <assertcc/subject/setsubject.h>
#include <assertcc/subject/sharedptrsubject.h>
#include <assertcc/subject/spansubject.h>
#include <assertcc/subject/stacksubject.h>
#include <assertcc/subject/stringsubject.h>
#include <assertcc/subject/stringviewsubject.h>
#include <assertcc/subject/uniqueptrsubject.h>
#include <assertcc/subject/weakptrsubject.h>
#include <assertcc/subject/functionsubject.h>


#include <array>
#include <concepts>
#include <deque>
#include <forward_list>
#include <functional>
#include <initializer_list>
#include <list>
#include <sstream>
#include <stack>
#include <string>
#include <type_traits>
#include <utility>
#include <span>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>

#define assertThat(x) assertcc::assert_that_internal(assertcc::Adl(), true, __FILE__, __LINE__, x)
#define expectThat(x) assertcc::assert_that_internal(assertcc::Adl(), false, __FILE__, __LINE__, x)

namespace assertcc {

template <typename T, typename std::enable_if<std::is_same<T, bool>::value>::type* = nullptr>
auto assert_that_internal(Adl dummy, bool failOnError, const char* file, int line, T v) {
  return subject::BoolSubject(failOnError, file, line, v);
}

template <typename T,
          typename std::enable_if<!std::is_same<T, bool>::value>::type* = nullptr,
          typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
auto assert_that_internal(Adl dummy, bool failOnError, const char* file, int line, T v) {
  return subject::IntegralSubject<T>(failOnError, file, line, v);
}

template <typename T>
auto assert_that_internal(
    Adl dummy, bool failOnError, const char* file, int line, std::complex<T> v) {
  return subject::ComplexSubject(failOnError, file, line, v);
}

template <typename T, typename std::enable_if<std::is_floating_point<T>::value, T>::type* = nullptr>
auto assert_that_internal(Adl dummy, bool failOnError, const char* file, int line, T v) {
  return subject::FloatingSubject<T>(failOnError, file, line, v);
}

template <typename T, size_t N>
auto assert_that_internal(
    Adl dummy, bool failOnError, const char* file, int line, std::array<T, N>& v) {
  return subject::IteratorsSubject(failOnError, file, line, v.cbegin(), v.cend());
}

template <typename T, typename A>
auto assert_that_internal(
    Adl dummy, bool failOnError, const char* file, int line, std::vector<T, A>& v) {
  return subject::IteratorsSubject(failOnError, file, line, v.cbegin(), v.cend());
}

template <typename T, typename A>
auto assert_that_internal(
    Adl dummy, bool failOnError, const char* file, int line, std::list<T, A>& v) {
  return subject::IteratorsSubject(failOnError, file, line, v.cbegin(), v.cend());
}

template <typename T, typename A>
auto assert_that_internal(
    Adl dummy, bool failOnError, const char* file, int line, std::deque<T, A>& v) {
  return subject::IteratorsSubject(failOnError, file, line, v.cbegin(), v.cend());
}

template <typename T, typename A>
auto assert_that_internal(
    Adl dummy, bool failOnError, const char* file, int line, std::forward_list<T, A>& v) {
  return subject::IteratorsSubject(failOnError, file, line, v.cbegin(), v.cend());
}

template <typename T>
auto assert_that_internal(
    Adl dummy, bool failOnError, const char* file, int line, std::optional<T> v) {
  return subject::OptionalSubject(failOnError, file, line, v);
}

template <typename T, typename V>
auto assert_that_internal(
    Adl dummy, bool failOnError, const char* file, int line, std::pair<T, V> v) {
  return subject::PairSubject(failOnError, file, line, v);
}

template <typename T, typename std::enable_if<std::is_pointer<T>::value, T>::type* = nullptr>
auto assert_that_internal(Adl dummy, bool failOnError, const char* file, int line, T v) {
  return subject::PointerSubject<T>(failOnError, file, line, v);
}

template <typename T, typename Container>
auto assert_that_internal(
    Adl dummy, bool failOnError, const char* file, int line, std::queue<T, Container>& q) {
  return subject::QueueSubject<std::queue<T, Container>>(failOnError, file, line, q);
}

template <typename T>
auto assert_that_internal(
    Adl dummy, bool failOnError, const char* file, int line, std::shared_ptr<T> v) {
  return subject::SharedPtrSubject(failOnError, file, line, v);
}

template <typename T, typename Deleter>
auto assert_that_internal(
    Adl dummy, bool failOnError, const char* file, int line, std::unique_ptr<T, Deleter>& v) {
  return subject::UniquePtrSubject(failOnError, file, line, v);
}

template <typename T>
auto assert_that_internal(
    Adl dummy, bool failOnError, const char* file, int line, std::weak_ptr<T>& v) {
  return subject::WeakPtrSubject(failOnError, file, line, v);
}

template <typename Key, typename T, typename Compare, typename Allocator>
auto assert_that_internal(Adl dummy,
                          bool failOnError,
                          const char* file,
                          int line,
                          std::map<Key, T, Compare, Allocator>& v) {
  return subject::MapSubject(failOnError, file, line, v);
}

template <typename Key, typename T, typename Hash, typename KeyEqual, typename Allocator>
auto assert_that_internal(Adl dummy,
                          bool failOnError,
                          const char* file,
                          int line,
                          std::unordered_map<Key, T, Hash, KeyEqual, Allocator>& v) {
  return subject::MapSubject(failOnError, file, line, v);
}

template <typename Key, typename T, typename Compare, typename Allocator>
auto assert_that_internal(Adl dummy,
                          bool failOnError,
                          const char* file,
                          int line,
                          std::multimap<Key, T, Compare, Allocator>& v) {
  return subject::MultiMapSubject(failOnError, file, line, v);
}

template <typename Key, typename T, typename Hash, typename KeyEqual, typename Allocator>
auto assert_that_internal(Adl dummy,
                          bool failOnError,
                          const char* file,
                          int line,
                          std::unordered_multimap<Key, T, Hash, KeyEqual, Allocator>& v) {
  return subject::MultiMapSubject(failOnError, file, line, v);
}

template <typename Key, typename Compare, typename Allocator>
auto assert_that_internal(
    Adl dummy, bool failOnError, const char* file, int line, std::set<Key, Compare, Allocator>& v) {
  return subject::SetSubject(failOnError, file, line, v);
}

template <typename Key, typename Hash, typename KeyEqual, typename Allocator>
auto assert_that_internal(Adl dummy,
                          bool failOnError,
                          const char* file,
                          int line,
                          std::unordered_set<Key, Hash, KeyEqual, Allocator>& v) {
  return subject::SetSubject(failOnError, file, line, v);
}

template <typename Key, typename Compare, typename Allocator>
auto assert_that_internal(Adl dummy,
                          bool failOnError,
                          const char* file,
                          int line,
                          std::multiset<Key, Compare, Allocator>& v) {
  return subject::MultiSetSubject(failOnError, file, line, v);
}

template <typename Key, typename Hash, typename KeyEqual, typename Allocator>
auto assert_that_internal(Adl dummy,
                          bool failOnError,
                          const char* file,
                          int line,
                          std::unordered_multiset<Key, Hash, KeyEqual, Allocator>& v) {
  return subject::MultiSetSubject(failOnError, file, line, v);
}

template <typename CharT, typename Traits>
auto assert_that_internal(Adl dummy,
                          bool failOnError,
                          const char* file,
                          int line,
                          const std::basic_string<CharT, Traits>& v) {
  return subject::StringSubject(failOnError, file, line, v);
}

template <typename CharT, typename Traits>
auto assert_that_internal(Adl dummy,
                          bool failOnError,
                          const char* file,
                          int line,
                          const std::basic_string_view<CharT, Traits>& v) {
  return subject::StringViewSubject(failOnError, file, line, v);
}

template <typename E, typename C>
auto assert_that_internal(
    Adl dummy, bool failOnError, const char* file, int line, std::stack<E, C>& v) {
  return subject::StackSubject(failOnError, file, line, v);
}

template <typename Type, typename Container, typename Compare>
auto assert_that_internal(Adl dummy,
                          bool failOnError,
                          const char* file,
                          int line,
                          std::priority_queue<Type, Container, Compare>& v) {
  return subject::PriorityQueueSubject(failOnError, file, line, v);
}

template <typename T, std::size_t Extent>
auto assert_that_internal(
    Adl dummy, bool failOnError, const char* file, int line, std::span<T, Extent>& v) {
  return subject::SpanSubject(failOnError, file, line, v);
}

template <typename R, typename... Args>
auto assert_that_internal(
    Adl dummy, bool failOnError, const char* file, int line, std::function<R(Args...)> v) {
  return subject::FunctionSubject<R, Args...>(failOnError, file, line, v);
}

}  // namespace assertcc
