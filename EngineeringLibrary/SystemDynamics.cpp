#include "pch.h"

#include <cmath>

#include "SystemDynamics.h"

namespace eng {
  physics::Frequency natural_frequency(physics::Mass mass, physics::Damping damping,
                           physics::Stiffness stiffness) {
    return physics::sqrt(stiffness/mass);
  }

  double damping_ratio(physics::Mass mass, physics::Damping damping, physics::Stiffness stiffness) {
    return damping/(2 * mass * natural_frequency(mass, damping, stiffness));
  }

  physics::Frequency resonant_frequency(physics::Frequency natural_frequency, double damping_ratio) {
    return natural_frequency * std::sqrt(1 - 2 * damping_ratio*damping_ratio);
  }

  physics::Frequency resonant_frequency(physics::Mass mass, physics::Damping damping, physics::Stiffness stiffness) {
    return resonant_frequency(natural_frequency(mass, damping, stiffness),
                              damping_ratio(mass, damping, stiffness));
  }

  double resonant_magnitude_ratio(physics::Frequency natural_frequency, double damping_ratio) {
    return 1 / (2*damping_ratio * std::sqrt(1 - damping_ratio*damping_ratio));
  }

};  // namespace eng
