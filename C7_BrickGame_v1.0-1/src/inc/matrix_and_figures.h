#ifndef _MATRIX_AND_FIGURES_H
#define _MATRIX_AND_FIGURES_H

#include "tetris.h"

int **create_matrix(int rows, int cols);
void copy_matrix(int **old_matrix, int **new_matrix, int rows, int cols);
void set_figure_on_field(int **field, int **figure, int x_pos, int y_pos);
void set_next_figure(struct _figure *, int **next);
void generate_figure(int **figure, int *figure_type);
void get_figure(int figure_type, int **figure);
void clear_figure();
void clear_figure_on_field(int **field, int **figure, int x_pos, int y_pos);

#endif