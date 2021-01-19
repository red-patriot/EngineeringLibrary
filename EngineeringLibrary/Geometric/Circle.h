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
     * \param diameter the diameter of the circle
     * \param center the location of the center of the circle
     */
    Circle(const Length& diameter = 0_m, const LengthVec& center = {0_m, 0_m, 0_m});

    /** Returns the diameter of the circle
     */
    Length diameter() const { return _diameter; }

  protected:
    Length _diameter;

    Area calculate_area() const override;
    virtual AreaMomentofInertia calculate_moment_of_inertia() const override;
  };

};  // namespace eng
