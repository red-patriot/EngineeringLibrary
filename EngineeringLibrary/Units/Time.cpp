#include "pch.h"

#include "Time.h"
#include "PhysicsMath.h"

namespace eng {

  /* Literal operators
   * The following units are supported:
   * sec, minute, hour
   */

  Time operator"" _sec (long double val) {
    return Time(val);
  }
  Time operator"" _sec (unsigned long long val) {
    return Time(val);
  }

  Time operator"" _minute (long double val) {
    return Time(val * 60.0);
  }
  Time operator"" _minute (unsigned long long val) {
    return Time(val * 60.0);
  }

  Time operator"" _hour (long double val) {
    return Time(val * 3600.0);
  }
  Time operator"" _hour (unsigned long long val) {
    return Time(val * 3600.0);
  }

};  // namespace eng
