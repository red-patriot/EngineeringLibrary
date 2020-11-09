#include "pch.h"

#include "PhysicsMath.h"
#include "Force.h"
#include "Torque.h"
#include "Energy.h"
#include "Stiffness.h"
#include "Pressure.h"
#include "Length.h"
#include "Area.h"
#include "Damping.h"
#include "Velocity.h"
#include "Acceleration.h"
#include "Mass.h"

namespace eng {

  /* Literal operators
   * The following units are supported:
   * N, kN
   * lbf, kips
   */

  Force  operator"" _N(long double val) {
    return Force(val);
  }
  Force  operator"" _N(unsigned long long val) {
    return Force(val);
  }

  Force  operator"" _kN(long double val) {
    return Force(val * 1000.0);
  }
  Force  operator"" _kN(unsigned long long val) {
    return Force(val * 1000.0);
  }

  Force  operator"" _lbf(long double val) {
    return Force(val * 4.4482216152605);
  }
  Force  operator"" _lbf(unsigned long long val) {
    return Force(val * 4.4482216152605);
  }

  Force  operator"" _kips(long double val) {
    return Force(val * 4448.2216152605);
  }
  Force  operator"" _kips(unsigned long long val) {
    return Force(val * 4448.2216152605);
  }

}; // namespace eng
