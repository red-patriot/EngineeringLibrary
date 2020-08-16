#include "pch.h"

#include "MomentOfArea.h"
#include "Volume.h"
#include "Area.h"
#include "Length.h"
#include "Velocity.h"
#include "TIme.h"
#include "PhysicsMath.h"

namespace physics {
  // Negation operator
  Length operator-(const Length& lh) {
    return Length(-lh.value());
  }
  // Mathematical Operators
  Length operator+ (const Length& lh, const Length& rh) {
    return Length(lh.value() + rh.value());
  }

  Length operator- (const Length& lh, const Length& rh) {
    return Length(lh.value() - rh.value());
  }

  Length operator* (const Length& lh, const double& n) {
    return Length(lh.value() * n);
  }
  Length operator* (const double& n, const Length& rh) {
    return rh * n;
  }
  Length operator* (const Velocity& lh, const Time& rh) {
    return Length(lh.value() * rh.value());
  }
  Length operator* (const Time& lh, const Velocity& rh) {
    return rh * lh;
  }

  Length operator/ (const Length& lh, const double& n) {
    return Length(lh.value() / n);
  }
  Length operator/ (const Area& lh, const Length& rh) {
    return Length(lh.value() / rh.value());
  }
  Length operator/ (const Volume& lh, const Area& rh) {
    return Length(lh.value() / rh.value());
  }
  Length operator/ (const SecondMomentOfArea& lh, const Volume& rh) {
    return Length(lh.value() / rh.value());
  }
  double operator/ (const Length& lh, const Length& rh) {
    return lh.value() / rh.value();
  }

  // Comparison operators
  bool operator== (const Length& lh, const Length& rh) {
    return fuzzy_equals(lh.value(), rh.value());
  }
  bool operator> (const Length& lh, const Length& rh) {
    return fuzzy_greater(lh.value(), rh.value());
  }
  bool operator!= (const Length& lh, const Length& rh) {
    return !(lh == rh);
  }
  bool operator< (const Length& lh, const Length& rh) {
    return rh > lh;
  }
  bool operator>= (const Length& lh, const Length& rh) {
    return lh > rh || lh == rh;
  }
  bool operator<= (const Length& lh, const Length& rh) {
    return rh > lh || lh == rh;
  }

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
    return Length(val * 1000);
  }
  Length operator"" _km (unsigned long long val) {
    return Length(val * 1000);
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

}; // namespace physics 
