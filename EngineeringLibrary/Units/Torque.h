#ifndef Torque_h_INCLUDED
#define Torque_h_INCLUDED

/*****************************************************************//**
 * \file   Torque.h
 * \brief  Objects representing Torques and Moments of Force
 *
 *
 * \author bltan
 * \date   September 2020
 *********************************************************************/

#include "UnitBase.h"
#include "Energy.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /** A representation of a Torque or Moment of Force
   * \class Torque
   * \addtogroup Units
   */
  using Torque = UnitBase<1, 2, -2, 0, 0, 0, 0>;

  Torque operator"" _Nm (long double val);
  Torque operator"" _Nm (unsigned long long val);

  Torque operator"" _kNm (long double val);
  Torque operator"" _kNm (unsigned long long val);

  Torque operator"" _Nmm (long double val);
  Torque operator"" _Nmm (unsigned long long val);

  Torque operator"" _lbft (long double val);
  Torque operator"" _lbft (unsigned long long val);

  Torque operator"" _lbin (long double val);
  Torque operator"" _lbin (unsigned long long val);

  // Some conventions use "Moment" istead of "Torque"
  using Moment = Torque;

  // Torques are commonly used as vectors, so provide some vectors for convenience
  using Torque2d = Eigen::Matrix<Torque, 1, 2>;
  using Torque3d = Eigen::Matrix<Torque, 1, 3>;

  using Moment2d = Eigen::Matrix<Moment, 1, 2>;
  using Moment3d = Eigen::Matrix<Moment, 1, 3>;

};  // namespace eng

using eng::operator"" _Nm;        using eng::operator"" _kNm;
using eng::operator"" _Nmm;       
using eng::operator"" _lbft;      using eng::operator"" _lbin;

#endif
