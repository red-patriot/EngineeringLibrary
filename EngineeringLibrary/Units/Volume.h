#pragma once

/*****************************************************************//**
 * \file  Volume.h
 * \brief An object representing a 3D spacial volume
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "SIUnit.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /**
   * \class Volume
   * \addtogroup Units
   */
  template<>
  class SIUnit<0, 3, 0, 0, 0, 0, 0> {
   public:
    typedef SIUnit<0, 3, 0, 0, 0, 0, 0> this_t; 
      UnitBaseCOMMON
   public:
    double mm3() const { return value_ * 1'000'000'000; }
    double cm3() const { return value_ * 1'000'000; }
    double m3() const { return value_; }

    double in3() const { return value_ * (1'000'000/16.387'064); }
    double ft3() const { return value_ * (1'000'000/28'316.846'592); }
  };

  using Volume = SIUnit<0, 3, 0, 0, 0, 0, 0>;

  Volume operator"" _mm3(long double val);
  Volume operator"" _mm3(unsigned long long val);

  Volume operator"" _cm3(long double val);
  Volume operator"" _cm3(unsigned long long val);

  Volume operator"" _m3(long double val);
  Volume operator"" _m3(unsigned long long val);

  Volume operator"" _in3(long double val);
  Volume operator"" _in3(unsigned long long val);

  Volume operator"" _ft3(long double val);
  Volume operator"" _ft3(unsigned long long val);

}; // namespace eng

using eng::operator"" _mm3;         using eng::operator"" _cm3;
using eng::operator"" _m3;
using eng::operator"" _in3;         using eng::operator"" _ft3;

