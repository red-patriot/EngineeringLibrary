#ifndef Stress_h_INCLUDED
#define Stress_h_INCLUDED

#include "EngineeringExport.h"
#include "Material.h"

#include "PhysicsLibrary/PhysicsMath.h"
#include "PhysicsLibrary/Pressure.h"
#include "PhysicsLibrary/Area.h"
#include "PhysicsLibrary/Length.h"
#include "PhysicsLibrary/Angle.h"

namespace eng {

  /* The stress of one 2 Dimensional stress element in a member */
  struct ENGINEERINGLIBRARY_API StressElement2 {
    Stress sigma_x;
    Stress sigma_y;

    Stress tau_xy;

    StressElement2(const Stress& xx = 0_Pa, const Stress& yy = 0_Pa, const Stress& xxyy = 0_Pa);
  };

  /* The stress of a 3 Dimensional stress element in a member*/
  struct ENGINEERINGLIBRARY_API StressElement3 {
    Stress sigma_x;
    Stress sigma_y;
    Stress sigma_z;

    Stress tau_xy;
    Stress tau_xz;
    Stress tau_yz;

    StressElement3(const Stress& xx = 0_Pa, const Stress& yy = 0_Pa, const Stress& zz = 0_Pa,
      const Stress& xxyy = 0_Pa, const Stress& xxzz = 0_Pa, const Stress& yyzz = 0_Pa);
  };

  /* The Principal stresses of a 2D stress element*/
  struct ENGINEERINGLIBRARY_API PrincipalStress2 {
    Stress sigma_1;
    Stress sigma_2;

    PrincipalStress2(const Stress& s1 = 0_Pa, const Stress& s2 = 0_Pa);
  };

  /* The Principal stresses of a 3D stress element*/
  struct ENGINEERINGLIBRARY_API PrincipalStress3 {
    Stress sigma_1;
    Stress sigma_2;
    Stress sigma_3;

    PrincipalStress3(const Stress& s1 = 0_Pa, const Stress& s2 = 0_Pa, const Stress& s3 = 0_Pa);
  };


  /* Calculate ths principal stresses of a planar stress state */
  PrincipalStress2 ENGINEERINGLIBRARY_API principal_stress(const StressElement2& s);
  // TODO(unimplemented): 3D Stress analysis
  //! This probably requires the implmentation of Stress Tensors and it might be difficult to implement.
  //! Look into this
  // TODO: PrincipalStress3 ENGINEERINGLIBRARY_API principal_stress(const StressElement3& s);
  /* Calculate the principal stresses in a Cylindrical pressure vessel. */
  PrincipalStress3 ENGINEERINGLIBRARY_API principal_stress(const physics::Length& a, const physics::Length& b,
    const physics::Length& r, const physics::Force& F, const physics::Pressure& Pi,
    const physics::Pressure& Po = 0_kPa);

  /* Calculate the maximum shear stress and the corresponding normal stresses of a planar stress state*/
  StressElement2 ENGINEERINGLIBRARY_API maximum_shear(const StressElement2& s);

  /* Calculate the interference of two press-fit cylinders. */
  physics::Length ENGINEERINGLIBRARY_API press_fit_interference(const physics::Length& ri,
    const physics::Length& R, const physics::Length& ro, const physics::Pressure& p,
    const MaterialBase& out_material, const MaterialBase& in_material);



}; // namespace eng


#endif
