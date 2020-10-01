#include "pch.h"

#include "Geometry.h"
#include "GeometricProperty.h"

#include "Units/PhysicsMath.h"
#include "Units/MomentOfArea.h"
#include "Units/Volume.h"
#include "Units/Area.h"
#include "Units/Length.h"
#include "Units/Angle.h"


namespace eng {

  /* 
   * Moment of Inertia
   */
  AreaMomentofInertia moment_of_inertia(const std::vector<Geometry*>& geo) {
    return moment_of_inertia(geo, centroid(geo));
  }

  AreaMomentofInertia moment_of_inertia(const std::vector<Geometry*>& geo, const Point& pt) {
    AreaMomentofInertia ret{0_m4, 0_m4, 0_m4};

    for (auto& g : geo) {
      auto i = g->moment_of_inertia(pt);
      ret.Ix += i.Ix;
      ret.Iy += i.Iy;
      ret.Ixy += i.Ixy;
    }

    return ret;
  }

  AreaMomentofInertia moment_of_inertia(const std::vector<Geometry*>& geo, 
                                        const std::vector<Geometry*>& neg, const Point& pt) {
    AreaMomentofInertia ret{0_m4, 0_m4, 0_m4},
      ret_pos = moment_of_inertia(geo, pt),
      ret_neg = moment_of_inertia(neg, pt);

    ret.Ix = ret_pos.Ix - ret_neg.Ix;
    ret.Iy = ret_pos.Iy - ret_neg.Iy;
    ret.Ixy = ret_pos.Ixy - ret_neg.Ixy;

   return ret;
  }

  AreaMomentofInertia moment_of_inertia(const std::vector<Geometry*>& geo, 
                                        const std::vector<Geometry*>& neg) {
    Point pt = centroid(geo, neg);
    
    return moment_of_inertia(geo, neg, pt);
  }

  /*
   * Radius of Gyration
   */
  Length radius_of_gyration(const SecondMomentOfArea& I, const Area& a) {
    return sqrt(I/a);
  }

  Length radius_of_gyration(const Geometry& geo, const Axis& axis) {
    SecondMomentOfArea I;
    switch (axis) {
      case Axis::X:
        I = geo.moment_of_inertia().Ix;
        break;
      case Axis::Y:
        I = geo.moment_of_inertia().Iy;
        break;
    };
    return radius_of_gyration(I, geo.area());
  }

  /*
   *  Point
   */
  Point centroid(const std::vector<Geometry*>& geo) {
    FirstMomentOfArea Qx{0_m3};
    FirstMomentOfArea Qy{0_m3};
    Area a{0_m2};
    Point ret;

    for (auto& g : geo) {
      auto area = g->area();
      auto cen = g->centroid();
      Qx += area * cen.x;
      Qy += area * cen.y;
      a += area;
    }

    ret.x = Qx/a;
    ret.y = Qx/a;

    return ret;
  }

  Point centroid(const std::vector<Geometry*>& geo, const std::vector<Geometry*>& neg) {
    FirstMomentOfArea Qx{0_m3};
    FirstMomentOfArea Qy{0_m3};
    Area a{0_m2};
    Point ret;

    // sum up the positive sections of the geometry
    for (auto& g : geo) {
      auto area = g->area();
      auto cen = g->centroid();
      Qx += area * cen.x;
      Qy += area * cen.y;
      a += area;
    }

    // subtract out the negative sections of the geometry
    for (auto& g : neg) {
      auto area = g->area();
      auto cen = g->centroid();
      Qx -= area * cen.x;
      Qy -= area * cen.y;
      a -= area;
    }

    ret.x = Qx/a;
    ret.y = Qx/a;

    return ret;
  }

};  // namespace eng


