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
   *
   * \note The user may define any children of Geometry not defined here,
   *  but all Geometry children must define calculate_area, which returns the 
   *  area of the geometry, and calculate_moment_of_inertia, which returns 
   *  the moment of inertia of the geometry about its own centroid, to work
   *  properly.
   */
  class Geometry {
  public:
    /* Area moments of inertia for a 2D area about various axes */
    struct AreaMomentofInertia {
      SecondMomentOfArea Ixx;
      SecondMomentOfArea Iyy;
      SecondMomentOfArea Ixy;

      AreaMomentofInertia(const SecondMomentOfArea& xx = 0_m4,
                          const SecondMomentOfArea& yy = 0_m4,
                          const SecondMomentOfArea& xy = 0_m4);
    };

    /**
    * \brief Geometry constructor
    *
    * \param area The area of the geometry
    * \param moi the area moment of inertia of the geometry
    * \param centroid The centroid of the geometry
    */
    Geometry(const Area& area, const AreaMomentofInertia& moi,
             const LengthVec& centroid = LengthVec(0_m, 0_m, 0_m));

    /** Returns the centroid of the Geometry.
     */
    LengthVec centroid() const;

    /** Returns the area of the Geometry.
     */
    Area area() const;

    /** Return the moment of inertia of a shape about its own centroid.
    */
    AreaMomentofInertia moment_of_inertia() const;
    
    /**
     * Calculate the moment of inertia of a shape using a Parallel Axis shift.
     *
     * \param pt The point about which to calculate the mement of inertia
     * \return the area moment of inertia of this Geometry about pt
     */
    AreaMomentofInertia moment_of_inertia(const LengthVec& pt) const;
    
    /**
     * Calculate the moment of inertia of a shape along rotated axes.
     *
     * \param theta The angle of rotation to the new axes from the old ones,
     *   where positive is counterclockwise from the axes.
     * \return the area moment of inertia of a shape about axes rotated by theta
     */
    AreaMomentofInertia moment_of_inertia(const Angle& theta) const;

  protected:
    LengthVec _centroid;        /**<The centroid of this Geometry in space */
    mutable Area _area;                 /**<The area of this Geometry */
    mutable AreaMomentofInertia _MOI;   /**<The moment of inertia of this
                                    Geometry about the X, Y and XY axes */

    mutable bool _area_calculated;
    mutable bool _moi_calculated;
                    
    /** An overrideable function used for calculating the area of a
     *  Geometry using whichever formula is appropriate.
     */
    virtual Area calculate_area() const;

    /** An overrideable function used for calculating the area moment of
     *  inertia of a Geometry using whichever formula is appropriate.
     */
    virtual AreaMomentofInertia calculate_moment_of_inertia() const;

    /**
     * \brief Geometry child constructor
     *
     * This constructor is intended for use only by Geometry children.
     */
    Geometry(const LengthVec& c);
  };

};  // namespace eng
