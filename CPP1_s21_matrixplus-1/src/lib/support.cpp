/**************** Вспомогательные методы **********************/

#include "../S21Matrix.h"

using myNamespase::S21Matrix;

/**
 * @brief Проверяет квадратная ли матрица
 *
 * @param row Количество строк матрицы.
 * @param col Количество столбцов матрицы.
 * @return true - матрица квадратная.
 *         false - в противном случае.
 */
bool S21Matrix::isSquare() const { return rows_ == cols_; }

/**
 * @brief Проверяет, находятся ли индексы строк и столбцов в допустимых
 * границах.
 * @param row индекс строки.
 * @param col индекс колонки.
 * @return
 *    true - если индексы действующие;
 *    false - в противном случае.
 */
bool S21Matrix::isValidIndex(int row, int col) const {
  return row >= 0 && row < rows_ && col >= 0 && col < cols_;
}

/**
 * @brief Проверяет, имеют ли две матрицы одинаковые размеры.
 * Mетод сравнивает количество строк и столбцов текущей матрицы
 * с количеством строк и столбцов переданной матрицы.
 *
 * @param other Ссылается на другую матрицу типа S21Matrix, которую нужно
 * сравнить с текущей матрицей.
 * @return
 *    true - если обе матрицы имеют одинаковое количество строк и столбцов;
 *    false - в противном случае.
 */
bool S21Matrix::isHasSameSize(const S21Matrix &other) const {
  return rows_ == other.rows_ && cols_ == other.cols_;
}

/**
 * @brief Метод для выделения памяти и инициализации матрицы нулями
 * @return void
 */
void S21Matrix::allocate_memory() {
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_]{0};
  }
}

/**
 * @brief Освобождает память, выделенную для матрицы.
 * @return void
 * @note Этот метод должен вызываться в деструкторе класса, чтобы
 * гарантировать отсутствие утечек памяти при уничтожении объекта S21Matrix.
 */
void S21Matrix::deallocate_memory() {
  for (int i = 0; i < rows_; ++i) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
}

/**
 * @brief Вычисляет определитель квадратной матрицы.
 *
 * Mетод использует рекурсивный подход для вычисления определителя матрицы
 * размерности n. Для матриц размерности 1 возвращает элемент матрицы, для
 * матриц размерности 2 вычисляет определитель по формуле ad - bc. Для матриц
 * большего размера метод использует разложение по первой строке, создавая
 * подматрицы (minor) и рекурсивно вычисляя их определители.
 *
 * @param n Размерность квадратной матрицы.
 * @return double Определитель матрицы в виде числа с плавающей запятой.
 *
 * @throws std::invalid_argument Если размерность матрицы не больше 0.
 * (Проверка в конструкторе)
 */
double S21Matrix::determinant_recursive(int n) const {
  if (n == 1) {
    return matrix_[0][0];
  }
  if (n == 2) {
    return matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  }
  double det = 0.0;
  for (int col = 0; col < n; col++) {
    S21Matrix minor = getMinor(0, col);
    double sub_det = minor.determinant();
    det += (col % 2 == 0 ? 1 : -1) * matrix_[0][col] * sub_det;
  }
  return det;
}

/**
 * @brief Вычисляет минор для данной матрицы. Исключая строку и столбец,
 * указанные параметрами `row` и `col`.
 * (Минор представляет собой матрицу меньшего размера, которая включает
 * все элементы исходной матрицы, кроме тех, что находятся в указанной
 * строке и столбце.
 *
 * @param row Индекс строки, которую нужно исключить
 * @param col Индекс столбца, который нужно исключить
 *
 * @return S21Matrix Возвращает новую матрицу, представляющую минор.
 *
 * @throw std::out_of_range Если значения `row` или `col` находятся
 * вне диапазона существующих индексов матрицы.
 * @throw std::invalid_argument Если размеры матрицы меньше 2, так как
 * невозможно вычислить минор для матрицы размером 1x1 или 1xN.
 */
S21Matrix S21Matrix::getMinor(int row, int col) const {
  if (!isValidIndex(row, col))
    throw out_of_range("Индексы для вычисления минора матрицы невалидные");
  int minor_i = 0, minor_j = 0;
  S21Matrix minor(rows_ - 1, cols_ - 1);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      if (i != row && j != col) {
        minor.setElement(minor_i, minor_j, matrix_[i][j]);
        minor_j++;
        if (minor_j == minor.getCols()) {
          minor_j = 0;
          minor_i++;
        }
      }
    }
  }
  return minor;
}

/**
 * @brief Метод для вывода  матрицы в терминал
 * @return void
 * @note Требуется только  в целях разработки.
 */
// void S21Matrix::print_matrix() const {
//   for (int i = 0; i < rows_; ++i) {
//     for (int j = 0; j < cols_; ++j) {
//       std::cout << matrix_[i][j] << " ";
//     }
//     std::cout << std::endl;
//   }
// }
