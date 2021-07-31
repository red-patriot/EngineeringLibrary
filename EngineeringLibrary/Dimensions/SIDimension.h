#pragma once

/*****************************************************************/ /**
 * \file   SIDimension.h
 * \brief  
 * 
 * 
 * \author bltan
 * \date   July 2021
 *********************************************************************/

#include <cmath>
#include <numeric>

namespace eng {

  template <int MassNum,
            int LengthNum,
            int TimeNum,
            int CurrentNum,
            int TemperatureNum,
            int AmountNum,
            int LuminousityNum,
            int MassDen = 1,
            int LengthDen = 1,
            int TimeDen = 1,
            int CurrentDen = 1,
            int TemperatureDen = 1,
            int AmountDen = 1,
            int LuminousityDen = 1>
  class SIDimension { };

  namespace dim_mgmt {
    auto sign = [](const int& n) constexpr {
      return (0 < n) - (n < 0);
    };
    auto abs = [](const int& n) constexpr {
      return n < 0 ? -n : n;
    };
    auto na = [](const int& a, const int& b, const int& c, const int& d) constexpr { return a * d + b * c; };
    auto ns = [](const int& a, const int& b, const int& c, const int& d) constexpr { return a * d - b * c; };
    auto d = [](const int&, const int& b, const int&, const int& d) constexpr { return b * d; };
    auto numa = [](const int& n1, const int& d1, const int& n2, const int& d2) constexpr {
      int num = na(n1, d1, n2, d2), den = d(n1, d1, n2, d2);
      return sign(num) * sign(den) * abs(num) / std::gcd(num, den);
    };
    auto denoma = [](const int& n1, const int& d1, const int& n2, const int& d2) constexpr {
      int num = na(n1, d1, n2, d2), den = d(n1, d1, n2, d2);
      return abs(den) / std::gcd(num, den);
    };
    auto nums = [](const int& n1, const int& d1, const int& n2, const int& d2) constexpr {
      int num = ns(n1, d1, n2, d2), den = d(n1, d1, n2, d2);
      return sign(num) * sign(den) * abs(num) / std::gcd(num, den);
    };
    auto denoms = [](const int& n1, const int& d1, const int& n2, const int& d2) constexpr {
      int num = ns(n1, d1, n2, d2), den = d(n1, d1, n2, d2);
      return abs(den) / std::gcd(num, den);
    };
  };  // namespace dim_mgmt

// These macros are to avoid repetitive typing of this pattern repeatedly.
#define SIDimensionsTemplateDeclaration(n) int MN##n, int LN##n, int TN##n, int CN##n, int TeN##n, int AN##n, int LuN##n, int MD##n, int LD##n, int TD##n, int CD##n, int TeD##n, int AD##n, int LuD##n
#define SIDimensionsTemplateValue(n) MN##n, LN##n, TN##n, CN##n, TeN##n, AN##n, LuN##n, MD##n, LD##n, TD##n, CD##n, TeD##n, AD##n, LuD##n

  template <typename T, typename U>
  struct addition {
    using type = void;
  };
  template <SIDimensionsTemplateDeclaration(1)>
  struct addition<SIDimension<SIDimensionsTemplateValue(1)>,
                  SIDimension<SIDimensionsTemplateValue(1)>> {
    using type = SIDimension<SIDimensionsTemplateValue(1)>;
  };

  template <typename T, typename U>
  struct multiplication {
    using type = void;
  };
  template <SIDimensionsTemplateDeclaration(1),
            SIDimensionsTemplateDeclaration(2)>
  struct multiplication<SIDimension<SIDimensionsTemplateValue(1)>,
                        SIDimension<SIDimensionsTemplateValue(2)>> {
    using type = SIDimension<dim_mgmt::numa(MN1, MD1, MN2, MD2),
                             dim_mgmt::numa(LN1, LD1, LN2, LD2),
                             dim_mgmt::numa(TN1, TD1, TN2, TD2),
                             dim_mgmt::numa(CN1, CD1, CN2, CD2),
                             dim_mgmt::numa(TeN1, TeD1, TeN2, TeD2),
                             dim_mgmt::numa(AN1, AD1, AN2, AD2),
                             dim_mgmt::numa(LuN1, LuD1, LuN2, LuD2),
                             dim_mgmt::denoma(MN1, MD1, MN2, MD2),
                             dim_mgmt::denoma(LN1, LD1, LN2, LD2),
                             dim_mgmt::denoma(TN1, TD1, TN2, TD2),
                             dim_mgmt::denoma(CN1, CD1, CN2, CD2),
                             dim_mgmt::denoma(TeN1, TeD1, TeN2, TeD2),
                             dim_mgmt::denoma(AN1, AD1, AN2, AD2),
                             dim_mgmt::denoma(LuN1, LuD1, LuN2, LuD2)>;
  };

  template <typename T, typename U>
  struct division {
    using type = void;
  };
  template <SIDimensionsTemplateDeclaration(1),
            SIDimensionsTemplateDeclaration(2)>
  struct division<SIDimension<SIDimensionsTemplateValue(1)>,
                  SIDimension<SIDimensionsTemplateValue(2)>> {
    using type = SIDimension<dim_mgmt::nums(MN1, MD1, MN2, MD2),
                             dim_mgmt::nums(LN1, LD1, LN2, LD2),
                             dim_mgmt::nums(TN1, TD1, TN2, TD2),
                             dim_mgmt::nums(CN1, CD1, CN2, CD2),
                             dim_mgmt::nums(TeN1, TeD1, TeN2, TeD2),
                             dim_mgmt::nums(AN1, AD1, AN2, AD2),
                             dim_mgmt::nums(LuN1, LuD1, LuN2, LuD2),
                             dim_mgmt::denoms(MN1, MD1, MN2, MD2),
                             dim_mgmt::denoms(LN1, LD1, LN2, LD2),
                             dim_mgmt::denoms(TN1, TD1, TN2, TD2),
                             dim_mgmt::denoms(CN1, CD1, CN2, CD2),
                             dim_mgmt::denoms(TeN1, TeD1, TeN2, TeD2),
                             dim_mgmt::denoms(AN1, AD1, AN2, AD2),
                             dim_mgmt::denoms(LuN1, LuD1, LuN2, LuD2)>;
  };

  template <typename T, typename U>
  using addition_t = typename addition<T, U>::type;

  template <typename T, typename U>
  using subtraction_t = typename addition<T, U>::type;

  template <typename T, typename U>
  using multiplication_t = typename multiplication<T, U>::type;

  template <typename T, typename U>
  using division_t = typename division<T, U>::type;

};  // namespace eng
