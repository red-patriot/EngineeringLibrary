#pragma once

/*****************************************************************//**
 * \file  Pressure.h
 * \brief Objects representing a pressure exerted over a surface. 
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "UnitBase.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /**
   * \class Pressure A force distributed over an area
   * \addtogroup Units
   */
  template<>
  class SIUnit<1, -1, -2, 0, 0, 0, 0> {
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

  inline Pressure conj(const Pressure& x) { return x; }
  inline Pressure real(const Pressure& x) { return x; }
  inline Pressure imag(const Pressure&) { return 0_Pa; }
}; // namespace eng

/* Integration with Eigen */
namespace Eigen {
  
  template<> struct NumTraits<eng::Pressure> : NumTraits<double> {
    typedef eng::Pressure Real;
    typedef eng::Pressure NonInteger;
    typedef eng::Pressure Nested;

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

using eng::operator"" _Pa;        using eng::operator"" _kPa;
using eng::operator"" _MPa;       using eng::operator"" _GPa;
using eng::operator"" _psi;       using eng::operator"" _ksi;
