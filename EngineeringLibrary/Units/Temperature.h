#pragma once

/*****************************************************************//**
 * \file   Temperature.h
 * \brief  
 * 
 * \author bltan
 * \date   November 2020
 *********************************************************************/

#include "SIUnit.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /**
   * \class Temperature
   * \addtogroup Units
   */
  template<>
  class SIUnit<0, 0, 0, 0, 1, 0, 0> {
   public:
    typedef SIUnit<0, 0, 0, 0, 1, 0, 0> this_t;
    UnitBaseCOMMON
   public:
    double Kelvin() { return value_; }
    double deg_C() { return value_ - 273.15; }

    double Rankine() { return value_ * (9.0/5.0); }
    double deg_F() { return value_ * 9.0/5.0 - 459.67; }
  };

  using Temperature = SIUnit<0, 0, 0, 0, 1, 0, 0>;

  Temperature operator"" _Kelvin(long double val);
  Temperature operator"" _Kelvin(unsigned long long val);

  Temperature operator"" _Rankine(long double val);
  Temperature operator"" _Rankine(unsigned long long val);

  Temperature Celcius(const double deg_C);
  Temperature Farenheit(const double deg_F);

};  // namespace eng

using eng::operator"" _Kelvin;
using eng::operator"" _Rankine;

