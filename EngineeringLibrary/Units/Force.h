#ifndef Force_h_INCLUDED
#define Force_h_INCLUDED

/*****************************************************************//**
 * \file  Force.h
 * \brief An object representing a force. 
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "UnitBase.h"

#include <Eigen/Core>

namespace eng {

  /**
   * \class Force The magnitude of a force in space
   */
  class ENGINEERINGLIBRARY_API Force : public UnitBase {
  public:
    /**
     * \brief Construct a Force
     * 
     * \param _newtons The magnitude of the force in Newtons
     */
    explicit Force(double newtons=0) : UnitBase(newtons) { }
    Force(const Force&) = default;
    ~Force() = default;

    double N() const { return _value; }
    double kN() const { return _value * 0.001; }

    double lbf() const { return _value * 0.224808943099711; }
    double kips() const { return _value * 0.000224808943099711;  }

    Force& operator+= (const Force& rh) { _value += rh._value; return *this; }
    Force& operator-= (const Force& rh) { _value -= rh._value; return *this; }
    Force& operator*= (const double& rh) { _value *= rh; return *this; }
    Force& operator/= (const double& rh) {_value /= rh; return *this; }
  };

  Force ENGINEERINGLIBRARY_API operator"" _N(long double val);
  Force ENGINEERINGLIBRARY_API operator"" _N(unsigned long long val);

  Force ENGINEERINGLIBRARY_API operator"" _kN(long double val);
  Force ENGINEERINGLIBRARY_API operator"" _kN(unsigned long long val);

  Force ENGINEERINGLIBRARY_API operator"" _lbf(long double val);
  Force ENGINEERINGLIBRARY_API operator"" _lbf(unsigned long long val);

  Force ENGINEERINGLIBRARY_API operator"" _kips(long double val);
  Force ENGINEERINGLIBRARY_API operator"" _kips(unsigned long long val);

  Force ENGINEERINGLIBRARY_API operator- (const Force& lh);

  Force ENGINEERINGLIBRARY_API operator+ (const Force& lh, const Force& rh);

  Force ENGINEERINGLIBRARY_API operator- (const Force& lh, const Force& rh);

  Force ENGINEERINGLIBRARY_API operator*(const class Pressure& lh, const class Area& rh);
  Force ENGINEERINGLIBRARY_API operator*(const class Area& lh, const class Pressure& rh);
  Force ENGINEERINGLIBRARY_API operator* (const Force& lh, const double& n);
  Force ENGINEERINGLIBRARY_API operator* (const double& n, const Force& rh);
  Force ENGINEERINGLIBRARY_API operator* (const class Stiffness& lh, const class Length& rh);
  Force ENGINEERINGLIBRARY_API operator* (const class Length& lh, const class Stiffness& rh);
  Force ENGINEERINGLIBRARY_API operator* (const class Mass& lh, const class Acceleration& rh);
  Force ENGINEERINGLIBRARY_API operator* (const class Acceleration& lh, const class Mass& rh);
  Force ENGINEERINGLIBRARY_API operator* (const class Damping& lh, const class Velocity& rh);
  Force ENGINEERINGLIBRARY_API operator* (const class Velocity& lh, const class Damping& rh);

  Force ENGINEERINGLIBRARY_API operator/ (const Force& lh, const double& n);
  double ENGINEERINGLIBRARY_API operator/ (const Force& lh, const Force& rh);

  bool ENGINEERINGLIBRARY_API operator== (const Force& lh, const Force& rh);
  bool ENGINEERINGLIBRARY_API operator> (const Force& lh, const Force& rh);
  bool ENGINEERINGLIBRARY_API operator!= (const Force& lh, const Force& rh);
  bool ENGINEERINGLIBRARY_API operator< (const Force& lh, const Force& rh);
  bool ENGINEERINGLIBRARY_API operator>= (const Force& lh, const Force& rh);
  bool ENGINEERINGLIBRARY_API operator<= (const Force& lh, const Force& rh);

  inline Force ENGINEERINGLIBRARY_API conj(const Force& x) { return x; }
  inline Force ENGINEERINGLIBRARY_API real(const Force& x) { return x; }
  inline Force ENGINEERINGLIBRARY_API imag(const Force&) { return 0_N; }
  

}; // namespace eng

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<eng::Force> : NumTraits<double> {
    typedef eng::Force Real;
    typedef eng::Force NonInteger;
    typedef eng::Force Nested;

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

using eng::operator""_N;        using eng::operator""_kN;
using eng::operator""_lbf;      using eng::operator""_kips;

#endif

