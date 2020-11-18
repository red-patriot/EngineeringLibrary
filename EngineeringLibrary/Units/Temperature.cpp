#include "pch.h"
#include "Temperature.h"

namespace eng {

  Temperature operator""_Kelvin(long double val) {
    return Temperature(val);
  }

  Temperature operator""_Kelvin(unsigned long long val) {
    return Temperature(val);
  }

  Temperature operator""_deg_C(long double val) {
    return Temperature(val + 273.15);
  }

  Temperature operator""_deg_C(unsigned long long val) {
    return Temperature(val + 273.15);
  }

  Temperature operator""_Rankine(long double val) {
    return Temperature(val * (5.0/9.0));
  }

  Temperature operator""_Rankine(unsigned long long val) {
    return Temperature(val * (5.0/9.0));
  }

  Temperature operator""_deg_F(long double val) {
    return Temperature((5.0/9.0)*(val - 32.0) + 237.15);
  }

  Temperature operator""_deg_F(unsigned long long val) {
    return Temperature((5.0/9.0)*(val - 32.0) + 237.15);
  }

};  // namespace eng
