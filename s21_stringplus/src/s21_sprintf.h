#ifndef SPRINTF_H
#define SPRINTF_H

#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int s21_sprintf(char *str, const char *format, ...);
void s21_shiftstring(char *make, int id, int shiftValue, int dir);
void s21_insertstring(char *str, char *insertItem, int startId, int lastSpec);
void s21_sprintfinsertstring(char *insertItem, char *str, int i,
                             int specSymbolCount);
int s21_countwidth(int **widthCounter, int *len);
void s21_convertetostring(double number, char **str, int precision, int ESpec,
                          int sharp);
void s21_convertglongtostring(long double number, char **str, int precision,
                              int g, int sharp);
void s21_convertlongetostring(long double number, char **str, int precision,
                              int ESpec, int sharp);

typedef struct varProperties {
  int specCounter;
  /*флаги*/
  int width;
  int minWidth;
  int dotWidth;
  int l;
  int L;
  int plusFlag;
  int minFlag;
  int dot;
  int zero;
  int star;
  int space;
  int sharp; /*решетка*/
  int empty;
  /*спецификаторы*/
  int d, u, f, c, s, p, h, ld, hd, lu, hu, o, x, i, X, E, e, g, G, Lf, n, Le,
      LE, Lg, LG;

} prop;

int s21_checknull(char **str, void *ptr);
int s21_checkvalidformat(prop *props, int *i, char *str);
void s21_getwidthnumber(char *str, int *i, int **widthCounter, int *widthNumLen,
                        prop *props);
int s21_savefindedspec(prop *props, int *i, char *str);
int s21_checksymbols(int saveI, char *str, int *i, prop *props);
void s21_getstringfromvar(prop *props, char **insertString, va_list *args);
void s21_dothandler(prop *props, char **insertString);
void s21_minhandler(prop *props, char **insertString);
void s21_widthhandler(prop *props, char **insertString);
void s21_convertgtostring(double number, char **str, int precision, int g,
                          int fillZero);
void s21_findspec(char *str, va_list *args);
void s21_readspec(char *str, int *i, prop *props, va_list *args);
void s21_propinit(prop *props);
int s21_spec_handling(char *insertString, prop props, char *str, int *i,
                      va_list *args);
void s21_get_string_from_int_spec(prop *props, va_list *args,
                                  char **insertString);
void s21_get_string_from_uint(prop *props, va_list *args, char **insertString);
void s21_get_string_from_double(prop *props, va_list *args, char **insertString,
                                int precision);
void s21_get_string_from_longdouble(prop *props, va_list *args,
                                    char **insertString, int precision);
void s21_find_spec_1(char *str, prop *props, int *i, int *res);
void s21_find_spec_2(char *str, prop *props, int *i, int *res);
void s21_find_spec_3(char *str, prop *props, int *i, int *res);

#endif
