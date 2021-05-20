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

std::string to_string(const std::array<double, 2> a);

template<typename Res, typename Arg>
std::ostream& operator<< (std::ostream& os, const eng::OptimizationResults<Res, Arg>& opt_res);

int main() {
  /*****************************************************************************
   * Unconstrained Tests
   */

  // Quadratic
  {
    std::array<double, 2> start = {1, 1};

    auto res = eng::quasi_newton<double, std::array<double, 2>>(quadratic, start);

    std::cout << res << '\n';

  }

  // Rosenbrock

  return 0;
}


std::string to_string(const std::array<double, 2> a) {
  return "[" + std::to_string(a[0]) + ", " + std::to_string(a[1]) + "]";
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
