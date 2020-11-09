#ifndef Frequency_h_INCLUDED
#define Frequency_h_INCLUDED

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
  class ENGINEERINGLIBRARY_API Frequency : public UnitBase<0, 0, -1, 0, 0, 0, 0> {
  public:
    /**
     * \brief Frequency constructor
     *
     * \param _hertz the measure of cycles per second
     */
    explicit Frequency(const double hertz = 0) : UnitBase(hertz) { }
    Frequency(const UnitBase<0, 0, -1, 0, 0, 0, 0>& b) : UnitBase(b) { }
    ~Frequency() = default;

    double Hz() const { return _value; }
    double kHz() const { return _value * 0.001; }
    double MHz() const { return _value * 0.000'001; }

    Frequency& operator+= (const Frequency& rh) { _value += rh._value; return *this; }
    Frequency& operator-= (const Frequency& rh) { _value -= rh._value; return *this; }
    Frequency& operator*= (const double& rh) { _value *= rh; return *this; }
    Frequency& operator/= (const double& rh) { _value /= rh; return *this; }
  };

  Frequency ENGINEERINGLIBRARY_API operator"" _Hz (long double val);
  Frequency ENGINEERINGLIBRARY_API operator"" _Hz (unsigned long long val);

  Frequency ENGINEERINGLIBRARY_API operator"" _kHz (long double val);
  Frequency ENGINEERINGLIBRARY_API operator"" _kHz (unsigned long long val);

  Frequency ENGINEERINGLIBRARY_API operator"" _MHz (long double val);
  Frequency ENGINEERINGLIBRARY_API operator"" _MHz (unsigned long long val);

  inline Frequency ENGINEERINGLIBRARY_API conj(const Frequency& x) { return x; }
  inline Frequency ENGINEERINGLIBRARY_API real(const Frequency& x) { return x; }
  inline Frequency ENGINEERINGLIBRARY_API imag(const Frequency&) { return 0_Hz; }

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

#endif
