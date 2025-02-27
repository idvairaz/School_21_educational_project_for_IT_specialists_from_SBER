#include "../../inc/matrix_and_figures.h"

/**
 * @brief Функция, которая создает матрицу с выделением памяти.
 *    Общая выделенная память будет вмещать и указатели, и сами элементы.
 * @param rows - колличество рядов
 * @param cols - колличество колонок
 *
 * @return указатель на матрицу или 0, в случае ошибки выделения пвмяти.
 */
int **create_matrix(int rows, int cols) {
  int **matrix =
      (int **)calloc(1, rows * sizeof(int *) + cols * rows * sizeof(int));

  if (matrix == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for matrix.\n");
        return NULL;
    } 
  matrix[0] = (int *)(matrix + rows);
  for (int i = 1; i < rows; i++) {
    matrix[i] = matrix[0] + i * cols;
  }
  return matrix;
}

/**
 * @brief Функция для копирования значений из одной матрицы в другую
 *
 * @param old_matrix указатель на матрицу(оригинал), значения которой надо
 *          скопировать
 * @param new_matrix указатель на матрицу, в которую будут скопированы значения
 *          оригинала
 * @param rows - колличество рядов
 * @param cols - колличество колонок
 *
 * @return (void)не возвращает значение
 */
void copy_matrix(int **old_matrix, int **new_matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      new_matrix[i][j] = old_matrix[i][j];
    }
  }
}

/**
 * @brief Генерирует случайную фигуру и устанавливает её в переданный массив.
 *        Функция выбирает случайный тип фигуры в диапазоне от 0 до 6
 * и устанавливает соответствующую фигуру в указанный двумерный массив.
 * Значение выбранного типа фигуры записывается по адресу, на который указывает
 * параметр next_figure_type.
 *
 * @param figure Двумерный массив, в который будет установлена фигура.
 * @param next_figure_type Указатель на целое число, в которое будет записан
 *                         выбранный тип фигуры.
 */
void generate_figure(int **figure, int *next_figure_type) {
  srand(time(NULL));
  int figure_type = (rand() % 7);
  get_figure(figure_type, figure);
  *next_figure_type = figure_type;
}

/**
 * @brief Получает фигуру по указанному типу и устанавливает её в массив.
 *        Функция использует тип фигуры для извлечения соответствующей
 * фигуры из заранее определённого массива фигур (struct _figure *figures[7])
 * и устанавливает её в предоставленный двумерный массив figure.
 *
 * @param figure_type Тип фигуры, которую нужно получить.
 *                  Должен находиться в диапазоне допустимых типов фигур(0-6).
 * @param figure Двумерный массив, в который будет установлена фигура.
 */
void get_figure(int figure_type, int **figure) {
  set_next_figure(figures[figure_type], figure);
}

/**
 * @brief Функция копирует данные одной из возможных ориентаций фигуры из
 *       структуры _figure в двумерный массив next. Функция использует поле
 * num_rotates для выбора нужной ориентации.
 *
 * @param figure Указатель на структуру _figure, содержащую информацию о фигуре,
 *          включая количество вариантов и их представление.
 * @param next Указатель на двумерный массив (размером FIGURE_SIZE x
 *          FIGURE_SIZE), который будет заполнен значениями, представляющими
 * следующую фигуру в нужной ориентации. Элементы массива next должны быть
 * инициализированы до вызова этой функции.
 *
 * @note
 * - Функция не выполняет проверки на допустимость значения figure->num_rotates.
 *   Убедитесь, что num_rotates находится в пределах от 0 до num_variants.
 * - В случае ошибки данные в массиве next будут непредсказуемыми.
 */
void set_next_figure(struct _figure *figure, int **next) {
  int *variants = (int *)figure->variants;
  int *sample = variants + 16 * figure->num_rotates;
  for (int i = 0; i < FIGURE_SIZE; i++) {
    for (int j = 0; j < FIGURE_SIZE; j++) {
      next[i][j] = *sample++;
    }
  }
}

/**
 * @brief Устанавливает фигуру на игровое поле.
 *              Функция копирует данные фигуры (представленной в виде двумерного
 * массива) на заданную позицию на игровом поле. Если определённая позиция для
 * установки фигуры выходит за границы игрового поля по координате x (x_pos), то
 * эта ячейка поля не изменяется.
 * @param field Указатель на двумерный массив, представляющий игровое поле.
 *              Ожидается, что поле инициализировано соответствующим образом.
 * @param figure Указатель на двумерный массив, представляющий фигуру.
 *              Ожидается, что фигура имеет размер FIGURE_SIZE x FIGURE_SIZE и
 * содержит значения, указывающие на части фигуры (1 для занятых, 0 для пустых).
 * @param x_pos Позиция по координате x для начала установки фигуры.
 *              Если x_pos + j < 0, то фигура не будет установлена в
 * соответствующую ячейку.
 * @param y_pos Позиция по координате y для начала установки фигуры.
 *              Ожидается, что y_pos + i не выходит за границы массива field.
 *
 * @return (void)не возвращает значение
 * @note
 * - В случае, если часть фигуры выходит за пределы поля, соответствующие
 *   значения в поле остаются неизменными.
 * - Функция не выполняет проверки на выход за границы массива field и figure,
 *   поэтому важно, чтобы передаваемые координаты были валидными.
 */
void set_figure_on_field(int **field, int **figure, int x_pos, int y_pos) {
  for (int i = 0; i < FIGURE_SIZE; i++) {
    for (int j = 0; j < FIGURE_SIZE; j++) {
      if (figure[i][j] == 1) {
        if (x_pos + j >= 0) field[y_pos + i][x_pos + j] = 1;
      }
    }
  }
}

/**
 * @brief Функция очищает текущую фигуру с игрового поля.
 *        Получает информацию из единственного экземпляра структуры
 * AllGameInfo_t, определяет позицию текущей фигуры и вызывает вспомогательную
 * функцию clear_figure_on_field, чтобы очистить фигуру с поля.
 *
 * @return (void) Функция не возвращает значений.
 */
void clear_figure() {
  GameInfo_t game_info;
  AllGameInfo_t *all_game_info = getSingleton();
  game_info.field = all_game_info->field;
  clear_figure_on_field(game_info.field, all_game_info->current_figure,
                        all_game_info->x_pos, all_game_info->y_pos);
}

/**
 * @brief Функция убирает фигуру с заданной позиции на игровом поле,
 *        устанавливая значения в соответствующих ячейках на 0. Используется
 * когда фигура больше не нужна (например, когда фигура перемещается).
 *
 * @param field Указатель на двумерный массив (игровое поле), из которого будет
 *        удалена фигура.
 * @param figure Указатель на двумерный массив (фигура), которую требуется
 *        удалить.
 * @param x_pos Позиция x, с которой начинается фигура на поле.
 * @param y_pos Позиция y, с которой начинается фигура на поле.
 * @return (void) Функция не возвращает значения.
 */
void clear_figure_on_field(int **field, int **figure, int x_pos, int y_pos) {
  for (int i = 0; i < FIGURE_SIZE; i++) {
    for (int j = 0; j < FIGURE_SIZE; j++) {
      if (figure[i][j] == 1) {
        field[y_pos + i][x_pos + j] = 0;
      }
    }
  }
}
