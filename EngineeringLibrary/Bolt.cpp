#include "pch.h"

#include <cmath>
#include <algorithm>

#include "Bolt.h"
#include "Units/Angle.h"
#include "Units/Length.h"
#include "Units/Area.h"
#include "Units/Volume.h"
#include "Units/MomentOfArea.h"
#include "Units/Stiffness.h"
#include "Units/PhysicsMath.h"

namespace eng {

  joint_member::joint_member(const Material& mat, const Length& thi) :
    material(mat),
    thickness(thi) { }

  Stiffness bolt_stiffness(const Area& Ad, const Area& At, const Stress& E, 
                                    const Length& lt, const Length& ld) {
    eng::Acceleration a = 1_mpsec2;
    eng::Mass m = 1_kg;
    eng::Force f = m * a;
    return E*((Ad * At)/(Ad*lt + At*ld));
  }
  Stiffness members_stiffness(const std::vector<joint_member>& members, 
                                       const Length& d, const Length& t) {
    Stiffness ret = 0_Npm;
    Length pos = 0_mm;
    Length thickness = joint_thickness(members);

    std::vector<joint_member> top, bottom;
    split_members(members, top, bottom, thickness);

    for (const auto& m : top) {
      Length D = 1.5*d + 2*pos*std::tan(0.523598775598);
      /*ret += (0.5774*pi*m.material.E()*d) /
        std::log(((1.15*m.thickness + D - d)*(D + d))/((1.15*m.thickness + D + d)*(D - d)));*/
      pos += m.thickness;
    }
    
    pos = 0_m;
    for (const auto& m : bottom) {
      Length D = 1.5*d + 2*pos*std::tan(0.523598775598);
      /*ret += (0.5774*pi*m.material.E()*d) /
        std::log(((1.15*m.thickness + D - d)*(D + d))/((1.15*m.thickness + D + d)*(D - d)));*/
      pos += m.thickness;
    }

    return ret;
  }
  Length joint_thickness(const std::vector<joint_member> members) {
    Length ret = 0_m;
    for (const auto& member : members) {
      ret += member.thickness;
    }
    return ret;
  }
  void split_members(const std::vector<joint_member>& members, std::vector<joint_member>& top, 
                     std::vector<joint_member>& bottom, const Length& thickness) { 
    Length pos = 0_m;
    Length half = thickness/2;
    
    for (const auto& member : members) {
      // determine whether the current member goes in the top half of bottom 
      //    half or if it should be split into both
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

    
  double factor_of_safety_yield(const Stress& Sp, const Area& At, const double& C, const Force& P, 
                                const Force& Fi) {
    return (Sp*At)/(C*P + Fi);
  }

  double factor_of_safety_load(const Stress& Sp, const Area& At, const double& C, const Force& P, 
                               const Force& Fi) {
    return (Sp*At - Fi)/(C*P);
  }

  double factor_of_safety_separation(const Force& Fi, const Force& P, const double& C) {
    return Fi / (P*(1 - C));
  }

};  // namespace eng
