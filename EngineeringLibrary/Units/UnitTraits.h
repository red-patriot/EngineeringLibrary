#pragma once

/*****************************************************************//**
 * \file   UnitTraits.h
 * \brief  Functionality to handle compile time dimensional analysis
 *
 * \author bltan
 * \date   May 2021
 *********************************************************************/

#include <numeric>

namespace eng {

  //////////////////////////////////////////////////////////////////////////////
  // Metafunctions to extract information about individual dimensions of units

  namespace dimension_mgmt {
    /** Return the nth template argument of a given template. */
    template<template<int...> typename U, int... Args>
    static constexpr int nth_arg(const U<Args...>& u, size_t n) {
      return [n]() {int r[sizeof...(Args)] = {Args...}; return r[n];}();
    }

    static constexpr int sign(const int& n) noexcept {
      return (0 < n) - (n < 0);
    }

    static constexpr int abs(const int& n) noexcept {
      return n * sign(n);
    }

    auto add_ = [](const int a, const int b) constexpr { return a + b; };
    auto sub_ = [](const int a, const int b) constexpr { return a - b; };

    /** Numerator result of fraction operation a/b # c/d where # is defined by f. */
    static constexpr int num(const int a, const int b, const int c, const int d,
                             int(*f)(const int, const int)) {
      int n_ = f(a*d, b*c);
      int d_ = b * d;
      return sign(n_) * sign(d_) * abs(n_)/std::gcd(n_, d_);
    }

    /** Denominator result of fraction operation a/b # c/d where # is defined by f. */
    static constexpr int den(const int a, const int b, const int c, const int d,
                             int(*f)(const int, const int)) {
      int n_ = f(a*d, b*c);
      int d_ = b * d;
      return abs(d_)/std::gcd(n_, d_);
    }

  };  // namespace dimension_mgmt
}; // namespace eng
