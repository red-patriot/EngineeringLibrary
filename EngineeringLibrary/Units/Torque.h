#pragma once

/*****************************************************************//**
 * \file   Torque.h
 * \brief  Objects representing Torques and Moments of Force
 *
 *
 * \author bltan
 * \date   September 2020
 *********************************************************************/

#include "SIUnit.h"
#include "Energy.h"
#include "../Vector.h"

#include <eigen3/Eigen/Core>

namespace eng {

  /**
   * \class Torque
   * \addtogroup Units
   */
  using Torque = SIUnit<1, 2, -2, 0, 0, 0, 0>;

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

  // Torques are commonly used as vectors
  using TorqueVec = Vector<1, 2, -2, 0, 0, 0, 0>;
  using MomentVec = TorqueVec;

};  // namespace eng

using eng::operator"" _Nm;        using eng::operator"" _kNm;
using eng::operator"" _Nmm;       
using eng::operator"" _lbft;      using eng::operator"" _lbin;
