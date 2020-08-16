#ifndef Physics_Base_h_INCLUDED
#define Physics_Base_h_INCLUDED

namespace physics {

  /**
   * \class UnitBase An internal base class for any physics object
   */
  class UnitBase {
  public:
    explicit UnitBase(const double n) : _value(n) { }
    virtual ~UnitBase() = default;

    double value() const { return _value; }

  protected:
    double _value;
  };

};  // namespace physics

#endif
