#include "pch.h"
#include "Rectangle.h"

namespace eng {

  Rectangle::Rectangle(const Length& b, 
                       const Length& h, 
                       const LengthVec& c) :
    _base(b),
    _height(h),
    Geometry(b*h,
             {b*h*h*h/12,
              b*b*b*h/12,
              0_m4},
             c) { }

};  // namespace eng
