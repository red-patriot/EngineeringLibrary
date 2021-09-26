#pragma once

/*****************************************************************/ /**
 * \file   Power.h
 * \brief  
 * 
 * \date 2021
 *********************************************************************/

#include "SIUnit.h"

namespace eng {

  template <>
  class SIUnit<1, 2, -3, 0, 0, 0, 0> {
   public:
    typedef SIUnit<1, 2, -3, 0, 0, 0, 0> this_t;
    UnitBaseCOMMON 
   public: 
    double mW() const { return 1000.0 * value_; }
    double W() const { return value_; }
    double kW() const { return 0.001 * value_; }
    double MW() const { return 0.000'001 * value_; }

    /** Imperial (Mechanical) horsepower */
    double hp() const { return 0.001'341'022'1 * value_; }
    /** Metric horsepower */
    double hp_M() const { return 0.001'341'022'896 * value_; }
    /** Electric horsepower */
    double hp_E() const { return 0.001'340'482'574 * value_; }
    double TR() const { return 0.000'284'345'1 * value_; }

  };

  using Power = SIUnit<1, 2, -3, 0, 0, 0, 0>;

  Power operator"" _mW(long double val);
  Power operator""_mW(unsigned long long val);

  Power operator""_W(long double val);
  Power operator""_W(unsigned long long val);

  Power operator""_kW(long double val);
  Power operator""_kW(unsigned long long val);

  Power operator""_MW(long double val);
  Power operator""_MW(unsigned long long val);

  /** Imperial (Mechanical) horsepower */
  Power operator""_hp(long double val);
  /** Imperial (Mechanical) horsepower */
  Power operator""_hp(unsigned long long val);

  /** Metric horsepower */
  Power operator""_hp_M(long double val);
  /** Metric horsepower */
  Power operator""_hp_M(unsigned long long val);

  /** Electric horsepower */
  Power operator""_hp_E(long double val);
  /** Electric horsepower */
  Power operator""_hp_E(unsigned long long val);

  Power operator""_TR(long double val);
  Power operator""_TR(unsigned long long val);

};  // namespace eng

using eng::operator"" _mW;        using eng::operator"" _W;
using eng::operator"" _kW;        using eng::operator"" _MW;
using eng::operator"" _hp;        using eng::operator"" _TR;
