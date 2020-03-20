#include "pch.h"
#include "Material.h"

namespace eng {
  /* Material Base
   * Basic Material properties which are not changed by processing
   */
  MaterialBase::MaterialBase(const Stress& _youngs_modulus, const Stress& _rigidity_modulus, const double& _poissons_ratio) :
    youngs_modulus(_youngs_modulus),
    rigidity_modulus(_rigidity_modulus),
    ratio_poisson(_poissons_ratio) { }

  /* Material
   * Material Properties whcih can be changed by processing
   */

  Material::Material(const Stress& _yield_strength, const Stress& _tensile_strength, 
    const Stress& _youngs_modulus, const Stress& _rigidity_modulus, double _poissons_ratio) :
    yield_str(_yield_strength),
    tensile_str(_tensile_strength),
    MaterialBase(_youngs_modulus, _rigidity_modulus, _poissons_ratio) { }

  Material::Material(const Stress& _yield_strength, const Stress& _tensile_strength, const MaterialBase& base_material) :
    yield_str(_yield_strength),
    tensile_str(_tensile_strength),
    MaterialBase(base_material) { }

};  // namespace eng
