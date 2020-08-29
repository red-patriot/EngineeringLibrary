#include "pch.h"

#include "Angle.h"
#include "PhysicsMath.h"

namespace eng {

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

  bool operator== (const Angle& lh, const Angle& rh) {
    return fuzzy_equals(lh.value(), rh.value());
  }
  bool operator> (const Angle& lh, const Angle& rh) {
    return fuzzy_greater(lh.value(), rh.value());
  }
  bool operator!= (const Angle& lh, const Angle& rh) {
    return !(lh == rh);
  }
  bool operator< (const Angle& lh, const Angle& rh) {
    return rh > lh;
  }
  bool operator>= (const Angle& lh, const Angle& rh) {
    return lh > rh || lh == rh;
  }
  bool operator<= (const Angle& lh, const Angle& rh) {
    return rh > lh || lh == rh;
  }

  /* Literals operators
   * The following units are supported: 
   * radians, degrees
   */
  Angle operator""_deg(long double val) {
    return Angle(val * pi / 180.0);
  }

  Angle operator""_deg(unsigned long long val) {
    return Angle(val * pi / 180.0);
  }

  Angle operator""_rad(long double val) {
    return Angle(val);
  }

  Angle operator""_rad(unsigned long long val) {
    return Angle(val);
  }

};  // namespace eng
