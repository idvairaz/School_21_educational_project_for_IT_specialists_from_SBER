#include "../s21_math.h"

/*computes cosinus of a double x number (radians)
returns: long double computed result*/
long double s21_cos(double x) { return s21_common_sin_cos(x, -1); }