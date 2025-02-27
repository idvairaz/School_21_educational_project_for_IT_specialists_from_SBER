#include "../../inc/state_and_stats.h"

/**
 * @brief Функция инициализирует все необходимые параметры для новой игры.
 *        и загружает сохраненный рекорд из файла.
 * @param init Указатель на структуру `AllGameInfo_t`, в которую будут сохранены
 *        все параметры и состояние игры.
 * @return (void) Функция не возвращает значения.
 */
void game_init(AllGameInfo_t *init) {
  init->field = create_matrix(FIELD_ROWS, FIELD_COLS);
  init->current_figure = create_matrix(FIGURE_SIZE, FIGURE_SIZE);
  init->next = create_matrix(FIGURE_SIZE, FIGURE_SIZE);
  init->y_pos = START_FIELD_ROW;
  init->x_pos = (FIELD_COLS / 2 - FIGURE_SIZE / 2);
  init->level = 1;
  init->score = 0;
  init->speed = 1;
  init->high_score = load_high_score();
  init->pause = 0;
  init->state = START;
  init->ydec_skip_counter = 0;
  init->hold = FALSE;
  generate_figure(init->next, &init->next_figure_type);
  generate_figure(init->current_figure, &init->current_figure_type);
}

/**
 * @brief Функция реализует паттерн Singleton, обеспечивая создание и доступ
 *        к единственному экземпляру структуры AllGameInfo_t на протяжении
 * всего времени работы программы. При первом вызове функции инициализируется
 * статическая переменная all_game_info, которая хранит полные данные о
 * состоянии игры.
 * @return Указатель на единственный экземпляр структуры AllGameInfo_t.
 */
AllGameInfo_t *getSingleton() {
  static AllGameInfo_t all_game_info;
  return &all_game_info;
}

GameInfo_t updateCurrentState() {
  GameInfo_t game_info;
  AllGameInfo_t *all_game_info = getSingleton();
  game_info.field = all_game_info->field;
  game_info.next = all_game_info->next;
  copy_matrix(all_game_info->field, game_info.field, FIELD_ROWS, FIELD_COLS);

  set_figure_on_field(game_info.field, all_game_info->current_figure,
                      all_game_info->x_pos, all_game_info->y_pos);
  copy_matrix(all_game_info->next, game_info.next, FIGURE_SIZE, FIGURE_SIZE);
  game_info.score = all_game_info->score;
  game_info.high_score = all_game_info->high_score;
  game_info.level = all_game_info->level;
  game_info.speed = all_game_info->speed;
  game_info.pause = all_game_info->pause;
  return game_info;
}

/**
 * @brief Функция устанавливает начальный счет игры в 0 и меняет значение поля
 *        'state' (запускает или завершает игру), в зависимости  от значения
 * поля `action` (действия игорока)  в структуре `AllGameInfo_t` устанавливается
 * состояние игры 'state':
 * - action `Start` - состояние изменяется на `SPAWN`,
 * - action`Terminate` - состояние изменяется на `GAMEOVER`,
 *
 * @param all_game_info Указатель на структуру, содержащу всю информацию об
 * игре.
 * @return (void) Не возвращает значения.
 */
void start(AllGameInfo_t *all_game_info) {
  all_game_info->score = 0;

  if (all_game_info->action == Start) {
    all_game_info->state = SPAWN;
  }
  if (all_game_info->action == Terminate) {
    all_game_info->state = GAMEOVER;
  }
}

/**
 * @brief Функция устанавливает первоначальную позицию фигуры на игровом поле,
 *      очистку полных линий и генерацию следующей фигуры. Функция обновляет
 * координаты текущей фигуры и ее тип, а также устанавливает состояние игры
 * в 'MOVING'.
 * @param all_game_info Указатель на структуру, содержащу полную информацию об
 *        игре. Cтруктура `AllGameInfo_t` инициализирована до вызова функции.
 * @return (void) Не возвращает значения.
 */
void spawn(AllGameInfo_t *all_game_info) {
  delete_full_line(all_game_info);

  all_game_info->x_pos = (FIELD_COLS / 2 - FIGURE_SIZE / 2);
  all_game_info->y_pos = START_FIELD_ROW;

  copy_matrix(all_game_info->next, all_game_info->current_figure, FIGURE_SIZE,
              FIGURE_SIZE);
  all_game_info->current_figure_type = all_game_info->next_figure_type;

  generate_figure(all_game_info->next, &all_game_info->next_figure_type);

  all_game_info->state = MOVING;
}

/**
 * @brief Функция устанавливает текущую фигуру  на игровом поле в координатах,
 *        заданных `x_pos` и `y_pos` структуры `AllGameInfo_t` и проверяет,
 * находится ли фигура на стартовой строке поля:
 * - Если `y_pos` = `START_FIELD_ROW, игра переходит в состояние `GAMEOVER`.
 * - В противном случае, состояние меняется на `SPAWN`, указывая на то, что
 * фигура была успешно размещена.
 * @param all_game_info Указатель на структуру, содержащую всю информацию об
 *        игре,
 * @return (void) Функция не возвращает значения.
 */
void attaching(AllGameInfo_t *all_game_info) {
  set_figure_on_field(all_game_info->field, all_game_info->current_figure,
                      all_game_info->x_pos, all_game_info->y_pos);
  if (all_game_info->y_pos == START_FIELD_ROW) {
    all_game_info->state = GAMEOVER;
  } else {
    all_game_info->state = SPAWN;
  }
}

/**
 * @brief Функция управляет состоянием игры в зависимости от действия,
 * указанного в структуре `AllGameInfo_t` в поле `action`. В зависимости от
 * значения поля `action` выполняются следующие действия:
 * - Если действие равно `Terminate`, игра переходит в состояние `GAMEOVER`.
 * - Если действие равно `Pause`, игра переходит в состояние `PAUSE`, и
 * устанавливается флаг паузы.
 * - Если игра не приостановлена, происходит очистка текущей фигуры.
 * - Если действие равно `Left`, вызывается функция для перемещения фигуры
 * влево.
 * - Если действие равно `Right`, вызывается функция для перемещения фигуры
 * вправо.
 * - Если действие равно `Action`, фигура поворачивается.
 * - Если действие равно `Down`, происходит обновление счётчика и установка
 * флага на необходимость сбросить фигуру.
 * - В противном случае, вызывается функция `inaction` для обработки
 * бездействия.
 * @param all_game_info Указатель на структуру, содержащую всю информацию об
 * игре.
 * @return (void) Функция не возвращает значений.
 */
void moving(AllGameInfo_t *all_game_info) {
  if (all_game_info->action == Terminate) all_game_info->state = GAMEOVER;
  if (all_game_info->action == Pause) {
    all_game_info->state = PAUSE;
  } else {
    clear_figure();
    inaction(all_game_info);
    if (all_game_info->state != ATTACHING) {
      if (all_game_info->action == Down && !all_game_info->hold) {
        all_game_info->hold = TRUE;
      }
      if (all_game_info->action == Left) left_moving(all_game_info);
      if (all_game_info->action == Right) right_moving(all_game_info);
      if (all_game_info->action == Action) rotate_figure(all_game_info);
    } else {
      all_game_info->hold = FALSE;
    }
  }
}

/**
 * @brief Функция управляет состоянием игры при выполнении действия паузы.
 *      Если текущее действие `all_game_info->action` равно `Pause`, и игра
 *      находится в состоянии паузы (т.е. `pause` равно 1), функция возобновляет
 *      игру, устанавливая `pause` в 0 и состояние игры в `MOVING`. В противном
 *      случае (если игра не находится в паузе), функция устанавливает состояние
 *      паузы в 1.
 * @param all_game_info Указатель на структуру, содержащую всю информацию об
 *      игре.
 * @return (void) Функция не возвращает значений.
 */
void pause_tetris(AllGameInfo_t *all_game_info) {
  if (all_game_info->pause) {
    if (all_game_info->action == Pause) {
      all_game_info->pause = 0;
      all_game_info->state = MOVING;
    }
  } else {
    all_game_info->pause = 1;
  }
}

/**
 * @brief Обрабатывает завершение игры и обновляет рекорд.
 *     Функция проверяет, превысил ли текущий счёт игрока прежний рекорд. Если
 * да, то обновляет рекорд и сохраняет его с помощью функции `save_high_score`.
 * Затем в зависимости от действия игрока (`action`), либо инициализируется игра
 * заново, либо устанавливается  состояние завершения игры.
 * @param all_game_info Указатель на структуру, содержащую  полную информацию об
 *     игре.
 * @return (void) Функция не возвращает значения.
 */
void game_over(AllGameInfo_t *all_game_info) {
  if (all_game_info->high_score < all_game_info->score) {
    all_game_info->high_score = all_game_info->score;
  }
  save_high_score(all_game_info->high_score);

  if (all_game_info->action == Start) game_init(all_game_info);
  if (all_game_info->action == Terminate) all_game_info->state = TERMINATE;
}

/**
 * @brief Функция для вращения фигуры
 * @param all_game_info Указатель на адрес структуры с полной информацией об
 * игре
 * @return (void) не возвращает значение
 */
void rotate_figure(AllGameInfo_t *all_game_info) {
  struct _figure *figure = figures[all_game_info->current_figure_type];
  int num_rotates = figure->num_rotates;
  num_rotates++;

  if (num_rotates == figure->num_variants) num_rotates = 0;

  int *variants = (int *)figure->variants;
  int *figure_after_rotate = variants + 16 * num_rotates;

  int is_intersect_rotate =
      check_intersect_after_rotate(figure_after_rotate, all_game_info);

  int figure_empty_column_left = calc_empty_column_left(figure_after_rotate);

  int figure_empty_column_right = calc_empty_column_right(figure_after_rotate);

  if (!is_intersect_rotate &&
      !is_intersect_left_edge(all_game_info->x_pos, figure_empty_column_left) &&
      !is_intersect_right_edge(all_game_info->x_pos,
                               figure_empty_column_right)) {
    figure_after_rotate = variants + 16 * num_rotates;
    {
      copy_sample_to_array(figure_after_rotate,
                           &all_game_info->current_figure[0][0],
                           FIGURE_SIZE * FIGURE_SIZE);
      figure->num_rotates = num_rotates;
    }
  }
}

/**
 * @brief Вспомогательная функция для rotate_figure. Копирует массив значений
 *       из одного указателя в другой (copy_matrix).
 * @param ptr_from Указатель на источник данных.
 * @param ptr_arr_to Указатель на массив, в который будут скопированы данные.
 * @param size Количество элементов, подлежащих копированию.
 * @return (void) не возвращает значение.
 */
void copy_sample_to_array(int *ptr_from, int *ptr_arr_to, int size) {
  int *from = ptr_from;
  int *to = ptr_arr_to;

  for (int i = 0; i < size; i++) *to++ = *from++;
}

/**
 * @brief Вспомогательная функция для rotate_figure.
 *        Проверяет наличие пересечений после вращения фигуры.
 * @param sample Указатель на данные фигуры после вращения.
 * @param all_game_info Указатель на структуру с полной информацией об игре.
 * @return 1, если есть пересечение; 0 в противном случае.
 */
int check_intersect_after_rotate(int *sample, AllGameInfo_t *all_game_info) {
  int sample_array[4][4];
  int is_intersect_rotate = 0;

  copy_sample_to_array(sample, &sample_array[0][0], FIGURE_SIZE * FIGURE_SIZE);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (all_game_info->y_pos + i < FIELD_ROWS) {
        is_intersect_rotate +=
            all_game_info
                ->field[all_game_info->y_pos + i][all_game_info->x_pos + j] *
            sample_array[i][j];
      } else {
        if (sample_array[i][j] == 1) {
          is_intersect_rotate += 1;
        }
      }
    }
  }
  return is_intersect_rotate;
}

/**
 * @brief Вспомогательная функция для rotate_figure. Вычисляет количество
 *        пустых колонок слева от фигуры.
 * @param sample Указатель на данные фигуры для анализа.
 * @return Количество пустых колонок слева.
 */
int calc_empty_column_left(int *sample) {
  int sample_array[4][4];
  int x = 0;
  int sum_y = 0;
  int figure_empty_column_left = 0;

  copy_sample_to_array(sample, &sample_array[0][0], FIGURE_SIZE * FIGURE_SIZE);

  while (x < 4 || !sum_y) {
    for (int y = 0; y < 4; y++) {
      sum_y += sample_array[y][x];
    }
    if (!sum_y) figure_empty_column_left += 1;
    x++;
  }

  return figure_empty_column_left;
}

/**
 * @brief Вспомогательная функция для rotate_figure.
 *        Вычисляет количество пустых колонок справа от фигуры.
 * @param sample Указатель на данные фигуры для анализа.
 * @return Количество пустых колонок справа.
 */
int calc_empty_column_right(int *sample) {
  int sample_array[4][4];
  int x = 3;
  int sum_y = 0;
  int figure_empty_column_right = 0;

  copy_sample_to_array(sample, &sample_array[0][0], FIGURE_SIZE * FIGURE_SIZE);

  while (x >= 0 || !sum_y) {
    for (int y = 0; y < 4; y++) {
      sum_y += sample_array[y][x];
    }
    if (!sum_y) {
      figure_empty_column_right += 1;
    }
    x--;
  }
  return figure_empty_column_right;
}