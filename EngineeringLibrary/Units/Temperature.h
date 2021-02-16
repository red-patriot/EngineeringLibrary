#pragma once

/*****************************************************************//**
 * \file   Temperature.h
 * \brief  
 * 
 * \author bltan
 * \date   November 2020
 *********************************************************************/

#include "UnitBase.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /** A Temperature
   * \class Temperature
   * \addtogroup Units
   */
  template<>
  class UnitBase<0, 0, 0, 0, 1, 0, 0> {
    typedef UnitBase<0, 0, 0, 0, 1, 0, 0> this_t;
    UnitBaseCOMMON
  public:
    double Kelvin() { return mValue; }
    double deg_C() { return mValue - 273.15; }

    double Rankine() { return mValue * (9.0/5.0); }
    double deg_F() { return mValue * 9.0/5.0 - 459.67; }
  };

  using Temperature = UnitBase<0, 0, 0, 0, 1, 0, 0>;

  Temperature operator"" _Kelvin(long double val);
  Temperature operator"" _Kelvin(unsigned long long val);

  Temperature operator"" _Rankine(long double val);
  Temperature operator"" _Rankine(unsigned long long val);

  Temperature Celcius(const double deg_C);
  Temperature Farenheit(const double deg_F);

};  // namespace eng

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<eng::Temperature> : NumTraits<double> {
    typedef eng::Temperature Real;
    typedef eng::Temperature NonInteger;
    typedef eng::Temperature Nested;

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

using eng::operator"" _Kelvin;
using eng::operator"" _Rankine;

