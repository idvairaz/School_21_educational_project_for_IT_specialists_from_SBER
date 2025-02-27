#ifndef _TETRIS_H
#define _TETRIS_H

#include <locale.h>
#include <ncurses.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "defines.h"
#include "game_objects.h"
#include "matrix_and_figures.h"
#include "scoring.h"
#include "state_and_stats.h"
#include "type.h"
#include "user_actions.h"

void game_loop();

#endif