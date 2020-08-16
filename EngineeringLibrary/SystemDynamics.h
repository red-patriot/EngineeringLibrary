#ifndef System_Dynamics_h_INCLUDED
#define System_Dynamics_h_INCLUDED

#include "EngineeringExport.h"

#include "Units/Mass.h"
#include "Units/Damping.h"
#include "Units/Stiffness.h"
#include "Units/Frequency.h"

namespace eng {

  /* Calulate the natural frequency of the system's frequency response*/
  physics::Frequency ENGINEERINGLIBRARY_API natural_frequency(physics::Mass mass, 
                                                              physics::Damping damping, 
                                                              physics::Stiffness stiffness);
  double ENGINEERINGLIBRARY_API damping_ratio(physics::Mass mass,  
                                              physics::Damping damping,
                                              physics::Stiffness stiffness);
  physics::Frequency ENGINEERINGLIBRARY_API resonant_frequency(physics::Frequency natural_frequency,
                                                               double damping_ratio);
  physics::Frequency ENGINEERINGLIBRARY_API resonant_frequency(physics::Mass mass, 
                                                               physics::Damping damping,
                                                               physics::Stiffness stiffness);
  double ENGINEERINGLIBRARY_API resonant_magnitude_ratio(physics::Frequency natural_frequency, 
                                                         double damping_ratio);

};  // namespace eng

#endif
