#include "pch.h"
#include "Geometry.h"

#include "PhysicsLibrary/PhysicsMath.h"
#include "PhysicsLibrary/Area.h"

namespace eng {

  Centroid::Centroid(const physics::Length& xx, const physics::Length& yy) :
    x(xx),
    y(yy) { }

  AreaMomentofInertia::AreaMomentofInertia(const physics::SecondMomentOfArea& xx,
    const physics::SecondMomentOfArea& yy, const physics::SecondMomentOfArea& xy) :
    Ix(xx),
    Iy(yy),
    Ixy(xy) { }

  /* ***********************************************************************************************
   * Geometry
   */
  Geometry::Geometry(const physics::Length& xx, const physics::Length& yy) :
    c(xx, yy),
    a(0_m2),
    MOI(0_m4) { }

  Geometry::Geometry(const physics::Area& aa, const AreaMomentofInertia& mmoi,
    const physics::Length& xx, const physics::Length& yy) :
    a(aa),
    MOI(mmoi),
    c(xx, yy) { }

  Centroid Geometry::centroid() const {
    return c;
  }

  physics::Area Geometry::area() const {
    return a;
  }

  AreaMomentofInertia Geometry::moment_of_inertia() const {
    return MOI;
  }

  AreaMomentofInertia Geometry::moment_of_inertia(const Centroid& pt) const {
    physics::Length x = pt.x - c.x;
    physics::Length y = pt.y - c.y;
    AreaMomentofInertia ret = moment_of_inertia();
    ret.Ix += area()*(y*y);
    ret.Iy += area()*(x*x);
    ret.Ixy += area()*(x*y);
    return ret;
  }

  Geometry create_geometry(const Geometry& geo) {
    return Geometry(geo.area(), geo.moment_of_inertia(), geo.centroid().x, geo.centroid().y);
  }

  /* ***********************************************************************************************
   * Circle
   */

  Circle::Circle(const physics::Length& dd, const physics::Length& xx, const physics::Length& yy) :
    diam(dd),
    Geometry(xx, yy) { }

  physics::Area Circle::area() const {
    return pi * (diam*diam)/4;
  }

  AreaMomentofInertia Circle::moment_of_inertia() const {
    AreaMomentofInertia ret;
    ret.Ix = (pi * (diam*diam)*(diam*diam)) / 64;
    ret.Iy = (pi * (diam*diam)*(diam*diam)) / 64;
    ret.Ixy = 0_m4;
    return ret;
  }

  AreaMomentofInertia Circle::moment_of_inertia(const Centroid& pt) const {
    return Geometry::moment_of_inertia(pt);
  }

  /* ***********************************************************************************************
   * Semi Circle
   */

  SemiCircle::SemiCircle(const physics::Length& dd, const physics::Length& xx, const physics::Length& yy) :
    diam(dd),
    Geometry(xx, yy) { }

  physics::Area SemiCircle::area() const {
    return pi * diam*diam/8;
    return pi * diam*diam/8;
  }

  AreaMomentofInertia SemiCircle::moment_of_inertia() const {
    AreaMomentofInertia ret;
    ret.Ix = (pi / 8 - 8 / (9*pi)) * (diam*diam)/4 * (diam*diam)/4;
    ret.Iy = (pi / 8) * (diam*diam)/4 * (diam*diam)/4;
    ret.Ixy = 0_m4;
    return ret;
  }

  AreaMomentofInertia SemiCircle::moment_of_inertia(const Centroid& pt) const {
    return Geometry::moment_of_inertia(pt);
  }

  /* ***********************************************************************************************
   * HollowCircle
   */

  HollowCircle::HollowCircle(const physics::Length& ddo, const physics::Length& ddi, const physics::Length& xx, const physics::Length& yy) :
    diam_out(ddo),
    diam_in(ddi),
    Geometry(xx, yy) { }

  physics::Area HollowCircle::area() const {
    return pi * ((diam_out*diam_in) - (diam_in*diam_in))/4;
  }

  AreaMomentofInertia HollowCircle::moment_of_inertia() const {
    AreaMomentofInertia ret;
    ret.Ix = (pi * (((diam_out*diam_out)*(diam_out*diam_out))
      - ((diam_in*diam_in)*(diam_in*diam_in)))) / 64;
    ret.Iy = (pi * (((diam_out*diam_out)*(diam_out*diam_out))
      - ((diam_in*diam_in)*(diam_in*diam_in)))) / 64;
    ret.Ixy = 0_m4;
    return ret;
  }

  AreaMomentofInertia HollowCircle::moment_of_inertia(const Centroid& pt) const {
    return Geometry::moment_of_inertia(pt);
  }

  /* ***********************************************************************************************
   * Rectangle
   */

  Rectangle::Rectangle(const physics::Length& bb, const physics::Length& hh, const physics::Length& xx, const physics::Length& yy) :
    b(bb),
    h(hh),
    Geometry(xx, yy) { }

  physics::Area Rectangle::area() const {
    return b*h;
  }

  AreaMomentofInertia Rectangle::moment_of_inertia() const {
    AreaMomentofInertia ret;
    ret.Ix = (b*h)*(h*h) / 12;
    ret.Iy = (b*b)*(b*h) / 12;
    ret.Ixy = 0_m4;

    return ret;
  }

  AreaMomentofInertia Rectangle::moment_of_inertia(const Centroid& pt) const {
    return Geometry::moment_of_inertia(pt);
  }

  /* ***********************************************************************************************
   * HollowRectangle
   */

  HollowRectangle::HollowRectangle(const physics::Length& bbo, const physics::Length& hho, const physics::Length& bbi, const physics::Length& hhi, const physics::Length& xx, const physics::Length& yy) :
    bo(bbo),
    ho(hho),
    bi(bbi),
    hi(hhi) { }

  physics::Area HollowRectangle::area() const {
    return (bo*ho) - (bi*hi);
  }

  AreaMomentofInertia HollowRectangle::moment_of_inertia() const {
    AreaMomentofInertia ret;
    ret.Ix = ((bo*ho)*(ho*ho) - (bi*hi)*(hi*hi))/12;
    ret.Iy = ((bo*bo)*(bo*ho) - (bi*bi)*(bi*hi))/12;
    ret.Ixy = 0_m4;
    return ret;
  }

  AreaMomentofInertia HollowRectangle::moment_of_inertia(const Centroid& pt) const {
    return Geometry::moment_of_inertia(pt);
  }

}; // namespace eng
