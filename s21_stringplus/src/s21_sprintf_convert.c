#include "s21_sprintf_convert.h"

#include "s21_string.h"

void s21_ushorttostring(unsigned short number, char** str) {
  /* перевод int в string */

  unsigned short counter = 10;
  *str = malloc(sizeof(char));
  if (*str == s21_NULL) {
    printf("alloc failed");
  }
  (*str)[0] = '\0';
  if (number < 10) {
    s21_insertcharatindex(str, 0, number + '0');
    return;
  }

  unsigned short i = 0;
  int found = 0;
  while (number != 0 && !found) {
    int cRes = number % counter;
    if (i == 4) {
      int count = 0;
      while (number > 0) {
        number -= 10000;
        count++;
      }
      s21_insertcharatindex(str, 0, count + '0');
      found = 1;
    }
    if (cRes == 0) {
      s21_insertcharatindex(str, 0, '0');
      i++;
      counter *= 10;

    } else {
      s21_insertcharatindex(str, 0, (cRes / (counter / 10)) + '0');

      number -= cRes;
      counter *= 10;
      i++;
    }
  }
}

/*перевод int в string*/

void s21_longuinttostring(unsigned long number, char** str) {
  unsigned long counter = 10;
  *str = malloc(sizeof(char));
  if (*str == s21_NULL) {
    printf("alloc failed");
  }

  (*str)[0] = '\0';
  if (number < 10) {
    s21_insertcharatindex(str, 0, number + '0');
    return;
  }

  unsigned long i = 0;
  while (number != 0) {
    int cRes = number % counter;
    if (i == 9) {
      int count = 0;
      while (number > 0) {
        number -= 1000000000;
        count++;
      }
      s21_insertcharatindex(str, 0, count + '0');
      break;
    }
    if (cRes == 0) {
      s21_insertcharatindex(str, 0, '0');
      i++;
      counter *= 10;

    } else {
      s21_insertcharatindex(str, 0, (cRes / (counter / 10)) + '0');
      number -= cRes;
      counter *= 10;
      i++;
    }
  }
}

/*перевод int в string*/

void s21_longinttostring(long long int number, char** str) {
  int LowerZero = 0;
  if (number < 0) {
    number *= -1;
    LowerZero = 1;
  }
  long counter = 10;
  *str = malloc(sizeof(char));
  if (*str == s21_NULL) {
    printf("alloc failed");
  }
  (*str)[0] = '\0';
  if (number < 10) {
    s21_insertcharatindex(str, 0, number + '0');
    if (LowerZero) s21_insertcharatindex(str, 0, '-');
    return;
  }
  long i = 0;
  while (number != 0) {
    long cRes = number % counter;
    if (i == 18) {
      int count = 0;
      while (number > 0) {
        number -= 1000000000000000000;
        count++;
      }
      s21_insertcharatindex(str, 0, count + '0');
      break;
    }
    if (cRes == 0) {
      s21_insertcharatindex(str, 0, '0');
      i++;
      counter *= 10;

    } else {
      s21_insertcharatindex(str, 0, (cRes / (counter / 10)) + '0');

      number -= cRes;
      counter *= 10;
      i++;
    }
  }
  if (LowerZero) s21_insertcharatindex(str, 0, '-');
}

void s21_uinttostring(unsigned int number, char** str) {
  unsigned int counter = 10;
  *str = malloc(sizeof(char));
  if (*str == s21_NULL) {
    printf("alloc failed");
  }
  (*str)[0] = '\0';
  if (number < 10) {
    s21_insertcharatindex(str, 0, number + '0');
    return;
  }

  int i = 0;
  while (number != 0) {
    unsigned int cRes = number % counter;

    if (i == 9) {
      int count = 0;
      while (number > 0) {
        number -= 1000000000;
        count++;
      }
      s21_insertcharatindex(str, 0, count + '0');
      break;
    }
    if (cRes == 0) {
      s21_insertcharatindex(str, 0, '0');
      i++;
      counter *= 10;

    } else {
      s21_insertcharatindex(str, 0, (cRes / (counter / 10)) + '0');
      number -= cRes;
      counter *= 10;
      i++;
    }
  }
}

/* перевод int в string */

void s21_intostring(int number, char** str) {
  int LowerZero = 0;
  if (number < 0) {
    number *= -1;
    LowerZero = 1;
  }
  int counter = 10;
  *str = malloc(sizeof(char));
  if (*str == s21_NULL) {
    printf("alloc failed");
  }
  (*str)[0] = '\0';
  if (number < 10) {
    s21_insertcharatindex(str, 0, number + '0');
    if (LowerZero) s21_insertcharatindex(str, 0, '-');
    return;
  }
  int i = 0;
  while (number != 0) {
    int cRes = number % counter;
    if (i == 9) {
      int count = 0;
      while (number > 0) {
        number -= 1000000000;
        count++;
      }
      s21_insertcharatindex(str, 0, count + '0');
      break;
    }
    if (cRes == 0) {
      s21_insertcharatindex(str, 0, '0');
      i++;
      counter *= 10;

    } else {
      s21_insertcharatindex(str, 0, (cRes / (counter / 10)) + '0');
      number -= cRes;
      counter *= 10;
      i++;
    }
  }
  if (LowerZero) s21_insertcharatindex(str, 0, '-');
}

void s21_convertpointertostring(char* str, void* pointer) {
  unsigned long long numAddress =
      (unsigned long long)pointer;  // перевод адреса в число
  if (pointer == s21_NULL) {
    s21_strcpy(str, "(nil)");
    return;
  }
  char hexDigits[] = "0123456789abcdef";
  // каждый символ имеет десятичное значение по индексу
  int size = sizeof(void*) * 2;  // размер указателя в байтах * 2
  // OxF - представление числа 15 (шестнадцатеричная система)
  int zeroEnd = 0;
  str[0] = '0';
  str[1] = 'x';
  int j = 2;
  int len = 0;
  for (int i = 0; i < size; i++) {
    int digit = (numAddress >> (size - i - 1) * 4) &
                0xF;  // битовый сдвиг вправо, за один раз делит address на 2
    //& оператор И , например 30 & 0xF = 14, работает почти как выражение 10 %
    // 15 = 10 умножение на 4 используется для преобразования смещения в битах в
    // смещение в байтах.
    if (digit == 0 && zeroEnd == 0) continue;
    len++;
    zeroEnd = 1;
    str[j] = hexDigits[digit];
    j++;
  }
  str[len + 2] = '\0';
}

void s21_insertcharatindex(char** str, int index, char ch) {
  // вставить символ по индексу и сдвинуть вправо строку
  int len = s21_strlen(*str);

  *str = realloc(*str, sizeof(char) * (len + 2));

  if (*str == s21_NULL) {
    free(str);
    printf("error");
    exit(1);
  }
  if (index == len) {
    (*str)[index] = ch;
    (*str)[index + 1] = '\0';
  } else if (index >= 0 && index <= len) {
    s21_memmove(*str + index + 1, *str + index, len - index + 1);
    (*str)[index] = ch;
  }
}

void s21_converttoo(unsigned int number, char** str) {
  int index = 0;
  *str = malloc(12 * sizeof(char));

  if (number == 0) {
    (*str)[index++] = '0';
  }
  while (number != 0) {
    int digit = number % 8;
    (*str)[index++] = digit + '0';  // Конвертируем цифру в символ ASCII
    number /= 8;
  }
  (*str)[index] = '\0';

  // переворачиваем строку
  int start = 0;
  int end = index - 1;
  while (start < end) {
    char temp = (*str)[start];
    (*str)[start] = (*str)[end];
    (*str)[end] = temp;
    start++;
    end--;
  }
}

void s21_convertox(unsigned int number, char** str, int XSpec) {
  *str = malloc(sizeof(char) * 9);
  int remainder = 0;
  int index = 0;
  if (number == 0) {
    (*str)[index] = '0';
    index++;
  }

  while (number != 0) {
    remainder = number % 16;
    if (remainder < 10) {
      (*str)[index] = remainder + '0';
      index++;
    } else {
      if (XSpec) {
        (*str)[index] = remainder - 10 + 'A';
      } else {
        (*str)[index] = remainder - 10 + 'a';
      }
      index++;
    }
    number /= 16;
  }

  /*переворачиваем строку*/
  int start = 0;
  int end = index - 1;
  while (start < end) {
    char temp = (*str)[start];
    (*str)[start] = (*str)[end];
    (*str)[end] = temp;
    start++;
    end--;
  }
  (*str)[index] = '\0';
}

int s21_infinitycheck(double number, char** str) {
  int res = 1;
  int minus = 0;
  if (number < 0) minus = 1;
  if (number == -INFINITY || number == INFINITY) {
    res = 0;
    if (*str == s21_NULL) *str = malloc(sizeof(char) * 5);
    s21_strcpy(*str, "inf");
  }
  if (number == -NAN || number == NAN) {
    res = 0;
    if (*str == s21_NULL) *str = malloc(sizeof(char) * 5);
    s21_strcpy(*str, "nan");
  }
  if (res == 0 && minus) {
    s21_insertcharatindex(str, 0, '-');
  }
  return res;
}

void s21_getintegerstring(double number, char** numString, int lf) {
  if (lf) {
    s21_longinttostring((long int)number, numString);
  } else {
    s21_intostring((int)number, numString);
  }
}

int s21_getfloatafterdotstring(long double number, char** floatString,
                               int fillZero, int maxO, int precision, int e) {
  if (number < 0) number *= -1;
  int res = 0;
  number = fabsl(number - floor(number));
  long double floatNum = number * 10000000000;
  floatNum = round(floatNum);
  long int intFloatNum = (long int)floatNum;
  s21_longinttostring(intFloatNum, floatString);
  int lenFloat = s21_strlen(*floatString);
  while (lenFloat < 10) {
    s21_insertcharatindex(floatString, 0, '0');
    lenFloat++;
  }
  if (precision == 0 && ((*floatString)[0] - '0') > 4) {
    res = 1;
  }
  {
    if (maxO < lenFloat) {
      while (lenFloat != maxO) {
        (*floatString)[lenFloat - 1] = '\0';
        lenFloat--;
      }
    }
    if (fillZero != 1) {
      while ((*floatString)[lenFloat - 1] == '0') {
        (*floatString)[lenFloat - 1] = '\0';
        lenFloat--;
        if (lenFloat == 0) break;
      }
    }
    if (precision < 10 && precision > 0 && e == 0)
      res = s21_convertdoublestringtoprecision(precision, *floatString);
    s21_insertcharatindex(floatString, 0, '.');
  }
  return res;
}

int s21_convertdoublestringtoprecision(int precison, char* str) {
  int len = s21_strlen(str);
  int res = 0;
  int nextNum = 0;
  int num = 0;
  while (precison != len) {
    if (len != 0) {
      if (len > 1) nextNum = str[len - 2] - '0';
      num = str[len - 1] - '0';
      if (num > 5) {
        nextNum++;
      }
      if (nextNum == 10) {
        if (s21_countnine(str, len - 2)) {
          res = 1;
        }
      } else {
        if (len > 1) str[len - 2] = nextNum + '0';
      }
    }
    if (len - 1 > -1) str[len - 1] = '\0';
    len--;
    if (len < 0) break;
  }
  return res;
}

void s21_doubletostring(double number, char** str, int fillZero, int maxO,
                        int precision, int sharp, int e, int longD,
                        long double numberLong) {
  char* floatString;
  char* numString;

  if (precision == -1) precision = 6;
  int additionNum = 0;
  if (longD)
    s21_getfloatafterdotstring(numberLong, &floatString, fillZero, maxO,
                               precision, e);
  if (longD == 0)
    s21_getfloatafterdotstring(number, &floatString, fillZero, maxO, precision,
                               e);

  s21_get_double_string_before_dot(number + additionNum, &numString);
  int lenInt = s21_strlen(numString);
  int lenFloat = s21_strlen(floatString);
  while (precision + 1 > lenFloat) {
    s21_insertcharatindex(&floatString, lenFloat, '0');
    lenFloat++;
  }
  *str = malloc((lenFloat + lenInt) * sizeof(char) + 2);
  if (*str == s21_NULL) {
    printf("alloc failed");
  }
  if (number < 0) s21_insertcharatindex(&numString, 0, '-');
  s21_strcpy(*str, numString);
  free(numString);

  if (precision == 0 && sharp) {
    s21_strcat(*str, ".");
  }
  if (precision != 0) s21_strcat(*str, floatString);
  free(floatString);
}

int s21_countnine(char* str, int i) {
  int result = 0;
  int found = 1;
  while (str[i] == '9' && found) {
    str[i] = '0';
    if (i == 0) {
      result = 1;
      found = 0;
    } else {
      i--;
    }
  }
  if (found) {
    int num = str[i] - '0';
    num++;
    str[i] = num + '0';
  }
  return result;
}

void s21_longdoubletostring(long double number, char** str, int fillZero,
                            int maxO) {
  char* floatString;
  char* numString;
  int intNum = (int)number;
  long double floatNum = (number - intNum) * 1000000;
  floatNum = round(floatNum);
  int intFloatNum = (int)floatNum;
  if (intFloatNum < 0) intFloatNum *= -1;
  s21_intostring(intNum, &numString);
  s21_intostring(intFloatNum, &floatString);
  int lenInt = s21_strlen(numString);
  int lenFloat = s21_strlen(floatString);
  while (lenFloat < 6) {
    s21_insertcharatindex(&floatString, 0, '0');
    lenFloat++;
  }
  if (maxO < lenFloat) {
    while (lenFloat != maxO) {
      floatString[lenFloat - 1] = '\0';
      lenFloat--;
    }
  }
  if (fillZero != 1) {
    while (floatString[lenFloat - 1] == '0') {
      floatString[lenFloat - 1] = '\0';
      lenFloat--;
    }
  }
  s21_insertcharatindex(&floatString, 0, '.');
  *str = malloc((lenFloat + lenInt) * sizeof(char) + 2);
  if (*str == s21_NULL) {
    printf("alloc failed");
  }
  s21_strcpy(*str, numString);
  s21_strcat(*str, floatString);
  free(floatString);
  free(numString);
}

void s21_get_double_string_before_dot(long double number, char** str) {
  if (number < 0) number *= -1;
  number = roundl(number);
  long double counter = 10;
  if (number < 11) {
    counter = 100;
    s21_intostring((int)number, str);
  } else {
    *str = malloc(sizeof(char));
    (*str)[0] = '\0';
  }

  while (counter < number * 10) {
    long double remainder = fmodl(number, counter);

    if (remainder == 0) {
      s21_insertcharatindex(str, 0, '0');
    } else {
      s21_insertcharatindex(str, 0, (remainder / (counter / 10.0)) + '0');
    }
    counter *= 10;
  }
}