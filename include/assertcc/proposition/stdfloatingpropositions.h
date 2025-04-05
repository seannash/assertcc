#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/util/failmessage.h>

#include <limits>
#include <memory>

namespace assertcc::proposition {

template <typename T, typename U>
class FloatingPropositions : public virtual subject::Base<U> {
 protected:
  virtual const U* getTolerance() const = 0;

 public:
  T& isEqualTo(const U& other) {
    double relativeDifference = (*this->getObject() - other) / other;
    if (std::abs(relativeDifference) >= *this->getTolerance()) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("value is equal to", other)
          .fact("Got", this->getObjectAsString());
    }
    return *dynamic_cast<T*>(this);
  }

  T& isNotEqualTo(const U& other) {
    double relativeDifference = (*this->getObject() - other) / other;
    if (std::abs(relativeDifference) < *this->getTolerance()) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("value is notequal to", other)
          .fact("Got", this->getObjectAsString())
          .build();
    }
    return *dynamic_cast<T*>(this);
  }

  T& isNan() {
    if (!std::isnan(*this->getObject())) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("value is not a number")
          .fact("Got", this->getObjectAsString())
          .build();
    }
    return *dynamic_cast<T*>(this);
  }

  T& isNotNan() {
    if (std::isnan(*this->getObject())) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("value is not the special not a number value")
          .fact("Got", this->getObjectAsString())
          .build();
    }
    return *dynamic_cast<T*>(this);
  }

  T& isFinite() {
    if (!std::isfinite(*this->getObject())) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("value is finite")
          .fact("Got", this->getObjectAsString())
          .build();
    }
    return *dynamic_cast<T*>(this);
  }

  T& isNotFinite() {
    if (std::isfinite(*this->getObject())) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("value is not finite")
          .fact("Got", this->getObjectAsString())
          .build();
    }
    return *dynamic_cast<T*>(this);
  }

  T& isPositiveInfinity() {
    if ((*this->getObject()) != std::numeric_limits<U>::infinity()) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("value is not finite")
          .fact("Got", this->getObjectAsString())
          .build();
    }
    return *dynamic_cast<T*>(this);
  }

  T& isNegativeInfinity() {
    if ((*this->getObject()) != -std::numeric_limits<U>::infinity()) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("value is not finite")
          .fact("Got", this->getObjectAsString())
          .build();
    }
    return *dynamic_cast<T*>(this);
  }

  T& isZero() {
    if ((*this->getObject()) != 0.0) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("value is zero")
          .fact("Got", this->getObjectAsString())
          .build();
    }
    return *dynamic_cast<T*>(this);
  }

  T& isNotZero() {
    if ((*this->getObject()) == 0.0) {
      util::FailMessage::create()
          .failOnError(this->getFailOnError())
          .file(this->getFile())
          .line(this->getLine())
          .fact("value is not zero")
          .fact("Got", this->getObjectAsString());
    }
    return *dynamic_cast<T*>(this);
  }

};

}  // namespace assertcc::proposition
