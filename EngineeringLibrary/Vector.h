#pragma once

/*****************************************************************//**
 * \file   Vector.h
 * \brief  A 3D vector along with all necessary functions
 *
 *
 * \author bltan
 * \date   November 2020
 *********************************************************************/

#include <utility>
#include "Units/UnitBase.h"

namespace eng {

  /** A 3D Cartesian vector
   * \class Vector
   */
  template<typename T>
  class Vector {
  public:
    Vector(const T& xx = T(0), const T& yy = T(0), const T& zz = T(0)) : _x(xx), _y(yy), _z(zz) { }

    /** Get the x component of the vector. */
    T x() const { return _x; }
    /** Set the x component of the vector. */
    void x(const T& new_x) { _x = new_x; }

    /** Get the y component of the vector. */
    T y() const { return _y; }
    /** Set the y component of the vector. */
    void y(const T& new_y) { _y = new_y; }

    /** Get the z component of the vector. */
    T z() const { return _z; }
    /** Set the z component of the vector. */
    void z(const T& new_z) { _z = new_z; }

    /** Calculate the length of the vector. */
    T length() const {
      return sqrt(_x*_x + _y*_y + _z*_z);
    }

    /** Calculate the Euclidean norm of the vector, which isequivalent to its length.  */
    T norm() const {
      return sqrt(_x*_x + _y*_y + _z*_z);
    }

    /**
     * Normalize this vector.
     * 
     * After this operation, this vector will have a length of 1.
     */
    void normalize() {
      const T l = length();
      _x /= l;
      _y /= l;
      _z /= l;
      return;
    }

    T& operator+= (const Vector<T>& rh) { 
      _x += rh._x;
      _y += rh._y;
      _z += rh._z;
      return *this;
    }

    T& operator-= (const Vector<T>& rh) { 
      _x -= rh._x;
      _y -= rh._y;
      _z -= rh._z;
      return *this;
    }

    T& operator*= (const double& rh) { 
      _x *= rh;
      _y *= rh;
      _z *= rh;
      return *this;
    }

    T& operator/= (const double& rh) { 
      _x /= rh;
      _y /= rh;
      _z /= rh;
      return *this;
    }

  private:
    T _x;
    T _y;
    T _z;
  };

  /**
   * Vector<T> inversion operator. 
   */
  template<typename T>
  Vector<T> operator- (const Vector<T>& lh) {
    return Vector<T>(-lh.x(), -lh.y(), -lh.z());
  }

  /**
   * Vector<T> addition operator.
   */
  template<typename T>
  Vector<T> operator+ (const Vector<T>& lh, const Vector<T>& rh) {
    return Vector<T>(lh.x() + rh.x(), lh.y() + rh.y(), lh.z() + rh.z());
  }

  /**
   * Vector<T> subtraction operator.
   */
  template<typename T>
  Vector<T> operator- (const Vector<T>& lh, const Vector<T>& rh) {
    return Vector<T>(lh.x() - rh.x(), lh.y() - rh.y(), lh.z() - rh.z());
  }
  /**
   * Vector<T> multiplication operator
   */
  template<typename T, typename U>
  Vector<decltype(std::forward<T> * std::forward<U>)> operator* (const Vector<T>& lh, const U& rh) {
    return Vector<decltype(std::forward<T> * std::forward<U>)>(lh.x()*rh, lh.y()*rh, lh.z()*rh);
  }

  /**
 * Vector<T> multiplication operator
 */
  template<typename T, typename U>
  Vector<decltype(std::forward<T> * std::forward<U>)> operator* (const U& lh, const Vector<U>& rh) {
    return rh * lh;
  }

  /**
   * Vector<T> dot product.
   */
  template<typename T, typename U>
  decltype(std::forward<T> * std::forward<U>) dot(const Vector<T>& lh, const Vector<U>& rh) {
    return lh.x()* rh.x() + lh.y()*rh.y() + lh.z()*rh.z();
  }

   /**
    * Vector<T> cross product.
    */
  template<typename T, typename U>
  Vector<decltype(std::forward<T> * std::forward<U>)> cross(const Vector<T>& lh, const Vector<U>& rh) {
    return Vector<decltype(std::forward<T> * std::forward<U>)>(
      lh.y()*rh.z() - lh.z()*rh.y(),
      lh.z()*rh.x() - lh.x()*rh.z(),
      lh.x()*rh.y() - lh.y()*rh.y()
      );
  }

  /**
   * Vector<T> division operator
   */
  template<typename T, typename U>
  Vector<decltype(std::forward<T> / std::forward<U>)> operator/ (const Vector<T>& lh, const U& rh) {
    return Vector<decltype(std::forward<T> / std::forward<U>)>(lh.x()/rh, lh.y()/rh, lh.z()/rh);
  }

  template<typename T>
  bool operator== (const Vector<T>& lh, const Vector<T>& rh) {
    return lh.x() == rh.x() && lh.y() == rh.y() && lh.z() == rh.z();
  }

  template<typename T>
  bool operator!= (const Vector<T>& lh, const Vector<T>& rh) {
    return !(lh == rh);
  }

};  // namespace eng

