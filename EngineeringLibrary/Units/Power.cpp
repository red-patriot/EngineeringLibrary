#include "pch.h"

#include "Power.h"

namespace eng {
  Power operator""_mW(long double val) {
    return Power(val * 0.001);
  }

  Power operator""_mW(unsigned long long val) {
    return Power(val * 0.001);
  }

  Power operator""_W(long double val) {
    return Power(val);
  }

  Power operator""_W(unsigned long long val) {
    return Power(val);
  }

  Power operator""_kW(long double val) {
    return Power(val * 1'000.0);
  }

  Power operator""_kW(unsigned long long val) {
    return Power(val * 1'000.0);
  }

  Power operator""_MW(long double val) {
    return Power(val * 1'000'000.0);
  }

  Power operator""_MW(unsigned long long val) {
    return Power(val * 1'000'000.0);
  }

  Power operator""_hp(long double val) {
    return Power(val * 745.699'871'582'270);
  }

  Power operator""_hp(unsigned long long val) {
    return Power(val * 745.699'871'582'270);
  }

  Power operator""_hp_M(long double val) {
    return Power(val * 735.498'75);
  }

  Power operator""_hp_M(unsigned long long val) {
    return Power(val * 735.498'75);
  }

  Power operator""_hp_E(long double val) {
    return Power(val * 746.0);
  }

  Power operator""_hp_E(unsigned long long val) {
    return Power(val * 746.0);
  }

  Power operator""_TR(long double val) {
    return Power(val * 3'516.852'842'1);
  }

  Power operator""_TR(unsigned long long val) {
    return Power(val * 3'516.852'842'1);
  }
};  // namespace eng
