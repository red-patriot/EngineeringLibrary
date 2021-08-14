#pragma once

/*****************************************************************//**
 * \file  Damping.h
 * \brief An object representing a Damping component. 
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "UnitBase.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /**
   * \class Damping
   * \addtogroup Units
   */
  template<>
  class SIUnit<1, 0, -1, 0, 0, 0, 0> {
   public:
    typedef SIUnit<1, 0, -1, 0, 0, 0, 0> this_t;
    UnitBaseCOMMON
   public:
    double Nspm() const { return value_; }
    double kNspm() const { return value_ / 1000; }

    double lbspin() const { return value_ * .0254/4.4482216152605; }
    double lbspft() const { return value_ * .3048/4.4482216152605; }
  };

  using Damping = SIUnit<1, 0, -1, 0, 0, 0, 0>;

  // Literal operators
  Damping operator"" _Nspm (long double val);
  Damping operator"" _Nspm (unsigned long long val);

  Damping operator"" _kNspm (long double val);
  Damping operator"" _kNspm (unsigned long long val);

  Damping operator"" _lbspin (long double val);
  Damping operator"" _lbspin (unsigned long long val);

  Damping operator"" _lbspft (long double val);
  Damping operator"" _lbspft (unsigned long long val);

};  // namespace eng

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<eng::Damping> : NumTraits<double> {
    typedef eng::Damping Real;
    typedef eng::Damping NonInteger;
    typedef eng::Damping Nested;

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

using eng::operator"" _Nspm;        using eng::operator"" _kNspm;
using eng::operator"" _lbspin;      using eng::operator"" _lbspft;
