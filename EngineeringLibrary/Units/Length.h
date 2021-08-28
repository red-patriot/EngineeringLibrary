#pragma once

/*****************************************************************//**
 * \file  Length.h
 * \brief An object representing a 1D length. 
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "SIUnit.h"
#include "../Vector.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /** 
   * \class Length 
   * \addtogroup Units
   */
  template<>
  class SIUnit<0, 1, 0, 0, 0, 0, 0> {
   public:
    typedef SIUnit<0, 1, 0, 0, 0, 0, 0> this_t;
    UnitBaseCOMMON
   public:
    double mm() const { return value_ * 1000; }
    double cm() const { return value_ * 100; }
    double m() const { return value_; }
    double km() const { return value_ * 0.001; }
    
    double in() const { return value_ * (100/2.54); }
    double ft() const { return value_ * (100/30.48); }
    double mi() const { return value_ * (100/160'934.4); }
  };

  using Length = SIUnit<0, 1, 0, 0, 0, 0, 0>;

  Length operator"" _mm (long double val);
  Length operator"" _mm (unsigned long long val);

  Length operator"" _cm (long double val);
  Length operator"" _cm (unsigned long long val);

  Length operator"" _m (long double val);
  Length operator"" _m (unsigned long long val);

  Length operator"" _km (long double val);
  Length operator"" _km (unsigned long long val);

  Length operator"" _in (long double val);
  Length operator"" _in (unsigned long long val);

  Length operator"" _ft (long double val);
  Length operator"" _ft (unsigned long long val);

  Length operator"" _mi (long double val);
  Length operator"" _mi (unsigned long long val);

  // Lengths are commonly used as vectors
  using LengthVec = Vector<0, 1, 0, 0, 0, 0, 0>;

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

using eng::operator"" _mm;      using eng::operator"" _cm;
using eng::operator"" _m;       using eng::operator"" _km;
using eng::operator"" _in;      using eng::operator"" _ft;
using eng::operator"" _mi;


