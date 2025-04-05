#pragma once

#include <assertcc/proposition/hasvaluethatpropositions.h>
#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/proposition/isnullpropositions.h>
#include <assertcc/subject/base.h>

#include <functional>
namespace assertcc::subject {

template <typename R, typename... Args>
class FunctionSubject : public virtual Base<std::function<R(Args...)>>,
                        public proposition::IsNullPropositions<FunctionSubject<R, Args...>,
                                                               std::function<R(Args...)>> {
  const std::function<R(Args...)> d_function;

 protected:
  const std::function<R(Args...)>* getObject() const override { return &d_function; }
  const std::string getObjectAsString(const std::function<R(Args...)>& other) const override {
    return d_function == nullptr ? "an empty function" : "a function";
  }

 public:
  FunctionSubject(const bool failOnError,
                  const char* file,
                  int line,
                  const std::function<R(Args...)>& func)
      : Base<std::function<R(Args...)>>(failOnError, file, line), d_function(func) {}
};

}  // namespace assertcc::subject
