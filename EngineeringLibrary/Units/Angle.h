#ifndef Angle_h_INCLUDED
#define Angle_h_INCLUDED

/*****************************************************************//**
 * \file  Angle.h
 * \brief An object representing the angle between two noncolinear lines. 
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "UnitBase.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /** The geometry formed by two non-colinear, coplanar lines. 
   * \class Angle 
   * \addtogroup Units
   */
  class ENGINEERINGLIBRARY_API Angle : public UnitBase{
  public:
    /**
     * \brief Construct an Angle
     * 
     * \param _radians The measure of the angle in radians
     */
    explicit Angle(const double& radians = 0) : UnitBase(radians) { }  
    //? Becuase radians are "imaginary" units, maybe this should be implicit?
    Angle(const Angle&) = default;
    ~Angle() = default;

    double rad() const { return _value; }
    double deg() const;    // defined in Angle.cpp to not require PhysicsMath.h here

    explicit operator double();         
    //? Becuase radians are "imaginary" units, maybe this should be implicit?
  };

  Angle ENGINEERINGLIBRARY_API operator"" _deg(long double val);
  Angle ENGINEERINGLIBRARY_API operator"" _deg(unsigned long long val);

  Angle ENGINEERINGLIBRARY_API operator"" _rad(long double val);
  Angle ENGINEERINGLIBRARY_API operator"" _rad(unsigned long long val);
  
  Angle ENGINEERINGLIBRARY_API operator- (const Angle& rh);

  Angle ENGINEERINGLIBRARY_API operator+ (const Angle& lh, const Angle& rh);

  Angle ENGINEERINGLIBRARY_API operator- (const Angle& lh, const Angle& rh);

  Angle ENGINEERINGLIBRARY_API operator* (const Angle& lh, const double& n);
  Angle ENGINEERINGLIBRARY_API operator* (const double& n, const Angle& rh);

  Angle ENGINEERINGLIBRARY_API operator/ (const Angle& lh, const double& n);

  bool ENGINEERINGLIBRARY_API operator== (const Angle& lh, const Angle& rh);
  bool ENGINEERINGLIBRARY_API operator> (const Angle& lh, const Angle& rh);
  bool ENGINEERINGLIBRARY_API operator!= (const Angle& lh, const Angle& rh);
  bool ENGINEERINGLIBRARY_API operator< (const Angle& lh, const Angle& rh);
  bool ENGINEERINGLIBRARY_API operator>= (const Angle& lh, const Angle& rh);
  bool ENGINEERINGLIBRARY_API operator<= (const Angle& lh, const Angle& rh);

  double ENGINEERINGLIBRARY_API sin(const Angle& a);
  double ENGINEERINGLIBRARY_API cos(const Angle& a);
  double ENGINEERINGLIBRARY_API tan(const Angle& a);

  Angle ENGINEERINGLIBRARY_API asin(const double& x);
  Angle ENGINEERINGLIBRARY_API acos(const double& x);
  Angle ENGINEERINGLIBRARY_API atan(const double& x);
  Angle ENGINEERINGLIBRARY_API atan2(const double& x, const double& y);

  inline Angle ENGINEERINGLIBRARY_API conj(const Angle& x) { return x; }
  inline Angle ENGINEERINGLIBRARY_API real(const Angle& x) { return x; }
  inline Angle ENGINEERINGLIBRARY_API imag(const Angle&) { return 0_rad; }

}; // namespace eng

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<eng::Angle> : NumTraits<double> {
    typedef eng::Angle Real;
    typedef eng::Angle NonInteger;
    typedef eng::Angle Nested;

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

using eng::operator"" _rad;        using eng::operator"" _deg;

#endif
