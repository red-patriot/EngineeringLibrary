#ifndef Angle_h_INCLUDED
#define Angle_h_INCLUDED

/*****************************************************************//**
 * \file  Angle.h
 * \brief An object representing the angle between two noncolinear lines. 
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "UnitBase.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /** The geometry formed by two non-colinear, coplanar lines. 
   * \class Angle 
   * \addtogroup Units
   */
  template<>
  class UnitBase<0, 0, 0, 0, 0, 0, 0> {
    typedef UnitBase<0, 0, 0, 0, 0, 0, 0> this_t;
    UnitBaseCOMMON
  public:
    static constexpr long double pi = 3.141592653589793238462643383279;

    double rad() const { return _value; }
    double deg() const { return _value * (pi/180); }

    explicit operator double() { return _value; }
  };

  using Angle = UnitBase<0, 0, 0, 0, 0, 0, 0>;

  Angle operator"" _deg(long double val);
  Angle operator"" _deg(unsigned long long val);

  Angle operator"" _rad(long double val);
  Angle operator"" _rad(unsigned long long val);

  double sin(const Angle& a);
  double cos(const Angle& a);
  double tan(const Angle& a);

  Angle asin(const double& x);
  Angle acos(const double& x);
  Angle atan(const double& x);
  Angle atan2(const double& x, const double& y);

}; // namespace eng

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<eng::Angle> : NumTraits<double> {
    typedef eng::Angle Real;
    typedef eng::Angle NonInteger;
    typedef eng::Angle Nested;

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

using eng::operator"" _rad;        using eng::operator"" _deg;

#endif
