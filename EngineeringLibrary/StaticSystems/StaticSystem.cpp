#include "pch.h"

#include <eigen3/Eigen/Core>
#include <algorithm>

#include "StaticSystem.h"
#include "../Units/Torque.h"
#include "echelon.h"

namespace eng {

  void StaticSystem::add_known_load(const AppliedLoad new_load) { 
    if (new_load._state == AppliedLoad::State::KNOWN_FORCE) {
      _known_loads.push_back(new_load);
    }
  }

  void StaticSystem::add_unknown_load(const AppliedLoad new_load) { 
    if (new_load._state != AppliedLoad::State::KNOWN_FORCE) {
      _unknown_loads.push_back(new_load);
    }
  }

  std::vector<AppliedLoad> StaticSystem::get_known_loads() const {
    return _known_loads;
  }

  void StaticSystem::add_known_moment(const AppliedMoment new_moment) { 
    if (new_moment._state == AppliedMoment::State::KNOWN_MOMENT) {
      _known_moments.push_back(new_moment);
    }
  }

  void StaticSystem::add_unknown_moment(const AppliedMoment new_moment) { 
    if (new_moment._state != AppliedMoment::State::KNOWN_MOMENT) {
      _unknown_moments.push_back(new_moment);
    }
  }

  std::vector<AppliedMoment> StaticSystem::get_known_moments() const {
    return _known_moments;
  }

  bool StaticSystem::solve() const {
    //TODO: Determine if the system is indeterminate using a more sophisticated
    //  metric, if possible.
    if (_unknown_loads.size() + _unknown_moments.size() > 6) {
      // There are too many unknowns to solve
      return false;
    }
    SystemModel system_matrix = SystemModel::Zero();

    // populate the loads and moments into the Matrix
    populate_known_loads(system_matrix);
    populate_known_moments(system_matrix);

    populate_unknown_values(system_matrix);

    // row reduce the system matrix
    solve_system(system_matrix);

    // extract and store the newly solved loads
    save_solved_values(system_matrix);

    // Set the flag that the system is solved
    _is_solved = true;

    return true;
  }

  std::vector<AppliedLoad> StaticSystem::get_solved_loads() const {
    if (!_is_solved) {
      solve();
    }
    return _unknown_loads;
  }

  std::vector<AppliedMoment> StaticSystem::get_solved_moments() const {
    if (!_is_solved) {
      solve();
    }
    return _unknown_moments;
  }

  void StaticSystem::populate_known_loads(SystemModel& system_matrix) const { 
    for (const auto& load : _known_loads) {
      ForceVec force = *load.get_force_vector();
      LengthVec position = load.get_position();
      MomentVec moment = cross(position, force);

      system_matrix(0, 6) -= force.x().N();
      system_matrix(1, 6) -= force.y().N();
      system_matrix(2, 6) -= force.z().N();
      system_matrix(3, 6) -= moment.x().Nm();
      system_matrix(4, 6) -= moment.y().Nm();
      system_matrix(5, 6) -= moment.z().Nm();
    }

    return;
  }

  void StaticSystem::populate_known_moments(SystemModel & system_matrix) const { 
    for (const auto& moment : _known_moments) {
      system_matrix(3, 6) -= moment.get_moment_vector()->x().Nm();
      system_matrix(4, 6) -= moment.get_moment_vector()->y().Nm();
      system_matrix(5, 6) -= moment.get_moment_vector()->z().Nm();
    }
  }

  void StaticSystem::populate_unknown_values(SystemModel& system_matrix) const { 
    // a counter for the current unknown (there can be 6 max)
    int current_unknown = 0;

    populate_unknown_loads(system_matrix, current_unknown);
    populate_unknown_moments(system_matrix, current_unknown);
  }

  void StaticSystem::populate_unknown_loads(SystemModel& system_matrix, int& index) const {
    for (const auto& load : _unknown_loads) {
      LengthVec position = load.get_position();
      // if the direction is known, there is only 1 unknown
      if (auto direction = load.get_direction()) {
        LengthVec moment_arm = cross(position, *direction);
        system_matrix(0, index) = direction->x();
        system_matrix(1, index) = direction->y();
        system_matrix(2, index) = direction->z();
        system_matrix(3, index) = moment_arm.x().m();
        system_matrix(4, index) = moment_arm.y().m();
        system_matrix(5, index) = moment_arm.z().m();
        ++index;
        // if the directon is unknown, there are 3 unknowns
      } else {
        system_matrix(0, index) = 1.0;
        system_matrix(1, index) = 0.0;
        system_matrix(2, index) = 0.0;
        system_matrix(3, index) = 0.0;
        system_matrix(4, index) = position.z().m();
        system_matrix(5, index) = position.y().m();
        ++index;
        system_matrix(0, index) = 0.0;
        system_matrix(1, index) = 1.0;
        system_matrix(2, index) = 0.0;
        system_matrix(3, index) = -position.z().m();
        system_matrix(4, index) = 0.0;
        system_matrix(5, index) = position.x().m();
        ++index;
        system_matrix(0, index) = 0.0;
        system_matrix(1, index) = 0.0;
        system_matrix(2, index) = 1.0;
        system_matrix(3, index) = position.y().m();
        system_matrix(4, index) = -position.x().m();
        system_matrix(5, index) = 0.0;
        ++index;
      }
    }

    return;
  }

  void StaticSystem::populate_unknown_moments(SystemModel& system_matrix, int& index) const { 
    for (const auto& moment : _unknown_moments) {
      // if the direction is known, there is only one unknown
      if (auto direction = moment.get_direction()) {
        system_matrix(3, index) = direction->x();
        system_matrix(4, index) = direction->y();
        system_matrix(5, index) = direction->z();
        ++index;
        // if the direction is unknown, there are 3 unknowns
      } else {
        system_matrix(3, index++) = 1.0;
        system_matrix(4, index++) = 1.0;
        system_matrix(5, index++) = 1.0;
      }
    }
  }

  void StaticSystem::solve_system(SystemModel& system_matrix) const {
    reduced_row_echelon_form<6, 7>(system_matrix);
    return;
  }

  void StaticSystem::save_solved_values(SystemModel& system_matrix) const {
    // This uses the same algorithm as StaticSystem::populate_unknown_loads to
    //   extract the solved loadss
    int current_unknown = 0;
    for (auto& load : _unknown_loads) {
      // if the direction is known, there is only 1 unknown
      auto direction = load.get_direction();
      if (direction.has_value()) {
        load._force_or_direction = system_matrix(current_unknown++, 6) * *direction;
      // if the directon is unknown, there are 3 unknowns
      } else {
        load._force_or_direction.x(system_matrix(current_unknown++, 6));
        load._force_or_direction.y(system_matrix(current_unknown++, 6));
        load._force_or_direction.z(system_matrix(current_unknown++, 6));
      }

      // Set the load to a known load
      load._state = AppliedLoad::State::KNOWN_FORCE;
    }

    // extract solved moments
    for (auto& moment : _unknown_moments) {
      // if the direction is known, there is only 1 unknown
      if (auto direction = moment.get_direction()) {
        moment._moment_or_direction = system_matrix(current_unknown++, 6) * *direction;
      // if the direction is unknown, there are 3 unknowns
      } else {
        moment._moment_or_direction.x(system_matrix(current_unknown++, 6));
        moment._moment_or_direction.y(system_matrix(current_unknown++, 6));
        moment._moment_or_direction.z(system_matrix(current_unknown++, 6));
      }
     
      moment._state = AppliedMoment::State::KNOWN_MOMENT;
    }

    return;
  }

};  // namespace eng
