#pragma once

#include <assertcc/proposition/hasbackthatpropositions.h>
#include <assertcc/proposition/hasfrontthatpropositions.h>
#include <assertcc/proposition/hassizepropositions.h>
#include <assertcc/proposition/isemptypropositions.h>
#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/subject/base.h>

#include <queue>
#include <sstream>

namespace assertcc::subject {

template <typename T>
class QueueSubject : public virtual Base<T>,
                     public proposition::IsEmptyPropositions<QueueSubject<T>, T>,
                     public proposition::HasSizePropositions<QueueSubject<T>, T>,
                     public proposition::HasFrontThatPropositions<QueueSubject<T>, T>,
                     public proposition::HasBackThatPropositions<QueueSubject<T>, T>,
                     public proposition::IsEqualToPropositions<QueueSubject<T>, T> {
  const T d_value;

 protected:
  const T* getObject() const override { return &d_value; }
  const std::string getObjectAsString(const T& other) const override {
    std::stringstream ss;
    ss << "queue with first and last elements: [" << other.front() << ", " << other.back() << "]";
    return ss.str();
  }

 public:
  QueueSubject(const bool failOnError, const char* file, int line, const T& v)
      : Base<T>(failOnError, file, line), d_value(v) {}
};

}  // namespace assertcc::subject