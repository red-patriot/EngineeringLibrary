#pragma once

/*****************************************************************//**
 * \file  Mass.h
 * \brief An object representing an inertial or gravitational mass. 
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "UnitBase.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /** A mass
   * \class Mass
   * \addtogroup Units
   */
  template<>
  class UnitBase<1, 0, 0, 0, 0, 0, 0> {
    typedef UnitBase<1, 0, 0, 0, 0, 0, 0> this_t;
    UnitBaseCOMMON
  public:
    double g() const { return mValue * 1000; }
    double kg() const { return mValue; }

    double slug() const { return mValue * 0.06852176556196105; }
  };

  using Mass = UnitBase<1, 0, 0, 0, 0, 0, 0>;

  Mass operator"" _g (long double val);
  Mass operator"" _g (unsigned long long val);

  Mass operator"" _kg (long double val);
  Mass operator"" _kg (unsigned long long val);

  Mass operator"" _slug (long double val);
  Mass operator"" _slug (unsigned long long val);

  inline Mass conj(const Mass& x) { return x; }
  inline Mass real(const Mass& x) { return x; }
  inline Mass imag(const Mass& x) { return 0_kg; }

};  // namespace eng

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<eng::Mass> : NumTraits<double> {
    typedef eng::Mass Real;
    typedef eng::Mass NonInteger;
    typedef eng::Mass Nested;

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

using eng::operator"" _g;       using eng::operator"" _kg;
using eng::operator"" _slug;
