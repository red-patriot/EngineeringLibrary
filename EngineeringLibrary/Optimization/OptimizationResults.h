#pragma once

/*****************************************************************//**
 * \file   OptimizationResults.h
 * \brief  Define a struct to store status of an optimization
 *
 * \author bltan
 * \date   May 2021
 *********************************************************************/

#include <ostream>
#include <string>

#include "../Units/Unitless.h"

namespace eng {

  /**
   * Report the status of an optimization upon completion
   */
  template<size_t N>
  struct OptimizationResults {
    UnitlessVec<N> x;  /**< The location of the optimum. */
    double f;  /**< The function value at x, the minimum value of the function. */
    size_t numevals;  /**< The number of function evaluations performed 
                          * during the optimization. */
    size_t numiters;  /**< The number of iterations to optimize the function. */
    bool success;  /**< Indicate success of the optimization, true if the
                       * optimization met its success criterion, 
                       * false otherwise. */
    std::string message;  /**< A message indicating the status of the 
                               * optimization. */

    OptimizationResults() :
      x(),
      f(),
      numevals(0),
      numiters(0),
      success(false),
      message("") { }
  };

}; // namespace eng
