#include "pch.h"

#include <cmath>
#include <algorithm>

#include "Bolt.h"
#include "PhysicsLibrary/Angle.h"
#include "PhysicsLibrary/Length.h"
#include "PhysicsLibrary/Volume.h"
#include "PhysicsLibrary/MomentOfArea.h"
#include "PhysicsLibrary/Stiffness.h"
#include "PhysicsLibrary/PhysicsMath.h"

namespace eng {

  joint_member::joint_member(const Material& mat, const physics::Length& thi) :
    material(mat),
    thickness(thi) { }

  physics::Stiffness bolt_stiffness(const physics::Area& Ad, const physics::Area& At, const Stress& E, 
                                    const physics::Length& lt, const physics::Length& ld) {
    return E*((Ad*At)/(Ad*lt + At*ld));
  }
  physics::Stiffness members_stiffness(const std::vector<joint_member>& members, 
                                       const physics::Length& d, const physics::Length& t) {
    physics::Stiffness ret = 0_Npm;
    physics::Length pos = 0_mm;
    physics::Length thickness = joint_thickness(members);

    std::vector<joint_member> top, bottom;
    split_members(members, top, bottom, thickness);

    for (const auto& m : top) {
      physics::Length D = 1.5*d + 2*pos*tan(0.523598775598);
      ret += (0.5774*pi*m.material.E()*d) /
        std::log(((1.15*m.thickness + D - d)*(D + d))/((1.15*m.thickness + D + d)*(D - d)));
      pos += m.thickness;
    }
    
    pos = 0_m;
    for (const auto& m : bottom) {
      physics::Length D = 1.5*d + 2*pos*tan(0.523598775598);
      ret += (0.5774*pi*m.material.E()*d) /
        std::log(((1.15*m.thickness + D - d)*(D + d))/((1.15*m.thickness + D + d)*(D - d)));
      pos += m.thickness;
    }

    return ret;
  }
  physics::Length joint_thickness(const std::vector<joint_member> members) {
    physics::Length ret = 0_m;
    for (const auto& member : members) {
      ret += member.thickness;
    }
    return ret;
  }
  void split_members(const std::vector<joint_member>& members, std::vector<joint_member>& top, 
                     std::vector<joint_member>& bottom, const physics::Length& thickness) { 
    physics::Length pos = 0_m;
    physics::Length half = thickness/2;
    
    for (const auto& member : members) {
      // determine whether the current member goes in the top half of bottom half or if it should be split into both
      if (pos < half && pos + member.thickness < half) {
        // this member goes in the top half
        top.push_back(member);
      } else if (pos < half && pos + member.thickness > half) {
        // this member should be split into both halves
        top.push_back(joint_member(member.material, half - pos));
        bottom.push_back(joint_member(member.material, pos + member.thickness - half));
      } else {
        // this member goes in the bottom half
        bottom.push_back(member);
      }
      std::reverse(bottom.begin(), bottom.end());

      pos += member.thickness;
    }
    return;
  }

    
  double factor_of_safety_yield(const Stress& Sp, const physics::Area& At, const double& C, const physics::Force& P, 
                                const physics::Force& Fi) {
    return (Sp*At)/(C*P + Fi);
  }

  double factor_of_safety_load(const Stress& Sp, const physics::Area& At, const double& C, const physics::Force& P, 
                               const physics::Force& Fi) {
    return (Sp*At - Fi)/(C*P);
  }

  double factor_of_safety_separation(const physics::Force& Fi, const physics::Force& P, const double& C) {
    return Fi / (P*(1 - C));
  }

};  // namespace eng
