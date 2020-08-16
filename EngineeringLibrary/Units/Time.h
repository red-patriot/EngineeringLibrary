#ifndef Time_h_INCLUDED
#define Time_h_INCLUDED

#include "PhysicsBase.h"

#include <Eigen/Core>

namespace physics {

  /**
   * \class Time a time
   */
  class ENGINEERINGLIBRARY_API Time : public PhysicsBase {
  public:
    /**
     * \brief Construct a Time
     * 
     * \param _seconds the measure of time in seconds
     */
    explicit Time(const double _seconds = 0) : PhysicsBase(_seconds) { }
    Time(const Time&) = default;
    ~Time() = default;

    double sec() const { return _value; }
    double minute() const { return _value / 60; }
    double hour() const { return _value / 3600; }

    Time& operator+= (const Time& rh) { _value += rh._value; return *this; }
    Time& operator-= (const Time& rh) { _value -= rh._value; return *this; }
    Time& operator*= (const double& rh) { _value *= rh; return *this; }
    Time& operator/= (const double& rh) { _value /= rh; return *this; }
  };

  Time ENGINEERINGLIBRARY_API operator"" _sec (long double val);
  Time ENGINEERINGLIBRARY_API operator"" _sec (unsigned long long val);

  Time ENGINEERINGLIBRARY_API operator"" _minute (long double val);
  Time ENGINEERINGLIBRARY_API operator"" _minute (unsigned long long val);

  Time ENGINEERINGLIBRARY_API operator"" _hour (long double val);
  Time ENGINEERINGLIBRARY_API operator"" _hour (unsigned long long val);

  Time ENGINEERINGLIBRARY_API operator- (const Time& lh);

  Time ENGINEERINGLIBRARY_API operator+ (const Time& lh, const Time& rh);

  Time ENGINEERINGLIBRARY_API operator- (const Time& lh, const Time& rh);
  
  Time ENGINEERINGLIBRARY_API operator* (const Time& lh, const double& rh);
  Time ENGINEERINGLIBRARY_API operator* (const double& lh, const Time& rh);

  Time ENGINEERINGLIBRARY_API operator/ (const Time& lh, const double& rh);

  bool operator== (const Time& lh, const Time& rh);
  bool operator> (const Time& lh, const Time& rh);
  bool operator!= (const Time& lh, const Time& rh);
  bool operator< (const Time& lh, const Time& rh);
  bool operator>= (const Time& lh, const Time& rh);
  bool operator<= (const Time& lh, const Time& rh);


  inline Time ENGINEERINGLIBRARY_API conj(const Time& x) { return x; }
  inline Time ENGINEERINGLIBRARY_API real(const Time& x) { return x; }
  inline Time ENGINEERINGLIBRARY_API imag(const Time& x) { return 0_sec; }

};  // namepsace physics

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<physics::Time> : NumTraits<double> {
    typedef physics::Time Real;
    typedef physics::Time NonInteger;
    typedef physics::Time Nested;

    enum {
      IsComplex = 0,
      IsInteger = 0,
      IsSigned = 1,
      RequireInitialization = 1,
      ReadCost = 1,
      AddCost = 3,
      MulCost = 3
    };
  };

};  // namespace Eigen

using physics::operator"" _sec;        using physics::operator"" _minute;
using physics::operator"" _hour;

#endif
