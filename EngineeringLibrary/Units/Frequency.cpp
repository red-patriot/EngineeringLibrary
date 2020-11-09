#include "pch.h"

#include "Time.h"
#include "Frequency.h"
#include "Mass.h"
#include "Length.h"
#include "Stiffness.h"
#include "Velocity.h"
#include "Acceleration.h"
#include "PhysicsMath.h"

namespace eng {

  /* Literal operators
   * The following units are supported:
   * Hz, kHz, MHz
   */

  Frequency operator"" _Hz (long double val) {
    return Frequency(val);
  }
  Frequency operator"" _Hz (unsigned long long val) {
    return Frequency(val);
  }

  Frequency operator"" _kHz (long double val) {
    return Frequency(val * 1'000.0);
  }
  Frequency operator"" _kHz (unsigned long long val) {
    return Frequency(val * 1'000.0);
  }

  Frequency operator"" _MHz (long double val) {
    return Frequency(val * 1'000'000.0);
  }
  Frequency operator"" _MHz (unsigned long long val) {
    return Frequency(val * 1'000'000.0);
  }

};
