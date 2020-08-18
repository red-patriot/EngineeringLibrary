#ifndef System_Dynamics_h_INCLUDED
#define System_Dynamics_h_INCLUDED

/*****************************************************************//**
 * \file  SystemDynamics.h
 * \brief Functionality to analyze Dynamic Systems 
 *
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "EngineeringExport.h"

#include "Units/Mass.h"
#include "Units/Damping.h"
#include "Units/Stiffness.h"
#include "Units/Frequency.h"

namespace eng {

  /**
   * \brief Calulate the natural frequency of the system's frequency response
   */
  Frequency ENGINEERINGLIBRARY_API natural_frequency(Mass mass, 
                                                     Damping damping,
                                                     Stiffness stiffness);
  /**
   * \brief Calculate the damping ration of a system 
   */
  double ENGINEERINGLIBRARY_API damping_ratio(Mass mass,  
                                              Damping damping,
                                              Stiffness stiffness);
  /**
   * \brief Calculate the resonant frequency of a system
   */
  Frequency ENGINEERINGLIBRARY_API resonant_frequency(Frequency natural_frequency,
                                                      double damping_ratio);
  /**
   * \brief Calculate the resonant frequency of a system
   */
  Frequency ENGINEERINGLIBRARY_API resonant_frequency(Mass mass, 
                                                      Damping damping,
                                                      Stiffness stiffness);
  /**
   * \brief Calculate the resonant magnitude ratio of a system
   */
  double ENGINEERINGLIBRARY_API resonant_magnitude_ratio(Frequency natural_frequency, 
                                                         double damping_ratio);

};  // namespace eng

#endif
