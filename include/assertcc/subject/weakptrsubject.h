#pragma once

#include <assertcc/assertcc.h>
#include <assertcc/proposition/expiredpropositions.h>
#include <assertcc/proposition/ispresentpropositions.h>
#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>

#include <memory>
#include <sstream>

namespace assertcc::subject {

template <typename T>
class WeakPtrSubject : virtual public Base<std::weak_ptr<T>>,
                       public proposition::ExpiredPropositions<WeakPtrSubject<T>, std::weak_ptr<T>>,
                       public proposition::IsPresentPropositions<WeakPtrSubject<T>, std::weak_ptr<T>> {

  const std::weak_ptr<T> d_value;

 protected:
  const std::weak_ptr<T>* getObject() const override { return &d_value; }
  const std::string getObjectAsString(const std::weak_ptr<T>& other) const override {
    std::stringstream ss;
    if (other.expired()) {
      ss << "expired weak pointer";
    } else {
      ss << "weak pointer with use count of " << other.use_count();
    }
    return ss.str();
  }

 public:
  WeakPtrSubject(const bool failOnError, const char* file, int line, const std::weak_ptr<T>& v)
      : Base<std::weak_ptr<T>>(failOnError, file, line), d_value(v) {}

  auto value() {
    auto sp = this->getObject()->lock();
    return assert_that_internal(assertcc::Adl(), 
                              this->getFailOnError(), 
                              this->getFile(), 
                              this->getLine(), 
                              *sp);
  }
};

}  // namespace assertcc::subject
