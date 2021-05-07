#include "pch.h"
#include "Circle.h"

namespace eng {

  Circle::Circle(const Length& d, const LengthVec& c) :
    diameter_(d),
    Geometry(pi*d*d/4,
             {pi*d*d*d*d/64, 
              pi*d*d*d*d/64, 
              0_m4},
             c) { }

};  // namespace eng
