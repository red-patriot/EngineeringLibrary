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

#include <eigen3/Eigen/Core>

namespace eng {

  /** A linear resistance to deformation measured in force/length
   * \class Stiffness 
   * \addtogroup Units
   */
  class ENGINEERINGLIBRARY_API Stiffness : public UnitBase<1, 0, -2, 0, 0, 0, 0> {
  public:
    /**
     * \brief Stiffness constructor
     * 
     * \param _newtons_per_meter the measure of stiffness in Newtons/meter
     */
    explicit Stiffness(double _newtons_per_meter = 0) : UnitBase(_newtons_per_meter) { }
    Stiffness(const UnitBase<1, 0, -2, 0, 0, 0, 0>& b) : UnitBase(b) { }
    ~Stiffness() = default;

    double Npm() const { return _value; }
    double Npmm() const { return _value * 0.001; }
    
    double lbpin() const { return _value * 0.005'710'147'154'732'646'26; }
    double lbpft() const { return _value * 0.068'521'765'856'791'755'19; }

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

