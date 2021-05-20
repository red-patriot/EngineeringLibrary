#include "pch.h"
#include "CppUnitTest.h"

#include <exception>

#include "UnitHelperFunctions.h"
//#include "VectorHelperFunctions.h"

#include "EngineeringLibrary/Engineering.h"
#include "EngineeringLibrary/Vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VectorTests {
  TEST_CLASS(VectorTests) {
  public:
    TEST_METHOD(TestConstruct1) {
      eng::MomentVec<1> v({12.5_Nm});
      Assert::AreEqual(12.5_Nm, v.x());

      Assert::AreEqual(v.x(), v[0]);
    }
    TEST_METHOD(TestConstruct2) {
      eng::ForceVec<2> v({5.5_lbf, 4_lbf});
      Assert::AreEqual(5.5_lbf, v.x());
      Assert::AreEqual(4.0_lbf, v.y());

      Assert::AreEqual(v.x(), v[0]);
      Assert::AreEqual(v.y(), v[1]);
    }
    TEST_METHOD(TestConstruct3) {
      eng::LengthVec<3> v({1_m, 2_m, 3_m});
      Assert::AreEqual(1_m, v.x());
      Assert::AreEqual(2_m, v.y());
      Assert::AreEqual(3_m, v.z());

      Assert::AreEqual(v.x(), v[0]);
      Assert::AreEqual(v.y(), v[1]);
      Assert::AreEqual(v.z(), v[2]);
    }

    TEST_METHOD(TestConstruct6) {
      eng::LengthVec<6> v({5_ft, 6.0_ft, 12.543_ft, 0.54_ft, 1.0_ft, 4.5_ft});
      Assert::AreEqual(5.0_ft, v.x());
      Assert::AreEqual(6.0_ft, v[1]);
      Assert::AreEqual(12.543_ft, v.z());
      Assert::AreEqual(0.54_ft, v[3]);
      Assert::AreEqual(1.0_ft, v[4]);
      Assert::AreEqual(4.5_ft, v[5]);
    }
    TEST_METHOD(TestCross) {
      Assert::AreEqual(eng::MomentVec<3>({-3_Nm, 6_Nm, -3_Nm}), 
                       eng::cross(eng::LengthVec<3>({1_m, 2_m, 3_m}), 
                       eng::ForceVec<3>({4_N, 5_N, 6_N})));
    }
    TEST_METHOD(TestDot) {
      Assert::AreEqual(32_Nm, eng::dot(eng::LengthVec<3>({1_m, 2_m, 3_m}),
                                       eng::ForceVec<3>({4_N, 5_N, 6_N})));
    }
  };
};  // namespace VectorTests
