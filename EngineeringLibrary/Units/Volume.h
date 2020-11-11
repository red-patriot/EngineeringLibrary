#ifndef Volume_h_INCLUDED
#define Volume_h_INCLUDED

/*****************************************************************//**
 * \file  Volume.h
 * \brief An object representing a 3D spacial volume
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "UnitBase.h"

#include <eigen3/Eigen/Core>

namespace eng {
  /** A measure of the 3D space taken up an object
   * \class Volume A 3D geometry
   */
  class ENGINEERINGLIBRARY_API Volume : public UnitBase<0, 3, 0, 0, 0, 0, 0> {
  public:
    /**
     * \brief Volume constructor
     * 
     * \param _meters3 
     */
    explicit Volume(const double& _meters3 = 0) : UnitBase(_meters3) { }
    Volume(const UnitBase<0, 3, 0, 0, 0, 0, 0>& b) : UnitBase(b) { }
    ~Volume() = default;

    double mm3() const { return _value * 1'000'000'000; }
    double cm3() const { return _value * 1'000'000; }
    double m3() const { return _value; }

    double in3() const { return _value * (1'000'000/16.387'064); }
    double ft3() const { return _value * (1'000'000/28'316.846'592); }

    Volume& operator+= (const Volume& rh) { _value += rh._value; return *this; }
    Volume& operator-= (const Volume& rh) { _value -= rh._value; return *this; }
    Volume& operator*= (const double& rh) { _value *= rh; return *this; }
    Volume& operator/= (const double& rh) { _value /= rh; return *this; }
  };

  Volume ENGINEERINGLIBRARY_API operator"" _mm3(long double val);
  Volume ENGINEERINGLIBRARY_API operator"" _mm3(unsigned long long val);

  Volume ENGINEERINGLIBRARY_API operator"" _cm3(long double val);
  Volume ENGINEERINGLIBRARY_API operator"" _cm3(unsigned long long val);

  Volume ENGINEERINGLIBRARY_API operator"" _m3(long double val);
  Volume ENGINEERINGLIBRARY_API operator"" _m3(unsigned long long val);

  Volume ENGINEERINGLIBRARY_API operator"" _in3(long double val);
  Volume ENGINEERINGLIBRARY_API operator"" _in3(unsigned long long val);

  Volume ENGINEERINGLIBRARY_API operator"" _ft3(long double val);
  Volume ENGINEERINGLIBRARY_API operator"" _ft3(unsigned long long val);

  inline Volume ENGINEERINGLIBRARY_API conj(const Volume& x) { return x; }
  inline Volume ENGINEERINGLIBRARY_API real(const Volume& x) { return x; }
  inline Volume ENGINEERINGLIBRARY_API imag(const Volume&) { return 0_m3; }

}; // namespace eng

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<eng::Volume> : NumTraits<double> {
    typedef eng::Volume Real;
    typedef eng::Volume NonInteger;
    typedef eng::Volume Nested;

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

using eng::operator"" _mm3;         using eng::operator"" _cm3;
using eng::operator"" _m3;
using eng::operator"" _in3;         using eng::operator"" _ft3;

#endif

