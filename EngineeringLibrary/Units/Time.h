#pragma once

/*****************************************************************//**
 * \file  Time.h
 * \brief An object representing time. 
 *
 * 
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "UnitBase.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /** A time
   * \class Time 
   * \addtogroup Units
   */
  template<>
  class UnitBase<0, 0, 1, 0, 0, 0, 0> {
    typedef UnitBase<0, 0, 1, 0, 0, 0, 0> this_t;
    UnitBaseCOMMON
  public:
    double sec() const { return _value; }
    double minute() const { return _value / 60; }
    double hour() const { return _value / 3600; }
  };

  using Time = UnitBase<0, 0, 1, 0, 0, 0, 0>;

  Time operator"" _sec (long double val);
  Time operator"" _sec (unsigned long long val);

  Time operator"" _minute (long double val);
  Time operator"" _minute (unsigned long long val);

  Time operator"" _hour (long double val);
  Time operator"" _hour (unsigned long long val);

  inline Time conj(const Time& x) { return x; }
  inline Time real(const Time& x) { return x; }
  inline Time imag(const Time& x) { return 0_sec; }

};  // namepsace eng

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<eng::Time> : NumTraits<double> {
    typedef eng::Time Real;
    typedef eng::Time NonInteger;
    typedef eng::Time Nested;

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

using eng::operator"" _sec;        using eng::operator"" _minute;
using eng::operator"" _hour;

