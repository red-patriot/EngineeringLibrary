#pragma once

/*****************************************************************//**
 * \file   Unconstrained.h
 * \brief  Functions for unconstrained optimization.
 * 
 *
 * \author bltan
 * \date   May 2021
 *********************************************************************/

#include <type_traits>
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

  template <typename Ret, typename Arg, typename Grad>
  OptimizationResults<Ret, Arg> steepest_descent(std::function<Ret(Arg)> function, 
                                                 Arg start,
                                                 std::function<Grad(Arg)> grad_func) {
    OptimizationResults<Ret, Arg> results;

    auto func = [&results, function](Arg x) {
      ++results.numevals;
      return function(x);
    };

    // Determine the starting values of the function
    results.x = start;
    results.f = func(start);
    auto del_f = grad_func(results.x);
        
    do {
      // Determine the search direction
      auto p = -normalize(del_f);

      // Determine the step size
      auto alpha = norm(del_f);

      // Take the step
      results.x = results.x + p*alpha;
      results.f = func(results.x);

      // Determine if x is a minimum
    } while (norm_inf(del_f).value() > 10.0e-6);
    
    return results;
  }

}; // namespace eng
