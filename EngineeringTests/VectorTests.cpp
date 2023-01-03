#include "pch.h"
#include "CppUnitTest.h"

#include "VectorHelperFunctions.h"

#include "EngineeringLibrary/Engineering.h"
#include "EngineeringLibrary/Vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VectorTests {
  TEST_CLASS(TestVector) {
  public:
    TEST_METHOD(TestCross) {
      Assert::AreEqual(eng::MomentVec(-3_Nm, 6_Nm, -3_Nm), eng::cross(eng::LengthVec{1_m, 2_m, 3_m}, 
                                                                      eng::ForceVec{4_N, 5_N, 6_N}));
    }
    TEST_METHOD(TestDot) {
      Assert::AreEqual(32_Nm, eng::dot(eng::LengthVec{1_m, 2_m, 3_m},
                                       eng::ForceVec{4_N, 5_N, 6_N}));
    }
  };
};  // namespace VectorTests
