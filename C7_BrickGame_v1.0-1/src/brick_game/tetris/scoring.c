#include "../../inc/scoring.h"

/**
 * @brief Функция для начисления очков в игре, зависящее
 *        от количества уничтоженных заполненных линий
 *  1 линия — 100 очков;
 *  2 линии — 300 очков;
 *  3 линии — 700 очков;
 *  4 линии — 1500 очков.
 *
 * Функция также отвечает за повышение уровня игры и
 * увеличение скорости, если это необходимо после начисления очков
 *
 * @param all_game_info указатель на адрес структуры, содержащую полную
 *        информацию о текущем состоянии игры
 * @param cnt_together_rows int индекс массива score_for_rows, указывает
 *        на кол-во уничтоженных заполненных линий (0 - 4). Значение по
 * этому индексу - кол-во очков, которое прибавится к текущуму счету.
 *
 * @return (void)не возвращает значение
 */
void scoring(AllGameInfo_t *all_game_info, int cnt_together_rows) {
  all_game_info->score += score_for_rows[cnt_together_rows];
  level_up(all_game_info);
  speed_up(all_game_info);
}

/**
 * @brief Функция для повышения счета, которое зависит от колличества очков,
 *        когда игрок набирает 600 очков, уровень увеличивается на 1.
 *        Максимальное количество уровней — 10.
 * @param all_game_info указатель на адрес структуры, содержащую полную
 *        информацию о текущем состоянии игры
 * @return (void)не возвращает значение
 */
void level_up(AllGameInfo_t *all_game_info) {
  if (all_game_info->score >= 600 && all_game_info->score < 1200)
    all_game_info->level = 2;
  if (all_game_info->score >= 1200 && all_game_info->score < 1800)
    all_game_info->level = 3;
  if (all_game_info->score >= 1800 && all_game_info->score < 2400)
    all_game_info->level = 4;
  if (all_game_info->score >= 2400 && all_game_info->score < 3000)
    all_game_info->level = 5;
  if (all_game_info->score >= 3000 && all_game_info->score < 3600)
    all_game_info->level = 6;
  if (all_game_info->score >= 3600 && all_game_info->score < 4200)
    all_game_info->level = 7;
  if (all_game_info->score >= 4200 && all_game_info->score < 4800)
    all_game_info->level = 8;
  if (all_game_info->score >= 4800 && all_game_info->score < 5400)
    all_game_info->level = 9;
  if (all_game_info->score >= 5400) all_game_info->level = 10;
}

/**
 * @brief Функция для повышения скорости движения фигур в игре, зависит
 *      от текущего уровня игры. Макс. скорость и количество уровней - 10.
 * @param all_game_info указатель на адрес структуры, содержащую полную
 *       информацию о текущем состоянии игры
 * @return (void)не возвращает значение
 */
void speed_up(AllGameInfo_t *all_game_info) {
  all_game_info->speed = all_game_info->level;
}

/**
 * @brief Функция  сохраняет максимальный счет в файл "high_score.txt".
 *        Если файл не удается открыть, выводит сообщение об ошибке
 * @param high_score Значение максимального счета, которое будет сохранено в
 *        файл.
 * @return (void) не возвращает значение
 */
void save_high_score(int high_score) {
  FILE *file = fopen("high_score.txt", "w+");

  if (file != NULL) {
    fprintf(file, "%d", high_score);
    fclose(file);
    // } else {
    //   printf("ERROR opening file to write max count.\n");
  }
}

/**
 * @brief Функция считывает из файла "high_score.txt" и загружает в игру
 *        максимальный счет.
 *  Если файл  не может быть открыт, выводится сообщение об ошибке и
 *  максимальный счет устанавливается в 0.
 * @return Возвращаемое значение int:
 *                      - 0 (чтение не удалось);
 *                      - Значение максимального счета, загруженное из файла.
 */
int load_high_score() {
  int high_score = 0;
  FILE *file = fopen("high_score.txt", "r+");

  if (file != NULL) {
    fscanf(file, "%d", &high_score);
    fclose(file);
  } else {
    printf("ERROR opening file to read max count. Set max count to 0.\n");
  }
  return high_score;
}

/**
 * @brief Функция проверяет каждую линию игрового поля на заполненность
 *        и удаляет их, сдвигая все строки выше вниз. Также обновляет счет
 * игрока в зависимости от количества удаленных линий за раз.
 *
 * @param all_game_info Указатель на структуру AllGameInfo_t, содержащую всю
 *        информацию об игре
 * @note Функция начинает проверку с нижней строки и работает вверх. Счет
 *       обновляется после удаления линий, если встречена неполная линия.
 */
void delete_full_line(AllGameInfo_t *all_game_info) {
  int cnt_together_rows = 0;
  int row = FIELD_ROWS - 1;

  while (row > 0) {
    int is_row_full = 1;
    for (int col = 0; col < FIELD_COLS; col++) {
      is_row_full *= all_game_info->field[row][col];
    }
    if (is_row_full) {
      for (int r = row - 1; r > 0; r--) {
        for (int c = 0; c < FIELD_COLS; c++) {
          all_game_info->field[r + 1][c] = all_game_info->field[r][c];
        }
      }
      cnt_together_rows++;
    } else {
      row--;
      scoring(all_game_info, cnt_together_rows);
      cnt_together_rows = 0;
    }
  }
}