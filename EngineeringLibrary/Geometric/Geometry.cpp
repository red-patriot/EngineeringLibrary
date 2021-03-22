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
                     const AreaMomentofInertia& moi, 
                     const LengthVec & centroid) :
    _centroid(centroid),
    _area(area),
    _MOI(moi) { }

  LengthVec Geometry::centroid() const {
    return _centroid;
  }

  Area Geometry::area() const {
    return _area;
  }

  Geometry::AreaMomentofInertia Geometry::moment_of_inertia() const {
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

  Geometry eng::operator+(const Geometry & lh, const Geometry & rh) {
    Area composite_area = lh._area + rh._area;

    LengthVec composite_centroid = {(lh._centroid.x()*lh._area + rh._centroid.x()*rh._area)/composite_area,
      (lh._centroid.y()*lh._area + rh._centroid.y()*rh._area)/composite_area,
      (lh._centroid.z()*lh._area + rh._centroid.z()*rh._area)/composite_area};
    

    Geometry::AreaMomentofInertia lh_moi = lh.moment_of_inertia(composite_centroid);
    Geometry::AreaMomentofInertia rh_moi = rh.moment_of_inertia(composite_centroid);
    Geometry::AreaMomentofInertia composite_moi = {lh_moi.Ixx + rh_moi.Ixx,
      lh_moi.Iyy + rh_moi.Iyy,
      lh_moi.Ixy + rh_moi.Ixy};

    return Geometry(composite_area, composite_moi, composite_centroid);
  }

  Geometry eng::operator-(const Geometry & lh, const Geometry & rh) {
    Area composite_area = lh._area - rh._area;

    LengthVec composite_centroid = {(lh._centroid.x()*lh._area - rh._centroid.x()*rh._area)/composite_area,
      (lh._centroid.y()*lh._area - rh._centroid.y()*rh._area)/composite_area,
      (lh._centroid.z()*lh._area - rh._centroid.z()*rh._area)/composite_area};

    Geometry::AreaMomentofInertia lh_moi = lh.moment_of_inertia(composite_centroid);
    Geometry::AreaMomentofInertia rh_moi = rh.moment_of_inertia(composite_centroid);
    Geometry::AreaMomentofInertia composite_moi = {lh_moi.Ixx - rh_moi.Ixx,
      lh_moi.Iyy - rh_moi.Iyy,
      lh_moi.Ixy - rh_moi.Ixy};

    return Geometry(composite_area, composite_moi, composite_centroid);
  }

};  // namespace eng
