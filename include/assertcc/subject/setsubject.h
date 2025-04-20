#pragma once

#include <assertcc/proposition/hassizepropositions.h>
#include <assertcc/proposition/isemptypropositions.h>
#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>

namespace assertcc::subject {

template <typename C>
class SetSubject : public virtual Base<C>,
                   public proposition::ContainsPropositions<SetSubject<C>, C>,
                   public proposition::IsEmptyPropositions<SetSubject<C>, C>,
                   public proposition::IsEqualToPropositions<SetSubject<C>, C>,
                   public proposition::HasSizePropositions<SetSubject<C>, C> {
  const C& d_value;

 public:
  SetSubject(const bool failOnError, const char* file, int line, const C& v)
      : Base<C>(failOnError, file, line), d_value(v) {}

 protected:
  const C* getObject() const override { return &d_value; }
  const std::string getObjectAsString(const C& other) const override {
    std::stringstream ss;
    ss << "set with elements: {";
    bool isFirst = true;
    for (const auto& elem : other) {
      if (!isFirst) {
        ss << ", ";
      }
      ss << elem;
      isFirst = false;
    }
    ss << "}";
    return ss.str();
  }

};


}  // namespace assertcc::subject
