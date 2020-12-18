#pragma once

/*****************************************************************//**
 * \file   UnitVector.h
 * \brief  A Unit vector
 * 
 * 
 * \author bltan
 * \date   September 2020
 *********************************************************************/


#include "Vector.h"

namespace eng {
  using UnitlessVec = Vector<0, 0, 0, 0, 0, 0, 0>;

  static const UnitlessVec i_hat(1.0, 0.0, 0.0);
  static const UnitlessVec j_hat(0.0, 1.0, 0.0);
  static const UnitlessVec k_hat(0.0, 0.0, 1.0);
};

