#include "../s21_decimal.h"

int is_bad_decimal(s21_decimal dec) {
  union union_decimal u = {dec.bits[3]};
  int unused1 = u.sign_and_exp.unused1;
  int exp = u.sign_and_exp.exp;
  int unused2 = u.sign_and_exp.unused2;
  int return_value = 0;
  if (unused1 != 0 || unused2 != 0) {
    return_value = 1;
  }
  if (exp > 28) {
    return_value = 1;
  }
  return return_value;
}