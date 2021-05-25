#include "pch.h"
#include "CppUnitTest.h"

#include <vector>
#include <iostream>
#include <algorithm>

#include "UnitHelperFunctions.h"

#include "EngineeringLibrary/Engineering.h"
#include "EngineeringLibrary/StaticSystems/AppliedLoad.h"
#include "EngineeringLibrary/StaticSystems/StaticSystem.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StaticSystemsTests {
  TEST_CLASS(TestsAppliedLoadKnown) {
    eng::AppliedLoad a{eng::ForceVec<3>({2_N, 10_N, 25_N}), eng::LengthVec<3>({4_m, 13_m, 16_m})};
    eng::AppliedLoad b{1_N, 2_N, 2_N, eng::LengthVec<3>({4_m, 4_m, 7_m})};
  public:
    TEST_METHOD(TestDirection1) { 
      Assert::AreEqual(eng::UnitlessVec<3>({2.0/27.0, 10.0/27.0, 25.0/27.0}), *a.get_direction());
    }
    TEST_METHOD(TestDirection2) {
      Assert::AreEqual(eng::UnitlessVec<3>({1.0/3.0, 2.0/3.0, 2.0/3.0}), *b.get_direction());
    }
    TEST_METHOD(TestMagnitude) { 
      Assert::AreEqual(27_N, *a.get_magnitude());
    }
    TEST_METHOD(TestForceVec) { 
      Assert::AreEqual(eng::ForceVec<3>({1_N, 2_N, 2_N}), *b.get_force_vector());
    }
    TEST_METHOD(TestPosition) {
      Assert::AreEqual(eng::LengthVec<3>({4_m, 4_m, 7_m}), b.get_position());
    }
  };

  TEST_CLASS(TestsAppliedLoadUnknown) {
    eng::AppliedLoad a{2_m, 10_m, 11_m};  // Completely unknown
    eng::AppliedLoad b{2_m, 10_m, 11_m};  // Completely unknown
    eng::AppliedLoad c{eng::UnitlessVec<3>(eng::i_hat), 
                       eng::LengthVec<3>({1_m, 2_m, 2_m})};  // Magnitude unknown
  public:
    TEST_METHOD(TestDirection1) {
      Assert::AreEqual(false, (bool)a.get_direction());
    }
    TEST_METHOD(TestDirection2) {
      Assert::AreEqual(false, (bool)b.get_direction());
    }
    TEST_METHOD(TestDirection3) {
      Assert::AreEqual(eng::i_hat, *c.get_direction());
    }
    TEST_METHOD(TestMagnitude1) {
      Assert::AreEqual(false, (bool)a.get_magnitude());
    }
    TEST_METHOD(TestMagnitude2) {
      Assert::AreEqual(false, (bool)c.get_magnitude());
    }
    TEST_METHOD(TestForceVec1) {
      Assert::AreEqual(false, (bool)b.get_force_vector());
    }
    TEST_METHOD(TestForceVec2) {
      Assert::AreEqual(false, (bool)c.get_force_vector());
    }
    TEST_METHOD(TestPosition1) {
      Assert::AreEqual(eng::LengthVec<3>({2_m, 10_m, 11_m}), a.get_position());
    }
    TEST_METHOD(TestPosition2) {
      Assert::AreEqual(eng::LengthVec<3>({2_m, 10_m, 11_m}), b.get_position());
    }
    TEST_METHOD(TestPosition3) {
      Assert::AreEqual(eng::LengthVec<3>({1_m, 2_m, 2_m}), c.get_position());
    }
  };


};
