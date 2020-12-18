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
#include "AppliedMoment.h"

namespace eng {

  /** A class which analyzes static systems:
   *    &Sigma;F = &Sigma;M = 0
   * \class StaticSystem
   * \addtogroup Statics
   */
  class StaticSystem {
  public:
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

    /**
     * \brief Access all known loads
     *
     * \return a std::vector of all known loads
     */
    std::vector<AppliedLoad> get_known_loads() const;

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
     * \brief Access all known moments
     *
     * \return a std::vector of all known moments
     */
    std::vector<AppliedMoment> get_known_moments() const;

    /** Uses matrix math to solve for the magnitudes and directions of the 
     *   unknown loads and moments in the system.
     * \brief solve the system
     * 
     * \return A boolean indicating if the system was successfully solved.
     */
    bool solve() const;

    /** Access the solved loads. If the system has not been solved, 
     *    solve it first.
     * 
     * \return A std::vector of previously unknown loads
     */
    std::vector<AppliedLoad> get_solved_loads() const;

    /** Access the solved moments. If the system has not been solved, 
     *    solve it first.
     * 
     * \return A std::vector of previously unknown moments
     */
    std::vector<AppliedMoment> get_solved_moments() const;

  private:
    mutable bool _is_solved;

    std::vector<AppliedLoad> _known_loads;
    mutable std::vector<AppliedLoad> _unknown_loads;

    std::vector<AppliedMoment> _known_moments;
    mutable std::vector<AppliedMoment> _unknown_moments;

    typedef Eigen::Matrix<double, 6, 7> SystemModel;

    void populate_known_loads(SystemModel& system_matrix) const;
    void populate_known_moments(SystemModel& system_matrix) const;

    void populate_unknown_values(SystemModel& system_matrix) const;
    void populate_unknown_loads(SystemModel& system_matrix, int& index) const;
    void populate_unknown_moments(SystemModel& system_matrix, int& index) const;

    void solve_system(SystemModel& system_matrix) const;
    void save_solved_values(SystemModel& system_matrix) const;
  };

};  // namespace eng
