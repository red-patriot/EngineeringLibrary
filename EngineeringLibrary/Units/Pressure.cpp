#include "pch.h"

#include "Pressure.h"
#include "Force.h"
#include "Stiffness.h"
#include "Length.h"
#include "Area.h"
#include "PhysicsMath.h"

namespace eng {

  /* Literal operators
   * The following units are supported:
   * Pa, kPa, MPa, GPa
   * psi, ksi, Mpsi, lb/ft^2
   */

  Pressure operator"" _Pa (long double val) {
    return Pressure(val);
  }
  Pressure operator"" _Pa (unsigned long long val) {
    return Pressure(val);
  }

  Pressure operator"" _kPa (long double val) {
    return Pressure(val * 1000.0);
  }
  Pressure operator"" _kPa (unsigned long long val) {
    return Pressure(val * 1000.0);
  }

  Pressure operator"" _MPa (long double val) {
    return Pressure(val * 1'000'000.0);
  }
  Pressure operator"" _MPa (unsigned long long val) {
    return Pressure(val * 1'000'000.0);
  }

  Pressure operator"" _GPa (long double val) {
    return Pressure(val * 1'000'000'000.0);
  }
  Pressure operator"" _GPa (unsigned long long val) {
    return Pressure(val * 1'000'000'000.0);
  }

  Pressure operator"" _psi (long double val) {
    return Pressure(val * 6'894.757'293'168'361);
  }
  Pressure operator"" _psi (unsigned long long val) {
    return Pressure(val * 6'894.757'293'168'361);
  }

  Pressure operator"" _ksi (long double val) {
    return Pressure(val * 6'894'757.293'168'361);
  }
  Pressure operator"" _ksi (unsigned long long val) {
    return Pressure(val * 6'894'757.293'168'361);
  }

}; // namespace eng
