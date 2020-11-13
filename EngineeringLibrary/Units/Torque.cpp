#include "pch.h"

#include "Length.h"
#include "Force.h"
#include "Torque.h"

namespace eng {

  /* Literal operators
   * The following units are suported:
   * Nm, kNm, Nmm,
   * lb*ft, lb*in
   */

  Torque operator"" _Nm (long double val) {
    return Torque(val);
  }
  Torque operator"" _Nm (unsigned long long val) {
    return Torque(val);
  }

  Torque operator"" _kNm (long double val) {
    return Torque(val * 1000.0);
  }
  Torque operator"" _kNm (unsigned long long val) {
    return Torque(val * 1000.0);
  }

  Torque operator"" _Nmm (long double val) {
    return Torque(val * 0.001);
  }
  Torque operator"" _Nmm (unsigned long long val) {
    return Torque(val * 0.001);
  }

  Torque operator"" _lbft (long double val) {
    return Torque(val * 1.3558179483314);
  }
  Torque operator"" _lbft (unsigned long long val) {
    return Torque(val * 1.3558179483314);
  }

  Torque operator"" _lbin (long double val) {
    return Torque(val * 0.11298482902413);
  }
  Torque operator"" _lbin (unsigned long long val) {
    return Torque(val * 0.11298482902413);
  }

};  // namespace eng
