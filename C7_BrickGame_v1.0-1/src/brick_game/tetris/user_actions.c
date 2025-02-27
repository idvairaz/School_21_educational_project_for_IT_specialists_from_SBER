#include "../../inc/user_actions.h"

/**
 * @brief Функция для передвижения фигуры вправо
 * @param all_game_info Указатель на адрес структуры с полной информацией об
 * игре
 * @return (void) не возвращает значение
 */
void right_moving(AllGameInfo_t *all_game_info) {
  all_game_info->x_pos++;

  int figure_empty_column =
      num_empty_column_right(all_game_info->current_figure);

  if (is_intersect_right_edge(all_game_info->x_pos, figure_empty_column)) {
    all_game_info->x_pos =
        START_FIELD_COL + FIELD_COLS - 4 + figure_empty_column;
  }

  if (is_intersect(all_game_info, all_game_info->current_figure)) {
    all_game_info->x_pos--;
  }
}
/**
 * @brief Функция для передвижения фигуры влево,если это возможно.
 * @param all_game_info Указатель на структуру с информацией об игре.
 *     В этой функции обновляется позиция фигуры по оси
 * @return (void) не возвращает значение
 */
void left_moving(AllGameInfo_t *all_game_info) {
  all_game_info->x_pos--;

  int figure_empty_column =
      num_empty_column_left(all_game_info->current_figure);

  if (is_intersect_left_edge(all_game_info->x_pos, figure_empty_column)) {
    all_game_info->x_pos = START_FIELD_COL - figure_empty_column;
  }

  if (is_intersect(all_game_info, all_game_info->current_figure)) {
    all_game_info->x_pos++;
  }
}

/**
 * @brief Функция проверяет пересечение между текущей фигурой и игровым полем.
 *
 * @param all_game_info Указатель на структуру с полной информацией об игре.
 * @param figure Двумерный массив, представляющий текущую фигуру.
 *
 * @return Возвращает количество точек пересечения между фигурой и полем.
 * Если фигура не пересекается с полем, возвращает 0.
 */
int is_intersect(AllGameInfo_t *all_game_info, int **figure) {
  int is_intersect_figures = 0;
  int x_pos = all_game_info->x_pos;
  int y_pos = all_game_info->y_pos;

  for (int y = 0; y < 4; y++) {
    if (y_pos + y < FIELD_ROWS) {
      for (int x = 0; x < 4; x++) {
        is_intersect_figures +=
            all_game_info->field[y_pos + y][x_pos + x] * figure[y][x];
      }
    }
  }

  return is_intersect_figures;
}

/**
 * @brief Функция проверяет, пересекается ли фигура с левой границей
 * игрового поля.
 *
 * @param x_pos Позиция фигуры по оси X.
 * @param figure_empty_column Количество пустых колонок слева от фигуры.
 *
 * @return Возвращает 1 (true), если фигура выходит за левую границу,
 * иначе возвращает 0 (false).
 */
int is_intersect_left_edge(int x_pos, int figure_empty_column) {
  return x_pos < START_FIELD_COL - figure_empty_column;
}

/**
 * @brief Функция проверяет, пересекается ли фигура с правой границей
 * игрового поля.
 *
 * @param x_pos Позиция фигуры по оси X.
 * @param figure_empty_column Количество пустых колонок справа от фигуры.
 *
 * @return Возвращает 1 (true), если фигура выходит за левую границу,
 * иначе возвращает 0 (false).
 */
int is_intersect_right_edge(int x_pos, int figure_empty_column) {
  return x_pos > START_FIELD_COL + FIELD_COLS - 4 + figure_empty_column;
}

/**
 * @brief Функция для подсчета количества пустых колонок в фигуре слева.
 *
 * @param figure Двумерный массив, представляющий текущую фигуру.
 *
 * @return Возвращает int figure_empty_column количество пустых колонок слева.
 */
int num_empty_column_left(int **figure) {
  int figure_empty_column = 0;
  int x = 0;
  int sum_y = 0;
  while (x < 4 || !sum_y) {
    for (int y = 0; y < 4; y++) {
      sum_y += figure[y][x];
    }
    if (!sum_y) {
      figure_empty_column += 1;
    }
    x++;
  }

  return figure_empty_column;
}

/**
 * @brief Функция для подсчета количества пустых колонок в фигуре справа.
 *
 * @param figure Двумерный массив, представляющий текущую фигуру.
 *
 * @return Возвращает int figure_empty_column количество пустых колонок справа.
 */
int num_empty_column_right(int **figure) {
  int figure_empty_column = 0;
  int x = 3;
  int sum_y = 0;
  while (x >= 0 || !sum_y) {
    for (int y = 0; y < 4; y++) {
      sum_y += figure[y][x];
    }
    if (!sum_y) {
      figure_empty_column += 1;
    }
    x--;
  }
  return figure_empty_column;
}

bool check_intersect_current_spawn(AllGameInfo_t *all_game_info) {
  bool check_intersect = FALSE;
  int figure_height = 4;
  int y = 3;
  int sum_x = 0;
  while (y >= 0 || !sum_x) {
    for (int x = 0; x < 4; x++) {
      sum_x += all_game_info->current_figure[y][x];
    }
    if (!sum_x) figure_height -= 1;
    y--;
  }
  int is_intersect_figures = 0;
  bool is_intersect_bottom = FALSE;
  int y_pos = all_game_info->y_pos;
  int x_pos = all_game_info->x_pos;

  if (y_pos > FIELD_ROWS - figure_height) {
    is_intersect_bottom = TRUE;
  } else {
    for (int h = 0; h < figure_height; h++) {
      for (int w = 0; w < 4; w++) {
        is_intersect_figures += all_game_info->field[y_pos + h][x_pos + w] *
                                all_game_info->current_figure[h][w];
      }
    }
  }
  if (is_intersect_figures != 0 || is_intersect_bottom) {
    check_intersect = TRUE;
  }
  return check_intersect;
}

void check_attaching(AllGameInfo_t *all_game_info) {
  if (check_intersect_current_spawn(all_game_info)) {
    all_game_info->state = ATTACHING;
    all_game_info->y_pos--;
  }
}
/**
 * @brief Обрабатывает состояние бездействия игрока для текущей фигуры в игре.
 *
 * Эта функция управляет поведением фигуры, когда не происходит никаких
 * действий со стороны игрока. Если счетчик `ydec_skip_counter` меньше или равен
 * нулю, фигура по оси Y перемещается вниз. Если фигура не должна падать,
 * `ydec_skip_counter` устанавливается на 20. ydec_skip_counter нужендля
 * увеличения скорости игры, счетчик уменьшается на значение скорости.
 *
 * Функция также вычисляет высоту фигуры и проверяет, достигает ли она
 * нижней границы игрового поля, а также есть ли пересечение с уже
 * установленными фигурами на игровом поле. Если фигура выходит за пределы
 * или пересекается с другими фигурами, состояние игры меняется на `ATTACHING`,
 * и фигура поднимается на одну позицию обратно.
 *
 * @param all_game_info Указатель на структуру содержащую всю информацию об
 * игре.
 * @return (void) Функция не возвращает значений.
 */
void inaction(AllGameInfo_t *all_game_info) {
  if (all_game_info->ydec_skip_counter <= 0 || all_game_info->hold == TRUE) {
    all_game_info->y_pos++;
    check_attaching(all_game_info);
    all_game_info->ydec_skip_counter = 20;
  } else {
    all_game_info->ydec_skip_counter -= all_game_info->speed;
  }
}

/**
 * @brief Функция принимает действие, которое пользователь хочет выполнить,
 *       и обновляет состояние игры, если не установлен флаг удержания.
 * @param action (ENUM UserAction_t) Действие, которое пользователь
 *      хочет выполнить,
 * @param hold (bool) Флаг, указывающий, удерживается ли текущее действие.
 *      - true, текущее действие не будет обновлено.
 *      - false, текущее действие будет установлено в значение параметра
 *      action.(при активном hold не меняется action в структуре AllGameInfo_t)
 */
void userInput(UserAction_t action, bool hold) {
  AllGameInfo_t *all_game_info = getSingleton();
  if (!hold) all_game_info->action = action;
}