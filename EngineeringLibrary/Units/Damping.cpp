#include "pch.h"

#include "Time.h"
#include "Frequency.h"
#include "Mass.h"
#include "Damping.h"
#include "Stiffness.h"
#include "PhysicsMath.h"

namespace physics {

  Damping operator- (const Damping& lh) {
    return Damping(-lh.value());
  }

  Damping operator+ (const Damping& lh, const Damping& rh) {
  	return Damping(lh.value() + rh.value());
  }

  Damping operator- (const Damping& lh, const Damping& rh) {
  	return Damping(lh.value() - rh.value());
  }

  Damping operator* (const Damping& lh, const double& rh) {
  	return Damping(lh.value() * rh);
  }
  Damping operator* (const double& lh, const Damping& rh) {
  	return Damping(lh * rh.value());
  }
  Damping operator* (const Stiffness& lh, const Time& rh) {
  	return Damping(lh.value() * rh.value());
  }
  Damping operator* (const Time& lh, const Stiffness& rh) {
  	return Damping(lh.value() * rh.value());
  }
  Damping operator* (const Mass& lh, const Frequency& rh) {
  	return Damping(lh.value() * rh.value());
  }
  Damping operator* (const Frequency& lh, const Mass& rh) {
  	return Damping(lh.value() * rh.value());
  }
    
  Damping operator/ (const Damping& lh, const double& rh) {
  	return Damping(lh.value() / rh);
  }
  double operator/ (const Damping& lh, const Damping& rh) {
  	return double(lh.value() / rh.value());
  }

  bool operator== (const Damping& lh, const Damping& rh) {
    return fuzzy_equals(lh.value(), rh.value());
  }
  bool operator> (const Damping& lh, const Damping& rh) {
    return fuzzy_greater(lh.value(), rh.value());
  }

  bool operator!= (const Damping& lh, const Damping& rh) {
    return !(lh == rh);
  }
  bool operator< (const Damping& lh, const Damping& rh) {
    return rh > lh;
  }
  bool operator>= (const Damping& lh, const Damping& rh) {
    return lh > rh || lh == rh;
  }
  bool operator<= (const Damping& lh, const Damping& rh) {
    return rh > lh || lh == rh;
  }

  /* Literal operators
   * The following units are supported:
   * Ns / m, kNs / m,
   * lbs/ in, lbs / ft
   */

  Damping operator"" _Nspm (long double val) {
    return Damping(val);
  }
  Damping operator"" _Nspm (unsigned long long val) {
    return Damping(val);
  }

  Damping operator"" _kNspm (long double val) {
    return Damping(val);
  }
  Damping operator"" _kNspm (unsigned long long val) {
    return Damping(val);
  }

  Damping operator"" _lbspin (long double val) {
    return Damping(val);
  }
  Damping operator"" _lbspin (unsigned long long val) {
    return Damping(val);
  }

  Damping operator"" _lbspft (long double val) {
    return Damping(val);
  }
  Damping operator"" _lbspft (unsigned long long val) {
    return Damping(val);
  }

};  // namespace physics
