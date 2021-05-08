#pragma once

/*****************************************************************//**
 * \file   Geometry.h
 * \brief  An object to represent any geometric form in 2D space
 *
 *
 * \author bltan
 * \date   January 2021
 *********************************************************************/

#include "../Units/Angle.h"
#include "../Units/Length.h"
#include "../Units/Area.h"
#include "../Units/MomentOfArea.h"

namespace eng {

  /** A generic 2D geometry
   * \class Geometry
   * \addtogroup Geometric
   */
  class Geometry {
    /** Combine geometries to create composite shapes. */
    friend Geometry operator+ (const Geometry& lh, const Geometry& rh);
    friend Geometry operator- (const Geometry& lh, const Geometry& rh);
  public:
    /**
     * \brief Geometry constructor
     * 
     * \param area The area of the geometry
     * \param ixx The area moment of inertia about the geometry's x axis
     * \param iyy The area moment of inertia about the geometry's y axis
     * \param ixy The product of inertia of the geometry
     * \param centroid The location of the geometry's centroid
     */
    Geometry(const Area& area = 0_m2,
             const SecondMomentOfArea& ixx = 0_m4,
             const SecondMomentOfArea& iyy = 0_m4,
             const SecondMomentOfArea& ixy = 0_m4,
             const LengthVec& centroid = {0_m, 0_m, 0_m});

    /** Returns the centroid of the Geometry.
     */
    LengthVec centroid() const;

    /** Returns the area of the Geometry.
     */
    Area area() const;

    /** Return the XX moment of inertia of a shape about its own centroid.
     */
    SecondMomentOfArea Ixx() const;
    /**
     * Calculate the XXmoment of inertia of a shape using a Parallel Axis shift.
     *
     * \param y The y location about which to calculate the mement of inertia
     * \return the area moment of inertia of this Geometry about y
     */
    SecondMomentOfArea Ixx(const Length& y) const;
    /**
     * Calculate the moment of inertia of a shape along rotated axes.
     *
     * \param theta The angle of rotation to the new axes from the old ones,
     *   where positive is counterclockwise from the axes.
     * \return the area moment of inertia of a shape about axes rotated by theta
     */
    SecondMomentOfArea Ixx(const Angle& theta) const;

    /** Return the YY moment of inertia of a shape about its own centroid.
     */
    SecondMomentOfArea Iyy() const;
    /**
     * Calculate the YY moment of inertia of a shape using a Parallel Axis shift.
     *
     * \param x The x location about which to calculate the moment of inertia
     * \return the area moment of inertia of this Geometry about x
     */
    SecondMomentOfArea Iyy(const Length& x) const;
    /**
     * Calculate the moment of inertia of a shape along rotated axes.
     *
     * \param theta The angle of rotation to the new axes from the old ones,
     *   where positive is counterclockwise from the axes.
     * \return the area moment of inertia of a shape about axes rotated by theta
     */
    SecondMomentOfArea Iyy(const Angle& theta) const;

    /** Return the product of inertia of a shape about its own centroid.
    */
    SecondMomentOfArea Ixy() const;
    /**
     * Calculate the product of inertia of a shape using a Parallel Axis shift.
     *
     * \param x The x location of the point about which to calculate the 
     *   product of inertia
     * \param y The y location of the point about which to calculate the 
     *   product of inertia
     * \return the product of inertia of this Geometry
     */
    SecondMomentOfArea Ixy(const Length& x, const Length& y) const;
    /**
     * Calculate the moment of inertia of a shape along rotated axes.
     *
     * \param theta The angle of rotation to the new axes from the old ones,
     *   where positive is counterclockwise from the axes.
     * \return the product of inertia of a shape about axes rotated by theta
     */
    SecondMomentOfArea Ixy(const Angle& theta) const;

  private:
    LengthVec centroid_;        /**< The centroid of this Geometry in space */
    Area area_;                 /**< The area of this Geometry */
    /* Area moments of inertia for a 2D area about various axes */
    struct AreaMomentofInertia {
      SecondMomentOfArea Ixx;
      SecondMomentOfArea Iyy;
      SecondMomentOfArea Ixy;

      AreaMomentofInertia(const SecondMomentOfArea& xx = 0_m4,
                          const SecondMomentOfArea& yy = 0_m4,
                          const SecondMomentOfArea& xy = 0_m4);
    } MOI_;   /**< The moment of inertia of this
                                     Geometry about the X and Y axes and 
                                     the XY product of inertia */
  };

  /* Calculate Radius of Gyration of a Moment of Inertia and an Area */
  
  Length radius_of_gyration(const SecondMomentOfArea& I,
                            const typename Area& a);

};  // namespace eng
