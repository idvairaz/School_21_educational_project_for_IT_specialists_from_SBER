#include "../s21_decimal.h"

int count_zeros_before_non_zero(const char *str);
void get_exp_and_znak(int *exp, bool *znak, const char *str_src);
void get_base_digts(const char *str_src, char *str_src1);
void do_exp_shift(s21_decimal *dst, int exp);
void exp_get_and_set(bool znak, s21_decimal *dst, int *error, int *exp,
                     int zero_count);

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int error = 0;
  if (isnan(src)) {
    decimal_to_zero(dst);
    error = 1;
  }
  if (src != 0 && !error) {
    float max_f = 7.92281577919e+28;
    float min_f = -7.92281577919e+28;
    float max_f_to_zero = 1.0e-28;
    float min_f_to_zero = -1.0e-28;
    if (src > max_f || src < min_f)
      error = 1;
    else if (src < max_f_to_zero && min_f_to_zero < src) {
      decimal_to_zero(dst);
      error = 1;
    } else {
      decimal_to_zero(dst);
      bool sign = 0;
      if (src < 0) {
        sign = 1;
        src = fabs(src);
      }
      char str_src[128] = {'\0'};
      sprintf(str_src, "%e", src);
      int exp = 0;
      bool znak = 0;
      get_exp_and_znak(&exp, &znak, str_src);
      int zero_count = count_zeros_before_non_zero(str_src);
      // после функции ниже exp будет выступать в роли shift
      exp_get_and_set(znak, dst, &error, &exp, zero_count);
      if (!error) {
        char str_src1[128] = {'\0'};
        int int_src = 0;
        set_sign(dst, sign);
        get_base_digts(str_src, str_src1);
        sscanf(str_src1, "%d", &int_src);
        dst->bits[0] = int_src;
        if (exp) {
          do_exp_shift(dst, exp);  // делаем сдвиг по 10 если требуется
        }
      }
    }
  } else if (src == 0 && !error) {
    decimal_to_zero(dst);
  }
  return error;
}

int count_zeros_before_non_zero(const char *str) {
  int count = 0;
  int i;
  // Находим позицию символа 'e' в строке
  const char *ptr_e = strchr(str, 'e');
  // Перебираем символы перед 'e'
  for (i = ptr_e - str - 1; i >= 0 && str[i] == '0'; i--) {
    count++;
  }
  return count;
}

void get_exp_and_znak(int *exp, bool *znak, const char *str_src) {
  int i = 3;
  for (; str_src[i] != '\0'; i++) {
    if (str_src[i - 2] == 'e') {
      *exp = (str_src[i] - '0') * 10;
    }
    if (str_src[i - 3] == 'e') {
      *exp += str_src[i] - '0';
    }
  }
  if (str_src[i - 3] == '-' ||
      str_src[i - 4] == '-') {  // смотрим знак экспоненты флоата
    *znak = 1;
  }
}

void get_base_digts(const char *str_src, char *str_src1) {
  int flag = 0;
  int i = 0;
  for (; str_src[i] != 'e'; i++) {
    if (str_src[i] == '.') {
      flag = 1;
    }
    if (flag == 0) {
      str_src1[i] = str_src[i];
    }
    if (flag == 1 && str_src[i + 1] != 'e') {
      str_src1[i] = str_src[i + 1];
    }
  }
}

void do_exp_shift(s21_decimal *dst, int exp) {
  t_bcd bcd_val = {0};
  decimal_to_bcd2(&bcd_val, dst);
  bcd_2_to_10(&bcd_val);
  shift_bcd_10(&bcd_val, exp);
  from_bcd_10_to_decimal(&bcd_val, dst, 0);
}

void exp_get_and_set(bool znak, s21_decimal *dst, int *error, int *exp,
                     int zero_count) {
  if (znak) {          // если < +-1
    if (*exp <= 22) {  // если не нужно ничего сдвигать и все помещается
      *error = set_exp(dst, 6 + *exp);
      *exp = 0;
    } else if (zero_count - 6 < *exp - 28) {  // если не помещается с учетом
                                              // округлений и сдвигов
      *error = 1;
    } else {  // если помещается со сдвигами без потери базы
      *error = set_exp(dst, *exp - zero_count + 6);
      *exp = zero_count;  // на сколько нужно сделать сдвиг
    }
  } else {  // если > +-1
    if (*exp <= 6) {
      *error = set_exp(dst, 6 - *exp);
      *exp = 0;
    } else {
      *exp = 6 - *exp;  // на сколько нужно сделать сдвиг
    }
  }
}