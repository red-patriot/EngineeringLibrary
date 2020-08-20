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

  /** An internal base class for any unit type
   * \class UnitBase
   */
  class UnitBase {
  public:
    /**
     * \brief UnitBase constructor
     * 
     * \param n The stored value 
     */
    explicit UnitBase(const double n) : _value(n) { }
    /**
     * \brief UnitBase virtual destructor
     */
    virtual ~UnitBase() = default;

    /** An internal function which allows for uniformity across all Unit classes
     * \return the stored value
     */
    double value() const { return _value; }

  protected:
    double _value; /**<The internal value which represents a value with units */
  };

};  // namespace eng

#endif
