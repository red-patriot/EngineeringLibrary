#ifndef Stiffness_h_INCLUDED
#define Stiffness_h_INCLUDED

/*****************************************************************//**
 * \file  Stiffness.h
 * \brief An object representing a linear stiffness
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "UnitBase.h"

#include <Eigen/Core>

namespace eng {

  /**
   * \class Stiffness a linear resistance to deformation measured in force/length
   */
  class ENGINEERINGLIBRARY_API Stiffness : public UnitBase {
  public:
    /**
     * \brief Construct a stiffness
     * 
     * \param _newtons_per_meter the measure of stiffness in Newtons/meter
     */
    explicit Stiffness(double _newtons_per_meter = 0) : UnitBase(_newtons_per_meter) { }
    Stiffness(const Stiffness&) = default;
    ~Stiffness() = default;

    double Npm() const { return _value; }
    double Npmm() const { return _value * 0.001; }
    
    double lbpin() const { return _value * 0.00571014715473264626; }
    double lbpft() const { return _value * 0.06852176585679175519; }

    Stiffness& operator+= (const Stiffness& rh) { _value += rh._value; return *this; }
    Stiffness& operator-= (const Stiffness& rh) { _value -= rh._value; return *this; }
    Stiffness& operator*= (const double& rh) { _value *= rh; return *this; }
    Stiffness& operator/= (const double& rh) { _value /= rh; return *this; }
  };

  Stiffness ENGINEERINGLIBRARY_API operator"" _Npm(long double val);
  Stiffness ENGINEERINGLIBRARY_API operator"" _Npm(unsigned long long val);

  Stiffness ENGINEERINGLIBRARY_API operator"" _Npmm(long double val);
  Stiffness ENGINEERINGLIBRARY_API operator"" _Npmm(unsigned long long val);

  Stiffness ENGINEERINGLIBRARY_API operator"" _lbpin(long double val);
  Stiffness ENGINEERINGLIBRARY_API operator"" _lbpin(unsigned long long val);

  Stiffness ENGINEERINGLIBRARY_API operator"" _lbpft(long double val);
  Stiffness ENGINEERINGLIBRARY_API operator"" _lbpft(unsigned long long val);

  Stiffness ENGINEERINGLIBRARY_API operator- (const Stiffness& lh);

  Stiffness ENGINEERINGLIBRARY_API operator+ (const Stiffness& lh, const Stiffness& rh);

  Stiffness ENGINEERINGLIBRARY_API operator- (const Stiffness& lh, const Stiffness& rh);

  Stiffness ENGINEERINGLIBRARY_API operator* (const Stiffness& lh, const double& n);
  Stiffness ENGINEERINGLIBRARY_API operator* (const double& n, const Stiffness& rh);
  Stiffness ENGINEERINGLIBRARY_API operator* (const class Pressure& lh, const class Length& rh);
  Stiffness ENGINEERINGLIBRARY_API operator* (const class Length& lh, const class Pressure& rh);

  Stiffness ENGINEERINGLIBRARY_API operator/ (const Stiffness& lh, const double& n);
  Stiffness ENGINEERINGLIBRARY_API operator/ (const class Force& lh, const class Length& rh);
  Stiffness ENGINEERINGLIBRARY_API operator/ (const class Damping& lh, const class Time& rh);
  double ENGINEERINGLIBRARY_API operator/ (const Stiffness& lh, const Stiffness& rh);

  bool ENGINEERINGLIBRARY_API  operator== (const Stiffness& lh, const Stiffness& rh);
  bool ENGINEERINGLIBRARY_API  operator> (const Stiffness& lh, const Stiffness& rh);
  bool ENGINEERINGLIBRARY_API  operator!= (const Stiffness& lh, const Stiffness& rh);
  bool ENGINEERINGLIBRARY_API  operator< (const Stiffness& lh, const Stiffness& rh);
  bool ENGINEERINGLIBRARY_API  operator>= (const Stiffness& lh, const Stiffness& rh);
  bool ENGINEERINGLIBRARY_API  operator<= (const Stiffness& lh, const Stiffness& rh);

  inline Stiffness ENGINEERINGLIBRARY_API conj(const Stiffness& x) { return x; }
  inline Stiffness ENGINEERINGLIBRARY_API real(const Stiffness& x) { return x; }
  inline Stiffness ENGINEERINGLIBRARY_API imag(const Stiffness&) { return 0_Npm; }
  

}; // namespace eng

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<eng::Stiffness> : NumTraits<double> {
    typedef eng::Stiffness Real;
    typedef eng::Stiffness NonInteger;
    typedef eng::Stiffness Nested;

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

using eng::operator"" _Npm;       using eng::operator"" _Npmm;
using eng::operator"" _lbpin;     using eng::operator"" _lbpft;

#endif

