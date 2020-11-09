#include "pch.h"

#include "PhysicsMath.h"
#include "Energy.h"
#include "Force.h"
#include "Length.h"

namespace eng {

  /* Literal operators
   * The following units are suported:
   * J, kJ, MJ,
   * ft*lb, in*lb, BTU
   */

  Energy operator"" _J (long double val) {
    return Energy(val);
  }
  Energy operator"" _J (unsigned long long val) {
    return Energy(val);
  }

  Energy operator"" _kJ (long double val) {
    return Energy(val * 1000.0);
  }
  Energy operator"" _kJ (unsigned long long val) {
    return Energy(val * 1000.0);
  }

  Energy operator"" _MJ (long double val) {
    return Energy(val * 1'000'000.0);
  }
  Energy operator"" _MJ (unsigned long long val) {
    return Energy(val * 1'000'000.0);
  }

  Energy operator"" _ftlb (long double val) {
    return Energy(val * 1.3558179483314);
  }
  Energy operator"" _ftlb (unsigned long long val) {
    return Energy(val * 1.3558179483314);
  }

  Energy operator"" _inlb (long double val) {
    return Energy(val * 0.11298482902413);
  }
  Energy operator"" _inlb (unsigned long long val) {
    return Energy(val * 0.11298482902413);
  }

  Energy operator"" _BTU (long double val) {
    return Energy(val * 1055.87);
  }
  Energy operator"" _BTU (unsigned long long val) {
    return Energy(val * 1055.87);
  }
};
