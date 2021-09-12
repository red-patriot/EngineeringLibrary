#pragma once

/*****************************************************************//**
 * \file  Velocity.h
 * \brief An object representing a linear velocity
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "SIUnit.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /**
   * \class Velocity
   * \addtogroup Units
   */
  template<>
  class SIUnit<0, 1, -1, 0, 0, 0, 0> {
   public:
    typedef SIUnit<0, 1, -1, 0, 0, 0, 0> this_t;
    UnitBaseCOMMON
   public:
    double mpsec() const { return value_; }
    double kph() const { return value_ * 3.600; }

    double inpsec() const { return value_ * 39.370'007'874'015'748; }  // 100/2.54
    double ftpsec() const { return value_ * 3.280'839'895'013'123; }  // 100/30.48
    double mph() const { return value_ * 2.236'936'292'054'402; }  // 360'000 / 160'934.4
  };

  using Velocity = SIUnit<0, 1, -1, 0, 0, 0, 0>;

  Velocity operator"" _mpsec (long double val);
  Velocity operator"" _mpsec (unsigned long long val);

  Velocity operator"" _kph (long double val);
  Velocity operator"" _kph (unsigned long long val);

  Velocity operator"" _inpsec (long double val);
  Velocity operator"" _inpsec (unsigned long long val);

  Velocity operator"" _ftpsec (long double val);
  Velocity operator"" _ftpsec (unsigned long long val);

  Velocity operator"" _mph (long double val);
  Velocity operator"" _mph (unsigned long long val);

};  // namespace eng

using eng::operator"" _mpsec;      using eng::operator"" _kph;
using eng::operator"" _inpsec;     using eng::operator"" _ftpsec;
using eng::operator"" _mph;

