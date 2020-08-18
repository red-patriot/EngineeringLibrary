#ifndef Bolt_h_INCLUDED
#define Bolt_h_INCLUDED

/*****************************************************************//**
 * \file  Bolt.h
 * \brief Contains functionality to perform stress analysis on bots and 
 *          bolted members
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

// TODO: MAKE SURE THIS IS ALL CORRECT (THESE EUQATIONS ARE VERY LONG)

#include <vector>
#include <utility>

#include "EngineeringExport.h"
#include "Material.h"

#include "Units/Length.h"
#include "Units/Area.h"
#include "Units/Force.h"

namespace eng {

  struct joint_member {
    Material material;
    Length thickness;

    joint_member(const Material& mat, const Length& thi);
  };

  /* Calculate the stiffness of a bolt */
  Stiffness ENGINEERINGLIBRARY_API bolt_stiffness(const Area& Ad, const Area& At,
                                                           const Stress& E, const Length& lt, 
                                                           const Length& ld);
  /* Calculate the stiffess of members bolted by a bolt */
  Stiffness ENGINEERINGLIBRARY_API members_stiffness(const std::vector<joint_member>& members,
                                                              const Length& d, const Length& t);
  /* Calculate the thickness of a bolted joint. */
  Length joint_thickness(const std::vector<joint_member> members);
  /* Split the joint members into the top and bottom half 
       Both vectors will have their first elements 
       on the outside of the joint and continue inwards.*/
  void split_members (const std::vector<joint_member>& members, std::vector<joint_member>& top, 
                      std::vector<joint_member>& bottom, const Length& thickness);

  /* Calculate the factor of safety against yielding of a bolted joint */
  double ENGINEERINGLIBRARY_API factor_of_safety_yield(const Stress& Sp, const Area& At,
    const double& C, const Force& P, const Force& Fi);
  /* Calculate the load factor of safety of a bolted joint */
  double ENGINEERINGLIBRARY_API factor_of_safety_load(const Stress& Sp, const Area& At,
                                                      const double& C, const Force& P, 
                                                      const Force& Fi);
  /* Calculate the factor of safety against joint separation of a bolted joint */
  double ENGINEERINGLIBRARY_API factor_of_safety_separation(const Force& Fi, const Force& P, 
                                                            const double& C);

};  // namespace eng

#endif
