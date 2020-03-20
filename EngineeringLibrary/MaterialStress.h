#ifndef Materials_Stress_h_INCLUDED
#define Materials_Stress_h_INCLUDED

#include "EngineeringExport.h"
#include "Material.h"

#include "PhysicsLibrary\PhysicsMath.h"
#include "PhysicsLibrary\Pressure.h"
#include "PhysicsLibrary\Area.h"
#include "PhysicsLibrary\Length.h"

/* MaterialsStress.h
 * Functions to calculate the stresses in materials under different loading conditions
 */

namespace stress {

  /* Stress in cylindrical pressure vessels */
  namespace cylindrical {
    /* The stresses at one stress element in a member */
    struct ENGINEERINGLIBRARY_API StressState {
      eng::Stress s_t;
      eng::Stress s_r;
      eng::Stress s_z;

      StressState(const eng::Stress& tt = 0_Pa, const eng::Stress& rr = 0_Pa, const eng::Stress& zz = 0_Pa);
    };

    /* Calculate the stress in a Cylindrical pressure vessel. */
    StressState ENGINEERINGLIBRARY_API principal_stress(const physics::Length& a, const physics::Length& b, 
      const physics::Length& r, const physics::Force& F, const physics::Pressure& Pi, 
      const physics::Pressure& Po = 0_kPa);

    /* Calculate the interference of two press-fit cylinders. */
    physics::Length ENGINEERINGLIBRARY_API press_fit_interference(const physics::Length& ri,
      const physics::Length& R, const physics::Length& ro, const physics::Pressure& p,
      const eng::MaterialBase& out_material, const eng::MaterialBase& in_material);

  };  // namespace cylindrical

  // TODO: Write a method for general 2D stress states.

}; // namespace stress


#endif
