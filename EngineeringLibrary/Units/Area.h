#pragma once

/*****************************************************************//**
 * \file  Area.h
 * \brief An object representing any 2D Area.
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "SIUnit.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /**
   * \class Area
   * \addtogroup Units
   */
  template<>
  class SIUnit<0, 2, 0, 0, 0, 0, 0> {
   public:
    typedef SIUnit<0, 2, 0, 0, 0, 0, 0> this_t;
    UnitBaseCOMMON
   public:
    double mm2() const { return value_ * 1'000'000; }
    double cm2() const { return value_ * 10'000; }
    double m2() const { return value_; }

    double in2() const { return value_ * 10'000/(6.4516); }
    double ft2() const { return value_ * 10'000/(929.0304); }
  };

  using Area = SIUnit<0, 2, 0, 0, 0, 0, 0>;

  Area operator"" _mm2(long double val);
  Area operator"" _mm2(unsigned long long val);

  Area operator"" _cm2(long double val);
  Area operator"" _cm2(unsigned long long val);

  Area operator"" _m2(long double val);
  Area operator"" _m2(unsigned long long val);

  Area operator"" _in2(long double val);
  Area operator"" _in2(unsigned long long val);

  Area operator"" _ft2(long double val);
  Area operator"" _ft2(unsigned long long val);

}; // namespace eng

using eng::operator"" _mm2;       using eng::operator"" _cm2;
using eng::operator"" _m2;
using eng::operator"" _in2;       using eng::operator"" _ft2;

