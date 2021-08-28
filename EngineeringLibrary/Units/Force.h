#pragma once

/*****************************************************************//**
 * \file  Force.h
 * \brief An object representing a force. 
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "SIUnit.h"
#include "../Vector.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /**
   * \class Force 
   * \addtogroup Units
   */
  template<>
  class SIUnit<1, 1, -2, 0, 0, 0, 0> {
    typedef SIUnit<1, 1, -2, 0, 0, 0, 0> this_t;
    UnitBaseCOMMON
  public:
    double N() const { return value_; }
    double kN() const { return value_ * 0.001; }

    double lbf() const { return value_ * 0.224808943099711; }
    double kips() const { return value_ * 0.000224808943099711;  }
  };

  using Force = SIUnit<1, 1, -2, 0, 0, 0, 0>;

  Force operator"" _N(long double val);
  Force operator"" _N(unsigned long long val);

  Force operator"" _kN(long double val);
  Force operator"" _kN(unsigned long long val);

  Force operator"" _lbf(long double val);
  Force operator"" _lbf(unsigned long long val);

  Force operator"" _kips(long double val);
  Force operator"" _kips(unsigned long long val);

  // Forces are commonly used as vectors
  using ForceVec = Vector<1, 1, -2, 0, 0, 0, 0>;
  

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
