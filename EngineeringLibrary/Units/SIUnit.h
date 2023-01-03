#pragma once

/*****************************************************************/ /**
 * \file  SIUnit.h
 * \brief A base class for all units to give them a uniform interface and
 *          to simplify the implementation where possible. This class may be 
 *          used outside this library raw, however it is not recommended.
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include <cmath>
#include <numeric>

#include <eigen3/Eigen/Core>

/* This macro allows for all explicit specializations of SIUnit to share the 
 *   necessary base functionality.
 *   Each specialization must define type_t as a typedef for the class type
 *     before using this macro.
 *   UnitBaseCOMMON must be used before every other class member except this_t.
 */
#define UnitBaseCOMMON                            \
 public:                                          \
  explicit SIUnit(const double& n = 0) : value_(n) { } \
  double value() const { return value_; }              \
  this_t& operator+=(const this_t& rh) {          \
    value_ += rh.value();                         \
    return *this;                                 \
  }                                               \
  this_t& operator-=(const this_t& rh) {          \
    value_ -= rh.value();                         \
    return *this;                                 \
  }                                               \
  this_t& operator*=(const double& rh) {               \
    value_ *= rh;                                 \
    return *this;                                 \
  }                                               \
  this_t& operator/=(const double& rh) {               \
    value_ /= rh;                                 \
    return *this;                                 \
  }                                               \
                                                  \
 private:                                         \
  double value_;

namespace eng {

  /** A class representing and Unit in the SI system.
   * \class SIUnit
   */
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
  class SIUnit {
   public:
    typedef SIUnit this_t;

    UnitBaseCOMMON
  };

  namespace unit_mgmt {
    inline auto sign = [](const int& n) constexpr {
      return (0 < n) - (n < 0);
    };
    inline auto abs = [](const int& n) constexpr {
      return n < 0 ? -n : n;
    };
    inline auto na = [](const int& a, const int& b, const int& c, const int& d) constexpr { return a * d + b * c; };
    inline auto ns = [](const int& a, const int& b, const int& c, const int& d) constexpr { return a * d - b * c; };
    inline auto d = [](const int&, const int& b, const int&, const int& d) constexpr { return b * d; };
    inline auto numa = [](const int& n1, const int& d1, const int& n2, const int& d2) constexpr {
      int num = na(n1, d1, n2, d2), den = d(n1, d1, n2, d2);
      return sign(num) * sign(den) * abs(num) / std::gcd(num, den);
    };
    inline auto denoma = [](const int& n1, const int& d1, const int& n2, const int& d2) constexpr {
      int num = na(n1, d1, n2, d2), den = d(n1, d1, n2, d2);
      return abs(den) / std::gcd(num, den);
    };
    inline auto nums = [](const int& n1, const int& d1, const int& n2, const int& d2) constexpr {
      int num = ns(n1, d1, n2, d2), den = d(n1, d1, n2, d2);
      return sign(num) * sign(den) * abs(num) / std::gcd(num, den);
    };
    inline auto denoms = [](const int& n1, const int& d1, const int& n2, const int& d2) constexpr {
      int num = ns(n1, d1, n2, d2), den = d(n1, d1, n2, d2);
      return abs(den) / std::gcd(num, den);
    };
  };  // namespace unit_mgmt

  /**
   * UnitBase inversion operator.
   */
  template <int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
            int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>
  operator-(const SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh) {
    return SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>(-lh.value());
  }

  /**
   * UnitBase addition operator.
   */
  template <int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
            int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>
  operator+(const SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh,
            const SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& rh) {
    return SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>(lh.value() + rh.value());
  }

  /**
   * UnitBase subtraction operator.
   */
  template <int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
            int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>
  operator-(const SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh,
            const SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& rh) {
    return SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>(lh.value() - rh.value());
  }

  /**
   * UnitBase multiplication operators.
   */
  template <int MN1, int LN1, int TN1, int CN1, int TeN1, int AN1, int LuN1,
            int MD1, int LD1, int TD1, int CD1, int TeD1, int AD1, int LuD1,
            int MN2, int LN2, int TN2, int CN2, int TeN2, int AN2, int LuN2,
            int MD2, int LD2, int TD2, int CD2, int TeD2, int AD2, int LuD2>
  auto
  operator*(const SIUnit<MN1, LN1, TN1, CN1, TeN1, AN1, LuN1, MD1, LD1, TD1, CD1, TeD1, AD1, LuD1>& lh,
            const SIUnit<MN2, LN2, TN2, CN2, TeN2, AN2, LuN2, MD2, LD2, TD2, CD2, TeD2, AD2, LuD2>& rh) {
    return SIUnit<unit_mgmt::numa(MN1, MD1, MN2, MD2),
                  unit_mgmt::numa(LN1, LD1, LN2, LD2),
                  unit_mgmt::numa(TN1, TD1, TN2, TD2),
                  unit_mgmt::numa(CN1, CD1, CN2, CD2),
                  unit_mgmt::numa(TeN1, TeD1, TeN2, TeD2),
                  unit_mgmt::numa(AN1, AD1, AN2, AD2),
                  unit_mgmt::numa(LuN1, LuD1, LuN2, LuD2),
                  unit_mgmt::denoma(MN1, MD1, MN2, MD2),
                  unit_mgmt::denoma(LN1, LD1, LN2, LD2),
                  unit_mgmt::denoma(TN1, TD1, TN2, TD2),
                  unit_mgmt::denoma(CN1, CD1, CN2, CD2),
                  unit_mgmt::denoma(TeN1, TeD1, TeN2, TeD2),
                  unit_mgmt::denoma(AN1, AD1, AN2, AD2),
                  unit_mgmt::denoma(LuN1, LuD1, LuN2, LuD2)>(lh.value() * rh.value());
  }
  template <int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
            int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>
  operator*(const SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh,
            const double& rh) {
    return SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>(lh.value() * rh);
  }
  template <int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
            int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>
  operator*(const double& lh,
            const SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& rh) {
    return rh * lh;
  }
  template <int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
            int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  double
  operator*(const SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh,
            const SIUnit<-MN, -LN, -TN, -CN, -TeN, -AN, -LuN, MD, LD, TD, CD, TeD, AD, LuD>& rh) {
    return lh.value() * rh.value();
  }

  /**
   * UnitBase division operators.
   */
  template <int MN1, int LN1, int TN1, int CN1, int TeN1, int AN1, int LuN1,
            int MD1, int LD1, int TD1, int CD1, int TeD1, int AD1, int LuD1,
            int MN2, int LN2, int TN2, int CN2, int TeN2, int AN2, int LuN2,
            int MD2, int LD2, int TD2, int CD2, int TeD2, int AD2, int LuD2>
  auto
  operator/(const SIUnit<MN1, LN1, TN1, CN1, TeN1, AN1, LuN1, MD1, LD1, TD1, CD1, TeD1, AD1, LuD1>& lh,
            const SIUnit<MN2, LN2, TN2, CN2, TeN2, AN2, LuN2, MD2, LD2, TD2, CD2, TeD2, AD2, LuD2>& rh) {
    return SIUnit<unit_mgmt::nums(MN1, MD1, MN2, MD2),
                  unit_mgmt::nums(LN1, LD1, LN2, LD2),
                  unit_mgmt::nums(TN1, TD1, TN2, TD2),
                  unit_mgmt::nums(CN1, CD1, CN2, CD2),
                  unit_mgmt::nums(TeN1, TeD1, TeN2, TeD2),
                  unit_mgmt::nums(AN1, AD1, AN2, AD2),
                  unit_mgmt::nums(LuN1, LuD1, LuN2, LuD2),
                  unit_mgmt::denoms(MN1, MD1, MN2, MD2),
                  unit_mgmt::denoms(LN1, LD1, LN2, LD2),
                  unit_mgmt::denoms(TN1, TD1, TN2, TD2),
                  unit_mgmt::denoms(CN1, CD1, CN2, CD2),
                  unit_mgmt::denoms(TeN1, TeD1, TeN2, TeD2),
                  unit_mgmt::denoms(AN1, AD1, AN2, AD2),
                  unit_mgmt::denoms(LuN1, LuD1, LuN2, LuD2)>(lh.value() / rh.value());
  }
  template <int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
            int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>
  operator/(const SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh,
            const double& rh) {
    return SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>(lh.value() / rh);
  }
  template <int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
            int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  SIUnit<-MN, -LN, -TN, -CN, -TeN, -AN, -LuN, MD, LD, TD, CD, TeD, AD, LuD>
  operator/(const double& lh,
            const SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& rh) {
    return SIUnit<-MN, -LN, -TN, -CN, -TeN, -AN, -LuN, MD, LD, TD, CD, TeD, AD, LuD>(lh / rh.value());
  }
  template <int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
            int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  double
  operator/(const SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh,
            const SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& rh) {
    return lh.value() / rh.value();
  }

  /**
   * UnitBase comparison operators.
   */
  namespace internal {
    /* Tests that the numbers differ by less than 100,000 times smaller than 
     * either of them. */
    inline bool fuzzy_equals(const double& lh, const double& rh) {
      auto flh = fabs(lh), frh = fabs(rh);
      return fabs(lh - rh) <= fabs((flh < frh ? flh : frh) * 0.000001);
    }
    /* Tests that lh is greater than rh by an accaptable margin of error. */
    inline bool fuzzy_greater(const double& lh, const double& rh) {
      return lh - rh > ((lh < rh ? lh : rh) * 0.000001);
    }
  };  // namespace internal

  template <int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
            int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  bool operator==(const SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh,
                  const SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& rh) {
    return internal::fuzzy_equals(lh.value(), rh.value());
  }

  template <int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
            int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  bool operator>(const SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh,
                 const SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& rh) {
    return internal::fuzzy_greater(lh.value(), rh.value());
  }

  template <int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
            int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  bool operator!=(const SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh,
                  const SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& rh) {
    return !(lh == rh);
  }

  template <int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
            int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  bool operator<(const SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh,
                 const SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& rh) {
    return rh > lh;
  }

  template <int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
            int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  bool operator>=(const SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh,
                  const SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& rh) {
    return lh > rh || lh == rh;
  }

  template <int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
            int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  bool operator<=(const SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh,
                  const SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& rh) {
    return rh > lh || lh == rh;
  }

  // Mathematical functions
  /* TODO:
   * pow (maybe?)
   */
  template <int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
            int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  inline SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>
  abs(const SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& x) {
    return SIUnit<MN, LN, TN, CN, TeN, AN, LuN,
                  MD, LD, TD, CD, TeD, AD, LuD>(std::fabs(x.value()));
  }

  template <int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
            int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  inline auto
  sqrt(const SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& x) {
    return SIUnit<
        unit_mgmt::numa(MN, MD * 2, 0, 1),
        unit_mgmt::numa(LN, LD * 2, 0, 1),
        unit_mgmt::numa(TN, TD * 2, 0, 1),
        unit_mgmt::numa(CN, CD * 2, 0, 1),
        unit_mgmt::numa(TeN, TeD * 2, 0, 1),
        unit_mgmt::numa(AN, AD * 2, 0, 1),
        unit_mgmt::numa(LuN, LuD * 2, 0, 1),
        unit_mgmt::denoma(MN, MD * 2, 0, 1),
        unit_mgmt::denoma(LN, LD * 2, 0, 1),
        unit_mgmt::denoma(TN, TD * 2, 0, 1),
        unit_mgmt::denoma(CN, CD * 2, 0, 1),
        unit_mgmt::denoma(TeN, TeD * 2, 0, 1),
        unit_mgmt::denoma(AN, AD * 2, 0, 1),
        unit_mgmt::denoma(LuN, LuD * 2, 0, 1)>(std::sqrt(x.value()));
  }

  template <int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
            int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  inline auto
  abs2(const SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& x) {
    return SIUnit<
        unit_mgmt::numa(MN * 2, MD, 0, 1),
        unit_mgmt::numa(LN * 2, LD, 0, 1),
        unit_mgmt::numa(TN * 2, TD, 0, 1),
        unit_mgmt::numa(CN * 2, CD, 0, 1),
        unit_mgmt::numa(TeN * 2, TeD, 0, 1),
        unit_mgmt::numa(AN * 2, AD, 0, 1),
        unit_mgmt::numa(LuN * 2, LuD, 0, 1),
        unit_mgmt::denoma(MN * 2, MD, 0, 1),
        unit_mgmt::denoma(LN * 2, LD, 0, 1),
        unit_mgmt::denoma(TN * 2, TD, 0, 1),
        unit_mgmt::denoma(CN * 2, CD, 0, 1),
        unit_mgmt::denoma(TeN * 2, TeD, 0, 1),
        unit_mgmt::denoma(AN * 2, AD, 0, 1),
        unit_mgmt::denoma(LuN * 2, LuD, 0, 1)>(x.value() * x.value());
  }

  template <int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
            int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  inline auto conj(const SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& x) {
    return x;
  }

  template <int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
            int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  inline auto real(const SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& x) {
    return x;
  }

  template <int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
            int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  inline auto imag(const SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>&) {
    return SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>(0.0);
  }

};  // namespace eng

/* Integration with Eigen. */
namespace Eigen {

  template <int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
            int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  struct NumTraits<eng::SIUnit<MN, LN, TN, CN, TeN, AN, LuN,
                               MD, LD, TD, CD, TeD, AD, LuD>> : NumTraits<double> {
    typedef eng::SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD> Real;
    typedef eng::SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD> NonInteger;
    typedef eng::SIUnit<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD> Nested;

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
