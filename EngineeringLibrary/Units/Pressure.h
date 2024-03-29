#pragma once

/*****************************************************************//**
 * \file  Pressure.h
 * \brief Objects representing a pressure exerted over a surface. 
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "SIUnit.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /**
   * \class Pressure
   * \addtogroup Units
   */
  template<>
  class SIUnit<1, -1, -2, 0, 0, 0, 0> {
   public:
    typedef SIUnit<1, -1, -2, 0, 0, 0, 0> this_t;
    UnitBaseCOMMON
   public:
    double Pa() const { return value_; }
    double kPa() const { return value_ * 0.001; }
    double MPa() const { return value_ * 0.000'001; }
    double GPa() const { return value_ * 0.000'000'001; }

    double psi() const { return value_ * 0.000'145'037'737'796'858'691'163; }
    double ksi() const { return value_ * 0.000'000'145'037'737'796'858'691; }
  };

  using Pressure = SIUnit<1, -1, -2, 0, 0, 0, 0>;

  // Literal operators
  Pressure operator"" _Pa (long double val);
  Pressure operator"" _Pa (unsigned long long val);

  Pressure operator"" _kPa (long double val);
  Pressure operator"" _kPa (unsigned long long val);

  Pressure operator"" _MPa (long double val);
  Pressure operator"" _MPa (unsigned long long val);

  Pressure operator"" _GPa (long double val);
  Pressure operator"" _GPa (unsigned long long val);

  Pressure operator"" _psi (long double val);
  Pressure operator"" _psi (unsigned long long val);

  Pressure operator"" _ksi (long double val);
  Pressure operator"" _ksi (unsigned long long val);

}; // namespace eng

using eng::operator"" _Pa;        using eng::operator"" _kPa;
using eng::operator"" _MPa;       using eng::operator"" _GPa;
using eng::operator"" _psi;       using eng::operator"" _ksi;
