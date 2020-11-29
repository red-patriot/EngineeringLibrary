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
  static const Vector<double> i_hat(1.0, 0.0, 0.0);
  static const Vector<double> j_hat(0.0, 1.0, 0.0);
  static const Vector<double> k_hat(0.0, 0.0, 1.0);
};

