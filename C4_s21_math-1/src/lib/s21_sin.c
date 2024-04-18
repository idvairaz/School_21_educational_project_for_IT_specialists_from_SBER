#include "../s21_math.h"

/*computes sinus of a double x number (radians)
returns: long double computed result*/
long double s21_sin(double x) { return s21_common_sin_cos(x, 1); }