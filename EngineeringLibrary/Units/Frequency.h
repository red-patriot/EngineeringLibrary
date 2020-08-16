#ifndef Frequency_h_INCLUDED
#define Frequency_h_INCLUDED

#include "UnitBase.h"

#include <Eigen\Core>

namespace physics {


  /**
   * \class Frequency a measure of cycles/repetitions per unit time
   */
  class ENGINEERINGLIBRARY_API Frequency : public UnitBase { 
  public:
    /**
     * \brief Construct a frequency
     * 
     * \param _hertz the measure of cycles per second
     */
    explicit Frequency(const double _hertz=0) : UnitBase(_hertz) { }
    Frequency(const Frequency&) = default;
    ~Frequency() = default;

    double Hz() const { return _value; }
    double kHz() const { return _value * 0.001; }
    double MHz() const { return _value * 0.000'001; }

    Frequency& operator+= (const Frequency& rh) { _value += rh._value; return *this; }
    Frequency& operator-= (const Frequency& rh) { _value -= rh._value; return *this; }
    Frequency& operator*= (const double& rh) { _value *= rh; return *this; }
    Frequency& operator/= (const double& rh) { _value /= rh; return *this; }
  };

  // Literal operators
  Frequency ENGINEERINGLIBRARY_API operator"" _Hz (long double val);
  Frequency ENGINEERINGLIBRARY_API operator"" _Hz (unsigned long long val);

  Frequency ENGINEERINGLIBRARY_API operator"" _kHz (long double val);
  Frequency ENGINEERINGLIBRARY_API operator"" _kHz (unsigned long long val);

  Frequency ENGINEERINGLIBRARY_API operator"" _MHz (long double val);
  Frequency ENGINEERINGLIBRARY_API operator"" _MHz (unsigned long long val);

  Frequency ENGINEERINGLIBRARY_API operator- (const Frequency& lh);

  Frequency ENGINEERINGLIBRARY_API operator+ (const Frequency& lh, const Frequency& rh);

  Frequency ENGINEERINGLIBRARY_API operator- (const Frequency& lh, const Frequency& rh);

  Frequency ENGINEERINGLIBRARY_API operator* (const Frequency& lh, const double& rh);
  Frequency ENGINEERINGLIBRARY_API operator* (const double& lh, const Frequency& rh);

  Frequency ENGINEERINGLIBRARY_API operator/ (const Frequency& lh, const double& rh);
  double ENGINEERINGLIBRARY_API operator/ (const Frequency& lh, const Frequency& rh);
  Frequency ENGINEERINGLIBRARY_API operator/ (const double& lh, const class Time& rh);
  Frequency ENGINEERINGLIBRARY_API operator/ (const class Velocity& lh, const class Length& rh);
  Frequency ENGINEERINGLIBRARY_API operator/ (const class Acceleration& lh, const class Velocity& rh);
  Frequency ENGINEERINGLIBRARY_API operator/ (const class Frequency2& lh, const Frequency& rh);

  bool ENGINEERINGLIBRARY_API operator== (const Frequency& lh, const Frequency& rh);
  bool ENGINEERINGLIBRARY_API operator> (const Frequency& lh, const Frequency& rh);
  bool ENGINEERINGLIBRARY_API operator!= (const Frequency& lh, const Frequency& rh);
  bool ENGINEERINGLIBRARY_API operator< (const Frequency& lh, const Frequency& rh);
  bool ENGINEERINGLIBRARY_API operator>= (const Frequency& lh, const Frequency& rh);
  bool ENGINEERINGLIBRARY_API operator<= (const Frequency& lh, const Frequency& rh);
  
  inline Frequency ENGINEERINGLIBRARY_API conj(const Frequency& x) { return x; }
  inline Frequency ENGINEERINGLIBRARY_API real(const Frequency& x) { return x; }
  inline Frequency ENGINEERINGLIBRARY_API imag(const Frequency&) { return 0_Hz; }

  /**
   * \class Frequency2 A class modeling a frequency squared for intermediate steps in equations
   * 
   * this class is only for use in intermetiate operations of.
   * equations; it has limited functionality. 
   */
  class ENGINEERINGLIBRARY_API Frequency2 : public UnitBase { 
  public:
    /**
     * \brief Construct a Frequency2
     * 
     * \param _hertz2 the measure of Hertz^2
     */
    explicit Frequency2(const double _hertz2 = 0): UnitBase(_hertz2) { }
    Frequency2(const Frequency2&) = default;
    ~Frequency2() = default;
  };

  Frequency2 ENGINEERINGLIBRARY_API operator- (const Frequency2& lh);

  Frequency2 ENGINEERINGLIBRARY_API operator+ (const Frequency2& lh, const Frequency2& rh);

  Frequency2 ENGINEERINGLIBRARY_API operator- (const Frequency2& lh, const Frequency2& rh);

  Frequency2 ENGINEERINGLIBRARY_API operator* (const Frequency2& lh, const double& rh);
  Frequency2 ENGINEERINGLIBRARY_API operator* (const double& lh, const Frequency2& rh);
  Frequency2 ENGINEERINGLIBRARY_API operator* (const Frequency& lh, const Frequency& rh);

  Frequency2 ENGINEERINGLIBRARY_API operator/ (const Frequency2& lh, const double& rh);
  Frequency2 ENGINEERINGLIBRARY_API operator/ (const class Acceleration& lh, const class Length& rh);
  Frequency2 ENGINEERINGLIBRARY_API operator/ (const class Stiffness& lh, const class Mass& rh);

};

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<physics::Frequency> : NumTraits<double> {
    typedef physics::Frequency Real;
    typedef physics::Frequency NonInteger;
    typedef physics::Frequency Nested;

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

using physics::operator"" _Hz;        using physics::operator"" _kHz;
using physics::operator"" _MHz;

#endif
