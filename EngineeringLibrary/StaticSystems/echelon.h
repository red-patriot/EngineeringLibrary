#pragma once

/*****************************************************************//**
 * \file   echelon.h
 * \brief  Functions to manipulate a matrix into row echelon form and
 *           reduced row echelon form to solve systems of equations. 
 *
 *
 * \author bltan
 * \date   September 2020
 *********************************************************************/

#include <eigen3/Eigen/Core>

namespace eng {
  namespace {

    inline int first_nonzero_index(const Eigen::VectorXd& row) {
      if (row[0] != 0) return 0;
      int ret = 0;
      while (++ret != row.size()) {
        if (row[ret] != 0) break;
      }
      return ret;
    }
  };

  inline Eigen::MatrixXd sort_rows(Eigen::MatrixXd A) {
    std::vector<Eigen::VectorXd> rows;
    for (size_t i = 0; i != A.rows(); ++i) {
      rows.push_back(A.row(i));
    }

    std::sort(rows.begin(), rows.end(),
              [](const Eigen::VectorXd& lh, const Eigen::VectorXd& rh) {
      return first_nonzero_index(lh) < first_nonzero_index(rh);
    });

    for (size_t i = 0; i != A.rows(); ++i) {
      A.row(i) = rows[i];
    }

    return A;
  }

  /**
   * Perform row reduction on the matrix to put it into row echelon form, which 
   *   may not be unique.
   * 
   * \param A The matrix to be row reduced
   * \return The original matrix in row echelon form
   */
  template<int Rows, int Cols>
  Eigen::Matrix<double, Rows, Cols> row_echelon_form
  (Eigen::Matrix<double, Rows, Cols>& A) {
    // put all rows with leading zeros at the end
    A = sort_rows(A);

    // Subtract rows down the matrix
    for (size_t i = 0; i != A.rows() - 1; ++i) {
      for (size_t j = i+1; j != A.rows(); ++j) {
        int k = first_nonzero_index(A.row(i));
        double c = k < A.rows() ? A(j, k) / A(i, k) : 1.0;
        A.row(j) = A.row(j) - A.row(i)*c;
      }
    }

    // divide rows by their leading coefficient
    for (size_t i = 0; i != A.rows(); ++i) {
      int k = first_nonzero_index(A.row(i));
      double c = first_nonzero_index(A.row(i)) < A.rows() ? 1 / A(i, k) : 1.0;
      A.row(i) = A.row(i) * c;
    }

    return A;
  }

  /**
   * Perform row reduction on a copy of the matrix to put it into row echelon 
   *   form, which may not be unique.
   * 
   * \param A The matrix to be row reduced
   * \return The original matrix in row echelon form
   */
  template<int Rows, int Cols>
  [[nodiscard]] Eigen::Matrix<double, Rows, Cols> row_echelon_form_copy
  (Eigen::Matrix<double, Rows, Cols> A) { 
    row_echelon_form(A);
    return A;
  }

  /**
   * Perform row reduction on the matrix to put it into reduced row echelon form.
   * 
   * \param A The matrix to be row reduced
   * \return The copied matrix in row echelon form
   */
  template<int Rows, int Cols>
  Eigen::Matrix<double, Rows, Cols> reduced_row_echelon_form
  (Eigen::Matrix<double, Rows, Cols>& A) {
    // put the matrix in Row Echelon Form first
    A = row_echelon_form<Rows, Cols>(A);

    // Subtract rows up the matrix
    for (size_t i = A.rows() - 1; i != 0; --i) {
      for (size_t j = i - 1; j < A.rows(); --j) {
        double c = A(j, i);
        A.row(j) = A.row(j) - A.row(i)*c;
      }
    }

    return A;
  }

  /**
   * Perform row reduction on a copy of the matrix to put it into reduced row 
   *   echelon form.
   * 
   * \param A The matrix to be row reduced
   * \return The copied matrix in row echelon form
   */
  template<int Rows, int Cols>
  [[nodiscard]] Eigen::Matrix<double, Rows, Cols> reduced_row_echelon_form_copy
  (Eigen::Matrix<double, Rows, Cols> A) { 
    reduced_row_echelon_form(A);
    return A;
  }

}; // namespace eng
