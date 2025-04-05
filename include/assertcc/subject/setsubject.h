#pragma once

#include <assertcc/proposition/hassizepropositions.h>
#include <assertcc/proposition/isemptypropositions.h>
#include <assertcc/proposition/isequaltopropositions.h>
#include <assertcc/subject/base.h>

namespace assertcc::subject {

template <typename C>
class SetSubject : public virtual Base,
                   public proposition::IsEmptyPropositions<SetSubject<C>, C>,
                   public proposition::IsEqualToPropositions<SetSubject<C>, C>,
                   public proposition::HasSizePropositions<SetSubject<C>, C> {
  const C& d_value;

 public:
  SetSubject(const bool failOnError, const char* file, int line, const C& v)
      : Base(failOnError, file, line), d_value(v) {}

 protected:
  const C* getValue() const override { return &d_value; }
};

}  // namespace assertcc::subject