#pragma once

/*****************************************************************//**
 * \file   ElectricCurrent.h
 * \brief  An object representing electric current
 * 
 * \date 2021
 *********************************************************************/

#include "UnitBase.h"

#include <eigen3/Eigen/Core>

namespace eng { 
  
  /**
   * \class ElectricCurrent
   * \addtogroup Units
   */
  template<>
  class SIUnit<0, 0, 0, 1, 0, 0, 0> {
   public:
    typedef SIUnit<0, 0, 0, 1, 0, 0, 0> this_t;
    UnitBaseCOMMON;
   public:
    double mAmp() const { return 1000.0 * value_; }
    double amp() const { return value_; }
  };

  using ElectricCurrent = SIUnit<0, 0, 0, 1, 0, 0, 0>;

  ElectricCurrent operator"" _Amp(long double val);
  ElectricCurrent operator"" _Amp(unsigned long long val);

  ElectricCurrent operator"" _mAmp(long double val);
  ElectricCurrent operator"" _mAmp(unsigned long long val);

};  // namespace eng
