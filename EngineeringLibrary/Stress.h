#ifndef Stress_h_INCLUDED
#define Stress_h_INCLUDED

/*****************************************************************//**
 * \file  Stress.h
 * \brief Functionality to analyse Stresses in materials
 *
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include <eigen3/Eigen/Dense>

#include "Material.h"

#include "Units/Pressure.h"
#include "Units/Area.h"
#include "Units/Length.h"
#include "Units/Angle.h"

namespace eng {

  // Stress and Pressure have the same units, so define them as "equal" here
  using Stress = Pressure;

  /**
   * \class StressElement2 The stress of one 2D stress element
   */
  struct StressElement2 {
    Stress sigma_x;
    Stress sigma_y;

    Stress tau_xy;

    /**
     * \brief StressElement2 constructor
     * 
     * \param xx The normal stress in the X direction
     * \param yy The normal stress in the Y direction
     * \param xxyy The shear stress on the X face in the Y direction
     */
    StressElement2(const Stress& xx = 0_Pa, const Stress& yy = 0_Pa, const Stress& xxyy = 0_Pa);
  };

  /**
   * \class StressElement2 The stress of a 3D stress element
   */
  struct StressElement3 {
    Stress sigma_x;
    Stress sigma_y;
    Stress sigma_z;

    Stress tau_xy;
    Stress tau_xz;
    Stress tau_yz;

    /**
     * \brief StressElement3 constructor
     * 
     * \param xx The normal stress in the X direction
     * \param yy The normal stress in the Y direction
     * \param zz The normal stress in the Z direction
     * \param xxyy The shear stress on the X face in the Y direction
     * \param xxzz The shear stress on the X face in the Z direction
     * \param yyzz The shear stress on the Y face in the Z direction
     */
    StressElement3(const Stress& xx = 0_Pa, const Stress& yy = 0_Pa, const Stress& zz = 0_Pa,
                   const Stress& xxyy = 0_Pa, const Stress& xxzz = 0_Pa, const Stress& yyzz = 0_Pa);
  };

  using StressTensor = Eigen::Matrix<Pressure, 3, 3>;

  /**  
   * \class PrincipalStress2 The Principal stresses of a 2D stress element
   */
  struct PrincipalStress2 {
    Stress sigma_1;
    Stress sigma_2;

    /**
     * \brief PrincipalStress2 constructor
     * 
     * \param s1 Sugma 1, the maximum normal stress value
     * \param s2 Sigma 2. the minimum normal stress value
     */
    PrincipalStress2(const Stress& s1 = 0_Pa, const Stress& s2 = 0_Pa);
  };

  /**
   * \brief The Principal stresses of a 3D stress element
   */
  struct PrincipalStress3 {
    Stress sigma_1;
    Stress sigma_2;
    Stress sigma_3;

    /**
     * \brief PrincipalStress3 constructor
     * 
     * \param s1 Sigma 1, the maximum normal stress value
     * \param s2 Sigma 2, the medium normal stress value
     * \param s3 Sigma 3, the minimum normal stress value
     */
    PrincipalStress3(const Stress& s1 = 0_Pa, const Stress& s2 = 0_Pa, const Stress& s3 = 0_Pa);
  };


  /* Calculate ths principal stresses of a planar stress state */
  PrincipalStress2 principal_stress(const StressElement2& s);
  /* Calculate the principal stresses of a general 3D stress state */
  PrincipalStress3 principal_stress(const StressElement3& s);
  /* Calculate the principal stresses in a Cylindrical pressure vessel. */
  PrincipalStress3 principal_stress(const Length& a, const Length& b,
                                    const Length& r, const Force& F, const Pressure& Pi,
                                    const Pressure& Po = 0_kPa);

  /* Calculate the maximum shear stress and the corresponding normal 
   * stresses of a planar stress state */
  StressElement2  maximum_shear(const StressElement2& s);

  /* Calculate the interference of two press-fit cylinders. */
  Length  press_fit_interference(const Length& ri, const Length& R, const Length& ro, 
                                 const Pressure& p, const MaterialBase& out_material, 
                                 const MaterialBase& in_material);

}; // namespace eng


#endif
