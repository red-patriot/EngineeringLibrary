#pragma once

/*****************************************************************//**
 * \file  Frequency.h
 * \brief An object representing an oscillatory frequency
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "UnitBase.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /** A measure of cycles/repetitions per unit time
   * \class Frequency
   * \addtogroup Units
   */
  template<>
  class UnitBase<0, 0, -1, 0, 0, 0, 0> {
    typedef UnitBase<0, 0, -1, 0, 0, 0, 0> this_t;
    UnitBaseCOMMON
  public:
    double Hz() const { return mValue; }
    double kHz() const { return mValue * 0.001; }
    double MHz() const { return mValue * 0.000'001; }
  };

  using Frequency = UnitBase<0, 0, -1, 0, 0, 0, 0>;

  Frequency operator"" _Hz (long double val);
  Frequency operator"" _Hz (unsigned long long val);

  Frequency operator"" _kHz (long double val);
  Frequency operator"" _kHz (unsigned long long val);

  Frequency operator"" _MHz (long double val);
  Frequency operator"" _MHz (unsigned long long val);

  inline Frequency conj(const Frequency& x) { return x; }
  inline Frequency real(const Frequency& x) { return x; }
  inline Frequency imag(const Frequency&) { return 0_Hz; }

};  // namespace eng

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<eng::Frequency> : NumTraits<double> {
    typedef eng::Frequency Real;
    typedef eng::Frequency NonInteger;
    typedef eng::Frequency Nested;

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

using eng::operator"" _Hz;        using eng::operator"" _kHz;
using eng::operator"" _MHz;

