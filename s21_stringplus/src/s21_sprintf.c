#include "s21_sprintf.h"

#include "s21_sprintf_convert.h"
#include "s21_string.h"

/*библиотека для множественных аргументов функции*/

int s21_sprintf(char *str, const char *format, ...) {
  int result = 0;
  va_list args; /*список переданных аргументов*/
  s21_strcpy(str, format);
  va_start(args, format); /*начало работы с библиотекой*/
  s21_findspec(str, &args); /*основная функция*/
  va_end(args); /*конец работы с библиотекой*/
  result = s21_strlen(str);
  return result;
}

void s21_findspec(char *str, va_list *args) {
  int i = 0;
  int endWork = 0;
  while (str[i] != '\0' && endWork != 1) {
    prop props;
    s21_propinit(&props);
    int strLen = s21_strlen(str);
    if (str[i] == '%') {
      if (i == strLen - 1) {
        str[i] = '\0';
        break;
      }
      s21_readspec(str, &i, &props, args);
      char *insertString = s21_NULL;
      if (s21_checkvalidformat(&props, &i, str)) {
        endWork = s21_spec_handling(insertString, props, str, &i, args);
      }
    } else {
      i++;
    }
  }
}

void s21_readspec(char *str, int *i, prop *props, va_list *args) {
  int saveI = *i;
  int *widthCounter = malloc(sizeof(int));
  int widthNumLen = 0;
  *i = *i + 1;
  props->specCounter++;
  int endWork = 0;
  while (str[*i] != '\0' && endWork == 0) {
    if (str[*i] == ' ') {
      if (props->space != 1) props->space = 1;
    }

    if (str[*i] == '0' && props->dot == 0) {
      props->zero = 1;
      *i = *i + 1;
      props->specCounter++;

    } else {
      if (str[*i] == '*' && props->dot) {
        props->dotWidth = va_arg(*args, int);

      } else if (str[*i] == '*' && props->minFlag && props->minWidth == -1) {
        props->minWidth = va_arg(*args, int);
      } else if (str[*i] == '*') {
        props->width = va_arg(*args, int);
      }
      s21_getwidthnumber(str, i, &widthCounter, &widthNumLen, props);
      if (s21_savefindedspec(props, i, str) == 0 ||
          s21_checksymbols(saveI, str, i, props) != 1) {
        endWork = 1;
      } else {
        *i = *i + 1;
        props->specCounter++;
      }
    }
  }

  free(widthCounter);
  *i = *i + 1;
  props->specCounter++;
}

void s21_shiftstring(char *str, int id, int shiftValue, int dir) {
  /*dir либо -1(влево) либо 1 (вправо)*/
  /*сдвинуть часть строки от индекса id на shiftValue*/
  int strLen = s21_strlen(str);
  char *strCopy = malloc(sizeof(char) * strLen + shiftValue + 1);
  s21_strcpy(strCopy, str);
  for (int i = id; i < strLen + shiftValue; i++) {
    str[i + (shiftValue * dir)] = strCopy[i];
  }

  free(strCopy);
}

void s21_insertstring(char *str, char *insertItem, int startId, int lastSpec) {
  /*вставить строку, не сдвигая символы!*/

  int itemLen = s21_strlen(insertItem);

  for (int i = 0; i < itemLen + lastSpec; i++) {
    str[i + startId] = insertItem[i];
  }
}

void s21_sprintfinsertstring(char *insertItem, char *str, int i,
                             int specSymbolCount) {
  int sLen = s21_strlen(insertItem);
  int strLen = s21_strlen(str);

  if (strLen == i) {
    s21_insertstring(str, insertItem, i - specSymbolCount, 1);
  } else if (sLen < specSymbolCount) {
    s21_shiftstring(str, i, specSymbolCount - sLen, -1);
    s21_insertstring(str, insertItem, i - specSymbolCount, 0);
  } else {
    s21_shiftstring(str, i, sLen - specSymbolCount, 1);
    s21_insertstring(str, insertItem, i - specSymbolCount, 0);
  }
}

int s21_countwidth(int **widthCounter, int *len) {
  int res = 0;
  if (*len > 0) {
    for (int i = 0; i < *len; i++) {
      res += (*widthCounter)[i];
    }
  }
  *len = 0;
  free(*widthCounter);
  *widthCounter = malloc(sizeof(int));
  return res;
}

void s21_convertetostring(double number, char **str, int precision, int ESpec,
                          int sharp) {
  *str = malloc(sizeof(char) * 500);
  int exponent = (int)log10(fabs(number));
  double mantissa = number / pow(10, exponent);
  char *zeros = malloc(sizeof(char));
  zeros[0] = '\0';
  char format[] = "%.*f%s.e%+03d";
  if (ESpec) format[7] = 'E';

  if (number == 0) {
    format[8] = '+';
    format[9] = '0';
    format[10] = '0';
    format[11] = '\0';
  }
  if (precision != 0 || (precision == 0 && sharp == 0))
    s21_shiftstring(format, 7, 1, -1);

  if (s21_infinitycheck(number, str)) {
    s21_sprintf(*str, format, precision, zeros, mantissa, exponent);
  }
  if (number == 0) {
    s21_shiftstring(*str, 1, 1, -1);
  }
  if (s21_strcmp("-0.000000e-00", *str) == 0 ||
      s21_strcmp("-0.000000E-00", *str) == 0) {
    (*str)[0] = '\0';
    s21_strcpy(*str, "nan");
  }

  free(zeros);
}

void s21_convertlongetostring(long double number, char **str, int precision,
                              int ESpec, int sharp) {
  *str = malloc(sizeof(char) * 500);
  int exponent = (int)log10(fabsl(number));
  long double mantissa = number / pow(10, exponent);
  char *zeros = malloc(sizeof(char));
  zeros[0] = '\0';
  char format[] = "%.*Lf%s.e%+03d";
  if (ESpec) format[8] = 'E';

  if (number == 0) {
    format[9] = '+';
    format[10] = '0';
    format[11] = '0';
    format[12] = '\0';
  }
  if (precision != 0 || (precision == 0 && sharp == 0))
    s21_shiftstring(format, 8, 1, -1);

  if (s21_infinitycheck(number, str)) {
    s21_sprintf(*str, format, precision, mantissa, zeros, exponent);
  }
  if (number == 0) {
    s21_shiftstring(*str, 1, 1, -1);
  }
  if (s21_strcmp("-0.000000e-00", *str) == 0 ||
      s21_strcmp("-0.000000E-00", *str) == 0) {
    (*str)[0] = '\0';
    s21_strcpy(*str, "nan");
  }

  free(zeros);
}

void s21_convertgtostring(double number, char **str, int precision, int g,
                          int sharp) {
  /*precision - точность*/
  /*получаем порядок числа*/

  int exponent = (int)log10(fabs(number));
  /*если порядок от -4 до указанной точности, форматируем в десятичной форме*/

  if ((exponent >= -4 && exponent < precision) || precision == -1) {
    int fillZero = 0;
    if (sharp) fillZero = 1;
    if (precision == -1) {
      precision = 5;
    }
    s21_doubletostring(number, str, fillZero, 5, precision, sharp, 0, 0, 0.0);
  } else {
    if (g) s21_convertetostring(number, str, precision, 0, sharp);
    if (g != 1) s21_convertetostring(number, str, precision, 1, sharp);
  }
}

void s21_convertglongtostring(long double number, char **str, int precision,
                              int g, int sharp) {
  /*precision - точность*/
  /*получаем порядок числа*/

  int exponent = (int)log10(fabsl(number));
  /*если порядок от -4 до указанной точности, форматируем в десятичной форме */

  if ((exponent >= -4 && exponent < precision) || precision == -1) {
    int fillZero = 0;
    if (sharp) fillZero = 1;
    s21_longdoubletostring(number, str, fillZero, 5);
  } else {
    if (g) s21_convertlongetostring(number, str, precision, 0, sharp);
    if (g != 1) s21_convertlongetostring(number, str, precision, 1, sharp);
  }
}

void s21_dothandler(prop *props, char **insertString) {
  /* для целых*/
  if (s21_strcmp(*insertString, "(null)") == 0) {
    (*insertString)[0] = '\0';
  }
  if (props->d || props->u || props->x || props->o || props->X || props->ld ||
      props->hu) {
    int insertStrLen = s21_strlen(*insertString);
    int copyWidth = props->dotWidth - insertStrLen;
    if (insertStrLen < props->dotWidth) {
      int insertId = 0;

      if ((*insertString)[0] == '-' || (*insertString)[0] == '+') {
        insertId = 1;
        copyWidth++;
      }

      while (copyWidth != 0) {
        copyWidth--;
        s21_insertcharatindex(insertString, insertId, '0');
      }
    }
  }

  /*для нецелых e, E, f, g и G*/

  if (props->s) {
    int len = s21_strlen(*insertString);
    if (len >= props->dotWidth) {
      (*insertString)[props->dotWidth] = '\0';
    }
  }
}

void s21_minhandler(prop *props, char **insertString) {
  int insertStrLen = s21_strlen(*insertString);
  props->minWidth -= insertStrLen;
  int InsertPos = insertStrLen;

  while (props->minWidth > 0) {
    char ch = ' ';
    s21_insertcharatindex(insertString, InsertPos, ch);
    props->minWidth--;
  }
}

void s21_widthhandler(prop *props, char **insertString) {
  int insertStrLen = s21_strlen(*insertString);

  props->width -= insertStrLen;
  if (props->space) props->width--;
  int InsertPos = 0;
  if (((*insertString)[0] == '-' || (*insertString)[0] == '+') && props->zero)
    InsertPos++;

  if (props->p && props->zero) {
    InsertPos = 2;
  }
  char ch = ' ';
  if (props->zero) ch = '0';
  while (props->width > 0) {
    s21_insertcharatindex(insertString, InsertPos, ch);
    props->width--;
  }
}

void s21_getstringfromvar(prop *props, char **insertString, va_list *args) {
  if (props->ld) {
    long long int num = va_arg(*args, long long int);
    if (s21_checknull(insertString, &num))
      s21_longinttostring(num, insertString);
  }
  if (props->d || props->c || props->hd || props->hu)
    s21_get_string_from_int_spec(props, args, insertString);
  if (props->u || props->x || props->X || props->o)
    s21_get_string_from_uint(props, args, insertString);
  if (props->lu) {
    unsigned long num = va_arg(*args, unsigned long);
    if (s21_checknull(insertString, &num))
      s21_longuinttostring(num, insertString);
  }
  if (props->s) {
    char *s = va_arg(*args, char *);
    if (s21_checknull(insertString, s)) {
      *insertString = malloc(sizeof(char) * s21_strlen(s) + 1);
      s21_strcpy(*insertString, s);
    }
  }
  if (props->p) {
    *insertString = malloc(sizeof(char) * 100);
    s21_convertpointertostring(*insertString, va_arg(*args, void *));
  }
  int precision = props->dotWidth;
  if (props->dot == -1) {
    precision = 6;
  }
  if (props->f || props->g || props->G || props->e || props->E)
    s21_get_string_from_double(props, args, insertString, precision);

  if (props->Le || props->LE || props->LG || props->Le || props->LE ||
      props->Lf || props->Lg)
    s21_get_string_from_longdouble(props, args, insertString, precision);
  if (props->plusFlag &&
      (props->d || props->f || props->hd || props->ld || props->Lf ||
       props->Le || props->LE || props->Lg || props->LG || props->e ||
       props->g || props->E || props->e) &&
      (*insertString)[0] != '-') {
    s21_insertcharatindex(insertString, 0, '+');
  }
}

int s21_checksymbols(int saveI, char *str, int *i, prop *props) {
  char specsSymbols[] = ".dfgGeEusch#+-01234567890lLxXpo *";
  int checkRes = 0;
  for (int j = 0; j < 33; j++) {
    if (str[*i] == specsSymbols[j]) {
      checkRes = 1;
    }
  }
  if (checkRes == 0) {
    props->empty = saveI;
  }
  return checkRes;
}

int s21_savefindedspec(prop *props, int *i, char *str) {
  int res = -1;
  s21_find_spec_1(str, props, i, &res);
  s21_find_spec_2(str, props, i, &res);
  s21_find_spec_3(str, props, i, &res);

  return res;
}

void s21_getwidthnumber(char *str, int *i, int **widthCounter, int *widthNumLen,
                        prop *props) {
  while (isdigit(str[*i])) {
    (*widthCounter)[*widthNumLen] = str[*i] - '0';

    *widthNumLen = *widthNumLen + 1;
    *widthCounter = realloc(*widthCounter, (*widthNumLen + 1) * sizeof(int));
    for (int j = 0; j < *widthNumLen - 1; j++) {
      (*widthCounter)[j] *= 10;
    }

    props->specCounter++;
    *i = *i + 1;
  }

  if (*widthNumLen > 0) {
    if (props->minFlag) {
      props->minWidth = s21_countwidth(widthCounter, widthNumLen);
      props->minFlag = 0;
    } else if (props->dot) {
      props->dotWidth = s21_countwidth(widthCounter, widthNumLen);
    } else {
      props->width = s21_countwidth(widthCounter, widthNumLen);
    }
  }
}

int s21_checkvalidformat(prop *props, int *i, char *str) {
  int res = 1;
  if (props->empty != -1) {
    s21_shiftstring(str, props->empty + 1, 1, -1);
    *i = props->empty + 1;
    res = 0;
  }
  return res;
}

void s21_propinit(prop *props) {
  props->specCounter = 0;
  props->space = 0;
  /*флаги*/
  props->l = 0;
  props->L = 0;
  props->plusFlag = 0;
  props->minFlag = 0;
  props->width = -1;
  props->dot = 0;
  props->zero = 0;
  props->star = 0;
  props->minWidth = -1;
  props->dotWidth = -1;
  props->sharp = 0;
  /*спецификаторы*/
  props->d = 0;
  props->u = 0;
  props->f = 0;
  props->c = 0;
  props->s = 0;
  props->p = 0;
  props->ld = 0;
  props->hd = 0;
  props->h = 0;
  props->lu = 0;
  props->hu = 0;
  props->o = 0;
  props->x = 0;
  props->X = 0;
  props->i = 0;
  props->e = 0;
  props->E = 0;
  props->g = 0;
  props->G = 0;
  props->empty = -1;
  props->Lf = 0;
  props->Le = 0;
  props->LE = 0;
  props->Lg = 0;
  props->LG = 0;
}

int s21_checknull(char **str, void *ptr) {
  int res = 0;
  if (ptr != s21_NULL) {
    res = 1;
  } else {
    *str = malloc(sizeof(char) * 7);
    s21_strcpy(*str, "(null)");
  }
  return res;
}

int s21_spec_handling(char *insertString, prop props, char *str, int *i,
                      va_list *args) {
  int res = 0;
  s21_getstringfromvar(&props, &insertString, args);

  if (props.dot) {
    s21_dothandler(&props, &insertString);
  }
  if (props.minWidth > -1) {
    s21_minhandler(&props, &insertString);
  }
  if (props.zero && props.dot && props.f == 0 && props.LE == 0 &&
      props.Le == 0 && props.e == 0 && props.E == 0) {
    props.zero = 0;
  }

  if (props.width > -1) {
    s21_widthhandler(&props, &insertString);
  }
  if (props.space && insertString[0] != '-' &&
      ((props.width == -1 || props.dot != -1)) && props.s == 0 && props.u == 0)
    s21_insertcharatindex(&insertString, 0, ' ');

  if (insertString != s21_NULL) {
    s21_sprintfinsertstring(insertString, str, *i, props.specCounter);
    *i = s21_strlen(insertString) - props.specCounter + *i - 1;

  } else {
    res = 1;
  }
  free(insertString);
  return res;
}

void s21_get_string_from_int_spec(prop *props, va_list *args,
                                  char **insertString) {
  int num = va_arg(*args, int);
  if (s21_checknull(insertString, &num)) {
    if (props->d) {
      s21_intostring(num, insertString);
    }
    if (props->hd) {
      short numhd = num;
      s21_intostring(numhd, insertString);
    }

    if (props->hu) {
      unsigned short numhu = num;

      s21_ushorttostring(numhu, insertString);
    }

    if (props->c) {
      char ch = num;

      *insertString = malloc(sizeof(char) * 2);
      (*insertString)[0] = ch;
      (*insertString)[1] = '\0';
    }
  }
}

void s21_get_string_from_uint(prop *props, va_list *args, char **insertString) {
  unsigned int num = va_arg(*args, unsigned int);
  if (s21_checknull(insertString, &num)) {
  }
  if (props->u) {
    s21_uinttostring(num, insertString);
  }
  if (props->o) {
    s21_converttoo(num, insertString);
    if (props->sharp && num != 0) {
      s21_insertcharatindex(insertString, 0, '0');
    }
  }
  if (props->x) {
    s21_convertox(num, insertString, 0);
    if (props->sharp && num != 0) {
      s21_insertcharatindex(insertString, 0, 'x');
      s21_insertcharatindex(insertString, 0, '0');
    }
  }
  if (props->X) {
    s21_convertox(num, insertString, 1);
    if (props->sharp && num != 0) {
      s21_insertcharatindex(insertString, 0, 'X');
      s21_insertcharatindex(insertString, 0, '0');
    }
  }
}

void s21_get_string_from_double(prop *props, va_list *args, char **insertString,
                                int precision) {
  double num = (double)va_arg(*args, double);

  if (s21_checknull(insertString, &num)) {
    if (props->f) {
      if (s21_infinitycheck(num, insertString))
        s21_doubletostring(num, insertString, 1, 100, props->dotWidth,
                           props->sharp, 0, 0, 0.0);
    }
    if (props->e) {
      s21_convertetostring(num, insertString, precision, 0, props->sharp);
    }
    if (props->E) {
      s21_convertetostring(num, insertString, precision, 1, props->sharp);
    }
    if (props->g) {
      s21_convertgtostring(num, insertString, precision, 1, props->sharp);
    }
    if (props->G) {
      s21_convertgtostring(num, insertString, precision, 0, props->sharp);
    }
  }
}

void s21_get_string_from_longdouble(prop *props, va_list *args,
                                    char **insertString, int precision) {
  long double num = va_arg(*args, long double);

  if (s21_checknull(insertString, &num)) {
    if (props->Le) {
      s21_convertlongetostring(num, insertString, precision, 0, props->sharp);
    }
    if (props->LE) {
      s21_convertlongetostring(num, insertString, precision, 1, props->sharp);
    }
    if (props->Lg) {
      s21_convertglongtostring(num, insertString, precision, 1, props->sharp);
    }
    if (props->LG) {
      s21_convertglongtostring(num, insertString, precision, 0, props->sharp);
    }
    if (props->Lf) {
      s21_doubletostring(num, insertString, 1, 100, precision, props->sharp, 0,
                         1, num);
    }
  }
}

void s21_find_spec_1(char *str, prop *props, int *i, int *res) {
  if (str[*i] == 'd') {
    props->d = 1;
    if (props->l) {
      props->ld = 1;
      props->d = 0;
    } else if (props->h) {
      props->hd = 1;
      props->d = 0;
    }
    *res = 0;
  }
  if (str[*i] == 'c') {
    props->c = 1;
    *res = 0;
  }
  if (str[*i] == 's') {
    props->s = 1;
    *res = 0;
  }
  if (str[*i] == 'u') {
    props->u = 1;
    if (props->l) {
      props->lu = 1;
      props->u = 0;
    } else if (props->h) {
      props->hu = 1;
      props->u = 0;
    }
    *res = 0;
  }
  if (str[*i] == 'o') {
    props->o = 1;
    *res = 0;
  }
  if (str[*i] == 'x') {
    props->x = 1;
    *res = 0;
  }
}

void s21_find_spec_2(char *str, prop *props, int *i, int *res) {
  if (str[*i] == 'X') {
    props->X = 1;
    *res = 0;
  }
  if (str[*i] == 'p') {
    props->p = 1;
    *res = 0;
  }
  if (str[*i] == 'f') {
    props->f = 1;

    if (props->L) {
      props->f = 0;
      props->Lf = 1;
    }
    *res = 0;
  }
  if (str[*i] == 'g') {
    if (props->L) {
      props->Lg = 1;
    } else {
      props->g = 1;
    }
    *res = 0;
  }
  if (str[*i] == 'G') {
    if (props->L) {
      props->LG = 1;
    } else {
      props->G = 1;
    }
    *res = 0;
  }
}

void s21_find_spec_3(char *str, prop *props, int *i, int *res) {
  if (str[*i] == '#') {
    props->sharp = 1;
  }
  if (str[*i] == '-') {
    props->minFlag = 1;
  }
  if (str[*i] == 'h') {
    props->h = 1;
  }
  if (str[*i] == '+') {
    props->plusFlag = 1;
  }

  if (str[*i] == 'l') {
    props->l = 1;
  }
  if (str[*i] == 'L') {
    props->L = 1;
  }

  if (str[*i] == '.') {
    props->dot = 1;
    props->minFlag = 0;
  }
  if (str[*i] == 'e') {
    if (props->L) {
      props->Le = 1;
    } else {
      props->e = 1;
    }
    *res = 0;
  }
  if (str[*i] == 'E') {
    if (props->L) {
      props->LE = 1;
    } else {
      props->E = 1;
    }
    *res = 0;
  }
}