#ifndef Materials_Stress_h_INCLUDED
#define Materials_Stress_h_INCLUDED

#include "EngineeringExport.h"
#include "Material.h"

#include "PhysicsLibrary\PhysicsMath.h"
#include "PhysicsLibrary\Pressure.h"
#include "PhysicsLibrary\Area.h"
#include "PhysicsLibrary\Length.h"
#include "PhysicsLibrary/Angle.h"

/* MaterialsStress.h
 * Functions to calculate the stresses in materials under different loading conditions
 */

namespace eng {

  /* ***********************************************************************************************
   * 2D (Planar) Stress analysis
   */

  /* The stress of one 2 Dimensional stress element in a member */
  struct StressPlanar {
    Stress sigma_x;
    Stress sigma_y;
    Stress tau_xy;
    physics::Angle theta;

    StressPlanar(const Stress& xx = 0_Pa, const Stress& yy = 0_Pa, const Stress& xxyy = 0_Pa, 
      const physics::Angle& tt = 0_rad);
  };

  /* Calculate ths principal stress of a planar stress state */
  StressPlanar principal_stress(const StressPlanar& s);
  StressPlanar maximum_shear(const StressPlanar& s);

  /* ***********************************************************************************************
   * Cylindrical Pressure Vessel Stress analysis
   */

  /* The stresses at one stress element in a cylindrical pressure vessel */
  struct ENGINEERINGLIBRARY_API StressCylindrical {
    Stress sigma_t;
    Stress sigma_r;
    Stress sigma_z;

    StressCylindrical(const Stress& tt = 0_Pa, const Stress& rr = 0_Pa, const Stress& zz = 0_Pa);
  };

  /* Calculate the stress in a Cylindrical pressure vessel. */
  StressCylindrical ENGINEERINGLIBRARY_API principal_stress(const physics::Length& a, const physics::Length& b, 
    const physics::Length& r, const physics::Force& F, const physics::Pressure& Pi, 
    const physics::Pressure& Po = 0_kPa);

  /* Calculate the interference of two press-fit cylinders. */
  physics::Length ENGINEERINGLIBRARY_API press_fit_interference(const physics::Length& ri,
    const physics::Length& R, const physics::Length& ro, const physics::Pressure& p,
    const MaterialBase& out_material, const MaterialBase& in_material);

}; // namespace eng


#endif
