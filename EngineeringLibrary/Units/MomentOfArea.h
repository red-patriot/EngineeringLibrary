#pragma once

/*****************************************************************//**
 * \file  MomentOfArea.h
 * \brief Objects representing a First- or Second moment of area
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "UnitBase.h"
#include "Volume.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /** First moment of Area and Volume have the same units and functionality
   * \typedef FirstMomentOfArea Volume
   * \see Volume
   * \addtogroup Units
   */
  using FirstMomentOfArea = Volume;

  /** A 4D measure of the Area Moment of Inertia of a geometry
   * \class SecondMomentOfArea 
   * \addtogroup Units
   */
  template<>
  class SIUnit<0, 4, 0, 0, 0, 0, 0> {
    typedef SIUnit<0, 4, 0, 0, 0, 0, 0> this_t;
    UnitBaseCOMMON
  public:
    double mm4() const { return value_ * 1'000'000'000'000; }
    double m4() const { return value_; }

    double in4() const { return value_ * 100'000'000 / 41.623'142'56; }
    double ft4() const { return value_ * 100'000'000 / 863'097.481'241'6; }
  };

  using SecondMomentOfArea = SIUnit<0, 4, 0, 0, 0, 0, 0>;

  // Literal operators
  SecondMomentOfArea operator"" _mm4(long double val);
  SecondMomentOfArea operator"" _mm4(unsigned long long val);

  SecondMomentOfArea operator"" _m4(long double val);
  SecondMomentOfArea operator"" _m4(unsigned long long val);

  SecondMomentOfArea operator"" _in4(long double val);
  SecondMomentOfArea operator"" _in4(unsigned long long val);

  SecondMomentOfArea operator"" _ft4(long double val);
  SecondMomentOfArea operator"" _ft4(unsigned long long val);

  inline SecondMomentOfArea conj(const SecondMomentOfArea& x) { return x; }
  inline SecondMomentOfArea real(const SecondMomentOfArea& x) { return x; }
  inline SecondMomentOfArea imag(const SecondMomentOfArea&) { return 0_m4; }

}; // namespace eng

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<eng::SecondMomentOfArea> : NumTraits<double> {
    typedef eng::SecondMomentOfArea Real;
    typedef eng::SecondMomentOfArea NonInteger;
    typedef eng::SecondMomentOfArea Nested;

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

using eng::operator"" _mm4;         using eng::operator"" _m4;
using eng::operator"" _in4;         using eng::operator"" _ft4;

