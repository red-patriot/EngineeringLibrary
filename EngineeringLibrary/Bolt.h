#ifndef Bolt_h_INCLUDED
#define Bolt_h_INCLUDED

#include <vector>
#include <utility>

#include "EngineeringExport.h"
#include "Material.h"

#include "PhysicsLibrary/Length.h"
#include "PhysicsLibrary/Area.h"
#include "PhysicsLibrary/Force.h"

namespace eng {

  struct joint_member {
    Material material;
    physics::Length thickness;

    joint_member(const Material& mat, const physics::Length& thi);
  };

  /* Calculate the stiffness of a bolt */
  physics::Stiffness ENGINEERINGLIBRARY_API bolt_stiffness(const physics::Area& Ad, const physics::Area& At,
                                                           const Stress& E, const physics::Length& lt, 
                                                           const physics::Length& ld);
  /* Calculate the stiffess of members bolted by a bolt */
  physics::Stiffness ENGINEERINGLIBRARY_API members_stiffness(const std::vector<joint_member>& members,
                                                              const physics::Length& d, const physics::Length& t);
  /* Calculate the thickness of a bolted joint. */
  physics::Length joint_thickness(const std::vector<joint_member> members);
  /* Split the joint members into the top and bottom half 
     Both vectors will have their first elements on the outside of the joint and continue inwards. */
  void split_members (const std::vector<joint_member>& members, std::vector<joint_member>& top, 
                      std::vector<joint_member>& bottom, const physics::Length& thickness);

  /* Calculate the factor of safety against yielding of a bolted joint */
  double ENGINEERINGLIBRARY_API factor_of_safety_yield(const Stress& Sp, const physics::Area& At,
    const double& C, const physics::Force& P, const physics::Force& Fi);
  /* Calculate the load factor of a bolted joint */
  double ENGINEERINGLIBRARY_API factor_of_safety_load(const Stress& Sp, const physics::Area& At,
                                                      const double& C, const physics::Force& P, 
                                                      const physics::Force& Fi);
  /* Calculate the factor of safety against joint separation of a bolted joint */
  double ENGINEERINGLIBRARY_API factor_of_safety_separation(const physics::Force& Fi, const physics::Force& P, 
                                                            const double& C);

};  // namespace eng

#endif
