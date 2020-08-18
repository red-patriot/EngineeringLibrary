#include "pch.h"
#include "Geometry.h"

#include "Units/PhysicsMath.h"

namespace eng {

  Centroid::Centroid(const Length& xx, const Length& yy) :
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
  Geometry::Geometry(const Centroid& c) :
    _centroid(c),
    _area(0_m2),
    _MOI(0_m4),
    _area_valid(false),
    _moi_valid(false) { }

  Geometry::Geometry(const Area& aa, const AreaMomentofInertia& mmoi,
    const Centroid& c) :
    _centroid(c),
    _area(aa),
    _MOI(mmoi),
    _area_valid(true),
    _moi_valid(true) { }

  Centroid Geometry::centroid() const {
    return _centroid;
  }

  Area Geometry::area() const {
    if (!_area_valid) {
      _area_valid = true;
      _area = calculate_area();
    }
    return _area;
  }

  AreaMomentofInertia Geometry::moment_of_inertia() const {
    if (!_moi_valid) {
      _moi_valid = true;
      _MOI = calculate_moment_of_inertia();
    }
    return _MOI;
  }

  AreaMomentofInertia Geometry::moment_of_inertia(const Centroid& pt) const {
    Length x = pt.x - _centroid.x;
    Length y = pt.y - _centroid.y;
    AreaMomentofInertia ret = moment_of_inertia();
    ret.Ix += area()*(y*y);
    ret.Iy += area()*(x*x);
    ret.Ixy += area()*(x*y);
    return ret;
  }

  Area Geometry::calculate_area() const {
    return 0_m2;
  }

  AreaMomentofInertia Geometry::calculate_moment_of_inertia() const {
    return 0_m4;
  }

  /* ***************************************************************************
   * Circle
   */

  Circle::Circle(const Length& dd, const Centroid& c) :
    diam(dd),
    Geometry(c) { }

  Area Circle::calculate_area() const {
    return pi * (diam*diam)/4;
  }

  AreaMomentofInertia Circle::calculate_moment_of_inertia() const {
    AreaMomentofInertia ret;
    ret.Ix = (pi * (diam*diam)*(diam*diam)) / 64;
    ret.Iy = (pi * (diam*diam)*(diam*diam)) / 64;
    ret.Ixy = 0_m4;
    return ret;
  }

  /* ***************************************************************************
   * Semi Circle
   */

  SemiCircle::SemiCircle(const Length& dd, const Centroid& c) :
    diam(dd),
    Geometry(c) { }

  Area SemiCircle::calculate_area() const {
    return pi * diam*diam/8;
    return pi * diam*diam/8;
  }

  AreaMomentofInertia SemiCircle::calculate_moment_of_inertia() const {
    AreaMomentofInertia ret;
    ret.Ix = (pi / 8 - 8 / (9*pi)) * (diam*diam)/4 * (diam*diam)/4;
    ret.Iy = (pi / 8) * (diam*diam)/4 * (diam*diam)/4;
    ret.Ixy = 0_m4;
    return ret;
  }

  /* ***************************************************************************
   * HollowCircle
   */

  HollowCircle::HollowCircle(const Length& ddo, const Length& ddi, const Centroid& c) :
    diam_out(ddo),
    diam_in(ddi),
    Geometry(c) { }

  Area HollowCircle::calculate_area() const {
    return pi * ((diam_out*diam_in) - (diam_in*diam_in))/4;
  }

  AreaMomentofInertia HollowCircle::calculate_moment_of_inertia() const {
    AreaMomentofInertia ret;
    ret.Ix = (pi * (((diam_out*diam_out)*(diam_out*diam_out))
      - ((diam_in*diam_in)*(diam_in*diam_in)))) / 64;
    ret.Iy = (pi * (((diam_out*diam_out)*(diam_out*diam_out))
      - ((diam_in*diam_in)*(diam_in*diam_in)))) / 64;
    ret.Ixy = 0_m4;
    return ret;
  }

  /* ***************************************************************************
   * Rectangle
   */

  Rectangle::Rectangle(const Length& bb, const Length& hh, const Centroid& c) :
    b(bb),
    h(hh),
    Geometry(c) { }

  Area Rectangle::calculate_area() const {
    return b*h;
  }

  AreaMomentofInertia Rectangle::calculate_moment_of_inertia() const {
    AreaMomentofInertia ret;
    ret.Ix = (b*h)*(h*h) / 12;
    ret.Iy = (b*b)*(b*h) / 12;
    ret.Ixy = 0_m4;

    return ret;
  }

  /* ***************************************************************************
   * HollowRectangle
   */

  HollowRectangle::HollowRectangle(const Length& bbo, const Length& hho, const Length& bbi, 
                                   const Length& hhi, const Centroid& c) :
    bo(bbo),
    ho(hho),
    bi(bbi),
    hi(hhi) { }

  Area HollowRectangle::calculate_area() const {
    return (bo*ho) - (bi*hi);
  }

  AreaMomentofInertia HollowRectangle::calculate_moment_of_inertia() const {
    AreaMomentofInertia ret;
    ret.Ix = ((bo*ho)*(ho*ho) - (bi*hi)*(hi*hi))/12;
    ret.Iy = ((bo*bo)*(bo*ho) - (bi*bi)*(bi*hi))/12;
    ret.Ixy = 0_m4;
    return ret;
  }

}; // namespace eng
