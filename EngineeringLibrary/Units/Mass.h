#ifndef Mass_h_INCLUDED
#define Mass_h_INCLUDED

/*****************************************************************//**
 * \file  Mass.h
 * \brief An object representing an inertial or gravitational mass. 
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "PhysicsMath.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /** A mass
   * \class Mass
   * \addtogroup Units
   */
  class ENGINEERINGLIBRARY_API Mass : public UnitBase {
  public:
    /**
     * \brief Mass constructor
     * 
     * \param _kilograms the measure of the mass in kilograms
     */
    explicit Mass(const double kilograms=0) : UnitBase(kilograms) { }
    Mass(const Mass&) = default;
    ~Mass() = default;

    double g() const { return _value * 1000; }
    double kg() const { return _value; }

    double slug() const { return _value * 0.06852176556196105; }

    Mass& operator+= (const Mass& rh) { _value += rh._value; return *this; }
    Mass& operator-= (const Mass& rh) { _value -= rh._value; return *this; }
    Mass& operator*= (const double& rh) { _value *= rh; return *this; }
    Mass& operator/= (const double& rh) { _value /= rh; return *this; }
  };

  Mass ENGINEERINGLIBRARY_API operator"" _g (long double val);
  Mass ENGINEERINGLIBRARY_API operator"" _g (unsigned long long val);

  Mass ENGINEERINGLIBRARY_API operator"" _kg (long double val);
  Mass ENGINEERINGLIBRARY_API operator"" _kg (unsigned long long val);

  Mass ENGINEERINGLIBRARY_API operator"" _slug (long double val);
  Mass ENGINEERINGLIBRARY_API operator"" _slug (unsigned long long val);

  Mass ENGINEERINGLIBRARY_API operator- (const Mass& lh);

  Mass ENGINEERINGLIBRARY_API operator+ (const Mass& lh, const Mass& rh);

  Mass ENGINEERINGLIBRARY_API operator- (const Mass& lh, const Mass& rh);

  Mass ENGINEERINGLIBRARY_API operator* (const Mass& lh, const double& rh);
  Mass ENGINEERINGLIBRARY_API operator* (const double& lh, const Mass& rh);
  Mass ENGINEERINGLIBRARY_API operator* (const class Damping& lh, const class Time& rh);
  Mass ENGINEERINGLIBRARY_API operator* (const class Time& lh, const class Damping& rh);

  Mass ENGINEERINGLIBRARY_API operator/ (const Mass& lh, const double& rh);
  Mass ENGINEERINGLIBRARY_API operator/ (const class Force& lh, const class Acceleration& rh);

  bool ENGINEERINGLIBRARY_API operator== (const Mass& lh, const Mass& rh);
  bool ENGINEERINGLIBRARY_API operator> (const Mass& lh, const Mass& rh);
  bool ENGINEERINGLIBRARY_API operator!= (const Mass& lh, const Mass& rh);
  bool ENGINEERINGLIBRARY_API operator< (const Mass& lh, const Mass& rh);
  bool ENGINEERINGLIBRARY_API operator>= (const Mass& lh, const Mass& rh);
  bool ENGINEERINGLIBRARY_API operator<= (const Mass& lh, const Mass& rh);

  inline Mass ENGINEERINGLIBRARY_API conj(const Mass& x) { return x; }
  inline Mass ENGINEERINGLIBRARY_API real(const Mass& x) { return x; }
  inline Mass ENGINEERINGLIBRARY_API imag(const Mass& x) { return 0_kg; }

};  // namespace eng

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<eng::Mass> : NumTraits<double> {
    typedef eng::Mass Real;
    typedef eng::Mass NonInteger;
    typedef eng::Mass Nested;

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

using eng::operator"" _g;       using eng::operator"" _kg;
using eng::operator"" _slug;

#endif
