#pragma once

/*****************************************************************//**
 * \file   Viscosity.h
 * \brief  Objects representing fluid viscosity
 *
 * \author bltan
 * \date   December 2020
 *********************************************************************/

#include "UnitBase.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /**
   * \class DViscosity
   * \addtogroup Units
   */
  template<>
  class SIUnit<1, -1, -1, 0, 0, 0, 0> {
   public:
    typedef SIUnit<1, -1, -1, 0, 0, 0, 0> this_t;
    UnitBaseCOMMON
   public:
    double kgpms() const { return value_; }
    double Pas() const { return value_; }
    double Nspm2() const { return value_; }
    double P() const { return value_ * 10; }

    double lbspft2() const { return value_ * 0.671968900; }
  };

  using DViscosity = SIUnit<1, -1, -1, 0, 0, 0, 0>;

  DViscosity operator""_kgpms(long double val);
  DViscosity operator""_kgpms(unsigned long long val);

  DViscosity operator""_Pas(long double val);
  DViscosity operator""_Pas(unsigned long long val);

  DViscosity operator""_Nspm2(long double val);
  DViscosity operator""_Nspm2(unsigned long long val);

  DViscosity operator""_P(long double val);
  DViscosity operator""_P(unsigned long long val);

  DViscosity operator""_lbspft2(long double val);
  DViscosity operator""_lbspft2(unsigned long long val);

  /**
   * \class KViscosity
   * \addtogroup Units
   */
  template<>
  class SIUnit<0, 2, -1, 0, 0, 0, 0> {
    typedef SIUnit<0, 2, -1, 0, 0, 0, 0> this_t;
    UnitBaseCOMMON
  public:
    double m2ps() const { return value_; }
    double St() const { return value_ * 10'000.0; }
    
    double ft2ps() const { return value_ * 10.763'91; }
  };

  using  KViscosity = SIUnit<0, 2, -1, 0, 0, 0, 0>;

  KViscosity operator""_m2ps(long double val);
  KViscosity operator""_m2ps(unsigned long long val);

  KViscosity operator""_St(long double val);
  KViscosity operator""_St(unsigned long long val);

  KViscosity operator""_ft2ps(long double val);
  KViscosity operator""_ft2ps(unsigned long long val);

};  // namespace eng

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<eng::DViscosity> : NumTraits<double> {
    typedef eng::DViscosity Real;
    typedef eng::DViscosity NonInteger;
    typedef eng::DViscosity Nested;

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

  template<> struct NumTraits<eng::KViscosity> : NumTraits<double> {
    typedef eng::KViscosity Real;
    typedef eng::KViscosity NonInteger;
    typedef eng::KViscosity Nested;

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

using eng::operator""_kgpms;        using eng::operator""_Pas;
using eng::operator""_Nspm2;        using eng::operator""_P;
using eng::operator""_lbspft2;

using eng::operator""_m2ps;         using eng::operator""_St;
using eng::operator""_ft2ps;
