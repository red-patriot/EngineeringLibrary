#pragma once

/*****************************************************************//**
 * \file  Time.h
 * \brief An object representing time. 
 *
 * 
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "SIUnit.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /**
   * \class Time 
   * \addtogroup Units
   */
  template<>
  class SIUnit<0, 0, 1, 0, 0, 0, 0> {
   public:
    typedef SIUnit<0, 0, 1, 0, 0, 0, 0> this_t;
    UnitBaseCOMMON
   public:
    double sec() const { return value_; }
    double minute() const { return value_ / 60; }
    double hour() const { return value_ / 3600; }
  };

  using Time = SIUnit<0, 0, 1, 0, 0, 0, 0>;

  Time operator"" _sec (long double val);
  Time operator"" _sec (unsigned long long val);

  Time operator"" _minute (long double val);
  Time operator"" _minute (unsigned long long val);

  Time operator"" _hour (long double val);
  Time operator"" _hour (unsigned long long val);

};  // namepsace eng

using eng::operator"" _sec;        using eng::operator"" _minute;
using eng::operator"" _hour;

