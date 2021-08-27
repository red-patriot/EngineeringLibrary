#pragma once

/*****************************************************************/ /**
 * \file   Voltage.h
 * \brief  A representation of electric potential (voltage).
 * 
 * \date 2021
 *********************************************************************/

#include <eigen3/Eigen/Core>

#include "UnitBase.h"

namespace eng {

  /**
   * \class Voltage
   * \addtogroup Units
   */
  template <>
  class SIUnit<1, 2, -3, -1, 0, 0, 0> {
   public:
    typedef SIUnit<1, 2, -3, -1, 0, 0, 0> this_t;
    UnitBaseCOMMON 
   public: 
    double V() const { return value_; }
    double mV() const { return value_ * 1000.0; }
    double kV() const { return value_ * 0.001; }
  };

  using Voltage = SIUnit<1, 2, -3, -1, 0, 0, 0>;

  Voltage operator"" _mV(long double val);
  Voltage operator"" _mV(unsigned long long val);

  Voltage operator"" _V(long double val);
  Voltage operator"" _V(unsigned long long val);

  Voltage operator"" _kV(long double val);
  Voltage operator"" _kV(unsigned long long val);

  inline Voltage conj(const Voltage& x) { return x; }
  inline Voltage real(const Voltage& x) { return x; }
  inline Voltage imag(const Voltage& x) { return 0_V; }

};  // namespace eng

/* Integration with Eigen. */
namespace Eigen {

  template <>
  struct NumTraits<eng::Voltage> : NumTraits<double> {
    typedef eng::Voltage Real;
    typedef eng::Voltage NonInteger;
    typedef eng::Voltage Nested;

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

using eng::operator"" _V;        using eng::operator"" _kV;
using eng::operator"" _mV;
