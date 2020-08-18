#ifndef Area_h_INCLUDED
#define Area_h_INCLUDED

/*****************************************************************//**
 * \file  Area.h
 * \brief An object representing any 2D Area.
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "UnitBase.h"

#include <Eigen/Core>

namespace eng {

  class SecondMomentOfArea;
  class Volume;
  class Length;

  /**
   * \class Area A 2D geometry
   */
  class ENGINEERINGLIBRARY_API Area : public UnitBase {
  public:
    /**
     * \brief Construct an Area
     * 
     * \param _meters2 The meaasure of the area in meters^2
     */
    explicit Area(const double meters2 = 0) : UnitBase(meters2) { }
    Area(const Area&) = default;
    ~Area() = default;

    double mm2() const { return _value * 1'000'000; }
    double cm2() const { return _value * 10'000; }
    double m2() const { return _value; }

    double in2() const { return _value * 10'000/(6.4516); }
    double ft2() const { return _value * 10'000/(929.0304); }

    Area& operator+= (const Area& rh) { _value += rh._value; return *this; }
    Area& operator-= (const Area& rh) { _value -= rh._value; return *this; }
    Area& operator*= (const double& rh) { _value *= rh; return *this; }
    Area& operator/= (const double& rh) { _value /= rh; return *this; }
  };

  Area ENGINEERINGLIBRARY_API operator"" _mm2(long double val);
  Area ENGINEERINGLIBRARY_API operator"" _mm2(unsigned long long val);

  Area ENGINEERINGLIBRARY_API operator"" _cm2(long double val);
  Area ENGINEERINGLIBRARY_API operator"" _cm2(unsigned long long val);

  Area ENGINEERINGLIBRARY_API operator"" _m2(long double val);
  Area ENGINEERINGLIBRARY_API operator"" _m2(unsigned long long val);

  Area ENGINEERINGLIBRARY_API operator"" _in2(long double val);
  Area ENGINEERINGLIBRARY_API operator"" _in2(unsigned long long val);

  Area ENGINEERINGLIBRARY_API operator"" _ft2(long double val);
  Area ENGINEERINGLIBRARY_API operator"" _ft2(unsigned long long val);

  Area ENGINEERINGLIBRARY_API operator- (const Area& lh);
  
  Area ENGINEERINGLIBRARY_API operator+ (const Area& lh, const Area& rh);

  Area ENGINEERINGLIBRARY_API operator- (const Area& lh, const Area& rh);

  Area ENGINEERINGLIBRARY_API operator* (const Length& lh, const Length& rh);
  Area ENGINEERINGLIBRARY_API operator* (const Area& lh, const double& n);
  Area ENGINEERINGLIBRARY_API operator* (const double& n, const Area& rh);

  Area ENGINEERINGLIBRARY_API operator/ (const Volume& lh, const Length& rh);
  Area ENGINEERINGLIBRARY_API operator/ (const SecondMomentOfArea& lh, const Area& rh);
  Area ENGINEERINGLIBRARY_API operator/ (const Area& lh, const double& n);
  double ENGINEERINGLIBRARY_API operator/ (const Area& lh, const Area& rh);

  bool ENGINEERINGLIBRARY_API operator== (const Area& lh, const Area& rh);
  bool ENGINEERINGLIBRARY_API operator> (const Area& lh, const Area& rh);
  bool ENGINEERINGLIBRARY_API operator!= (const Area& lh, const Area& rh);
  bool ENGINEERINGLIBRARY_API operator< (const Area& lh, const Area& rh);
  bool ENGINEERINGLIBRARY_API operator>= (const Area& lh, const Area& rh);
  bool ENGINEERINGLIBRARY_API operator<= (const Area& lh, const Area& rh);

  inline Area ENGINEERINGLIBRARY_API conj(const Area& x) { return x; }
  inline Area ENGINEERINGLIBRARY_API real(const Area& x) { return x; }
  inline Area ENGINEERINGLIBRARY_API imag(const Area&) { return 0_m2; }

}; // namespace eng

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<eng::Area> : NumTraits<double> {
    typedef eng::Area Real;
    typedef eng::Area NonInteger;
    typedef eng::Area Nested;

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

using eng::operator"" _mm2;       using eng::operator"" _cm2;
using eng::operator"" _m2;
using eng::operator"" _in2;       using eng::operator"" _ft2;

#endif

