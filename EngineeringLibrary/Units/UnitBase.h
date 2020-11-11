#ifndef Unit_Base_h_INCLUDED
#define Unit_Base_h_INCLUDED

/*****************************************************************//**
 * \file  UnitBase.h
 * \brief A base class for all units to give them a uniform interface and
 *          to simplify the implementation where possible. This class is not 
 *          available for use outside this library
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include <cmath>
#include <numeric>

#include "../EngineeringExport.h"

/* This macro allows for all explicit specializations of UnitBase to share the 
 *   necessary base functionality.
 *   Each specialization must define type_t as a typedef for the class type
 *     before using this macro.
 *   UnitBaseCOMMON must be used before every other class member except this_t.
 */
#define UnitBaseCOMMON public:                                                 \
    explicit UnitBase(const double& n) : _value(n) { }                         \
    ~UnitBase() = default;                                                     \
    double value() const { return _value; }                                    \
    this_t& operator+= (const this_t& rh) {_value += rh.value(); return *this;}\
    this_t& operator-= (const this_t& rh) {_value -= rh.value(); return *this;}\
    this_t& operator*= (const double& rh) {_value *= rh; return *this;}        \
    this_t& operator/= (const double& rh) {_value /= rh; return *this;}        \
  protected:                                                                   \
    double _value;

namespace eng {

  /** An internal base class for any unit type
   * \class UnitBase
   */
  template<int MassNum, int LengthNum, int TimeNum, int CurrentNum, int TemperatureNum, int AmountNum, int LuminousityNum,
    int MassDen=1, int LengthDen=1, int TimeDen=1, int CurrentDen=1, int TemperatureDen=1, int AmountDen=1, int LuminousityDen=1>
  class ENGINEERINGLIBRARY_API UnitBase {
    typedef UnitBase this_t;
    UnitBaseCOMMON
  };

  auto _sign = [](const int& n) constexpr { 
    return (0 < n) - (n < 0); 
  };
  auto _abs = [](const int& n) constexpr { 
    return n < 0 ? -n : n; 
  };
  auto _na = [](const int& a, const int& b, const int& c, const int& d) constexpr { return a*d + b*c; };
  auto _ns = [](const int& a, const int& b, const int& c, const int& d) constexpr { return a*d - b*c; };
  auto _d = [](const int&, const int& b, const int&, const int& d) constexpr { return b*d; };
  auto _numa = [](const int& n1, const int& d1, const int& n2, const int& d2) constexpr {
    int num = _na(n1, d1, n2, d2), den = _d(n1, d1, n2, d2);
    return _sign(num) * _sign(den) * _abs(num)/std::gcd(num, den); };
  auto _denoma = [](const int& n1, const int& d1, const int& n2, const int& d2) constexpr {
    int num = _na(n1, d1, n2, d2), den = _d(n1, d1, n2, d2);
    return _abs(den)/std::gcd(num, den);
  };
  auto _nums = [](const int& n1, const int& d1, const int& n2, const int& d2) constexpr {
    int num = _ns(n1, d1, n2, d2), den = _d(n1, d1, n2, d2);
    return _sign(num) * _sign(den) * _abs(num)/std::gcd(num, den); };
  auto _denoms = [](const int& n1, const int& d1, const int& n2, const int& d2) constexpr {
    int num = _ns(n1, d1, n2, d2), den = _d(n1, d1, n2, d2);
    return _abs(den)/std::gcd(num, den);
  };

  /**
   * UnitBase inversion operator.
   */
  template<int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
    int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
    UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>
    ENGINEERINGLIBRARY_API operator- (const UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh) {
    return UnitBase(-lh.value());
  }

  /**
   * UnitBase addition operator.
   */
  template<int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
    int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
    UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>
    ENGINEERINGLIBRARY_API operator+ (const UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh,
                                      const UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& rh) {
    return UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>(lh.value() + rh.value());
  }

  /**
   * UnitBase subtraction operator.
   */
  template<int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
    int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
    UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>
    ENGINEERINGLIBRARY_API operator- (const UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh,
                                      const UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& rh) {
    return UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>(lh.value() - rh.value());
  }

  /**
   * UnitBase multiplication operators.
   */
  template<int MN1, int LN1, int TN1, int CN1, int TeN1, int AN1, int LuN1,
    int MD1, int LD1, int TD1, int CD1, int TeD1, int AD1, int LuD1,
    int MN2, int LN2, int TN2, int CN2, int TeN2, int AN2, int LuN2,
    int MD2, int LD2, int TD2, int CD2, int TeD2, int AD2, int LuD2>
    auto
    ENGINEERINGLIBRARY_API operator* (const UnitBase<MN1, LN1, TN1, CN1, TeN1, AN1, LuN1, MD1, LD1, TD1, CD1, TeD1, AD1, LuD1>& lh,
                                      const UnitBase<MN2, LN2, TN2, CN2, TeN2, AN2, LuN2, MD2, LD2, TD2, CD2, TeD2, AD2, LuD2>& rh) {
    return UnitBase<_numa(MN1, MD1, MN2, MD2),
      _numa(LN1, LD1, LN2, LD2),
      _numa(TN1, TD1, TN1, TD2),
      _numa(CN1, CD1, CN2, CD2),
      _numa(TeN1, TeD1, TeN2, TeD2),
      _numa(AN1, AD1, AN2, AD2),
      _numa(LuN1, LuD1, LuN2, LuD2),
      _denoma(MN1, MD1, MN2, MD2),
      _denoma(LN1, LD1, LN2, LD2),
      _denoma(TN1, TD1, TN1, TD2),
      _denoma(CN1, CD1, CN2, CD2),
      _denoma(TeN1, TeD1, TeN2, TeD2),
      _denoma(AN1, AD1, AN2, AD2),
      _denoma(LuN1, LuD1, LuN2, LuD2)>(lh.value() * rh.value());
  }
  template<int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
    int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
    UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>
    ENGINEERINGLIBRARY_API operator* (const UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh,
                                      const double& rh) {
    return UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>(lh.value() * rh);
  }
  template<int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
    int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
    UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>
    ENGINEERINGLIBRARY_API operator* (const double& lh,
                                      const UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& rh) {
    return rh * lh;
  }

  /**
   * UnitBase division operators.
   */
  template<int MN1, int LN1, int TN1, int CN1, int TeN1, int AN1, int LuN1,
    int MD1, int LD1, int TD1, int CD1, int TeD1, int AD1, int LuD1,
    int MN2, int LN2, int TN2, int CN2, int TeN2, int AN2, int LuN2,
    int MD2, int LD2, int TD2, int CD2, int TeD2, int AD2, int LuD2>
    auto
    ENGINEERINGLIBRARY_API operator/ (const UnitBase<MN1, LN1, TN1, CN1, TeN1, AN1, LuN1, MD1, LD1, TD1, CD1, TeD1, AD1, LuD1>& lh,
                                      const UnitBase<MN2, LN2, TN2, CN2, TeN2, AN2, LuN2, MD2, LD2, TD2, CD2, TeD2, AD2, LuD2>& rh) {
    return UnitBase<_nums(MN1, MD1, MN2, MD2),
      _nums(LN1, LD1, LN2, LD2),
      _nums(TN1, TD1, TN1, TD2),
      _nums(CN1, CD1, CN2, CD2),
      _nums(TeN1, TeD1, TeN2, TeD2),
      _nums(AN1, AD1, AN2, AD2),
      _nums(LuN1, LuD1, LuN2, LuD2),
      _denoms(MN1, MD1, MN2, MD2),
      _denoms(LN1, LD1, LN2, LD2),
      _denoms(TN1, TD1, TN1, TD2),
      _denoms(CN1, CD1, CN2, CD2),
      _denoms(TeN1, TeD1, TeN2, TeD2),
      _denoms(AN1, AD1, AN2, AD2),
      _denoms(LuN1, LuD1, LuN2, LuD2)>(lh.value() / rh.value());
  }
  template<int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
    int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
    UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>
    ENGINEERINGLIBRARY_API operator/ (const UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh,
                                      const double& rh) {
    return UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>(lh.value() / rh);
  }
  template<int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
    int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
    double
    ENGINEERINGLIBRARY_API operator/ (const UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh,
                                      const UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& rh) {
    return lh.value() / rh.value();
  }

  /**
   * UnitBase comparison operators.
   */
  template<int MN1, int LN1, int TN1, int CN1, int TeN1, int AN1, int LuN1,
    int MD1, int LD1, int TD1, int CD1, int TeD1, int AD1, int LuD1,
    int MN2, int LN2, int TN2, int CN2, int TeN2, int AN2, int LuN2,
    int MD2, int LD2, int TD2, int CD2, int TeD2, int AD2, int LuD2>
    bool ENGINEERINGLIBRARY_API operator== (const UnitBase<MN1, LN1, TN1, CN1, TeN1, AN1, LuN1, MD1, LD1, TD1, CD1, TeD1, AD1, LuD1>& lh,
                                            const UnitBase<MN2, LN2, TN2, CN2, TeN2, AN2, LuN2, MD2, LD2, TD2, CD2, TeD2, AD2, LuD2>& rh) {
    return MN1 == MN2 &&
      LN1 == LN2 &&
      TN1 == TN2 &&
      CN1 == CN2 &&
      TeN1 == TeN2 &&
      AN1 == AN2 &&
      LuN1 == LuN2 &&
      MD1 == MD2 &&
      LD1 == LD2 &&
      TD1 == TD2 &&
      CD1 == CD2 &&
      TeD1 == TeD2 &&
      AD1 == AD2 &&
      LuD1 == LuD2 &&
      lh.value() == rh.value();
  }

  template<int MN1, int LN1, int TN1, int CN1, int TeN1, int AN1, int LuN1,
    int MD1, int LD1, int TD1, int CD1, int TeD1, int AD1, int LuD1,
    int MN2, int LN2, int TN2, int CN2, int TeN2, int AN2, int LuN2,
    int MD2, int LD2, int TD2, int CD2, int TeD2, int AD2, int LuD2>
    bool ENGINEERINGLIBRARY_API operator> (const UnitBase<MN1, LN1, TN1, CN1, TeN1, AN1, LuN1, MD1, LD1, TD1, CD1, TeD1, AD1, LuD1>& lh,
                                           const UnitBase<MN2, LN2, TN2, CN2, TeN2, AN2, LuN2, MD2, LD2, TD2, CD2, TeD2, AD2, LuD2>& rh) {
    return MN1 == MN2 &&
      LN1 == LN2 &&
      TN1 == TN2 &&
      CN1 == CN2 &&
      TeN1 == TeN2 &&
      AN1 == AN2 &&
      LuN1 == LuN2 &&
      MD1 == MD2 &&
      LD1 == LD2 &&
      TD1 == TD2 &&
      CD1 == CD2 &&
      TeD1 == TeD2 &&
      AD1 == AD2 &&
      LuD1 == LuD2 &&
      lh.value() > rh.value();
  }

  template<int MN1, int LN1, int TN1, int CN1, int TeN1, int AN1, int LuN1,
    int MD1, int LD1, int TD1, int CD1, int TeD1, int AD1, int LuD1,
    int MN2, int LN2, int TN2, int CN2, int TeN2, int AN2, int LuN2,
    int MD2, int LD2, int TD2, int CD2, int TeD2, int AD2, int LuD2>
    bool ENGINEERINGLIBRARY_API operator!= (const UnitBase<MN1, LN1, TN1, CN1, TeN1, AN1, LuN1, MD1, LD1, TD1, CD1, TeD1, AD1, LuD1>& lh,
                                            const UnitBase<MN2, LN2, TN2, CN2, TeN2, AN2, LuN2, MD2, LD2, TD2, CD2, TeD2, AD2, LuD2>& rh) {
    return !(lh == rh);
  }

  template<int MN1, int LN1, int TN1, int CN1, int TeN1, int AN1, int LuN1,
    int MD1, int LD1, int TD1, int CD1, int TeD1, int AD1, int LuD1,
    int MN2, int LN2, int TN2, int CN2, int TeN2, int AN2, int LuN2,
    int MD2, int LD2, int TD2, int CD2, int TeD2, int AD2, int LuD2>
    bool ENGINEERINGLIBRARY_API operator< (const UnitBase<MN1, LN1, TN1, CN1, TeN1, AN1, LuN1, MD1, LD1, TD1, CD1, TeD1, AD1, LuD1>& lh,
                                           const UnitBase<MN2, LN2, TN2, CN2, TeN2, AN2, LuN2, MD2, LD2, TD2, CD2, TeD2, AD2, LuD2>& rh) {
    return rh > lh;
  }

  template<int MN1, int LN1, int TN1, int CN1, int TeN1, int AN1, int LuN1,
    int MD1, int LD1, int TD1, int CD1, int TeD1, int AD1, int LuD1,
    int MN2, int LN2, int TN2, int CN2, int TeN2, int AN2, int LuN2,
    int MD2, int LD2, int TD2, int CD2, int TeD2, int AD2, int LuD2>
    bool ENGINEERINGLIBRARY_API operator>= (const UnitBase<MN1, LN1, TN1, CN1, TeN1, AN1, LuN1, MD1, LD1, TD1, CD1, TeD1, AD1, LuD1>& lh,
                                            const UnitBase<MN2, LN2, TN2, CN2, TeN2, AN2, LuN2, MD2, LD2, TD2, CD2, TeD2, AD2, LuD2>& rh) {
    return lh > rh || lh == rh;
  }

  template<int MN1, int LN1, int TN1, int CN1, int TeN1, int AN1, int LuN1,
    int MD1, int LD1, int TD1, int CD1, int TeD1, int AD1, int LuD1,
    int MN2, int LN2, int TN2, int CN2, int TeN2, int AN2, int LuN2,
    int MD2, int LD2, int TD2, int CD2, int TeD2, int AD2, int LuD2>
    bool ENGINEERINGLIBRARY_API operator<= (const UnitBase<MN1, LN1, TN1, CN1, TeN1, AN1, LuN1, MD1, LD1, TD1, CD1, TeD1, AD1, LuD1>& lh,
                                            const UnitBase<MN2, LN2, TN2, CN2, TeN2, AN2, LuN2, MD2, LD2, TD2, CD2, TeD2, AD2, LuD2>& rh) {
    return rh > lh || lh == rh;
  }

  template<int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
    int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
    inline UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>
    ENGINEERINGLIBRARY_API conj(const UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& x) { 
    return x; 
  }
  template<int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
    int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
    inline UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>
    ENGINEERINGLIBRARY_API real(const UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& x) {
    return x;
  }
  template<int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
    int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
    inline UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>
    ENGINEERINGLIBRARY_API imag(const UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& x) {
    return UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>(0);
  }
};  // namespace eng

#endif
