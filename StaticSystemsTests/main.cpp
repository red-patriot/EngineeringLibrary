/*****************************************************************//**
 * \file   main.cpp
 * \brief  
 * 
 * 
 * \author bltan
 * \date   December 2020
 *********************************************************************/

#include <iostream>
#include <vector>
#include <cmath>

#include "EngineeringLibrary\Engineering.h"
#include "EngineeringLibrary\StaticSystems\AppliedLoad.h"
#include "EngineeringLibrary\StaticSystems\StaticSystem.h"

int main() {
  // Test a 2D system
  eng::StaticSystem sys2D;

  sys2D.add_known_load({eng::ForceVec<3>({0_lbf, -50_N, 0_lbf}),
                       eng::LengthVec<3>({0_m, 0_m, 0_m})});
  sys2D.add_unknown_load({eng::UnitlessVec<3>({eng::cos(15_deg), eng::sin(15_deg), 0.0}),
                       eng::LengthVec<3>({0_m, 0_m, 0_m})});
  sys2D.add_unknown_load({eng::UnitlessVec<3>({-eng::sin(15_deg), eng::cos(15_deg), 0.0}),
                         eng::LengthVec<3>({0_m, 0_m, 0_m})});

  sys2D.solve();
  std::vector<eng::AppliedLoad> result2D = sys2D.get_solved_loads();

  std::cout << "2D System:" << '\n';
  for (const auto& load : result2D) {
    eng::ForceVec<3> f = *load.get_force_vector();
    std::cout << '[' << f.x().N() << ", "
      << f.y().N() << ", "
      << f.z().N() << "] : "
      << load.get_magnitude()->N() << '\n';
  }
  
  std::cout << '\n' << '\n';
  
  
  // Test a 3D system (5.105)
  eng::StaticSystem sys3D;

  sys3D.add_known_load({eng::ForceVec<3>({0_N, 0_N, -100_N}), 
                       eng::LengthVec<3>({4_m, 4_m, 0_m})});  // C

  sys3D.add_unknown_load({eng::LengthVec<3>({0_m, 0_m, 0_m})});  // A
  sys3D.add_unknown_load({eng::i_hat, 
                         eng::LengthVec<3>({4_m, 8_m, 2_m})});   // Ex
  sys3D.add_unknown_load({eng::k_hat,
                         eng::LengthVec<3>({4_m, 8_m, 2_m})});   // Ez
  sys3D.add_unknown_load({eng::UnitlessVec<3>({-std::sqrt(2)/2, 0, std::sqrt(2)/2}), 
                         eng::LengthVec<3>({4_m, 0_m, 0_m})});   // T

  std::vector<eng::AppliedLoad> result3D = sys3D.get_solved_loads();

  std::cout << "3D System:" << '\n';
  for (const auto& load : result3D) {
    eng::ForceVec<3> f = *load.get_force_vector();
    std::cout << '[' << f.x().N() << ", "
      << f.y().N() << ", "
      << f.z().N() << "] : "
      << load.get_magnitude()->N() << '\n';
  }

  std::cout << '\n' << '\n';
  
  
  // Test a 3D system with applied Moments (5.104)
  eng::StaticSystem sys3D_M;

  sys3D_M.add_known_load({eng::ForceVec<3>({0_lbf, 0_lbf, -10_lbf}),
                         eng::LengthVec<3>({0_in, 4_in, 8_in})});  // B
  sys3D_M.add_known_load({eng::ForceVec<3>({0_lbf, 0_lbf, -20_lbf}),
                         eng::LengthVec<3>({12_in, 0_in, 8_in})});  // D

  sys3D_M.add_unknown_load({0_in, 0_in, 0_in});  // A
  sys3D_M.add_unknown_load({eng::k_hat,
                           eng::LengthVec<3>({12_in, -4_in, 0_in})});  // Fz

  sys3D_M.add_unknown_moment({eng::UnitlessVec<3>(eng::i_hat)});  // MAx
  sys3D_M.add_unknown_moment({eng::UnitlessVec<3>(eng::k_hat)});  // MAz

  std::vector<eng::AppliedLoad> result3D_M_L = sys3D_M.get_solved_loads();
  std::vector<eng::AppliedMoment> result3D_M_M = sys3D_M.get_solved_moments();

  std::cout << "3D System with Moments:" << '\n';
  for (const auto& load : result3D_M_L) {
    eng::ForceVec<3> f = *load.get_force_vector();
    std::cout << '[' << f.x().lbf() << ", "
      << f.y().lbf() << ", "
      << f.z().lbf() << "] : "
      << load.get_magnitude()->lbf() << '\n';
  }

  for (const auto& moment : result3D_M_M) {
    eng::MomentVec<3> f = *moment.get_moment_vector();
    std::cout << '[' << f.x().inlb() << ", "
      << f.y().inlb() << ", "
      << f.z().inlb() << "] : "
      << moment.get_magnitude()->inlb() << '\n';
  }

  return 0;
}
