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

  inline bool ENGINEERINGLIBRARY_API fuzzy_equals(const double& lh, const double& rh);
  inline bool ENGINEERINGLIBRARY_API fuzzy_greater(const double& lh, const double& rh);
  inline bool ENGINEERINGLIBRARY_API approx(const double& lh, const double& rh);

  /*
   * Trigonometric functions
   * The trig and inverse trig functions for a eng::Angle
   */

  inline double ENGINEERINGLIBRARY_API sin(const class Angle& a);
  inline double ENGINEERINGLIBRARY_API cos(const class Angle& a);
  inline double ENGINEERINGLIBRARY_API tan(const class Angle& a);

  inline Angle ENGINEERINGLIBRARY_API asin(const double& x);
  inline Angle ENGINEERINGLIBRARY_API acos(const double& x);
  inline Angle ENGINEERINGLIBRARY_API atan(const double& x);
  inline Angle ENGINEERINGLIBRARY_API atan2(const double& x, const double& y);

  /*
   * Misc functions
   * Miscellaneous math functions such as sqrt
   */

  inline class Length ENGINEERINGLIBRARY_API sqrt(const class Area& r);
  inline class Area ENGINEERINGLIBRARY_API sqrt(const class SecondMomentOfArea& r);


  // TODO: This could probably be a single template
  inline class Time ENGINEERINGLIBRARY_API abs(const class Time& x);
  inline class Frequency ENGINEERINGLIBRARY_API abs(const class Frequency& x);
  inline class Mass ENGINEERINGLIBRARY_API abs(const class Mass& x);
  inline class Angle abs(const class Angle& x);
  inline class Length abs(const class Length& x);
  inline class Area abs(const class Area& x);
  inline class Volume ENGINEERINGLIBRARY_API abs(const class Volume& x);
  inline class SecondMomentOfArea ENGINEERINGLIBRARY_API abs(const class SecondMomentOfArea& x);
  inline class Force abs(const class Force& x);
  inline class Stiffness ENGINEERINGLIBRARY_API abs(const class Stiffness& x);
  inline class Damping ENGINEERINGLIBRARY_API abs(const class Damping& x);
  inline class Pressure ENGINEERINGLIBRARY_API abs(const class Pressure& x);
  inline class Velocity ENGINEERINGLIBRARY_API abs(const class Velocity& x);
  inline class Acceleration ENGINEERINGLIBRARY_API abs(const class Acceleration& x);

  inline class Area ENGINEERINGLIBRARY_API abs2(const class Length& x);
  inline class SecondMomentOfArea ENGINEERINGLIBRARY_API abs2(const class Area& x);

}; // namespace eng

#endif
