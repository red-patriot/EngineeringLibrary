#include "pch.h"
#include "CppUnitTest.h"

#include <exception>

#include "UnitHelperFunctions.h"
//#include "VectorHelperFunctions.h"

#include "EngineeringLibrary/Engineering.h"
#include "EngineeringLibrary/Vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VectorTests {
  TEST_CLASS(TestVec1) {
    eng::MomentVec<1> v = eng::MomentVec<1>({12.5_Nm});
  public:
    TEST_METHOD(TestX) {
      Assert::AreEqual(12.5_Nm, v.x());
    }
    TEST_METHOD(TestSubscript) {
      Assert::AreEqual(v.x(), v[0]);
    }
  };
  TEST_CLASS(TestVec2) {
    eng::ForceVec<2> v = eng::ForceVec<2>({5.5_lbf, 4_lbf});
  public:
    TEST_METHOD(TestXY) {
      Assert::AreEqual(5.5_lbf, v.x());
      Assert::AreEqual(4.0_lbf, v.y());
    }
    TEST_METHOD(TestSubscript) {
      Assert::AreEqual(v.x(), v[0]);
      Assert::AreEqual(v.y(), v[1]);
    }
  };
  TEST_CLASS(TestVec3) {
    eng::LengthVec<3> v = eng::LengthVec<3>({1_m, 2_m, 3_m});
  public:
    TEST_METHOD(TestXYZ) {
      Assert::AreEqual(1_m, v.x());
      Assert::AreEqual(2_m, v.y());
      Assert::AreEqual(3_m, v.z());
    }
    TEST_METHOD(TestSubscript) {
      Assert::AreEqual(v.x(), v[0]);
      Assert::AreEqual(v.y(), v[1]);
      Assert::AreEqual(v.z(), v[2]);
    }
  }; 
  TEST_CLASS(TestVec6) {
    eng::LengthVec<6> v = eng::LengthVec<6>({5_ft, 6.0_ft, 12.543_ft, 0.54_ft, 1.0_ft, 4.5_ft});
  public:
    TEST_METHOD(TestSubscript) {
      Assert::AreEqual(5.0_ft, v.x());
      Assert::AreEqual(6.0_ft, v[1]);
      Assert::AreEqual(12.543_ft, v.z());
      Assert::AreEqual(0.54_ft, v[3]);
      Assert::AreEqual(1.0_ft, v[4]);
      Assert::AreEqual(4.5_ft, v[5]);
    }
  };
  TEST_CLASS(ArithmeticTests) {
  public:
    TEST_METHOD(TestAdd) {
      Assert::AreEqual(true, true);
    }
    TEST_METHOD(TestSubttract) {
      Assert::AreEqual(true, true);
    }
    TEST_METHOD(TestDivide) {
      Assert::AreEqual(true, true);
    }
    TEST_METHOD(TestMultiply) {
      Assert::AreEqual(true, true);
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
  TEST_CLASS(NormTests) {
  public:
    TEST_METHOD(TestNorm) {
      eng::LengthVec<4> v({12_m, 3.24_m, -9.846_m, 0.5_m});
      Assert::AreEqual(15.864782255_m, eng::norm(v));
    }
    TEST_METHOD(TestNormalize) {
     eng::LengthVec<4> v({12_m, 3.24_m, -9.846_m, 0.5_m});
     Assert::AreEqual(eng::UnitlessVec<4>({0.756392354, 0.204225935, -0.6206199266, 0.031516348}),
                      eng::normalize(v));
   }
   TEST_METHOD(TestInfinityNorm1) {
     eng::ForceVec<5> v({1.5_N, 0.0_N, 10_N, -3.45_N, 5.67_N});
     Assert::AreEqual(10_N, eng::norm_inf(v));
   }
   TEST_METHOD(TestInfinityNorm2) {
     eng::ForceVec<3> v({4.56_lbf, -12.7_lbf, -10_lbf});
     Assert::AreEqual(12.7_lbf, eng::norm_inf(v));
   }
   TEST_METHOD(TestInfinityNorm3) {
     eng::MomentVec<4> v({1.25_Nm, 3.5_Nm, -1.3_Nm, 3.5_Nm});
     Assert::AreEqual(3.5_Nm, eng::norm_inf(v));
   }
  };
};  // namespace VectorTests
