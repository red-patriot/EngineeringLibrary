#include "pch.h"

#include "Stress.h"
#include "Material.h"

#include "PhysicsLibrary\PhysicsMath.h"
#include "PhysicsLibrary\Force.h"
#include "PhysicsLibrary\Pressure.h"
#include "PhysicsLibrary\Area.h"
#include "PhysicsLibrary\Length.h"

namespace eng {

  StressElement2::StressElement2(const Stress& xx, const Stress& yy, const Stress& xxyy) :
    sigma_x(xx),
    sigma_y(yy),
    tau_xy(xxyy) { }

  StressElement3::StressElement3(const Stress& xx, const Stress& yy, const Stress& zz,
    const Stress& xxyy, const Stress& xxzz, const Stress& yyzz) :
    sigma_x(xx),
    sigma_y(yy),
    sigma_z(zz),
    tau_xy(xxyy),
    tau_xz(xxzz),
    tau_yz(yyzz) { }

  PrincipalStress2::PrincipalStress2(const Stress& s1, const Stress& s2) :
    sigma_1(s1),
    sigma_2(s2) { }

  PrincipalStress3::PrincipalStress3(const Stress& s1, const Stress& s2, const Stress& s3) :
    sigma_1(s1),
    sigma_2(s2),
    sigma_3(s3) { }

  PrincipalStress2 principal_stress(const StressElement2& s) {
    PrincipalStress2 ret;
    ret.sigma_1 = (s.sigma_x + s.sigma_y)/2 
      + physics::sqrt(((s.sigma_x - s.sigma_y)*(s.sigma_x - s.sigma_y))/4 + (s.tau_xy * s.tau_xy));
    ret.sigma_2 = (s.sigma_x + s.sigma_y)/2
      - physics::sqrt(((s.sigma_x - s.sigma_y)*(s.sigma_x - s.sigma_y))/4 + (s.tau_xy * s.tau_xy));

    return ret;
  }

  PrincipalStress3  principal_stress(const physics::Length& a, const physics::Length& b, const physics::Length& r,
    const physics::Force& F, const physics::Pressure& Pi, const physics::Pressure& Po) {
    Stress transverse = (Pi*(a*a) - Po*(b*b))/(b*b - a*a)
      - ((a*a)/(r*r)) * ((b*b)/(b*b - a*a))*(Po - Pi);
    Stress radial = (Pi*(a*a) - Po*(b*b))/(b*b - a*a)
      + ((a*a)/(r*r)) * ((b*b)/(b*b - a*a))*(Po - Pi);
    Stress longitudinal = (Pi*(a*a) - Po*(b*b))/(b*b - a*a) + F/(pi *(b*b - a*a));

    if (transverse < longitudinal) {
      return PrincipalStress3(longitudinal, transverse, radial);
    } else if (radial < longitudinal) {
      return PrincipalStress3(transverse, longitudinal, radial);
    } else {
      return PrincipalStress3(transverse, radial, longitudinal);
    }
  }

  StressElement2 maximum_shear(const StressElement2& s) {
    StressElement2 ret;
    PrincipalStress2 principal = principal_stress(s);
    ret.tau_xy = physics::sqrt(((s.sigma_x - s.sigma_y)*(s.sigma_x - s.sigma_y))/4
      + s.tau_xy*s.tau_xy);
    ret.sigma_x = ret.sigma_y = (principal.sigma_1 + principal.sigma_2) / 2;

    return ret;
  }

  physics::Length  press_fit_interference(const physics::Length& ri,
    const physics::Length& R, const physics::Length& ro, const physics::Pressure& p,
    const MaterialBase& out_material, const MaterialBase& in_material) {  
    return (p/out_material.E())*R*((ro*ro + R*R)/(ro*ro - R*R) + out_material.nu())
      + (p/in_material.E())*R*((ri*ri + R*R)/(R*R - ri*ri) - in_material.nu());
  }

}; // namespace eng
