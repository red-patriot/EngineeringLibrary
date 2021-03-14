#pragma once

/*****************************************************************//**
 * \file   Circle.h
 * \brief  Definitions for a Circle
 *
 *
 * \author bltan
 * \date   January 2021
 *********************************************************************/

#include "Geometry.h"

namespace eng {

  /** A circle
   * \class Circle
   */
  class Circle : public Geometry {
  public:
    /**
     * \brief Circle constructor
     * 
     * \param d the diameter of the Circle
     * \param c the location of the centroid of the Circle
     */
    Circle(const Length& d = 0_m, const LengthVec& c = {0_m, 0_m, 0_m});

    /** Returns the diameter of the circle
     */
    Length diameter() const { return _diameter; }

  private:
    Length _diameter;
  };

};  // namespace eng
