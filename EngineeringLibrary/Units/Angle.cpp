#include "pch.h"

#include "Angle.h"
#include "PhysicsMath.h"

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

};  // namespace eng
