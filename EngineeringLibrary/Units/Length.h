#ifndef Length_h_INCLUDED
#define Length_h_INCLUDED

/*****************************************************************//**
 * \file  Length.h
 * \brief An object representing a 1D length. 
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "UnitBase.h"

#include <eigen3/Eigen/Core>

namespace eng {

  class SecondMomentOfArea;
  class Volume;
  class Area;

  /** A 1D geometry
   * \class Length 
   * \addtogroup Units
   */
  class ENGINEERINGLIBRARY_API Length : public UnitBase {
  public:
    /**
     * \brief Length constructor
     * 
     * \param _meters the measure of the length in meters
     */
    explicit Length(double meters = 0) : UnitBase(meters) { }
    Length(const Length&) = default;
    ~Length() = default;

    double mm() const { return _value * 1000; }
    double cm() const { return _value * 100; }
    double m() const { return _value; }
    double km() const { return _value * 0.001; }

    double in() const { return _value * (100/2.54); }
    double ft() const { return _value * (100/(30.48)); }
    double mi() const { return _value * (100/(160'934.4)); }

    Length& operator+= (const Length& rh) { _value += rh._value; return *this; }
    Length& operator-= (const Length& rh) { _value -= rh._value; return *this; }
    Length& operator*= (const double& rh) { _value *= rh; return *this; }
    Length& operator/= (const double& rh) { _value /= rh; return *this; }
  };

  Length ENGINEERINGLIBRARY_API operator"" _mm (long double val);
  Length ENGINEERINGLIBRARY_API operator"" _mm (unsigned long long val);

  Length ENGINEERINGLIBRARY_API operator"" _cm (long double val);
  Length ENGINEERINGLIBRARY_API operator"" _cm (unsigned long long val);

  Length ENGINEERINGLIBRARY_API operator"" _m (long double val);
  Length ENGINEERINGLIBRARY_API operator"" _m (unsigned long long val);

  Length ENGINEERINGLIBRARY_API operator"" _km (long double val);
  Length ENGINEERINGLIBRARY_API operator"" _km (unsigned long long val);

  Length ENGINEERINGLIBRARY_API operator"" _in (long double val);
  Length ENGINEERINGLIBRARY_API operator"" _in (unsigned long long val);

  Length ENGINEERINGLIBRARY_API operator"" _ft (long double val);
  Length ENGINEERINGLIBRARY_API operator"" _ft (unsigned long long val);

  Length ENGINEERINGLIBRARY_API operator"" _mi (long double val);
  Length ENGINEERINGLIBRARY_API operator"" _mi (unsigned long long val);

  Length ENGINEERINGLIBRARY_API operator- (const Length& lh);

  Length ENGINEERINGLIBRARY_API operator+ (const Length& lh, const Length& rh);

  Length ENGINEERINGLIBRARY_API operator- (const Length& lh, const Length& rh);

  Length ENGINEERINGLIBRARY_API operator* (const Length& lh, const double& n);
  Length ENGINEERINGLIBRARY_API operator* (const double& n, const Length& rh);
  Length ENGINEERINGLIBRARY_API operator* (const class Velocity& lh, const class Time& rh);
  Length ENGINEERINGLIBRARY_API operator* (const class Time& lh, const class Velocity& rh);

  Length ENGINEERINGLIBRARY_API operator/ (const class Energy& lh, const class Force& rh);
  Length ENGINEERINGLIBRARY_API operator/ (const Area& lh, const Length& rh);
  Length ENGINEERINGLIBRARY_API operator/ (const Volume& lh, const Area& rh);
  Length ENGINEERINGLIBRARY_API operator/ (const SecondMomentOfArea& lh, const Volume& rh);
  Length ENGINEERINGLIBRARY_API operator/ (const Length& lh, const double& n);
  double ENGINEERINGLIBRARY_API operator/ (const Length& lh, const Length& rh);
   
  bool ENGINEERINGLIBRARY_API operator== (const Length& lh, const Length& rh);
  bool ENGINEERINGLIBRARY_API operator> (const Length& lh, const Length& rh);
  bool ENGINEERINGLIBRARY_API operator!= (const Length& lh, const Length& rh);
  bool ENGINEERINGLIBRARY_API operator< (const Length& lh, const Length& rh);
  bool ENGINEERINGLIBRARY_API operator>= (const Length& lh, const Length& rh);
  bool ENGINEERINGLIBRARY_API operator<= (const Length& lh, const Length& rh);

  inline Length ENGINEERINGLIBRARY_API conj(const Length& x) { return x; }
  inline Length ENGINEERINGLIBRARY_API real(const Length& x) { return x; }
  inline Length ENGINEERINGLIBRARY_API imag(const Length&) { return 0_m; }


}; // namespace eng

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<eng::Length> : NumTraits<double> {
    typedef eng::Length Real;
    typedef eng::Length NonInteger;
    typedef eng::Length Nested;

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

//? This feels hacky, is there some other way to do this?
using eng::operator"" _mm;      using eng::operator"" _cm;
using eng::operator"" _m;       using eng::operator"" _km;
using eng::operator"" _in;      using eng::operator"" _ft;
using eng::operator"" _mi;

#endif

