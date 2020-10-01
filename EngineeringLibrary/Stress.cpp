#include "pch.h"

#include <algorithm>
#include <eigen3/Eigen/Dense>

#include "Stress.h"
#include "Material.h"

#include "Units/PhysicsMath.h"
#include "Units/Force.h"
#include "Units/Pressure.h"
#include "Units/Area.h"
#include "Units/Length.h"

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
      + sqrt(((s.sigma_x - s.sigma_y)*(s.sigma_x - s.sigma_y))/4 + (s.tau_xy * s.tau_xy));
    ret.sigma_2 = (s.sigma_x + s.sigma_y)/2
      - sqrt(((s.sigma_x - s.sigma_y)*(s.sigma_x - s.sigma_y))/4 + (s.tau_xy * s.tau_xy));

    return ret;
  }

  PrincipalStress3 principal_stress(const StressElement3& s) {
    // create a stress tensor with the stress element
    Eigen::Matrix3d tensor;
    tensor << s.sigma_x.Pa(), s.tau_xy.Pa(), s.tau_xz.Pa(),
              s.tau_xy.Pa(), s.sigma_y.Pa(), s.tau_yz.Pa(),
              s.tau_xz.Pa(), s.tau_yz.Pa(), s.sigma_z.Pa();

    // calculate the eigenvalues of the stress tensor
    auto eig = tensor.eigenvalues();
    Pressure s_a = Stress(eig(0).real());
    Pressure s_b = Stress(eig(1).real());
    Pressure s_c = Stress(eig(2).real());

    // Sort the principal stresses by size
    PrincipalStress3 ret;
    ret.sigma_1 = s_a > s_b ? (s_a > s_c ? s_a : s_c) : (s_b > s_c ? s_b : s_c);
    ret.sigma_2 = s_a > s_b ? (s_c > s_a ? s_a : (s_b > s_c ? s_b : s_c)) : 
      (s_c > s_b ? s_b : (s_a > s_c ? s_a : s_c));
    ret.sigma_3 = s_a > s_b ? (s_b > s_c ? s_c : s_b) : (s_a > s_c ? s_c : s_a);
    
    return ret;
  }

  PrincipalStress3  principal_stress(const Length& a, const Length& b, const Length& r,
    const Force& F, const Pressure& Pi, const Pressure& Po) {
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
    ret.tau_xy = sqrt(((s.sigma_x - s.sigma_y)*(s.sigma_x - s.sigma_y))/4
      + s.tau_xy*s.tau_xy);
    ret.sigma_x = ret.sigma_y = (principal.sigma_1 + principal.sigma_2) / 2;

    return ret;
  }

  Length  press_fit_interference(const Length& ri,
    const Length& R, const Length& ro, const Pressure& p,
    const MaterialBase& out_material, const MaterialBase& in_material) {  
    return (p/out_material.E())*R*((ro*ro + R*R)/(ro*ro - R*R) + out_material.nu())
      + (p/in_material.E())*R*((ri*ri + R*R)/(R*R - ri*ri) - in_material.nu());
  }

}; // namespace eng
