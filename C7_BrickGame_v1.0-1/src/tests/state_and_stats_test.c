#include "test.h"

START_TEST(test_getSingleton_1) {
  AllGameInfo_t *instance_1 = getSingleton();
  AllGameInfo_t *instance_2 = getSingleton();

  ck_assert_ptr_eq(instance_1, instance_2);
}
END_TEST

Suite *getSingleton_suite(void) {
  Suite *suite_getSingleton = suite_create("getSingleton");
  TCase *tcase_core_getSingleton = tcase_create("getSingleton");
  tcase_add_test(tcase_core_getSingleton, test_getSingleton_1);

  suite_add_tcase(suite_getSingleton, tcase_core_getSingleton);
  return suite_getSingleton;
}
///////////////////////////////////////////////////////////////////

START_TEST(test_start_1) {
  AllGameInfo_t game_info;
  game_info.action = Start;

  start(&game_info);

  ck_assert_int_eq(game_info.state, SPAWN);
}
END_TEST

START_TEST(test_start_2) {
  AllGameInfo_t game_info;
  game_info.action = Terminate;

  start(&game_info);

  ck_assert_int_eq(game_info.state, GAMEOVER);
}
END_TEST

Suite *start_suite(void) {
  Suite *suite_start = suite_create("start");
  TCase *tcase_core_start = tcase_create("start");
  tcase_add_test(tcase_core_start, test_start_1);
  tcase_add_test(tcase_core_start, test_start_2);

  suite_add_tcase(suite_start, tcase_core_start);
  return suite_start;
}
/////////////////////////////////////////////////////////////////

START_TEST(test_spawn_1) {
  AllGameInfo_t game_info;

  game_info.next = create_matrix(FIGURE_SIZE, FIGURE_SIZE);
  game_info.current_figure = create_matrix(FIGURE_SIZE, FIGURE_SIZE);
  game_info.field = create_matrix(FIELD_ROWS, FIELD_COLS);

  spawn(&game_info);
  int expected_x = 3;
  int expected_y = 0;

  ck_assert_int_eq(game_info.x_pos, expected_x);
  ck_assert_int_eq(game_info.y_pos, expected_y);

  free(game_info.next);
  free(game_info.field);
  free(game_info.current_figure);
}
END_TEST

START_TEST(test_spawn_2) {
  AllGameInfo_t game_info;

  game_info.next = create_matrix(FIGURE_SIZE, FIGURE_SIZE);
  game_info.current_figure = create_matrix(FIGURE_SIZE, FIGURE_SIZE);
  game_info.field = create_matrix(FIELD_ROWS, FIELD_COLS);

  spawn(&game_info);

  ck_assert_int_eq(game_info.state, MOVING);

  free(game_info.next);
  free(game_info.field);
  free(game_info.current_figure);
}
END_TEST

Suite *spawn_suite(void) {
  Suite *suite_spawn = suite_create("spawn");
  TCase *tcase_core_spawn = tcase_create("spawn");
  tcase_add_test(tcase_core_spawn, test_spawn_1);
  tcase_add_test(tcase_core_spawn, test_spawn_2);

  suite_add_tcase(suite_spawn, tcase_core_spawn);
  return suite_spawn;
}
//////////////////////////////////////////////

START_TEST(test_game_over_1) {
  AllGameInfo_t game_info;
  game_info.action = Terminate;

  game_over(&game_info);

  ck_assert_int_eq(game_info.state, TERMINATE);
}
END_TEST

START_TEST(test_game_over_2) {
  AllGameInfo_t game_info;
  game_info.action = Start;

  game_over(&game_info);

  ck_assert_int_eq(game_info.state, START);

  free(game_info.next);
  free(game_info.field);
  free(game_info.current_figure);
}
END_TEST

START_TEST(test_game_over_3) {
  AllGameInfo_t game_info;
  game_info.high_score = 600;
  game_info.score = 500;

  game_over(&game_info);

  ck_assert_int_eq(game_info.high_score, 600);
}
END_TEST

Suite *game_over_suite(void) {
  Suite *suite_game_over = suite_create("game_over");
  TCase *tcase_core_game_over = tcase_create("game_over");
  tcase_add_test(tcase_core_game_over, test_game_over_1);
  tcase_add_test(tcase_core_game_over, test_game_over_2);
  tcase_add_test(tcase_core_game_over, test_game_over_3);

  suite_add_tcase(suite_game_over, tcase_core_game_over);
  return suite_game_over;
}
////////////////////////////////////////////////////////////////////

START_TEST(test_attaching_1) {
  AllGameInfo_t all_game_info;
  all_game_info.y_pos = 5;
  all_game_info.next = create_matrix(FIGURE_SIZE, FIGURE_SIZE);
  all_game_info.current_figure = create_matrix(FIGURE_SIZE, FIGURE_SIZE);
  attaching(&all_game_info);

  ck_assert_int_eq(all_game_info.state, SPAWN);

  free(all_game_info.next);
  free(all_game_info.current_figure);
}
END_TEST

START_TEST(test_attaching_2) {
  AllGameInfo_t all_game_info;
  all_game_info.y_pos = START_FIELD_ROW;
  all_game_info.next = create_matrix(FIGURE_SIZE, FIGURE_SIZE);
  all_game_info.current_figure = create_matrix(FIGURE_SIZE, FIGURE_SIZE);
  attaching(&all_game_info);

  ck_assert_int_eq(all_game_info.state, GAMEOVER);

  free(all_game_info.next);
  free(all_game_info.current_figure);
}
END_TEST

Suite *attaching_suite(void) {
  Suite *suite_attaching = suite_create("attaching");
  TCase *tcase_core_attaching = tcase_create("attaching");
  tcase_add_test(tcase_core_attaching, test_attaching_1);
  tcase_add_test(tcase_core_attaching, test_attaching_2);
  suite_add_tcase(suite_attaching, tcase_core_attaching);

  return suite_attaching;
}
//////////////////////////////////////////////////////////////

START_TEST(test_pause_1) {
  AllGameInfo_t all_game_info;
  all_game_info.action = Pause;
  all_game_info.pause = 0;

  pause_tetris(&all_game_info);

  ck_assert_int_eq(all_game_info.pause, 1);
}
END_TEST

START_TEST(test_pause_2) {
  AllGameInfo_t all_game_info;
  all_game_info.action = Pause;
  all_game_info.pause = 1;

  pause_tetris(&all_game_info);

  ck_assert_int_eq(all_game_info.state, 3);
}
END_TEST

Suite *pause_suite(void) {
  Suite *suite_pause = suite_create("pause");
  TCase *tcase_core_pause = tcase_create("pause");
  tcase_add_test(tcase_core_pause, test_pause_1);
  tcase_add_test(tcase_core_pause, test_pause_2);

  suite_add_tcase(suite_pause, tcase_core_pause);

  return suite_pause;
}

//////////////////////////////////////////////

START_TEST(test_updateCurrentState_1) {
  AllGameInfo_t *all_game_info = getSingleton();

  game_init(all_game_info);

  GameInfo_t game_info = updateCurrentState(all_game_info);

  ck_assert_int_eq(game_info.level, 1);

  free(all_game_info->next);
  free(all_game_info->field);
  free(all_game_info->current_figure);
}
END_TEST

Suite *updateCurrentState_suite(void) {
  Suite *suite_updateCurrentState = suite_create("updateCurrentState");
  TCase *tcase_core_updateCurrentState = tcase_create("updateCurrentState");
  tcase_add_test(tcase_core_updateCurrentState, test_updateCurrentState_1);

  suite_add_tcase(suite_updateCurrentState, tcase_core_updateCurrentState);

  return suite_updateCurrentState;
}

//////////////////////////////////////////////////

START_TEST(test_moving_1) {
  AllGameInfo_t *all_game_info = getSingleton();
  game_init(all_game_info);

  all_game_info->action = Terminate;
  moving(all_game_info);

  ck_assert_int_eq(all_game_info->state, 5);

  free(all_game_info->next);
  free(all_game_info->field);
  free(all_game_info->current_figure);
}
END_TEST

START_TEST(test_moving_2) {
  AllGameInfo_t *all_game_info = getSingleton();

  game_init(all_game_info);
  all_game_info->action = Pause;

  moving(all_game_info);

  ck_assert_int_eq(all_game_info->state, PAUSE);

  free(all_game_info->next);
  free(all_game_info->field);
  free(all_game_info->current_figure);
}
END_TEST

START_TEST(test_moving_3) {
  AllGameInfo_t *all_game_info = getSingleton();
  game_init(all_game_info);

  all_game_info->action = Left;
  moving(all_game_info);

  ck_assert_int_eq(all_game_info->x_pos, 2);

  free(all_game_info->current_figure);
  free(all_game_info->field);
  free(all_game_info->next);
}
END_TEST

START_TEST(test_moving_4) {
  AllGameInfo_t *all_game_info = getSingleton();
  game_init(all_game_info);

  all_game_info->ydec_skip_counter = 10;
  all_game_info->action = Down;

  moving(all_game_info);

  ck_assert_int_eq(all_game_info->ydec_skip_counter, 9);

  free(all_game_info->current_figure);
  free(all_game_info->field);
  free(all_game_info->next);
}
END_TEST

START_TEST(test_moving_5) {
  AllGameInfo_t *all_game_info = getSingleton();
  game_init(all_game_info);

  all_game_info->action = Right;
  moving(all_game_info);

  ck_assert_int_eq(all_game_info->x_pos, 4);

  free(all_game_info->current_figure);
  free(all_game_info->field);
  free(all_game_info->next);
}
END_TEST

START_TEST(test_moving_6) {
  AllGameInfo_t *all_game_info = getSingleton();
  game_init(all_game_info);

  all_game_info->action = Action;
  moving(all_game_info);

  ck_assert_int_eq(all_game_info->x_pos, 3);

  free(all_game_info->current_figure);
  free(all_game_info->field);
  free(all_game_info->next);
}
END_TEST

Suite *moving_suite(void) {
  Suite *suite_moving = suite_create("moving");
  TCase *tcase_core_moving = tcase_create("moving");
  tcase_add_test(tcase_core_moving, test_moving_1);
  tcase_add_test(tcase_core_moving, test_moving_2);
  tcase_add_test(tcase_core_moving, test_moving_3);
  tcase_add_test(tcase_core_moving, test_moving_4);
  tcase_add_test(tcase_core_moving, test_moving_5);
  tcase_add_test(tcase_core_moving, test_moving_6);

  suite_add_tcase(suite_moving, tcase_core_moving);
  return suite_moving;
}

/////////////////////////////////////////////////

START_TEST(test_rotate_figure_1) {
  AllGameInfo_t *all_game_info = getSingleton();
  game_init(all_game_info);

  struct _figure *figure = figures[all_game_info->current_figure_type];
  int num_rotates_before = figure->num_rotates;

  for (int i = 0; i < FIELD_ROWS; i++) {
    for (int j = 0; j < FIELD_COLS; j++) {
      all_game_info->field[i][j] = 1;
    }
  }
  rotate_figure(all_game_info);

  int num_rotates_after = figure->num_rotates;

  ck_assert_int_eq(num_rotates_before, num_rotates_after);

  free(all_game_info->current_figure);
  free(all_game_info->field);
  free(all_game_info->next);
}
END_TEST

START_TEST(test_rotate_figure_2) {
  AllGameInfo_t *all_game_info = getSingleton();
  game_init(all_game_info);

  struct _figure *figure = figures[all_game_info->current_figure_type];
  int num_rotates_before = figure->num_rotates;

  for (int i = 0; i < FIELD_ROWS; i++) {
    for (int j = 0; j < FIELD_COLS; j++) {
      all_game_info->field[i][j] = 0;
    }
  }

  rotate_figure(all_game_info);

  int num_rotates_after = figure->num_rotates;
  ck_assert_int_ne(num_rotates_before, num_rotates_after);

  free(all_game_info->current_figure);
  free(all_game_info->field);
  free(all_game_info->next);
}
END_TEST

START_TEST(test_rotate_figure_3) {
  AllGameInfo_t *all_game_info = getSingleton();
  game_init(all_game_info);

  struct _figure *figure = figures[all_game_info->current_figure_type];
  int num_rotates_before = figure->num_rotates;

  for (int i = 0; i < FIELD_ROWS; i++) {
    for (int j = 0; j < FIELD_COLS; j++) {
      all_game_info->field[i][j] = 1;
    }
  }
  rotate_figure(all_game_info);

  int num_rotates_after = figure->num_rotates;

  ck_assert_int_eq(num_rotates_before, num_rotates_after);

  free(all_game_info->current_figure);
  free(all_game_info->field);
  free(all_game_info->next);
}
END_TEST

START_TEST(test_rotate_figure_4) {
  AllGameInfo_t *all_game_info = getSingleton();
  game_init(all_game_info);

  struct _figure *figure = figures[all_game_info->current_figure_type];
  int num_rotates_before = figure->num_rotates;

  for (int i = 0; i < FIELD_ROWS; i++) {
    for (int j = 0; j < FIELD_COLS; j++) {
      all_game_info->field[i][j] = 0;
    }
  }

  rotate_figure(all_game_info);

  int num_rotates_after = figure->num_rotates;
  ck_assert_int_ne(num_rotates_before, num_rotates_after);

  free(all_game_info->current_figure);
  free(all_game_info->field);
  free(all_game_info->next);
}
END_TEST

Suite *rotate_figure_suite(void) {
  Suite *suite_rotate_figure = suite_create("rotate_figure");
  TCase *tcase_core_rotate_figure = tcase_create("rotate_figure");
  tcase_add_test(tcase_core_rotate_figure, test_rotate_figure_1);
  tcase_add_test(tcase_core_rotate_figure, test_rotate_figure_2);
  tcase_add_test(tcase_core_rotate_figure, test_rotate_figure_3);
  tcase_add_test(tcase_core_rotate_figure, test_rotate_figure_4);

  suite_add_tcase(suite_rotate_figure, tcase_core_rotate_figure);
  return suite_rotate_figure;
}