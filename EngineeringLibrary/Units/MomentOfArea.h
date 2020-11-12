#ifndef Moment_Of_Inertia_h_INCLUDED
#define Moment_Of_Inertia_h_INCLUDED

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
  class ENGINEERINGLIBRARY_API UnitBase<0, 4, 0, 0, 0, 0, 0> {
    typedef UnitBase<0, 4, 0, 0, 0, 0, 0> this_t;
    UnitBaseCOMMON
  public:
    double mm4() const { return _value * 1'000'000'000'000; }
    double m4() const { return _value; }

    double in4() const { return _value * 100'000'000 / 41.623'142'56; }
    double ft4() const { return _value * 100'000'000 / 863'097.481'241'6; }
  };

  using SecondMomentOfArea = UnitBase<0, 4, 0, 0, 0, 0, 0>;

  // Literal operators
  SecondMomentOfArea ENGINEERINGLIBRARY_API operator"" _mm4(long double val);
  SecondMomentOfArea ENGINEERINGLIBRARY_API operator"" _mm4(unsigned long long val);

  SecondMomentOfArea ENGINEERINGLIBRARY_API operator"" _m4(long double val);
  SecondMomentOfArea ENGINEERINGLIBRARY_API operator"" _m4(unsigned long long val);

  SecondMomentOfArea ENGINEERINGLIBRARY_API operator"" _in4(long double val);
  SecondMomentOfArea ENGINEERINGLIBRARY_API operator"" _in4(unsigned long long val);

  SecondMomentOfArea ENGINEERINGLIBRARY_API operator"" _ft4(long double val);
  SecondMomentOfArea ENGINEERINGLIBRARY_API operator"" _ft4(unsigned long long val);

  inline SecondMomentOfArea ENGINEERINGLIBRARY_API conj(const SecondMomentOfArea& x) { return x; }
  inline SecondMomentOfArea ENGINEERINGLIBRARY_API real(const SecondMomentOfArea& x) { return x; }
  inline SecondMomentOfArea ENGINEERINGLIBRARY_API imag(const SecondMomentOfArea&) { return 0_m4; }

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

#endif
