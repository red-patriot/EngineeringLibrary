#include "pch.h"

#include "PhysicsMath.h"
#include "Energy.h"
#include "Force.h"
#include "Length.h"

namespace eng {

  Energy operator- (const Energy& lh) {
    return Energy(-lh.value());
  }

  Energy operator+ (const Energy& lh, const Energy& rh) {
  	return Energy(lh.value() + rh.value());
  }

  Energy operator- (const Energy& lh, const Energy& rh) {
  	return Energy(lh.value() - rh.value());
  }

  Energy operator* (const Force& lh, const Length& rh) {
  	return Energy(lh.value() * rh.value());
  }
  Energy operator* (const Length& lh, const Force& rh) {
  	return Energy(lh.value() * rh.value());
  }
  Energy operator* (const Energy& lh, const double& rh) {
  	return Energy(lh.value() * rh);
  }
  Energy operator* (const double& lh, const Energy& rh) {
  	return Energy(lh * rh.value());
  }

  Energy operator/ (const Energy& lh, const double& rh) {
  	return Energy(lh.value() / rh);
  }
  double operator/ (const Energy& lh, const Energy& rh) {
  	return double(lh.value() / rh.value());
  }

  bool  operator== (const Energy& lh, const Energy& rh) {
    return fuzzy_equals(lh.value(), rh.value());
  }
  bool  operator> (const Energy& lh, const Energy& rh) {
    return fuzzy_greater(lh.value(), rh.value());
  }
  bool  operator!= (const Energy& lh, const Energy& rh) {
    return !(lh == rh);
  }
  bool  operator< (const Energy& lh, const Energy& rh) {
    return rh > lh;
  }
  bool  operator>= (const Energy& lh, const Energy& rh) {
    return lh > rh || lh == rh;
  }
  bool  operator<= (const Energy& lh, const Energy& rh) {
    return rh > lh || lh == rh;
  }

  /* Literal operators
   * The following units are suported:
   * J, kJ, MJ,
   * ft*lb, in*lb, BTU
   */

  Energy operator"" _J (long double val) {
    return Energy(val);
  }
  Energy operator"" _J (unsigned long long val) {
    return Energy(val);
  }

  Energy operator"" _kJ (long double val) {
    return Energy(val * 1000.0);
  }
  Energy operator"" _kJ (unsigned long long val) {
    return Energy(val * 1000.0);
  }

  Energy operator"" _MJ (long double val) {
    return Energy(val * 1'000'000.0);
  }
  Energy operator"" _MJ (unsigned long long val) {
    return Energy(val * 1'000'000.0);
  }

  Energy operator"" _ftlb (long double val) {
    return Energy(val * 1.3558179483314);
  }
  Energy operator"" _ftlb (unsigned long long val) {
    return Energy(val * 1.3558179483314);
  }

  Energy operator"" _inlb (long double val) {
    return Energy(val * 0.11298482902413);
  }
  Energy operator"" _inlb (unsigned long long val) {
    return Energy(val * 0.11298482902413);
  }

  Energy operator"" _BTU (long double val) {
    return Energy(val * 1055.87);
  }
  Energy operator"" _BTU (unsigned long long val) {
    return Energy(val * 1055.87);
  }
};
