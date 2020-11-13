#include "pch.h"

#include "MomentOfArea.h"
#include "Volume.h"
#include "Area.h"
#include "Length.h"

namespace eng {

  /* Literal operators
   * The following units are supported:
   * mm^3, cm^3, m^3
   * in^3, ft^3
   */

  Volume operator""_mm3(long double val) {
    return Volume(val * 0.000'000'001);
  }

  Volume operator""_mm3(unsigned long long val) {
    return Volume(val * 0.000'000'001);
  }

  Volume operator""_cm3(long double val) {
    return Volume(val * 0.000001);
  }

  Volume operator""_cm3(unsigned long long val) {
    return Volume(val * 0.000001);
  }

  Volume operator""_m3(long double val) {
    return Volume(val);
  }

  Volume operator""_m3(unsigned long long val) {
    return Volume(val);
  }

  Volume operator""_in3(long double val) {
    return Volume(val * (16.387'064/1'000'000));
  }

  Volume operator""_in3(unsigned long long val) {
    return Volume(val * (16.387'064/1'000'000));
  }

  Volume operator""_ft3(long double val) {
    return Volume(val * (28'316.846'592/1'000'000));
  }

  Volume operator""_ft3(unsigned long long val) {
    return Volume(val * (28'316.846'592/1'000'000));
  }

}; // namespace eng
