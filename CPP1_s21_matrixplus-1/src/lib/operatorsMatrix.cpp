/************** Библиотека s21_matrix_oop *********************/
/****************** Перегрузка операторов *********************/

#include "../S21Matrix.h"

using myNamespase::S21Matrix;

/**
 * @note
 * в C++ оператор == и метод equals выполняют разные функции.
 * Оператор == в C++ по умолчанию сравнивает указатели, если не перегружен.
 *
 * В библиотеке s21_matrix_oop перегружается.
 * Вызывать в коде: M1 == M2;
 */
bool S21Matrix::operator==(const S21Matrix &other) const {
  return eqMatrix(other);
}

/**
 * @note
 * Перегрузка Оператора "=".
 * @brief Этот оператор позволяет присваивать значения одной матрицы другой.
 * Оператор реализует глубокое копирование, то есть создает отдельную копию
 данных,
 * а не только копирует указатели. Сначала освобождает существующие ресурсы,
 * затем выделяет память заново и копирует элементы

 * @param const S21Matrix &other Константная ссылка на другой объект матрицы,
 * значения которого будут скопированы в текущую матрицу.
 * @return  ссылку на текущий объект S21Matrix (*this), что позволяет
 осуществлять цепочку присваиваний.
 * @note
 * Вызывать в коде: S21Matrix m1(3, 3);
                    S21Matrix m2; // базовый конструктор, размеренность другая
                    m2 = m1;
 */
S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (this == &other) {
    return *this;
  }
  deallocate_memory();
  rows_ = other.rows_;
  cols_ = other.cols_;
  allocate_memory();

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
  return *this;
}
/**
 * @note
 * Перегрузка оператора сложения.
 * Сложение двух матриц.
 * Выполняет сложение двух матриц.
 *
 * @return result Возвращает новую матрицу - результат сложения.
 * @throw std::invalid_argument при разных размерах матриц
 * @note Вызывать в коде: S21Matrix mNew = M1 + M2;
 */
S21Matrix S21Matrix::operator+(const S21Matrix &other) const {
  if (!isHasSameSize(other)) {
    throw std::invalid_argument(
        "Матрицы должны иметь одинаковую размеренность!");
  }
  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      result.matrix_[i][j] = matrix_[i][j] + other.matrix_[i][j];
    }
  }
  return result;
}

/**
 * @note
 * Перегрузка оператора сложения.
 * Присвоение сложения.
 * Выполняет сложение текущей матрицы и другой (other), используя метод
 * sumMatrix.
 *
 * @return Возвращает ссылку на текущий объект (для возможности цепочечного
 * вызова (например, a += b += c)).
 * @note Вызывать в коде: M1 += M2;
 */
S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  sumMatrix(other);
  return *this;
}

/**
 * @note
 * Перегрузка оператора вычитания.
 * Выполняет вычитание другой (other) матрицы из текущей (первой в выражении).
 *
 * @return result Возвращает новую матрицу - результат вычитания.
 * @throw std::invalid_argument при разных размерах матриц
 * @note Вызывать в коде: S21Matrix mNew = curent - other;
 */
S21Matrix S21Matrix::operator-(const S21Matrix &other) const {
  if (!isHasSameSize(other)) {
    throw std::invalid_argument(
        "Матрицы должны иметь одинаковую размеренность!");
  }
  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      result.matrix_[i][j] = matrix_[i][j] - other.matrix_[i][j];
    }
  }
  return result;
}
/**
 * @note
 * Перегрузка оператора рвзности.
 * Присвоение рвзности.
 * Выполняет вычитание из текущей матрицы другой (other), используя метод
 * subMatrix.
 *
 * @return Возвращает ссылку на текущий объект (для возможности цепочечного
 * вызова (например, a -= b -= c)).
 * @note Вызывать в коде: M1 -= M2;
 */
S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  subMatrix(other);
  return *this;
}

/**
 * @note
 * Перегрузка оператора умножения.
 * Присвоение умножения.
 * Выполняет умножения текущей матрицы на заданное число вещественного типа
 * используя метод mulNumber.
 *
 * @param num Число, на которое будет умножена текущая матрица.
 *
 * @return Возвращает текущий объект
 * @note Вызывать в коде: M1 *= M2;
 */
S21Matrix S21Matrix::operator*=(double num) {
  mulNumber(num);
  return *this;
}

/**
 * @brief Перегрузка оператора умножения для умножения матрицы на
 * заданное число вещественного типа.
 *
 * Создается новая матрица, в которой каждый элемент исходной матрицы
 * умножается на переданное число.
 *
 * @param number Вещественного типа, на которое будет произведено умножение.
 * @return S21Matrix Новая матрица - результат умножения.
 */
S21Matrix S21Matrix::operator*(const double number) const {
  S21Matrix result{*this};
  result.mulNumber(number);
  return result;
}

/**
 * @note
 * Перегрузка оператора умножения.
 * Присвоение умножения.
 * Выполняет умножения текущей матрицы на другую (other) матрицу
 * и сохраняет результат в текущей матрице используя метод mulNumber.
 *
 * @param other Другя матрица, на которую будет умножена текущая матрица.
 *
 * @return S21Matrix& Ссылку на текущую матрицу после умножения.
 * @note Вызывать в коде: M1 *= M2;
 */
S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  mulMatrix(other);
  return *this;
}

/**
 * @note
 * Перегрузка оператора умножения для перемножения двух матриц.
 *
 * Данный оператор позволяет перемножить текущую матрицу с другой
 * матрицей. Результат умножения возвращается в виде новой матрицы.
 *
 * @param other Вторая матрица, с которой будет произведено
 * умножение.
 * @return S21Matrix Новая матрица - результат умножения двух матриц.
 */
S21Matrix S21Matrix::operator*(const S21Matrix &other) const {
  S21Matrix result{*this};
  result.mulMatrix(other);
  return result;
}
