#include "pch.h"
#include "CppUnitTest.h"

#include <vector>
#include <iostream>
#include <algorithm>

#include "UnitHelperFunctions.h"
#include "VectorHelperFunctions.h"

#include "EngineeringLibrary/Engineering.h"
#include "EngineeringLibrary/StaticSystems/AppliedLoad.h"
#include "EngineeringLibrary/StaticSystems/StaticSystem.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StaticSystemsTests {
  TEST_CLASS(TestsAppliedLoadKnown) {
    eng::AppliedLoad a{{2_N, 10_N, 25_N}, {4_m, 13_m, 16_m}};
    eng::AppliedLoad b{1_N, 2_N, 2_N, {4_m, 4_m, 7_m}};

   public:
    TEST_METHOD(TestDirection1) {
      Assert::AreEqual(eng::UnitlessVec{2.0 / 27.0, 10.0 / 27.0, 25.0 / 27.0}, *a.get_direction());
    }
    TEST_METHOD(TestDirection2) {
      Assert::AreEqual(eng::UnitlessVec{1.0 / 3.0, 2.0 / 3.0, 2.0 / 3.0}, *b.get_direction());
    }
    TEST_METHOD(TestMagnitude) {
      Assert::AreEqual(27_N, *a.get_magnitude());
    }
    TEST_METHOD(TestForceVec) {
      Assert::AreEqual({1_N, 2_N, 2_N}, *b.get_force_vector());
    }
    TEST_METHOD(TestPosition) {
      Assert::AreEqual({4_m, 4_m, 7_m}, b.get_position());
    }
  };

  TEST_CLASS(TestsAppliedLoadUnknown) {
    eng::AppliedLoad a{{2_m, 10_m, 11_m}};  // Completely unknown
    eng::AppliedLoad b{2_m, 10_m, 11_m};    // Completely unknown
    eng::AppliedLoad c{eng::UnitlessVec(eng::i_hat),
                       {1_m, 2_m, 2_m}};  // Magnitude unknown
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
      Assert::AreEqual({2_m, 10_m, 11_m}, a.get_position());
    }
    TEST_METHOD(TestPosition2) {
      Assert::AreEqual({2_m, 10_m, 11_m}, b.get_position());
    }
    TEST_METHOD(TestPosition3) {
      Assert::AreEqual({1_m, 2_m, 2_m}, c.get_position());
    }
  };

  TEST_CLASS(SolveSystems){
    public:
    TEST_METHOD(System2D) {
      eng::StaticSystem sys2D;
      sys2D.add_known_load({{0_lbf, -50_N, 0_lbf},
                            {0_m, 0_m, 0_m}});
      sys2D.add_unknown_load({eng::UnitlessVec(eng::cos(15_deg), eng::sin(15_deg), 0),
                          {0_m, 0_m, 0_m}});
      sys2D.add_unknown_load({eng::UnitlessVec(-eng::sin(15_deg), eng::cos(15_deg), 0),
                          {0_m, 0_m, 0_m}});

      sys2D.solve();

      std::vector<eng::AppliedLoad> result2D = sys2D.get_solved_loads();

      Assert::AreEqual(eng::ForceVec{12.5_N, 3.349364905_N, 0.0_N}, 
                       result2D[0].get_force_vector().value());
      Assert::AreEqual(eng::ForceVec{-12.5_N, 46.65063509_N, 0.0_N},
                       result2D[1].get_force_vector().value());
    } 

    TEST_METHOD(System3D) {
      eng::StaticSystem sys3D;

      sys3D.add_known_load({{0_N, 0_N, -100_N}, {4_m, 4_m, 0_m}});  // C

      sys3D.add_unknown_load({{0_m, 0_m, 0_m}});  // A
      sys3D.add_unknown_load({eng::UnitlessVec(eng::i_hat),
                              {4_m, 8_m, 2_m}});  // Ex
      sys3D.add_unknown_load({eng::UnitlessVec(eng::k_hat),
                              {4_m, 8_m, 2_m}});  // Ez
      sys3D.add_unknown_load({eng::UnitlessVec{-std::sqrt(2) / 2, 0, std::sqrt(2) / 2},
                              {4_m, 0_m, 0_m}});  // T

      std::vector<eng::AppliedLoad> result3D = sys3D.get_solved_loads();

      Assert::AreEqual(eng::ForceVec{50.0_N, 0.0_N, 0.0_N},
                       result3D[0].get_force_vector().value());
      Assert::AreEqual(eng::ForceVec{0_N, 0_N, 0_N},
                       result3D[1].get_force_vector().value());
      Assert::AreEqual(eng::ForceVec{0_N, 0_N, 50_N},
                       result3D[2].get_force_vector().value());
      Assert ::AreEqual(eng::ForceVec{-50_N, 0_N, 50_N},
                        result3D[3].get_force_vector().value());
    }

    TEST_METHOD(System3DWithMoments) {
      eng::StaticSystem sys3D_M;

      sys3D_M.add_known_load({{0_lbf, 0_lbf, -10_lbf},
                              {0_in, 4_in, 8_in}});  // B
      sys3D_M.add_known_load({{0_lbf, 0_lbf, -20_lbf},
                              {12_in, 0_in, 8_in}});  // D

      sys3D_M.add_unknown_load({0_in, 0_in, 0_in});  // A
      sys3D_M.add_unknown_load({eng::UnitlessVec(eng::k_hat),
                                {12_in, -4_in, 0_in}});  // Fz

      sys3D_M.add_unknown_moment({eng::UnitlessVec(eng::i_hat)});  // MAx
      sys3D_M.add_unknown_moment({eng::UnitlessVec(eng::k_hat)});  // MAz

      std::vector<eng::AppliedLoad> result3D_M_L = sys3D_M.get_solved_loads();
      std::vector<eng::AppliedMoment> result3D_M_M = sys3D_M.get_solved_moments();

      Assert::AreEqual(eng::ForceVec{0_lbf, 0_lbf, 10_lbf},
                       result3D_M_L[0].get_force_vector().value());
      Assert::AreEqual(eng::ForceVec{0_lbf, 0_lbf, 20_lbf},
                       result3D_M_L[1].get_force_vector().value());

      Assert::AreEqual(eng::MomentVec{120_inlb, 0_inlb, 0_inlb},
                       result3D_M_M[0].get_moment_vector().value());
      Assert::AreEqual(eng::MomentVec{0_inlb, 0_inlb, 0_inlb},
                       result3D_M_M[1].get_moment_vector().value());
    }
  };
};  // namespace StaticSystemsTests
