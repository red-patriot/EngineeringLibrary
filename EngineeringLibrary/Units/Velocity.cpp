#include "pch.h"

#include "Force.h"
#include "Damping.h"
#include "Velocity.h"
#include "Acceleration.h"
#include "Time.h"
#include "Length.h"
#include "PhysicsMath.h"


namespace physics {

  Velocity operator- (const Velocity& lh) {
    return Velocity(-lh.value());
  }

  Velocity operator+ (const Velocity& lh, const Velocity& rh) {
	  return Velocity(lh.value() + rh.value());
  }

  Velocity operator- (const Velocity& lh, const Velocity& rh) {
	  return Velocity(lh.value() - rh.value());
  }

  Velocity operator* (const Velocity& lh, const double& rh) {
	  return Velocity(lh.value() * rh);
  }
  Velocity operator* (const double& lh, const Velocity& rh) {
	  return Velocity(lh * rh.value());
  }
  Velocity operator* (const Acceleration& lh, const Time& rh) {
  	return Velocity(lh.value() * rh.value());
  }
  Velocity operator* (const Time& lh, const Acceleration& rh) {
  	return Velocity(lh.value() * rh.value());
  }

  Velocity operator/ (const Velocity& lh, const double& rh) {
	  return Velocity(lh.value() / rh);
  }
  Velocity operator/ (const Length& lh, const Time& rh) {
  	return Velocity(lh.value() / rh.value());
  }
  double operator/ (const Velocity& lh, const Velocity& rh) {
  	return lh.value() / rh.value();
  }
  Velocity operator/ (const Force& lh, const Damping& rh) {
  	return Velocity(lh.value() / rh.value());
  }

  bool operator== (const Velocity& lh, const Velocity& rh) {
    return fuzzy_equals(lh.value(), rh.value());
  }
  bool operator> (const Velocity& lh, const Velocity& rh) {
    return fuzzy_greater(lh.value(), rh.value());
  }

  bool operator!= (const Velocity& lh, const Velocity& rh) {
    return !(lh == rh);
  }
  bool operator< (const Velocity& lh, const Velocity& rh) {
    return rh > lh;
  }
  bool operator>= (const Velocity& lh, const Velocity& rh) {
    return lh > rh || lh == rh;
  }
  bool operator<= (const Velocity& lh, const Velocity& rh) {
    return rh > lh || lh == rh;
  }

  /* Literal operators
 * The following units are supported:
 * m/s, kph,
 * in/s, ft/s, mph
 */

  Velocity operator"" _mpsec (long double val) {
    return Velocity(val);
  }
  Velocity operator"" _mpsec (unsigned long long val) {
    return Velocity(val);
  }

  Velocity operator"" _kph (long double val) {
    return Velocity(val);
  }
  Velocity operator"" _kph (unsigned long long val) {
    return Velocity(val);
  }

  Velocity operator"" _inpsec (long double val) {
    return Velocity(val);
  }
  Velocity operator"" _inpsec (unsigned long long val) {
    return Velocity(val);
  }

  Velocity operator"" _ftpsec (long double val) {
    return Velocity(val);
  }
  Velocity operator"" _ftpsec (unsigned long long val) {
    return Velocity(val);
  }

  Velocity operator"" _mph (long double val) {
    return Velocity(val);
  }
  Velocity operator"" _mph (unsigned long long val) {
    return Velocity(val);
  }

};  // namespace physics
