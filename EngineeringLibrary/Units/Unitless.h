#pragma once

/*****************************************************************//**
 * \file  Unitless.h
 * \brief An object representing the a UnitBase with no units.
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "SIUnit.h"

#include <eigen3/Eigen/Core>

namespace eng {

  static constexpr long double pi = 3.141592653589793238462643383279;

  /** 
   * \class Unitless
   * \addtogroup Units
   */
  template<>
  class SIUnit<0, 0, 0, 0, 0, 0, 0> {
   public:
    typedef SIUnit<0, 0, 0, 0, 0, 0, 0> this_t;
   public:
    SIUnit(const double& n = 0) : value_(n) { } // purposefully implicit.
    double value() const { return value_; }

    double rad() const { return value_; }
    double deg() const { return value_ * (pi/180); }

    this_t& operator+= (const this_t& rh) { value_ += rh.value(); return *this; }
    this_t& operator-= (const this_t& rh) { value_ -= rh.value(); return *this; }
    this_t& operator*= (const double& rh) { value_ *= rh; return *this; }
    this_t& operator/= (const double& rh) { value_ /= rh; return *this; }

    operator double() { return value_; } // purposefully implicit

  protected:
    double value_;
  };

  using Unitless = SIUnit<0, 0, 0, 0, 0, 0, 0>;
  using Angle = SIUnit<0, 0, 0, 0, 0, 0, 0>;

}; // namespace eng
