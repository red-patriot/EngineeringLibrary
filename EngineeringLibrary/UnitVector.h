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
#include "Units\Unitless.h"

namespace eng {
  static const UnitlessVec<3> i_hat({1.0, 0.0, 0.0});
  static const UnitlessVec<3> j_hat({0.0, 1.0, 0.0});
  static const UnitlessVec<3> k_hat({0.0, 0.0, 1.0});
};

