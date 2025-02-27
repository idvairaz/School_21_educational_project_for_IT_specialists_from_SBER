#include "../../inc/front.h"

void print_overlay(void) {
  print_rectangle(0, BOARD_N + 1, 0, BOARD_M + 1);
  print_rectangle(0, BOARD_N + 1, BOARD_M + 2, BOARD_M + HUD_WIDTH + 3);

  print_rectangle(1, 3, BOARD_M + 3, BOARD_M + HUD_WIDTH + 2);
  print_rectangle(4, 6, BOARD_M + 3, BOARD_M + HUD_WIDTH + 2);
  print_rectangle(7, 9, BOARD_M + 3, BOARD_M + HUD_WIDTH + 2);
  print_rectangle(10, 16, BOARD_M + 3, BOARD_M + HUD_WIDTH + 2);
  print_rectangle(17, 20, BOARD_M + 3, BOARD_M + HUD_WIDTH + 2);

  MVPRINTW(2, BOARD_M + 5, "LEVEL ");
  MVPRINTW(5, BOARD_M + 5, "SCORE ");
  MVPRINTW(8, BOARD_M + 5, "SPEED ");
  MVPRINTW(11, BOARD_M + 5, "NEXT");
  MVPRINTW(18, BOARD_M + 5, "HIGH  SCORE");

  MVPRINTW(1, BOARD_M + HUD_WIDTH + 6, " OPERATION");
  MVPRINTW(3, BOARD_M + HUD_WIDTH + 6, "Rotation UP");
  MVPRINTW(4, BOARD_M + HUD_WIDTH + 6, "Left   LEFT");
  MVPRINTW(5, BOARD_M + HUD_WIDTH + 6, "Right RIGHT");
  MVPRINTW(6, BOARD_M + HUD_WIDTH + 6, "Down   DOWN");
  MVPRINTW(7, BOARD_M + HUD_WIDTH + 6, "Pause    BS");
  MVPRINTW(8, BOARD_M + HUD_WIDTH + 6, "Exit    ESC");

  MVPRINTW(BOARD_N / 2, (BOARD_M - INTRO_MESSAGE_LEN) / 2 + 1, INTRO_MESSAGE);
}

void print_rectangle(int top_y, int bottom_y, int left_x, int right_x) {
  mvaddch(BOARDS_BEGIN + (top_y), BOARDS_BEGIN + (left_x), ACS_ULCORNER);

  int i = left_x + 1;

  for (; i < right_x; i++) {
    mvaddch(BOARDS_BEGIN + top_y, BOARDS_BEGIN + i, ACS_HLINE);
  }
  mvaddch(BOARDS_BEGIN + top_y, BOARDS_BEGIN + i, ACS_URCORNER);

  for (i = top_y + 1; i < bottom_y; i++) {
    mvaddch(BOARDS_BEGIN + i, BOARDS_BEGIN + left_x, ACS_VLINE);
    mvaddch(BOARDS_BEGIN + i, BOARDS_BEGIN + right_x, ACS_VLINE);
  }

  mvaddch(BOARDS_BEGIN + bottom_y, BOARDS_BEGIN + left_x, ACS_LLCORNER);
  i = left_x + 1;
  for (; i < right_x; i++) {
    mvaddch(BOARDS_BEGIN + bottom_y, BOARDS_BEGIN + i, ACS_HLINE);
  }
  mvaddch(BOARDS_BEGIN + bottom_y, BOARDS_BEGIN + i, ACS_LRCORNER);
}

void print_stats(GameInfo_t *stats) {
  MVPRINTW(2, BOARD_M + 11, "%d", stats->level);
  MVPRINTW(5, BOARD_M + 11, "%-6d", stats->score);
  MVPRINTW(8, BOARD_M + 11, "%d", stats->speed);
  MVPRINTW(19, BOARD_M + 5, "%-6d", stats->high_score);
}

void print_next(int **next) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (next[i][j] == 1) {
        mvaddch(14 + i, 26 + j * PIXEL_MULT, '[');
        mvaddch(14 + i, 26 + j * PIXEL_MULT + HALF_PIXEL, ']');
      } else {
        mvaddch(14 + i, 26 + j * PIXEL_MULT, ' ');
        mvaddch(14 + i, 26 + j * PIXEL_MULT + HALF_PIXEL, ' ');
      }
    }
  }
}

/**
 * @brief Функция отображает на экране графическое представление положения
          фигур на   игровом поле, где каждая единица (значение 1)
 отрисовывается парой
 * символов "[" и "]", создавая "пиксели", которые имеют ширину в 2 символа
 из-за значения
 * PIXEL_WIDTH,
 * @param field указатель на матрицу), в которой хранятся значения пикселей
 игрового поля
 *        0 – пустой пиксель, 1 – занятый.
 * @return не возвращает значение
 */
void print_game_field(int **field) {
  for (int i = 0; i < FIELD_ROWS; i++) {
    for (int j = 0; j < FIELD_COLS; j++) {
      if (field[i][j] == 1) {
        mvaddch(3 + i, 3 + j * PIXEL_MULT, '[');
        mvaddch(3 + i, 3 + j * PIXEL_MULT + HALF_PIXEL, ']');
      } else {
        mvaddch(3 + i, 3 + j * PIXEL_MULT, ' ');
        mvaddch(3 + i, 3 + j * PIXEL_MULT + HALF_PIXEL, ' ');
      }
    }
  }
}

void print_game_over_ban() {
  MVPRINTW(BOARD_N / 2 - 2, (BOARD_M - 20) / 2 + 1, EMPTY_ROW);
  MVPRINTW(BOARD_N / 2 - 1, (BOARD_M - GAMEOVER_MESSAGE_LEN) / 2 + 1,
           GAMEOVER_MESSAGE);
  MVPRINTW(BOARD_N / 2, (BOARD_M - INTRO_MESSAGE_LEN) / 2 + 1, INTRO_MESSAGE);
  MVPRINTW(BOARD_N / 2 + 1, (BOARD_M - INTRO_MESSAGE_LEN) / 2 + 1,
           EXIT_MESSAGE);
  MVPRINTW(BOARD_N / 2 + 2, (BOARD_M - 20) / 2 + 1, EMPTY_ROW);
}
void print_pause_ban() {
  MVPRINTW(BOARD_N / 2 - 1, (BOARD_M - 20) / 2 + 1, EMPTY_ROW);
  MVPRINTW(BOARD_N / 2, (BOARD_M - PAUSE_MESSAGE_LEN) / 2 + 1, PAUSE_MESSAGE1);
  MVPRINTW(BOARD_N / 2 + 1, (BOARD_M - PAUSE_MESSAGE_LEN) / 2 + 1,
           PAUSE_MESSAGE2);
  MVPRINTW(BOARD_N / 2 + 2, (BOARD_M - 20) / 2 + 1, EMPTY_ROW);
}

void print_start_ban() {
  MVPRINTW(BOARD_N / 2 - 1, (BOARD_M - 20) / 2 + 1, "                    ");
  MVPRINTW(BOARD_N / 2, (BOARD_M - INTRO_MESSAGE_LEN) / 2 + 1, INTRO_MESSAGE);
  MVPRINTW(BOARD_N / 2 + 1, (BOARD_M - 20) / 2 + 1, "                    ");
}