#include "pch.h"
#include "PhysicsMath.h"
#include "Physics.h"

#include <cmath>


namespace physics {

  // Fussy comparison operators
  bool fuzzy_equals(const double& lh, const double& rh) {
    /* Tests that the numbers differ by less than 100,000 times smaller than either of them. */
    return fabs(lh - rh) <= fabs((lh < rh ? lh : rh) * 0.000001);
  }
  bool fuzzy_greater(const double& lh, const double& rh) {
    /* Tests that lh is greater than rh by an accaptable margin of error. */
    return lh - rh > ((lh < rh ? lh : rh) * 0.000001);
  }

  bool approx(const double& lh, const double& rh) {
    /* This is a less-stringent version of fuzzy_equals, when the equality must be tested on an order of 1000. */
    return fabs(lh - rh) <= fabs((lh < rh ? lh : rh) * 0.0001);
  }

  double sin(const Angle& a) {
    return std::sin(a.rad());
  }

  double cos(const Angle& a) {
    return std::cos(a.rad());
  }

  double tan(const Angle& a) {
    return std::tan(a.rad());
  }

  Angle asin(const double& x) {
    return Angle(std::asin(x));
  }

  Angle acos(const double& x) {
    return Angle(std::acos(x));
  }

  Angle atan(const double& x) {
    return Angle(std::atan(x));
  }

  Angle atan2(const double& x, const double& y) {
    return Angle(std::atan2(x, y));
  }

  Length sqrt(const Area& r) {
    return Length(std::sqrt(r.m2()));
  }

  Area sqrt(const SecondMomentOfArea& r) {
    return Area(std::sqrt(r.m4()));
  }

  Pressure sqrt(const Pressure2& r) {
    return Pressure(std::sqrt(r.value()));
  }

  Frequency sqrt(const Frequency2& r) {
      return Frequency(std::sqrt(r.value()));
  }

  Time abs(const Time& x) {
    return Time(fabs(x.value()));
  }

  Frequency abs(const Frequency& x) {
    return Frequency(fabs(x.value()));
  }

  Mass abs(const Mass& x) {
    return Mass(fabs(x.value()));
  }

  Angle abs(const Angle& x) {
    return Angle(fabs(x.rad()));
  }

  Length abs(const Length& x) {
    return Length(fabs(x.m())); 
  }

  Area abs(const Area& x) {
    return Area(std::fabs(x.m2()));
  }

  Volume abs(const Volume& x) {
    return Volume(fabs(x.m3()));
  }

  SecondMomentOfArea abs(const SecondMomentOfArea& x) { 
    return SecondMomentOfArea(fabs(x.m4())); 
  }

  Force abs(const Force& x) {
    return Force(fabs(x.N())); 
  }

  Stiffness abs(const Stiffness& x) {
    return Stiffness(fabs(x.Npm()));
  }

  Damping abs(const Damping& x) {
      return Damping(fabs(x.value()));
  }

  Pressure abs(const Pressure& x) {
    return Pressure(fabs(x.Pa())); 
  }

  Velocity abs(const Velocity& x) {
    return Velocity(fabs(x.value()));
  }

  Acceleration abs(const Acceleration& x) {
      return Acceleration(fabs(x.value()));
  }

  Area abs2(const Length& x) {
    return x*x; 
  }

  SecondMomentOfArea abs2(const Area& x) {
    return x*x;
  }

  Pressure2 abs2(const Pressure& x) {
    return x*x; 
  }

  Frequency2 abs2(const Frequency& x) {
    return x*x;
  }

};
