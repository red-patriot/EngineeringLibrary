#include "pch.h"

#include "Voltage.h"

namespace eng {
  Voltage operator""_mV(long double val) {
    return Voltage(val * 0.001);
  }

  Voltage operator""_mV(unsigned long long val) {
    return Voltage(val * 0.001);
  }

  Voltage operator""_V(long double val) {
    return Voltage(val);
  }

  Voltage operator""_V(unsigned long long val) {
    return Voltage(val);
  }

  Voltage operator""_kV(long double val) {
    return Voltage(val * 1000.0);
  }

  Voltage operator""_kV(unsigned long long val) {
    return Voltage(val * 1000.0);
  }

};  // namespace eng
