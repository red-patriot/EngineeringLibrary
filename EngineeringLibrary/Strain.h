#ifndef Strain_h_INCLUDED
#define Strain_h_INCLUDED

#include "EngineeringExport.h"
#include "Material.h"

#include "Stress.h"

namespace eng {

  /* ***********************************************************************************************
   * Strain analysis
   */

  struct ENGINEERINGLIBRARY_API Strain {
    double epsilon_x;
    double epsilon_y;
    double epsilon_z;

    Strain(const double& xx = 0, const double& yy = 0, const double& zz = 0);
  };

  struct StrainShear {
    //? Maybe unused?
  };

  /* Hooke's Law to determine strain from stress for a material alone a single axis */
  double ENGINEERINGLIBRARY_API hookes_law(const Material& material, const Stress& stress);
  /* Hooke's Law to determine strain from stress for a material loaded in planar stress */
  Strain ENGINEERINGLIBRARY_API hookes_law(const Material& material, const StressElement2& stress);
  // TODO: Hooke's Law for material loaded in general 3D stress
  /* Hooke's Law to determine strain from stress for a material loaded in Cylindrical stress */
  Strain ENGINEERINGLIBRARY_API hookes_law(const Material& material, const StressCylindrical& stress);

  // TODO: Hooke's Law in shear

};  // namespace eng

#endif

