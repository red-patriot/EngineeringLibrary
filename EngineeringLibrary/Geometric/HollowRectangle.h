#pragma once

/*****************************************************************//**
 * \file   HollowRectangle.h
 * \brief  Definitions for a hollow rectangle
 *
 *
 * \author bltan
 * \date   January 2021
 *********************************************************************/

#include "Geometry.h"

namespace eng {

  /** A rectangle with a rectangular hole around its center
 * \class HollowRectangle
 */
  class HollowRectangle : public Geometry {
  public:
    /**
     * \brief HollowRectangle constructor
     *
     * \param outer_base The base of the outer rectangle
     * \param outer_height The height of the outer rectangle
     * \param inner_base The base of the inner rectangle
     * \param inner_height The height of the inner rectangle
     * \param c The centroid of the HollowRectangle
     */
    HollowRectangle(const Length& outer_base = 0_m, const Length& outer_height = 0_m,
                    const Length& inner_base = 0_m, const Length& inner_height = 0_m,
                    const LengthVec& c = LengthVec(0_m, 0_m, 0_m));

    Length outer_base() const { return _outer_base; }
    Length outer_height() const { return _outer_height; }
    Length inner_base() const { return _inner_base; }
    Length inner_height() const { return _inner_height; }

  private:
    Length _outer_base;
    Length _outer_height;
    Length _inner_base;
    Length _inner_height;

    Area calculate_area() const override;
    virtual AreaMomentofInertia calculate_moment_of_inertia() const override;
  };

};  // namespace eng
