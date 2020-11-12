#ifndef Strain_h_INCLUDED
#define Strain_h_INCLUDED

/*****************************************************************//**
 * \file  Strain.h
 * \brief Functionality to perform strain analysis on elements. 
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "Material.h"
#include "Stress.h"

#include "Units/Angle.h"

namespace eng {

  /**
   * \class NormalStrain Store 3D strain for a member
   */
  struct  NormalStrain {
    double epsilon_x;
    double epsilon_y;
    double epsilon_z;

    /**
     * \brief NormalStrain constructor
     * 
     * \param xx The strain in the X direction
     * \param yy The strain in the Y direction
     * \param zz The strain in the Z direction
     */
    NormalStrain(const double& xx = 0, const double& yy = 0, const double& zz = 0);
  };
  /**
   * \class ShearStrain Store 3D shear strain for a member
   */
  struct ShearStrain{
    Angle gamma_xy;
    Angle gamma_xz;
    Angle gamma_yz;

    /**
     * \brief ShearStrain constructor
     * 
     * \param xy The strain on the X face in the Y direction
     * \param xz The strain on the X face in the Z direction
     * \param yz The strain on the Y face in the Z direction
     */
    ShearStrain(const Angle& xy = 0_rad, const Angle& xz = 0_rad, const Angle& yz = 0_rad);
  };

  /* Hooke's Law to determine strain from stress for a material alone a single axis */
  double hookes_law(const Material& material, const Stress& stress);
  /* Hooke's Law to determine strain from stress for a material loaded in planar stress */
  NormalStrain hookes_law(const Material& material, 
                                                 const StressElement2& stress);
  // TODO: Hooke's Law for material loaded in general 3D stress
  /* Hooke's Law to determine strain from stress for a material loaded in Cylindrical stress */
  NormalStrain hookes_law(const Material& material, 
                                                 const StressElement3& stress);

  // TODO: Hooke's Law in shear
  ShearStrain hookes_law_shear(const Material& material, const StressElement2& stress);
  ShearStrain hookes_law_shear(const Material& material, const StressElement3& stress);


};  // namespace eng

#endif

