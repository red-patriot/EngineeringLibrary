#pragma once

/*****************************************************************//**
 * \file  Angle.h
 * \brief An object representing the angle between two noncolinear lines. 
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "SIUnit.h"
#include "Unitless.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /**
   * \class Angle 
   * \addtogroup Units
   */
  using Angle = SIUnit<0, 0, 0, 0, 0, 0, 0>;

  Angle operator"" _deg(long double val);
  Angle operator"" _deg(unsigned long long val);

  Angle operator"" _rad(long double val);
  Angle operator"" _rad(unsigned long long val);

  double sin(const Angle& a);
  double cos(const Angle& a);
  double tan(const Angle& a);

  Angle asin(const double& x);
  Angle acos(const double& x);
  Angle atan(const double& x);
  Angle atan2(const double& x, const double& y);

}; // namespace eng

using eng::operator"" _rad;        using eng::operator"" _deg;
