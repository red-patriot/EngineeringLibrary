#include "pch.h"
#include "SemiCircle.h"

namespace eng {

  SemiCircle::SemiCircle(const Length& d, const LengthVec& c) :
    diameter_(d),
    Geometry(pi*d*d/8,
             {(pi/8 - 8/(9*pi))*(d*d*d*d)/16,
              (pi/8)*(d*d*d*d)/16,
              0_m4}, 
             c) { }

};
