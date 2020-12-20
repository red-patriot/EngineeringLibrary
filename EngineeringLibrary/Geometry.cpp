#include "pch.h"
#include "Geometry.h"

namespace eng {

  AreaMomentofInertia::AreaMomentofInertia(const SecondMomentOfArea& xx,
    const SecondMomentOfArea& yy, const SecondMomentOfArea& xy) :
    Ixx(xx),
    Iyy(yy),
    Ixy(xy) { }

  /* ***************************************************************************
   * Geometry
   */

  Geometry::Geometry(const Area& aa, const AreaMomentofInertia& mmoi,
    const LengthVec& c) :
    _centroid(c),
    _area(aa),
    _MOI(mmoi) { }

  LengthVec Geometry::centroid() const {
    return _centroid;
  }

  AreaMomentofInertia Geometry::moment_of_inertia(const LengthVec& pt) const {
    Length x = pt.x() - _centroid.x();
    Length y = pt.y() - _centroid.y();
    AreaMomentofInertia ret = moment_of_inertia();
    ret.Ixx += area()*(y*y);
    ret.Iyy += area()*(x*x);
    ret.Ixy += area()*(x*y);
    return ret;
  }

  AreaMomentofInertia Geometry::moment_of_inertia(const Angle & theta) const {
      AreaMomentofInertia ret;
      ret.Ixx = (_MOI.Ixx + _MOI.Iyy)/2 + (_MOI.Ixx - _MOI.Iyy)/2 * cos(2*theta) - _MOI.Ixy * sin(2*theta);
      ret.Iyy = (_MOI.Ixx + _MOI.Iyy)/2 - (_MOI.Ixx - _MOI.Iyy)/2 * cos(2*theta) + _MOI.Ixy * sin(2*theta);
      ret.Ixy = (_MOI.Ixx - _MOI.Iyy)/2 * sin(2*theta) + _MOI.Ixy * cos(2*theta);
      return ret;
  }

  void Geometry::calculate_area() {
    return;
  }

  void Geometry::calculate_moment_of_inertia() {
    return;
  }

  Geometry::Geometry(const LengthVec& c) :
    _centroid(c),
    _area(0_m2),
    _MOI(0_m4, 0_m4, 0_m4) { }

  /* ***************************************************************************
   * Circle
   */

  Circle::Circle(const Length& dd, const LengthVec& c) :
    diam(dd),
    Geometry(c) { 
    calculate_area();
    calculate_moment_of_inertia();
  }

  void Circle::calculate_area() {
    _area = pi * (diam*diam)/4;
    return;
  }

  void Circle::calculate_moment_of_inertia() {
    _MOI.Ixx = (pi * (diam*diam)*(diam*diam)) / 64;
    _MOI.Iyy = (pi * (diam*diam)*(diam*diam)) / 64;
    _MOI.Ixy = 0_m4;
    return;
  }

  /* ***************************************************************************
   * Semi Circle
   */

  SemiCircle::SemiCircle(const Length& dd, const LengthVec& c) :
    diam(dd),
    Geometry(c) { 
    calculate_area();
    calculate_moment_of_inertia();
  }

  void SemiCircle::calculate_area() {
    _area = pi * diam*diam/8;
    return;
  }

  void SemiCircle::calculate_moment_of_inertia() {
    _MOI.Ixx = (pi / 8 - 8 / (9*pi)) * (diam*diam)/4 * (diam*diam)/4;
    _MOI.Iyy = (pi / 8) * (diam*diam)/4 * (diam*diam)/4;
    _MOI.Ixy = 0_m4;
    return;
  }

  /* ***************************************************************************
   * HollowCircle
   */

  HollowCircle::HollowCircle(const Length& ddo, const Length& ddi, const LengthVec& c) :
    diam_out(ddo),
    diam_in(ddi),
    Geometry(c) { 
    calculate_area();
    calculate_moment_of_inertia();
  }

  void HollowCircle::calculate_area() {
    _area = pi * ((diam_out*diam_in) - (diam_in*diam_in))/4;
    return;
  }

  void HollowCircle::calculate_moment_of_inertia() {
    _MOI.Ixx = (pi * (((diam_out*diam_out)*(diam_out*diam_out))
      - ((diam_in*diam_in)*(diam_in*diam_in)))) / 64;
    _MOI.Iyy = (pi * (((diam_out*diam_out)*(diam_out*diam_out))
      - ((diam_in*diam_in)*(diam_in*diam_in)))) / 64;
    _MOI.Ixy = 0_m4;
    return;
  }

  /* ***************************************************************************
   * Rectangle
   */

  Rectangle::Rectangle(const Length& bb, const Length& hh, const LengthVec& c) :
    b(bb),
    h(hh),
    Geometry(c) { 
    calculate_area();
    calculate_moment_of_inertia();
  }

  void Rectangle::calculate_area() {
    _area = b*h;
    return;
  }

  void Rectangle::calculate_moment_of_inertia() {
    _MOI.Ixx = (b*h)*(h*h) / 12;
    _MOI.Iyy = (b*b)*(b*h) / 12;
    _MOI.Ixy = 0_m4;
    return;
  }

  /* ***************************************************************************
   * HollowRectangle
   */

  HollowRectangle::HollowRectangle(const Length& bbo, const Length& hho, const Length& bbi, 
                                   const Length& hhi, const LengthVec& c) :
    bo(bbo),
    ho(hho),
    bi(bbi),
    hi(hhi),
    Geometry(c) {
    calculate_area();
    calculate_moment_of_inertia();
  }

  void HollowRectangle::calculate_area() {
    _area = (bo*ho) - (bi*hi);
    return;
  }

  void HollowRectangle::calculate_moment_of_inertia() {
    _MOI.Ixx = ((bo*ho)*(ho*ho) - (bi*hi)*(hi*hi))/12;
    _MOI.Iyy = ((bo*bo)*(bo*ho) - (bi*bi)*(bi*hi))/12;
    _MOI.Ixy = 0_m4;
    return;
  }

}; // namespace eng
