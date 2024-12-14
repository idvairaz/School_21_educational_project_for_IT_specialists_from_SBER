#ifndef CAT_H_
#define CAT_H_

#define _GNU_SOURCE
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 512
#define ERROR_01 "в программе нет флага '%s'\n"

typedef struct {
  int last;
  int blanks;
  int line;
  int stop;
  int sflag;
  int nflag;
  int bflag;
  int eflag;
  int tflag;
  int vflag;
} Data_struct;

void printbuf(int size, unsigned char buffer[], Data_struct *ptrdata);
int parse_flags(Data_struct *ptrdata, char *current_flag);
void print_file(Data_struct *ptrdata, char *filename);

#endif /*CAT_H_*/