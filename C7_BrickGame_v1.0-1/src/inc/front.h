#ifndef _FRONT_H
#define _FRONT_H

#include <ncurses.h>
#include <stdio.h>

#include "defines.h"
#include "game_objects.h"

void print_overlay(void);
void print_rectangle(int top_y, int bottom_y, int left_x, int right_x);
void print_stats(GameInfo_t *stats);
void print_next(int **next);
void print_game_over_ban();
void print_pause_ban();
void print_start_ban();
void print_game_field(int **field);

#endif