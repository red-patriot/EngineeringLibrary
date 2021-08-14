#pragma once

/*****************************************************************//**
 * \file  Unitless.h
 * \brief An object representing the a UnitBase with no units.
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "UnitBase.h"

#include <eigen3/Eigen/Core>

namespace eng {

  static constexpr long double pi = 3.141592653589793238462643383279;

  /** 
   * \class Unitless
   * \addtogroup Units
   */
  template<>
  class SIUnit<0, 0, 0, 0, 0, 0, 0> {
   public:
    typedef SIUnit<0, 0, 0, 0, 0, 0, 0> this_t;
   public:
    SIUnit(const double& n = 0) : value_(n) { }
    double value() const { return value_; }

    double rad() const { return value_; }
    double deg() const { return value_ * (pi/180); }

    this_t& operator+= (const this_t& rh) { value_ += rh.value(); return *this; }
    this_t& operator-= (const this_t& rh) { value_ -= rh.value(); return *this; }
    this_t& operator*= (const double& rh) { value_ *= rh; return *this; }
    this_t& operator/= (const double& rh) { value_ /= rh; return *this; }

    operator double() { return value_; }

  protected:
    double value_;
  };

  using Unitless = SIUnit<0, 0, 0, 0, 0, 0, 0>;
  using Angle = SIUnit<0, 0, 0, 0, 0, 0, 0>;

}; // namespace eng

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<eng::Unitless> : NumTraits<double> {
    typedef eng::Unitless Real;
    typedef eng::Unitless NonInteger;
    typedef eng::Unitless Nested;

    enum {
      IsComplex = 0,
      IsInteger = 0,
      IsSigned = 1,
      RequireInitialization = 1,
      ReadCost = 1,
      AddCost = 3,
      MulCost = 3
    };
  };

};  // namespace Eigen
