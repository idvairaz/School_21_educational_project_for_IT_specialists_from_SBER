#ifndef _SCORING_H
#define _SCORING_H

#include "tetris.h"

void scoring(AllGameInfo_t *all_game_info, int cnt_together_rows);
void level_up(AllGameInfo_t *all_game_info);
void speed_up(AllGameInfo_t *all_game_info);
void save_high_score(int high_score);
int load_high_score();
void delete_full_line(AllGameInfo_t *all_game_info);

#endif
