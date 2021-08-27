#pragma once

/*****************************************************************/ /**
 * \file   Resistance.h
 * \brief  A representation of electrical Resistance
 * 
 * \date 2021
 *********************************************************************/

#include "UnitBase.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /**
   * \class Resistance
   * \addtogroup Units
   */
  template<>
  class SIUnit<1, 2, -3, -2, 0, 0, 0> {
   public:
    typedef SIUnit<1, 2, -3, -2, 0, 0, 0> this_t;
    UnitBaseCOMMON 
   public: 
    double Ohm() const { return value_; }
    double kOhm() const { return value_ * 0.001; }
    double MOhm() const { return value_ * 0.000'001; }
  };

  using Resistance = SIUnit<1, 2, -3, -2, 0, 0, 0>;

  Resistance operator"" _Ohm(long double val);
  Resistance operator"" _Ohm(unsigned long long val);

  Resistance operator"" _kOhm(long double val);
  Resistance operator"" _kOhm(unsigned long long val);

  Resistance operator"" _MOhm(long double val);
  Resistance operator"" _KOhm(unsigned long long val);

};  // namespace eng

/* Integration with Eigen. */
namespace Eigen {

  template <>
  struct NumTraits<eng::Resistance> : NumTraits<double> {
    typedef eng::Resistance Real;
    typedef eng::Resistance NonInteger;
    typedef eng::Resistance Nested;

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

using eng::operator"" _Ohm;      using eng::operator"" _kOhm;
using eng::operator"" _MOhm;
