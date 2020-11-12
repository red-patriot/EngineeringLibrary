#ifndef Velocity_h_INCLUDED
#define Velocity_h_INCLUDED

/*****************************************************************//**
 * \file  Velocity.h
 * \brief An object representing a linear velocity
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "UnitBase.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /** The speed of an object moving through space.
   * \class Velocity
   * \addtogroup Units
   */
  template<>
  class ENGINEERINGLIBRARY_API UnitBase<0, 1, -1, 0, 0, 0, 0> {
    typedef UnitBase<0, 1, -1, 0, 0, 0, 0> this_t;
    UnitBaseCOMMON
  public:
    double mpsec() const { return _value; }
    double kph() const { return _value * 3.600; }

    double inpsec() const { return _value * 39.370'007'874'015'748; }  // 100/2.54
    double ftpsec() const { return _value * 3.280'839'895'013'123; }  // 100/30.48
    double mph() const { return _value * 2.236'936'292'054'402; }  // 360'000 / 160'934.4
  };

  using Velocity = UnitBase<0, 1, -1, 0, 0, 0, 0>;

  Velocity ENGINEERINGLIBRARY_API operator"" _mpsec (long double val);
  Velocity ENGINEERINGLIBRARY_API operator"" _mpsec (unsigned long long val);

  Velocity ENGINEERINGLIBRARY_API operator"" _kph (long double val);
  Velocity ENGINEERINGLIBRARY_API operator"" _kph (unsigned long long val);

  Velocity ENGINEERINGLIBRARY_API operator"" _inpsec (long double val);
  Velocity ENGINEERINGLIBRARY_API operator"" _inpsec (unsigned long long val);

  Velocity ENGINEERINGLIBRARY_API operator"" _ftpsec (long double val);
  Velocity ENGINEERINGLIBRARY_API operator"" _ftpsec (unsigned long long val);

  Velocity ENGINEERINGLIBRARY_API operator"" _mph (long double val);
  Velocity ENGINEERINGLIBRARY_API operator"" _mph (unsigned long long val);

  inline Velocity ENGINEERINGLIBRARY_API conj(const Velocity& x) { return x; }
  inline Velocity ENGINEERINGLIBRARY_API real(const Velocity& x) { return x; }
  inline Velocity ENGINEERINGLIBRARY_API imag(const Velocity& x) { return 0_mpsec; }

};  // namespace eng

/* Integration with Eigen. */
namespace Eigen {

  template<> struct NumTraits<eng::Velocity> : NumTraits<double> {
    typedef eng::Velocity Real;
    typedef eng::Velocity NonInteger;
    typedef eng::Velocity Nested;

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

using eng::operator"" _mpsec;      using eng::operator"" _kph;
using eng::operator"" _inpsec;     using eng::operator"" _ftpsec;
using eng::operator"" _mph;

#endif
