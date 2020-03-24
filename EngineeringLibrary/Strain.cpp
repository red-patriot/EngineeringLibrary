#include "pch.h"

#include "Strain.h"

namespace eng {

  NormalStrain::NormalStrain(const double& xx, const double& yy, const double& zz) :
    epsilon_x(xx),
    epsilon_y(yy),
    epsilon_z(zz) { }

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

};  // namespace eng
