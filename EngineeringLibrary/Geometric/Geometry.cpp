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
    centroid_(centroid),
    area_(area),
    MOI_(moi) { }

  LengthVec Geometry::centroid() const {
    return centroid_;
  }

  Area Geometry::area() const {
    return area_;
  }

  Geometry::AreaMomentofInertia Geometry::moment_of_inertia() const {
    return MOI_;
  }

  Geometry::AreaMomentofInertia Geometry::moment_of_inertia(const LengthVec& pt) const {
    Length x = pt.x() - centroid_.x();
    Length y = pt.y() - centroid_.y();
    AreaMomentofInertia ret = moment_of_inertia();
    ret.Ixx += area()*(y*y);
    ret.Iyy += area()*(x*x);
    ret.Ixy += area()*(x*y);
    return ret;
  }

  Geometry::AreaMomentofInertia Geometry::moment_of_inertia(const Angle & theta) const {
    AreaMomentofInertia ret;
    ret.Ixx = (MOI_.Ixx + MOI_.Iyy)/2 + (MOI_.Ixx - MOI_.Iyy)/2 * cos(2*theta) - MOI_.Ixy * sin(2*theta);
    ret.Iyy = (MOI_.Ixx + MOI_.Iyy)/2 - (MOI_.Ixx - MOI_.Iyy)/2 * cos(2*theta) + MOI_.Ixy * sin(2*theta);
    ret.Ixy = (MOI_.Ixx - MOI_.Iyy)/2 * sin(2*theta) + MOI_.Ixy * cos(2*theta);
    return ret;
  }

  SecondMomentOfArea Geometry::Ixx() const {
      return MOI_.Ixx;
  }

  SecondMomentOfArea Geometry::Ixx(const Length & y) const {
    return Ixx() + area()*(y*y);
  }

  SecondMomentOfArea Geometry::Ixx(const Angle & theta) const {
      return (MOI_.Ixx + MOI_.Iyy)/2 + (MOI_.Ixx - MOI_.Iyy)/2 * cos(2*theta) - MOI_.Ixy * sin(2*theta);
  }

  SecondMomentOfArea Geometry::Iyy() const {
      return MOI_.Iyy;
  }

  SecondMomentOfArea Geometry::Iyy(const Length & x) const {
    return Iyy() + area()*(x*x);
  }

  SecondMomentOfArea Geometry::Iyy(const Angle & theta) const {
    return (MOI_.Ixx + MOI_.Iyy)/2 - (MOI_.Ixx - MOI_.Iyy)/2 * cos(2*theta) + MOI_.Ixy * sin(2*theta);
  }

  SecondMomentOfArea Geometry::Ixy() const {
      return MOI_.Ixy;
  }

  SecondMomentOfArea Geometry::Ixy(const Length & x, const Length & y) const {
    return MOI_.Ixy + area_*x*y;
  }

  SecondMomentOfArea Geometry::Ixy(const Angle & theta) const {
    return (MOI_.Ixx - MOI_.Iyy)/2 * sin(2*theta) + MOI_.Ixy * cos(2*theta);
  }

  Geometry eng::operator+(const Geometry & lh, const Geometry & rh) {
    Area composite_area = lh.area_ + rh.area_;

    LengthVec composite_centroid = {(lh.centroid_.x()*lh.area_ + rh.centroid_.x()*rh.area_)/composite_area,
      (lh.centroid_.y()*lh.area_ + rh.centroid_.y()*rh.area_)/composite_area,
      (lh.centroid_.z()*lh.area_ + rh.centroid_.z()*rh.area_)/composite_area};
    

    Geometry::AreaMomentofInertia lh_moi = lh.moment_of_inertia(composite_centroid);
    Geometry::AreaMomentofInertia rh_moi = rh.moment_of_inertia(composite_centroid);
    Geometry::AreaMomentofInertia composite_moi = {lh_moi.Ixx + rh_moi.Ixx,
      lh_moi.Iyy + rh_moi.Iyy,
      lh_moi.Ixy + rh_moi.Ixy};

    return Geometry(composite_area, composite_moi, composite_centroid);
  }

  Geometry eng::operator-(const Geometry & lh, const Geometry & rh) {
    Area composite_area = lh.area_ - rh.area_;

    LengthVec composite_centroid = {(lh.centroid_.x()*lh.area_ - rh.centroid_.x()*rh.area_)/composite_area,
      (lh.centroid_.y()*lh.area_ - rh.centroid_.y()*rh.area_)/composite_area,
      (lh.centroid_.z()*lh.area_ - rh.centroid_.z()*rh.area_)/composite_area};

    Geometry::AreaMomentofInertia lh_moi = lh.moment_of_inertia(composite_centroid);
    Geometry::AreaMomentofInertia rh_moi = rh.moment_of_inertia(composite_centroid);
    Geometry::AreaMomentofInertia composite_moi = {lh_moi.Ixx - rh_moi.Ixx,
      lh_moi.Iyy - rh_moi.Iyy,
      lh_moi.Ixy - rh_moi.Ixy};

    return Geometry(composite_area, composite_moi, composite_centroid);
  }

  Length radius_of_gyration(const SecondMomentOfArea & I, const typename Area & a) {
      return sqrt(I/a);
  }

};  // namespace eng
