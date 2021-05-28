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

  template <size_t N>
  OptimizationResults<N> steepest_descent(std::function<double(UnitlessVec<N>)> function, 
                                          UnitlessVec<N> start,
                                          std::function<UnitlessVec<N>(UnitlessVec<N>)> gradient_function) {
    OptimizationResults<N> results;

    auto func = [&results, function](UnitlessVec<N> x) {
      ++results.numevals;
      return function(x);
    };
    auto grad_func = [&results, gradient_function](UnitlessVec<N> x) {
      ++results.numevals;
      return gradient_function(x);
    };

    // Determine the starting values
    results.x = start;
    const double tau = 1.0e-6;
    UnitlessVec<N> del_f;
        
    do {
      ++results.numiters;
      // Calculate the gradient at the current location
      del_f = grad_func(results.x);

      // Take a step
      UnitlessVec<N> p = -normalize(del_f);
      double alpha = norm(del_f);
      results.x = results.x + (p*alpha);

      // Determine if x is a minimum
    } while (norm_inf(del_f) > tau);

    if (norm_inf(del_f) <= tau) {
      results.success = true;
      results.message = "optimization completed successfully";
    }
    
    results.f = func(results.x);
    return results;
  }

}; // namespace eng
