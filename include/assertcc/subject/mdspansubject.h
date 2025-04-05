#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/proposition/hassizepropositions.h>
#include <assertcc/proposition/isemptypropositions.h>

#include <mdspan>

namespace assertcc::subject {
template <typename T>
class MdspanSubject : public virtual Base,
                      public proposition::HasSizePropositions<MdspanSubject<T>, T>,
                      public proposition::IsEmptyPropositions<MdspanSubject<T>, T> {
 public:

  MdspanSubject(bool failOnError, const char* file, int line, const T& v)
      : Base(failOnError, file, line), d_object(v) {}

 private:
  T d_object;

  const T* getObject() const override { return &d_object; }
  const std::string getObjectAsString() const override {
    std::stringstream ss;
    ss << "mdspan with elements: [";
    for (size_t i = 0; i < d_object.extent(0); ++i) {
      ss << d_object(i) << ", ";
    }
    ss << "]";
    return ss.str();
  }
};

} // namespace assertcc::subject
