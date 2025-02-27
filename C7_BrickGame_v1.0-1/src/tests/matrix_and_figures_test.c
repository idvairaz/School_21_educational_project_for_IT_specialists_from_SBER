#include "test.h"

START_TEST(test_copy_matrix_1) {
  int **old_matrix = create_matrix(FIGURE_SIZE, FIGURE_SIZE);

  for (int i = 0; i < FIGURE_SIZE; i++) {
    for (int j = 0; j < FIGURE_SIZE; j++) {
      old_matrix[i][j] = i * FIGURE_SIZE + j;
    }
  }

  int **new_matrix = create_matrix(FIGURE_SIZE, FIGURE_SIZE);

  copy_matrix(old_matrix, new_matrix, FIGURE_SIZE, FIGURE_SIZE);

  for (int i = 0; i < FIGURE_SIZE; i++) {
    for (int j = 0; j < FIGURE_SIZE; j++) {
      ck_assert_int_eq(new_matrix[i][j], old_matrix[i][j]);
    }
  }
  free(old_matrix);
  free(new_matrix);
}

END_TEST

Suite *copy_matrix_suite(void) {
  Suite *suite_copy_matrix = suite_create("copy_matrix");
  TCase *tcase_core_copy_matrix = tcase_create("copy_matrix");
  tcase_add_test(tcase_core_copy_matrix, test_copy_matrix_1);

  suite_add_tcase(suite_copy_matrix, tcase_core_copy_matrix);
  return suite_copy_matrix;
}

//////////////////////////////////////////////////

START_TEST(test_set_figure_on_field_1) {
  int **field = create_matrix(FIELD_ROWS, FIELD_COLS);
  int **figure = create_matrix(FIELD_ROWS, FIELD_COLS);

  set_next_figure(figures[1], figure);

  int x_pos = (FIELD_COLS / 2 - FIGURE_SIZE / 2);
  int y_pos = START_FIELD_ROW;

  set_figure_on_field(field, figure, x_pos, y_pos);

  for (int i = 0; i < FIGURE_SIZE; i++) {
    for (int j = 0; j < FIGURE_SIZE; j++) {
      if (figure[i][j] == 1) {
        ck_assert_int_eq(field[y_pos + i][x_pos + j], 1);
      } else {
        ck_assert_int_eq(field[y_pos + i][x_pos + j], 0);
      }
    }
  }
  free(field);
  free(figure);
}
END_TEST

START_TEST(test_set_figure_on_field_2) {
  int **field = create_matrix(FIELD_ROWS, FIELD_COLS);
  int **figure = create_matrix(FIELD_ROWS, FIELD_COLS);

  set_next_figure(figures[1], figure);

  int x_pos = -10;
  int y_pos = START_FIELD_ROW;

  set_figure_on_field(field, figure, x_pos, y_pos);

  for (int i = 0; i < FIELD_ROWS; i++) {
    for (int j = 0; j < FIELD_COLS; j++) {
      ck_assert_int_eq(field[i][j], 0);
    }
  }
  free(field);
  free(figure);
}
END_TEST

Suite *set_figure_on_field_suite(void) {
  Suite *suite_set_figure_on_field = suite_create("set_figure_on_field");
  TCase *tcase_core_set_figure_on_field = tcase_create("set_figure_on_field");
  tcase_add_test(tcase_core_set_figure_on_field, test_set_figure_on_field_1);
  tcase_add_test(tcase_core_set_figure_on_field, test_set_figure_on_field_2);

  suite_add_tcase(suite_set_figure_on_field, tcase_core_set_figure_on_field);
  return suite_set_figure_on_field;
}
///////////////////////////////////////////////////////////

START_TEST(test_set_next_figure_1) {
  int **next = create_matrix(FIELD_ROWS, FIELD_COLS);
  int **expected = create_matrix(FIELD_ROWS, FIELD_COLS);

  expected[0][0] = 0;
  expected[0][1] = 1;
  expected[0][2] = 0;
  expected[0][3] = 0;

  expected[1][0] = 0;
  expected[1][1] = 1;
  expected[1][2] = 0;
  expected[1][3] = 0;

  expected[2][0] = 0;
  expected[2][1] = 1;
  expected[2][2] = 0;
  expected[2][3] = 0;

  expected[3][0] = 0;
  expected[3][1] = 1;
  expected[3][2] = 0;
  expected[3][3] = 0;

  figures[1]->num_rotates = 1;

  set_next_figure(figures[1], next);

  for (int i = 0; i < FIGURE_SIZE; i++) {
    for (int j = 0; j < FIGURE_SIZE; j++) {
      ck_assert_int_eq(next[i][j], expected[i][j]);
    }
  }
  free(next);
  free(expected);
}
END_TEST

Suite *set_next_figure_suite(void) {
  Suite *suite_set_next_figure = suite_create("set_next_figure");
  TCase *tcase_core_set_next_figure = tcase_create("set_next_figure");
  tcase_add_test(tcase_core_set_next_figure, test_set_next_figure_1);

  suite_add_tcase(suite_set_next_figure, tcase_core_set_next_figure);
  return suite_set_next_figure;
}

//////////////////////////////////////////////////

START_TEST(test_generate_figure_1) {
  int **figure = create_matrix(FIELD_ROWS, FIELD_COLS);
  int next_figure_type;

  generate_figure(figure, &next_figure_type);

  int expected_0 = 0;
  int expected_6 = 6;

  ck_assert_int_ge(next_figure_type, expected_0);
  ck_assert_int_le(next_figure_type, expected_6);

  free(figure);
}
END_TEST

Suite *generate_figure_suite(void) {
  Suite *suite_generate_figure = suite_create("generate_figure");
  TCase *tcase_core_generate_figure = tcase_create("generate_figure");
  tcase_add_test(tcase_core_generate_figure, test_generate_figure_1);

  suite_add_tcase(suite_generate_figure, tcase_core_generate_figure);
  return suite_generate_figure;
}
///////////////////////////////////////////////////////////////////

START_TEST(test_clear_figure_1) {
  AllGameInfo_t *all_game_info = getSingleton();

  all_game_info->x_pos = 3;
  all_game_info->y_pos = 0;

  all_game_info->field = create_matrix(FIELD_ROWS, FIELD_COLS);
  all_game_info->current_figure = create_matrix(FIGURE_SIZE, FIGURE_SIZE);

  for (int i = 0; i < FIELD_ROWS; i++) {
    for (int j = 0; j < FIELD_COLS; j++) {
      all_game_info->field[i][j] = 0;
    }
  }

  for (int i = 0; i < FIGURE_SIZE; i++) {
    for (int j = 0; j < FIGURE_SIZE; j++) {
      all_game_info->current_figure[i][j] = 1;
    }
  }

  set_figure_on_field(all_game_info->field, all_game_info->current_figure,
                      all_game_info->x_pos, all_game_info->y_pos);
  clear_figure();

  for (int i = 0; i < FIELD_ROWS; i++) {
    for (int j = 0; j < FIELD_COLS; j++) {
      ck_assert_int_eq(all_game_info->field[i][j], 0);
    }
  }

  free(all_game_info->field);
  free(all_game_info->current_figure);
}
END_TEST

Suite *clear_figure_suite(void) {
  Suite *suite_clear_figure = suite_create("clear_figure");
  TCase *tcase_core_clear_figure = tcase_create("clear_figure");
  tcase_add_test(tcase_core_clear_figure, test_clear_figure_1);

  suite_add_tcase(suite_clear_figure, tcase_core_clear_figure);
  return suite_clear_figure;
}