#ifndef Velocity_h_INCLUDED
#define Velocity_h_INCLUDED

#include "UnitBase.h"

#include <Eigen/Core>

namespace physics {

  /**
   * \class Velocity The speed of an object moving through space.
   */
  class ENGINEERINGLIBRARY_API Velocity : public UnitBase {
  public:
    /**
     * \brief Construct a Velocity
     * 
     * \param _meters_per_second The measure of speed in meters per second
     */
    explicit Velocity(const double _meters_per_second = 0) : UnitBase(_meters_per_second) { }
    Velocity(const Velocity&) = default;
    ~Velocity() = default;

    double mpsec() const { return _value; }
    double kph() const { return _value * 3600 / 1000; }

    double inpsec() const { return _value * 100 / 2.54; }
    double ftpsec() const { return _value * 100 / 30.48; }
    double mph() const { return _value * 360'000 / 160'934.4; }

    Velocity& operator+= (const Velocity& rh) { _value += rh._value; return *this; }
    Velocity& operator-= (const Velocity& rh) { _value -= rh._value; return *this; }
    Velocity& operator*= (const double& rh) { _value *= rh; return *this; }
    Velocity& operator/= (const double& rh) { _value /= rh; return *this; }
  };

  // Literal operators
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

};  // namespace physics

/* Integration with Eigen. */
namespace Eigen {

  template<> struct NumTraits<physics::Velocity> : NumTraits<double> {
    typedef physics::Velocity Real;
    typedef physics::Velocity NonInteger;
    typedef physics::Velocity Nested;

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

using physics::operator"" _mpsec;      using physics::operator"" _kph;
using physics::operator"" _inpsec;     using physics::operator"" _ftpsec;
using physics::operator"" _mph;

#endif
