#include "pch.h"

#include "Acceleration.h"
#include "Velocity.h"
#include "Time.h"
#include "Mass.h"
#include "Force.h"
#include "PhysicsMath.h"

namespace eng {

  /* Literal operators
   * The following units are supported:
   * m / s^2, 
   * in / s^2, ft / s^2
   */

  Acceleration operator"" _mpsec2 (long double val) {
    return Acceleration(val);
  }
  Acceleration operator"" _mpsec2 (unsigned long long val) {
    return Acceleration(val);
  }

  Acceleration operator"" _inpsec2 (long double val) {
    return Acceleration(val * (2.54/100));
  }
  Acceleration operator"" _inpsec2 (unsigned long long val) {
    return Acceleration(val * (2.54/100));
  }

  Acceleration operator"" _ftpsec2 (long double val) {
    return Acceleration(val * (30.48/100));
  }
  Acceleration operator"" _ftpsec2 (unsigned long long val) {
    return Acceleration(val * (30.48/100));
  }

};
