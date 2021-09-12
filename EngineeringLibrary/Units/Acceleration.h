#pragma once

/*****************************************************************//**
 * \file  Acceleration.h
 * \brief An object representing a linear Acceleration. 
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "SIUnit.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /**
   * \class Acceleration 
   * \addtogroup Units
   */
  template<>
  class SIUnit<0, 1, -2, 0, 0, 0, 0> {
   public:
    typedef SIUnit<0, 1, -2, 0, 0, 0, 0> this_t;
    UnitBaseCOMMON
   public:
    double mpsec2() const { return value_; }
    
    double inpsec2() const { return value_ * (100/2.54); }
    double ftpsec2() const { return value_ * (100/(30.48)); }
  };

  using Acceleration = SIUnit<0, 1, -2, 0, 0, 0, 0>;

  Acceleration operator"" _mpsec2 (long double val);
  Acceleration operator"" _mpsec2 (unsigned long long val);

  Acceleration operator"" _inpsec2 (long double val);
  Acceleration operator"" _inpsec2 (unsigned long long val);

  Acceleration operator"" _ftpsec2 (long double val);
  Acceleration operator"" _ftpsec2 (unsigned long long val);

};  // namespace eng

using eng::operator"" _mpsec2;
using eng::operator"" _inpsec2;      using eng::operator"" _ftpsec2;
