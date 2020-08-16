#ifndef Physics_Base_h_INCLUDED
#define Physics_Base_h_INCLUDED

namespace physics {

  /**
   * \class PhysicsBase An internal base class for any physics object
   */
  class PhysicsBase {
  public:
    explicit PhysicsBase(const double n) : _value(n) { }
    virtual ~PhysicsBase() = default;

    double value() const { return _value; }

  protected:
    double _value;
  };

};  // namespace physics

#endif
