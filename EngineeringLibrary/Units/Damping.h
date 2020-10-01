#ifndef Damping_h_INCLUDED
#define Damping_h_INCLUDED

/*****************************************************************//**
 * \file  Damping.h
 * \brief An object representing a Damping component. 
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "UnitBase.h"

#include <eigen3/Eigen\Core>

namespace eng {

  /** A resistance to motion proportional to velocity
   * \class Damping
   * \addtogroup Units
   */
  class ENGINEERINGLIBRARY_API Damping : public UnitBase {
  public:
    /**
     * \brief Damping constructor
     * 
     * \param _Newton_seconds_per_meter the measure of Damping in Newton seconds per meter.
     */
    explicit Damping(const double newton_seconds_per_meter = 0) :
      UnitBase(newton_seconds_per_meter) { }
    Damping(const Damping&) = default;
    ~Damping() = default;

    double Nspm() const { return _value; }
    double kNspm() const { return _value / 1000; }

    double lbspin() const { return _value * .0254/4.4482216152605; }
    double lbspft() const { return _value * .3048/4.4482216152605; }

    Damping& operator+= (const Damping& rh) { _value += rh._value; return *this; }
    Damping& operator-= (const Damping& rh) { _value -= rh._value; return *this; }
    Damping& operator*= (const double& rh) { _value *= rh; return *this; }
    Damping& operator/= (const double& rh) { _value /= rh; return *this; }
  };

  // Literal operators
  Damping ENGINEERINGLIBRARY_API operator"" _Nspm (long double val);
  Damping ENGINEERINGLIBRARY_API operator"" _Nspm (unsigned long long val);

  Damping ENGINEERINGLIBRARY_API operator"" _kNspm (long double val);
  Damping ENGINEERINGLIBRARY_API operator"" _kNspm (unsigned long long val);

  Damping ENGINEERINGLIBRARY_API operator"" _lbspin (long double val);
  Damping ENGINEERINGLIBRARY_API operator"" _lbspin (unsigned long long val);

  Damping ENGINEERINGLIBRARY_API operator"" _lbspft (long double val);
  Damping ENGINEERINGLIBRARY_API operator"" _lbspft (unsigned long long val);

  Damping ENGINEERINGLIBRARY_API operator- (const Damping& lh);

  Damping ENGINEERINGLIBRARY_API operator+ (const Damping& lh, const Damping& rh);

  Damping ENGINEERINGLIBRARY_API operator- (const Damping& lh, const Damping& rh);

  Damping ENGINEERINGLIBRARY_API operator* (const Damping& lh, const double& rh);
  Damping ENGINEERINGLIBRARY_API operator* (const double& lh, const Damping& rh);
  Damping ENGINEERINGLIBRARY_API operator* (const class Stiffness& lh, const class Time& rh);
  Damping ENGINEERINGLIBRARY_API operator* (const class Time& lh, const class Stiffness& rh);
  Damping ENGINEERINGLIBRARY_API operator* (const class Mass& lh, const class Frequency& rh);
  Damping ENGINEERINGLIBRARY_API operator* (const class Frequency& lh, const class Mass& rh);

  Damping ENGINEERINGLIBRARY_API operator/ (const Damping& lh, const double& rh);
  double ENGINEERINGLIBRARY_API operator/ (const Damping& lh, const Damping& rh);

  bool ENGINEERINGLIBRARY_API operator== (const Damping& lh, const Damping& rh);
  bool ENGINEERINGLIBRARY_API operator> (const Damping& lh, const Damping& rh);
  bool ENGINEERINGLIBRARY_API operator!= (const Damping& lh, const Damping& rh);
  bool ENGINEERINGLIBRARY_API operator< (const Damping& lh, const Damping& rh);
  bool ENGINEERINGLIBRARY_API operator>= (const Damping& lh, const Damping& rh);
  bool ENGINEERINGLIBRARY_API operator<= (const Damping& lh, const Damping& rh);

};  // namespace eng

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<eng::Damping> : NumTraits<double> {
    typedef eng::Damping Real;
    typedef eng::Damping NonInteger;
    typedef eng::Damping Nested;

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

using eng::operator"" _Nspm;        using eng::operator"" _kNspm;
using eng::operator"" _lbspin;      using eng::operator"" _lbspft;

#endif
