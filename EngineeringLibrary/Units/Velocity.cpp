#include "pch.h"

#include "Force.h"
#include "Damping.h"
#include "Velocity.h"
#include "Acceleration.h"
#include "Time.h"
#include "Length.h"

namespace eng {

  /* Literal operators
   * The following units are supported:
   * m/s, kph,
   * in/s, ft/s, mph
   */

  Velocity operator"" _mpsec (long double val) {
    return Velocity(val);
  }
  Velocity operator"" _mpsec (unsigned long long val) {
    return Velocity(val);
  }

  Velocity operator"" _kph (long double val) {
    return Velocity(val * 0.277'777'777'777'778);
  }
  Velocity operator"" _kph (unsigned long long val) {
    return Velocity(val * 0.277'777'777'777'778);
  }

  Velocity operator"" _inpsec (long double val) {
    return Velocity(val * 0.0254);
  }
  Velocity operator"" _inpsec (unsigned long long val) {
    return Velocity(val * 0.0254);
  }

  Velocity operator"" _ftpsec (long double val) {
    return Velocity(val * 0.3048);
  }
  Velocity operator"" _ftpsec (unsigned long long val) {
    return Velocity(val * 0.3048);
  }

  Velocity operator"" _mph (long double val) {
    return Velocity(val * 0.44704);
  }
  Velocity operator"" _mph (unsigned long long val) {
    return Velocity(val * 0.44704);
  }

};  // namespace eng
