#ifndef S21_MATH_H
#define S21_MATH_H

#define S21_PI 3.141592653589793238462643
#define S21_E 2.7182818284590452354

#define S21_NAN __builtin_nan("")
#define S21_INF __builtin_inf()
#define S21_IS_INF __builtin_isinf
#define S21_IS_NAN __builtin_isnan

#define EPSILON 1e-6
#include <stdio.h>
#include <stdlib.h>
#define S21_MAX_INT 2147483647
#define S21_MIN_INT (-2147483648)
#define S21_MAX_DOUBLE 1.7976931348623158e+308
#define S21_MIN_DOUBLE 2.2250738585072014e-308

int s21_abs(int x);
long double s21_fabs(double x);

long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);

long double s21_floor(double x);
long double s21_ceil(double x);

long double s21_fmod(double x, double y);
long double s21_log(double x);

long double s21_exp(double x);
long double s21_pow(double base, double exp);
long double s21_sqrt(double x);

long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);

long double s21_ceil_or_floor(double x, int rounding);
long double s21_common_sin_cos(double x, int flag);

#endif
