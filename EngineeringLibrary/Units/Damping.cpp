#include "pch.h"

#include "Time.h"
#include "Frequency.h"
#include "Mass.h"
#include "Damping.h"
#include "Stiffness.h"

namespace eng {

  /* Literal operators
   * The following units are supported:
   * Ns / m, kNs / m,
   * lbs/ in, lbs / ft
   */

  Damping operator"" _Nspm (long double val) {
    return Damping(val);
  }
  Damping operator"" _Nspm (unsigned long long val) {
    return Damping(val);
  }

  Damping operator"" _kNspm (long double val) {
    return Damping(val * 1000.0);
  }
  Damping operator"" _kNspm (unsigned long long val) {
    return Damping(val * 1000.0);
  }

  Damping operator"" _lbspin (long double val) {
    return Damping(val * (4.4482216152605/.0254));
  }
  Damping operator"" _lbspin (unsigned long long val) {
    return Damping(val * (4.4482216152605/.0254));
  }

  Damping operator"" _lbspft (long double val) {
    return Damping(val * (4.4482216152605/.3048));
  }
  Damping operator"" _lbspft (unsigned long long val) {
    return Damping(val * (4.4482216152605/.3048));
  }

};  // namespace eng
