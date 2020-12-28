#include "pch.h"
#include "Viscosity.h"

namespace eng {

  DViscosity operator""_kgpms(long double val) {
    return DViscosity(val);
  }

  DViscosity operator""_kgpms(unsigned long long val) {
    return DViscosity(val);
  }

  DViscosity operator""_Pas(long double val) {
    return DViscosity(val);
  }

  DViscosity operator""_Pas(unsigned long long val) {
    return DViscosity(val);
  }

  DViscosity operator""_Nspm2(long double val) {
    return DViscosity(val);
  }

  DViscosity operator""_Nspm2(unsigned long long val) {
    return DViscosity(val);
  }

  DViscosity operator""_P(long double val) {
    return DViscosity(val * 0.1);
  }

  DViscosity operator""_P(unsigned long long val) {
    return DViscosity(val * 0.1);
  }

  DViscosity operator""_lbspft2(long double val) {
    return DViscosity(val * 1.4881641);
  }

  DViscosity operator""_lbspft2(unsigned long long val) {
    return DViscosity(val * 1.4881641);
  }

///////////////////////////////////////////////////////////////////////////////
// Kinematic Viscosity
//

  KViscosity operator""_m2ps(long double val) {
    return KViscosity(val);
  }

  KViscosity operator""_m2ps(unsigned long long val) {
    return KViscosity(val);
  }

  KViscosity operator""_St(long double val) {
    return KViscosity(val * 0.0001);
  }

  KViscosity operator""_St(unsigned long long val) {
    return KViscosity(val * 0.0001);
  }

  KViscosity operator""_ft2ps(long double val) {
    return KViscosity(val * 0.092'903'04);
  }

  KViscosity operator""_ft2ps(unsigned long long val) {
      return KViscosity(val * 0.092'903'04);
  }

};  // namespace eng
