#ifndef _USER_ACTION_H
#define _USER_ACTION_H

#include "tetris.h"

void userInput(UserAction_t action, bool hold);
UserAction_t get_signal();

void left_moving(AllGameInfo_t *allgame_Info);
int num_empty_column_left(int **figure);
int num_empty_column_right(int **figure);
int is_intersect_left_edge(int x_pos, int figure_empty_column);
int is_intersect_right_edge(int x_pos, int figure_empty_column);
int is_intersect(AllGameInfo_t *all_game_info, int **figure);
void right_moving(AllGameInfo_t *all_game_info);
void inaction(AllGameInfo_t *all_game_info);

#endif