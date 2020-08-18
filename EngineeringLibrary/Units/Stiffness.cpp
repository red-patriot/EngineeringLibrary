#include "pch.h"

#include "PhysicsMath.h"
#include "Stiffness.h"
#include "Force.h"
#include "Pressure.h"
#include "Damping.h"
#include "Length.h"
#include "Time.h"

namespace eng {
  Stiffness operator-(const Stiffness& lh) {
    return Stiffness(-lh.value());
  }

  Stiffness operator+(const Stiffness& lh, const Stiffness& rh) {
    return Stiffness(lh.value() + rh.value());
  }

  Stiffness operator-(const Stiffness& lh, const Stiffness& rh) {
    return Stiffness(lh.value() - rh.value());
  }

  Stiffness operator*(const Stiffness& lh, const double& n) {
    return Stiffness(lh.value() * n);
  }

  Stiffness operator*(const double& n, const Stiffness& rh) {
    return rh * n;
  }

  Stiffness operator*(const Pressure& lh, const Length& rh) {
    return Stiffness(lh.value() * rh.value());
  }

  Stiffness operator*(const Length& lh, const Pressure& rh) {
    return rh * lh;
  }

  Stiffness operator/(const Stiffness& lh, const double& n) {
    return Stiffness(lh.value() / n);
  }
  Stiffness operator/(const Force& lh, const Length& rh) {
    return Stiffness(lh.value() / rh.value());
  }
  Stiffness operator/ (const Damping& lh, const Time& rh) {
  	return Stiffness(lh.value() / rh.value());
  }
  double operator/ (const Stiffness& lh, const Stiffness& rh) {
    return lh.value() / rh.value();
  }

  bool operator==(const Stiffness& lh, const Stiffness& rh) {
    return fuzzy_equals(lh.value(), rh.value());
  }

  bool operator>(const Stiffness& lh, const Stiffness& rh) {
    return fuzzy_greater(lh.value(), rh.value());
  }

  bool operator!=(const Stiffness& lh, const Stiffness& rh) {
    return !(lh == rh);
  }

  bool operator<(const Stiffness& lh, const Stiffness& rh) {
    return rh > lh;
  }

  bool operator>=(const Stiffness& lh, const Stiffness& rh) {
    return lh > rh || lh == rh;
  }

  bool operator<=(const Stiffness& lh, const Stiffness& rh) {
    return rh > lh || rh == lh;
  }

  /* Literal operators
 * The following units are supported:
 * N/m, N/mm,
 * lb/in, lb/ft
 */

  Stiffness operator""_Npm(long double val) {
    return Stiffness(val);
  }

  Stiffness operator""_Npm(unsigned long long val) {
    return Stiffness(val);
  }

  Stiffness operator""_Npmm(long double val) {
    return Stiffness(val * 1000);
  }

  Stiffness operator""_Npmm(unsigned long long val) {
    return Stiffness(val * 1000);
  }

  Stiffness operator""_lbpin(long double val) {
    return Stiffness(val * 175.12683524647637795);
  }

  Stiffness operator""_lbpin(unsigned long long val) {
    return Stiffness(val * 175.12683524647637795);
  }

  Stiffness operator""_lbpft(long double val) {
    return Stiffness(val * 14.593902937206364829);
  }

  Stiffness operator""_lbpft(unsigned long long val) {
    return Stiffness(val * 14.593902937206364829);
  }

};  // namespace eng
