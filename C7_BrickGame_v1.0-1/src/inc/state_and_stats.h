#ifndef _STATE_AND_STATS_H
#define _STATE_AND_STATS_H

#include "tetris.h"

void game_init(AllGameInfo_t *stats);
AllGameInfo_t *getSingleton();
GameInfo_t updateCurrentState();

void start(AllGameInfo_t *all_game_info);
void spawn(AllGameInfo_t *all_game_info);
void game_over(AllGameInfo_t *all_game_info);
void attaching(AllGameInfo_t *all_game_info);
void moving(AllGameInfo_t *all_game_info);
void pause_tetris(AllGameInfo_t *all_game_info);
void rotate_figure(AllGameInfo_t *all_game_info);

void copy_sample_to_array(int *ptr_from, int *ptr_arr_to, int size);
int check_intersect_after_rotate(int *sample, AllGameInfo_t *all_game_info);
int calc_empty_column_left(int *sample);
int calc_empty_column_right(int *sample);

void check_attaching(AllGameInfo_t *all_game_info);

#endif