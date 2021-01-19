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
   */
  class HollowCircle : public Geometry {
  public:
    /**
     * \brief HollowCircle constructor
     *
     * \param outer_diam The diameter of the outer circle
     * \param inner_diam The diameter of the inner circle
     * \param center The centroid of the HollowCircle
     */
    HollowCircle(const Length& outer_diam = 0_m, const Length& inner_diam = 0_m,
                 const LengthVec& center = {0_m, 0_m, 0_m});

    Length outer_diameter() const { return _outer_diameter; }
    Length inner_diameter() const { return _inner_diameter; }

  private:
    Length _outer_diameter;
    Length _inner_diameter;

    Area calculate_area() const override;
    virtual AreaMomentofInertia calculate_moment_of_inertia() const override;
  };

};  // namespace eng
