#pragma once

/*****************************************************************//**
 * \file   Energy.h
 * \brief  An object representing any kind of energy 
 * 
 * 
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "UnitBase.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /** A representation of any kind of energy
   * \class Energy
   * \addtogroup Units
   */
  template<>
  class UnitBase<1, 2, -2, 0, 0, 0, 0> {
    typedef UnitBase<1, 2, -2, 0, 0, 0, 0> this_t;
    UnitBaseCOMMON
  public:
    double J() const { return _value; }
    double kJ() const { return _value * 0.001; }
    double MJ() const { return _value * 0.000'001; }

    double Nm() const { return _value; }
    double kNm() const { return _value * 0.001; }
    double Nmm() const { return _value * 1000.0; }

    double ftlb() const { return _value * 0.737'562'149; }
    double inlb() const { return _value * 8.850'745'8; }
    double BTU() const { return _value * 0.000'947'817'12; }

    double lbft() const { return _value * 0.737'562'149; }
    double lbin() const { return _value * 8.850'745'8; }
  };

  using Energy = UnitBase<1, 2, -2, 0, 0, 0, 0>;
  using Torque = UnitBase<1, 2, -2, 0, 0, 0, 0>;

  Energy operator"" _J (long double val);
  Energy operator"" _J (unsigned long long val);

  Energy operator"" _kJ (long double val);
  Energy operator"" _kJ (unsigned long long val);

  Energy operator"" _MJ (long double val);
  Energy operator"" _MJ (unsigned long long val);

  Energy operator"" _ftlb (long double val);
  Energy operator"" _ftlb (unsigned long long val);

  Energy operator"" _inlb (long double val);
  Energy operator"" _inlb (unsigned long long val);

  Energy operator"" _BTU (long double val);
  Energy operator"" _BTU (unsigned long long val);

}; // namespace eng

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<eng::Energy> : NumTraits<double> {
    typedef eng::Energy Real;
    typedef eng::Energy NonInteger;
    typedef eng::Energy Nested;

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

using eng::operator"" _J;        using eng::operator"" _kJ;
using eng::operator"" _MJ;
using eng::operator"" _ftlb;     using eng::operator"" _inlb;
