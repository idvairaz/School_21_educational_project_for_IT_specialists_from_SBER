#ifndef CPP1_S21_MATRIXPLUS_1_S21MATRIX_H
#define CPP1_S21_MATRIXPLUS_1_S21MATRIX_H
#include <cmath>
#include <iostream>
#include <stdexcept>

using std::abs;
using std::cout;
using std::endl;
using std::invalid_argument;
using std::logic_error;
using std::move;
using std::out_of_range;

namespace myNamespase {

class S21Matrix {
 private:
  int rows_, cols_;
  double **matrix_;

 public:
  /** Конструкторы и деструктор*/

  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other) noexcept;

  ~S21Matrix();

  /** accessor и mutator*/
  int getRows() const;
  void setRows(int rows);
  int getCols() const;
  void setCols(int cols);
  void setElement(int row, int col, double value);

  const double &operator()(int row, int col) const;

  /** Вспомогательные методы*/
  bool isSquare() const;
  bool isHasSameSize(const S21Matrix &other) const;
  bool isValidIndex(int row, int col) const;
  S21Matrix getMinor(int row, int col) const;
  double determinant_recursive(int n) const;

  void allocate_memory();
  void deallocate_memory();
  //  void print_matrix() const;

  /** Библиотека s21_matrix_oop */
  /**  Операции  */

  bool eqMatrix(const S21Matrix &other) const;
  void sumMatrix(const S21Matrix &other);
  void subMatrix(const S21Matrix &other);
  void mulNumber(const double num);
  void mulMatrix(const S21Matrix &other);
  S21Matrix transpose() const;
  double determinant() const;
  S21Matrix calcComplements() const;
  S21Matrix inverseMatrix() const;

  /** Перегрузка операторов  */

  bool operator==(const S21Matrix &other) const;
  S21Matrix &operator=(const S21Matrix &other);
  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix operator+(const S21Matrix &other) const;
  S21Matrix &operator-=(const S21Matrix &other);
  S21Matrix operator-(const S21Matrix &other) const;
  S21Matrix operator*=(double num);
  S21Matrix operator*(double number) const;
  S21Matrix &operator*=(const S21Matrix &other);
  S21Matrix operator*(const S21Matrix &other) const;
};
}  // namespace myNamespase

#endif  // CPP1_S21_MATRIXPLUS_1_S21MATRIX_H
