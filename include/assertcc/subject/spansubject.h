#pragma once

#if __cplusplus > 201703L

#include <assertcc/proposition/hassizepropositions.h>
#include <assertcc/proposition/isemptypropositions.h>
#include <assertcc/subject/base.h>

#include <span>

namespace assertcc::subject {

template <typename T>
class SpanSubject : public proposition::HasSizePropositions<SpanSubject<T>, T> public proposition::
                        IsEmptyPropositions<SpanSubject<T>, T> {
  const T d_value;

 protected:
  const T* getObject() const override { return &d_value; }
  const std::string getObjectAsString(const T& other) const override {
    std::stringstream ss;
    ss << "span with elements: [";
    bool isFirst = true;
    for (const auto& elem : other) {
      if (!isFirst) {
        ss << ", ";
      }
      ss << elem;
      isFirst = false;
    }
    ss << "]";
    return ss.str();
  }

 public:
  SpanSubject(const bool failOnError, const char* file, int line, const T& v)
      : Base(failOnError, file, line), d_value(v) {}

};

}  // namespace assertcc::subject

#endif
