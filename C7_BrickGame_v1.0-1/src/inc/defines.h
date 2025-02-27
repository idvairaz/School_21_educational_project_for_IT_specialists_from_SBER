#ifndef DEFINES_H
#define DEFINES_H

#define GET_USER_INPUT getch()

#define WIN_INIT(time)    \
  do {                    \
    initscr();            \
    noecho();             \
    curs_set(0);          \
    keypad(stdscr, TRUE); \
    timeout(time);        \
  } while (0)

#define MVPRINTW(y, x, ...) \
  mvprintw(BOARDS_BEGIN + (y), BOARDS_BEGIN + (x), __VA_ARGS__)

#define INTRO_MESSAGE "Press ENTER to start"
#define PAUSE_MESSAGE1 "  Press SPACE   "
#define PAUSE_MESSAGE2 "  to continue   "
#define EXIT_MESSAGE "Press ESCAPE to exit"
#define GAMEOVER_MESSAGE "     GAME OVER     "
#define INTRO_MESSAGE_LEN 20
#define PAUSE_MESSAGE_LEN 16
#define EMPTY_ROW "                    "

#define GAMEOVER_MESSAGE_LEN 17

#define ROWS_MAP 14

#define BOARDS_BEGIN 2

#define BOARD_N (ROWS_MAP + MAP_PADDING * 2)
#define BOARD_M 20
#define HUD_WIDTH 15
#define MAP_PADDING 3

#define SUCCESS 0
#define ERROR 1

#define ESCAPE 27
#define ENTER_KEY 10
#define BS 32

#define FIELD_ROWS 20
#define FIELD_COLS 10
#define START_FIELD_ROW 0
#define START_FIELD_COL 0
#define FIGURE_SIZE 4

#define HALF_PIXEL 1
#define PIXEL_MULT 2

#endif