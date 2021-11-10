#include "pch.h"
#include "CppUnitTest.h"

#include "UnitHelperFunctions.h"
#include "EngineeringLibrary/Engineering.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests {
  TEST_CLASS(TestsAccleration) {
  public:
    TEST_METHOD(TestConstruct) {
      eng::Acceleration a(1);
      Assert::AreEqual(1.0, a.mpsec2());
    }
    TEST_METHOD(TestConversion1) {
      eng::Acceleration a = eng::Acceleration(2.54/100), b = 1_inpsec2;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestConversion2) {
      eng::Acceleration a = eng::Acceleration(30.48/100), b = 1_ftpsec2;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestInversion) {
      eng::Acceleration a = 1_mpsec2;
      Assert::AreEqual(-1_mpsec2, -a);
    }
    TEST_METHOD(TestAdd) {
      eng::Acceleration a = 1_mpsec2, b = 10_mpsec2;
      auto c = a + b;
      Assert::AreEqual(11.0_mpsec2, c);
    }
    TEST_METHOD(TestSubtract) {
      eng::Acceleration a = 1_mpsec2, b = 10_mpsec2;
      auto c = b - a;
      Assert::AreEqual(9_mpsec2, c);
    }
    TEST_METHOD(TestMultiply) {
      eng::Acceleration a = 1_mpsec2;
      eng::Acceleration c = a * 123;
      Assert::AreEqual(123.0_mpsec2, c);
    }
    TEST_METHOD(TestDivide) {
      eng::Acceleration a = 12_mpsec2;
      eng::Acceleration c = a / 4;
      Assert::AreEqual(3_mpsec2, c);
    }
	};

  TEST_CLASS(TestsAngle) {
  public:
    TEST_METHOD(TestConstruct) {
      eng::Angle a(123);
      Assert::AreEqual(123.0, a.rad());
    }
    TEST_METHOD(TestConversion1) {
      eng::Angle a(eng::pi), b = 180_deg;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestInversion) {
      eng::Angle a = 1_rad;
      Assert::AreEqual(-1.0_rad, -a);
    }
    TEST_METHOD(TestAdd) {
      eng::Angle a = 2_rad, b = 18_rad;
      auto c = a + b;
      Assert::AreEqual(20_rad, c);
    }
    TEST_METHOD(TestSubtract) {
      eng::Angle a = 2_rad, b = 18_rad;
      auto c = b - a;
      Assert::AreEqual(16_rad, c);
    }
    TEST_METHOD(TestMultiply) {
      eng::Angle a = 3_deg;
      auto c = a * 12.0;
      Assert::AreEqual(36_deg, c);
    }
    TEST_METHOD(TestDivide) {
      eng::Angle a = 12_rad;
      auto c = a / 3.0;
      Assert::AreEqual(4_rad, c);
    }
  };

  TEST_CLASS(TestsArea) {
  public:
    TEST_METHOD(TestConstruct) {
      eng::Area a(57.234);
      Assert::AreEqual(57.234, a.m2());
    }
    TEST_METHOD(TestConversion1) {
      eng::Area a(6.4516/10'000), b = 1_in2;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestConversion2) {
      eng::Area a(929.0304/10'000), b = 1_ft2;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestConversion3) {
      eng::Area a = 1_m2, b = 10'000_cm2;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestConversion4) {
      eng::Area a = 1_m2, b = 1'000'000_mm2;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestInversion) {
      eng::Area a = 1_m2;
      Assert::AreEqual(-1.0_m2, -a);
    }
    TEST_METHOD(TestAdd) {
      eng::Area a = 3_in2, b = 1_in2;
      auto c = a + b;
      Assert::AreEqual(4.0_in2, c);
    }
    TEST_METHOD(TestSubtract) {
      eng::Area a = 3_m2, b = 1_m2;
      auto c = a - b;
      Assert::AreEqual(2.0_m2, c);
    }
    TEST_METHOD(TestMultiply) {
      eng::Area a = 4_in2;
      auto c = a * 2;
      Assert::AreEqual(8.0_in2, c);
    }
    TEST_METHOD(TestDivide) {
      eng::Area a = 4_mm2;
      auto c = a / 2;
      Assert::AreEqual(2.0_mm2, c);
    }
  };

  TEST_CLASS(TestsDamping) {
  public:
    TEST_METHOD(TestConstruct) {
      eng::Damping a(15.5);
      Assert::AreEqual(15.5, a.Nspm());
    }
    TEST_METHOD(TestConversion1) {
      eng::Damping a = 1_lbspin, b = 175.12683524648_Nspm;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestConversion2) {
      eng::Damping a = 1_lbspft, b = 14.59390293721_Nspm;
      Assert::AreEqual(b, a);
    }
    TEST_METHOD(TestConversion3) {
      eng::Damping a = 1_kNspm, b = 1000_Nspm;
      Assert::AreEqual(a, b);
    }

    TEST_METHOD(TestInversion) {
      eng::Damping a = 3_Nspm;
      Assert::AreEqual(-3_Nspm, -a);
    }
    TEST_METHOD(TestAdd) {
      eng::Damping a = 3_lbspft, b = 2_lbspft;
      auto c = a + b;
      Assert::AreEqual(5_lbspft, c);
    }
    TEST_METHOD(TestSubtract) {
      eng::Damping a = 3_lbspft, b = 2_lbspft;
      auto c = a - b;
      Assert::AreEqual(1_lbspft, c);
    }
    TEST_METHOD(TestMultiply) {
      eng::Damping a = 4_Nspm;
      auto c = a * 3;
      Assert::AreEqual(12_Nspm, c);
    }
    TEST_METHOD(TestDivide) {
      eng::Damping a = 4_Nspm;
      auto c = a / 2;
      Assert::AreEqual(2_Nspm, c);
    }
  };

  TEST_CLASS(TestsDViscosity) {
  public:
    TEST_METHOD(TestConstruct) {
      eng::DViscosity a(5.24);
      Assert::AreEqual(5.24, a.kgpms());
    }
    TEST_METHOD(TestConversion1) {
      eng::DViscosity a = 4.7037823_lbspft2;
      Assert::AreEqual(7_kgpms, a);
    }
    TEST_METHOD(TestConversion2) {
      eng::DViscosity a = 123.45_P;
      Assert::AreEqual(12.345_kgpms, a);
    }
  };

  TEST_CLASS(TestsKViscosity) {
  public:
    TEST_METHOD(TestConstruct) {
      eng::KViscosity a(5.24);
      Assert::AreEqual(5.24, a.m2ps());
    }
    TEST_METHOD(TestConversion1) {
      eng::KViscosity a = 4.7037823_ft2ps;
      Assert::AreEqual(0.436996_m2ps, a);
    }
    TEST_METHOD(TestConversion2) {
      eng::KViscosity a = 123.45_St;
      Assert::AreEqual(.012345_m2ps, a);
    }
  };

  TEST_CLASS(TestsEnergy) {
  public:
    TEST_METHOD(TestConstruct) {
      eng::Energy a(15.23);
      Assert::AreEqual(15.23, a.J());
    }
    TEST_METHOD(TestConversion1) {
      eng::Energy a = 1000_J, b = 1_kJ;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestConversion2) {
      eng::Energy a = 1'000'000_J, b = 1_MJ;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestConversion3) {
      eng::Energy a = 1_ftlb, b = 1.3558179_J;
      Assert::AreEqual(b, a);
    }
    TEST_METHOD(TestConversion4) {
      eng::Energy a = 10_inlb, b = 1.12984829_J;
      Assert::AreEqual(b, a);
    }
    TEST_METHOD(TestInversion) {
      eng::Energy a = 12.5_ftlb;
      Assert::AreEqual(-12.5_ftlb, -a);
    }
    TEST_METHOD(TestAdd) {
      eng::Energy a = 15_J, b = 4.7_J;
      eng::Energy c = a + b;
      Assert::AreEqual(19.7_J, c);
    }
    TEST_METHOD(TestSubtract) {
      eng::Energy a = 15_J, b = 4.7_J;
      eng::Energy c = a - b;
      Assert::AreEqual(10.3_J, c);
    }
    TEST_METHOD(TestMultiply) {
      eng::Energy a = 15_J;
      eng::Energy c = a * 3;
      Assert::AreEqual(45_J, c);
    }
    TEST_METHOD(TestDivide) {
      eng::Energy a = 15_J;
      eng::Energy c = a / 3;
      Assert::AreEqual(5_J, c);
    }
  };

  TEST_CLASS(TestsForce) {
  public:
    TEST_METHOD(TestConstruct) {
      eng::Force a(4.583);
      Assert::AreEqual(4.583, a.N());
    }
    TEST_METHOD(TestConversion1) {
      eng::Force a = 1_lbf, b = 4.4482216152605_N;
      Assert::AreEqual(b, a);
    }
    TEST_METHOD(TestConversion2) {
      eng::Force a = 1_kN, b = 1000_N;
      Assert::AreEqual(b, a);
    }
    TEST_METHOD(TestConversion3) {
      eng::Force a = 1_kips, b = 4448.2216152605_N;
      Assert::AreEqual(b, a);
    }
    TEST_METHOD(TestConversion4) {
      eng::Force a = 1_kips, b = 4.4482216152605_kN;
      Assert::AreEqual(b, a);
    }
    TEST_METHOD(TestInversion) {
      eng::Force a = 3_kN;
      Assert::AreEqual(-3_kN, -a);
    }
    TEST_METHOD(TestAdd) {
      eng::Force a = 16_lbf, b = 5_lbf;
      auto c = a + b;
      Assert::AreEqual(21_lbf, c);
    }
    TEST_METHOD(TestSubtract) {
      eng::Force a = 16_lbf, b = 5_lbf;
      auto c = a - b;
      Assert::AreEqual(11_lbf, c);
    }
    TEST_METHOD(TestMultiply) {
      eng::Force a = 5_kN;
      auto c = 8 * a;
      Assert::AreEqual(40_kN, c);
    }
    TEST_METHOD(TestDivide) {
      eng::Force a = 15_kN;
      auto c = a / 3;
      Assert::AreEqual(5_kN, c);
    }
  };

  TEST_CLASS(TestsFrequency) {
  public:
    TEST_METHOD(TestConstruct) {
      eng::Frequency a(9.1234);
      Assert::AreEqual(9.1234, a.Hz());
    }
    TEST_METHOD(TestConversion1) {
      eng::Frequency a = 12_kHz, b = 12'000_Hz;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestConversion2) {
      eng::Frequency a = 2_MHz, b = 2'000'000_Hz;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestInversion) {
      eng::Frequency a = 1_Hz;
      Assert::AreEqual(-1_Hz, -a);
    }
    TEST_METHOD(TestAdd) {
      eng::Frequency a = 30_Hz, b = 12_Hz;
      auto c = a + b;
      Assert::AreEqual(42_Hz, c);
    }
    TEST_METHOD(TestSubtract) {
      eng::Frequency a = 30_Hz, b = 12_Hz;
      auto c = a - b;
      Assert::AreEqual(18_Hz, c);
    }
    TEST_METHOD(TestMultiply) {
      eng::Frequency a = 15_kHz;
      auto c = a * 2;
      Assert::AreEqual(30_kHz, c);
    }
    TEST_METHOD(TestDivide) {
      eng::Frequency a = 15_kHz;
      auto c = a / 3;
      Assert::AreEqual(5_kHz, c);
    }
  };

  TEST_CLASS(TestsLength) {
  public:
    TEST_METHOD(TestConstruct) {
      eng::Length a(48.95);
      Assert::AreEqual(48.95, a.m());
    }
    TEST_METHOD(TestConversion1) {
      eng::Length a = 2.54_cm, b = 1_in;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestConversion2) {
      eng::Length a = 0.3048_m, b = 1_ft;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestConversion3) {
      eng::Length a = 5280_ft, b = 1_mi;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestConversion4) {
      eng::Length a = 100_cm, b = 1_m;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestInversion) {
      eng::Length a = 3_in;
      Assert::AreEqual(-3_in, -a);
    }
    TEST_METHOD(TestAdd) {
      eng::Length a = 18_m, b = 6_m;
      auto c = a + b;
      Assert::AreEqual(24_m, c);
    }
    TEST_METHOD(TestSubtract) {
      eng::Length a = 18_m, b = 6_m;
      auto c = a - b;
      Assert::AreEqual(12_m, c);
    }
    TEST_METHOD(TestMultiply) {
      eng::Length a = 18_m;
      auto c = a * 2;
      Assert::AreEqual(36_m, c);
    }
    TEST_METHOD(TestDivide) {
      eng::Length a = 18_m;
      auto c = a / 2;
      Assert::AreEqual(9_m, c);
    }
  };

  TEST_CLASS(TestsMass) {
  public:
    TEST_METHOD(TestConstruct) {
      eng::Mass a(14.0);
      Assert::AreEqual(14.0, a.kg());
    }
    TEST_METHOD(TestConversion1) {
      eng::Mass a = 50_g, b = .05_kg;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestConversion2) {
      eng::Mass a = 14.593903_kg, b = 1_slug;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestInversion) {
      eng::Mass a = 1_slug;
      Assert::AreEqual(-1_slug, -a);
    }
    TEST_METHOD(TestAdd) {
      eng::Mass a = 50_g, b = 5_g;
      auto c = a + b;
      Assert::AreEqual(55_g, c);
    }
    TEST_METHOD(TestSubtract) {
      eng::Mass a = 50_g, b = 5_g;
      auto c = a - b;
      Assert::AreEqual(45_g, c);
    }
    TEST_METHOD(TestMultiply) {
      eng::Mass a = 50_g;
      auto c = a * 20;
      Assert::AreEqual(1_kg, c);
    }
    TEST_METHOD(TestDivide) {
      eng::Mass a = 50_g;
      auto c = a / 5;
      Assert::AreEqual(10_g, c);
    }
  };

  TEST_CLASS(TestsPressure) {
  public:
    TEST_METHOD(TestConstruct) {
      eng::Pressure a(33.54);
      Assert::AreEqual(33.54, a.Pa());
    }
    TEST_METHOD(TestConversion1) {
      eng::Pressure a = 1_psi, b = 6'894.757'293_Pa;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestConversion2) {
      eng::Pressure a = 1000_psi, b = 1_ksi;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestConversion3) {
      eng::Pressure a = 1000_Pa, b = 1_kPa;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestConversion4) {
      eng::Pressure a = 1'000'000_Pa, b = 1_MPa;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestInversion) {
      eng::Pressure a = 12.5_Pa;
      Assert::AreEqual(-12.5_Pa, -a);
    }
    TEST_METHOD(TestAdd) {
      eng::Pressure a = 12_kPa, b = 4_kPa;
      auto c = a + b;
      Assert::AreEqual(16_kPa, c);
    }
    TEST_METHOD(TestSubtract) {
      eng::Pressure a = 12_kPa, b = 4_kPa;
      auto c = a - b;
      Assert::AreEqual(8_kPa, c);
    }
    TEST_METHOD(TestMultiply) {
      eng::Pressure a = 15_MPa;
      auto c = a * 2.5;
      Assert::AreEqual(37.5_MPa, c);
    }
    TEST_METHOD(TestDivide) {
      eng::Pressure a = 15_MPa;
      auto c = a / 1.5;
      Assert::AreEqual(10_MPa, c);
    }
  };

  TEST_CLASS(TestsSecondMomentOfArea) {
  public:
    TEST_METHOD(TestConstruct) {
      eng::SecondMomentOfArea a(54.34);
      Assert::AreEqual(54.34, a.m4());
    }
    TEST_METHOD(TestConversion1) {
      eng::SecondMomentOfArea a = 1_ft4, b = 0.0086309748_m4;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestConversion2) {
      eng::SecondMomentOfArea a = 20'736_in4, b = 1_ft4;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestConversion3) {
      eng::SecondMomentOfArea a = 1_m4, b = 1'000'000'000'000_mm4;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestInversion) {
      eng::SecondMomentOfArea a = 5_ft4;
      Assert::AreEqual(-5_ft4, -a);
    }
    TEST_METHOD(TestAdd) {
      eng::SecondMomentOfArea a = 500_mm4, b = 20_mm4;
      auto c = a + b;
      Assert::AreEqual(520_mm4, c);
    }
    TEST_METHOD(TestSubtract) {
      eng::SecondMomentOfArea a = 500_mm4, b = 20_mm4;
      auto c = a - b;
      Assert::AreEqual(480_mm4, c);
    }
    TEST_METHOD(TestMultiply) {
      eng::SecondMomentOfArea a = 50_m4;
      auto c = a * 1.5;
      Assert::AreEqual(75_m4, c);
    }
    TEST_METHOD(TestDivide) {
      eng::SecondMomentOfArea a = 50_m4;
      auto c = a / 2.0;
      Assert::AreEqual(25_m4, c);
    }
  };

  TEST_CLASS(TestsStiffness) {
  public:
    TEST_METHOD(TestConstruct) {
      eng::Stiffness a(14.5);
      Assert::AreEqual(14.5, a.Npm());
    }
    TEST_METHOD(TestConversion1) {
      eng::Stiffness a = 1_Npmm, b = 1000_Npm;
      Assert::AreEqual(b, a);
    }
    TEST_METHOD(TestConversion2) {
      eng::Stiffness a = 1_lbpin, b = 175.126835246_Npm;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestConversion3) {
      eng::Stiffness a = 1_lbpft, b = 14.5939029_Npm;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestInversion) {
      eng::Stiffness a = 12.654_Npmm;
      Assert::AreEqual(-12.654_Npmm, -a);
    }
    TEST_METHOD(TestAdd) {
      eng::Stiffness a = 54.5_lbpin, b = 43_lbpin;
      auto c = a + b;
      Assert::AreEqual(97.5_lbpin, c);
    }
    TEST_METHOD(TestSubtract) {
      eng::Stiffness a = 54.5_lbpin, b = 43_lbpin;
      auto c = a - b;
      Assert::AreEqual(11.5_lbpin, c);
    }
    TEST_METHOD(TestMultiply) {
      eng::Stiffness a = 15_Npm;
      auto c = a * 1.75;
      Assert::AreEqual(26.25_Npm, c);
    }
    TEST_METHOD(TestDivide) {
      eng::Stiffness a = 15_Npm;
      auto c = a / 1.75;
      Assert::AreEqual(8.571428_Npm, c);
    }
  };

  TEST_CLASS(TestsTemperature) {
  public:
    TEST_METHOD(TestConstruct) {
      eng::Temperature a(173.15);
      Assert::AreEqual(173.15, a.Kelvin());
    }
    TEST_METHOD(TestConversion1) {
      eng::Temperature a = eng::Celcius(0);
      Assert::AreEqual(273.15_Kelvin, a);
    }
    TEST_METHOD(TestConversion2) {
      eng::Temperature a = eng::Farenheit(32);
      Assert::AreEqual(273.15_Kelvin, a);
    }
    TEST_METHOD(TestConversion3) {
      eng::Temperature a = 100_Rankine;
      Assert::AreEqual(55.555555555_Kelvin, a);
    }
    TEST_METHOD(TestConversion4) {
      eng::Temperature a = eng::Farenheit(-459.67);
      Assert::AreEqual(0_Rankine, a);
    }
  };

  TEST_CLASS(TestsTime) {
  public:
    TEST_METHOD(TestConstruct) {
      eng::Time a(48.92);
      Assert::AreEqual(48.92, a.sec());
    }
    TEST_METHOD(TestConversion1) {
      eng::Time a = 60_sec, b = 1_minute;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestConversion2) {
      eng::Time a = 1_hour, b = 3600_sec;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestInversion) {
      eng::Time a = 39.54_minute;
      Assert::AreEqual(-39.54_minute, -a);
    }
    TEST_METHOD(TestAdd) {
      eng::Time a = 45_sec, b = 15_sec;
      auto c = a + b;
      Assert::AreEqual(1_minute, c);
    }
    TEST_METHOD(TestSubtract) {
      eng::Time a = 45_sec, b = 15_sec;
      auto c = a - b;
      Assert::AreEqual(0.5_minute, c);
    }
    TEST_METHOD(TestMultiply) {
      eng::Time a = 20_sec;
      auto c = a * 2;
      Assert::AreEqual(40_sec, c);
    }
    TEST_METHOD(TestDivide) {
      eng::Time a = 20_sec;
      auto c = a / 2;
      Assert::AreEqual(10_sec, c);
    }
  };

  TEST_CLASS(TestsTorque) {
  public:
    TEST_METHOD(TestConstruct) {
      eng::Torque a(15.23);
      Assert::AreEqual(15.23, a.Nm());
    }
    TEST_METHOD(TestConversion1) {
      eng::Torque a = 1000_Nm, b = 1_kNm;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestConversion2) {
      eng::Torque a = 0.001_Nm, b = 1_Nmm;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestConversion3) {
      eng::Torque a = 1_lbft, b = 1.3558179_Nm;
      Assert::AreEqual(b, a);
    }
    TEST_METHOD(TestConversion4) {
      eng::Torque a = 10_lbin, b = 1.12984829_Nm;
      Assert::AreEqual(b, a);
    }
    TEST_METHOD(TestInversion) {
      eng::Torque a = 12.5_lbft;
      Assert::AreEqual(-12.5_lbft, -a);
    }
    TEST_METHOD(TestAdd) {
      eng::Torque a = 15_Nm, b = 4.7_Nm;
      eng::Torque c = a + b;
      Assert::AreEqual(19.7_Nm, c);
    }
    TEST_METHOD(TestSubtract) {
      eng::Torque a = 15_Nm, b = 4.7_Nm;
      eng::Torque c = a - b;
      Assert::AreEqual(10.3_Nm, c);
    }
    TEST_METHOD(TestMultiply) {
      eng::Torque a = 15_Nm;
      eng::Torque c = a * 3;
      Assert::AreEqual(45_Nm, c);
    }
    TEST_METHOD(TestDivide) {
      eng::Torque a = 15_Nm;
      eng::Torque c = a / 3;
      Assert::AreEqual(5_Nm, c);
    }
  };

  TEST_CLASS(TestsVelocity) {
  public:
    TEST_METHOD(TestConstruct) {
      eng::Velocity a(56.017);
      Assert::AreEqual(56.017, a.mpsec());
    }
    TEST_METHOD(TestConversion1) {
      eng::Velocity a = 1_ftpsec, b = 0.3048_mpsec;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestConversion2) {
      eng::Velocity a = 1_kph, b = 0.277'778_mpsec;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestConversion3) {
      eng::Velocity a = 5_inpsec, b = 0.127_mpsec;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestConversion4) {
      eng::Velocity a = 2_mph, b = 0.89408_mpsec;
      Assert::AreEqual(a, b);
    }
    TEST_METHOD(TestInversion) {
      eng::Velocity a = 35_kph;
      Assert::AreEqual(-35_kph, -a);
    }
    TEST_METHOD(TestAdd) {
      eng::Velocity a = 35.5_ftpsec, b = 5.25_ftpsec;
      auto c = a + b;
      Assert::AreEqual(40.75_ftpsec, c);
    }
    TEST_METHOD(TestSubtract) {
      eng::Velocity a = 35.5_ftpsec, b = 5.25_ftpsec;
      auto c = a - b;
      Assert::AreEqual(30.25_ftpsec, c);
    }
    TEST_METHOD(TestMultiply) {
      eng::Velocity a = 18.5_mph;
      auto c = a * 2;
      Assert::AreEqual(37_mph, c);
    }
    TEST_METHOD(TestDivide) {
      eng::Velocity a = 18.5_mph;
      auto c = a / 2;
      Assert::AreEqual(9.25_mph, c);
    }
  };
}

