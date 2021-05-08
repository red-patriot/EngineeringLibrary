#include "pch.h"
#include "HollowCircle.h"

namespace eng {

  HollowCircle::HollowCircle(const Length& od, 
                             const Length& id, 
                             const LengthVec& c) :
    outer_diameter_(od),
    inner_diameter_(id),
    Geometry(pi*((od*od) - (id*id))/4,
             pi*((od*od*od*od) - (id*id*id*id))/64,
             pi*((od*od*od*od) - (id*id*id*id))/64,
             0_m4,
             c) { }

};  // namespace eng
