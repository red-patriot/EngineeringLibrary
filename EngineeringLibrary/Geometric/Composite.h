#pragma once

/*****************************************************************//**
 * \file   Composite.h
 * \brief  Functions to analyze properties of composite geometries: geometries
 *           made of combinations of simpler geometries
 *
 *
 * \author bltan
 * \date   January 2021
 *********************************************************************/

#include <vector>

#include "Geometry.h"
#include "../Units/Length.h"
#include "../Units/Area.h"
#include "../Units/Volume.h"
#include "../Units/MomentOfArea.h"

namespace eng {

  Geometry::AreaMomentofInertia moment_of_inertia(const std::vector<Geometry*>& geometry);

  Geometry::AreaMomentofInertia moment_of_inertia(const std::vector<Geometry*>& geometry,
                                                  const LengthVec& point);

  Geometry::AreaMomentofInertia moment_of_inertia(const std::vector<Geometry*>& positive,
                                                  const std::vector<Geometry*>& negative);

  Geometry::AreaMomentofInertia moment_of_inertia(const std::vector<Geometry*>& positive,
                                                  const std::vector<Geometry*>& negative,
                                                  const LengthVec& point);

  Length radius_of_gyration(const SecondMomentOfArea& I,
                            const Area& a);
  enum Axis {X, Y};
  Length radius_of_gyration(const Geometry& geometry, const Axis& axis);

};  // namespace eng

