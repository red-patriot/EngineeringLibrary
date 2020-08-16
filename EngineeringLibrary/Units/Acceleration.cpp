#include "pch.h"

#include "Acceleration.h"
#include "Velocity.h"
#include "Time.h"
#include "Mass.h"
#include "Force.h"
#include "PhysicsMath.h"

namespace physics {

  Acceleration operator- (const Acceleration& lh) {
    return Acceleration(-lh.value());
  }

  Acceleration operator+ (const Acceleration& lh, const Acceleration& rh) {
  	return Acceleration(lh.value() + rh.value());
  }
    
  Acceleration operator- (const Acceleration& lh, const Acceleration& rh) {
  	return Acceleration(lh.value() - rh.value());
  }

  Acceleration operator* (const Acceleration& lh, const double& rh) {
  	return Acceleration(lh.value() * rh);
  }
  Acceleration operator* (const double& lh, const Acceleration& rh) {
  	return Acceleration(lh * rh.value());
  }

  Acceleration operator/ (const Acceleration& lh, const double& rh) {
  	return Acceleration(lh.value() / rh);
  }
  double operator/ (const Acceleration& lh, const Acceleration& rh) {
  	return double(lh.value() / rh.value());
  }
  Acceleration operator/ (const Velocity& lh, const Time& rh) {
  	return Acceleration(lh.value() / rh.value());
  }
  Acceleration operator/ (const Force& lh, const Mass& rh) {
  	return Acceleration(lh.value() / rh.value());
  }

  bool operator== (const Acceleration& lh, const Acceleration& rh) {
    return fuzzy_equals(lh.value(), rh.value());
  }
  bool operator> (const Acceleration& lh, const Acceleration& rh) {
    return fuzzy_greater(lh.value(), rh.value());
  }

  bool operator!= (const Acceleration& lh, const Acceleration& rh) {
    return !(lh == rh);
  }
  bool operator< (const Acceleration& lh, const Acceleration& rh) {
    return rh > lh;
  }
  bool operator>= (const Acceleration& lh, const Acceleration& rh) {
    return lh > rh || lh == rh;
  }
  bool operator<= (const Acceleration& lh, const Acceleration& rh) {
    return rh > lh || lh == rh;
  }

  /* Literal operators
   * The following units are supported:
   * m / s^2, 
   * in / s^2, ft / s^2
   */

  Acceleration operator"" _mpsec2 (long double val) {
    return Acceleration(val);
  }
  Acceleration operator"" _mpsec2 (unsigned long long val) {
    return Acceleration(val);
  }

  Acceleration operator"" _inpsec2 (long double val) {
    return Acceleration(val);
  }
  Acceleration operator"" _inpsec2 (unsigned long long val) {
    return Acceleration(val);
  }

  Acceleration operator"" _ftpsec2 (long double val) {
    return Acceleration(val);
  }
  Acceleration operator"" _ftpsec2 (unsigned long long val) {
    return Acceleration(val);
  }

};
