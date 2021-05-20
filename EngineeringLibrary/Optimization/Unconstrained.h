#pragma once

/*****************************************************************//**
 * \file   Unconstrained.h
 * \brief  Functions for unconstrained optimization.
 * 
 *
 * \author bltan
 * \date   May 2021
 *********************************************************************/

#include <functional>

#include "OptimizationResults.h"

namespace eng {

  /**
   * Optimize the given function using a quasi-Newton method.
   * 
   * \param function the function to minimize
   * \param start the starting point to begin the optimization
   * \return the optimal value of the function
   */
  template <typename Ret, typename Arg>
  OptimizationResults<Ret, Arg> quasi_newton(std::function<Ret(Arg)> function, Arg start, 
                                             Ret tau = Ret(1e-6)) {
    OptimizationResults<Ret, Arg> results;

    do {
      // Determine the search direction

      // Determine the step size

      // Take the step

      // Determine if x is a minimum
    } while (false);
    
    return results;
  }

}; // namespace eng
