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

template<typename Res, typename Arg>
std::ostream& operator<< (std::ostream& os, const eng::OptimizationResults<Res, Arg>& opt_res);

int main() {
  /*****************************************************************************
   * Unconstrained Tests
   */

  // Quadratic
  {
    eng::UnitlessVec<2> start({1, 1});

    auto res = eng::steepest_descent<double, 
      eng::UnitlessVec<2>, 
      eng::UnitlessVec<2>>(quadratic, start, gradient_quadratic);

    std::cout << res << '\n';

  }

  // Rosenbrock

  return 0;
}


std::string to_string(const eng::UnitlessVec<2> a) {
  return "[" + std::to_string(a.x()) + ", " + std::to_string(a.y()) + "]";
}


/** OptimizationResults output operator */
template<typename Res, typename Arg>
std::ostream& operator<< (std::ostream& os, const eng::OptimizationResults<Res, Arg>& opt_res) {
  using namespace std;
  os << "x = " << to_string(opt_res.x) << '\n'
    << "f(x) = " << to_string(opt_res.f) << '\n'
    << "numevals: " << opt_res.numevals << '\n'
    << "numiters: " << opt_res.numiters << '\n'
    << "status: " << (opt_res.success ? "SUCCESS" : "FAILURE") << '\n'
    << "message: " << opt_res.message;

  return os;
}
