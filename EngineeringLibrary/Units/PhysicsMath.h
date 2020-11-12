#ifndef Physics_Math_h_INCLUDED
#define Physics_Math_h_INCLUDED

/*****************************************************************//**
 * \file   PhysicsMath.h
 * \brief This file contains a number of mathematical functions to use in 
 *          calculations for the engineering library.
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "UnitBase.h"
#include "../Units.h"

namespace eng {

  // Define some important mathematical constants
  static constexpr long double pi = 3.141592653589793238462643383279;

  /*
   * Comparison functions
   * Because unit conversions can cause some small error in units, especially 
   *    those that do not have exact conversions, and because of error in the 
   *    binary representations of those that are exact, this library uses 
   *    slightly fuzzy comparisons for its types.
   */

  /*
   * Trigonometric functions
   * The trig and inverse trig functions for a eng::Angle
   */

  //inline double sin(const Angle& a);
  //inline double cos(const Angle& a);
  //inline double tan(const Angle& a);

  //inline Angle asin(const double& x);
  //inline Angle acos(const double& x);
  //inline Angle atan(const double& x);
  //inline Angle atan2(const double& x, const double& y);

}; // namespace eng

#endif
