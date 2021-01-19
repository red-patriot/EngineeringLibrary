#pragma once

/*****************************************************************//**
 * \file   SemiCircle.h
 * \brief  Definitions of a semi circle geometry
 *
 *
 * \author bltan
 * \date   January 2021
 *********************************************************************/

#include "Geometry.h"
#include "Circle.h"

namespace eng {
  
  /** A semi circle
   * \class SemiCircle
   */
  class SemiCircle : public Circle {
  public:
    /**
    * \brief SemiCircle constructor
    *
    * \param diameter The diameter of the SemiCircle
    * \param center The location of the center of the SemiCircle
    */
    SemiCircle(const Length& diameter = 0_m, const LengthVec& center = {0_m, 0_m, 0_m});

  private:
    Area calculate_area() const override;
    virtual AreaMomentofInertia calculate_moment_of_inertia() const override;
  };
};  // namespace eng
