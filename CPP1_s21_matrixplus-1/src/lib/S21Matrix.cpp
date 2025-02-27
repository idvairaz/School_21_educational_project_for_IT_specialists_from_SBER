#include "../S21Matrix.h"

using myNamespase::S21Matrix;

/***************************************************************/

/************* Конструкторы и деструктор ***********************/

/***************************************************************/

/**
 * @brief Конструктор по умолчанию (Default constructor).
 * Создает объект S21Matrix размером [1 × 1], заполненный нулями.
 */
S21Matrix::S21Matrix() : rows_(1), cols_(1) {
  //  std::cout << "Конструктор по умолчанию " << endl;
  allocate_memory();
}

/**
 * @brief Параметризованный конструктор (Parameterized Constructor).
 * Создает объект * S21Matrix размером [rows × cols], заполненный нулями.
 * @param rows Количество строк
 * @param cols Количество столбцов
 * @throws std::out_of_range в случае невалидных аргументов.
 */
S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  //  std::cout << "Параметризованный конструктор" << endl;

  if (rows <= 0 || cols <= 0) {
    throw invalid_argument(
        "Значения аргументов (кол-во рядов и колонок) должно быть больше нуля.");
  }
  allocate_memory();
}

/**
 * @brief Конструктор копирования для создания новой матрицы.
 * Создает новую матрицу, копируя значения из переданного объекта S21Matrix.
 *
 * @param other Объект S21Matrix, из которого будут скопированы значения.
 *
 * @return Не возвращает значение. Создает новый объект S21Matrix на основе
 * существующего, обеспечивая безопасность ресурсов и корректное управление
 * памятью.
 * @note вызывать в коде: S21Matrix matrix = other Адреса у матриц будут разные
 */
S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(other.rows_), cols_(other.cols_) {
  //  std::cout << "Конструктор копирования" << endl;

  allocate_memory();
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) matrix_[i][j] = other.matrix_[i][j];
}

/**
 * @brief Конструктор переноса.
 * Cоздает новый объект матрицы, перемещая ресурсы из other объекта типа
 * S21Matrix. При этом ресурсы, принадлежащие  переданному объекту, передаются
 * новому объекту, а переданный  объект обнуляется, чтобы избежать двойного
 * освобождения памяти.
 *
 * @param other Объект матрицы, из которого будут перемещены ресурсы.
 *
 * @return Не возвращает значение. Создает новый объект S21Matrix на основе
 * существующего, обеспечивая безопасность ресурсов и корректное управление
 * памятью.
 *
 * @note вызывать в коде: S21Matrix matrix = (move(other)) std::move — это
 * стандартная функция из библиотеки <utility>. Она используется для
 * преобразования объекта в rvalue-ссылку (временный объект), что позволяет
 * передать его ресурсы другому объекту без копирования. Адрес марицы matrix
 * будет такой же какой был у other
 */
S21Matrix::S21Matrix(S21Matrix &&other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  //  std::cout << "Конструктор переноса" << endl;

  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

/**
 * @brief Деструктор
 * Освобождает память, выделенную для матрицы, вызывая deallocate_memory().
 */
S21Matrix::~S21Matrix() {
  //  std::cout << "деструктор" << endl;
  deallocate_memory();
}

/***************************************************************/

/**************** accessor и mutator ***************************/

/***************************************************************/

/**
 * @brief mutator Устанавливает значение элемента в матрице.
 *
 * Позволяет установить значение указанного элемента матрицы по заданным
 * индексам. Если индексы выходят за пределы размеров матрицы, вызывается
 * исключение std::out_of_range.
 *
 * @param row Индекс строки.
 * @param col Индекс столбца.
 * @param value Значение, которое будет установлено в указанную ячейку матрицы.
 *
 * @throws std::out_of_range Если указанные индексы находятся за пределами
 * массива.
 */
void S21Matrix::setElement(int row, int col, double value) {
  if (!isValidIndex(row, col)) {
    throw out_of_range("Невалидный индекс!");
  }
  matrix_[row][col] = value;
}

/**
 * @brief  accessor Возвращает элемент матрицы по заданным индексам.
 * @param row Индекс строки.
 * @param col Индекс столбца.
 *
 * @throws std::out_of_range Если указанные индексы находятся за пределами
 * массива.
 */
const double &S21Matrix::operator()(int row, int col) const {
  if (!isValidIndex(row, col)) {
    throw std::out_of_range("Невалидный индекс!");
  }
  return matrix_[row][col];
}

int S21Matrix::getRows() const { return rows_; }
void S21Matrix::setRows(int rows) { rows_ = rows; }
int S21Matrix::getCols() const { return cols_; }
void S21Matrix::setCols(int cols) { cols_ = cols; }
