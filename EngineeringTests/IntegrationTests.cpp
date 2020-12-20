#include "pch.h"
#include "CppUnitTest.h"

#include "UnitHelperFunctions.h"

#include "EngineeringLibrary/Engineering.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntegrationTests {
  TEST_CLASS(IntegrationTests) {
  public:
    TEST_METHOD(Length_Area) {
      eng::Length a = 1_m;
      eng::Length b = 5_m;
      Assert::AreEqual(5_m2, a * b);
    }
    TEST_METHOD(Area_SecondMomentOfArea) {
      eng::Area a = 2_m2;
      eng::Area b = 4_m2;
      Assert::AreEqual(8_m4, a * b);
    }
    TEST_METHOD(Mass_Accel_Force) {
      eng::Acceleration a = 1_mpsec2;
      eng::Mass b = 1_kg;
      Assert::AreEqual(1_N, a * b);
    }
    TEST_METHOD(Stiffness_Length_Force) {
      eng::Stiffness a = 1_Npm;
      eng::Length b = 2_m;
      Assert::AreEqual(2_N, a * b);
    }
    TEST_METHOD(Pressure_Area_Force) {
      eng::Pressure a = 1_Pa;
      eng::Area b = 1_m2;
      Assert::AreEqual(1_N, a * b);
    }
  };
};
