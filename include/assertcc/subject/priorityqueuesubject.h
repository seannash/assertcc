#pragma once

#include <assertcc/proposition/hassizepropositions.h>
#include <assertcc/proposition/isemptypropositions.h>
#include <assertcc/subject/base.h>

#include <stack>

namespace assertcc::subject {

template <typename T>
class PriorityQueueSubject : public virtual Base<T>,
                             public proposition::HasSizePropositions<PriorityQueueSubject<T>, T>,
                             public proposition::IsEmptyPropositions<PriorityQueueSubject<T>, T> {
  const T d_value;

 protected:
  const T* getObject() const override { return &d_value; }
  const std::string getObjectAsString(const T& other) const override {
    std::stringstream ss;
    ss << "priority queue with " << other.size() << " elements";
    if (d_value.size() > 1) {
      ss << ", top element: " << other.top();
    }
    return ss.str();
  }

 public:
  PriorityQueueSubject(const bool failOnError, const char* file, int line, const T& v)
      : Base<T>(failOnError, file, line), d_value(v) {}
};

}  // namespace assertcc::subject
