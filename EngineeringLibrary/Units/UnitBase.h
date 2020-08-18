#ifndef Physics_Base_h_INCLUDED
#define Physics_Base_h_INCLUDED

/*****************************************************************//**
 * \file  UnitBase.h
 * \brief A base class for all units to give them a uniform interface and
 *          to simplify the implementation where possible. This class is not 
 *          available outside this library
 *
 * \author bltan
 * \date   August 2020
 *********************************************************************/

#include "../EngineeringExport.h"

namespace eng {

  /**
   * \class UnitBase An internal base class for any unit type
   */
  class UnitBase {
  public:
    explicit UnitBase(const double n) : _value(n) { }
    virtual ~UnitBase() = default;

    double value() const { return _value; }

  protected:
    double _value;
  };

};  // namespace eng

#endif
