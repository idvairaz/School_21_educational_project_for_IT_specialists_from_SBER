#include "../s21_decimal.h"

void prnt(s21_decimal a) {
  printf("\n");
  for (int i = 127; i >= 0; i--) {
    printf("%d", get_bit(a, i));
    if (i % 32 == 0) printf(" ");
  }
  printf("\n");
}