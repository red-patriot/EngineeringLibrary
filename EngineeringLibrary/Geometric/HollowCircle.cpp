#include "pch.h"
#include "HollowCircle.h"

namespace eng {

  HollowCircle::HollowCircle(const Length& outer_diam, 
                             const Length& inner_diam, 
                             const LengthVec& center) :
    _outer_diameter(outer_diam),
    _inner_diameter(inner_diam),
    Geometry(center) { }

  Area HollowCircle::calculate_area() const {
    return pi * ((_outer_diameter*_outer_diameter) - (_inner_diameter*_inner_diameter))/4;
    
  }

  Geometry::AreaMomentofInertia HollowCircle::calculate_moment_of_inertia() const {
    return {(pi * (((_outer_diameter*_outer_diameter)*(_outer_diameter*_outer_diameter))
                - ((_inner_diameter*_inner_diameter)*(_inner_diameter*_inner_diameter)))) / 64,
            (pi * (((_outer_diameter*_outer_diameter)*(_outer_diameter*_outer_diameter))
                - ((_inner_diameter*_inner_diameter)*(_inner_diameter*_inner_diameter)))) / 64,
            0_m4};
  }

};  // namespace eng
