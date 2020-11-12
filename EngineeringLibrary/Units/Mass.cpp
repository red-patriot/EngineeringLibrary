#include "pch.h"

#include "Mass.h"
#include "Force.h"
#include "Damping.h"
#include "Acceleration.h"
#include "Time.h"

namespace eng {

  /* Literal operators
   * The following units are supported:
   * g, kg,
   * slug
   */

  Mass operator"" _g (long double val) {
    return Mass(val * 0.001);
  }
  Mass operator"" _g (unsigned long long val) {
    return Mass(val * 0.001);
  }

  Mass operator"" _kg (long double val) {
    return Mass(val);
  }
  Mass operator"" _kg (unsigned long long val) {
    return Mass(val);
  }

  Mass operator"" _slug (long double val) {
    return Mass(val * 14.593903);
  }
  Mass operator"" _slug (unsigned long long val) {
    return Mass(val * 14.593903);
  }

};  // namespace eng
