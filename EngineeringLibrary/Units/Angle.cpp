#include "pch.h"

#include "Angle.h"
#include "PhysicsMath.h"

namespace physics {

  double Angle::rad() const {
    return value();
  }

  double Angle::deg() const {
    return value() * 180 / pi;
  }

  Angle::operator double() { 
    return value();
  }

  Angle operator-(const Angle& rh) {
    return Angle(-rh.value());
  }

  Angle operator+(const Angle& lh, const Angle& rh) {
    return Angle(lh.value() + rh.value());
  }

  Angle operator-(const Angle& lh, const Angle& rh) {
    return Angle(lh.value() - rh.value());
  }

  Angle operator*(const Angle& lh, const double& n) {
    return Angle(lh.value() * n);
  }

  Angle operator*(const double& n, const Angle& rh) {
    return rh * n;
  }

  Angle operator/(const Angle& lh, const double& n) {
    return Angle(lh.value() / n);
  }

  /* Literals operators
   * The following units are supported: 
   * radians, degrees
   */
  Angle operator""_deg(long double val) {
    return Angle(val * pi / 180);
  }

  Angle operator""_deg(unsigned long long val) {
    return Angle(val * pi / 180);
  }

  Angle operator""_rad(long double val) {
    return Angle(val);
  }

  Angle operator""_rad(unsigned long long val) {
    return Angle(val);
  }

};  // namespace physics
