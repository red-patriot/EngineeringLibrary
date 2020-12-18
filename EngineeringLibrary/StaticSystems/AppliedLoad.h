#pragma once

/*****************************************************************//**
 * \file   AppliedLoad.h
 * \brief  A known or unknown load in a static system
 * 
 * 
 * \author bltan
 * \date   September 2020
 *********************************************************************/

#include <optional>

#include "../Units/Force.h"
#include "../Units/Length.h"
#include "../UnitVector.h"

namespace eng {

  /** A load which can be applied to any point in a StaticSystem
   * \class AppliedLoad
   * \addtogroup Statics
   */
  class AppliedLoad {
    friend class StaticSystem;
  public:
    /** Construct an AppliedLoad with a known or partially known Force
     * 
     * \param Fx The x component of the Force
     * \param Fy The y component of the Force
     * \param Fz The z component of the Force
     * \param c The location of the load
     */
    AppliedLoad(const Force Fx, const Force Fy, const Force Fz, const LengthVec c);
    /** Construct an AppliedLoad with a known or partially known Force
     * 
     * \param F The Force applied
     * \param c The location of the laod
     */
    AppliedLoad(const ForceVec F, const LengthVec c);
    /** Construct an AppliedLoad with an unknown Force
     * 
     * \param x The x coordinate of the location of the load
     * \param y The y coordinate of the location of the load
     * \param z The z coordinate of the location of the load
     */
    AppliedLoad(const Length x, const Length y, const Length z);
    /** Construct an AppliedLoad with an unknown Force
     * 
     * \param c The location of the Load
     */
    AppliedLoad(const LengthVec c);
    /** Construct an AppliedLoad with a known direction
     * 
     * \param u A unit vector in the direction of the load.
     * \param c The location of the load
     */
    AppliedLoad(const UnitlessVec u, const LengthVec c);
    /** Construct an AppliedLoad with a known direction
     * 
     * \param i_hat The x component of the direction of the load
     * \param j_hat The y component of the direction of the load
     * \param k_hat The z component of the direction of the load
     */
    AppliedLoad(const double i_hat, const double j_hat, const double k_hat, const LengthVec c);

    /** Get the direction of the AppliedLoad, if possible
     * 
     * \return A std::optional<eng::UnitlessVec> in the direction in the Load, if
     *   the direction can be determined
     */
    std::optional<UnitlessVec> get_direction() const;
    /** Get the magnitude of the AppliedLoad, if possible
     * 
     * \return A std::optional<eng::Force> depending on if this load's magnitude 
     *   is known
     */
    std::optional<Force> get_magnitude() const;
    /** Get the vector representation of the AppliedLoad, if possible
     * 
     * \return A std::optional<eng::ForceVec> depending on if this load's 
     *   forces are known.
     */
    std::optional<ForceVec> get_force_vector() const;
    /** An accessor to retrieve the location of the AppliedLoad
     * 
     * \return The position of the AppliedLoad
     */
    eng::LengthVec get_position() const { return _position; }

  private:
    enum class State { 
      KNOWN_FORCE,
      UNKNOWN_FORCE,
      KNOWN_DIRECTION,
    } _state;

    UnitlessVec _force_or_direction;

    LengthVec _position;

    /** Set the force in the AppliedLoad.
     * This can only be a known force, and can only be used in the solving process
     */
    void set_force_vector(const ForceVec& new_force);
  };

};  // namespace eng
