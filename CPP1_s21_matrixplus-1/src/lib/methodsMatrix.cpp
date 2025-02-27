/************** Библиотека s21_matrix_oop *********************/
/********************** Операции **************************/

#include "../S21Matrix.h"

using myNamespase::S21Matrix;

/**
 * @brief Сравнивает текущую матрицу с другой (other) матрицей на равенство.
 *
 * Метод проверяет, имеют ли две матрицы одинаковые размеры,
 * а затем сравнивает ЗНАЧЕНИЯ элементов на соответствующих позициях.
 *
 * @param other Ссылка на другую матрицу, с которой будет производиться
 * сравнение.
 * @return true - матрицы равны (одинаковые размеры и элементы).
 *         false - матрицы не равны (размеры или элементы различаются).
 */
bool S21Matrix::eqMatrix(const S21Matrix &other) const {
  if (isHasSameSize(other)) {
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        double diff = fabs(matrix_[i][j] - other.matrix_[i][j]);
        if (diff >= 1e-7) return false;
      }
    }
    return true;
  } else {
    return false;
  }
}

/**
 * @brief Суммирует текущую матрицу с другой (other) матрицей.
 *
 * Метод добавляет элементы другой матрицы к элементам текущей матрицы.
 * Оба матричных объекта должны иметь одинаковый размер для выполнения
 * операции. Если размеры матриц не совпадают, операция не выполняется.
 *
 * @param other Ссылка на другую матрицу типа S21Matrix, с которой нужно
 * выполнить сложение.
 * @throw std::invalid_argument при разных размерах матриц
 */
void S21Matrix::sumMatrix(const S21Matrix &other) {
  if (isHasSameSize(other)) {
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        matrix_[i][j] += other.matrix_[i][j];
      }
    }
  } else {
    throw std::invalid_argument(
        "Матрицы должны иметь одинаковую размеренность!");
  }
}

/**
 * @brief Вычитает другую (other) матрицу из текущей матрицы.
 *
 * Метод вычитает элементы другой матрицы из элементов текущей матрицы.
 * Обе матрицы должны иметь одинаковый размер для выполнения операции.
 * В случае несоответствия размеров операция не выполняется.
 *
 * @param other Ссылка на другую (other) матрицу типа S21Matrix, которую  нужно
 * вычесть.
 * @throw std::invalid_argument при разных размерах матриц
 */
void S21Matrix::subMatrix(const S21Matrix &other) {
  if (isHasSameSize(other)) {
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        matrix_[i][j] -= other.matrix_[i][j];
      }
    }
  } else {
    throw invalid_argument("Матрицы должны иметь одинаковую размернность!");
  }
}

/**
 * @brief Умножает каждый элемент матрицы на заданное число вещественного типа.
 * @param num число вещественного типа на которое нужно умножать элементы
 * матрицы
 * @return void не возвращает значение
 */
void S21Matrix::mulNumber(const double num) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] *= num;
    }
  }
}

/**
 * @brief Умножает текущую матрицу на другую (other) матрицу.
 *
 * Этот метод выполняет умножение текущей матрицы (I множитель) на матрицу
 * `other` (II множитель). Чтобы операция была корректной, количество столбцов
 * текущей матрицы должно совпадать с количеством строк матрицы `other`. В
 * противном случае выбрасывается исключение.
 *
 * @param other Матрица, на которую производится умножение.
 * @throw logic_error Если количество столбцов текущей матрицы не совпадает
 * с количеством строк матрицы `other`.
 *
 * @details
 * Метод создает новую матрицу `result` размером (rows_, other.getCols()),
 * инициализируя ее нулями. Затем он вычисляет значения для каждой ячейки
 * в результирующей матрице, применяя стандартный алгоритм умножения матриц:
 * для каждого элемента результата происходит сумма произведений соответствующих
 * элементов по строке текущей матрицы и по столбцу матрицы `other`.
 *
 * После завершения вычислений текущая матрица заменяется на результат
 * умножения.
 */
void S21Matrix::mulMatrix(const S21Matrix &other) {
  if (cols_ != other.getRows()) {
    throw logic_error(
        "Не корректная размерность матриц, кол-во колонок I множителя должно "
        "совпадать с кол-вом рядов II множителя");
  }
  S21Matrix result{rows_, other.getCols()};

  for (int i = 0; i < result.getRows(); ++i) {
    for (int j = 0; j < result.getCols(); ++j) {
      for (int k = 0; k < cols_; ++k) {
        result.setElement(
            i, j, (result.matrix_[i][j] + matrix_[i][k] * other.matrix_[k][j]));
      }
    }
  }
  *this = move(result);
}

/**
 * @brief Транспонирует матрицу.
 *
 * Этот метод создает и возвращает новую матрицу, которая является
 * транспонированной версией текущей матрицы. В новой матрице строки
 * становятся столбцами и наоборот.
 *
 * @return S21Matrix Объект матрицы, представляющий транспонированную версию
 * текущей матрицы.
 * @warning !!! Т.К метод возвращает новый объект, а не меняет текущий,
 * результат его выпполнения нужно присваивать новому объекту: S21Matrix A(3,
 * 2); S21Matrix B(2, 3); B = A.transpose();
 */
S21Matrix S21Matrix::transpose() const {
  S21Matrix result(cols_, rows_);

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      result.setElement(j, i, matrix_[i][j]);
    }
  }
  return result;
}

/**
 * @brief Вычисляет определитель квадратной матрицы.
 *
 * Mетод использует вспоиогательный метод determinant_recursive(int row).
 * @throws std::logic_error Если  матрица не квадратная.
 * (Проверка в конструкторе)
 */
double S21Matrix::determinant() const {
  if (!isSquare()) {
    throw logic_error(
        "Вычисление определителя возможно только у квадратной матрицы.");
  }
  return determinant_recursive(rows_);
}

/**
 * @brief Вычисляет матрицу алгебраических дополнений для квадратной матрицы.
 *
 * @return S21Matrix Возвращает матрицу алгебраических дополнений.
 * @throws std::invalid_argument Если матрица не квадратная.
 */
S21Matrix S21Matrix::calcComplements() const {
  if (!isSquare()) {
    throw invalid_argument(
        "Вычисление матрицы алгебраических дополнений возможно только у "
        "квадратной матрицы..");
  }
  S21Matrix complements(rows_, cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      S21Matrix subMatrix(rows_ - 1, cols_ - 1);
      for (int subI = 0; subI < rows_ - 1; ++subI) {
        for (int subJ = 0; subJ < cols_ - 1; ++subJ) {
          subMatrix.matrix_[subI][subJ] =
              matrix_[subI >= i ? subI + 1 : subI][subJ >= j ? subJ + 1 : subJ];
        }
      }
      complements.matrix_[i][j] =
          (i + j) % 2 == 0 ? subMatrix.determinant() : -subMatrix.determinant();
    }
  }
  return complements;
}

/**
 *  @brief Вычисляет обратную матрицу для квадратной матрицы.
 *  Если обе проверки прошли успешно, функция создает и
 *  заполняет матрицу дополнений, вызывая метод `calcComplements()`.
 *  Далее создается временная матрица `invers`, которая инициализируется
 *  результатом транспонирования матрицы дополнений, что производится
 *  методом `transpose()`.
 *  Далее все элементы матрицы `invers` умножаются на обратное значение
 *  определителя `det`, чтобы получить искомую обратную матрицу.
 *
 * @return S21Matrix Возвращает обратную матрицу.
 * @throws std::invalid_argument Если матрица не квадратная.
 * @throws std::logic_error Если определитель матрицы равен 0, что делает
 * матрицу необратимой.
 */
S21Matrix S21Matrix::inverseMatrix() const {
  if (!isSquare())
    throw invalid_argument(
        "Вычисление обратной матрицы возможно только у квадратной матрицы.");
  double det = determinant();
  if (abs(det) < 1e-6)
    throw logic_error(
        "Обратная матрица не существует, так как определитель равен 0.");
  S21Matrix calk(rows_, cols_);
  calk = calcComplements();
  S21Matrix invers(rows_, cols_);
  invers = calk.transpose();
  invers.mulNumber(1.0 / det);

  return invers;
}
