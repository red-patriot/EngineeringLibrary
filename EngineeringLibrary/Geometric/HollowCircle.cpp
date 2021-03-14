#include "pch.h"
#include "HollowCircle.h"

namespace eng {

  HollowCircle::HollowCircle(const Length& od, 
                             const Length& id, 
                             const LengthVec& c) :
    _outer_diameter(od),
    _inner_diameter(id),
    Geometry(pi*((od*od) - (id*id))/4,
             {pi*((od*od*od*od) - (id*id*id*id))/64,
              pi*((od*od*od*od) - (id*id*id*id))/64,
              0_m4},
             c) { }

};  // namespace eng
