#include "pch.h"

#include "Time.h"
#include "PhysicsMath.h"

namespace physics {

  Time operator- (const Time& lh) {
    return Time(-lh.value());
  }

  Time operator+ (const Time& lh, const Time& rh) {
	  return Time(lh.value() + rh.value());
  }

  Time operator- (const Time& lh, const Time& rh) {
	  return Time(lh.value() - rh.value());
  }

  Time operator* (const Time& lh, const double& rh) {
	  return Time(lh.value() * rh);
  }
  Time operator* (const double& lh, const Time& rh) {
	  return Time(lh * rh.value());
  }

  Time operator/ (const Time& lh, const double& rh) {
	  return Time(lh.value() / rh);
  }

  // Comparison operators
  bool operator== (const Time& lh, const Time& rh) {
    return fuzzy_equals(lh.value(), rh.value());
  }
  bool operator> (const Time& lh, const Time& rh) {
    return fuzzy_greater(lh.value(), rh.value());
  }
  bool operator!= (const Time& lh, const Time& rh) {
    return !(lh == rh);
  }
  bool operator< (const Time& lh, const Time& rh) {
    return rh > lh;
  }
  bool operator>= (const Time& lh, const Time& rh) {
    return lh > rh || lh == rh;
  }
  bool operator<= (const Time& lh, const Time& rh) {
    return rh > lh || lh == rh;
  }

  /* Literal operators
  * The following units are supported:
  * sec, minute, hour
  */

  Time operator"" _sec (long double val) {
    return Time(val);
  }
  Time operator"" _sec (unsigned long long val) {
    return Time(val);
  }

  Time operator"" _minute (long double val) {
    return Time(val * 60);
  }
  Time operator"" _minute (unsigned long long val) {
    return Time(val * 60);
  }

  Time operator"" _hour (long double val) {
    return Time(val * 3600);
  }
  Time operator"" _hour (unsigned long long val) {
    return Time(val * 3600);
  }

};  // namespace physics
