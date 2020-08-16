#ifndef Volume_h_INCLUDED
#define Volume_h_INCLUDED

#include "UnitBase.h"

#include <Eigen/Core>

namespace physics {

  class SecondMomentOfArea;
  class Area;
  class Length;

  /**
   * \class Volume A 3D geometry
   */
  class ENGINEERINGLIBRARY_API Volume : public UnitBase {
  public:
    /**
     * \brief Construct a Volume
     * 
     * \param _meters3 the measure of the volume in meters^3
     */
    explicit Volume(const double& _meters3 = 0) : UnitBase(_meters3) { }
    Volume(const Volume&) = default;
    ~Volume() = default;

    double mm3() const { return _value * 1'000'000'000; }
    double cm3() const { return _value * 1'000'000; }
    double m3() const { return _value; }

    double in3() const { return _value * (1'000'000/16.387'064); }
    double ft3() const { return _value * (1'000'000/28'316.846'592); }

    Volume& operator+= (const Volume& rh) { _value += rh._value; return *this; }
    Volume& operator-= (const Volume& rh) { _value -= rh._value; return *this; }
    Volume& operator*= (const double& rh) { _value *= rh; return *this; }
    Volume& operator/= (const double& rh) { _value /= rh; return *this; }
  };

  // Literal operators
  Volume ENGINEERINGLIBRARY_API operator"" _mm3(long double val);
  Volume ENGINEERINGLIBRARY_API operator"" _mm3(unsigned long long val);

  Volume ENGINEERINGLIBRARY_API operator"" _cm3(long double val);
  Volume ENGINEERINGLIBRARY_API operator"" _cm3(unsigned long long val);

  Volume ENGINEERINGLIBRARY_API operator"" _m3(long double val);
  Volume ENGINEERINGLIBRARY_API operator"" _m3(unsigned long long val);

  Volume ENGINEERINGLIBRARY_API operator"" _in3(long double val);
  Volume ENGINEERINGLIBRARY_API operator"" _in3(unsigned long long val);

  Volume ENGINEERINGLIBRARY_API operator"" _ft3(long double val);
  Volume ENGINEERINGLIBRARY_API operator"" _ft3(unsigned long long val);

  Volume ENGINEERINGLIBRARY_API operator- (const Volume& lh);

  Volume ENGINEERINGLIBRARY_API operator+ (const Volume& lh, const Volume& rh);

  Volume ENGINEERINGLIBRARY_API operator- (const Volume& lh, const Volume& rh);

  Volume ENGINEERINGLIBRARY_API operator* (const Area& lh, const Length& rh);
  Volume ENGINEERINGLIBRARY_API operator* (const Length& lh, const Area& rh);
  Volume ENGINEERINGLIBRARY_API operator* (const Volume& lh, const double& n);
  Volume ENGINEERINGLIBRARY_API operator* (const double& n, const Volume& rh);

  Volume ENGINEERINGLIBRARY_API operator/ (const SecondMomentOfArea& lh, const Length& rh);
  Volume ENGINEERINGLIBRARY_API operator/ (const Volume& lh, const double& n);
  double ENGINEERINGLIBRARY_API operator/ (const Volume& lh, const Volume& rh);

  bool ENGINEERINGLIBRARY_API operator== (const Volume& lh, const Volume& rh);
  bool ENGINEERINGLIBRARY_API operator> (const Volume& lh, const Volume& rh);
  bool ENGINEERINGLIBRARY_API operator!= (const Volume& lh, const Volume& rh);
  bool ENGINEERINGLIBRARY_API operator< (const Volume& lh, const Volume& rh);
  bool ENGINEERINGLIBRARY_API operator>= (const Volume& lh, const Volume& rh);
  bool ENGINEERINGLIBRARY_API operator<= (const Volume& lh, const Volume& rh);

  inline Volume ENGINEERINGLIBRARY_API conj(const Volume& x) { return x; }
  inline Volume ENGINEERINGLIBRARY_API real(const Volume& x) { return x; }
  inline Volume ENGINEERINGLIBRARY_API imag(const Volume&) { return 0_m3; }

}; // namespace physics

/* Integration with Eigen */
namespace Eigen {

  template<> struct NumTraits<physics::Volume> : NumTraits<double> {
    typedef physics::Volume Real;
    typedef physics::Volume NonInteger;
    typedef physics::Volume Nested;

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

using physics::operator"" _mm3;         using physics::operator"" _cm3;
using physics::operator"" _m3;
using physics::operator"" _in3;         using physics::operator"" _ft3;

#endif

