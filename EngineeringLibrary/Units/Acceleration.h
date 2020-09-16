#ifndef Acceleration_h_INCLUDED
#define Acceleration_h_INCLUDED

/*****************************************************************//**
 * \file  Acceleration.h
 * \brief An object representing a linear Acceleration. 
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "UnitBase.h"

#include <Eigen/Core>

namespace eng {

  /** The change in speed of an object moginv through space
   * \class Acceleration 
   * \addtogroup Units
   */
  class ENGINEERINGLIBRARY_API Acceleration : public UnitBase {
  public:
    /**
     * \brief Construct an Acceleration
     * 
     * \param _meters_per_second2 The measure of acceleration in meters per second per second.
     */
    Acceleration(const double meters_per_second2=0) : UnitBase(meters_per_second2) { }
    Acceleration(const Acceleration&) = default;
    ~Acceleration() = default;

    double mpsec2() const { return _value; }
    
    double inpsec2() const { return _value * (100/2.54); }
    double ftpsec2() const { return _value * (100/(30.48)); }

    Acceleration& operator+= (const Acceleration& rh) { _value += rh._value; return *this; }
    Acceleration& operator-= (const Acceleration& rh) { _value -= rh._value; return *this; }
    Acceleration& operator*= (const double& rh) { _value *= rh; return *this; }
    Acceleration& operator/= (const double& rh) { _value /= rh; return *this; }
  };

  Acceleration ENGINEERINGLIBRARY_API operator"" _mpsec2 (long double val);
  Acceleration ENGINEERINGLIBRARY_API operator"" _mpsec2 (unsigned long long val);

  Acceleration ENGINEERINGLIBRARY_API operator"" _inpsec2 (long double val);
  Acceleration ENGINEERINGLIBRARY_API operator"" _inpsec2 (unsigned long long val);

  Acceleration ENGINEERINGLIBRARY_API operator"" _ftpsec2 (long double val);
  Acceleration ENGINEERINGLIBRARY_API operator"" _ftpsec2 (unsigned long long val);

  Acceleration ENGINEERINGLIBRARY_API operator- (const Acceleration& lh);

  Acceleration ENGINEERINGLIBRARY_API operator+ (const Acceleration& lh, const Acceleration& rh);

  Acceleration ENGINEERINGLIBRARY_API operator- (const Acceleration& lh, const Acceleration& rh);

  Acceleration ENGINEERINGLIBRARY_API operator* (const Acceleration& lh, const double& rh);
  Acceleration ENGINEERINGLIBRARY_API operator* (const double& lh, const Acceleration& rh);

  Acceleration ENGINEERINGLIBRARY_API operator/ (const Acceleration& lh, const double& rh);
  double ENGINEERINGLIBRARY_API operator/ (const Acceleration& lh, const Acceleration& rh);
  Acceleration ENGINEERINGLIBRARY_API operator/ (const class Velocity& lh, const class Time& rh);
  Acceleration ENGINEERINGLIBRARY_API operator/ (const class Force& lh, const class Mass& rh);

  bool ENGINEERINGLIBRARY_API operator== (const Acceleration& lh, const Acceleration& rh);
  bool ENGINEERINGLIBRARY_API operator> (const Acceleration& lh, const Acceleration& rh);
  bool ENGINEERINGLIBRARY_API operator!= (const Acceleration& lh, const Acceleration& rh);
  bool ENGINEERINGLIBRARY_API operator< (const Acceleration& lh, const Acceleration& rh);
  bool ENGINEERINGLIBRARY_API operator>= (const Acceleration& lh, const Acceleration& rh);
  bool ENGINEERINGLIBRARY_API operator<= (const Acceleration& lh, const Acceleration& rh);

  inline Acceleration ENGINEERINGLIBRARY_API conj(const Acceleration& x) { return x; }
  inline Acceleration ENGINEERINGLIBRARY_API real(const Acceleration& x) { return x; }
  inline Acceleration ENGINEERINGLIBRARY_API imag(const Acceleration&) { return 0_mpsec2; }

};  // namespace eng

/* Integration with Eigen. */
namespace Eigen {

  template<> struct NumTraits<eng::Acceleration> : NumTraits<double> {
    typedef eng::Acceleration Real;
    typedef eng::Acceleration NonInteger;
    typedef eng::Acceleration Nested;

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

using eng::operator"" _mpsec2;
using eng::operator"" _inpsec2;      using eng::operator"" _ftpsec2;

#endif