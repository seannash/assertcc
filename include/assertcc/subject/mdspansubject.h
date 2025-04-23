#pragma once

#include <assertcc/proposition/hassizepropositions.h>
#include <assertcc/proposition/isemptypropositions.h>
#include <assertcc/subject/base.h>

#include <mdspan>

namespace assertcc::subject {
template <typename T>
class MdspanSubject : public virtual Base<T>,
                      public proposition::HasSizePropositions<MdspanSubject<T>, T>,
                      public proposition::IsEmptyPropositions<MdspanSubject<T>, T> {
 public:
  MdspanSubject(bool failOnError, const char* file, int line, const T& v)
      : Base<T>(failOnError, file, line), d_object(v) {}

 private:
  T d_object;

  const T* getObject() const override { return &d_object; }
  const std::string getObjectAsString(const T& other) const override {
    std::stringstream ss;
    ss << "mdspan with elements: [";
    for (size_t i = 0; i < other.extent(0); ++i) {
      // ss << other(i) << ", ";
    }
    ss << "]";
    return ss.str();
  }
};

}  // namespace assertcc::subject
