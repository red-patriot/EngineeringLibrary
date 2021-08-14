#pragma once

/*****************************************************************//**
 * \file  Stiffness.h
 * \brief An object representing a linear stiffness
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "UnitBase.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /** A linear resistance to deformation measured in force/length
   * \class Stiffness 
   * \addtogroup Units
   */
  template<>
  class SIUnit<1, 0, -2, 0, 0, 0, 0> {
    typedef SIUnit<1, 0, -2, 0, 0, 0, 0> this_t;
    UnitBaseCOMMON
  public:
    double Npm() const { return value_; }
    double Npmm() const { return value_ * 0.001; }
    
    double lbpin() const { return value_ * 0.005'710'147'154'732'646'26; }
    double lbpft() const { return value_ * 0.068'521'765'856'791'755'19; }
  };

  using Stiffness = SIUnit<1, 0, -2, 0, 0, 0, 0>;

  Stiffness operator"" _Npm(long double val);
  Stiffness operator"" _Npm(unsigned long long val);

  Stiffness operator"" _Npmm(long double val);
  Stiffness operator"" _Npmm(unsigned long long val);

  Stiffness operator"" _lbpin(long double val);
  Stiffness operator"" _lbpin(unsigned long long val);

  Stiffness operator"" _lbpft(long double val);
  Stiffness operator"" _lbpft(unsigned long long val);

  inline Stiffness conj(const Stiffness& x) { return x; }
  inline Stiffness real(const Stiffness& x) { return x; }
  inline Stiffness imag(const Stiffness&) { return 0_Npm; }
  

}; // namespace eng

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<eng::Stiffness> : NumTraits<double> {
    typedef eng::Stiffness Real;
    typedef eng::Stiffness NonInteger;
    typedef eng::Stiffness Nested;

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

using eng::operator"" _Npm;       using eng::operator"" _Npmm;
using eng::operator"" _lbpin;     using eng::operator"" _lbpft;

