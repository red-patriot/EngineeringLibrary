#ifndef Geometric_Property_h_INCLUDED
#define Geometric_Property_h_INCLUDED

/*****************************************************************//**
 * \file   GeometricProperty.h
 * \brief  Functions to calculate properties of various geometries
 * 
 * A set of functions which calculate geometric properties (first and second 
 *   moment of area and controid) of various common shapes. These functions can 
 *   calculate the Moment of Inertia or Polar Moment of Inertia for each 
 *   supported shape. Also included is functionality to perform Polar Axis 
 *   shifts on some of the shapes to create composite cross sections of beams.
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include <vector>

#include "EngineeringExport.h"
#include "Geometry.h"

namespace eng {
  
  /* Calculate the Moment of Inertia of a composite shape about the given centroid. */
  AreaMomentofInertia ENGINEERINGLIBRARY_API moment_of_inertia(const std::vector<Geometry*>& geo, 
                                                               const Point& pt);
  /* Calculate the Moment of Inertia of a composite shape about its own centroid. */
  AreaMomentofInertia ENGINEERINGLIBRARY_API moment_of_inertia(const std::vector<Geometry*>& geo);
  /* Calculate the Moment of Inertia of a composite shape about the given centroid.
     neg represents holes in the geometry. */
  AreaMomentofInertia ENGINEERINGLIBRARY_API moment_of_inertia(const std::vector<Geometry*>& geo,
    const std::vector<Geometry*>& neg, const Point& pt);
  /* Calculate the Moment of Inertia of a composite shape about its own centroid.
     neg represents holes in the geometry. */
  AreaMomentofInertia ENGINEERINGLIBRARY_API moment_of_inertia(const std::vector<Geometry*>& geo, 
    const std::vector<Geometry*>& neg);

  /* The axis about which a Radius of Gyration is calculated */
  enum class Axis { X,Y };
  /* Calculate Radius of Gyration of a Moment of Inertia and an Area */
  class Length ENGINEERINGLIBRARY_API radius_of_gyration(const class SecondMomentOfArea& I,
    const class Area& a);
  /* Calculate Radius of Gyration of a geometry about the given axis */
  class Length ENGINEERINGLIBRARY_API radius_of_gyration(const Geometry& geo, const Axis& axis);
  
  /* Calculate the Point of a composite shape. */
  Point ENGINEERINGLIBRARY_API centroid(const std::vector<Geometry*>& geo);
  /* Calculate the Point of a composite shape.
     neg represents holes in the geometry. */
  Point ENGINEERINGLIBRARY_API centroid(const std::vector<Geometry*>& geo, 
                                           const std::vector<Geometry*>& neg);

};  // namespace eng

#endif
