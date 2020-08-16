#ifndef Stiffness_h_INCLUDED
#define Stiffness_h_INCLUDED

/* Stiffness.h
 * Simulation of a linear stiffness in force per unit length
 */

#include "UnitBase.h"

#include <Eigen/Core>

namespace physics {

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

  // Literal operators
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

  // Comparison operators
  bool ENGINEERINGLIBRARY_API  operator== (const Stiffness& lh, const Stiffness& rh);
  bool ENGINEERINGLIBRARY_API  operator> (const Stiffness& lh, const Stiffness& rh);
  bool ENGINEERINGLIBRARY_API  operator!= (const Stiffness& lh, const Stiffness& rh);
  bool ENGINEERINGLIBRARY_API  operator< (const Stiffness& lh, const Stiffness& rh);
  bool ENGINEERINGLIBRARY_API  operator>= (const Stiffness& lh, const Stiffness& rh);
  bool ENGINEERINGLIBRARY_API  operator<= (const Stiffness& lh, const Stiffness& rh);

  inline Stiffness ENGINEERINGLIBRARY_API conj(const Stiffness& x) { return x; }
  inline Stiffness ENGINEERINGLIBRARY_API real(const Stiffness& x) { return x; }
  inline Stiffness ENGINEERINGLIBRARY_API imag(const Stiffness&) { return 0_Npm; }
  

}; // namespace physics

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<physics::Stiffness> : NumTraits<double> {
    typedef physics::Stiffness Real;
    typedef physics::Stiffness NonInteger;
    typedef physics::Stiffness Nested;

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

using physics::operator"" _Npm;       using physics::operator"" _Npmm;
using physics::operator"" _lbpin;     using physics::operator"" _lbpft;

#endif

