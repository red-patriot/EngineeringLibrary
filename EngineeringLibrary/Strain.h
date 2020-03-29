#ifndef Strain_h_INCLUDED
#define Strain_h_INCLUDED

#include "EngineeringExport.h"
#include "Material.h"

#include "Stress.h"

#include "PhysicsLibrary/Angle.h"

namespace eng {

  /* ***********************************************************************************************
   * Strain analysis
   */

  struct ENGINEERINGLIBRARY_API NormalStrain {
    double epsilon_x;
    double epsilon_y;
    double epsilon_z;

    NormalStrain(const double& xx = 0, const double& yy = 0, const double& zz = 0);
  };

  struct ShearStrain{
    physics::Angle gamma_xy;
    physics::Angle gamma_xz;
    physics::Angle gamma_yz;

    ShearStrain(const physics::Angle& xy = 0_rad, const physics::Angle& xz = 0_rad, const physics::Angle& yz = 0_rad);
  };

  /* Hooke's Law to determine strain from stress for a material alone a single axis */
  double ENGINEERINGLIBRARY_API hookes_law(const Material& material, const Stress& stress);
  /* Hooke's Law to determine strain from stress for a material loaded in planar stress */
  NormalStrain ENGINEERINGLIBRARY_API hookes_law(const Material& material, const StressElement2& stress);
  // TODO: Hooke's Law for material loaded in general 3D stress
  /* Hooke's Law to determine strain from stress for a material loaded in Cylindrical stress */
  NormalStrain ENGINEERINGLIBRARY_API hookes_law(const Material& material, const StressElement3& stress);

  // TODO: Hooke's Law in shear
  ShearStrain ENGINEERINGLIBRARY_API hookes_law_shear(const Material& material, const StressElement2& stress);
  ShearStrain ENGINEERINGLIBRARY_API hookes_law_shear(const Material& material, const StressElement3& stress);


};  // namespace eng

#endif

