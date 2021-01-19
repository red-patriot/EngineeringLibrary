#include "pch.h"
#include "HollowRectangle.h"

namespace eng {

  HollowRectangle::HollowRectangle(const Length& outer_base, const Length& outer_height, const Length& inner_base,
                                   const Length& inner_height, const LengthVec& c) :
    _outer_base(outer_base),
    _outer_height(outer_height),
    _inner_base(inner_base),
    _inner_height(inner_height),
    Geometry(c) { }

  Area HollowRectangle::calculate_area() const {
    return (_outer_base*_outer_height) - (_inner_base*_inner_height);
  }

  Geometry::AreaMomentofInertia HollowRectangle::calculate_moment_of_inertia() const {
    return {((_outer_base*_outer_height*_outer_height*_outer_height)
                  - (_inner_base*_inner_height*_inner_height*_inner_height))/12,
            ((_outer_base*_outer_base*_outer_base*_outer_height)
                  - (_inner_base*_inner_base)*(_inner_base*_inner_height))/12,
            0_m4};
  }

};  // namespace eng
