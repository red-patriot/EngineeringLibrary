#ifndef Acceleration_h_INCLUDED
#define Acceleration_h_INCLUDED

/*****************************************************************//**
 * \file  Acceleration.h
 * \brief An object representing a linear Acceleration. 
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "UnitBase.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /** The change in speed of an object moginv through space
   * \class Acceleration 
   * \addtogroup Units
   */
  template<>
  class ENGINEERINGLIBRARY_API UnitBase<0, 1, -2, 0, 0, 0, 0> {
    typedef UnitBase<0, 1, -2, 0, 0, 0, 0> this_t;
    UnitBaseCOMMON
  public:
    double mpsec2() const { return _value; }
    
    double inpsec2() const { return _value * (100/2.54); }
    double ftpsec2() const { return _value * (100/(30.48)); }
  };

  using Acceleration = UnitBase<0, 1, -2, 0, 0, 0, 0>;

  Acceleration ENGINEERINGLIBRARY_API operator"" _mpsec2 (long double val);
  Acceleration ENGINEERINGLIBRARY_API operator"" _mpsec2 (unsigned long long val);

  Acceleration ENGINEERINGLIBRARY_API operator"" _inpsec2 (long double val);
  Acceleration ENGINEERINGLIBRARY_API operator"" _inpsec2 (unsigned long long val);

  Acceleration ENGINEERINGLIBRARY_API operator"" _ftpsec2 (long double val);
  Acceleration ENGINEERINGLIBRARY_API operator"" _ftpsec2 (unsigned long long val);

  inline Acceleration ENGINEERINGLIBRARY_API conj(const Acceleration& x) { return x; }
  inline Acceleration ENGINEERINGLIBRARY_API real(const Acceleration& x) { return x; }
  inline Acceleration ENGINEERINGLIBRARY_API imag(const Acceleration&) { return 0_mpsec2; }

};  // namespace eng

/* Integration with Eigen. */
namespace Eigen {

  template<> struct NumTraits<eng::Acceleration> : NumTraits<double> {
    typedef eng::Acceleration Real;
    typedef eng::Acceleration NonInteger;
    typedef eng::Acceleration Nested;

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

using eng::operator"" _mpsec2;
using eng::operator"" _inpsec2;      using eng::operator"" _ftpsec2;

#endif
