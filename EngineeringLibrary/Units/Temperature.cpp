#include "pch.h"
#include "Temperature.h"

namespace eng {

  Temperature operator""_Kelvin(long double val) {
    return Temperature(val);
  }

  Temperature operator""_Kelvin(unsigned long long val) {
    return Temperature(val);
  }

  Temperature operator""_Rankine(long double val) {
    return Temperature(val * (5.0/9.0));
  }

  Temperature operator""_Rankine(unsigned long long val) {
    return Temperature(val * (5.0/9.0));
  }

  Temperature Celcius(const double deg_C) {
      return Temperature(deg_C + 273.15);
  }

  Temperature Farenheit(const double deg_F) {
    return Temperature((deg_F + 459.67) * 5.0/9.0);
  }

  /* Angry comment:
   * The Celcius and Farenheit functions exist (as opposed to being literal 
   * operators like the other operators) because temperature scales are the 
   * literal worst and whoever decided that we would continue using 
   * non-absolute temperature scales deserves to rot in Hell.
   * Yes I understand the historical reasons that relative scales are used, but 
   * that does not make them any less frustrating.
   */

};  // namespace eng
