#include "pch.h"

#include "Strain.h"

namespace eng {

  NormalStrain::NormalStrain(const double& xx, const double& yy, const double& zz) :
    epsilon_x(xx),
    epsilon_y(yy),
    epsilon_z(zz) { }

  ShearStrain::ShearStrain(const Angle& xy, const Angle& xz, const Angle& yz) :
    gamma_xy(xy),
    gamma_xz(xz),
    gamma_yz(yz) { }

  double hookes_law(const Material& material, const Stress& stress) {
    return stress / material.E();
  }

  NormalStrain hookes_law(const Material& material, const StressElement2& stress) {
    return hookes_law(material, StressElement3(stress.sigma_x, stress.sigma_y));
  }

  NormalStrain hookes_law(const Material& material, const StressElement3& stress) {
    NormalStrain ret;
    ret.epsilon_x = (stress.sigma_x - material.nu()*(stress.sigma_y + stress.sigma_z))/material.E();
    ret.epsilon_y = (stress.sigma_y - material.nu()*(stress.sigma_x + stress.sigma_z))/material.E();
    ret.epsilon_z = (stress.sigma_z - material.nu()*(stress.sigma_x + stress.sigma_y))/material.E();

    return ret;
  }

  ShearStrain hookes_law_shear(const Material& material, const StressElement2& stress) {
    return hookes_law_shear(material, StressElement3(stress.sigma_x, stress.sigma_y, 0_Pa,
      stress.tau_xy, 0_Pa, 0_Pa));
  }

  ShearStrain hookes_law_shear(const Material& material, const StressElement3& stress) {
    ShearStrain ret;
    ret.gamma_xy = Angle(stress.tau_xy / material.G());
    ret.gamma_xz = Angle(stress.tau_xz / material.G());
    ret.gamma_yz = Angle(stress.tau_yz / material.G());
    return ret;
  }

};  // namespace eng
