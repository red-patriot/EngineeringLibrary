#include "pch.h"
#include "HollowRectangle.h"

namespace eng {

  HollowRectangle::HollowRectangle(const Length& ob, const Length& oh, 
                                   const Length& ib, const Length& ih, 
                                   const LengthVec& c) :
    _outer_base(ob),
    _outer_height(oh),
    _inner_base(ib),
    _inner_height(ih),
    Geometry((ob*oh) - (ib*ih),
             {((ob*oh*oh*oh) 
               - (ib*ih*ih*ih))/12,
              ((ob*ob*ob*oh)
               - (ib*ib*ib*ih))/12,
              0_m4},
             c) { }

};  // namespace eng
