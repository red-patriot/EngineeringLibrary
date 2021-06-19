/*****************************************************************//**
 * \file   main.cpp
 * \brief  The main file for the Optimization tester project
 * 
 * \author bltan
 * \date   May 2021
 *********************************************************************/

#include <iostream>
#include <array>
#include <string>

#include "EngineeringLibrary\Units\Unitless.h"
#include "EngineeringLibrary\Optimization\Unconstrained.h"

#include "TestFunctions.h"

std::string to_string(const eng::UnitlessVec<2> a);

template<size_t N>
std::ostream& operator<< (std::ostream& os, const eng::OptimizationResults<N>& opt_res);

int main() {
  /*****************************************************************************
   * Unconstrained Tests
   */

  // Quadratic
  {
    eng::UnitlessVec<2> start({1, 1});

    auto res = eng::steepest_descent<2>(quadratic, start, gradient_quadratic);

    std::cout << "QUADRATIC:\n" << res << '\n' << '\n';

  }

  // Rosenbrock
  {
    eng::UnitlessVec<2> start({2.0, -1.5});

    auto res = eng::steepest_descent<2>(rosenbrock, start, gradient_rosenbrock);

    std::cout << "ROSENBROCK:\n" << res << '\n';
  }

  return 0;
}


std::string to_string(const eng::UnitlessVec<2> a) {
  return "[" + std::to_string(a.x()) + ", " + std::to_string(a.y()) + "]";
}


/** OptimizationResults output operator */
template<size_t N>
std::ostream& operator<< (std::ostream& os, const eng::OptimizationResults<N>& opt_res) {
  using namespace std;
  os << "x = " << to_string(opt_res.x) << '\n'
    << "f(x) = " << to_string(opt_res.f) << '\n'
    << "numevals: " << opt_res.numevals << '\n'
    << "numiters: " << opt_res.numiters << '\n'
    << "status: " << (opt_res.success ? "SUCCESS" : "FAILURE") << '\n'
    << "message: " << opt_res.message;

  return os;
}
