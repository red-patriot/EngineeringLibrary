#include "pch.h"
#include "Material.h"

namespace eng {
  /* 
   * MaterialBase
   */

  MaterialBase::MaterialBase(const Stress& youngs_modulus, const Stress& rigidity_modulus, 
                             const double& poissons_ratio) :
    _youngs_modulus(youngs_modulus),
    _rigidity_modulus(rigidity_modulus),
    _poissons_ratio(poissons_ratio) { }

  /* 
   * Material
   */

  Material::Material(const Stress& yield_strength, const Stress& tensile_strength, 
    const Stress& youngs_modulus, const Stress& rigidity_modulus, double poissons_ratio) :
    _yield_str(yield_strength),
    _tensile_str(tensile_strength),
    MaterialBase(youngs_modulus, rigidity_modulus, poissons_ratio) { }

  Material::Material(const Stress& yield_strength, const Stress& tensile_strength, 
                     const MaterialBase& base_material) :
    _yield_str(yield_strength),
    _tensile_str(tensile_strength),
    MaterialBase(base_material) { }

};  // namespace eng
