#ifndef Torque_h_INCLUDED
#define Torque_h_INCLUDED

/*****************************************************************//**
 * \file   Torque.h
 * \brief  Objects representing Torques and Moments of Force
 *
 *
 * \author bltan
 * \date   September 2020
 *********************************************************************/

#include "UnitBase.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /** A representation of a Torque or Moment of Force
   * \class Torque
   * \addtogroup Units
   */
  class Torque : public UnitBase<1, 2, -2, 0, 0, 0, 0> {
  public:
    /**
     * \brief Torque constructor
     * 
     * \param _Newtonmeters the measure of Torque in Newton*meters
     */
    explicit Torque(const double _Newtonmeters=0) : UnitBase(_Newtonmeters) { }
    Torque(const UnitBase<1, 2, -2, 0, 0, 0, 0>& b) : UnitBase(b) { }
    ~Torque() = default;

    double Nm() const { return _value; }
    double kNm() const { return _value * 0.001; }
    double Nmm() const { return _value * 1000.0; }

    double lbft() const { return _value * 0.737'562'149; }
    double lbin() const { return _value * 8.850'745'8; }

    // Explicitly delete the Energy units so they cannot accidentally be used
    double J() const = delete;
    double kJ() const = delete;
    double MJ() const = delete;

    double ftlb() const = delete;
    double inlb() const = delete;
    double BTU() const = delete;
   
    Torque& operator+= (const Torque& rh) { _value += rh._value; return *this; }
    Torque& operator-= (const Torque& rh) { _value -= rh._value; return *this; }
    Torque& operator*= (const double& rh) { _value *= rh; return *this; }
    Torque& operator/= (const double& rh) { _value /= rh; return *this; }
  };

  Torque operator"" _Nm (long double val);
  Torque operator"" _Nm (unsigned long long val);

  Torque operator"" _kNm (long double val);
  Torque operator"" _kNm (unsigned long long val);

  Torque operator"" _Nmm (long double val);
  Torque operator"" _Nmm (unsigned long long val);

  Torque operator"" _lbft (long double val);
  Torque operator"" _lbft (unsigned long long val);

  Torque operator"" _lbin (long double val);
  Torque operator"" _lbin (unsigned long long val);

  inline Torque conj(const Torque& x) { return x; }
  inline Torque real(const Torque& x) { return x; }
  inline Torque imag(const Torque&) { return 0_Nm; }

  // Some conventions use "Moment" istead of "Torque"
  using Moment = Torque;

  // Torques are commonly used as vectors, so provide some vectors for convenience
  using Torque2d = Eigen::Matrix<Torque, 1, 2>;
  using Torque3d = Eigen::Matrix<Torque, 1, 3>;

  using Moment2d = Eigen::Matrix<Moment, 1, 2>;
  using Moment3d = Eigen::Matrix<Moment, 1, 3>;

};  // namespace eng

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<eng::Torque> : NumTraits<double> {
    typedef eng::Torque Real;
    typedef eng::Torque NonInteger;
    typedef eng::Torque Nested;

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

using eng::operator"" _Nm;        using eng::operator"" _kNm;
using eng::operator"" _Nmm;       
using eng::operator"" _lbft;      using eng::operator"" _lbin;

#endif
