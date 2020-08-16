#include "pch.h"

#include "MomentOfArea.h"
#include "Volume.h"
#include "Area.h"
#include "Length.h"
#include "PhysicsMath.h"

namespace physics {
  // Negation operator
  Volume operator-(const Volume& lh) {
    return Volume(-lh.value());
  }
  // Mathematical Operators
  Volume operator+ (const Volume& lh, const Volume& rh) {
    return Volume(lh.value() + rh.value());
  }

  Volume operator- (const Volume& lh, const Volume& rh) {
    return Volume(lh.value() - rh.value());
  }

  Volume operator* (const Area& lh, const Length& rh) {
    return Volume(lh.value() * rh.value());
  }
  Volume operator* (const Length& lh, const Area& rh) {
    return rh * lh;
  }
  Volume operator* (const Volume& lh, const double& n) {
    return Volume(lh.value() * n);
  }
  Volume operator* (const double& n, const Volume& rh) {
    return rh * n;
  }

  Volume  operator/ (const SecondMomentOfArea& lh, const Length& rh) {
    return Volume(lh.value() / rh.value());
  }
  double operator/ (const Volume& lh, const Volume& rh) {
    return lh.value() / rh.value();
  }
  Volume operator/ (const Volume& lh, const double& n) {
    return Volume(lh.value() / n);
  }

  // Comparison Operators
  bool operator== (const Volume& lh, const Volume& rh) {
    return fuzzy_equals(lh.value(), rh.value());
  }
  bool operator> (const Volume& lh, const Volume& rh) {
    return fuzzy_greater(lh.value(), rh.value());
  }
  bool operator!= (const Volume& lh, const Volume& rh) {
    return !(lh == rh);
  }
  bool operator< (const Volume& lh, const Volume& rh) {
    return rh > lh;
  }
  bool operator>= (const Volume& lh, const Volume& rh) {
    return lh > rh || lh == rh;
  }
  bool operator<= (const Volume& lh, const Volume& rh) {
    return rh > lh || lh == rh;
  }

  /* Literal operators
   * The following units are supported:
   * mm^3, cm^3, m^3
   * in^3, ft^3
   */
  Volume operator""_mm3(long double val) {
    return Volume(val * 0.000'000'001);
  }

  Volume operator""_mm3(unsigned long long val) {
    return Volume(val * 0.000'000'001);
  }

  Volume operator""_cm3(long double val) {
    return Volume(val * 0.000001);
  }

  Volume operator""_cm3(unsigned long long val) {
    return Volume(val * 0.000001);
  }

  Volume operator""_m3(long double val) {
    return Volume(val);
  }

  Volume operator""_m3(unsigned long long val) {
    return Volume(val);
  }

  Volume operator""_in3(long double val) {
    return Volume(val * (16.387'064/1'000'000));
  }

  Volume operator""_in3(unsigned long long val) {
    return Volume(val * (16.387'064/1'000'000));
  }

  Volume operator""_ft3(long double val) {
    return Volume(val * (28'316.846'592/1'000'000));
  }

  Volume operator""_ft3(unsigned long long val) {
    return Volume(val * (28'316.846'592/1'000'000));
  }

}; // namespace physics
