#include "pch.h"
#include "Buckling.h"

#include <cmath>

#include "GeometricProperty.h"

#include "Units/MomentOfArea.h"
#include "Units/Force.h"

namespace eng {

  Column::Column(const Material& material, const Geometry& geometry,
    const Length& length, const EndConditions& supports) :
    _material(material),
    _geometry(geometry),
    _length(length),
    _supports(supports) { }

  Stress critical_load(const Column& _column) {
    Geometry::AreaMomentofInertia temp = _column.moment_of_inertia();
    SecondMomentOfArea I = temp.Ixx < temp.Iyy ? temp.Ixx : temp.Iyy;
    Length k = radius_of_gyration(I, _column.area());

    if ((_column.length()*_column.length())/(k*k) < l_k_1(_column)) {
      // Johnson buckling
      return critical_load_johnson(_column);
    } else {
      // Euler Buckling
      return critical_load_euler(_column);
    }
  }

  Stress critical_load_euler(const Column& _column) {
    // Determine the weak direction radius of gyration
    Geometry::AreaMomentofInertia temp = _column.moment_of_inertia();
    SecondMomentOfArea I = temp.Ixx < temp.Iyy ? temp.Ixx : temp.Iyy;
    Length k = radius_of_gyration(I, _column.area());
    
    // calculate the critical load
    return (end_condition_constant(_column.supports()) * pi*pi * _column.material().E()) 
      /((_column.length() * _column.length())/(k*k));
  }

  Stress critical_load_johnson(const Column& _column) {
    // Determine the weak direction radius of gyration
    Geometry::AreaMomentofInertia temp = _column.moment_of_inertia();
    SecondMomentOfArea I = temp.Ixx < temp.Iyy ? temp.Ixx : temp.Iyy;
    Length k = radius_of_gyration(I, _column.area());

    // calculate the critical load
    return _column.material().yield_strength()
      - _column.material().yield_strength()*(_column.material().yield_strength()/
                                             (4*end_condition_constant(_column.supports())
                                              *_column.material().E()*pi*pi))
      * (_column.length()*_column.length())/(k*k);
  }

  double l_k_1(const Column& _column) {
    return std::sqrt((2*end_condition_constant(_column.supports())*pi*pi*_column.material().E())
      /_column.material().yield_strength());
  }

  double end_condition_constant(const EndConditions& _supports, const int& v) {
    if (_supports == EndConditions::FIXED_FREE) {
      return 0.25;
    } else if (_supports == EndConditions::PIN_PIN) {
      return 1.0;
    } else if (v == COL_CONSERVATIVE_VALUE) {
      return 1.0;
    } else if (v == COL_RECOMMENDED_VALUE) {
      return 1.2;
    } else if (_supports == EndConditions::FIXED_PIN) {
      return 2.0;
    } else if (_supports == EndConditions::FIXED_FIXED) {
      return 4.0;
    } else {
      // Returns -1 on an invalid input
      return -1;
    }
  }

};  // namespace eng
