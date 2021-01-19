#include "pch.h"
#include "Circle.h"

namespace eng {

  Circle::Circle(const Length& dd, const LengthVec& c) :
    _diameter(dd),
    Geometry(c) { }

  Area Circle::calculate_area() const {
    return pi * (_diameter*_diameter)/4;
  }

  Geometry::AreaMomentofInertia Circle::calculate_moment_of_inertia() const {
    return {(pi * (_diameter*_diameter)*(_diameter*_diameter)) / 64, 
            (pi * (_diameter*_diameter)*(_diameter*_diameter)) / 64,
            0_m4};
  }

};  // namespace eng
