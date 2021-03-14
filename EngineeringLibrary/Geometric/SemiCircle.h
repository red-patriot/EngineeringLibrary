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

namespace eng {
  
  /** A semi circle
   * \class SemiCircle
   */
  class SemiCircle : public Geometry {
  public:
    /**
    * \brief SemiCircle constructor
    *
    * \param d The diameter of the SemiCircle
    * \param c The location of the centroid of the SemiCircle
    */
    SemiCircle(const Length& d = 0_m, const LengthVec& c = {0_m, 0_m, 0_m});
  
    /** Returns the diameter of the SemiCircle
     */
    Length diameter() const { return _diameter; }

  private:
    Length _diameter;

  private:

  };
};  // namespace eng
