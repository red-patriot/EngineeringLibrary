#include "pch.h"
#include "Rectangle.h"

namespace eng {

  Rectangle::Rectangle(const Length& base, 
                       const Length& height, 
                       const LengthVec& centroid) :
    _base(base),
    _height(height),
    Geometry(centroid) { }

  Area Rectangle::calculate_area() const {
    return _base*_height;
  }

  Geometry::AreaMomentofInertia Rectangle::calculate_moment_of_inertia() const {
    return {(_base*_height*_height*_height) / 12,
            (_base*_base*_base*_height) / 12,
            0_m4};
  }

};  // namespace eng
