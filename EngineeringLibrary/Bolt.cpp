#include "pch.h"

#include <cmath>

#include "Bolt.h"
#include "PhysicsLibrary/Length.h"
#include "PhysicsLibrary/Volume.h"
#include "PhysicsLibrary/MomentOfArea.h"
#include "PhysicsLibrary/Stiffness.h"
#include "PhysicsLibrary/PhysicsMath.h"

namespace eng {

  namespace bolt {
    physics::Stiffness bolt_stiffness(const physics::Area& Ad, const physics::Area& At, const Stress& E, const physics::Length& lt, const physics::Length& ld) {
      /* Calculate the stiffness of a bolt. */
      return E*((Ad*At)/(Ad*lt + At*ld));
    }

    physics::Stiffness members_stiffness(const std::vector<std::pair<Material, physics::Length>>& members, const physics::Length& d, const physics::Length& t) {
      /* Calculate the stiffess of members bolted by a bolt. */
      physics::Stiffness ret = 0_Npm;
      physics::Length pos = 0_mm;

      std::vector<std::pair<Material, physics::Length>> top, bottom;
      // TODO: write function to split members into top and bottom half and put them into top and bottom, respectively

      for (const auto& m : members) {
        // determine D
        // TODO: Write a better way to determine D
        physics::Length D = 1.5*d + 2*pos*std::tan(0.523598775598);

        ret += (0.577 * pi * m.first.E() * d) /
          std::log(((1.15*m.second + D - d)*(D + d))/((1.15*m.second + D + d)*(D - d)));
      }

      return ret;
    }
    
    physics::Stiffness member_stiffness(const std::vector<std::pair<Material, physics::Length>>& members, const physics::Length& d) {
      /* Calculate the stiffness of the members bolted by a bolt. */
      // determine the thickness of all members and then calculate the stiffness of the beam. 
      return physics::Stiffness();
    }
    double factor_of_safety_yield(const Stress& Sp, const physics::Area& At, const double& C, const physics::Force& P, const physics::Force& Fi) {
      return (Sp*At)/(C*P + Fi);
    }

    double factor_of_safety_load(const Stress& Sp, const physics::Area& At, const double& C, const physics::Force& P, const physics::Force& Fi) {
      return (Sp*At - Fi)/(C*P);
    }

    double factor_of_safety_separation(const physics::Force& Fi, const physics::Force& P, const double& C) {
      return Fi / (P*(1 - C));
    }

  };  // namespace bolt

};  // namespace eng
