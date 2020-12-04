#include "pch.h"

#include <eigen3/Eigen/Core>

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

  std::vector<AppliedLoad> StaticSystem::operator() () {
    //? Maybe determine if the system is indeterminate before solving
    SystemModel system_matrix = SystemModel::Zero();

    // populate the loads into the Matrix
    populate_known_loads(system_matrix);
    populate_unknown_loads(system_matrix);

    // row reduce the system matrix
    solve_system(system_matrix);

    // extract and store the newly solved loads
    save_solved_loads(system_matrix);

    return _unknown_loads;
  }

  void StaticSystem::populate_known_loads(SystemModel& system_matrix) const { 
    for (const auto& load : _known_loads) {
      ForceVec force = *load.get_force_vector();
      LengthVec position = load.get_position();
      MomentVec moment = cross_product(position, force);

      system_matrix(0, 6) -= force.x().N();
      system_matrix(1, 6) -= force.y().N();
      system_matrix(2, 6) -= force.z().N();
      system_matrix(3, 6) -= moment.x().Nm();
      system_matrix(4, 6) -= moment.y().Nm();
      system_matrix(5, 6) -= moment.z().Nm();
    }

    return;
  }

  void StaticSystem::populate_unknown_loads(SystemModel& system_matrix) const {
    // a counter for the current unknown (there can be 6 max)
    int current_unknown = 0;
    
    for (const auto& load : _unknown_loads) {
      LengthVec position = load.get_position();
      // if the firection is known, there is only 1 unknown
      if (auto direction = load.get_direction()) {
        system_matrix(0, current_unknown) = direction->x();
        system_matrix(1, current_unknown) = direction->y();
        system_matrix(2, current_unknown) = direction->z();
        system_matrix(3, current_unknown) = direction->y()*position.z().m() - 
          direction->z().value()*position.y().m();
        system_matrix(4, current_unknown) = direction->x()*position.z().m() -
          direction->z().value()*position.x().m();
        system_matrix(5, current_unknown) = direction->x()*position.y().m() -
          direction->y().value()*position.x().m();
        ++current_unknown;
      // if the directon is unknown, there are 3 unknowns
      } else {
        // TODO: clean this up so there aren't so many repeated lines
        system_matrix(0, current_unknown) = 1.0;
        system_matrix(1, current_unknown) = 0.0;
        system_matrix(2, current_unknown) = 0.0;
        system_matrix(3, current_unknown) = 0.0;
        system_matrix(4, current_unknown) = position.z().m();
        system_matrix(5, current_unknown) = position.y().m();
        ++current_unknown;
        system_matrix(0, current_unknown) = 0.0;
        system_matrix(1, current_unknown) = 1.0;
        system_matrix(2, current_unknown) = 0.0;
        system_matrix(3, current_unknown) = -position.z().m();
        system_matrix(4, current_unknown) = 0.0;
        system_matrix(5, current_unknown) = position.x().m();
        ++current_unknown;
        system_matrix(0, current_unknown) = 0.0;
        system_matrix(1, current_unknown) = 0.0;
        system_matrix(2, current_unknown) = 1.0;
        system_matrix(3, current_unknown) = position.y().m();
        system_matrix(4, current_unknown) = -position.x().m();
        system_matrix(5, current_unknown) = 0.0;
        ++current_unknown;
      } // TODO: Maybe there are other cases here?
    }

    return;
  }

  void StaticSystem::solve_system(SystemModel& system_matrix) const {
    reduced_row_echelon_form<6, 7>(system_matrix);
    return;
  }

  void StaticSystem::save_solved_loads(SystemModel& system_matrix) {
    // This uses the same algorithm as StaticSystem::populate_unknown_loads to
    //   extract the solved values
    int current_unknown = 0;
    for (auto& load : _unknown_loads) {
      // if the firection is known, there is only 1 unknown
      if (auto direction = load.get_direction()) {
        load._force_or_direction = system_matrix(current_unknown++, 6) * *direction;
      // if the directon is unknown, there are 3 unknowns
      } else {
        load._force_or_direction.x(system_matrix(current_unknown++, 6));
        load._force_or_direction.y(system_matrix(current_unknown++, 6));
        load._force_or_direction.z(system_matrix(current_unknown++, 6));
      }
    }

    return;
  }

};  // namespace eng
