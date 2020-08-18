#include "pch.h"

#include <cmath>

#include "SystemDynamics.h"

namespace eng {
  Frequency natural_frequency(Mass mass, Damping damping, Stiffness stiffness) {
    return sqrt(stiffness/mass);
  }

  double damping_ratio(Mass mass, Damping damping, Stiffness stiffness) {
    return damping/(2 * mass * natural_frequency(mass, damping, stiffness));
  }

  Frequency resonant_frequency(Frequency natural_frequency, double damping_ratio) {
    return natural_frequency * std::sqrt(1 - 2 * damping_ratio*damping_ratio);
  }

  Frequency resonant_frequency(Mass mass, Damping damping, Stiffness stiffness) {
    return resonant_frequency(natural_frequency(mass, damping, stiffness),
                              damping_ratio(mass, damping, stiffness));
  }

  double resonant_magnitude_ratio(Frequency natural_frequency, double damping_ratio) {
    return 1 / (2*damping_ratio * std::sqrt(1 - damping_ratio*damping_ratio));
  }

};  // namespace eng
