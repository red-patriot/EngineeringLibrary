#pragma once

/*****************************************************************//**
 * \file   AppliedMoment.h
 * \brief  A known or unknown moment in a static system
 * 
 * 
 * \author bltan
 * \date   December 2020
 *********************************************************************/

#include <optional>

#include "../Units/Torque.h"
#include "../Units/Length.h"
#include "../UnitVector.h"


namespace eng {

  /** A moment which can be applied to a StaticSystem
   * \class AppliedMoment
   * \addtogroup Statics
   */
  class AppliedMoment {
    friend class StaticSystem;
  public:
    /**Construct an AppliedMoment with a completely unknown direction and 
     *   magnitude
     * \brief default AppliedMoment constructor 
     */
    AppliedMoment();
    /** Construct an AppliedMoment with a known or partially known Moment
     *
     * \param Mx The x component of the Moment
     * \param My The y component of the Moment
     * \param Mz The z component of the Moment
     */
    AppliedMoment(const Moment Mx, const Moment My, const Moment Mz);
    /** Construct an AppliedMoment with a known or partially known Moment
     *
     * \param M The Moment applied
     */
    AppliedMoment(const MomentVec M);
    /**
     * Construct an AppliedMoment with a known direction
     *
     * \param u A unit vector in the direction of the moment.
     */
    AppliedMoment(const UnitlessVec u);
    /** Construct an AppliedMoment with a known direction
     *
     * \param i_hat The x component of the direction of the moment
     * \param j_hat The y component of the direction of the moment
     * \param k_hat The z component of the direction of the moment
     */
    AppliedMoment(const double i_hat, const double j_hat, const double k_hat);

    /** Get the direction of the AppliedMoment, if possible
     *
     * \return A std::optional<eng::UnitlessVec> in the direction in the moment, 
     *   if the direction can be determined
     */
    std::optional<UnitlessVec> get_direction() const;
    /** Get the magnitude of the AppliedMoment, if possible
     *
     * \return A std::optional<eng::Moment> depending on if this moment's 
     *   magnitude is known
     */
    std::optional<Moment> get_magnitude() const;
    /** Get the vector representation of the AppliedMoment, if possible
     *
     * \return A std::optional<eng::MomentVec> depending on if the moment is 
     *   known
     */
    std::optional<MomentVec> get_moment_vector() const;

  private:
    enum class State {
      KNOWN_MOMENT,
      UNKNOWN_MOMENT,
      KNOWN_DIRECTION,
    } _state;

    UnitlessVec _moment_or_direction;

    /** Set the force in the AppliedMoment.
     * This can only be a known moment, and can only be used in the solving process
     */
    void set_moment_vector(const MomentVec& new_moment);
  };

};  // namespace eng
