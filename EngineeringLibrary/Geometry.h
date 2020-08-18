#ifndef Geometry_h_INCLUDED
#define Geometry_h_INCLUDED

// TODO: Fix this mess

/*****************************************************************//**
 * \file  Geometry.h
 * \brief Objects representing generic 2D geometric forms
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "EngineeringExport.h"

#include "Units/Length.h"
#include "Units/Area.h"
#include "Units/MomentOfArea.h"

namespace eng {

  /**
   * \class A point in 2D space representing the centroid of an area
   */
  struct ENGINEERINGLIBRARY_API Centroid {
    Length x;
    Length y;

    /**
     * \brief Construct a Centroid
     * 
     * \param xx the x position of the centroid
     * \param yy the y position of the centroid
     */
    Centroid(const Length& xx = 0_m, const Length& yy = 0_m);
  };

  /**
   * \class Moments of Inertia for a 2D area about various aves
   */
  struct ENGINEERINGLIBRARY_API AreaMomentofInertia {
    SecondMomentOfArea Ix;
    SecondMomentOfArea Iy;
    SecondMomentOfArea Ixy;
    /**
     * \brief Construct an AreaMomentofInertia
     * 
     * \param xx The Second moment of area about the x axis
     * \param yy The Second moment of area about the x axis
     * \param xy
     */
    AreaMomentofInertia(const class SecondMomentOfArea& xx = 0_m4, 
                        const class SecondMomentOfArea& yy = 0_m4,
      const SecondMomentOfArea& xy = 0_m4);
  };
  
  /**
   * \class A generic 2D geometry
   */
  class ENGINEERINGLIBRARY_API Geometry {
  public:
    /**
     * \brief Construct a Geometry
     * 
     * \param c The centroid of the geometry
     */
    Geometry(const Centroid& c=(0_m, 0_m));
    /**
     * \brief Construct a geometry
     * 
     * \param aa The area of the geometry
     * \param mmoi the area moment of inertia of the geometry
     * \param c The centroid of the geometry
     */
    Geometry(const class Area& aa, const AreaMomentofInertia& mmoi,
      const Centroid& c=(0_m, 0_m));
    virtual ~Geometry() = default;

    /* Return the centroid of this geometry. */
    Centroid centroid() const;

    /* Return the area of the shape. */
    Area area() const;
    // TODO: Modify this function (or add a different one) to handle rotation of axes
    /* Return the moment of inertia of a shape about its own centroid. */
    AreaMomentofInertia moment_of_inertia() const; 
    /* Calculate the moment of inertia of a shape using a Parallel Axis shift. */
    AreaMomentofInertia moment_of_inertia(const Centroid& pt) const;

  protected:
    Centroid _centroid;
    mutable Area _area;
    mutable AreaMomentofInertia _MOI;

    virtual Area calculate_area() const;
    virtual AreaMomentofInertia calculate_moment_of_inertia() const;

    mutable bool _area_valid;
    mutable bool _moi_valid;
  };


  /* ***********************************************************************************************
   * Geometry children - specifications of some common geometric shapes
   */
  
  /**
   * \class Circle a Circle
   */
  class ENGINEERINGLIBRARY_API Circle : public Geometry {
  public:
    /**
     * \brief Construct a Circle
     * 
     * \param dd diameter of the circle
     * \param c the centroid of the circle
     */
    Circle(const Length& dd = 0_m, const Centroid& c = (0_m, 0_m));
    ~Circle() override = default;

    Length diameter() const { return diam; }

  private:
    Length diam;

    Area calculate_area() const override;
    AreaMomentofInertia calculate_moment_of_inertia() const override;
  };

  /**
   * \class SemiCircle a semi circle
   */
  class ENGINEERINGLIBRARY_API SemiCircle : public Geometry {
  public:
    /**
     * \brief Construct a SemiCircle
     * 
     * \param dd The diameter of the SemiCircle
     * \param c The centroid of the SemiCircle
     */
    SemiCircle(const Length& dd = 0_m, const Centroid& c = (0_m, 0_m));
    ~SemiCircle() override = default;
    
  private:
    Length diam;

    Area calculate_area() const override;
    AreaMomentofInertia calculate_moment_of_inertia() const override;
  };

  /**
   * \class HollowCircle A hollow circle
   */
  class ENGINEERINGLIBRARY_API HollowCircle : public Geometry {
  public:
    /**
     * \brief Construct a HollowCircle
     * 
     * \param ddo The diameter of the outer circle
     * \param ddi The diameter of the inner circle
     * \param c The centroid of the HollowCircle
     */
    HollowCircle(const Length& ddo = 0_m, const Length& ddi = 0_m,
      const Centroid& c = (0_m, 0_m));

    Length outer_diameter() const { return diam_out; }
    Length inner_diameter() const { return diam_in; }

  private:
    Length diam_out;
    Length diam_in;

    Area calculate_area() const override;
    AreaMomentofInertia calculate_moment_of_inertia() const override;
  };

  /**
   * \class Rectangle A rectangle
   */
  class ENGINEERINGLIBRARY_API Rectangle : public Geometry {
  public:
    /**
     * \brief Construct a Rectangle
     * 
     * \param bb The length of the base of the Rectangle
     * \param hh The length of the height of the Rectangle
     * \param c The centroid of the Rectangle
     */
    Rectangle(const Length& bb = 0_m, const Length& hh = 0_m,
      const Centroid& c = (0_m, 0_m));
    ~Rectangle() override = default;

    Length base() const { return b; }
    Length height() const { return h; }

  private:
    Length b;
    Length h;

    Area calculate_area() const override;
    AreaMomentofInertia calculate_moment_of_inertia() const override;
  };

  /**
   * \class HollowRectangle A hollow rectangle
   */
  class ENGINEERINGLIBRARY_API HollowRectangle : public Geometry {
  public:
    /**
     * \brief Construct a HollowRectangle
     * 
     * \param bbo The base of the outer rectangle
     * \param hho The height of the outer rectangle
     * \param bbi The base of the inner rectangle
     * \param hhi The height of the inner rectangle
     * \param c The centroid of the HollowRectangle
     */
    HollowRectangle(const Length& bbo = 0_m, const Length& hho = 0_m,
      const Length& bbi = 0_m, const Length& hhi = 0_m,
      const Centroid& c = (0_m, 0_m));

    Length outer_base() const { return bo; }
    Length outer_height() const { return ho; }
    Length inner_base() const { return bi; }
    Length inner_height() const { return hi; }

  private:
    Length bo;
    Length ho;
    Length bi;
    Length hi;

    Area calculate_area() const override;
    AreaMomentofInertia calculate_moment_of_inertia() const override;
  };

};  // namespace eng

#endif
