#ifndef Material_h_INCLUDED
#define Material_h_INCLUDED

/* Material.h
 * A model of different materials with different properties.
 */

#include <unordered_map>

#include "EngineeringExport.h"
#include "Units/Pressure.h"

namespace eng {

  // Stress and Pressure have the same units, so define them as "equal" here
  using Stress = physics::Pressure;

  class ENGINEERINGLIBRARY_API MaterialBase {
    /* Base material properties which are constant regardless of material processes. */
    friend class Material;
  public:
    MaterialBase(const Stress& _youngs_modulus, const Stress& _rigidity_modulus, const double& _poissons_ratio);
    ~MaterialBase() = default;

    Stress modulus_elasticity() const { return youngs_modulus; }
    Stress modulus_rigidity() const { return rigidity_modulus; }
    double poissons_ratio() const { return ratio_poisson; }

    Stress E() const { return youngs_modulus; }
    Stress G() const { return rigidity_modulus; }
    double nu() const { return ratio_poisson; }

  private:
    Stress youngs_modulus;
    Stress rigidity_modulus;
    double ratio_poisson;
  };

  class ENGINEERINGLIBRARY_API Material : public MaterialBase {
    /* A representation of certain processed materials. */
  public:
    Material(const Stress& _yield_strength, const Stress& _tensile_strength, 
      const Stress& _youngs_modulus, const Stress& _rigidity_modulus, double _poissons_ratio);
    Material(const Stress& _yield_strength, const Stress& _tensile_strength, const MaterialBase& base_material);
    Material(const Material& material) = default;
    ~Material() = default;

    Stress yield_strength() const { return yield_str; }
    Stress tensile_strength() const { return tensile_str; }

    Stress Sy() const { return yield_str; }
    Stress St() const { return tensile_str; }

  private:
    Stress yield_str;
    Stress tensile_str;
  };

}; // namespace eng

namespace basic_materials {

  // Some basic materials for use
  const static eng::MaterialBase aluminum{ 71.7_GPa,  26.9_GPa, 0.333 };
  const static eng::MaterialBase brass{ 106.0_GPa, 40.1_GPa, 0.324 };
  const static eng::MaterialBase steel{ 207.0_GPa, 79.3_GPa, 0.292 };
  const static eng::MaterialBase cast_iron{ 100.0_GPa, 41.4_GPa, 0.211 };
  const static eng::MaterialBase copper{ 119.0_GPa, 44.7_GPa, 0.326 };
  const static eng::MaterialBase lead{ 36.5_GPa,  13.1_GPa, 0.425 };
  const static eng::MaterialBase magnesium{ 44.8_GPa,  16.5_GPa, 0.350 };
  const static eng::MaterialBase stainless_steel{ 190.0_GPa, 73.1_GPa, 0.305 };
  const static eng::MaterialBase titanium{ 114.0_GPa, 42.4_GPa, 0.340 };

  // Map of processed steels and their properties, specifies with AISI numbers
  const static std::unordered_map<const char*, eng::Material> steels({
    {"1006 HR", eng::Material{170_MPa, 300_MPa, steel}},
    {"1006 CD", eng::Material{280_MPa, 330_MPa, steel}},
    {"1010 HR", eng::Material{180_MPa, 320_MPa, steel}},
    {"1010 CD", eng::Material{200_MPa, 370_MPa, steel}},
    {"1015 HR", eng::Material{190_MPa, 340_MPa, steel}},
    {"1015 CD", eng::Material{320_MPa, 390_MPa, steel}},
    {"1018 HR", eng::Material{220_MPa, 400_MPa, steel}},
    {"1018 CD", eng::Material{370_MPa, 440_MPa, steel}},
    {"1020 HR", eng::Material{210_MPa, 380_MPa, steel}},
    {"1020 CD", eng::Material{390_MPa, 470_MPa, steel}},
    {"1030 HR", eng::Material{260_MPa, 470_MPa, steel}},
    {"1030 CD", eng::Material{440_MPa, 520_MPa, steel}},
    {"1035 HR", eng::Material{270_MPa, 500_MPa, steel}},
    {"1035 CD", eng::Material{460_MPa, 550_MPa, steel}},
    {"1040 HR", eng::Material{290_MPa, 520_MPa, steel}},
    {"1040 CD", eng::Material{490_MPa, 590_MPa, steel}},
    {"1045 HR", eng::Material{310_MPa, 570_MPa, steel}},
    {"1045 CD", eng::Material{530_MPa, 630_MPa, steel}},
    {"1050 HR", eng::Material{340_MPa, 620_MPa, steel}},
    {"1050 CD", eng::Material{580_MPa, 690_MPa, steel}},
    {"1060 HR", eng::Material{370_MPa, 680_MPa, steel}},
    {"1080 HR", eng::Material{420_MPa, 770_MPa, steel}},
    {"1095 HR", eng::Material{460_MPa, 830_MPa, steel}}
    });

}; // namespace basic_materials

#endif
