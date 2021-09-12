#pragma once

/*****************************************************************//**
 * \file  MomentOfArea.h
 * \brief Objects representing a First- or Second moment of area
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "SIUnit.h"
#include "Volume.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /**
   * \typedef FirstMomentOfArea Volume
   * \see Volume
   * \addtogroup Units
   */
  using FirstMomentOfArea = Volume;

  /**
   * \class SecondMomentOfArea 
   * \addtogroup Units
   */
  template<>
  class SIUnit<0, 4, 0, 0, 0, 0, 0> {
   public:
    typedef SIUnit<0, 4, 0, 0, 0, 0, 0> this_t;
    UnitBaseCOMMON
   public:
    double mm4() const { return value_ * 1'000'000'000'000; }
    double m4() const { return value_; }

    double in4() const { return value_ * 100'000'000 / 41.623'142'56; }
    double ft4() const { return value_ * 100'000'000 / 863'097.481'241'6; }
  };

  using SecondMomentOfArea = SIUnit<0, 4, 0, 0, 0, 0, 0>;

  // Literal operators
  SecondMomentOfArea operator"" _mm4(long double val);
  SecondMomentOfArea operator"" _mm4(unsigned long long val);

  SecondMomentOfArea operator"" _m4(long double val);
  SecondMomentOfArea operator"" _m4(unsigned long long val);

  SecondMomentOfArea operator"" _in4(long double val);
  SecondMomentOfArea operator"" _in4(unsigned long long val);

  SecondMomentOfArea operator"" _ft4(long double val);
  SecondMomentOfArea operator"" _ft4(unsigned long long val);

}; // namespace eng

using eng::operator"" _mm4;         using eng::operator"" _m4;
using eng::operator"" _in4;         using eng::operator"" _ft4;

