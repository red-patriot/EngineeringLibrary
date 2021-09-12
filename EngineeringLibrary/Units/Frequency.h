#pragma once

/*****************************************************************//**
 * \file  Frequency.h
 * \brief An object representing an oscillatory frequency
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "SIUnit.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /**
   * \class Frequency
   * \addtogroup Units
   */
  template<>
  class SIUnit<0, 0, -1, 0, 0, 0, 0> {
   public:
    typedef SIUnit<0, 0, -1, 0, 0, 0, 0> this_t;
    UnitBaseCOMMON
   public:
    double Hz() const { return value_; }
    double kHz() const { return value_ * 0.001; }
    double MHz() const { return value_ * 0.000'001; }
  };

  using Frequency = SIUnit<0, 0, -1, 0, 0, 0, 0>;

  Frequency operator"" _Hz (long double val);
  Frequency operator"" _Hz (unsigned long long val);

  Frequency operator"" _kHz (long double val);
  Frequency operator"" _kHz (unsigned long long val);

  Frequency operator"" _MHz (long double val);
  Frequency operator"" _MHz (unsigned long long val);

};  // namespace eng
using eng::operator"" _Hz;        using eng::operator"" _kHz;
using eng::operator"" _MHz;

