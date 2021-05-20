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
   * \addtogroup Geometric
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
              const LengthVec<3>& c = LengthVec<3>({0_m, 0_m, 0_m}));

    Length base() const { return base_; }
    Length height() const { return height_; }

  private:
    Length base_;
    Length height_;
  };

};  // namespace eng
