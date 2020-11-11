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

  inline bool ENGINEERINGLIBRARY_API fuzzy_equals(const double& lh, const double& rh);
  inline bool ENGINEERINGLIBRARY_API fuzzy_greater(const double& lh, const double& rh);
  inline bool ENGINEERINGLIBRARY_API approx(const double& lh, const double& rh);

  /*
   * Trigonometric functions
   * The trig and inverse trig functions for a eng::Angle
   */

  inline double ENGINEERINGLIBRARY_API sin(const Angle& a);
  inline double ENGINEERINGLIBRARY_API cos(const Angle& a);
  inline double ENGINEERINGLIBRARY_API tan(const Angle& a);

  inline Angle ENGINEERINGLIBRARY_API asin(const double& x);
  inline Angle ENGINEERINGLIBRARY_API acos(const double& x);
  inline Angle ENGINEERINGLIBRARY_API atan(const double& x);
  inline Angle ENGINEERINGLIBRARY_API atan2(const double& x, const double& y);

  /*
   * Misc functions
   * Miscellaneous math functions such as sqrt
   */

  inline Length ENGINEERINGLIBRARY_API sqrt(const Area& r);
  inline Area ENGINEERINGLIBRARY_API sqrt(const SecondMomentOfArea& r);


  // TODO: This could probably be a single template
  inline Time ENGINEERINGLIBRARY_API abs(const Time& x);
  inline Frequency ENGINEERINGLIBRARY_API abs(const Frequency& x);
  inline Mass ENGINEERINGLIBRARY_API abs(const Mass& x);
  inline Angle abs(const  Angle& x);
  inline Length abs(const  Length& x);
  inline Area abs(const  Area& x);
  inline Volume ENGINEERINGLIBRARY_API abs(const  Volume& x);
  inline SecondMomentOfArea ENGINEERINGLIBRARY_API abs(const  SecondMomentOfArea& x);
  inline Force abs(const  Force& x);
  inline Stiffness ENGINEERINGLIBRARY_API abs(const  Stiffness& x);
  inline Damping ENGINEERINGLIBRARY_API abs(const  Damping& x);
  inline Pressure ENGINEERINGLIBRARY_API abs(const  Pressure& x);
  inline Velocity ENGINEERINGLIBRARY_API abs(const  Velocity& x);
  inline Acceleration ENGINEERINGLIBRARY_API abs(const  Acceleration& x);
  
  inline Area ENGINEERINGLIBRARY_API abs2(const Length& x);
  inline SecondMomentOfArea ENGINEERINGLIBRARY_API abs2(const Area& x);

}; // namespace eng

#endif
