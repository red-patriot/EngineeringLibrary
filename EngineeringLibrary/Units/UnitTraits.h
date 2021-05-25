#pragma once

/*****************************************************************//**
 * \file   UnitTraits.h
 * \brief  Functionality to handle compile time unit management
 *
 * \author bltan
 * \date   May 2021
 *********************************************************************/

namespace eng {

  //////////////////////////////////////////////////////////////////////////////
  // Metafunctions to extract information about individual dimensions of units

  template<typename U, size_t...>
  struct UnitDimension { };

  template<template<size_t...> typename U, size_t N, size_t... Args>
  struct UnitDimension<U<Args...>, N> {
    const size_t numerator = Args[0 + N];
    const size_t denominator = Args[7 + N];
  };

  template<template<size_t...> typename U, size_t... Args>
  using MassDimension = UnitDimension<U<Args...>, 0, Args...>;

}; // namespace eng
