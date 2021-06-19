#pragma once

/*****************************************************************//**
 * \file   TestFunctions.h
 * \brief  Test functions with known minima to test the optimization module
 *           of EngineeringLibrary.
 *
 *
 * \author bltan
 * \date   May 2021
 *********************************************************************/

#include "EngineeringLibrary\Units\Unitless.h"

/* A slanted quadratic function */
double quadratic(eng::UnitlessVec<2> x) {
  static const double beta = 1.5;
  return x[0]*x[0] + x[1]*x[1] - beta*x[0]*x[1];
}

eng::UnitlessVec<2> gradient_quadratic(eng::UnitlessVec<2> x) {
  static const double beta = 1.5;
  return eng::UnitlessVec<2>({2.0*x[0] - beta*x[1],
                              2.0*x[1] - beta*x[0]});
}

/* The Rosenbrock function */
double rosenbrock(eng::UnitlessVec<2> x) {
  return (1 - x[0])*(1 - x[0]) + 100*(x[1] - x[0]*x[0])*(x[1] - x[0]*x[0]);
}

eng::UnitlessVec<2> gradient_rosenbrock(eng::UnitlessVec<2> x) {
  return eng::UnitlessVec<2>({2*(1-x[0]) + 200*(x[1] - x[0]*x[0])*2*x[0],
                             200*(x[1] - x[0]*x[0])});
}
