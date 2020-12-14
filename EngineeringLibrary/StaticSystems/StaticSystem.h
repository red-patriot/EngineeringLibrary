#pragma once

/*****************************************************************//**
 * \file   StaticSystem.h
 * \brief  Represents and solves a static system
 *
 *
 * \author bltan
 * \date   September 2020
 *********************************************************************/

#include <vector>

#include "AppliedLoad.h"

namespace eng {

  /** A class which analyzes static systems 
   *    &Sigma;F = &Sigma;M = 0
   * \class StaticSystem
   */
  class StaticSystem {
  public:
    /**
     * StaticSystem default constructor 
     */
    StaticSystem() = default;

    /** Copies an AppliedLoad and adds it to the system. If the user 
     *   accidentally passes a load which is not known fully, it will be 
     *   silently discarded.
     * \brief Add a known load to the system
     * 
     * \param new_load the new AppliedLoad to be added
     */
    void add_known_load(const AppliedLoad new_load);
    /** Copies an AppliedLoad and adds it to the system. If the user 
     *   accidentally passes a load which is not at least partially unknown, 
     *   it will be silently discarded.
     * \brief Add an unknown load to the system
     * 
     * \param new_load the new AppliedLoad to be added
     */
    void add_unknown_load(const AppliedLoad new_load);

    /** Copies an AppliedMoment and adds it to the system. If the user 
     *   accidentally passes a moment which is not known fully, it will be 
     *   silently discarded.
     * \brief Add a known moment to the system
     * 
     * \param new_moment the new AppliedMoment to be added
     */
    void add_known_moment(const AppliedMoment new_moment);

    /** Copies an AppliedMoment and adds it to the system. If the user 
     *   accidentally passes a moment which is not at least partially unknown, 
     *   it will be silently discarded.
     * \brief Add an unknown moment to the system
     * 
     * \param new_load the new AppliedMoment to be added
     */
    void add_unknown_moment(const AppliedMoment new_moment);

    /**
     * \brief Access all known loads 
     * 
     * \return a std::vector of all known loads
     */
    std::vector<AppliedLoad> get_known_loads() const;

    /** Uses matrix math to solve for the magnitudes and directions of the 
     *   unknown loads in the system.
     * \brief solve the system
     * 
     * \return A std::vector of the previously unknown loads which were solved
     */
    std::vector<AppliedLoad> operator() ();

  private:
    std::vector<AppliedLoad> _known_loads;
    std::vector<AppliedLoad> _unknown_loads;

    typedef Eigen::Matrix<double, 6, 7> SystemModel;

    void populate_known_loads(SystemModel& system_matrix) const;
    void populate_unknown_loads(SystemModel& system_matrix) const;
    void solve_system(SystemModel& system_matrix) const;
    void save_solved_loads(SystemModel& system_matrix);

  };

};  // namespace eng
