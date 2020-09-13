#ifndef Energy_h_INCLUDED
#define Energy_h_INCLUDED

/*****************************************************************//**
 * \file   Energy.h
 * \brief  An object representing any kind of energy 
 * 
 * 
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "UnitBase.h"

#include <Eigen/Core>

namespace eng {

  /** A representation of any kind of energy
   * \class Energy
   * \addtogroup Units
   */
  class ENGINEERINGLIBRARY_API Energy : public UnitBase {
  public:
    /**
     * \brief Energy constructor
     *
     * \param _Joules the measure of energy in Joules
     */
    explicit Energy(const double _Joules = 0) : UnitBase(_Joules) { }
    Energy(const Energy&) = default;
    ~Energy() = default;

    double J() const { return _value; }
    double kJ() const { return _value * 0.001; }
    double MJ() const { return _value * 0.000'001; }

    double ftlb() const { return _value * 0.737'562'149; }
    double inlb() const { return _value * 8.850'745'8; }
    double BTU() const { return _value * 0.000'947'817'12; }

    Energy& operator+= (const Energy& rh) { _value += rh._value; return *this; }
    Energy& operator-= (const Energy& rh) { _value -= rh._value; return *this; }
    Energy& operator*= (const double& rh) { _value *= rh; return *this; }
    Energy& operator/= (const double& rh) { _value /= rh; return *this; }
  };

  Energy ENGINEERINGLIBRARY_API operator"" _J (long double val);
  Energy ENGINEERINGLIBRARY_API operator"" _J (unsigned long long val);

  Energy ENGINEERINGLIBRARY_API operator"" _kJ (long double val);
  Energy ENGINEERINGLIBRARY_API operator"" _kJ (unsigned long long val);

  Energy ENGINEERINGLIBRARY_API operator"" _MJ (long double val);
  Energy ENGINEERINGLIBRARY_API operator"" _MJ (unsigned long long val);

  Energy ENGINEERINGLIBRARY_API operator"" _ftlb (long double val);
  Energy ENGINEERINGLIBRARY_API operator"" _ftlb (unsigned long long val);

  Energy ENGINEERINGLIBRARY_API operator"" _inlb (long double val);
  Energy ENGINEERINGLIBRARY_API operator"" _inlb (unsigned long long val);

  Energy ENGINEERINGLIBRARY_API operator"" _BTU (long double val);
  Energy ENGINEERINGLIBRARY_API operator"" _BTU (unsigned long long val);

  Energy ENGINEERINGLIBRARY_API operator- (const Energy& lh);

  Energy ENGINEERINGLIBRARY_API operator+ (const Energy& lh, const Energy& rh);

  Energy ENGINEERINGLIBRARY_API operator- (const Energy& lh, const Energy& rh);

  Energy ENGINEERINGLIBRARY_API operator* (const class Force& lh, const class Length& rh);
  Energy ENGINEERINGLIBRARY_API operator* (const class Length& lh, const class Force& rh);
  Energy ENGINEERINGLIBRARY_API operator* (const Energy& lh, const double& rh);
  Energy ENGINEERINGLIBRARY_API operator* (const double& lh, const Energy& rh);

  Energy ENGINEERINGLIBRARY_API operator/ (const Energy& lh, const double& rh);
  double ENGINEERINGLIBRARY_API operator/ (const Energy& lh, const Energy& rh);

  bool ENGINEERINGLIBRARY_API operator== (const Energy& lh, const Energy& rh);
  bool ENGINEERINGLIBRARY_API operator> (const Energy& lh, const Energy& rh);
  bool ENGINEERINGLIBRARY_API operator!= (const Energy& lh, const Energy& rh);
  bool ENGINEERINGLIBRARY_API operator< (const Energy& lh, const Energy& rh);
  bool ENGINEERINGLIBRARY_API operator>= (const Energy& lh, const Energy& rh);
  bool ENGINEERINGLIBRARY_API operator<= (const Energy& lh, const Energy& rh);

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

#endif
