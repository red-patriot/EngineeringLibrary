#include "pch.h"
#include "MomentOfArea.h"
#include "Volume.h"
#include "Area.h"
#include "Length.h"
#include "PhysicsMath.h"

namespace eng {

  /* Literal operators
   * The following units are supported:
   * mm^4, m^4
   * in^4, ft^4
   */

  SecondMomentOfArea operator"" _mm4(long double val) {
    return SecondMomentOfArea(val * 0.000'000'000'001);
  }
  SecondMomentOfArea operator"" _mm4(unsigned long long val) {
    return SecondMomentOfArea(val * 0.000'000'000'001);
  }

  SecondMomentOfArea operator"" _m4(long double val) {
    return SecondMomentOfArea(val);
  }
  SecondMomentOfArea operator"" _m4(unsigned long long val) {
    return SecondMomentOfArea(val);
  }

  SecondMomentOfArea operator"" _in4(long double val) {
    return SecondMomentOfArea(val * 41.623'142'56 / 100'000'000);
  }
  SecondMomentOfArea operator"" _in4(unsigned long long val) {
    return SecondMomentOfArea(val * 41.623'142'56 / 100'000'000);
  }

  SecondMomentOfArea operator"" _ft4(long double val) {
    return SecondMomentOfArea(val * 863'097.481'241'6 / 100'000'000);
  }
  SecondMomentOfArea operator"" _ft4(unsigned long long val) {
    return SecondMomentOfArea(val * 863'097.481'241'6 / 100'000'000);
  }

}; // namespace eng
