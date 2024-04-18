#include "../s21_decimal.h"

bool get_bit_bcd(t_bcd dst, int bit) {
  unsigned int mask = 1 << (bit % 32);
  return (dst.bits[bit / 32] & mask) != 0;
}