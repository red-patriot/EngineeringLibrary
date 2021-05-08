#include "pch.h"
#include "Geometry.h"

namespace eng {

  Geometry::Geometry(const Area & area, 
                     const SecondMomentOfArea & ixx,
                     const SecondMomentOfArea & iyy, 
                     const SecondMomentOfArea & ixy, 
                     const LengthVec & centroid) :
  area_(area),
  MOI_(ixx, iyy, ixy),
  centroid_(centroid) { }

  LengthVec Geometry::centroid() const {
    return centroid_;
  }

  Area Geometry::area() const {
    return area_;
  }

  SecondMomentOfArea Geometry::Ixx() const {
      return MOI_.Ixx;
  }

  SecondMomentOfArea Geometry::Ixx(const Length& y) const {
    return Ixx() + area()*(y*y);
  }

  SecondMomentOfArea Geometry::Ixx(const Angle& theta) const {
      return (MOI_.Ixx + MOI_.Iyy)/2 + (MOI_.Ixx - MOI_.Iyy)/2 * cos(2*theta) - MOI_.Ixy * sin(2*theta);
  }

  SecondMomentOfArea Geometry::Iyy() const {
      return MOI_.Iyy;
  }

  SecondMomentOfArea Geometry::Iyy(const Length& x) const {
    return Iyy() + area()*(x*x);
  }

  SecondMomentOfArea Geometry::Iyy(const Angle& theta) const {
    return (MOI_.Ixx + MOI_.Iyy)/2 - (MOI_.Ixx - MOI_.Iyy)/2 * cos(2*theta) + MOI_.Ixy * sin(2*theta);
  }

  SecondMomentOfArea Geometry::Ixy() const {
      return MOI_.Ixy;
  }

  SecondMomentOfArea Geometry::Ixy(const Length& x, const Length& y) const {
    return MOI_.Ixy + area_*x*y;
  }

  SecondMomentOfArea Geometry::Ixy(const Angle& theta) const {
    return (MOI_.Ixx - MOI_.Iyy)/2 * sin(2*theta) + MOI_.Ixy * cos(2*theta);
  }

  Geometry eng::operator+(const Geometry& lh, const Geometry& rh) {
    Area composite_area = lh.area_ + rh.area_;

    LengthVec composite_centroid = {(lh.centroid_.x()*lh.area_ + rh.centroid_.x()*rh.area_)/composite_area,
      (lh.centroid_.y()*lh.area_ + rh.centroid_.y()*rh.area_)/composite_area,
      (lh.centroid_.z()*lh.area_ + rh.centroid_.z()*rh.area_)/composite_area};

    auto composite_ixx = rh.Ixx(composite_centroid.y()) + lh.Ixx(composite_centroid.y());
    auto composite_iyy = rh.Iyy(composite_centroid.x()) + lh.Iyy(composite_centroid.x());
    auto composite_ixy = rh.Ixy(composite_centroid.x(), composite_centroid.y())
      + lh.Ixy(composite_centroid.x(), composite_centroid.y());

    return Geometry(composite_area, composite_ixx, composite_iyy, composite_ixy, composite_centroid);
  }

  Geometry eng::operator-(const Geometry& lh, const Geometry& rh) {
    Area composite_area = lh.area_ - rh.area_;

    LengthVec composite_centroid = {(lh.centroid_.x()*lh.area_ - rh.centroid_.x()*rh.area_)/composite_area,
      (lh.centroid_.y()*lh.area_ - rh.centroid_.y()*rh.area_)/composite_area,
      (lh.centroid_.z()*lh.area_ - rh.centroid_.z()*rh.area_)/composite_area};

    auto composite_ixx = rh.Ixx(composite_centroid.y()) - lh.Ixx(composite_centroid.y());
    auto composite_iyy = rh.Iyy(composite_centroid.x()) - lh.Iyy(composite_centroid.x());
    auto composite_ixy = rh.Ixy(composite_centroid.x(), composite_centroid.y())
      - lh.Ixy(composite_centroid.x(), composite_centroid.y());

    return Geometry(composite_area, composite_ixx, composite_iyy, composite_ixy, composite_centroid);
  }

  Geometry::AreaMomentofInertia::AreaMomentofInertia(const SecondMomentOfArea& xx,
                                                     const SecondMomentOfArea& yy,
                                                     const SecondMomentOfArea& xy) :
    Ixx(xx),
    Iyy(yy),
    Ixy(xy) { }

  Length radius_of_gyration(const SecondMomentOfArea& I, const typename Area& a) {
      return sqrt(I/a);
  }

};  // namespace eng
