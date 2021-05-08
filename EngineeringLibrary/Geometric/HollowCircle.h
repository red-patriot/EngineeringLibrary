#pragma once

/*****************************************************************//**
 * \file   HollowCircle.h
 * \brief
 *
 *
 * \author bltan
 * \date   January 2021
 *********************************************************************/

#include "Geometry.h"

namespace eng {

  /** A circle with a circular hole around its center
   * \class HollowCircle
   * \addtogroup Geometric
   */
  class HollowCircle : public Geometry {
  public:
    /**
     * \brief HollowCircle constructor
     *
     * \param od The diameter of the outer circle
     * \param id The diameter of the inner circle
     * \param c The centroid of the HollowCircle
     */
    HollowCircle(const Length& od = 0_m, const Length& id = 0_m,
                 const LengthVec& c = {0_m, 0_m, 0_m});

    Length outer_diameter() const { return outer_diameter_; }
    Length inner_diameter() const { return inner_diameter_; }

  private:
    Length outer_diameter_;
    Length inner_diameter_;
  };

};  // namespace eng
