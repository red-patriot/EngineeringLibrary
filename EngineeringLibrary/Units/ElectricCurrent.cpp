#include "pch.h"
#include "ElectricCurrent.h"

namespace eng {

  ElectricCurrent eng::operator""_Amp(long double val) {
    return ElectricCurrent(val);
  }

  ElectricCurrent eng::operator""_Amp(unsigned long long val) {
    return ElectricCurrent(val);
  }

  ElectricCurrent eng::operator""_mAmp(long double val) {
    return ElectricCurrent(val * 0.001);
  }

  ElectricCurrent eng::operator""_mAmp(unsigned long long val) {
    return ElectricCurrent(val * 0.001);
  }

};  // namespace eng 
