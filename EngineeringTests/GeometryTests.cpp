#include "pch.h"
#include "CppUnitTest.h"

#include "UnitHelperFunctions.h"
#include "VectorHelperFunctions.h"
#include "EngineeringLibrary/Engineering.h"

#include"EngineeringLibrary/Geometric/Geometric.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GeometryTests {
  TEST_CLASS(TestGeometry) {
    eng::Geometry g{2_m2, {5.4_m4, 2.6_m4, 3.5_m4}, {0_m, 0_m, 3.5_m}};
  public:
    TEST_METHOD(TestArea) {
      Assert::AreEqual(2_m2, g.area());
    }
    TEST_METHOD(TestCentroid) {
      Assert::AreEqual({0_m, 0_m, 3.5_m}, g.centroid());
    }
    TEST_METHOD(TestMomentOfArea) {
      Assert::AreEqual(5.4_m4, g.moment_of_inertia().Ixx);
      Assert::AreEqual(2.6_m4, g.moment_of_inertia().Iyy);
      Assert::AreEqual(3.5_m4, g.moment_of_inertia().Ixy);
    }
    TEST_METHOD(TestParallelAxes) {
      eng::Geometry::AreaMomentofInertia I = g.moment_of_inertia({1_m, 2_m, 0_m});
      Assert::AreEqual(13.4_m4, I.Ixx);
      Assert::AreEqual(4.6_m4, I.Iyy);
      Assert::AreEqual(7.5_m4, I.Ixy);
    }
    TEST_METHOD(TestRotatedAxes) {
      eng::Geometry::AreaMomentofInertia I = g.moment_of_inertia(45_deg);
      Assert::AreEqual(0.5_m4, I.Ixx);
      Assert::AreEqual(7.5_m4, I.Iyy);
      Assert::AreEqual(1.4_m4, I.Ixy);
    }
  };
  TEST_CLASS(TestCircle) {
    eng::Circle c1{1_m};
    eng::Circle c2{2.5_m};
  public:
    TEST_METHOD(TestArea1) {
      Assert::AreEqual(0.78539816_m2, c1.area());
    }
    TEST_METHOD(TestMomentOfInertia1) {
      Assert::AreEqual(0.04908739_m4, c1.moment_of_inertia().Ixx);
      Assert::AreEqual(0.04908739_m4, c1.moment_of_inertia().Iyy);
      Assert::AreEqual(0_m4, c1.moment_of_inertia().Ixy);
    }
    TEST_METHOD(TestArea2) {
      Assert::AreEqual(4.9087385_m2, c2.area());
    }
    TEST_METHOD(TestMomentOfInertia2) {
      Assert::AreEqual(1.917476_m4, c2.moment_of_inertia().Ixx);
      Assert::AreEqual(1.917476_m4, c2.moment_of_inertia().Iyy);
      Assert::AreEqual(0_m4, c2.moment_of_inertia().Ixy);
    }
  };
  TEST_CLASS(TestSemiCircle) {
    eng::SemiCircle sc{2.5_m};
  public:
    TEST_METHOD(TestArea) {
      Assert::AreEqual(2.4543693_m2, sc.area());
    }
    TEST_METHOD(TestMomentOfInertia) {
      Assert::AreEqual(0.26796133_m4, sc.moment_of_inertia().Ixx);
      Assert::AreEqual(0.95873799_m4, sc.moment_of_inertia().Iyy);
      Assert::AreEqual(0_m4, sc.moment_of_inertia().Ixy);
    }
  };

  TEST_CLASS(TestHollowCircle) {
    eng::HollowCircle hc{2.5_m, 1.75_m};
  public:
    TEST_METHOD(TestArea) {
      Assert::AreEqual(2.5034566_m2, hc.area());
    }
    TEST_METHOD(TestMomentOfInertia) {
      Assert::AreEqual(1.45709_m4, hc.moment_of_inertia().Ixx);
      Assert::AreEqual(1.45709_m4, hc.moment_of_inertia().Iyy);
      Assert::AreEqual(0_m4, hc.moment_of_inertia().Ixy);
    }
  };

  TEST_CLASS(TestRectangle) {
    eng::Rectangle r{2_m, 6.7_m};
  public:
    TEST_METHOD(TestArea) {
      Assert::AreEqual(13.4_m2, r.area());
    }
    TEST_METHOD(TestMomentOfInertia) {
      Assert::AreEqual(50.127167_m4, r.moment_of_inertia().Ixx);
      Assert::AreEqual(4.4666667_m4, r.moment_of_inertia().Iyy);
      Assert::AreEqual(0_m4, r.moment_of_inertia().Ixy);
    }
  };

  TEST_CLASS(TestHollowRectangle) {
    eng::HollowRectangle hr{5_m, 3_m, 1.0_m, 1.5_m};
  public:
    TEST_METHOD(TestArea) {
      Assert::AreEqual(13.5_m2, hr.area());
    }
    TEST_METHOD(TestMomentOfInertia) {
      Assert::AreEqual(10.96875_m4, hr.moment_of_inertia().Ixx);
      Assert::AreEqual(31.125_m4, hr.moment_of_inertia().Iyy);
      Assert::AreEqual(0_m4, hr.moment_of_inertia().Ixy);
    }
  };
};
