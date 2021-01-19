#include "pch.h"
#include "SemiCircle.h"

namespace eng {

  SemiCircle::SemiCircle(const Length& diameter, const LengthVec& center) :
    Circle(diameter, center) { }

  Area SemiCircle::calculate_area() const {
    return pi * _diameter*_diameter/8;
  }

  Geometry::AreaMomentofInertia SemiCircle::calculate_moment_of_inertia() const {
    return {(pi / 8 - 8 / (9*pi)) * (_diameter*_diameter)/4 * (_diameter*_diameter)/4,
            (pi / 8) * (_diameter*_diameter)/4 * (_diameter*_diameter)/4,
            0_m4};
  }

};
