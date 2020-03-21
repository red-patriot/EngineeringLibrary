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

namespace eng {

  StressPlanar::StressPlanar(const Stress& xx, const Stress& yy, const Stress& xxyy, 
    const physics::Angle& tt) :
    sigma_x(xx),
    sigma_y(yy),
    tau_xy(xxyy),
    theta(tt) { }

  StressCylindrical::StressCylindrical(const Stress& tt, const Stress& rr, const Stress& zz) :
    sigma_t(tt),
    sigma_r(rr),
    sigma_z(zz) { }


  StressPlanar principal_stress(const StressPlanar& s) {
    // TODO: Update PhysicsLibrary with Pressure^2 object for this function to work
    StressPlanar princ;
    
  }

  StressPlanar maximum_shear(const StressPlanar& s) {
    return StressPlanar();
  }

  StressCylindrical  principal_stress(const physics::Length& a, const physics::Length& b, const physics::Length& r,
    const physics::Force& F, const physics::Pressure& Pi, const physics::Pressure& Po) {
    StressCylindrical ret;
    ret.sigma_t = (Pi*(a*a) - Po*(b*b))/(b*b - a*a)
      - ((a*a)/(r*r)) * ((b*b)/(b*b - a*a))*(Po - Pi);

    ret.sigma_r = (Pi*(a*a) - Po*(b*b))/(b*b - a*a)
      + ((a*a)/(r*r)) * ((b*b)/(b*b - a*a))*(Po - Pi);

    ret.sigma_z = (Pi*(a*a) - Po*(b*b))/(b*b - a*a) + F/(pi *(b*b - a*a));

    return ret;
  }

  physics::Length  press_fit_interference(const physics::Length& ri,
    const physics::Length& R, const physics::Length& ro, const physics::Pressure& p,
    const MaterialBase& out_material, const MaterialBase& in_material) {  
    return (p/out_material.E())*R*((ro*ro + R*R)/(ro*ro - R*R) + out_material.nu())
      + (p/in_material.E())*R*((ri*ri + R*R)/(R*R - ri*ri) - in_material.nu());
  }

}; // namespace eng
