#include "pch.h"

#include "Strain.h"

namespace eng {

  Strain::Strain(const double& xx, const double& yy, const double& zz) :
    epsilon_x(xx),
    epsilon_y(yy),
    epsilon_z(zz) { }

  double hookes_law(const Material& material, const Stress& stress) {
    return stress / material.E();
  }

  Strain hookes_law(const Material& material, const StressElement2& stress) {
    Strain ret;
    ret.epsilon_x = (stress.sigma_x - material.nu()*stress.sigma_y)/material.E();
    ret.epsilon_y = (stress.sigma_y - material.nu()*stress.sigma_x)/material.E();
    ret.epsilon_z = material.nu()*(stress.sigma_x + stress.sigma_y)/material.E();

    return ret;
  }

  Strain hookes_law(const Material& material, const StressCylindrical& stress) {
    Strain ret;
    ret.epsilon_x = (stress.sigma_

    return ret;
  }

};  // namespace eng
