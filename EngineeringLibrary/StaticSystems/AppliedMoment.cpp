#include "pch.h"

#include <cmath>

#include "AppliedMoment.h"

namespace eng {

  eng::AppliedMoment::AppliedMoment() :
  _state(State::UNKNOWN_MOMENT),
  _moment_or_direction(std::nan("unknown"),
                       std::nan("unknown"),
                       std::nan("unknown")) { }

  eng::AppliedMoment::AppliedMoment(const Moment Mx, const Moment My, const Moment Mz) :
  _state(State::KNOWN_MOMENT),
  _moment_or_direction(Mx.Nm(), My.Nm(), Mz.Nm()) { 
    if (std::isnan(Mx.Nm()) ||
        std::isnan(My.Nm()) ||
        std::isnan(Mz.Nm())) {
      _state = State::UNKNOWN_MOMENT;
    }
  }

  eng::AppliedMoment::AppliedMoment(const MomentVec M) :
    _state(State::KNOWN_MOMENT), 
    _moment_or_direction(M.x().Nm(),
                         M.y().Nm(),
                         M.z().Nm()) { 
    if (std::isnan(M.x().Nm()) ||
        std::isnan(M.y().Nm()) ||
        std::isnan(M.z().Nm())) {
      _state = State::UNKNOWN_MOMENT;
    }
  }

  eng::AppliedMoment::AppliedMoment(const UnitlessVec u) :
  _state(State::KNOWN_DIRECTION),
  _moment_or_direction(u) { }

  eng::AppliedMoment::AppliedMoment(const double i_hat, const double j_hat, const double k_hat) : 
  _state(State::KNOWN_DIRECTION),
  _moment_or_direction(i_hat, 
                       j_hat, 
                       k_hat) { }

  std::optional<UnitlessVec> eng::AppliedMoment::get_direction() const {
    switch (_state) {
      case State::KNOWN_MOMENT:
        return std::optional<UnitlessVec>(normalize(_moment_or_direction));
        break;
      case State::UNKNOWN_MOMENT:
        return {};
        break;
      case State::KNOWN_DIRECTION:
        return std::optional<UnitlessVec>(_moment_or_direction);
        break;
    }
  }

  std::optional<Moment> eng::AppliedMoment::get_magnitude() const {
    switch (_state) {
      case State::KNOWN_MOMENT:
        return Moment(_moment_or_direction.norm());
        break;
      case State::UNKNOWN_MOMENT:
        [[fallthrough]];
      case State::KNOWN_DIRECTION:
        return {};
        break;
    }
  }

  std::optional<MomentVec> eng::AppliedMoment::get_moment_vector() const {
    switch (_state) {
      case State::KNOWN_MOMENT:
        return MomentVec(_moment_or_direction);
        break;
      case State::UNKNOWN_MOMENT:
        [[fallthrough]];
      case State::KNOWN_DIRECTION:
        return {};
        break;
    }
  }

  void eng::AppliedMoment::set_moment_vector(const MomentVec & new_moment) { 
    _state = State::KNOWN_MOMENT;
    _moment_or_direction = UnitlessVec(new_moment.x().Nm(),
                                       new_moment.y().Nm(),
                                       new_moment.z().Nm());
  }

};  // namespace eng
