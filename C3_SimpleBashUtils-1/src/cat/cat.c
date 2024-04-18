#include "cat.h"

void printbuf(int size, unsigned char buffer[], Data_struct *ptrdata) {
  int index;

  for (index = 0; index < size; index++) {
    if ((ptrdata->last == '\n') && (ptrdata->last == buffer[index])) {
      ptrdata->blanks++;

    } else {
      ptrdata->blanks = 0;
    }

    if ((!ptrdata->sflag) || (ptrdata->blanks < 2)) {
      if ((ptrdata->last == '\n') &&
          !(buffer[index] == '\n' && ptrdata->bflag)) {
        if (ptrdata->nflag || ptrdata->bflag) {
          printf("%6d\t", ptrdata->line);
        }
        ptrdata->line++;
      }

      if (ptrdata->eflag && !ptrdata->vflag && buffer[index] == '\n') {
        printf("$");
      }

      if (ptrdata->tflag && !ptrdata->vflag && buffer[index] == '\t') {
        printf("^I");
        index++;
      }

      if (ptrdata->vflag) {
        if (buffer[index] < 32) {
          if (buffer[index] == 10 && ptrdata->eflag) {
            printf("$\n");
          } else if (buffer[index] == 9 && ptrdata->eflag) {
            printf("\t");

          } else if (buffer[index] == 10 && ptrdata->tflag) {
            printf("\n");
          } else if (buffer[index] == 9 && ptrdata->tflag) {
            printf("^I");
          }

          else if (buffer[index] != 9 || buffer[index] != 10) {
            printf("^%c", buffer[index] + 64);
          }

        } else if (buffer[index] == 127) {
          printf("^?");
        } else if (buffer[index] > 127) {
          char ch = buffer[index] - 128;
          printf("M-");
          if (ch < 32) {
            printf("^%c", ch + 64);
          } else {
            printf("%c", ch);
          }
        } else {
          printf("%c", buffer[index]);
        }

      } else {
        printf("%c", buffer[index]);
      }
    }
    ptrdata->last = buffer[index];
  }
}

int parse_flags(Data_struct *ptrdata, char *current_flag) {
  int index = 1;
  int res = 0;

  while (current_flag[index] != 0 && !res) {
    switch (current_flag[index]) {
      case 'b':
        ptrdata->bflag = 1;
        break;
      case 'e':
        ptrdata->eflag = 1;
        ptrdata->vflag = 1;
        break;
      case 'E':
        ptrdata->eflag = 1;
        break;
      case 'n':
        ptrdata->nflag = 1;
        break;
      case 's':
        ptrdata->sflag = 1;
        break;
      case 't':
        ptrdata->tflag = 1;
        ptrdata->vflag = 1;
        break;
      case 'T':
        ptrdata->tflag = 1;
        break;
      case 'v':
        ptrdata->vflag = 1;
        break;
      case '-':
        index = strlen(current_flag);
        if (index == 2) {
          ptrdata->stop = 1;
        } else if (!strcmp(current_flag, "--number-nonblank")) {
          ptrdata->nflag = 1;
          ptrdata->bflag = 1;
        } else if (!strcmp(current_flag, "--number")) {
          ptrdata->nflag = 1;
        } else if (!strcmp(current_flag, "--squeeze-blank")) {
          ptrdata->sflag = 1;
        } else {
          fprintf(stderr, ERROR_01, current_flag);
          res = 1;
        }
        index--;
        break;
      default:
        fprintf(stderr, ERROR_01, current_flag);
        res = 1;
    }
    index++;
  }
  return res;
}

void print_file(Data_struct *ptrdata, char *filename) {
  FILE *file;
  unsigned char buffer[BUFFER_SIZE];
  int bytes;
  int size;

  if ((file = fopen(filename, "r")) != NULL) {
    bytes = 0;
    while ((size = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
      if (bytes == 0) {
        ptrdata->last = '\n';
      }
      bytes += size;

      printbuf(size, buffer, ptrdata);
    }
    fclose(file);
  } else {
    printf("%s: %s\n", filename, strerror(errno));
  }
}

int main(int argc, char **argv) {
  int res = 0;
  if (argc > 2) {
    int count;
    Data_struct data = {0};

    data.line = 1;

    for (count = 1; count < argc && (data.stop != 1); count++) {
      char *current_argv = argv[count];
      if (current_argv[0] == '-') {
        parse_flags(&data, current_argv);

      } else {
        print_file(&data, current_argv);
      }
    }
  } else {
    printf("Недостаточно аргументов для: %s, требуется флаг и путь к файлу\n",
           argv[0]);
    res = 1;
  }
  return res;
}