#include "pch.h"
#include "Geometry.h"

#include "Units/PhysicsMath.h"

namespace eng {

  Point::Point(const Length& xx, const Length& yy) :
    x(xx),
    y(yy) { }

  AreaMomentofInertia::AreaMomentofInertia(const SecondMomentOfArea& xx,
    const SecondMomentOfArea& yy, const SecondMomentOfArea& xy) :
    Ix(xx),
    Iy(yy),
    Ixy(xy) { }

  /* ***************************************************************************
   * Geometry
   */

  Geometry::Geometry(const Area& aa, const AreaMomentofInertia& mmoi,
    const Point& c) :
    _centroid(c),
    _area(aa),
    _MOI(mmoi) { }

  Point Geometry::centroid() const {
    return _centroid;
  }

  AreaMomentofInertia Geometry::moment_of_inertia(const Point& pt) const {
    Length x = pt.x - _centroid.x;
    Length y = pt.y - _centroid.y;
    AreaMomentofInertia ret = moment_of_inertia();
    ret.Ix += area()*(y*y);
    ret.Iy += area()*(x*x);
    ret.Ixy += area()*(x*y);
    return ret;
  }

  void Geometry::calculate_area() {
    return;
  }

  void Geometry::calculate_moment_of_inertia() {
    return;
  }

  Geometry::Geometry(const Point& c) :
    _centroid(c),
    _area(0_m2),
    _MOI(0_m4, 0_m4, 0_m4) { }

  /* ***************************************************************************
   * Circle
   */

  Circle::Circle(const Length& dd, const Point& c) :
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
    _MOI.Ix = (pi * (diam*diam)*(diam*diam)) / 64;
    _MOI.Iy = (pi * (diam*diam)*(diam*diam)) / 64;
    _MOI.Ixy = 0_m4;
    return;
  }

  /* ***************************************************************************
   * Semi Circle
   */

  SemiCircle::SemiCircle(const Length& dd, const Point& c) :
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
    _MOI.Ix = (pi / 8 - 8 / (9*pi)) * (diam*diam)/4 * (diam*diam)/4;
    _MOI.Iy = (pi / 8) * (diam*diam)/4 * (diam*diam)/4;
    _MOI.Ixy = 0_m4;
    return;
  }

  /* ***************************************************************************
   * HollowCircle
   */

  HollowCircle::HollowCircle(const Length& ddo, const Length& ddi, const Point& c) :
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
    _MOI.Ix = (pi * (((diam_out*diam_out)*(diam_out*diam_out))
      - ((diam_in*diam_in)*(diam_in*diam_in)))) / 64;
    _MOI.Iy = (pi * (((diam_out*diam_out)*(diam_out*diam_out))
      - ((diam_in*diam_in)*(diam_in*diam_in)))) / 64;
    _MOI.Ixy = 0_m4;
    return;
  }

  /* ***************************************************************************
   * Rectangle
   */

  Rectangle::Rectangle(const Length& bb, const Length& hh, const Point& c) :
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
    _MOI.Ix = (b*h)*(h*h) / 12;
    _MOI.Iy = (b*b)*(b*h) / 12;
    _MOI.Ixy = 0_m4;
    return;
  }

  /* ***************************************************************************
   * HollowRectangle
   */

  HollowRectangle::HollowRectangle(const Length& bbo, const Length& hho, const Length& bbi, 
                                   const Length& hhi, const Point& c) :
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
    _MOI.Ix = ((bo*ho)*(ho*ho) - (bi*hi)*(hi*hi))/12;
    _MOI.Iy = ((bo*bo)*(bo*ho) - (bi*bi)*(bi*hi))/12;
    _MOI.Ixy = 0_m4;
    return;
  }

}; // namespace eng
