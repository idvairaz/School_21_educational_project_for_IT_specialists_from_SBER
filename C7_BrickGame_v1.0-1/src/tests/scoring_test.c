#include "test.h"

START_TEST(test_level_up_0) {
  AllGameInfo_t game_info;
  game_info.score = 599;
  game_info.level = 0;

  level_up(&game_info);

  int expected = 0;
  ck_assert_int_eq(game_info.level, expected);
}
END_TEST

START_TEST(test_level_up_1) {
  AllGameInfo_t game_info;
  game_info.score = 600;
  game_info.level = 0;

  level_up(&game_info);

  int expected = 2;
  ck_assert_int_eq(game_info.level, expected);
}
END_TEST

START_TEST(test_level_up_2) {
  AllGameInfo_t game_info;
  game_info.score = 1210;
  game_info.level = 0;

  level_up(&game_info);

  int expected = 3;
  ck_assert_int_eq(game_info.level, expected);
}
END_TEST

START_TEST(test_level_up_3) {
  AllGameInfo_t game_info;
  game_info.score = 1220;
  game_info.level = 0;

  level_up(&game_info);

  int expected = 3;
  ck_assert_int_eq(game_info.level, expected);
}
END_TEST

START_TEST(test_level_up_4) {
  AllGameInfo_t game_info;
  game_info.score = 1810;
  game_info.level = 0;

  level_up(&game_info);

  int expected = 4;
  ck_assert_int_eq(game_info.level, expected);
}
END_TEST

START_TEST(test_level_up_5) {
  AllGameInfo_t game_info;
  game_info.score = 2445;
  game_info.level = 0;

  level_up(&game_info);

  int expected = 5;
  ck_assert_int_eq(game_info.level, expected);
}
END_TEST

START_TEST(test_level_up_6) {
  AllGameInfo_t game_info;
  game_info.score = 3010;
  game_info.level = 0;

  level_up(&game_info);

  int expected = 6;
  ck_assert_int_eq(game_info.level, expected);
}
END_TEST

START_TEST(test_level_up_7) {
  AllGameInfo_t game_info;
  game_info.score = 3650;
  game_info.level = 0;

  level_up(&game_info);

  int expected = 7;
  ck_assert_int_eq(game_info.level, expected);
}
END_TEST

START_TEST(test_level_up_8) {
  AllGameInfo_t game_info;
  game_info.score = 4799;
  game_info.level = 0;

  level_up(&game_info);

  int expected = 8;
  ck_assert_int_eq(game_info.level, expected);
}
END_TEST

START_TEST(test_level_up_9) {
  AllGameInfo_t game_info;
  game_info.score = 4800;
  game_info.level = 0;

  level_up(&game_info);

  int expected = 9;
  ck_assert_int_eq(game_info.level, expected);
}
END_TEST

START_TEST(test_level_up_10) {
  AllGameInfo_t game_info;
  game_info.score = 6789;
  game_info.level = 0;

  level_up(&game_info);

  int expected = 10;
  ck_assert_int_eq(game_info.level, expected);
}
END_TEST

Suite *level_up_suite(void) {
  Suite *suite_level_up = suite_create("level_up");
  TCase *tcase_core_level_up = tcase_create("level_up");
  tcase_add_test(tcase_core_level_up, test_level_up_0);
  tcase_add_test(tcase_core_level_up, test_level_up_1);
  tcase_add_test(tcase_core_level_up, test_level_up_2);
  tcase_add_test(tcase_core_level_up, test_level_up_3);
  tcase_add_test(tcase_core_level_up, test_level_up_4);
  tcase_add_test(tcase_core_level_up, test_level_up_5);
  tcase_add_test(tcase_core_level_up, test_level_up_6);
  tcase_add_test(tcase_core_level_up, test_level_up_7);
  tcase_add_test(tcase_core_level_up, test_level_up_8);
  tcase_add_test(tcase_core_level_up, test_level_up_9);
  tcase_add_test(tcase_core_level_up, test_level_up_10);

  suite_add_tcase(suite_level_up, tcase_core_level_up);
  return suite_level_up;
}

START_TEST(test_speed_up_1) {
  AllGameInfo_t game_info;
  game_info.speed = 0;
  game_info.level = 1;

  speed_up(&game_info);

  int expected = 1;
  ck_assert_int_eq(game_info.speed, expected);
}
END_TEST

START_TEST(test_speed_up_2) {
  AllGameInfo_t game_info;
  game_info.speed = 0;
  game_info.level = 9;

  speed_up(&game_info);

  int expected = 9;
  ck_assert_int_eq(game_info.speed, expected);
}
END_TEST

Suite *speed_up_suite(void) {
  Suite *suite_speed_up = suite_create("speed_up");
  TCase *tcase_core_speed_up = tcase_create("speed_up");
  tcase_add_test(tcase_core_speed_up, test_speed_up_1);
  tcase_add_test(tcase_core_speed_up, test_speed_up_2);

  suite_add_tcase(suite_speed_up, tcase_core_speed_up);
  return suite_speed_up;
}

START_TEST(test_scoring_1) {
  AllGameInfo_t game_info;

  game_info.score = 0;
  game_info.level = 0;

  scoring(&game_info, 3);

  int expected = 700;
  ck_assert_int_eq(game_info.score, expected);
}
END_TEST

START_TEST(test_scoring_2) {
  AllGameInfo_t game_info;

  game_info.score = 5000;
  game_info.level = 0;
  game_info.speed = 0;

  scoring(&game_info, 4);

  int expected = 10;
  ck_assert_int_eq(game_info.speed, expected);
}
END_TEST

Suite *scoring_suite(void) {
  Suite *suite_scoring = suite_create("scoring");
  TCase *tcase_core_scoring = tcase_create("scoring");
  tcase_add_test(tcase_core_scoring, test_scoring_1);
  tcase_add_test(tcase_core_scoring, test_scoring_2);

  suite_add_tcase(suite_scoring, tcase_core_scoring);
  return suite_scoring;
}

START_TEST(test_high_score_1) {
  remove("high_score.txt");

  int score_to_test = 12345;

  save_high_score(score_to_test);

  int loaded_score = load_high_score();

  ck_assert_int_eq(score_to_test, loaded_score);
}
END_TEST

START_TEST(test_high_score_2) {
  remove("high_score.txt");

  int loaded_score = load_high_score();

  ck_assert_int_eq(loaded_score, 0);
}
END_TEST

Suite *high_score_suite(void) {
  Suite *suite_high_score = suite_create("high_score");
  TCase *tcase_core_high_score = tcase_create("high_score");
  tcase_add_test(tcase_core_high_score, test_high_score_1);
  tcase_add_test(tcase_core_high_score, test_high_score_2);

  suite_add_tcase(suite_high_score, tcase_core_high_score);
  return suite_high_score;
}

////////////////////////////////////////////////////////////

START_TEST(test_delete_full_line_1) {
  AllGameInfo_t game_info;
  game_info.field = create_matrix(FIELD_ROWS, FIELD_COLS);
  for (int i = 0; i < FIELD_ROWS; i++) {
    game_info.field[5][i] = 1;
  }

  delete_full_line(&game_info);

  ck_assert_int_eq(game_info.field[5][5], 0);
}
END_TEST

Suite *delete_full_line_suite(void) {
  Suite *suite_delete_full_line = suite_create("delete_full_line");
  TCase *tcase_core_delete_full_line = tcase_create("delete_full_line");
  tcase_add_test(tcase_core_delete_full_line, test_delete_full_line_1);

  suite_add_tcase(suite_delete_full_line, tcase_core_delete_full_line);
  return suite_delete_full_line;
}