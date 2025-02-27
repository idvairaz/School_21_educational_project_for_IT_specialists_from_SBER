#ifndef _TEST_H
#define _TEST_H

#include <check.h>
#include <ncurses.h>

#include "../inc/defines.h"
#include "../inc/game_objects.h"
#include "../inc/matrix_and_figures.h"
#include "../inc/scoring.h"
#include "../inc/user_actions.h"

void run_testcase(Suite *testscase, int counter_testcase);
void run_tests();
Suite *level_up_suite(void);
Suite *speed_up_suite(void);
Suite *scoring_suite(void);
Suite *getSingleton_suite(void);
Suite *start_suite(void);
Suite *spawn_suite(void);
Suite *copy_matrix_suite(void);
Suite *set_figure_on_field_suite(void);
Suite *set_next_figure_suite(void);
Suite *generate_figure_suite(void);
Suite *high_score_suite(void);
Suite *game_over_suite(void);
Suite *clear_figure_suite(void);
Suite *attaching_suite(void);
Suite *pause_suite(void);
Suite *left_moving_suite(void);
Suite *right_moving_suite(void);
Suite *updateCurrentState_suite(void);
Suite *moving_suite(void);
Suite *rotate_figure_suite(void);
Suite *inaction_suite(void);
Suite *userInput_suite(void);
Suite *delete_full_line_suite(void);

#endif /*TEST_H*/