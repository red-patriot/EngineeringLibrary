#pragma once

/*****************************************************************//**
 * \file   Vector.h
 * \brief  A 3D vector along with all necessary functions
 *
 *
 * \author bltan
 * \date   November 2020
 *********************************************************************/

#include <array>
#include <type_traits>
#include <algorithm>
#include <numeric>

#include "Units/UnitBase.h"

namespace eng {

  /** A Cartesian vector
   * \class Vector
   */
template<size_t N,
  int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
  int MD = 1, int LD = 1, int TD = 1, int CD = 1, int TeD = 1, int AD = 1, int LuD = 1>
  class Vector {
    typedef UnitBase<MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD> unit_t;
  public:
    Vector() = default;
    explicit Vector(const std::array<unit_t, N> elements) :
      elements_(elements) { }

    /**
     * Access any element of this vector.
     */
    unit_t& operator[] (const size_t i) {
      return elements_[i];
    }
    unit_t operator[] (const size_t i) const {
      return elements_[i];
    }

    /** Return an iterator to the first element in this vector. */
    auto begin() {
      return elements_.begin();
    }
    auto begin() const {
      return elements_.cbegin();
    }

    /** Return an iterator to one past the last element in this vector. */
    auto end() {
      return elements_.end();
    }
    auto end() const {
      return elements_.cend();
    }

    /** Get the x component of the vector. */
    unit_t x() const { return elements_[0]; }
    /** Set the x component of the vector. */
    void x(const unit_t& x) { elements_[0] = x; }

    /** Get the y component of the vector. */
    unit_t y() const { return elements_[1]; }
    /** Set the y component of the vector. */
    void y(const unit_t& y) { elements_[1] = y; }

    /** Get the z component of the vector. */
    unit_t z() const { return elements_[2]; }
    /** Set the z component of the vector. */
    void z(const unit_t& z) { elements_[2] = z; }

    Vector& operator+= (const Vector& rh) {
      for (size_t i = 0; i < N; ++i) {
        this->elements_[i] += rh.elements_[i];
      }
      return *this;
    }

    Vector& operator-= (const Vector& rh) {
      for (size_t i = 0; i < N; ++i) {
        this->elements_[i] -= rh.elements[i];
      }
      return *this;
    }

    Vector& operator*= (const double& rh) {
      std::for_each(elements_.begin(), elements_.end(), [&](unit_t& e) { e *= rh; });
      return *this;
    }

    Vector& operator/= (const double& rh) {
      std::for_each(elements_.begin(), elements_.end(), [rh](const unit_t& e) { e /= rh; });
      return *this;
    }

  private:
    std::array<unit_t, N> elements_;
};

/** Calculate the Euclidean norm of the vector.  */
template<size_t N,
  int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
  int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  UnitBase<MN, LN, TN, CN, TeN, AN, LuN,
  MD, LD, TD, CD, TeD, AD, LuD>
  norm(const Vector<N,
       MN, LN, TN, CN, TeN, AN, LuN,
       MD, LD, TD, CD, TeD, AD, LuD>& in) {
  UnitBase<2*MN, 2*LN, 2*TN, 2*CN, 2*TeN, 2*AN, 2*LuN,
    MD, LD, TD, CD, TeD, AD, LuD> sum;
  for (size_t i = 0; i < N; ++i) {
    sum += in[i]*in[i];
  }
  return sqrt<2*MN, 2*LN, 2*TN, 2*CN, 2*TeN, 2*AN, 2*LuN,
    MD, LD, TD, CD, TeD, AD, LuD>(sum);
}

/** Normalize a vector.
 *
 * \param in The vector to normalize.
 * \return The normalized vector in. 
 */
template<size_t N,
  int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
  int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  Vector<N, 0, 0, 0, 0, 0, 0, 0> normalize(const Vector<N,
                                           MN, LN, TN, CN, TeN, AN, LuN,
                                           MD, LD, TD, CD, TeD, AD, LuD>& in) {
  const auto l = norm(in);
  return Vector<N, 0, 0, 0, 0, 0, 0, 0>(in/l);
}

/** Calculate the infinity norm of a vector. */
template<size_t N,
  int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
  int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  UnitBase<MN, LN, TN, CN, TeN, AN, LuN,
  MD, LD, TD, CD, TeD, AD, LuD>
  norm_inf(const Vector<N,
       MN, LN, TN, CN, TeN, AN, LuN,
       MD, LD, TD, CD, TeD, AD, LuD>& in) {
  UnitBase<MN, LN, TN, CN, TeN, AN, LuN,
    MD, LD, TD, CD, TeD, AD, LuD> ret = abs(in[0]);
  for (size_t i = 0; i < N; ++i) {
    ret = (abs(in[i]) > ret) ? abs(in[i]) : ret;
  }
  return ret;
}

/**
 * Vector<T> inversion operator. 
 */
template<size_t N,
  int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
  int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  Vector<N, MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>
  operator- (const Vector<N, MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh) {
  Vector<N, MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD> ret(lh);
  ret *= -1.0;
  return ret;
}

/**
 * Vector addition operator.
 */
template<size_t N,
  int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
  int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  Vector<N, MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>
  operator+ (const Vector<N, MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh,
             const Vector<N, MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& rh) {
  Vector<N, MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD> ret(lh);
  ret += rh;
  return ret;
}

/**
 * Vector subtraction operator.
 */
template<size_t N,
  int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
  int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  Vector<N, MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>
  operator- (const Vector<N, MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh,
             const Vector<N, MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& rh) {
  Vector<N, MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD> ret(lh);
  ret -= rh;
  return ret;
}

/**
 * Vector multiplication operators
 */
template<size_t N,
  int MN1, int LN1, int TN1, int CN1, int TeN1, int AN1, int LuN1,
  int MD1, int LD1, int TD1, int CD1, int TeD1, int AD1, int LuD1,
  int MN2, int LN2, int TN2, int CN2, int TeN2, int AN2, int LuN2,
  int MD2, int LD2, int TD2, int CD2, int TeD2, int AD2, int LuD2>
  auto
  operator* (const Vector<N, MN1, LN1, TN1, CN1, TeN1, AN1, LuN1, MD1, LD1, TD1, CD1, TeD1, AD1, LuD1>& lh,
             const UnitBase<MN2, LN2, TN2, CN2, TeN2, AN2, LuN2, MD2, LD2, TD2, CD2, TeD2, AD2, LuD2>& rh) {
  Vector<N,
    unitManagement::numa(MN1, MD1, MN2, MD2),
    unitManagement::numa(LN1, LD1, LN2, LD2),
    unitManagement::numa(TN1, TD1, TN2, TD2),
    unitManagement::numa(CN1, CD1, CN2, CD2),
    unitManagement::numa(TeN1, TeD1, TeN2, TeD2),
    unitManagement::numa(AN1, AD1, AN2, AD2),
    unitManagement::numa(LuN1, LuD1, LuN2, LuD2),
    unitManagement::denoma(MN1, MD1, MN2, MD2),
    unitManagement::denoma(LN1, LD1, LN2, LD2),
    unitManagement::denoma(TN1, TD1, TN2, TD2),
    unitManagement::denoma(CN1, CD1, CN2, CD2),
    unitManagement::denoma(TeN1, TeD1, TeN2, TeD2),
    unitManagement::denoma(AN1, AD1, AN2, AD2),
    unitManagement::denoma(LuN1, LuD1, LuN2, LuD2)> ret;

  for (size_t i = 0; i < N; ++i) {
    ret[i] = lh[i] * rh;
  }
  return ret;
}
template<size_t N,
  int MN1, int LN1, int TN1, int CN1, int TeN1, int AN1, int LuN1,
  int MD1, int LD1, int TD1, int CD1, int TeD1, int AD1, int LuD1,
  int MN2, int LN2, int TN2, int CN2, int TeN2, int AN2, int LuN2,
  int MD2, int LD2, int TD2, int CD2, int TeD2, int AD2, int LuD2>
  auto
      operator* (const UnitBase<MN1, LN1, TN1, CN1, TeN1, AN1, LuN1, MD1, LD1, TD1, CD1, TeD1, AD1, LuD1>& lh,
                 const Vector<N, MN2, LN2, TN2, CN2, TeN2, AN2, LuN2, MD2, LD2, TD2, CD2, TeD2, AD2, LuD2>& rh) {
  return rh * lh;
}
template<size_t N,
  int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
  int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  Vector<N, MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>
  operator* (const Vector<N, MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh,
             const double& rh) {
  Vector<N, MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD> ret(lh);
  ret *= rh;
  return ret;
}
template<size_t N,
  int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
  int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  Vector<N, MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>
  operator* (const double& lh,
             const Vector<N, MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& rh) {
  return rh * lh;
}


/**
 * Vector dot product.
 */
template<size_t N,
  int MN1, int LN1, int TN1, int CN1, int TeN1, int AN1, int LuN1,
  int MD1, int LD1, int TD1, int CD1, int TeD1, int AD1, int LuD1,
  int MN2, int LN2, int TN2, int CN2, int TeN2, int AN2, int LuN2,
  int MD2, int LD2, int TD2, int CD2, int TeD2, int AD2, int LuD2>
  auto
  dot(const Vector<N, MN1, LN1, TN1, CN1, TeN1, AN1, LuN1, MD1, LD1, TD1, CD1, TeD1, AD1, LuD1>& lh,
      const Vector<N, MN2, LN2, TN2, CN2, TeN2, AN2, LuN2, MD2, LD2, TD2, CD2, TeD2, AD2, LuD2>& rh) {
  auto ret = lh[0] * rh[0];
  for (size_t i = 1; i < N; ++i) {
    ret += lh[i]*rh[i];
  }
  return ret;
}

/**
 * Vector cross product. (only defined for 3-Vectors
 */
template<int MN1, int LN1, int TN1, int CN1, int TeN1, int AN1, int LuN1,
  int MD1, int LD1, int TD1, int CD1, int TeD1, int AD1, int LuD1,
  int MN2, int LN2, int TN2, int CN2, int TeN2, int AN2, int LuN2,
  int MD2, int LD2, int TD2, int CD2, int TeD2, int AD2, int LuD2>
  auto
  cross(const Vector<3, MN1, LN1, TN1, CN1, TeN1, AN1, LuN1, MD1, LD1, TD1, CD1, TeD1, AD1, LuD1>& lh,
        const Vector<3, MN2, LN2, TN2, CN2, TeN2, AN2, LuN2, MD2, LD2, TD2, CD2, TeD2, AD2, LuD2>& rh) {
  Vector<3,
    unitManagement::numa(MN1, MD1, MN2, MD2),
    unitManagement::numa(LN1, LD1, LN2, LD2),
    unitManagement::numa(TN1, TD1, TN2, TD2),
    unitManagement::numa(CN1, CD1, CN2, CD2),
    unitManagement::numa(TeN1, TeD1, TeN2, TeD2),
    unitManagement::numa(AN1, AD1, AN2, AD2),
    unitManagement::numa(LuN1, LuD1, LuN2, LuD2),
    unitManagement::denoma(MN1, MD1, MN2, MD2),
    unitManagement::denoma(LN1, LD1, LN2, LD2),
    unitManagement::denoma(TN1, TD1, TN2, TD2),
    unitManagement::denoma(CN1, CD1, CN2, CD2),
    unitManagement::denoma(TeN1, TeD1, TeN2, TeD2),
    unitManagement::denoma(AN1, AD1, AN2, AD2),
    unitManagement::denoma(LuN1, LuD1, LuN2, LuD2)> ret;
  ret.x(lh.y()*rh.z() - lh.z()*rh.y());
  ret.y(lh.z()*rh.x() - lh.x()*rh.z());
  ret.z(lh.x()*rh.y() - lh.y()*rh.x());
  return ret;
}

/**
 * Vector division operators
 */
template<size_t N,
  int MN1, int LN1, int TN1, int CN1, int TeN1, int AN1, int LuN1,
  int MD1, int LD1, int TD1, int CD1, int TeD1, int AD1, int LuD1,
  int MN2, int LN2, int TN2, int CN2, int TeN2, int AN2, int LuN2,
  int MD2, int LD2, int TD2, int CD2, int TeD2, int AD2, int LuD2>
  auto
  operator/ (const Vector<N, MN1, LN1, TN1, CN1, TeN1, AN1, LuN1, MD1, LD1, TD1, CD1, TeD1, AD1, LuD1>& lh,
             const UnitBase<MN2, LN2, TN2, CN2, TeN2, AN2, LuN2, MD2, LD2, TD2, CD2, TeD2, AD2, LuD2>& rh) {
  Vector<N,
    unitManagement::nums(MN1, MD1, MN2, MD2),
    unitManagement::nums(LN1, LD1, LN2, LD2),
    unitManagement::nums(TN1, TD1, TN2, TD2),
    unitManagement::nums(CN1, CD1, CN2, CD2),
    unitManagement::nums(TeN1, TeD1, TeN2, TeD2),
    unitManagement::nums(AN1, AD1, AN2, AD2),
    unitManagement::nums(LuN1, LuD1, LuN2, LuD2),
    unitManagement::denoms(MN1, MD1, MN2, MD2),
    unitManagement::denoms(LN1, LD1, LN2, LD2),
    unitManagement::denoms(TN1, TD1, TN2, TD2),
    unitManagement::denoms(CN1, CD1, CN2, CD2),
    unitManagement::denoms(TeN1, TeD1, TeN2, TeD2),
    unitManagement::denoms(AN1, AD1, AN2, AD2),
    unitManagement::denoms(LuN1, LuD1, LuN2, LuD2)> ret;
  for (size_t i = 0; i != N; ++i) {
    ret[i] = lh[i] / rh;
  }
  return ret;
}
template<size_t N,
  int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
  int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  Vector<N, MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>
  operator/ (const Vector<N, MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh,
             const double& rh) {
  Vector<N, MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD> ret(lh);
  std::for_each(ret.begin(), ret.end(), [](auto& e) { e /= rh; });
  return ret;
}

template<size_t N,
  int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
  int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
  bool  operator== (const Vector<N, MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh,
                    const Vector<N, MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& rh) {
  for (size_t i = 0; i < N; ++i) {
    if (lh[i] != rh[i]) { return false; }
  }
  return true;
}

template<size_t N,
  int MN, int LN, int TN, int CN, int TeN, int AN, int LuN,
  int MD, int LD, int TD, int CD, int TeD, int AD, int LuD>
      bool  operator!= (const Vector<N, MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& lh,
                        const Vector<N, MN, LN, TN, CN, TeN, AN, LuN, MD, LD, TD, CD, TeD, AD, LuD>& rh) {
  return !(lh == rh);
}

};  // namespace eng

