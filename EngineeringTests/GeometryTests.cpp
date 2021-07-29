#include "pch.h"
#include "CppUnitTest.h"

#include "UnitHelperFunctions.h"
#include "VectorHelperFunctions.h"
#include "EngineeringLibrary/Engineering.h"

#include <vector>

#include"EngineeringLibrary/Geometric/Geometric.h"
#include "EngineeringLibrary/Units/Length.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GeometryTests {
  TEST_CLASS(TestGeometry) {
    eng::Geometry g{2_m2, 5.4_m4, 2.6_m4, 3.5_m4, {0_m, 0_m, 3.5_m}};
  public:
    TEST_METHOD(TestArea) {
      Assert::AreEqual(2_m2, g.area());
    }
    TEST_METHOD(TestCentroid) {
      Assert::AreEqual({0_m, 0_m, 3.5_m}, g.centroid());
    }
    TEST_METHOD(TestMomentOfArea) {
      Assert::AreEqual(5.4_m4, g.Ixx());
      Assert::AreEqual(2.6_m4, g.Iyy());
      Assert::AreEqual(3.5_m4, g.Ixy());
    }
    TEST_METHOD(TestParallelAxes) {
      Assert::AreEqual(13.4_m4, g.Ixx(2_m));
      Assert::AreEqual(4.6_m4, g.Iyy(1_m));
      Assert::AreEqual(7.5_m4, g.Ixy(1_m, 2_m));
    }
    TEST_METHOD(TestRotatedAxes) {
      eng::Angle theta = 45_deg;
      Assert::AreEqual(0.5_m4, g.Ixx(theta));
      Assert::AreEqual(7.5_m4, g.Iyy(theta));
      Assert::AreEqual(1.4_m4, g.Ixy(theta));
    }
    TEST_METHOD(TestCopy) {
      eng::Geometry copied = g;
      Assert::AreEqual(g.area(), copied.area());
      Assert::AreEqual(g.centroid(), copied.centroid());
      Assert::AreEqual(g.Ixx(), copied.Ixx());
      Assert::AreEqual(g.Iyy(), copied.Iyy());
      Assert::AreEqual(g.Ixy(), copied.Ixy());
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
      Assert::AreEqual(0.04908739_m4, c1.Ixx());
      Assert::AreEqual(0.04908739_m4, c1.Iyy());
      Assert::AreEqual(0_m4, c1.Ixy());
    }
    TEST_METHOD(TestArea2) {
      Assert::AreEqual(4.9087385_m2, c2.area());
    }
    TEST_METHOD(TestMomentOfInertia2) {
      Assert::AreEqual(1.917476_m4, c2.Ixx());
      Assert::AreEqual(1.917476_m4, c2.Iyy());
      Assert::AreEqual(0_m4, c2.Ixy());
    }
    TEST_METHOD(TestCopy) {
      eng::Geometry copied = c2;
      Assert::AreEqual(c2.area(), copied.area());
      Assert::AreEqual(c2.centroid(), copied.centroid());
      Assert::AreEqual(c2.Ixx(), copied.Ixx());
      Assert::AreEqual(c2.Iyy(), copied.Iyy());
      Assert::AreEqual(c2.Ixy(), copied.Ixy());
    }
  };
  
  TEST_CLASS(TestSemiCircle) {
    eng::SemiCircle sc{2.5_m};
  public:
    TEST_METHOD(TestArea) {
      Assert::AreEqual(2.4543693_m2, sc.area());
    }
    TEST_METHOD(TestMomentOfInertia) {
      Assert::AreEqual(0.26796133_m4, sc.Ixx());
      Assert::AreEqual(0.95873799_m4, sc.Iyy());
      Assert::AreEqual(0_m4, sc.Ixy());
    }
    TEST_METHOD(TestCopy) {
      eng::Geometry copied = sc;
      Assert::AreEqual(sc.area(), copied.area());
      Assert::AreEqual(sc.centroid(), copied.centroid());
      Assert::AreEqual(sc.Ixx(), copied.Ixx());
      Assert::AreEqual(sc.Iyy(), copied.Iyy());
      Assert::AreEqual(sc.Ixy(), copied.Ixy());
    }
  };
  
  TEST_CLASS(TestHollowCircle) {
    eng::HollowCircle hc{2.5_m, 1.75_m};
  public:
    TEST_METHOD(TestArea) {
      Assert::AreEqual(2.5034566_m2, hc.area());
    }
    TEST_METHOD(TestMomentOfInertia) {
      Assert::AreEqual(1.45709_m4, hc.Ixx());
      Assert::AreEqual(1.45709_m4, hc.Iyy());
      Assert::AreEqual(0_m4, hc.Ixy());
    }
    TEST_METHOD(TestCopy) {
      eng::Geometry copied = hc;
      Assert::AreEqual(hc.area(), copied.area());
      Assert::AreEqual(hc.centroid(), copied.centroid());
      Assert::AreEqual(hc.Ixx(), copied.Ixx());
      Assert::AreEqual(hc.Iyy(), copied.Iyy());
      Assert::AreEqual(hc.Ixy(), copied.Ixy());
    }
  };

  TEST_CLASS(TestRectangle) {
    eng::Rectangle r{2_m, 6.7_m};
  public:
    TEST_METHOD(TestArea) {
      Assert::AreEqual(13.4_m2, r.area());
    }
    TEST_METHOD(TestMomentOfInertia) {
      Assert::AreEqual(50.127167_m4, r.Ixx());
      Assert::AreEqual(4.4666667_m4, r.Iyy());
      Assert::AreEqual(0_m4, r.Ixy());
    }
    TEST_METHOD(TestCopy) {
      eng::Geometry copied = r;
      Assert::AreEqual(r.area(), copied.area());
      Assert::AreEqual(r.centroid(), copied.centroid());
      Assert::AreEqual(r.Ixx(), copied.Ixx());
      Assert::AreEqual(r.Iyy(), copied.Iyy());
      Assert::AreEqual(r.Ixy(), copied.Ixy());
    }
  };

  TEST_CLASS(TestHollowRectangle) {
    eng::HollowRectangle hr{5_m, 3_m, 1.0_m, 1.5_m};
  public:
    TEST_METHOD(TestArea) {
      Assert::AreEqual(13.5_m2, hr.area());
    }
    TEST_METHOD(TestMomentOfInertia) {
      Assert::AreEqual(10.96875_m4, hr.Ixx());
      Assert::AreEqual(31.125_m4, hr.Iyy());
      Assert::AreEqual(0_m4, hr.Ixy());
    }
    TEST_METHOD(TestCopy) {
      eng::Geometry copied = hr;
      Assert::AreEqual(hr.area(), copied.area());
      Assert::AreEqual(hr.centroid(), copied.centroid());
      Assert::AreEqual(hr.Ixx(), copied.Ixx());
      Assert::AreEqual(hr.Iyy(), copied.Iyy());
      Assert::AreEqual(hr.Ixy(), copied.Ixy());
    }
  };

  TEST_CLASS(TestCompositeShapes) {
  public:
    TEST_METHOD(ZBeam) {
      eng::Rectangle top(80_mm, 20_mm, {-50_mm, 70_mm, 0_mm});
      eng::Rectangle cross(20_mm, 160_mm, {0_mm, 0_mm, 0_mm});
      eng::Rectangle bottom(80_mm, 20_mm, {50_mm, -70_mm, 0_mm});

      eng::Geometry z_beam = top + cross + bottom;

      Assert::AreEqual(22.61333e6_mm4, z_beam.Ixx());
      Assert::AreEqual(9.813333e6_mm4, z_beam.Iyy());
      //Assert::AreEqual(0_mm4, z_beam.Ixy());
    }
    TEST_METHOD(BearingBlock) {
      eng::Rectangle base(12_in, 4_in, {0_in, 2_in, 0_in});
      eng::SemiCircle ring(8_in, {0_in, 5.6976527_in, 0_in});
      eng::Circle hole(4_in, {0_in, 4_in, 0_in});

      eng::Geometry bearing_block = base + ring - hole;

      Assert::AreEqual(886.35986_in4, bearing_block.Ixx(0_in));
    }
  };
};  // namespace GeometryTests
