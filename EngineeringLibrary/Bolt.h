#ifndef Bolt_h_INCLUDED
#define Bolt_h_INCLUDED

#include <vector>
#include <utility>

#include "EngineeringExport.h"
#include "Material.h"

#include "PhysicsLibrary/Length.h"
#include "PhysicsLibrary/Area.h"
#include "PhysicsLibrary/Force.h"

namespace eng {

  class ENGINEERINGLIBRARY_API ThreadStandard {
    /* A model of Metric or Unified series screws and bolts. */
  public:
    enum Series {
      METRIC, UNIFIED
    };
    // TODO: Add a constructor here
    ~ThreadStandard() = default;



  private:
    // TODO: Maybe add more members (L, Lt, ld, l)?
    physics::Length diameter;
    physics::Length pitch;
    physics::Area tensile_area;

    Series series;
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
