#include "pch.h"

#include "Pressure.h"
#include "Force.h"
#include "Stiffness.h"
#include "Length.h"
#include "Area.h"
#include "PhysicsMath.h"

/*
 * Pressure function definitions
 */

namespace physics {

  // Negation operator
  Pressure operator- (const Pressure& lh) {
    return Pressure(-lh.value());
  }

  // Mathematical Operators
  Pressure operator+ (const Pressure& lh, const Pressure& rh) {
    return Pressure(lh.value() + rh.value());
  }

  Pressure operator- (const Pressure& lh, const Pressure& rh) {
    return Pressure(lh.value() - rh.value());
  }

  Pressure operator* (const Pressure& lh, const double& n) {
    return Pressure(lh.value() * n);
  }
  Pressure operator* (const double& n, const Pressure& rh) {
    return rh * n;
  }
  Pressure physics::operator/(const Stiffness& lh, const Length& rh) {
    return Pressure(lh.value() / rh.value());
  }

  Pressure operator/ (const Force& lh, const Area& rh) {
    return Pressure(lh.value() / rh.value());
  }

  double operator/ (const Pressure& lh, const Pressure& rh) {
    return lh.value() / rh.value();
  }
  Pressure operator/ (const Pressure& lh, const double& n) {
    return Pressure(lh.value() / n);
  }

  // Comparison Operators
  bool operator== (const Pressure& lh, const Pressure& rh) {
    return fuzzy_equals(lh.value(), rh.value());
  }
  bool operator> (const Pressure& lh, const Pressure& rh) {
    return fuzzy_greater(lh.value(), rh.value());
  }

  bool operator!= (const Pressure& lh, const Pressure& rh) {
    return !(lh == rh);
  }
  bool operator< (const Pressure& lh, const Pressure& rh) {
    return rh > lh;
  }
  bool operator>= (const Pressure& lh, const Pressure& rh) {
    return lh > rh || lh == rh;
  }
  bool operator<= (const Pressure& lh, const Pressure& rh) {
    return rh > lh || lh == rh;
  }

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
    return Pressure(val * 1000);
  }
  Pressure operator"" _kPa (unsigned long long val) {
    return Pressure(val * 1000);
  }

  Pressure operator"" _MPa (long double val) {
    return Pressure(val * 1'000'000);
  }
  Pressure operator"" _MPa (unsigned long long val) {
    return Pressure(val * 1'000'000);
  }

  Pressure operator"" _GPa (long double val) {
    return Pressure(val * 1'000'000'000);
  }
  Pressure operator"" _GPa (unsigned long long val) {
    return Pressure(val * 1'000'000'000);
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

  Pressure2 operator+(const Pressure2& lh, const Pressure2& rh) {
    return Pressure2(lh.value() + rh.value());
  }

  Pressure2 operator-(const Pressure2& lh, const Pressure2& rh) {
    return Pressure2(lh.value() - rh.value());
  }

  Pressure2 operator* (const Pressure& lh, const Pressure& rh) {
    return Pressure2(lh.value() * rh.value());
  }

  Pressure2 operator*(const Pressure2& lh, const double& n) {
    return Pressure2(lh.value() * n);
  }

  Pressure2 operator*(const double& n, const Pressure2& rh) {
    return rh * n;
  }

  Pressure2 operator/(const Pressure2& lh, const double& n) {
    return Pressure2(lh.value() / n);
  }

  Pressure operator/(const Pressure2& lh, const Pressure& rh) {
    return Pressure(lh.value() / rh.value());
  }

  double operator/(const Pressure2& lh, const Pressure2& rh) {
    return lh.value() / rh.value();
  }

}; // namespace physics
