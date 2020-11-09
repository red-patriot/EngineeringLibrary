#include "pch.h"

#include "MomentOfArea.h"
#include "Volume.h"
#include "Area.h"
#include "Length.h"
#include "Force.h"
#include "Torque.h"
#include "Energy.h"
#include "Velocity.h"
#include "Time.h"
#include "PhysicsMath.h"

namespace eng {

  /* Literal operators
   * The following units are supported:
   * mm, cm, m, km
   * in, ft, mi
   */

  Length operator"" _mm (long double val) {
    return Length(val * 0.001);
  }
  Length operator"" _mm (unsigned long long val) {
    return Length(val * 0.001);
  }

  Length operator"" _cm (long double val) {
    return Length(val * 0.01);
  }
  Length operator"" _cm (unsigned long long val) {
    return Length(val * 0.01);
  }

  Length operator"" _m (long double val) {
    return Length(val);
  }
  Length operator"" _m (unsigned long long val) {
    return Length(val);
  }

  Length operator"" _km (long double val) {
    return Length(val * 1000.0);
  }
  Length operator"" _km (unsigned long long val) {
    return Length(val * 1000.0);
  }

  Length operator"" _in (long double val) {
    return Length(val * (2.54/100));
  }
  Length operator"" _in (unsigned long long val) {
    return Length(val * (2.54/100));
  }

  Length operator"" _ft (long double val) {
    return Length(val * (30.48/100));
  }
  Length operator"" _ft (unsigned long long val) {
    return Length(val * (30.48/100));
  }

  Length operator"" _mi (long double val) {
    return Length(val * (160'934.4/100));
  }
  Length operator"" _mi (unsigned long long val) {
    return Length(val * (160'934.4/100));
  }

}; // namespace eng 
