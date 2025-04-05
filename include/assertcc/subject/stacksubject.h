#pragma once

#include <assertcc/proposition/hassizepropositions.h>
#include <assertcc/proposition/isemptypropositions.h>
#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/subject/base.h>

#include <stack>

namespace assertcc::subject {

template <typename T>
class StackSubject : public virtual Base<T>,
                     public proposition::HasSizePropositions<StackSubject<T>, T>,
                     public proposition::IsEmptyPropositions<StackSubject<T>, T>,
                     public proposition::IsEqualToPropositions<StackSubject<T>, T> {
  const T d_value;

 protected:
  const T* getObject() const override { return &d_value; }
  const std::string getObjectAsString() const override {
    return getObjectAsString(d_value);
  }
  const std::string getObjectAsString(const T& other) const override {
    std::stringstream ss;
    ss << "stack with " << other.size() << " elements";
    if (other.size() > 1) {
      ss << ", top element: " << other.top();
    }
    return ss.str();
  }

 public:
  StackSubject(const bool failOnError, const char* file, int line, const T& v)
      : Base<T>(failOnError, file, line), d_value(v) {}
};

}  // namespace assertcc::subject
