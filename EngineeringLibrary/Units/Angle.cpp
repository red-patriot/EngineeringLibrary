#include "pch.h"

#include "Angle.h"

namespace eng {

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

  double sin(const Angle& a) {
    return std::sin(a.rad());
  }
  double cos(const Angle& a) {
    return std::cos(a.rad());
  }
  double tan(const Angle& a) {
    return std::tan(a.rad());
  }
  Angle asin(const double& x) {
    return Angle(std::asin(x));
  }
  Angle acos(const double& x) {
    return Angle(std::acos(x));
  }
  Angle atan(const double& x) {
    return Angle(std::atan(x));
  }
  Angle atan2(const double& x, const double& y) {
    return Angle(std::atan2(x, y));
  }

};  // namespace eng
