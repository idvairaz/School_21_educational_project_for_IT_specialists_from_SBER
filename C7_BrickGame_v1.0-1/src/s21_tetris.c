#include "inc/front.h"
#include "inc/tetris.h"

int main(void) {
  WIN_INIT(50);
  print_overlay();
  game_loop();
  endwin();

  return SUCCESS;
}

void game_loop() {
  GameInfo_t game_info;
  UserAction_t user_action;
  AllGameInfo_t *all_game_info = getSingleton();
  game_init(all_game_info);

  while (all_game_info->state != TERMINATE) {
    game_info = updateCurrentState();
    print_stats(&game_info);
    user_action = get_signal();
    userInput(user_action, all_game_info->hold);

    switch (all_game_info->state) {
      case START:
        print_start_ban();
        start(all_game_info);
        break;

      case SPAWN:
        spawn(all_game_info);
        print_next(all_game_info->next);
        break;

      case MOVING:
        print_game_field(all_game_info->field);
        moving(all_game_info);
        break;

      case ATTACHING:
        attaching(all_game_info);
        break;

      case GAMEOVER:
        print_game_over_ban();
        game_over(all_game_info);
        break;

      case PAUSE:
        print_pause_ban();
        pause_tetris(all_game_info);
        break;

      default:
        break;
    }
    refresh();
  }

  free(all_game_info->field);
  free(all_game_info->next);
  free(all_game_info->current_figure);

  return;
}
