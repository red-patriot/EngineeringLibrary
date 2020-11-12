#ifndef Force_h_INCLUDED
#define Force_h_INCLUDED

/*****************************************************************//**
 * \file  Force.h
 * \brief An object representing a force. 
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "UnitBase.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /** The magnitude of a force in space
   * \class Force 
   * \addtogroup Units
   */
  template<>
  class ENGINEERINGLIBRARY_API UnitBase<1, 1, -2, 0, 0, 0, 0> {
    typedef UnitBase<1, 1, -2, 0, 0, 0, 0> this_t;
    UnitBaseCOMMON
  public:
    double N() const { return _value; }
    double kN() const { return _value * 0.001; }

    double lbf() const { return _value * 0.224808943099711; }
    double kips() const { return _value * 0.000224808943099711;  }
  };

  using Force = UnitBase<1, 1, -2, 0, 0, 0, 0>;

  Force ENGINEERINGLIBRARY_API operator"" _N(long double val);
  Force ENGINEERINGLIBRARY_API operator"" _N(unsigned long long val);

  Force ENGINEERINGLIBRARY_API operator"" _kN(long double val);
  Force ENGINEERINGLIBRARY_API operator"" _kN(unsigned long long val);

  Force ENGINEERINGLIBRARY_API operator"" _lbf(long double val);
  Force ENGINEERINGLIBRARY_API operator"" _lbf(unsigned long long val);

  Force ENGINEERINGLIBRARY_API operator"" _kips(long double val);
  Force ENGINEERINGLIBRARY_API operator"" _kips(unsigned long long val);

  inline Force ENGINEERINGLIBRARY_API conj(const Force& x) { return x; }
  inline Force ENGINEERINGLIBRARY_API real(const Force& x) { return x; }
  inline Force ENGINEERINGLIBRARY_API imag(const Force&) { return 0_N; }

  // Forces are commonly used as vectors, so provide some vectors for convenience
  using Force2d = Eigen::Matrix<Force, 1, 2>;
  using Force3d = Eigen::Matrix<Force, 1, 3>;
  

}; // namespace eng

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<eng::Force> : NumTraits<double> {
    typedef eng::Force Real;
    typedef eng::Force NonInteger;
    typedef eng::Force Nested;

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

using eng::operator""_N;        using eng::operator""_kN;
using eng::operator""_lbf;      using eng::operator""_kips;

#endif

