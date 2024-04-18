#ifndef S21_SSCANF_H
#define S21_SSCANF_H

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

typedef struct s21_tocken {
  /* 0 - spase, 1 - symbol, 2 - specificator (diouxXfgGeEcspn%) */
  int type;
  /* 1 - сохранять результат, 0 (*)-  пропускать */
  int save;
  /* ширина: default strlen(str) - str_cur_char */
  int width;
  /* длина: d - default(int, float), h - short, l - long(long int, double),
  ll,L - long long */
  char length;
  /* тип спецификатора: diouxXfgGeEcsn% */
  char value;
} s21_tocken;

#define SPACE 0
#define SYMBOL 1
#define SPECIFIER 2

#define OK 0
#define ERROR -1
#define WRONG_FORMAT -2
#define SKIP 1

/* Функция возвращает 0, если нет ошибок; 1 - если есть ошибка, -1 - если
 * пропускает символы */
int s21_parse(const char *str, int *str_cur_char, const char *format,
              int *format_cur_char, va_list *args);

/* Получает следующий токен */
int s21_get_token(s21_tocken *tocken, const char *format, int *format_cur_char);

/* Устанавливает значения обнаруженного спецификатора */
int s21_get_specificator(s21_tocken *tocken, const char *format,
                         int *format_cur_char);

/* Проверяет наличие знака *. есть - 0, нет -1 */
void s21_get_save(s21_tocken *tocken, const char *format, int *format_cur_char);

/* Получает ширину для считывания из строки */
void s21_get_width(s21_tocken *tocken, const char *format,
                   int *format_cur_char);

/* Получет длину аргумента для сохранения: d - default(int, float), h - short
 * (i, d, o, u, x и X), l - long (i, d, o, u, x и X && c, s), L - long
 * double (e, E, f, g и G) */
void s21_get_length(s21_tocken *tocken, const char *format,
                    int *format_cur_char);

/* Получает значение спецификатора (diouxXfgGeEcspn%) */
int s21_get_value(s21_tocken *tocken, const char *format, int *format_cur_char);

/* Устанавливает значения токена по умолчанию */
void s21_tocken_init(s21_tocken *tocken);

/* Запускает обработку токена по значению tocken.type */
int s21_token_run(s21_tocken tocken, const char *str, int *str_index,
                  va_list *args);

/* Пропускает знаки разделители */
void s21_skip_space(const char *str, int *str_index);

/* Сверяет символы формата с символами строки, пропуская разделители */
int s21_check_symbol(const char *str, int *str_index, char symbol);

/* Обработка спецификаторов */
int s21_specifier_run(s21_tocken tocken, const char *str, int *str_index,
                      va_list *args);

/* **************************************************************** */

/* Получает символы из строки str */
int s21_get_char(s21_tocken tocken, const char *str, int *str_index,
                 va_list *args);

/* Получает обычные символы из строки str */
int s21_get_char_short(s21_tocken tocken, const char *str, int *str_index,
                       va_list *args);

/* Получает широкие символы из строки str */
int s21_get_char_long(s21_tocken tocken, const char *str, int *str_index,
                      va_list *args);

/* **************************************************************** */

/* Получает слово из строки str */
int s21_get_string(s21_tocken tocken, const char *str, int *str_index,
                   va_list *args);

/* Получает слово обычных символов из строки str */
int s21_get_string_short(s21_tocken tocken, const char *str, int *str_index,
                         va_list *args);

/* Получает слово широких символов из строки str */
int s21_get_string_long(s21_tocken tocken, const char *str, int *str_index,
                        va_list *args);

/* **************************************************************** */

/* Проверяет наличие знака % в строке str. не учитывается в количестве
 * полученных аргументов */
int s21_get_percent(const char *str, int *str_index);

/* получает значение указателя из строки */
int s21_get_pointer(s21_tocken tocken, const char *str, int *str_index,
                    va_list *args);

/* Возвращяет количество обработанных символов из строки str. не учитывается в
 * количестве полученных аргументов */
int s21_get_number(s21_tocken tocken, const int str_index, va_list *args);

/* **************************************************************** */

/* Получает знак числа, если он есть: 1 - положительное, -1 - отрицательное */
int s21_get_sign(const char *str, int *str_index, int *width);

/* *************************************************************** */
#define BASE_8 8
#define BASE_10 10
#define BASE_16 16

/* Проверяет основание целого числа */
int s21_check_base(const char *str, int str_index, int width);

/* Получает беззнаковое целое число по заданному основанию base (8,10,16). */
int s21_get_signed_int_base(const char *src, int *index, int base, int *value);

/* **************************************************************** */

/* Получает знаковое целое число по основанию 10 */
int s21_get_decimal(s21_tocken tocken, const char *str, int *str_index,
                    va_list *args);

/* Получает знаковое целое число по основаниям 8, 10, 16*/
int s21_get_integer(s21_tocken tocken, const char *str, int *str_index,
                    va_list *args);

int s21_get_unsigned_base(s21_tocken tocken, const char *str, int *str_index,
                          va_list *args);

/* **************************************************************** */

/* Получае signed long int из 10-ой строки str */
int s21_get_signed_decimal(const char *str, int *str_index, long *value,
                           int width);

/* Получает signed long int из 8-ой строки str */
int s21_get_signed_octal(const char *str, int *str_index, long *value,
                         int width);

/* Получает signed long int из 16-ой строки str */
int s21_get_signed_hex(const char *str, int *str_index, long *value, int width);

/* **************************************************************** */

/* Получае signed long int из 10-ой строки str */
int s21_get_unsigned_decimal(const char *str, int *str_index,
                             unsigned long *value, int width);

/* Получает unsigned long int из 8-ой строки str */
int s21_get_unsigned_octal(const char *str, int *str_index,
                           unsigned long *value, int width);

/* Получает unsigned long int из 16-ой строки str */
int s21_get_unsigned_hex(const char *str, int *str_index, unsigned long *value,
                         int width);

/* **************************************************************** */

/* Получает дробное число из строки str */
int s21_get_float(s21_tocken tocken, const char *str, int *str_index,
                  va_list *args);

/* Получает дробное число (long double) из строки str */
int s21_get_float_value(const char *str, int *str_index, long double *value,
                        int width);

/* Получает экспоненту из строки str */
int s21_get_exp(const char *str, int *str_index, int *value, int *width);

#endif