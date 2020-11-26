#pragma once

// TODO: Fix this mess

/*****************************************************************//**
 * \file  Geometry.h
 * \brief Objects representing generic 2D geometric forms
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "Units/Length.h"
#include "Units/Area.h"
#include "Units/MomentOfArea.h"

namespace eng {

  /** Area moments of inertia for a 2D area about various axes
   * \struct AreaMomentofInertia
   */
  struct AreaMomentofInertia {
    SecondMomentOfArea Ix;
    SecondMomentOfArea Iy;
    SecondMomentOfArea Ixy;
    /**
     * \brief AreaMomentofInertia constructor
     * 
     * \param xx The Second moment of area about the x axis
     * \param yy The Second moment of area about the x axis
     * \param xy
     */
    AreaMomentofInertia(const SecondMomentOfArea& xx = 0_m4, 
                        const SecondMomentOfArea& yy = 0_m4,
                        const SecondMomentOfArea& xy = 0_m4);
  };
  
  /** A generic 2D geometry
   * \class Geometry 
   * 
   * \note The user can define any children of Geometry not defined here,
   *  but all Geometry children should call calculate_area and 
   *  calculate_moment_of_inertia in their constructors to work properly.
   */
  class Geometry {
  public:
    /**
     * \brief Geometry constructor
     * 
     * \param aa The area of the geometry
     * \param mmoi the area moment of inertia of the geometry
     * \param c The centroid of the geometry
     */
    Geometry(const Area& aa, const AreaMomentofInertia& mmoi,
             const LengthVec& c = {0_m, 0_m, 0_m});
    /**
     * \brief Geometry default destructor
     */
    virtual ~Geometry() = default;

    /** Returns the centroid of the Geometry.
     */
    LengthVec centroid() const;

    /** Returns the area of the Geometry.
     */
    Area area() const { return _area; }
    
    /** Return the moment of inertia of a shape about its own centroid.
     */
    AreaMomentofInertia moment_of_inertia() const { return _MOI; }
    /**
     * Calculate the moment of inertia of a shape using a Parallel Axis shift.
     * 
     * \param pt The point about which to calculate the mement of inertia
     * \return the area moment of inertia of this Geometry about pt
     */
    AreaMomentofInertia moment_of_inertia(const LengthVec& pt) const;
    // TODO: Add a function to handle rotation of axes

  protected:
    LengthVec _centroid; /**<The centroid of this Geometry in space */
    Area _area; /**<The area of this Geometry */
    AreaMomentofInertia _MOI; /**<The moment of inertia of this 
                                    Geometry about the X, Y and XY axes */

    /** An overrideable function used for calculating the area of a 
     *  Geometry using whichever formula is appropriate.
     */
    virtual void calculate_area();
    /** An overrideable function used for calculating the area moment of 
     *  inertia of a Geometry using whichever formula is appropriate.
     */
    virtual void calculate_moment_of_inertia();

    /**
     * \brief Geometry child constructor
     * 
     * This constructor is intended for use only by Geometry children. 
     */
    Geometry(const LengthVec& c);
  };


  /* ***********************************************************************************************
   * Geometry children - specifications of some common geometric shapes
   */
  
  /** A circle
   * \class Circle 
   */
  class Circle : public Geometry {
  public:
    /**
     * \brief Circle constructor
     * 
     * \param dd diameter of the circle
     * \param c the centroid of the circle
     */
    Circle(const Length& dd = 0_m, const LengthVec& c = {0_m, 0_m, 0_m});
    ~Circle() override = default;

    Length diameter() const { return diam; }

  private:
    Length diam;

    void calculate_area() override;
    void calculate_moment_of_inertia() override;
  };

  /** A semi circle
   * \class SemiCircle 
   */
  class SemiCircle : public Geometry {
  public:
    /**
     * \brief SemiCircle constructor
     * 
     * \param dd The diameter of the SemiCircle
     * \param c The centroif the SemiCircle
     */
    SemiCircle(const Length& dd = 0_m, const LengthVec& c = {0_m, 0_m, 0_m});
    ~SemiCircle() override = default;
    
  private:
    Length diam;

    void calculate_area() override;
    void calculate_moment_of_inertia() override;
  };

  /** A hollow circle
   * \class HollowCircle
   */
  class HollowCircle : public Geometry {
  public:
    /**
     * \brief HollowCircle constructor
     * 
     * \param ddo The diameter of the outer circle
     * \param ddi The diameter of the inner circle
     * \param c The centroid of the HollowCircle
     */
    HollowCircle(const Length& ddo = 0_m, const Length& ddi = 0_m,
      const LengthVec& c = {0_m, 0_m, 0_m});

    Length outer_diameter() const { return diam_out; }
    Length inner_diameter() const { return diam_in; }

  private:
    Length diam_out;
    Length diam_in;

    void calculate_area() override;
    void calculate_moment_of_inertia() override;
  };

  /** A rectangle
   * \class Rectangle
   */
  class Rectangle : public Geometry {
  public:
    /**
     * \brief Rectangle constructor
     * 
     * \param bb The length of the base of the Rectangle
     * \param hh The length of the height of the Rectangle
     * \param c The centroid of the Rectangle
     */
    Rectangle(const Length& bb = 0_m, const Length& hh = 0_m,
      const LengthVec& c = {0_m, 0_m, 0_m});
    ~Rectangle() override = default;

    Length base() const { return b; }
    Length height() const { return h; }

  private:
    Length b;
    Length h;

    void calculate_area() override;
    void calculate_moment_of_inertia() override;
  };

  /** A hollow rectangle
   * \class HollowRectangle
   */
  class HollowRectangle : public Geometry {
  public:
    /**
     * \brief HollowRectangle constructor
     * 
     * \param bbo The base of the outer rectangle
     * \param hho The height of the outer rectangle
     * \param bbi The base of the inner rectangle
     * \param hhi The height of the inner rectangle
     * \param c The centroid of the HollowRectangle
     */
    HollowRectangle(const Length& bbo = 0_m, const Length& hho = 0_m,
      const Length& bbi = 0_m, const Length& hhi = 0_m,
      const LengthVec& c = {0_m, 0_m, 0_m});

    Length outer_base() const { return bo; }
    Length outer_height() const { return ho; }
    Length inner_base() const { return bi; }
    Length inner_height() const { return hi; }

  private:
    Length bo;
    Length ho;
    Length bi;
    Length hi;

    void calculate_area() override;
    void calculate_moment_of_inertia() override;
  };

};  // namespace eng

