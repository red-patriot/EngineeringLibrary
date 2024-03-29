#pragma once

/*****************************************************************//**
 * \file  Stiffness.h
 * \brief An object representing a linear stiffness
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "SIUnit.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /**
   * \class Stiffness 
   * \addtogroup Units
   */
  template<>
  class SIUnit<1, 0, -2, 0, 0, 0, 0> {
   public:
    typedef SIUnit<1, 0, -2, 0, 0, 0, 0> this_t;
    UnitBaseCOMMON
   public:
    double Npm() const { return value_; }
    double Npmm() const { return value_ * 0.001; }
    
    double lbpin() const { return value_ * 0.005'710'147'154'732'646'26; }
    double lbpft() const { return value_ * 0.068'521'765'856'791'755'19; }
  };

  using Stiffness = SIUnit<1, 0, -2, 0, 0, 0, 0>;

  Stiffness operator"" _Npm(long double val);
  Stiffness operator"" _Npm(unsigned long long val);

  Stiffness operator"" _Npmm(long double val);
  Stiffness operator"" _Npmm(unsigned long long val);

  Stiffness operator"" _lbpin(long double val);
  Stiffness operator"" _lbpin(unsigned long long val);

  Stiffness operator"" _lbpft(long double val);
  Stiffness operator"" _lbpft(unsigned long long val);
  
}; // namespace eng

using eng::operator"" _Npm;       using eng::operator"" _Npmm;
using eng::operator"" _lbpin;     using eng::operator"" _lbpft;

