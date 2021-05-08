#pragma once

/*****************************************************************//**
 * \file  Buckling.h
 * \brief Contains functionality to perform buckling analysis for a column. 
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "Material.h"
#include "Geometric.h"

#include "Units/Area.h"
#include "Units/Length.h"

// These defined constants will determine which value of the end condition 
//    constant wil be used.
//TODO: Maybe change these to an enum?
#define COL_THEORETICAL_VALUE 0   /* Use the theoretical value of C. */
#define COL_CONSERVATIVE_VALUE 1  /* Use the conservative value of C. */
#define COL_RECOMMENDED_VALUE 2   /* Use the recommended value of C. Use only with liberal factors of safety and when column load is known accurately. */

namespace eng {

  /**
   * \brief The support conditions for a column in buckling
   */
  enum class EndConditions { 
    FIXED_FREE,
    PIN_PIN,
    FIXED_PIN, 
    FIXED_FIXED
  };

  /**
   * \class Column A Column or other member of constant cross section
   *    being analysed in buckling.
   */
  class  Column {
  public:
    /**
     * \brief Column constructor
     * 
     * \param material The column material
     * \param geometry The cross-sectional geometry of the column
     * \param length The length of the column
     * \param supports the support conditions for the column
     */
    Column(const Material& material, const Geometry& geometry, const Length& length, 
      const EndConditions& supports);

    Material material() const { return _material; }
    Geometry::AreaMomentofInertia moment_of_inertia() const { return _geometry.moment_of_inertia(); }
    Area area() const { return _geometry.area(); }
    Length length() const { return _length; }
    EndConditions supports() const { return _supports; }

  private:
    Material _material;
    Geometry _geometry;
    Length _length;
    EndConditions _supports;
  };

  /* 
   * Buckling analysis functions.
   */

  /* Calculate the critical load to cause buckling of a column where it is unknown whether the
     column will fail in Euler or Johnson buckling. */
  Stress critical_load(const Column& _column);
  /* Calculate the ciritcal load to cause buckling of a column that will fail in Euler buckling. */
  Stress critical_load_euler(const Column& _column);
  /* Calculate the ciritcal load to cause buckling of a column that will fail in Johnson buckling. */
  Stress critical_load_johnson(const Column& _column);

  /* Calculate (l/k)_1, the critical point between Euler and Johnson buckling. */
  double l_k_1(const Column& _column);
  
  /* Determine the end condition constant to be used for a buckling problem. */
  double end_condition_constant(const EndConditions& _supports, const int& v=COL_THEORETICAL_VALUE);

};  // namespace eng

