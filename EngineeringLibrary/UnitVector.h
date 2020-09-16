/*****************************************************************//**
 * \file   UnitVector.h
 * \brief  A Unit vector, which is a 
 * 
 * 
 * \author bltan
 * \date   September 2020
 *********************************************************************/
#ifndef Unit_Vector_h_INCLUDED
#define Unit_Vector_h_INCLUDED

#include <Eigen/Core>

namespace eng {
  using UnitVector2d = Eigen::Vector2d;
  using UnitVector3d = Eigen::Vector3d;

  UnitVector3d i_hat = UnitVector3d(1.0, 0.0, 0.0);
  UnitVector3d j_hat = UnitVector3d(0.0, 1.0, 0.0);
  UnitVector3d k_hat = UnitVector3d(0.0, 0.0, 1.0);

  UnitVector2d i_hat2d = UnitVector2d(1.0, 0.0);
  UnitVector2d j_hat2d = UnitVector2d(0.0, 1.0);
};

#endif
