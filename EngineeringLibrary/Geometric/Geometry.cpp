#include "pch.h"
#include "Geometry.h"

namespace eng {

  Geometry::AreaMomentofInertia::AreaMomentofInertia(const SecondMomentOfArea& xx,
                                                     const SecondMomentOfArea& yy, 
                                                     const SecondMomentOfArea& xy) :
    Ixx(xx),
    Iyy(yy),
    Ixy(xy) { }


  Geometry::Geometry(const Area & area, 
                     const AreaMomentofInertia & moi, 
                     const LengthVec & centroid) :
    _centroid(centroid),
    _area(area),
    _MOI(moi),
    _area_calculated(true),
    _moi_calculated(true) { }

  LengthVec Geometry::centroid() const {
    return _centroid;
  }

  Area Geometry::area() const {
    if (!_area_calculated) {
      _area = calculate_area();
    }
    return _area;
  }

  Geometry::AreaMomentofInertia Geometry::moment_of_inertia() const {
    if (!_moi_calculated) {
      _MOI = calculate_moment_of_inertia();
    }
    return _MOI;
  }

  Geometry::AreaMomentofInertia Geometry::moment_of_inertia(const LengthVec& pt) const {
    Length x = pt.x() - _centroid.x();
    Length y = pt.y() - _centroid.y();
    AreaMomentofInertia ret = moment_of_inertia();
    ret.Ixx += area()*(y*y);
    ret.Iyy += area()*(x*x);
    ret.Ixy += area()*(x*y);
    return ret;
  }

  Geometry::AreaMomentofInertia Geometry::moment_of_inertia(const Angle & theta) const {
    AreaMomentofInertia ret;
    ret.Ixx = (_MOI.Ixx + _MOI.Iyy)/2 + (_MOI.Ixx - _MOI.Iyy)/2 * cos(2*theta) - _MOI.Ixy * sin(2*theta);
    ret.Iyy = (_MOI.Ixx + _MOI.Iyy)/2 - (_MOI.Ixx - _MOI.Iyy)/2 * cos(2*theta) + _MOI.Ixy * sin(2*theta);
    ret.Ixy = (_MOI.Ixx - _MOI.Iyy)/2 * sin(2*theta) + _MOI.Ixy * cos(2*theta);
    return ret;
  }

  Area Geometry::calculate_area() const {
    return Area();
  }

  Geometry::AreaMomentofInertia Geometry::calculate_moment_of_inertia() const {
    return AreaMomentofInertia();
  }

  Geometry::Geometry(const LengthVec& c) :
    _centroid(c),
    _area(0_m2),
    _MOI(0_m4, 0_m4, 0_m4),
    _area_calculated(false),
    _moi_calculated(false) { }

};  // namespace eng
