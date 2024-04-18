#include "test_s21_decimal.h"

START_TEST(test_mul_1) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal answer = {0};

  int error = s21_mul(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_mul_2) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  set_sign(&value_1, 1);

  s21_decimal value_2 = {{1, 0, 0, 0}};

  s21_decimal answer = {{1, 0, 0, 0}};
  set_sign(&answer, 1);

  s21_decimal result = {0};

  int error = s21_mul(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_mul_3) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};

  s21_decimal value_2 = {0};
  value_2.bits[0] = 1;
  set_sign(&value_2, 1);

  s21_decimal answer = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_sign(&answer, 1);

  s21_decimal result = {0};

  int error = s21_mul(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_mul_4) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};

  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};

  s21_decimal answer = {0};
  s21_decimal result = {0};

  int error = s21_mul(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _ERR_BIG_NUM);
}
END_TEST

START_TEST(test_mul_5) {
  s21_decimal value_1 = {0};
  value_1.bits[0] = 1;
  set_exp(&value_1, 28);
  set_sign(&value_1, 1);

  s21_decimal value_2 = {0};
  value_2.bits[0] = 3;
  set_sign(&value_2, 1);

  s21_decimal answer = {0};
  answer.bits[0] = 3;
  set_exp(&answer, 28);

  s21_decimal result = {0};

  int error = s21_mul(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_mul_6) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  set_exp(&value_1, 20);

  s21_decimal value_2 = {{1, 0, 0, 0}};
  set_exp(&value_2, 9);

  s21_decimal answer = {0};

  s21_decimal result = {0};

  int error = s21_mul(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _ERR_SMALL_NUM);
}
END_TEST

START_TEST(test_mul_7) {
  s21_decimal value_1 = {0};
  set_sign(&value_1, _MINUS);

  s21_decimal value_2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0, 0}};

  s21_decimal answer = {0};
  s21_decimal result = {0};

  int error = s21_mul(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_mul_8) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_sign(&value_1, _MINUS);

  s21_decimal value_2 = {0};

  s21_decimal answer = {0};
  s21_decimal result = {0};

  int error = s21_mul(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_mul_9) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_sign(&value_2, _MINUS);

  s21_decimal answer = {0};
  s21_decimal result = {0};

  int error = s21_mul(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _ERR_SMALL_NUM);
}
END_TEST

START_TEST(test_mul_10) {
  // 0,000..0123 * -0.1  = - 0.0012
  s21_decimal value_1 = {{123, 0, 0, 0}};
  set_exp(&value_1, 28);

  s21_decimal value_2 = {{1, 0, 0, 0}};
  set_exp(&value_2, 1);
  set_sign(&value_2, _MINUS);

  s21_decimal answer = {{12, 0, 0, 0}};
  set_exp(&answer, 28);
  set_sign(&answer, _MINUS);
  s21_decimal result = {0};

  int error = s21_mul(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_mul_11) {
  // 0,000..0126 * -0.1  = -0.0(0)013
  s21_decimal value_1 = {{126, 0, 0, 0}};
  set_exp(&value_1, 28);

  s21_decimal value_2 = {{1, 0, 0, 0}};
  set_exp(&value_2, 1);
  set_sign(&value_2, _MINUS);

  s21_decimal answer = {{13, 0, 0, 0}};
  set_exp(&answer, 28);
  set_sign(&answer, _MINUS);
  s21_decimal result = {0};

  int error = s21_mul(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_mul_12) {
  // 326927.6
  s21_decimal dec_1 = {{0x31e29c, 0x0, 0x0, 0x10000}};
  // 62176001689328668954
  s21_decimal dec_2 = {{0x2685d11a, 0x5edd881d, 0x3, 0x0}};
  // 20327051009888167352325730.4
  s21_decimal dec_check = {{0xa21e5fd8, 0x6ebd0d62, 0xa82434, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_mul_13) {
  // -5.3586740
  s21_decimal dec_1 = {{0x331ab34, 0x0, 0x0, 0x80070000}};
  // 4.802529423233
  s21_decimal dec_2 = {{0x2d0f6f81, 0x45e, 0x0, 0xc0000}};
  // -25.7351895545136730420
  s21_decimal dec_check = {{0x514ed134, 0xf379997d, 0xd, 0x80130000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_mul_14) {
  // -322537452084448658579484.134
  s21_decimal dec_1 = {{0x94936de6, 0x5019e1c3, 0x10acbf6, 0x80030000}};
  // -82.962020645
  s21_decimal dec_2 = {{0x50ebf925, 0x13, 0x0, 0x80090000}};
  // 26758358758615727896513719.098
  s21_decimal dec_check = {{0xb1d7ab3a, 0xe97149b3, 0x5675fede, 0x30000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_mul_15) {
  // -2.578350245659571517993289367
  s21_decimal dec_1 = {{0xf5688697, 0xe37d6441, 0x854c2e6, 0x801b0000}};
  // -9964435610
  s21_decimal dec_2 = {{0x51ed389a, 0x2, 0x0, 0x80000000}};
  // 25691805002.902482371234088310
  s21_decimal dec_check = {{0xf85dc576, 0xf606cae7, 0x5303c353, 0x120000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_mul_16) {
  // 29733005293342706
  s21_decimal dec_1 = {{0xc29d4ff2, 0x69a202, 0x0, 0x0}};
  // 397.2818994429
  s21_decimal dec_2 = {{0xfe7704fd, 0x39c, 0x0, 0xa0000}};
  // 11812384819084990341.900178487
  s21_decimal dec_check = {{0x1b389437, 0x2782a02b, 0x262af9c8, 0x90000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_mul_17) {
  // 8512000.4
  s21_decimal dec_1 = {{0x512d404, 0x0, 0x0, 0x10000}};
  // 65625950461
  s21_decimal dec_2 = {{0x479c88fd, 0xf, 0x0, 0x0}};
  // 558608116574412184.4
  s21_decimal dec_check = {{0x52ada7f4, 0x4d85bf39, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_mul_18) {
  // -8668740.8998243
  s21_decimal dec_1 = {{0x7c384763, 0x4ed7, 0x0, 0x80070000}};
  // -72
  s21_decimal dec_2 = {{0x48, 0x0, 0x0, 0x80000000}};
  // 624149344.7873496
  s21_decimal dec_check = {{0xefd413d8, 0x162c9a, 0x0, 0x70000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_mul_19) {
  // -686.0244053
  s21_decimal dec_1 = {{0x98e70455, 0x1, 0x0, 0x80070000}};
  // -47480680460
  s21_decimal dec_2 = {{0xe11b00c, 0xb, 0x0, 0x80000000}};
  // 32572905575810.8304380
  s21_decimal dec_check = {{0xed73a3fc, 0xa866126c, 0x11, 0x70000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_mul_20) {
  // 8852082.08
  s21_decimal dec_1 = {{0x34c33490, 0x0, 0x0, 0x20000}};
  // 587
  s21_decimal dec_2 = {{0x24b, 0x0, 0x0, 0x0}};
  // 5196172180.96
  s21_decimal dec_check = {{0xfb998630, 0x78, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_mul_21) {
  // -709742.522382
  s21_decimal dec_1 = {{0x3ff3700e, 0xa5, 0x0, 0x80060000}};
  // -816161672946286
  s21_decimal dec_2 = {{0x7298626e, 0x2e64b, 0x0, 0x80000000}};
  // 579264644428409955238.773252
  s21_decimal dec_check = {{0x6fcf8204, 0x4bf25207, 0x1df280f, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_mul_22) {
  // -0.20696824
  s21_decimal dec_1 = {{0x13bcef8, 0x0, 0x0, 0x80080000}};
  // 45964565401520159
  s21_decimal dec_2 = {{0x5903481f, 0xa34c87, 0x0, 0x0}};
  // -9513205203517520.63275016
  s21_decimal dec_check = {{0x9d5bd008, 0x305193c8, 0xc973, 0x80080000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_mul_23) {
  // -0.2
  s21_decimal dec_1 = {{0x2, 0x0, 0x0, 0x80010000}};
  // 8045779858826715
  s21_decimal dec_2 = {{0x1a6d25db, 0x1c9598, 0x0, 0x0}};
  // -1609155971765343.0
  s21_decimal dec_check = {{0x34da4bb6, 0x392b30, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_mul_24) {
  // -51409191962
  s21_decimal dec_1 = {{0xf83a041a, 0xb, 0x0, 0x80000000}};
  // -1447800319750
  s21_decimal dec_2 = {{0x179faf06, 0x151, 0x0, 0x80000000}};
  // 74430244560672729849500
  s21_decimal dec_check = {{0x5c4fde9c, 0xdf23f798, 0xfc2, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_mul_25) {
  // -7
  s21_decimal dec_1 = {{0x7, 0x0, 0x0, 0x80000000}};
  // 1901836495563741166
  s21_decimal dec_2 = {{0x62f357ee, 0x1a64ae37, 0x0, 0x0}};
  // -13312855468946188162
  s21_decimal dec_check = {{0xb4a76782, 0xb8c0c383, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_mul_26) {
  // -832626030524
  s21_decimal dec_1 = {{0xdc60f7bc, 0xc1, 0x0, 0x80000000}};
  // 28203.02
  s21_decimal dec_2 = {{0x2b08ce, 0x0, 0x0, 0x20000}};
  // -23482568591388982.48
  s21_decimal dec_check = {{0xfa593948, 0x2096af2b, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_mul_27) {
  // 577245649941368954948325
  s21_decimal dec_1 = {{0x3eb80ae5, 0x8ca49325, 0x7a3c, 0x0}};
  // 42.53
  s21_decimal dec_2 = {{0x109d, 0x0, 0x0, 0x20000}};
  // 24550257492006421653952262.25
  s21_decimal dec_check = {{0xf78cfe71, 0x8a2091c2, 0x7eebfec, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_mul_28) {
  // 109142629944753.383324
  s21_decimal dec_1 = {{0x1cefe79c, 0xeaa883ac, 0x5, 0x60000}};
  // 21573
  s21_decimal dec_2 = {{0x5445, 0x0, 0x0, 0x0}};
  // 2354533955798164738.448652
  s21_decimal dec_check = {{0x84a89d0c, 0x8a9ff6e2, 0x1f297, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_mul_29) {
  // -8605
  s21_decimal dec_1 = {{0x219d, 0x0, 0x0, 0x80000000}};
  // 513003427291221000
  s21_decimal dec_2 = {{0x2c404c08, 0x71e8de6, 0x0, 0x0}};
  int return_value = s21_mul(dec_1, dec_2, NULL);
  ck_assert_int_eq(return_value, _ERR_NUMBER);
}
END_TEST

START_TEST(test_mul_30) {
  // -8605
  s21_decimal dec_1 = {{0x219d, 0x0, 0x0, 0x80FF0000}};
  // 513003427291221000
  s21_decimal dec_2 = {{0x2c404c08, 0x71e8de6, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, _ERR_NUMBER);
}
END_TEST

START_TEST(test_mul_31) {
  // -8605
  s21_decimal dec_1 = {{0x219d, 0x0, 0x0, 0x80000000}};
  // 513003427291221000
  s21_decimal dec_2 = {{0x2c404c08, 0x71e8de6, 0x0, 0x801D0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, _ERR_NUMBER);
}
END_TEST

Suite *test_s21_mul(void) {
  Suite *s = suite_create("\033[45m-=S21_mul=-\033[0m");
  TCase *tc = tcase_create("S21 decimal mul");

  tcase_add_test(tc, test_mul_1);
  tcase_add_test(tc, test_mul_2);
  tcase_add_test(tc, test_mul_3);
  tcase_add_test(tc, test_mul_4);
  tcase_add_test(tc, test_mul_5);
  tcase_add_test(tc, test_mul_6);
  tcase_add_test(tc, test_mul_7);
  tcase_add_test(tc, test_mul_8);
  tcase_add_test(tc, test_mul_9);
  tcase_add_test(tc, test_mul_10);
  tcase_add_test(tc, test_mul_11);
  tcase_add_test(tc, test_mul_12);
  tcase_add_test(tc, test_mul_13);
  tcase_add_test(tc, test_mul_14);
  tcase_add_test(tc, test_mul_15);
  tcase_add_test(tc, test_mul_16);
  tcase_add_test(tc, test_mul_17);
  tcase_add_test(tc, test_mul_18);
  tcase_add_test(tc, test_mul_19);
  tcase_add_test(tc, test_mul_20);
  tcase_add_test(tc, test_mul_21);
  tcase_add_test(tc, test_mul_22);
  tcase_add_test(tc, test_mul_23);
  tcase_add_test(tc, test_mul_24);
  tcase_add_test(tc, test_mul_25);
  tcase_add_test(tc, test_mul_26);
  tcase_add_test(tc, test_mul_27);
  tcase_add_test(tc, test_mul_28);
  tcase_add_test(tc, test_mul_29);
  tcase_add_test(tc, test_mul_30);
  tcase_add_test(tc, test_mul_31);

  suite_add_tcase(s, tc);
  return s;
}