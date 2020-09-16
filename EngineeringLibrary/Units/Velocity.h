#ifndef Velocity_h_INCLUDED
#define Velocity_h_INCLUDED

/*****************************************************************//**
 * \file  Velocity.h
 * \brief An object representing a linear velocity
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "UnitBase.h"

#include <Eigen/Core>

namespace eng {

  /** The speed of an object moving through space.
   * \class Velocity
   * \addtogroup Units
   */
  class ENGINEERINGLIBRARY_API Velocity : public UnitBase {
  public:
    /**
     * \brief Velocity constructor
     * 
     * \param _meters_per_second The measure of speed in meters per second
     */
    explicit Velocity(const double _meters_per_second = 0) : UnitBase(_meters_per_second) { }
    Velocity(const Velocity&) = default;
    ~Velocity() = default;

    double mpsec() const { return _value; }
    double kph() const { return _value * 3.600; }

    double inpsec() const { return _value * 39.370'007'874'015'748; }  // 100/2.54
    double ftpsec() const { return _value * 3.280'839'895'013'123; }  // 100/30.48
    double mph() const { return _value * 2.236'936'292'054'402; }  // 360'000 / 160'934.4

    Velocity& operator+= (const Velocity& rh) { _value += rh._value; return *this; }
    Velocity& operator-= (const Velocity& rh) { _value -= rh._value; return *this; }
    Velocity& operator*= (const double& rh) { _value *= rh; return *this; }
    Velocity& operator/= (const double& rh) { _value /= rh; return *this; }
  };

  Velocity ENGINEERINGLIBRARY_API operator"" _mpsec (long double val);
  Velocity ENGINEERINGLIBRARY_API operator"" _mpsec (unsigned long long val);

  Velocity ENGINEERINGLIBRARY_API operator"" _kph (long double val);
  Velocity ENGINEERINGLIBRARY_API operator"" _kph (unsigned long long val);

  Velocity ENGINEERINGLIBRARY_API operator"" _inpsec (long double val);
  Velocity ENGINEERINGLIBRARY_API operator"" _inpsec (unsigned long long val);

  Velocity ENGINEERINGLIBRARY_API operator"" _ftpsec (long double val);
  Velocity ENGINEERINGLIBRARY_API operator"" _ftpsec (unsigned long long val);

  Velocity ENGINEERINGLIBRARY_API operator"" _mph (long double val);
  Velocity ENGINEERINGLIBRARY_API operator"" _mph (unsigned long long val);

  Velocity ENGINEERINGLIBRARY_API operator- (const Velocity& lh);

  Velocity ENGINEERINGLIBRARY_API operator+ (const Velocity& lh, const Velocity& rh);

  Velocity ENGINEERINGLIBRARY_API operator- (const Velocity& lh, const Velocity& rh);

  Velocity ENGINEERINGLIBRARY_API operator* (const Velocity& lh, const double& rh);
  Velocity ENGINEERINGLIBRARY_API operator* (const double& lh, const Velocity& rh);
  Velocity operator* (const class Acceleration& lh, const class Time& rh);
  Velocity operator* (const class Time& lh, const class Acceleration& rh);

  Velocity ENGINEERINGLIBRARY_API operator/ (const class Velocity2& lh, const Velocity& rh);
  Velocity ENGINEERINGLIBRARY_API operator/ (const Velocity& lh, const double& rh);
  Velocity ENGINEERINGLIBRARY_API operator/ (const class Length& lh, const class Time& rh);
  double ENGINEERINGLIBRARY_API operator/ (const Velocity& lh, const Velocity& rh);
  Velocity ENGINEERINGLIBRARY_API operator/ (const class Force& lh, const class Damping& rh);

  bool ENGINEERINGLIBRARY_API operator== (const Velocity& lh, const Velocity& rh);
  bool ENGINEERINGLIBRARY_API operator> (const Velocity& lh, const Velocity& rh);
  bool ENGINEERINGLIBRARY_API operator!= (const Velocity& lh, const Velocity& rh);
  bool ENGINEERINGLIBRARY_API operator< (const Velocity& lh, const Velocity& rh);
  bool ENGINEERINGLIBRARY_API operator>= (const Velocity& lh, const Velocity& rh);
  bool ENGINEERINGLIBRARY_API operator<= (const Velocity& lh, const Velocity& rh);

  inline Velocity ENGINEERINGLIBRARY_API conj(const Velocity& x) { return x; }
  inline Velocity ENGINEERINGLIBRARY_API real(const Velocity& x) { return x; }
  inline Velocity ENGINEERINGLIBRARY_API imag(const Velocity& x) { return 0_mpsec; }

  /** A class modeling a Velocity squared for intermediate steps in equations
   * \class Velocity2
   * 
   * \note This class is only for use in intermediate operations of
   * equations; it has limited functionality.
   * 
   * \addtogroup Units
   */
  class ENGINEERINGLIBRARY_API Velocity2 : public UnitBase {
  public:
    explicit Velocity2(const double _meters2_per_second2=0) : UnitBase(_meters2_per_second2) { }
    Velocity2(const Velocity2&) = default;
    ~Velocity2() = default;
  };

  Velocity2 operator- (const Velocity2& lh);

  Velocity2 ENGINEERINGLIBRARY_API operator+ (const Velocity2& lh, const Velocity2& rh);

  Velocity2 ENGINEERINGLIBRARY_API operator- (const Velocity2& lh, const Velocity2& rh);

  Velocity2 ENGINEERINGLIBRARY_API operator* (const Velocity& lh, const Velocity& rh);
  Velocity2 ENGINEERINGLIBRARY_API operator* (const Velocity2& lh, const double& rh);
  Velocity2 ENGINEERINGLIBRARY_API operator* (const double& lh, const Velocity2& rh);

  Velocity2 ENGINEERINGLIBRARY_API operator/ (const Velocity2& lh, const double& rh);
  double ENGINEERINGLIBRARY_API operator/ (const Velocity2& lh, const Velocity2& rh);

};  // namespace eng

/* Integration with Eigen. */
namespace Eigen {

  template<> struct NumTraits<eng::Velocity> : NumTraits<double> {
    typedef eng::Velocity Real;
    typedef eng::Velocity NonInteger;
    typedef eng::Velocity Nested;

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

using eng::operator"" _mpsec;      using eng::operator"" _kph;
using eng::operator"" _inpsec;     using eng::operator"" _ftpsec;
using eng::operator"" _mph;

#endif
