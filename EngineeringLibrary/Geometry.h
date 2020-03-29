#ifndef Geometry_h_INCLUDED
#define Geometry_h_INCLUDED

#include "EngineeringExport.h"

#include "PhysicsLibrary/Length.h"
#include "PhysicsLibrary/Area.h"
#include "PhysicsLibrary/MomentOfArea.h"

namespace eng {

  /* A point in 2D space representing the centroid of an area */
  struct ENGINEERINGLIBRARY_API Centroid {
    physics::Length x;
    physics::Length y;

    Centroid(const physics::Length& xx = 0_m, const physics::Length& yy = 0_m);
  };

  /* A set of Moments of Inertia values for a 2D area */
  struct ENGINEERINGLIBRARY_API AreaMomentofInertia {
    physics::SecondMomentOfArea Ix;
    physics::SecondMomentOfArea Iy;
    physics::SecondMomentOfArea Ixy;

    AreaMomentofInertia(const class physics::SecondMomentOfArea& xx = 0_m4, const class physics::SecondMomentOfArea& yy = 0_m4,
      const physics::SecondMomentOfArea& xy = 0_m4);
  };
  
  /* A generic 2D geometry */
  class ENGINEERINGLIBRARY_API Geometry {
  public:
    Geometry(const Centroid& c=(0_m, 0_m));
    Geometry(const class physics::Area& aa, const AreaMomentofInertia& mmoi,
      const Centroid& c=(0_m, 0_m));
    virtual ~Geometry() = default;

    /* Return the centroid of this geometry. */
    Centroid centroid() const;

    /* Return the area of the shape. */
    physics::Area area() const;
    // TODO: Modify this function (or add a different one) to handle rotation of axes
    /* Return the moment of inertia of a shape about its own centroid. */
    AreaMomentofInertia moment_of_inertia() const; 
    /* Calculate the moment of inertia of a shape using a Parallel Axis shift. */
    AreaMomentofInertia moment_of_inertia(const Centroid& pt) const;

    // TODO: This operator should allow implicit conversions from Geometry children to Geometry
    // TODO: Fix this functionality
    operator Geometry() const;

  protected:
    Centroid _centroid;

    virtual physics::Area calculate_area() const;
    virtual AreaMomentofInertia calculate_moment_of_inertia() const;

  private:
    mutable physics::Area _area;
    mutable AreaMomentofInertia _MOI;

    mutable bool _area_valid;
    mutable bool _moi_valid;
  };

  //? MAYBE DELETE THIS?
  /* Create a generic Geometry object from one of its children */
  Geometry ENGINEERINGLIBRARY_API create_geometry(const Geometry& geo);


  /* ***********************************************************************************************
   * Geometry children - specifications of some common geometric shapes
   */
  
  /* A circle */
  class ENGINEERINGLIBRARY_API Circle : public Geometry {
  public:
    Circle(const physics::Length& dd = 0_m, const Centroid& c = (0_m, 0_m));

    physics::Length diameter() const { return diam; }

  private:
    physics::Length diam;

    physics::Area calculate_area() const override;
    AreaMomentofInertia calculate_moment_of_inertia() const override;
  };

  /* A semi circle */
  class ENGINEERINGLIBRARY_API SemiCircle : public Geometry {
  public:
    SemiCircle(const physics::Length& dd = 0_m, const Centroid& c = (0_m, 0_m));
    ~SemiCircle() = default;
    
  private:
    physics::Length diam;

    physics::Area calculate_area() const override;
    AreaMomentofInertia calculate_moment_of_inertia() const override;
  };

  /* A hollow circle */
  class ENGINEERINGLIBRARY_API HollowCircle : public Geometry {
  public:
    HollowCircle(const physics::Length& ddo = 0_m, const physics::Length& ddi = 0_m,
      const Centroid& c = (0_m, 0_m));

    physics::Length outer_diameter() const { return diam_out; }
    physics::Length inner_diameter() const { return diam_in; }

  private:
    physics::Length diam_out;
    physics::Length diam_in;

    physics::Area calculate_area() const override;
    AreaMomentofInertia calculate_moment_of_inertia() const override;
  };

  /* A rectangle */
  class ENGINEERINGLIBRARY_API Rectangle : public Geometry {
  public:
    Rectangle(const physics::Length& bb = 0_m, const physics::Length& hh = 0_m,
      const Centroid& c = (0_m, 0_m));

    physics::Length base() const { return b; }
    physics::Length height() const { return h; }

  private:
    physics::Length b;
    physics::Length h;

    physics::Area calculate_area() const override;
    AreaMomentofInertia calculate_moment_of_inertia() const override;
  };

  /* A hollow rectangle */
  class ENGINEERINGLIBRARY_API HollowRectangle : public Geometry {
  public:
    HollowRectangle(const physics::Length& bbo = 0_m, const physics::Length& hho = 0_m,
      const physics::Length& bbi = 0_m, const physics::Length& hhi = 0_m,
      const Centroid& c = (0_m, 0_m));

    physics::Length outer_base() const { return bo; }
    physics::Length outer_height() const { return ho; }
    physics::Length inner_base() const { return bi; }
    physics::Length inner_height() const { return hi; }

  private:
    physics::Length bo;
    physics::Length ho;
    physics::Length bi;
    physics::Length hi;

    physics::Area calculate_area() const override;
    AreaMomentofInertia calculate_moment_of_inertia() const override;
  };

};  // namespace eng

#endif
