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
     * \param b The length of the base of the Rectangle
     * \param h The length of the height of the Rectangle
     * \param c The centroid of the Rectangle
     */
    Rectangle(const Length& b = 0_m, const Length& h = 0_m,
              const LengthVec& c = {0_m, 0_m, 0_m});

    Length base() const { return _base; }
    Length height() const { return _height; }

  private:
    Length _base;
    Length _height;
  };

};  // namespace eng
