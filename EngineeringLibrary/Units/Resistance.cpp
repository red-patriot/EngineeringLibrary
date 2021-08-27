#include "pch.h"
#include "Resistance.h"

namespace eng {

  Resistance operator""_Ohm(long double val) {
    return Resistance(val);
  }

  Resistance operator""_Ohm(unsigned long long val) {
    return Resistance(val);
  }

  Resistance operator""_kOhm(long double val) {
    return Resistance(val * 1'000.0);
  }

  Resistance operator""_kOhm(unsigned long long val) {
    return Resistance(val * 1'000.0);
  }

  Resistance operator""_MOhm(long double val) {
    return Resistance(val * 1'000'000.0);
  }

  Resistance operator""_KOhm(unsigned long long val) {
    return Resistance(val * 1'000'000.0);
  }

};  // namespace eng
