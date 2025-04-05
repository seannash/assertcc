#pragma once

#include <assertcc/proposition/boolpropositions.h>
#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/subject/base.h>

namespace assertcc::subject {

class BoolSubject : virtual public Base<bool>,
                    public proposition::BoolPropositions<BoolSubject>,
                    public proposition::IsEqualToPropositions<BoolSubject, bool> {
  const bool d_value;

 protected:
  const bool* getObject() const override { return &d_value; }
  const std::string getObjectAsString() const override { return d_value ? "true" : "false"; }
  const std::string getObjectAsString(const bool& other) const override {
    return other ? "true" : "false";
  }

 public:
  BoolSubject(const bool failOnError, const char* file, int line, const bool v)
      : Base<bool>(failOnError, file, line), d_value(v) {}
};

}  // namespace assertcc::subject
