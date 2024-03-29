#pragma once

/*****************************************************************//**
 * \file   Energy.h
 * \brief  An object representing any kind of energy 
 * 
 * 
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "SIUnit.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /**
   * \class Energy
   * \addtogroup Units
   */
  template<>
  class SIUnit<1, 2, -2, 0, 0, 0, 0> {
   public:
    typedef SIUnit<1, 2, -2, 0, 0, 0, 0> this_t;
    UnitBaseCOMMON
   public:
    double J() const { return value_; }
    double kJ() const { return value_ * 0.001; }
    double MJ() const { return value_ * 0.000'001; }

    double Nm() const { return value_; }
    double kNm() const { return value_ * 0.001; }
    double Nmm() const { return value_ * 1000.0; }

    double ftlb() const { return value_ * 0.737'562'149; }
    double inlb() const { return value_ * 8.850'745'8; }
    double BTU() const { return value_ * 0.000'947'817'12; }

    double lbft() const { return value_ * 0.737'562'149; }
    double lbin() const { return value_ * 8.850'745'8; }
  };

  using Energy = SIUnit<1, 2, -2, 0, 0, 0, 0>;
  using Torque = SIUnit<1, 2, -2, 0, 0, 0, 0>;

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

using eng::operator"" _J;        using eng::operator"" _kJ;
using eng::operator"" _MJ;
using eng::operator"" _ftlb;     using eng::operator"" _inlb;
