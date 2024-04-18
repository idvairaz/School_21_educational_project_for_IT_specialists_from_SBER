#ifndef SRC_S21_DECIMAL_H
#define SRC_S21_DECIMAL_H

#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define _DIRECT_MEM_VIEW 0
#define _NORMAL_BIT_VIEW 1

#define _NO_HIGH_INT 1
#define _YES_HIGH_INT 0
#define _NEGATIVE 0x80000000
#define _POINT_DECIMAL 0xFF0000
#define _HIGH_4BIT_INT 0xF0000000
#define _LOW_4BIT_INT 0x0F
#define _VALUE_INT 0xFFFFFFFF
#define _MINUS 1
#define _PLUS 0
#define MAX_EXP10 28
#define _NO_BANK_ROUND 1
#define _BANK_ROUND 0
#define _MAX_INT 0x8FFFFFFF
#define _MIN_INT 0x80000000

#define _NO_ERROR 0
#define _ERR_BIG_NUM 1
#define _ERR_SMALL_NUM 2
#define _ERR_DIV_0 3
#define _ERR_NUMBER 4
#define _ERR_CALCULATE 1

#define _BCD10_MORE 8
#define _BCD10_LESS 16
#define _BCD10_ZERO 32
#define _BCD10_MORE_OR_EQUAL 64
#define _BCD10_EQUAL 128

#define _1BIT 1
#define _2BIT 2
#define _8BIT 0x80
#define _31BIT 0x40000000
#define _32BIT 0x80000000
#define _INT_VALUE 0xFFFFFFFF
#define _DECIMAL_MAX 79228162514264337593543950335

#define _MAX_DIGIT_DECIMAL                                            \
  (_MAX_DECIMAL_DIGIT_INT * 4 / 3 * _SIZE_INT_BYTE * _SIZE_BYTE / 4 - \
   3)  // 29 digit in decimal
#define _SIZE_BYTE 8
#define _SIZE_INT_BYTE 4
#define _MAX_DECIMAL_INT 4
#define _MAX_DECIMAL_DIGIT_INT (_MAX_DECIMAL_INT - 1)
// #define _MAX_BCD_INT (_MAX_DECIMAL_DIGIT_INT * 4 / 3 * 3)  // 12INT
#define _BEGIN_BCD_10 (2 * _MAX_DECIMAL_DIGIT_INT)      // 6INT
#define _MAX_BCD_INT (_BEGIN_BCD_10 * 3)                // 18INT=
#define _MAX_BCD_BYTES (_MAX_BCD_INT * _SIZE_INT_BYTE)  // 48 bytes
#define _SIZE_DECIMAL_BITS \
  (_SIZE_BYTE * _SIZE_INT_BYTE * _MAX_DECIMAL_DIGIT_INT)  // 96 bits
#define _SIZE_INT_BITS (_SIZE_BYTE * _SIZE_INT_BYTE)      // 32 bits

struct s_bits_8_1 {
  unsigned char a0 : 1;
  unsigned char a1 : 1;
  unsigned char a2 : 1;
  unsigned char a3 : 1;
  unsigned char a4 : 1;
  unsigned char a5 : 1;
  unsigned char a6 : 1;
  unsigned char a7 : 1;
};

struct s_bits_2_4 {
  unsigned char a0 : 4;
  unsigned char a1 : 4;
};

typedef union {
  struct s_bits_2_4 bits_4[_SIZE_INT_BYTE * _MAX_BCD_INT];
  unsigned int bits[_MAX_BCD_INT];
} t_bcd;

typedef struct {
  unsigned int bits[_MAX_DECIMAL_INT];
} s21_decimal;

union decimal_bits {
  struct s_bits_8_1 bits_8[_SIZE_INT_BYTE * _MAX_DECIMAL_INT];
  struct s_bits_2_4 bits_4[_SIZE_INT_BYTE * _MAX_DECIMAL_INT];
  s21_decimal nums;
};

struct sign_and_exp_bits {
  unsigned int unused1 : 16;
  unsigned int exp : 8;
  unsigned int unused2 : 7;
  unsigned int sign : 1;
};

union union_decimal {
  unsigned int num_3_bits;
  struct sign_and_exp_bits sign_and_exp;
};

int shift_ints(unsigned int *value, short num_direction, short COUNT_INT);
void print_decimal_10(s21_decimal value);
void bcd_10_to_2(t_bcd *bcd10);
void bcd_2_to_10(t_bcd *bcd2);
void shift_bcd_10(t_bcd *bcd10, short shift_10);
int from_bcd_10_to_decimal(t_bcd *bcd10, s21_decimal *value, short point);
void decimal_to_bcd2(t_bcd *bcd2, s21_decimal *value);
short bcd_2_to_10_align_point(s21_decimal value_1, s21_decimal value_2,
                              t_bcd *bcd2_1, t_bcd *bcd2_2);
short bcd_10_count_digit(t_bcd *bcd10);
short bcd_10_to_2_N_INT_with_bank(t_bcd *bcd10, short N_INT, short *point,
                                  short next_10razryad, short bank_round);
bool get_sign(s21_decimal);
bool get_bit(s21_decimal dst, int bit);
int get_exp_10(s21_decimal dst);
bool get_bit_bcd(t_bcd dst, int bit);
void set_sign(s21_decimal *, bool sign);
bool set_bit(s21_decimal *dst, int bit, bool value);
bool set_exp(s21_decimal *dst, int exp);
int bcd_10_add(t_bcd bcd1, t_bcd bcd2, t_bcd *res_bcd);
int bcd_10_sub(t_bcd bcd1, t_bcd bcd2, t_bcd *res_bcd);
short decimal_bcd_is_zero(void *value, short size_int);
void decimal_to_zero(s21_decimal *dst);
int is_bad_decimal(s21_decimal decimal);
void set_bad_exp(s21_decimal *dst, int exp);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_is_less(s21_decimal, s21_decimal);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal, s21_decimal);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int s21_is_equal(s21_decimal, s21_decimal);
int s21_is_not_equal(s21_decimal, s21_decimal);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

#endif  //  SRC_S21_DECIMAL_H