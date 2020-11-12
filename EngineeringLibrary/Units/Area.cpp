#include "pch.h"

#include "MomentOfArea.h"
#include "Volume.h"
#include "Area.h"
#include "Length.h"

namespace eng {

  /* Literal operators
   * The following units are supported:
   * mm^2, cm^2, m^2
   * in^2, ft^2
   */

    Area operator"" _mm2(long double val) {
      return Area(val * 0.000001);
    }
    Area operator"" _mm2(unsigned long long val) {
      return Area(val * 0.000001);
    }

    Area operator"" _cm2(long double val) {
      return Area(val * 0.0001);
    }
    Area operator"" _cm2(unsigned long long val) {
      return Area(val * 0.0001);
    }

    Area operator"" _m2(long double val) {
    return Area(val);
    }
    Area operator"" _m2(unsigned long long val) {
      return Area(val);
    }

    Area operator"" _in2(long double val) {
      return Area(val * (6.4516/10'000));
    }
    Area operator"" _in2(unsigned long long val) {
      return Area(val * (6.4516/10'000));
    }

    Area operator"" _ft2(long double val) {
      return Area(val * (929.0304/10'000));
    }
    Area operator"" _ft2(unsigned long long val) {
      return Area(val * (929.0304/10'000));
    }

};  // namespace eng
