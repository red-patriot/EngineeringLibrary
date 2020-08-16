#include "pch.h"

#include "MomentOfArea.h"
#include "Volume.h"
#include "Area.h"
#include "Length.h"
#include "PhysicsMath.h"

namespace physics {
  // Negation operator
  Area operator-(const Area& lh) {
    return Area(-lh.value());
  }
  // Mathematical Operators
  Area operator+ (const Area& lh, const Area& rh) {
    return Area(lh.value() + rh.value());
  }

  Area operator- (const Area& lh, const Area& rh) {
    return Area(lh.value() - rh.value());
  }

  Area operator* (const Length& lh, const Length& rh) {
    return Area(lh.value() * rh.value());
  }
  Area operator* (const Area& lh, const double& n) {
    return Area(lh.value() * n);
  }
  Area operator* (const double& n, const Area& rh) {
    return rh *n;
  }

  Area operator/ (const Volume& lh, const Length& rh) {
    return Area(lh.value() / rh.value());
  }
  Area operator/ (const SecondMomentOfArea& lh, const Area& rh) {
    return Area(lh.value() / rh.value());
  }
  Area operator/ (const Area& lh, const double& n) {
    return Area(lh.value() / n);
  }
  double operator/ (const Area& lh, const Area& rh) {
    return lh.value() / rh.value();
  }

  // Comparison Operators
  bool operator== (const Area& lh, const Area& rh) {
    return fuzzy_equals(lh.value(), rh.value());
  }
  bool operator> (const Area& lh, const Area& rh) {
    return fuzzy_greater(lh.value(), rh.value());
  }
  bool operator!= (const Area& lh, const Area& rh) {
    return !(lh == rh);
  }
  bool operator< (const Area& lh, const Area& rh) {
    return rh > lh;
  }
  bool operator>= (const Area& lh, const Area& rh) {
    return lh > rh || lh == rh;
  }
  bool operator<= (const Area& lh, const Area& rh) {
    return rh > lh || lh == rh;
  }

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

}; // namespace physics
