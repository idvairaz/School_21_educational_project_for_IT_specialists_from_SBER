#ifndef GREP_H_
#define GREP_H_

#define _GNU_SOURCE
#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_01 "s21_grep: %s: Нет файла с таким именем\n"
#define ERROR_02 "Укажите  аргумент после опции\n"
#define ERROR_03 "в программе '%s' нет такого флага \n"

typedef struct {
  int number_line;
  int eflag;
  int iflag;
  int vflag;
  int cflag;
  int lflag;
  int nflag;
  int sflag;
  int hflag;
  int oflag;
  int count_of_matches;
  int only_one_file;
  int matches_last_strok;
} Data_struct;

void work(char *pattern, char *path, Data_struct *ptrflags);
int scan_opt(int argc, char **argv, Data_struct *ptrdata);
void o_flag_work(regex_t preg, char *fileline, Data_struct *ptrflags,
                 char *path);
int line_processing(char *fileline, char *path, Data_struct *ptrflags,
                    regex_t preg);

#endif /*GREP_H_*/