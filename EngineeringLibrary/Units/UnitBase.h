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

namespace eng {

  /** An internal base class for any unit type
   * \class UnitBase
   */
  template<int MassNum, int LengthNum, int TimeNum, int CurrentNum, int TemperatureNum, int AmountNum, int LuminousityNum,
    int MassDen=1, int LengthDen=1, int TimeDen=1, int CurrentDen=1, int TemperatureDen=1, int AmountDen=1, int LuminousityDen=1>
  class ENGINEERINGLIBRARY_API UnitBase {
  public:
    /**
     * \brief UnitBase constructor
     * 
     * \param n The stored value 
     */
    explicit UnitBase(const double n) : _value(n) { }
    /**
     * \brief UnitBase virtual destructor
     */
    virtual ~UnitBase() = default;

    /** An internal function which allows for uniformity across all Unit classes
     * \return the stored value
     */
    double value() const { return _value; }

  protected:
    double _value; /**<The internal value which represents a value with units */
  };

  template<typename T>
  inline constexpr T sign(const T& n) {
    return (T(0) < n) - (n < T(0));
  }

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
    UnitBase<sign(MN1*MD2 + MN2*MD1)*sign(MD1*MD2)*std::abs(MN1*MD2 + MN2*MD1)/std::gcd(MN1*MD2 + MN2*MD1, MD1*MD2),
             sign(LN1*LD2 + LN2*LD1)*sign(LD1*LD2)*std::abs(LN1*LD2 + LN2*LD1)/std::gcd(LN1*LD2 + LN2*LD1, LD1*LD2),
             sign(TN1*TD2 + TN2*TD1)*sign(TD1*TD2)*std::abs(TN1*TD2 + TN2*TD1)/std::gcd(TN1*TD2 + TN2*TD1, TD1*TD2),
             sign(CN1*CD2 + CN2*CD1)*sign(CD1*CD2)*std::abs(CN1*CD2 + CN2*CD1)/std::gcd(CN1*CD2 + CN2*CD1, CD1*CD2),
             sign(TeN1*TeD2 + TeN2*TeD1)*sign(TeD1*TeD2)*std::abs(TeN1*TeD2 + TeN2*TeD1)/std::gcd(TeN1*TeD2 + TeN2*TeD1, TeD1*TeD2),
             sign(AN1*AD2 + AN2*AD1)*sign(AD1*AD2)*std::abs(AN1*AD2 + AN2*AD1)/std::gcd(AN1*AD2 + AN2*AD1, AD1*AD2),
             sign(LuN1*LuD2 + LuN2*LuD1)*sign(LuD1*LuD2)*std::abs(LuN1*LuD2 + LuN2*LuD1)/std::gcd(LuN1*LuD2 + LuN2*LuD1, LuD1*LuD2),
             std::abs(MD1*MD2) / std::gcd(MN1*MD2 + MN2*MD1, MD1*MD2),
             std::abs(LD1*LD2) / std::gcd(LN1*LD2 + LN2*LD1, LD1*LD2),
             std::abs(TD1*TD2) / std::gcd(TN1*TD2 + TN2*TD1, TD1*TD2),
             std::abs(CD1*CD2) / std::gcd(CN1*CD2 + CN2*CD1, CD1*CD2),
             std::abs(TeD1*TeD2) / std::gcd(TeN1*TeD2 + TeN2*TeD1, TeD1*TeD2),
             std::abs(AD1*AD2) / std::gcd(AN1*AD2 + AN2*AD1, AD1*AD2),
             std::abs(LuD1*LuD2) / std::gcd(LuN1*LuD2 + LuN2*LuD1, LuD1*LuD2)>
    ENGINEERINGLIBRARY_API operator* (const UnitBase<MN1, LN1, TN1, CN1, TeN1, AN1, LuN1, MD1, LD1, TD1, CD1, TeD1, AD1, LuD1>& lh,
                                      const UnitBase<MN2, LN2, TN2, CN2, TeN2, AN2, LuN2, MD2, LD2, TD2, CD2, TeD2, AD2, LuD2>& rh) {
    return UnitBase(lh.value() * rh.value());
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
    UnitBase<sign(MN1*MD2 - MN2*MD1)*sign(MD1*MD2)*std::abs(MN1*MD2 - MN2*MD1)/std::gcd(MN1*MD2 - MN2*MD1, MD1*MD2),
             sign(LN1*LD2 - LN2*LD1)*sign(LD1*LD2)*std::abs(LN1*LD2 - LN2*LD1)/std::gcd(LN1*LD2 - LN2*LD1, LD1*LD2),
             sign(TN1*TD2 - TN2*TD1)*sign(TD1*TD2)*std::abs(TN1*TD2 - TN2*TD1)/std::gcd(TN1*TD2 - TN2*TD1, TD1*TD2),
             sign(CN1*CD2 - CN2*CD1)*sign(CD1*CD2)*std::abs(CN1*CD2 - CN2*CD1)/std::gcd(CN1*CD2 - CN2*CD1, CD1*CD2),
             sign(TeN1*TeD2 - TeN2*TeD1)*sign(TeD1*TeD2)*std::abs(TeN1*TeD2 - TeN2*TeD1)/std::gcd(TeN1*TeD2 - TeN2*TeD1, TeD1*TeD2),
             sign(AN1*AD2 - AN2*AD1)*sign(AD1*AD2)*std::abs(AN1*AD2 - AN2*AD1)/std::gcd(AN1*AD2 - AN2*AD1, AD1*AD2),
             sign(LuN1*LuD2 - LuN2*LuD1)*sign(LuD1*LuD2)*std::abs(LuN1*LuD2 - LuN2*LuD1)/std::gcd(LuN1*LuD2 - LuN2*LuD1, LuD1*LuD2),
             std::abs(MD1*MD2) / std::gcd(MN1*MD2 - MN2*MD1, MD1*MD2),
             std::abs(LD1*LD2) / std::gcd(LN1*LD2 - LN2*LD1, LD1*LD2),
             std::abs(TD1*TD2) / std::gcd(TN1*TD2 - TN2*TD1, TD1*TD2),
             std::abs(CD1*CD2) / std::gcd(CN1*CD2 - CN2*CD1, CD1*CD2),
             std::abs(TeD1*TeD2) / std::gcd(TeN1*TeD2 - TeN2*TeD1, TeD1*TeD2),
             std::abs(AD1*AD2) / std::gcd(AN1*AD2 - AN2*AD1, AD1*AD2),
             std::abs(LuD1*LuD2) / std::gcd(LuN1*LuD2 - LuN2*LuD1, LuD1*LuD2)>
    ENGINEERINGLIBRARY_API operator* (const UnitBase<MN1, LN1, TN1, CN1, TeN1, AN1, LuN1, MD1, LD1, TD1, CD1, TeD1, AD1, LuD1>& lh,
                                      const UnitBase<MN2, LN2, TN2, CN2, TeN2, AN2, LuN2, MD2, LD2, TD2, CD2, TeD2, AD2, LuD2>& rh) {
    return UnitBase(lh.value() / rh.value());
  }
  template<int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
    int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
    UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>
    ENGINEERINGLIBRARY_API operator/ (const UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh,
                                      const double& rh) {
    return UnitBase(lh.value() / rh);
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

};  // namespace eng

#endif
