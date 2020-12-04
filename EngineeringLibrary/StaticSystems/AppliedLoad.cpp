#include "pch.h"

#include <cmath>

#include "AppliedLoad.h"

namespace eng {

  AppliedLoad::AppliedLoad(const Force Fx, const Force Fy, const Force Fz, const LengthVec c) :
    _state(State::KNOWN_FORCE),
    _force_or_direction(Fx.N(), Fy.N(), Fz.N()),
    _position(c) {
    if (std::isnan(_force_or_direction.x()) || 
        std::isnan(_force_or_direction.y()) ||
        std::isnan(_force_or_direction.z())) {
      _state = State::UNKNOWN_FORCE;
    }
  }
  AppliedLoad::AppliedLoad(const ForceVec F, const LengthVec c) :
    _state(State::KNOWN_FORCE),
    _force_or_direction(F.x().N(), F.y().N(), F.z().N()),
    _position(c) {
    if (std::isnan(_force_or_direction.x()) || 
        std::isnan(_force_or_direction.y()) || 
        std::isnan(_force_or_direction.z())) {
      _state = State::UNKNOWN_FORCE;
    }
  }

  AppliedLoad::AppliedLoad(const Length x, const Length y, const Length z) :
    _state(State::UNKNOWN_FORCE),
    _force_or_direction(std::nan("unknown"), 
                        std::nan("unknown"), 
                        std::nan("unknown")),
    _position{x, y, z} { }

  AppliedLoad::AppliedLoad(const LengthVec c) :
    _state(State::UNKNOWN_FORCE),
    _force_or_direction(std::nan("unknown"), 
                        std::nan("unknown"), 
                        std::nan("unknown")),
    _position(c) { }

  AppliedLoad::AppliedLoad(const UnitlessVec u, const LengthVec c) :
    _state(State::KNOWN_DIRECTION),
    _force_or_direction(u),
    _position(c) {
    _force_or_direction = normalize(_force_or_direction);
  }
  AppliedLoad::AppliedLoad(const double i_hat, const double j_hat, const double k_hat,
                           const LengthVec c) :
    _state(State::KNOWN_DIRECTION),
    _force_or_direction(i_hat, j_hat, k_hat),
    _position(c) {
    _force_or_direction = normalize(_force_or_direction);;
  }

  std::optional<UnitlessVec> AppliedLoad::get_direction() const {
    switch (_state) {
      case State::KNOWN_FORCE:
        return std::optional<UnitlessVec>(normalize(_force_or_direction));
        break;
      case State::UNKNOWN_FORCE:
        return {};
        break;
      case State::KNOWN_DIRECTION:
        return std::optional<UnitlessVec>(_force_or_direction);
        break;
    }
  }

  std::optional<Force> AppliedLoad::get_magnitude() const {
    switch (_state) {
      case State::KNOWN_FORCE:
      {
        UnitlessVec ret(_force_or_direction.x(), 
                        _force_or_direction.y(),
                        _force_or_direction.z());
        return Force(ret.norm());
      }
      break;
      case State::UNKNOWN_FORCE:
        [[fallthrough]];
      case State::KNOWN_DIRECTION:
        return {};
        break;
    }
  }
  std::optional<ForceVec> AppliedLoad::get_force_vector() const {
    switch (_state) {
      case State::KNOWN_FORCE:
        return ForceVec(_force_or_direction);
        break;
      case State::UNKNOWN_FORCE:
        [[fallthrough]];
      case State::KNOWN_DIRECTION:
        return {};
        break;
    }
  }
  void AppliedLoad::set_force_vector(const ForceVec & new_force) { 
    // delete the old stored data, if necessary
    _state = State::KNOWN_FORCE;
    _force_or_direction = UnitlessVec(new_force.x().N(), 
                                      new_force.y().N(),
                                      new_force.z().N());
  }
};  // namespace eng
