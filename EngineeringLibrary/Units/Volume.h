#pragma once

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
   * \class Volume
   * \addtogroup Units
   */
  template<>
  class UnitBase<0, 3, 0, 0, 0, 0, 0> {
    typedef UnitBase<0, 3, 0, 0, 0, 0, 0> this_t; 
      UnitBaseCOMMON
  public:
    double mm3() const { return _value * 1'000'000'000; }
    double cm3() const { return _value * 1'000'000; }
    double m3() const { return _value; }

    double in3() const { return _value * (1'000'000/16.387'064); }
    double ft3() const { return _value * (1'000'000/28'316.846'592); }
  };

  using Volume = UnitBase<0, 3, 0, 0, 0, 0, 0>;

  Volume operator"" _mm3(long double val);
  Volume operator"" _mm3(unsigned long long val);

  Volume operator"" _cm3(long double val);
  Volume operator"" _cm3(unsigned long long val);

  Volume operator"" _m3(long double val);
  Volume operator"" _m3(unsigned long long val);

  Volume operator"" _in3(long double val);
  Volume operator"" _in3(unsigned long long val);

  Volume operator"" _ft3(long double val);
  Volume operator"" _ft3(unsigned long long val);

  inline Volume conj(const Volume& x) { return x; }
  inline Volume real(const Volume& x) { return x; }
  inline Volume imag(const Volume&) { return 0_m3; }

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

