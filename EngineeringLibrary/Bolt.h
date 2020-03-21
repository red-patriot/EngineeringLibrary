#ifndef Bolt_h_INCLUDED
#define Bolt_h_INCLUDED

#include <vector>
#include <utility>

#include "EngineeringExport.h"
#include "Material.h"

#include "PhysicsLibrary/Length.h"
#include "PhysicsLibrary/Area.h"
#include "PhysicsLibrary/Force.h"

/* TODO: Fix this set of functions. 
   Figure out some way to implement a Bolt class which can define a bolt will all necessary values of a bolt
   */

namespace eng {

  /* A model of Metric or Unified series thread standard 
     specifying nominal diameter, pitch, and tensile area */
  class ENGINEERINGLIBRARY_API ThreadStandard {
  public:
    enum Series {
      METRIC, UNIFIED
    };
    // TODO: Add a constructor 
    ~ThreadStandard() = default;

  private:
    physics::Length _diameter;
    physics::Length _pitch;
    physics::Area _tensile_area;

    Series _series;
  };

  /* A model of a bolt */
  class ENGINEERINGLIBRARY_API Bolt {
  public:

  private:
    ThreadStandard _standard;
  };

  namespace bolt {

    physics::Stiffness ENGINEERINGLIBRARY_API bolt_stiffness(const physics::Area& Ad, const physics::Area& At,
      const Stress& E, const physics::Length& lt, const physics::Length& ld);
    physics::Stiffness ENGINEERINGLIBRARY_API members_stiffness(const std::vector<std::pair<Material, physics::Length> >& members,
      const physics::Length& d, const physics::Length& t);
    double ENGINEERINGLIBRARY_API factor_of_safety_yield(const Stress& Sp, const physics::Area& At,
      const double& C, const physics::Force& P, const physics::Force& Fi);
    double ENGINEERINGLIBRARY_API factor_of_safety_load(const Stress& Sp, const physics::Area& At,
      const double& C, const physics::Force& P, const physics::Force& Fi);
    double ENGINEERINGLIBRARY_API factor_of_safety_separation(const physics::Force& Fi, const physics::Force& P, const double& C);

  };  // namespace bolt

};  // namespace eng

#endif
