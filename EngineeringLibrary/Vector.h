#pragma once

/*****************************************************************//**
 * \file   Vector.h
 * \brief  A 3D vector along with all necessary functions
 *
 *
 * \author bltan
 * \date   November 2020
 *********************************************************************/

#include "Units/UnitBase.h"

namespace eng {

  /** A 3D Cartesian vector
   * \class Vector
   */
  template<int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
    int MD=1, int LD=1, int TD=1, int CD=1, int TeD=1, int AD=1, int LuD=1>
  class Vector {
    typedef UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD> unit_t;
    typedef Vector<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD> vec_t;
  public:
    Vector(const unit_t& x = unit_t(0), const unit_t& y = unit_t(0), const unit_t& z = unit_t(0)) :
      _x(x), 
      _y(y), 
      _z(z) { }
    explicit Vector(const double& x, const double& y, const double& z) : 
      _x(x),
      _y(y),
      _z(z) { }
    explicit Vector(const Vector<0,0,0,0,0,0,0>& values) : 
      _x(values.x()), 
      _y(values.y()), 
      _z(values.z()) { }

    /** Get the x component of the vector. */
    unit_t x() const { return _x; }
    /** Set the x component of the vector. */
    void x(const unit_t& new_x) { _x = new_x; }

    /** Get the y component of the vector. */
    unit_t y() const { return _y; }
    /** Set the y component of the vector. */
    void y(const unit_t& new_y) { _y = new_y; }

    /** Get the z component of the vector. */
    unit_t z() const { return _z; }
    /** Set the z component of the vector. */
    void z(const unit_t& new_z) { _z = new_z; }

    /** Calculate the length of the vector. */
    unit_t length() const {
      return sqrt<2*MN, 2*LN, 2*TN, 2*CN, 2*TeN, 2*AN, 2*LuN, MD, LD, TD, CD, TeD, AD, LuD>(_x*_x + _y*_y + _z*_z);
    }

    /** Calculate the Euclidean norm of the vector, which is equivalent to its length.  */
    unit_t norm() const {
      return sqrt<2*MN, 2*LN, 2*TN, 2*CN, 2*TeN, 2*AN, 2*LuN, MD, LD, TD, CD, TeD, AD, LuD>(_x*_x + _y*_y + _z*_z);
    }

    vec_t& operator+= (const vec_t& rh) {
      _x += rh._x;
      _y += rh._y;
      _z += rh._z;
      return *this;
    }

    vec_t& operator-= (const vec_t& rh) {
      _x -= rh._x;
      _y -= rh._y;
      _z -= rh._z;
      return *this;
    }

    vec_t& operator*= (const double& rh) {
      _x *= rh;
      _y *= rh;
      _z *= rh;
      return *this;
    }

    vec_t& operator/= (const double& rh) {
      _x /= rh;
      _y /= rh;
      _z /= rh;
      return *this;
    }

  private:
    unit_t _x;
    unit_t _y;
    unit_t _z;
  };

  /** Normalize a vector.
   *
   * \param in The vector to normalize.
   * \return The normalized vector in. 
   */
  template<int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
    int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  Vector<0,0,0,0,0,0,0> normalize(const Vector<MN, LN, TN, CN, TeN, AN, LuN,
                                    MD, LD, TD, CD, TeD, AD, LuD>& in) {
    const auto l = in.norm();
    return Vector<0,0,0,0,0,0,0>(in.x()/l, 
                                 in.y()/l, 
                                 in.z()/l);
  }

  /**
   * Vector<T> inversion operator. 
   */
  template<int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
    int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
    Vector<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>
    operator- (const Vector<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh) {
    return Vector<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>(-lh.x(),
                                                                              -lh.y(),
                                                                              -lh.z());
  }

  /**
   * Vector<T> addition operator.
   */
  template<int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
    int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
    Vector<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>
    operator+ (const Vector<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh,
               const Vector<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& rh) {
    return Vector<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>(lh.x() + rh.x(),
                                                                              lh.y() + rh.y(),
                                                                              lh.z() + rh.z());
  }

  /**
   * Vector<T> subtraction operator.
   */
  template<int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
    int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
    Vector<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>
    operator- (const Vector<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh,
               const Vector<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& rh) {
    return Vector<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>(lh.x() - rh.x(),
                                                                              lh.y() - rh.y(),
                                                                              lh.z() - rh.z());
  }
  /**
   * Vector<T> multiplication operators
   */

  template<int MN1, int LN1, int TN1, int CN1, int TeN1, int AN1, int LuN1,
    int MD1, int LD1, int TD1, int CD1, int TeD1, int AD1, int LuD1,
    int MN2, int LN2, int TN2, int CN2, int TeN2, int AN2, int LuN2,
    int MD2, int LD2, int TD2, int CD2, int TeD2, int AD2, int LuD2>
    auto
    operator* (const Vector<MN1, LN1, TN1, CN1, TeN1, AN1, LuN1, MD1, LD1, TD1, CD1, TeD1, AD1, LuD1>& lh,
               const UnitBase<MN2, LN2, TN2, CN2, TeN2, AN2, LuN2, MD2, LD2, TD2, CD2, TeD2, AD2, LuD2>& rh) {
    return Vector<_numa(MN1, MD1, MN2, MD2),
      _numa(LN1, LD1, LN2, LD2),
      _numa(TN1, TD1, TN2, TD2),
      _numa(CN1, CD1, CN2, CD2),
      _numa(TeN1, TeD1, TeN2, TeD2),
      _numa(AN1, AD1, AN2, AD2),
      _numa(LuN1, LuD1, LuN2, LuD2),
      _denoma(MN1, MD1, MN2, MD2),
      _denoma(LN1, LD1, LN2, LD2),
      _denoma(TN1, TD1, TN2, TD2),
      _denoma(CN1, CD1, CN2, CD2),
      _denoma(TeN1, TeD1, TeN2, TeD2),
      _denoma(AN1, AD1, AN2, AD2),
      _denoma(LuN1, LuD1, LuN2, LuD2)>(lh.x() * rh,
                                       lh.y() * rh,
                                       lh.z() * rh);
  }
  template<int MN1, int LN1, int TN1, int CN1, int TeN1, int AN1, int LuN1,
    int MD1, int LD1, int TD1, int CD1, int TeD1, int AD1, int LuD1,
    int MN2, int LN2, int TN2, int CN2, int TeN2, int AN2, int LuN2,
    int MD2, int LD2, int TD2, int CD2, int TeD2, int AD2, int LuD2>
    auto
    operator* (const UnitBase<MN1, LN1, TN1, CN1, TeN1, AN1, LuN1, MD1, LD1, TD1, CD1, TeD1, AD1, LuD1>& lh,
               const Vector<MN2, LN2, TN2, CN2, TeN2, AN2, LuN2, MD2, LD2, TD2, CD2, TeD2, AD2, LuD2>& rh) {
    return rh * lh;
  }
  template<int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
    int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
    Vector<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>
    operator* (const Vector<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh,
               const double& rh) {
    return Vector<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>(lh.x() * rh,
                                                                              lh.y() * rh,
                                                                              lh.z() * rh);
  }
  template<int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
    int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
    Vector<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>
    operator* (const double& lh,
               const Vector<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& rh) {
    return rh * lh;
  }


  /**
   * Vector<T> dot product.
   */
  template<int MN1, int LN1, int TN1, int CN1, int TeN1, int AN1, int LuN1,
    int MD1, int LD1, int TD1, int CD1, int TeD1, int AD1, int LuD1,
    int MN2, int LN2, int TN2, int CN2, int TeN2, int AN2, int LuN2,
    int MD2, int LD2, int TD2, int CD2, int TeD2, int AD2, int LuD2>
    auto
    dot(const Vector<MN1, LN1, TN1, CN1, TeN1, AN1, LuN1, MD1, LD1, TD1, CD1, TeD1, AD1, LuD1>& lh, 
        const Vector<MN2, LN2, TN2, CN2, TeN2, AN2, LuN2, MD2, LD2, TD2, CD2, TeD2, AD2, LuD2>& rh) {
    return lh.x()*rh.x() + lh.y()*rh.y() + lh.z()*rh.z();
  }

   /**
    * Vector<T> cross product.
    */
  template<int MN1, int LN1, int TN1, int CN1, int TeN1, int AN1, int LuN1,
    int MD1, int LD1, int TD1, int CD1, int TeD1, int AD1, int LuD1,
    int MN2, int LN2, int TN2, int CN2, int TeN2, int AN2, int LuN2,
    int MD2, int LD2, int TD2, int CD2, int TeD2, int AD2, int LuD2>
    auto
    cross(const Vector<MN1, LN1, TN1, CN1, TeN1, AN1, LuN1, MD1, LD1, TD1, CD1, TeD1, AD1, LuD1>& lh,
          const Vector<MN2, LN2, TN2, CN2, TeN2, AN2, LuN2, MD2, LD2, TD2, CD2, TeD2, AD2, LuD2>& rh) {
    return Vector<_numa(MN1, MD1, MN2, MD2),
      _numa(LN1, LD1, LN2, LD2),
      _numa(TN1, TD1, TN2, TD2),
      _numa(CN1, CD1, CN2, CD2),
      _numa(TeN1, TeD1, TeN2, TeD2),
      _numa(AN1, AD1, AN2, AD2),
      _numa(LuN1, LuD1, LuN2, LuD2),
      _denoma(MN1, MD1, MN2, MD2),
      _denoma(LN1, LD1, LN2, LD2),
      _denoma(TN1, TD1, TN2, TD2),
      _denoma(CN1, CD1, CN2, CD2),
      _denoma(TeN1, TeD1, TeN2, TeD2),
      _denoma(AN1, AD1, AN2, AD2),
      _denoma(LuN1, LuD1, LuN2, LuD2)>(lh.y()*rh.z() - lh.z()*rh.y(),
                                       lh.z()*rh.x() - lh.x()*rh.z(),
                                       lh.x()*rh.y() - lh.y()*rh.x());
  }

  /**
   * Vector<T> division operators
   */
  template<int MN1, int LN1, int TN1, int CN1, int TeN1, int AN1, int LuN1,
    int MD1, int LD1, int TD1, int CD1, int TeD1, int AD1, int LuD1,
    int MN2, int LN2, int TN2, int CN2, int TeN2, int AN2, int LuN2,
    int MD2, int LD2, int TD2, int CD2, int TeD2, int AD2, int LuD2>
    auto 
    operator/ (const Vector<MN1, LN1, TN1, CN1, TeN1, AN1, LuN1, MD1, LD1, TD1, CD1, TeD1, AD1, LuD1>& lh, 
               const UnitBase<MN2, LN2, TN2, CN2, TeN2, AN2, LuN2, MD2, LD2, TD2, CD2, TeD2, AD2, LuD2>& rh) {
    return Vector<_nums(MN1, MD1, MN2, MD2),
      _nums(LN1, LD1, LN2, LD2),
      _nums(TN1, TD1, TN2, TD2),
      _nums(CN1, CD1, CN2, CD2),
      _nums(TeN1, TeD1, TeN2, TeD2),
      _nums(AN1, AD1, AN2, AD2),
      _nums(LuN1, LuD1, LuN2, LuD2),
      _denoms(MN1, MD1, MN2, MD2),
      _denoms(LN1, LD1, LN2, LD2),
      _denoms(TN1, TD1, TN2, TD2),
      _denoms(CN1, CD1, CN2, CD2),
      _denoms(TeN1, TeD1, TeN2, TeD2),
      _denoms(AN1, AD1, AN2, AD2),
      _denoms(LuN1, LuD1, LuN2, LuD2)>(lh.x()/rh,
                                       lh.y()/rh,
                                       lh.z()/rh);
  }
  template<int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
    int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
    Vector<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>
    operator/ (const Vector<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh,
               const double& rh) {
    return Vector<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>(lh.x() / rh,
                                                                              lh.y() / rh,
                                                                              lh.z() / rh)
      ;
  }

  template<int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
    int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
    bool  operator== (const Vector<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh,
                      const Vector<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& rh) {
    return lh.x() == rh.x() && lh.y() == rh.y() && lh.z() == rh.z();
  }

  template<int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
    int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
    bool  operator!= (const Vector<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh,
                      const Vector<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& rh) {
    return !(lh == rh);
  }

};  // namespace eng

