#include "pch.h"

#include "PhysicsMath.h"
#include "Stiffness.h"
#include "Force.h"
#include "Pressure.h"
#include "Damping.h"
#include "Length.h"
#include "Time.h"

namespace eng {
  
  /* Literal operators
   * The following units are supported:
   * N/m, N/mm,
   * lb/in, lb/ft
  */

  Stiffness operator""_Npm(long double val) {
    return Stiffness(val);
  }

  Stiffness operator""_Npm(unsigned long long val) {
    return Stiffness(val);
  }

  Stiffness operator""_Npmm(long double val) {
    return Stiffness(val * 1000.0);
  }

  Stiffness operator""_Npmm(unsigned long long val) {
    return Stiffness(val * 1000.0);
  }

  Stiffness operator""_lbpin(long double val) {
    return Stiffness(val * 175.12683524647637795);
  }

  Stiffness operator""_lbpin(unsigned long long val) {
    return Stiffness(val * 175.12683524647637795);
  }

  Stiffness operator""_lbpft(long double val) {
    return Stiffness(val * 14.593902937206364829);
  }

  Stiffness operator""_lbpft(unsigned long long val) {
    return Stiffness(val * 14.593902937206364829);
  }

};  // namespace eng
