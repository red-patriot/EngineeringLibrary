#pragma once

/*****************************************************************//**
 * \file   Rectangle.h
 * \brief  Definitions for a rectangle
 *
 *
 * \author bltan
 * \date   January 2021
 *********************************************************************/

#include "Geometry.h"

namespace eng {

  /** A rectangle
   * \class Rectangle
   */
  class Rectangle : public Geometry {
  public:
    /**
     * \brief Rectangle constructor
     *
     * \param base The length of the base of the Rectangle
     * \param height The length of the height of the Rectangle
     * \param centroid The centroid of the Rectangle
     */
    Rectangle(const Length& base = 0_m, const Length& height = 0_m,
              const LengthVec& centroid = {0_m, 0_m, 0_m});

    Length base() const { return _base; }
    Length height() const { return _height; }

  private:
    Length _base;
    Length _height;

    Area calculate_area() const override;
    virtual AreaMomentofInertia calculate_moment_of_inertia() const override;
  };

};  // namespace eng
