#include "s21_sscanf.h"

#include "s21_string.h"
/* Функция возвращает -1 - если есть ошибка, либо количество успешно считанных
  патаметров */
int s21_sscanf(const char *str, const char *format, ...) {
  int error = s21_strlen(str) ? OK : ERROR;
  int count = 0;

  int str_index = 0;
  int format_index = 0;

  va_list args;
  va_start(args, format);

  while (format[format_index] != '\0' && !error) {
    int result_code = s21_parse(str, &str_index, format, &format_index, &args);
    if (result_code == OK)
      count++;
    else if (result_code == ERROR)
      error = -1;
    else if (result_code == WRONG_FORMAT) {
      error = OK;
      break;
    }
  }

  va_end(args);
  // если есть хоть один считанный аргумент - возвращаем количество
  return (count || !error) ? count : error;
}

int s21_parse(const char *str, int *str_index, const char *format,
              int *format_index, va_list *args) {
  int error = OK;
  s21_tocken tocken;
  s21_tocken_init(&tocken);

  error = s21_get_token(&tocken, format, format_index);

  if (!error) error = s21_token_run(tocken, str, str_index, args);

  return error;
}

int s21_get_token(s21_tocken *tocken, const char *format, int *format_index) {
  int error = OK;
  if (format[*format_index] == '%') {
    // обнаружен спецификатор
    tocken->type = 2;
    (*format_index)++;
    error = s21_get_specificator(tocken, format, format_index);

  } else if (isspace(format[*format_index])) {
    // обнаружен знак-разделитель
    tocken->type = 0;
    (*format_index)++;

  } else {
    // обнаружен символ
    tocken->type = 1;
    tocken->value = format[*format_index];
    (*format_index)++;
  }
  return error;
}

int s21_get_specificator(s21_tocken *tocken, const char *format,
                         int *format_index) {
  int error = OK;
  s21_get_save(tocken, format, format_index);
  s21_get_width(tocken, format, format_index);
  s21_get_length(tocken, format, format_index);
  error = s21_get_value(tocken, format, format_index);
  return error;
}

void s21_get_save(s21_tocken *tocken, const char *format, int *format_index) {
  if (format[*format_index] == '*') {
    tocken->save = 0;
    (*format_index)++;
  }
  return;
}

void s21_get_width(s21_tocken *tocken, const char *format, int *format_index) {
  if (isdigit(format[*format_index])) {
    int value = 0;
    s21_get_signed_int_base(format, format_index, BASE_10, &value);
    tocken->width = value;
  } else {
    tocken->width = -1;
  }
  return;
}

void s21_get_length(s21_tocken *tocken, const char *format, int *format_index) {
  if (format[*format_index] == 'L') {
    tocken->length = 'L';
    (*format_index)++;

  } else if (format[*format_index] == 'l') {
    tocken->length = 'l';
    (*format_index)++;

  } else if (format[*format_index] == 'h') {
    tocken->length = 'h';
    (*format_index)++;
  }
  return;
}

int s21_get_value(s21_tocken *tocken, const char *format, int *format_index) {
  int error = OK;

  if (s21_strchr("diouxXfgGeEcsnp%", format[*format_index]) != s21_NULL) {
    tocken->value = format[*format_index];
    (*format_index)++;
  } else
    error = ERROR;

  return error;
}

void s21_tocken_init(s21_tocken *tocken) {
  tocken->save = 1;
  tocken->type = 0;
  tocken->width = 0;
  tocken->length = 'd';
  tocken->value = 0;
}

int s21_token_run(s21_tocken tocken, const char *str, int *str_index,
                  va_list *args) {
  int error = OK;
  switch (tocken.type) {
    case SPACE:
      s21_skip_space(str, str_index);
      error = SKIP;
      break;

    case SYMBOL:
      error = s21_check_symbol(str, str_index, tocken.value);
      if (!error) error = SKIP;
      break;

    case SPECIFIER:
      error = s21_specifier_run(tocken, str, str_index, args);
      break;
  }
  return error;
}

void s21_skip_space(const char *str, int *str_index) {
  while (isspace(str[*str_index])) (*str_index)++;
}

int s21_check_symbol(const char *str, int *str_index, char symbol) {
  int error = OK;

  s21_skip_space(str, str_index);

  if (str[*str_index] == symbol) {
    (*str_index)++;
  } else
    error = WRONG_FORMAT;

  return error;
}

int s21_specifier_run(s21_tocken tocken, const char *str, int *str_index,
                      va_list *args) {
  int error = OK;
  switch (tocken.value) {
    case 'd':
      error = s21_get_decimal(tocken, str, str_index, args);
      break;
    case 'i':
      error = s21_get_integer(tocken, str, str_index, args);
      break;
    case 'o':
      error = s21_get_unsigned_base(tocken, str, str_index, args);
      break;
    case 'x':
      error = s21_get_unsigned_base(tocken, str, str_index, args);
      break;
    case 'X':
      error = s21_get_unsigned_base(tocken, str, str_index, args);
      break;
    case 'u':
      error = s21_get_unsigned_base(tocken, str, str_index, args);
      break;
    case 'f':
    case 'e':
    case 'E':
    case 'g':
    case 'G':
      error = s21_get_float(tocken, str, str_index, args);
      break;
    case 'c':
      error = s21_get_char(tocken, str, str_index, args);
      break;
    case 's':
      error = s21_get_string(tocken, str, str_index, args);
      break;
    case 'p':
      error = s21_get_pointer(tocken, str, str_index, args);
      break;
    case 'n':
      error = s21_get_number(tocken, *str_index, args);
      break;
    case '%':
      error = s21_get_percent(str, str_index);
      break;
  }
  return error;
}

int s21_get_char(s21_tocken tocken, const char *str, int *str_index,
                 va_list *args) {
  int error = OK;

  switch (tocken.length) {
    case 'd':
      error = s21_get_char_short(tocken, str, str_index, args);
      break;

    case 'l':
      error = s21_get_char_long(tocken, str, str_index, args);
      break;
  }

  return error;
}

int s21_get_char_short(s21_tocken tocken, const char *str, int *str_index,
                       va_list *args) {
  int error = ERROR;
  if (tocken.width < 1) tocken.width = 1;

  if (tocken.save) {
    char *c = va_arg(*args, char *);
    while (str[*str_index] && tocken.width--) {
      *c = str[*str_index];
      c++;
      (*str_index)++;
      error = OK;
    }
  } else {
    while (str[*str_index] && tocken.width--) {
      (*str_index)++;
    }
    error = SKIP;
  }

  return error;
}

int s21_get_char_long(s21_tocken tocken, const char *str, int *str_index,
                      va_list *args) {
  int error = ERROR;
  if (tocken.width < 1) tocken.width = 1;

  if (tocken.save) {
    wchar_t *c = va_arg(*args, wchar_t *);

    while (str[*str_index] && tocken.width--) {
      mbtowc(c, &str[*str_index], 1);
      c++;
      (*str_index)++;
      error = OK;
    }
  } else {
    while (str[*str_index] && tocken.width--) {
      (*str_index)++;
    }
    error = SKIP;
  }

  return error;
}

int s21_get_string(s21_tocken tocken, const char *str, int *str_index,
                   va_list *args) {
  int error = OK;

  switch (tocken.length) {
    case 'd':
      error = s21_get_string_short(tocken, str, str_index, args);
      break;

    case 'l':
      error = s21_get_string_long(tocken, str, str_index, args);
      break;
  }

  return error;
}

int s21_get_string_short(s21_tocken tocken, const char *str, int *str_index,
                         va_list *args) {
  int error = ERROR;

  s21_skip_space(str, str_index);
  // если ширина не задана, то устанавливается длина оставшейся строки
  if (tocken.width == -1) tocken.width = s21_strlen(str) - *str_index;

  char *out_str;

  if (tocken.save) out_str = va_arg(*args, char *);

  while (str[*str_index] && !isspace(str[*str_index]) && tocken.width--) {
    error = SKIP;
    if (tocken.save) {
      error = OK;
      if (tocken.length == 'd') {
        *out_str = str[*str_index];
        out_str++;
      }
    }
    (*str_index)++;
  }

  if (!error && tocken.save) {
    if (tocken.length == 'd') *out_str = '\0';
  }

  return error;
}

int s21_get_string_long(s21_tocken tocken, const char *str, int *str_index,
                        va_list *args) {
  int error = ERROR;

  s21_skip_space(str, str_index);
  // если ширина не задана, то устанавливается длина оставшейся строки
  if (tocken.width == -1) tocken.width = s21_strlen(str) - *str_index;

  wchar_t *wstr;

  if (tocken.save) wstr = va_arg(*args, wchar_t *);

  while (str[*str_index] && !isspace(str[*str_index]) && tocken.width--) {
    error = SKIP;
    if (tocken.save) {
      error = OK;
      mbtowc(wstr, &str[*str_index], 1);
      wstr++;
    }
    (*str_index)++;
  }

  if (!error && tocken.save) mbtowc(wstr, '\0', 1);

  return error;
}

int s21_get_percent(const char *str, int *str_index) {
  int error = SKIP;

  s21_skip_space(str, str_index);

  // Пропускаем знак процента
  if (str[*str_index] == '%') {
    (*str_index)++;
  }

  return error;
}

int s21_get_pointer(s21_tocken tocken, const char *str, int *str_index,
                    va_list *args) {
  int error = SKIP;
  s21_skip_space(str, str_index);

  unsigned long value = 0;

  error = s21_get_unsigned_hex(str, str_index, &value, tocken.width);

  if (!error && tocken.save) {
    unsigned long *ptr = va_arg(*args, void *);
    *ptr = value;
  }

  return error;
}

int s21_get_number(s21_tocken tocken, const int str_index, va_list *args) {
  int error = SKIP;

  if (tocken.save) {
    int *number = va_arg(*args, int *);
    *number = str_index;
  }

  return error;
}

int s21_get_sign(const char *str, int *str_index, int *width) {
  int sign = 1;
  if (str[*str_index] == '-' && (*width)--) {
    sign = -1;
    (*str_index)++;
  } else if (str[*str_index] == '+' && (*width)--) {
    (*str_index)++;
  }
  return sign;
}

int s21_check_base(const char *str, int str_index, int width) {
  if (str[str_index] == '-' && width--) {
    (str_index)++;
  } else if (str[str_index] == '+' && width--) {
    str_index++;
  }

  int base = BASE_10;

  if (str[str_index] == '0' && width--) {
    base = BASE_8;
    str_index++;

    if ((str[str_index] == 'x' || str[str_index] == 'X') && width) {
      base = BASE_16;
    }
  }
  return base;
}

int s21_get_signed_int_base(const char *src, int *index, int base, int *value) {
  int error = ERROR;
  int sign = 1;

  if (src[*index] == '-') {
    sign = -1;
    (*index)++;
  } else if (src[*index] == '+') {
    (*index)++;
  }

  if (base == 10) {
    while (src[*index] >= '0' && src[*index] <= '9') {
      *value = *value * base + (src[*index] - 48);
      error = 0;
      (*index)++;
    }
  }

  if (!error) *value = *value * sign;

  return error;
}

/* **************************************************************************
 */

int s21_get_decimal(s21_tocken tocken, const char *str, int *str_index,
                    va_list *args) {
  int error = OK;
  s21_skip_space(str, str_index);
  long long_d = 0;

  error = s21_get_signed_decimal(str, str_index, &long_d, tocken.width);

  switch (tocken.length) {
    case 'h':
      if (!error && tocken.save) {
        short *val = va_arg(*args, short *);
        *val = (short)long_d;
      }
      break;

    case 'd':
      if (!error && tocken.save) {
        int *val = va_arg(*args, int *);
        *val = (int)long_d;
      }
      break;

    case 'l':
      if (!error && tocken.save) {
        long *val = va_arg(*args, long *);
        *val = long_d;
      }
      break;
  }

  return error;
}

int s21_get_integer(s21_tocken tocken, const char *str, int *str_index,
                    va_list *args) {
  int error = OK;
  s21_skip_space(str, str_index);
  int base = s21_check_base(str, *str_index, tocken.width);
  long long_i = 0;

  if (base == BASE_8)
    error = s21_get_signed_octal(str, str_index, &long_i, tocken.width);
  if (base == BASE_10)
    error = s21_get_signed_decimal(str, str_index, &long_i, tocken.width);
  if (base == BASE_16)
    error = s21_get_signed_hex(str, str_index, &long_i, tocken.width);

  switch (tocken.length) {
    case 'h':
      if (!error && tocken.save) {
        short *val = va_arg(*args, short *);
        *val = (short)long_i;
      }
      break;

    case 'd':
      if (!error && tocken.save) {
        int *val = va_arg(*args, int *);
        *val = (int)long_i;
      }
      break;

    case 'l':
      if (!error && tocken.save) {
        long *val = va_arg(*args, long *);
        *val = long_i;
      }
      break;
  }

  return error;
}

int s21_get_unsigned_base(s21_tocken tocken, const char *str, int *str_index,
                          va_list *args) {
  int error = OK;
  s21_skip_space(str, str_index);
  unsigned long long_i = 0;

  if (tocken.value == 'o')
    error = s21_get_unsigned_octal(str, str_index, &long_i, tocken.width);
  if (tocken.value == 'u')
    error = s21_get_unsigned_decimal(str, str_index, &long_i, tocken.width);
  if (tocken.value == 'x' || tocken.value == 'X')
    error = s21_get_unsigned_hex(str, str_index, &long_i, tocken.width);

  switch (tocken.length) {
    case 'h':
      if (!error && tocken.save) {
        unsigned short *val = va_arg(*args, unsigned short *);
        *val = (unsigned short)long_i;
      }
      break;

    case 'd':
      if (!error && tocken.save) {
        unsigned int *val = va_arg(*args, unsigned int *);
        *val = (unsigned int)long_i;
      }
      break;

    case 'l':
      if (!error && tocken.save) {
        unsigned long *val = va_arg(*args, unsigned long *);
        *val = long_i;
      }
      break;
  }

  return error;
}

/* **************************************************************************
 */

int s21_get_signed_decimal(const char *str, int *str_index, long *value,
                           int width) {
  int error = SKIP;

  // если ширина не задана, то устанавливается длина оставшейся строки
  if (width == -1)
    width = s21_strlen(str) - *str_index;
  else if (width == 0)
    width = 1;

  if (s21_strlen(str) - *str_index > 0) {
    long int number = 0;
    int sign = s21_get_sign(str, str_index, &width);

    while (str[*str_index] >= '0' && str[*str_index] <= '9' && width--) {
      error = OK;
      number = number * BASE_10 + (str[*str_index] - 48);
      (*str_index)++;
    }
    if (!error) *value = number * sign;

  } else
    error = ERROR;

  return error;
}

int s21_get_signed_octal(const char *str, int *str_index, long *value,
                         int width) {
  int error = SKIP;
  // если ширина не задана, то устанавливается длина оставшейся строки
  if (width == -1)
    width = s21_strlen(str) - *str_index;
  else if (width == 0)
    width = 1;

  if (s21_strlen(str) - *str_index > 0) {
    long int number = 0;
    int sign = s21_get_sign(str, str_index, &width);

    while (str[*str_index] >= '0' && str[*str_index] <= '7' && width-- &&
           error != ERROR) {
      error = OK;
      number = number * BASE_8 + (str[*str_index] - 48);
      (*str_index)++;
    }
    if (!error) *value = number * sign;

  } else
    error = ERROR;

  return error;
}

int s21_get_signed_hex(const char *str, int *str_index, long *value,
                       int width) {
  int error = SKIP;
  // если ширина не задана, то устанавливается длина оставшейся строки
  if (width == -1)
    width = s21_strlen(str) - *str_index;
  else if (width == 0)
    width = 1;

  if (s21_strlen(str) - *str_index > 0) {
    long int number = 0;
    int sign = s21_get_sign(str, str_index, &width);

    // Проверка наличия префикса 0x
    if (str[*str_index] == '0' && width--) {
      error = OK;
      (*str_index)++;
      if ((str[*str_index] == 'x' || str[*str_index] == 'X') && width--)
        (*str_index)++;
    }

    while (((str[*str_index] >= '0' && str[*str_index] <= '9') ||
            (str[*str_index] >= 'a' && str[*str_index] <= 'f') ||
            (str[*str_index] >= 'A' && str[*str_index] <= 'F')) &&
           width-- && error != ERROR) {
      error = OK;
      if (str[*str_index] >= '0' && str[*str_index] <= '9')
        number = number * BASE_16 + (str[*str_index] - 48);
      if (str[*str_index] >= 'a' && str[*str_index] <= 'f')
        number = number * BASE_16 + (str[*str_index] - 87);
      if (str[*str_index] >= 'A' && str[*str_index] <= 'F')
        number = number * BASE_16 + (str[*str_index] - 55);
      (*str_index)++;
    }
    if (!error) *value = number * sign;

  } else
    error = ERROR;

  return error;
}

/* **************************************************************************
 */

int s21_get_unsigned_decimal(const char *str, int *str_index,
                             unsigned long *value, int width) {
  int error = SKIP;
  // если ширина не задана, то устанавливается длина оставшейся строки
  if (width == -1)
    width = s21_strlen(str) - *str_index;
  else if (width == 0)
    width = 1;

  if (s21_strlen(str) - *str_index > 0) {
    unsigned long int number = 0;

    int sign = s21_get_sign(str, str_index, &width);

    while (str[*str_index] >= '0' && str[*str_index] <= '9' && width--) {
      error = OK;
      number = number * BASE_10 + (str[*str_index] - 48);
      (*str_index)++;
    }
    if (error != ERROR) *value = number * sign;
  } else
    error = ERROR;

  return error;
}

int s21_get_unsigned_octal(const char *str, int *str_index,
                           unsigned long *value, int width) {
  int error = SKIP;
  // если ширина не задана, то устанавливается длина оставшейся строки
  if (width == -1)
    width = s21_strlen(str) - *str_index;
  else if (width == 0)
    width = 1;

  if (s21_strlen(str) - *str_index > 0) {
    unsigned long int number = 0;
    int sign = s21_get_sign(str, str_index, &width);

    while (str[*str_index] >= '0' && str[*str_index] <= '7' && width--) {
      error = OK;
      number = number * BASE_8 + (str[*str_index] - 48);
      (*str_index)++;
    }

    if (!error) *value = number * sign;
  } else
    error = ERROR;

  return error;
}

int s21_get_unsigned_hex(const char *str, int *str_index, unsigned long *value,
                         int width) {
  int error = SKIP;
  // если ширина не задана, то устанавливается длина оставшейся строки
  if (width == -1)
    width = s21_strlen(str) - *str_index;
  else if (width == 0)
    width = 1;

  if (s21_strlen(str) - *str_index > 0) {
    unsigned long int number = 0;
    int sign = s21_get_sign(str, str_index, &width);

    // Проверка наличия префикса 0x
    if (str[*str_index] == '0' && width--) {
      error = OK;
      (*str_index)++;
      if ((str[*str_index] == 'x' || str[*str_index] == 'X') && width--)
        (*str_index)++;
    }

    while (((str[*str_index] >= '0' && str[*str_index] <= '9') ||
            (str[*str_index] >= 'a' && str[*str_index] <= 'f') ||
            (str[*str_index] >= 'A' && str[*str_index] <= 'F')) &&
           width--) {
      error = OK;
      if (str[*str_index] >= '0' && str[*str_index] <= '9')
        number = number * BASE_16 + (str[*str_index] - 48);
      if (str[*str_index] >= 'a' && str[*str_index] <= 'f')
        number = number * BASE_16 + (str[*str_index] - 87);
      if (str[*str_index] >= 'A' && str[*str_index] <= 'F')
        number = number * BASE_16 + (str[*str_index] - 55);
      (*str_index)++;
    }
    if (!error) *value = number * sign;
  } else
    error = ERROR;

  return error;
}

/* **************************************************************************
 */

/* Получает дробное число из 10-ой строки str */
int s21_get_float(s21_tocken tocken, const char *str, int *str_index,
                  va_list *args) {
  int error = OK;
  s21_skip_space(str, str_index);

  long double long_f = 0.0L;
  error = s21_get_float_value(str, str_index, &long_f, tocken.width);

  if (!error && tocken.save) {
    switch (tocken.length) {
      case 'd':
        float *result_f = va_arg(*args, float *);
        *result_f = (float)long_f;
        break;

      case 'l':
        double *result_lf = va_arg(*args, double *);
        *result_lf = (double)long_f;
        break;

      case 'L':
        long double *result_llf = va_arg(*args, long double *);
        *result_llf = long_f;
        break;
    }
  }
  return error;
}

/* Получает дробное число (float) из 10-ой строки str */
int s21_get_float_value(const char *str, int *str_index, long double *value,
                        int width) {
  int error = SKIP;

  // если ширина не задана, то устанавливается длина оставшейся строки
  if (width == -1)
    width = s21_strlen(str) - *str_index;
  else if (width == 0)
    width = 1;

  if (s21_strlen(str) - *str_index > 0) {
    long double integer_part = 0.0L;
    long double fractional_part = 0.0L;
    int point = 0;
    int exp = 0;
    int fractional_exp = 0;

    int sign = s21_get_sign(str, str_index, &width);

    while (str[*str_index] != '\0' && width--) {
      if (str[*str_index] >= '0' && str[*str_index] <= '9') {
        error = OK;
        if (point) {
          fractional_part *= 10.0L;
          fractional_part += (str[*str_index] - '0');
          fractional_exp++;
        } else {
          integer_part *= 10.0L;
          integer_part += (str[*str_index] - '0');
        }
      } else if (str[*str_index] == '.' && !fractional_exp) {
        error = OK;
        point = 1;
      } else {
        width++;
        break;
      }
      (*str_index)++;
    }

    s21_get_exp(str, str_index, &exp, &width);

    if (error != ERROR) {
      fractional_part = fractional_part * powl(0.1L, fractional_exp);
      *value = sign * (integer_part + fractional_part);
      fractional_part = powl(10.0L, (long double)exp);
      *value = *value * fractional_part;
    }
  } else
    error = ERROR;

  return error;
}

/* Получает экспоненту */
int s21_get_exp(const char *str, int *str_index, int *value, int *width) {
  int error = ERROR;

  if ((str[*str_index] == 'e' || str[*str_index] == 'E') && (*width)--) {
    error = OK;
    (*str_index)++;

    long int exp = 0;
    error = s21_get_signed_decimal(str, str_index, &exp, *width);

    if (!error) *value = (int)exp;
  }

  return error;
}
