#include "pch.h"
#include "MaterialStress.h"
#include "Material.h"

#include "PhysicsLibrary\PhysicsMath.h"
#include "PhysicsLibrary\Force.h"
#include "PhysicsLibrary\Pressure.h"
#include "PhysicsLibrary\Area.h"
#include "PhysicsLibrary\Length.h"

/* MaterialsStress.h
 * Functions to calculate the stresses in materials under different loading conditions
 */

namespace stress {

  namespace cylindrical {

    StressState::StressState(const eng::Stress& tt, const eng::Stress& rr, const eng::Stress& zz) :
      s_t(tt),
      s_r(rr),
      s_z(zz) {
    }


    StressState  principal_stress(const physics::Length& a, const physics::Length& b, const physics::Length& r,
      const physics::Force& F, const physics::Pressure& Pi, const physics::Pressure& Po) {
      StressState ret;
      ret.s_t = (Pi*(a*a) - Po*(b*b))/(b*b - a*a)
        - ((a*a)/(r*r)) * ((b*b)/(b*b - a*a))*(Po - Pi);

      ret.s_r = (Pi*(a*a) - Po*(b*b))/(b*b - a*a)
        + ((a*a)/(r*r)) * ((b*b)/(b*b - a*a))*(Po - Pi);


      ret.s_z = (Pi*(a*a) - Po*(b*b))/(b*b - a*a) + F/(pi *(b*b - a*a));

      return ret;
    }

    physics::Length  press_fit_interference(const physics::Length& ri,
      const physics::Length& R, const physics::Length& ro, const physics::Pressure& p,
      const eng::MaterialBase& out_material, const eng::MaterialBase& in_material) {  
      return (p/out_material.E())*R*((ro*ro + R*R)/(ro*ro - R*R) + out_material.nu())
        + (p/in_material.E())*R*((ri*ri + R*R)/(R*R - ri*ri) - in_material.nu());
    }

  };  // namespace cylindrical

}; // namespace stress
