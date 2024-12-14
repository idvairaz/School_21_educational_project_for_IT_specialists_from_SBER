#include "grep.h"

int main(int argc, char **argv) {
  int res = 0;
  if (argc > 2) {
    Data_struct data = {0};
    res = scan_opt(argc, argv, &data);
  } else {
    printf(
        "Недостаточно аргументов для: %s, требуется флаг, паттерн и путь к "
        "файлу\n",
        argv[0]);
    res = 1;
  }
  return res;
}

int scan_opt(int argc, char **argv, Data_struct *ptrdata) {
  int res = 0;

  int opt;
  char *argument = NULL;
  while ((opt = getopt(argc, argv, "e:ivclnsho")) != -1 && !res) {
    switch (opt) {
      case 'e':
        ptrdata->eflag = 1;
        argument = optarg;
        break;
      case 'i':
        ptrdata->iflag = 1;
        break;
      case 'v':
        ptrdata->vflag = 1;
        break;
      case 'c':
        ptrdata->cflag = 1;
        break;
      case 'l':
        ptrdata->lflag = 1;
        break;
      case 'n':
        ptrdata->nflag = 1;
        break;
      case 's':
        ptrdata->sflag = 1;
        break;
      case 'h':
        ptrdata->hflag = 1;
        break;
      case 'o':
        ptrdata->oflag = 1;
        break;

      default: /* '?' */
        fprintf(stderr, ERROR_03, argv[0]);
        res = 1;
    }
  }

  if (optind >= argc && !res) {
    fprintf(stderr, ERROR_02);
    res = 1;
  }

  if (!res) {
    char *pattern;

    if (ptrdata->eflag == 1) {
      pattern = argument;
    } else {
      pattern = argv[optind++];
    }

    if (optind == (argc - 1)) {
      ptrdata->only_one_file = 1;
    }

    for (int i = optind; i < argc; i++) {
      work(pattern, argv[i], ptrdata);
    }
  }

  return res;
}

void work(char *pattern, char *path, Data_struct *ptrflags) {
  FILE *file = fopen(path, "r");

  if (file != NULL) {
    regex_t preg;

    int result;
    int regcomp_cflags = ptrflags->iflag ? REG_ICASE : 0;

    result = regcomp(&preg, pattern, regcomp_cflags);

    if (result != 0) {
      char buff[512];
      regerror(result, &preg, buff, sizeof(buff));
      printf("%s", buff);
    }

    char *fileline = NULL;
    size_t len = 0;
    int bytesread;
    ptrflags->number_line = 1;

    while ((bytesread = getline(&fileline, &len, file)) != -1) {
      if (line_processing(fileline, path, ptrflags, preg)) {
        break;
      }
    }

    if (ptrflags->cflag == 1) {
      if (ptrflags->only_one_file == 1) {
        printf("%d\n", ptrflags->count_of_matches);
      } else {
        printf("%s:%d\n", path, ptrflags->count_of_matches);
      }
    }

    ptrflags->count_of_matches = 0;
    ptrflags->number_line = 1;

    free(fileline);
    regfree(&preg);
    fclose(file);

  } else {
    if (!ptrflags->sflag) {
      fprintf(stderr, ERROR_01, path);
    }
  }
}

int line_processing(char *fileline, char *path, Data_struct *ptrflags,
                    regex_t preg) {
  int error = 0;
  if (fileline[strlen(fileline) - 1] == '\n') {
    fileline[strlen(fileline) - 1] = '\0';
  }

  int result = -1;
  result = regexec(&preg, fileline, 0, NULL, 0);

  if ((result == 0) ^ (ptrflags->vflag)) {
    ptrflags->matches_last_strok = 1;

    if (ptrflags->lflag && !ptrflags->cflag) {
      printf("%s\n", path);
      error = 1;
    }

    if (!error) {
      if (!ptrflags->only_one_file && !ptrflags->cflag) {
        if (!ptrflags->hflag && !ptrflags->oflag) printf("%s:", path);
      }

      if (ptrflags->nflag && !ptrflags->cflag) {
        printf("%d:", ptrflags->number_line);
      }

      if (!ptrflags->oflag) {
        if (!ptrflags->cflag) {
          printf("%s\n", fileline);
        }
      } else {
        o_flag_work(preg, fileline, ptrflags, path);
      }
    }

    ptrflags->count_of_matches++;
  }

  ptrflags->number_line++;
  return error;
}

void o_flag_work(regex_t preg, char *fileline, Data_struct *ptrflags,
                 char *path) {
  regmatch_t pmatch;
  int offset = 0;

  while (regexec(&preg, fileline + offset, 1, &pmatch, REG_NOTEOL) == 0 &&
         (int)strlen(fileline) > offset) {
    if (pmatch.rm_so == pmatch.rm_eo) {
      offset++;
      continue;
    }

    if (!ptrflags->only_one_file) {
      printf("%s:", path);
    }
    for (int i = pmatch.rm_so; i < pmatch.rm_eo; i++) {
      putchar(fileline[offset + i]);
    }
    putchar('\n');
    offset += pmatch.rm_eo;
  }
}
