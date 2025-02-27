#include "test.h"

START_TEST(test_left_moving_1) {
  AllGameInfo_t all_game_info;
  all_game_info.x_pos = -1;
  all_game_info.y_pos = 7;
  all_game_info.current_figure = create_matrix(FIGURE_SIZE, FIGURE_SIZE);
  all_game_info.next = create_matrix(FIGURE_SIZE, FIGURE_SIZE);
  all_game_info.field = create_matrix(FIELD_ROWS, FIELD_COLS);

  all_game_info.current_figure[0][0] = 0;
  all_game_info.current_figure[0][1] = 1;
  all_game_info.current_figure[0][2] = 0;
  all_game_info.current_figure[0][3] = 0;

  all_game_info.current_figure[1][0] = 0;
  all_game_info.current_figure[1][1] = 1;
  all_game_info.current_figure[1][2] = 0;
  all_game_info.current_figure[1][3] = 0;

  all_game_info.current_figure[2][0] = 0;
  all_game_info.current_figure[2][1] = 1;
  all_game_info.current_figure[2][2] = 0;
  all_game_info.current_figure[2][3] = 0;

  all_game_info.current_figure[3][0] = 0;
  all_game_info.current_figure[3][1] = 1;
  all_game_info.current_figure[3][2] = 0;
  all_game_info.current_figure[3][3] = 0;

  left_moving(&all_game_info);
  ck_assert_int_eq(all_game_info.x_pos, -1);

  free(all_game_info.current_figure);
  free(all_game_info.field);
  free(all_game_info.next);
}
END_TEST

START_TEST(test_left_moving_2) {
  AllGameInfo_t all_game_info;
  all_game_info.x_pos = 3;
  all_game_info.y_pos = 6;
  all_game_info.current_figure = create_matrix(FIGURE_SIZE, FIGURE_SIZE);
  all_game_info.next = create_matrix(FIGURE_SIZE, FIGURE_SIZE);
  all_game_info.field = create_matrix(FIELD_ROWS, FIELD_COLS);

  all_game_info.field[all_game_info.y_pos][all_game_info.x_pos] = 1;

  all_game_info.current_figure[0][0] = 0;
  all_game_info.current_figure[0][1] = 1;
  all_game_info.current_figure[0][2] = 0;
  all_game_info.current_figure[0][3] = 0;

  all_game_info.current_figure[1][0] = 0;
  all_game_info.current_figure[1][1] = 1;
  all_game_info.current_figure[1][2] = 0;
  all_game_info.current_figure[1][3] = 0;

  all_game_info.current_figure[2][0] = 0;
  all_game_info.current_figure[2][1] = 1;
  all_game_info.current_figure[2][2] = 0;
  all_game_info.current_figure[2][3] = 0;

  all_game_info.current_figure[3][0] = 0;
  all_game_info.current_figure[3][1] = 1;
  all_game_info.current_figure[3][2] = 0;
  all_game_info.current_figure[3][3] = 0;

  left_moving(&all_game_info);
  ck_assert_int_eq(all_game_info.x_pos, 3);

  free(all_game_info.current_figure);
  free(all_game_info.field);
  free(all_game_info.next);
}
END_TEST

START_TEST(test_left_moving_3) {
  AllGameInfo_t all_game_info;
  game_init(&all_game_info);
  all_game_info.x_pos = 3;
  all_game_info.y_pos = 6;

  all_game_info.current_figure[0][0] = 0;
  all_game_info.current_figure[0][1] = 1;
  all_game_info.current_figure[0][2] = 0;
  all_game_info.current_figure[0][3] = 0;

  all_game_info.current_figure[1][0] = 0;
  all_game_info.current_figure[1][1] = 1;
  all_game_info.current_figure[1][2] = 0;
  all_game_info.current_figure[1][3] = 0;

  all_game_info.current_figure[2][0] = 0;
  all_game_info.current_figure[2][1] = 1;
  all_game_info.current_figure[2][2] = 0;
  all_game_info.current_figure[2][3] = 0;

  all_game_info.current_figure[3][0] = 0;
  all_game_info.current_figure[3][1] = 1;
  all_game_info.current_figure[3][2] = 0;
  all_game_info.current_figure[3][3] = 0;

  left_moving(&all_game_info);
  ck_assert_int_eq(all_game_info.x_pos, 2);

  free(all_game_info.current_figure);
  free(all_game_info.field);
  free(all_game_info.next);
}
END_TEST

Suite *left_moving_suite(void) {
  Suite *suite_left_moving = suite_create("left_moving");
  TCase *tcase_core_left_moving = tcase_create("left_moving");
  tcase_add_test(tcase_core_left_moving, test_left_moving_1);
  tcase_add_test(tcase_core_left_moving, test_left_moving_2);
  tcase_add_test(tcase_core_left_moving, test_left_moving_3);

  suite_add_tcase(suite_left_moving, tcase_core_left_moving);
  return suite_left_moving;
}

//////////////////////////////////////////////////

START_TEST(test_right_moving_1) {
  AllGameInfo_t all_game_info;
  game_init(&all_game_info);
  all_game_info.x_pos = 9;
  all_game_info.y_pos = 6;

  all_game_info.field[all_game_info.y_pos][all_game_info.x_pos] = 1;

  all_game_info.current_figure[0][0] = 0;
  all_game_info.current_figure[0][1] = 1;
  all_game_info.current_figure[0][2] = 0;
  all_game_info.current_figure[0][3] = 0;

  all_game_info.current_figure[1][0] = 0;
  all_game_info.current_figure[1][1] = 1;
  all_game_info.current_figure[1][2] = 0;
  all_game_info.current_figure[1][3] = 0;

  all_game_info.current_figure[2][0] = 0;
  all_game_info.current_figure[2][1] = 1;
  all_game_info.current_figure[2][2] = 0;
  all_game_info.current_figure[2][3] = 0;

  all_game_info.current_figure[3][0] = 0;
  all_game_info.current_figure[3][1] = 1;
  all_game_info.current_figure[3][2] = 0;
  all_game_info.current_figure[3][3] = 0;

  right_moving(&all_game_info);
  ck_assert_int_eq(all_game_info.x_pos, 7);

  free(all_game_info.current_figure);
  free(all_game_info.field);
  free(all_game_info.next);
}
END_TEST

Suite *right_moving_suite(void) {
  Suite *suite_right_moving = suite_create("right_moving");
  TCase *tcase_core_right_moving = tcase_create("right_moving");
  tcase_add_test(tcase_core_right_moving, test_right_moving_1);

  suite_add_tcase(suite_right_moving, tcase_core_right_moving);
  return suite_right_moving;
}
//////////////////////////////////////////////////////////////////

START_TEST(test_inaction_1) {
  AllGameInfo_t *all_game_info = getSingleton();
  game_init(all_game_info);
  all_game_info->ydec_skip_counter = 5;
  all_game_info->y_pos = 21;

  inaction(all_game_info);
  ck_assert_int_eq(all_game_info->ydec_skip_counter, 4);

  free(all_game_info->current_figure);
  free(all_game_info->field);
  free(all_game_info->next);
}
END_TEST

Suite *inaction_suite(void) {
  Suite *suite_inaction = suite_create("inaction");
  TCase *tcase_core_inaction = tcase_create("inaction");
  tcase_add_test(tcase_core_inaction, test_inaction_1);

  suite_add_tcase(suite_inaction, tcase_core_inaction);
  return suite_inaction;
}

/////////////////////////////////////////////////////

START_TEST(test_userInput_1) {
  UserAction_t action = Start;
  userInput(action, FALSE);

  ck_assert_int_eq(action, 0);
}
END_TEST

START_TEST(test_userInput_2) {
  UserAction_t action = Start;
  userInput(action, TRUE);
  ck_assert_int_eq(action, 0);
}
END_TEST

Suite *userInput_suite(void) {
  Suite *suite_userInput = suite_create("userInput");
  TCase *tcase_core_userInput = tcase_create("userInput");
  tcase_add_test(tcase_core_userInput, test_userInput_1);
  tcase_add_test(tcase_core_userInput, test_userInput_2);

  suite_add_tcase(suite_userInput, tcase_core_userInput);
  return suite_userInput;
}