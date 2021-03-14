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
     * \param ob The base of the outer rectangle
     * \param oh The height of the outer rectangle
     * \param ib The base of the inner rectangle
     * \param ih The height of the inner rectangle
     * \param c The centroid of the HollowRectangle
     */
    HollowRectangle(const Length& ob = 0_m, const Length& oh = 0_m,
                    const Length& ib = 0_m, const Length& ih = 0_m,
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
  };

};  // namespace eng
