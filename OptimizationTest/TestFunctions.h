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

#include <array>

/* A slanted quadratic function */
double quadratic(const std::array<double, 2>x ) {
  static const double beta = 1.5;
  return x[0]*x[0] + x[1]*x[1] - beta*x[0]*x[1];
}

/* The Rosenbrock function */
double rosenbrock(const std::array<double, 2> x) {
  return (1 - x[0])*(1 - x[0]) + 100*(x[1] - x[0]*x[0])*(x[1] - x[0]*x[0]);
}
