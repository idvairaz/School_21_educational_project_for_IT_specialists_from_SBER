#include "test.h"

int main() {
  run_tests();
  return 0;
}

void run_testcase(Suite *testscase, int counter_testcase) {
  if (counter_testcase > 1) putchar('\n');
  printf("Test %d:\n", counter_testcase);

  SRunner *sr = srunner_create(testscase);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);  // изменить CK_ENV на CK_VERBOSE , для более
                                // подробного вывода информации о тестах
  srunner_free(sr);
}
void run_tests() {
  int counter_testcase = 0;
  Suite *list_cases[] = {level_up_suite(),
                         speed_up_suite(),
                         scoring_suite(),
                         getSingleton_suite(),
                         start_suite(),
                         spawn_suite(),
                         copy_matrix_suite(),
                         set_figure_on_field_suite(),
                         set_next_figure_suite(),
                         generate_figure_suite(),
                         high_score_suite(),
                         game_over_suite(),
                         clear_figure_suite(),
                         attaching_suite(),
                         pause_suite(),
                         left_moving_suite(),
                         right_moving_suite(),
                         updateCurrentState_suite(),
                         moving_suite(),
                         rotate_figure_suite(),
                         inaction_suite(),
                         userInput_suite(),
                         delete_full_line_suite(),
                         NULL};

  for (Suite **testcase = list_cases; *testcase; testcase++) {
    run_testcase(*testcase, ++counter_testcase);
  }
}
