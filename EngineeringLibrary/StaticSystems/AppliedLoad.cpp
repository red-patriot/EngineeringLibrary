#include "pch.h"

#include <cmath>

#include "AppliedLoad.h"

namespace eng {

  AppliedLoad::AppliedLoad(const Force Fx, const Force Fy, const Force Fz, const LengthVec<3> c) :
    _state(State::KNOWN_FORCE),
    _force_or_direction({Fx.N(), Fy.N(), Fz.N()}),
    _position(c) {
    if (std::isnan(Fx.N()) || 
        std::isnan(Fy.N()) ||
        std::isnan(Fz.N())) {
      _state = State::UNKNOWN_FORCE;
    }
  }
  AppliedLoad::AppliedLoad(const ForceVec<3> F, const LengthVec<3> c) :
    _state(State::KNOWN_FORCE),
    _force_or_direction({F.x().N(), F.y().N(), F.z().N()}),
    _position(c) {
    if (std::isnan(F.x().N()) || 
        std::isnan(F.y().N()) || 
        std::isnan(F.z().N())) {
      _state = State::UNKNOWN_FORCE;
    }
  }

  AppliedLoad::AppliedLoad(const Length x, const Length y, const Length z) :
    _state(State::UNKNOWN_FORCE),
    _force_or_direction({std::nan("unknown"), 
                        std::nan("unknown"), 
                        std::nan("unknown")}),
    _position({x, y, z}) { }

  AppliedLoad::AppliedLoad(const LengthVec<3> c) :
    _state(State::UNKNOWN_FORCE),
    _force_or_direction({std::nan("unknown"), 
                        std::nan("unknown"), 
                        std::nan("unknown")}),
    _position(c) { }

  AppliedLoad::AppliedLoad(const UnitlessVec<3> u, const LengthVec<3> c) :
    _state(State::KNOWN_DIRECTION),
    _force_or_direction(u),
    _position(c) {
    _force_or_direction = normalize(_force_or_direction);
  }
  AppliedLoad::AppliedLoad(const double i_hat, const double j_hat, const double k_hat,
                           const LengthVec<3> c) :
    _state(State::KNOWN_DIRECTION),
    _force_or_direction({i_hat,
                        j_hat,
                        k_hat}),
    _position(c) {
    _force_or_direction = normalize(_force_or_direction);;
  }

  std::optional<UnitlessVec<3>> AppliedLoad::get_direction() const {
    switch (_state) {
      case State::KNOWN_FORCE:
        return std::optional<UnitlessVec<3>>(normalize(_force_or_direction));
        break;
      case State::UNKNOWN_FORCE:
        return {};
        break;
      case State::KNOWN_DIRECTION:
        return std::optional<UnitlessVec<3>>(_force_or_direction);
        break;
    }
  }

  std::optional<Force> AppliedLoad::get_magnitude() const {
    switch (_state) {
      case State::KNOWN_FORCE:
        return Force(_force_or_direction.norm());
        break;
      case State::UNKNOWN_FORCE:
        [[fallthrough]];
      case State::KNOWN_DIRECTION:
        return {};
        break;
    }
  }
  std::optional<ForceVec<3>> AppliedLoad::get_force_vector() const {
    switch (_state) {
      case State::KNOWN_FORCE:
        return ForceVec<3>({Force(_force_or_direction[0]),
                           Force(_force_or_direction[1]),
                           Force(_force_or_direction[2])});
        break;
      case State::UNKNOWN_FORCE:
        [[fallthrough]];
      case State::KNOWN_DIRECTION:
        return {};
        break;
    }
  }
  void AppliedLoad::set_force_vector(const ForceVec<3> & new_force) { 
    _state = State::KNOWN_FORCE;
    _force_or_direction = UnitlessVec<3>({new_force.x().N(), 
                                         new_force.y().N(),
                                         new_force.z().N()});
  }
};  // namespace eng
