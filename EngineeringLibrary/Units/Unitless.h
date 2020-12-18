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

  /** A class to manage unitless Units
   * \class Unitless
   * \addtogroup Units
   */
  template<>
  class UnitBase<0, 0, 0, 0, 0, 0, 0> {
    typedef UnitBase<0, 0, 0, 0, 0, 0, 0> this_t;
  public:
    UnitBase(const double& n = 0) : _value(n) { }
    double value() const { return _value; }

    double rad() const { return _value; }
    double deg() const { return _value * (pi/180); }

    this_t& operator+= (const this_t& rh) { _value += rh.value(); return *this; }
    this_t& operator-= (const this_t& rh) { _value -= rh.value(); return *this; }
    this_t& operator*= (const double& rh) { _value *= rh; return *this; }
    this_t& operator/= (const double& rh) { _value /= rh; return *this; }

    operator double() { return _value; }

  protected:
    double _value;
  };

  using Unitless = UnitBase<0, 0, 0, 0, 0, 0, 0>;
  using Angle = UnitBase<0, 0, 0, 0, 0, 0, 0>;

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
