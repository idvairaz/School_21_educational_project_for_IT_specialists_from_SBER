#include "test_s21_decimal.h"

START_TEST(test_div_1) {  // division by 0
  s21_decimal value_1 = {{11, 0, 0, 0}};

  s21_decimal value_2 = {0};
  set_exp(&value_2, 1);

  s21_decimal answer = {0};

  s21_decimal result = {0};

  int error = s21_div(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _ERR_DIV_0);
}
END_TEST

START_TEST(test_div_2) {
  s21_decimal value_1 = {{44, 0, 0, 0}};

  s21_decimal value_2 = {{2, 0, 0, 0}};
  set_exp(&value_2, 1);

  s21_decimal answer = {{220, 0, 0, 0}};

  s21_decimal result = {0};

  int error = s21_div(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_div_3) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_sign(&value_1, _MINUS);

  s21_decimal value_2 = {{1, 0, 0, 0}};

  s21_decimal answer = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_sign(&answer, _MINUS);

  s21_decimal result = {0};

  int error = s21_div(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_div_4) {
  s21_decimal value_1 = {{100, 0, 0, 0}};

  s21_decimal value_2 = {{100, 0, 0, 0}};

  s21_decimal answer = {{1, 0, 0, 0}};

  s21_decimal result = {0};

  int error = s21_div(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_div_5) {
  s21_decimal value_1 = {{28592016, 0, 0, 0}};

  s21_decimal value_2 = {{318, 0, 0, 0}};
  set_exp(&value_2, 1);

  s21_decimal answer = {{899120, 0, 0, 0}};

  s21_decimal result = {0};

  int error = s21_div(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_div_6) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  set_exp(&value_1, 28);

  s21_decimal value_2 = {{1, 0, 0, 0}};
  set_exp(&value_2, 1);

  s21_decimal answer = {{1, 0, 0, 0}};
  set_exp(&answer, 27);

  s21_decimal result = {0};

  int error = s21_div(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_div_7) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  set_exp(&value_1, 28);

  s21_decimal value_2 = {{10, 0, 0, 0}};

  s21_decimal answer = {{0, 0, 0, 0}};

  s21_decimal result = {0};

  int error = s21_div(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _ERR_SMALL_NUM);
}
END_TEST

START_TEST(test_div_8) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_sign(&value_1, _MINUS);
  s21_decimal value_2 = {{10, 0, 0, 0}};
  set_exp(&value_2, 5);

  s21_decimal answer = {{0, 0, 0, 0}};

  s21_decimal result = {0};

  int error = s21_div(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _ERR_SMALL_NUM);
}
END_TEST

START_TEST(test_div_9) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{10, 0, 0, 0}};
  set_exp(&value_2, 5);

  s21_decimal answer = {{0, 0, 0, 0}};

  s21_decimal result = {0};

  int error = s21_div(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _ERR_BIG_NUM);
}
END_TEST

START_TEST(test_div_10) {
  // 3.1 415 926 530 119 026 040 722 614 948
  s21_decimal value_1 = {{103993, 0, 0, 0}};
  set_exp(&value_1, 1);

  s21_decimal value_2 = {{33102, 0, 0, 0}};
  set_exp(&value_2, 1);
  s21_decimal answer = {{0x9712EAA4, 0xBAE16BD1, 0x6582A535, 0}};
  set_exp(&answer, 28);
  s21_decimal result = {0};

  int error = s21_div(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_div_11) {
  // 0.3 141 592 653 011 902 604 072 261 495
  s21_decimal value_1 = {{103993, 0, 0, 0}};
  set_exp(&value_1, 1);

  s21_decimal value_2 = {{33102, 0, 0, 0}};

  s21_decimal answer = {{0x28B51777, 0xF9168AC8, 0x0A26AA1E, 0}};
  set_exp(&answer, 28);
  s21_decimal result = {0};

  int error = s21_div(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_div_12) {
  // 0.1 / 100
  s21_decimal value_1 = {{1, 0, 0, 0}};
  set_exp(&value_1, 1);

  s21_decimal value_2 = {{100, 0, 0, 0}};

  s21_decimal answer = {{1, 0, 0, 0}};
  set_exp(&answer, 3);
  s21_decimal result = {0};

  int error = s21_div(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_div_13) {
  // 0.1 / 100
  s21_decimal value_1 = {{1, 0, 0, 0}};
  set_exp(&value_1, 1);

  s21_decimal value_2 = {{10000, 0, 0, 0}};
  set_exp(&value_2, 2);

  s21_decimal answer = {{1, 0, 0, 0}};
  set_exp(&answer, 3);
  s21_decimal result = {0};

  int error = s21_div(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_div_14) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  set_exp(&value_1, 28);

  s21_decimal value_2 = {{1, 0, 0, 0}};

  s21_decimal answer = {{1, 0, 0, 0}};
  set_exp(&answer, 28);

  s21_decimal result = {0};

  int error = s21_div(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_div_15) {
  // 65765765765 / 78676 = 835906.3216864100869388377650
  s21_decimal value_1 = {{0x4FF1F285, 0xF, 0, 0}};

  s21_decimal value_2 = {{78676, 0, 0, 0}};

  s21_decimal answer = {{0xA6C01E32, 0xFBBF3594, 0x1B02747C, 0}};
  set_exp(&answer, 22);

  s21_decimal result = {0};

  int error = s21_div(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_div_16) {
  // 92233720390022594565 / 65 = 1418980313692655301
  s21_decimal value_1 = {{0x5, 0x5, 0x5, 0}};

  s21_decimal value_2 = {{65, 0, 0, 0}};
  set_sign(&value_2, _MINUS);

  s21_decimal answer = {{0xC4EC4EC5, 0x13B13B13, 0, 0}};
  // set_exp(&answer, 1);
  set_sign(&answer, _MINUS);

  s21_decimal result = {0};

  int error = s21_div(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_div_17) {
  // 92233720390022594565 / 650 = 141898031369.2655301
  s21_decimal value_1 = {{0x5, 0x5, 0x5, 0}};

  s21_decimal value_2 = {{650000000, 0, 0, 0}};
  set_sign(&value_2, _MINUS);

  s21_decimal answer = {{0xC4EC4EC5, 0x13B13B13, 0, 0}};
  set_exp(&answer, 7);
  set_sign(&answer, _MINUS);

  s21_decimal result = {0};

  int error = s21_div(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_div_18) {
  // 302012.9519812
  s21_decimal dec_1 = {{0x2dbf48c4, 0x2bf, 0x0, 0x70000}};
  // 4577008043893937580006561
  s21_decimal dec_2 = {{0x42ffdca1, 0x1a6d859c, 0x3c938, 0x0}};
  s21_decimal dec_check = {{659847982, 0, 0, 0x001c0000}};
  // 659847982 * 10^-28
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_div_19) {
  // 9595870130562
  s21_decimal dec_1 = {{0x366e3182, 0x8ba, 0x0, 0x0}};
  // -42
  s21_decimal dec_2 = {{0x2a, 0x0, 0x0, 0x80000000}};
  // -228473098346.71428571428571429 ++
  s21_decimal dec_check = {{0x1df44925, 0xe8f6654b, 0x49d2da0b, 0x80110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_div_20) {
  // 9740340847528680
  s21_decimal dec_1 = {{0xd4354ae8, 0x229ac9, 0x0, 0x0}};
  // 4
  s21_decimal dec_2 = {{0x4, 0x0, 0x0, 0x0}};
  // 2435085211882170
  s21_decimal dec_check = {{0x750d52ba, 0x8a6b2, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_div_21) {
  // -487
  s21_decimal dec_1 = {{0x1e7, 0x0, 0x0, 0x80000000}};
  // -110.0143
  s21_decimal dec_2 = {{0x10c96f, 0x0, 0x0, 0x80040000}};
  // 4.4266972566293654552180943750
  s21_decimal dec_check = {{0xee03eb86, 0x495dfb20, 0x8f08c80f, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_div_22) {
  // 39
  s21_decimal dec_1 = {{0x27, 0x0, 0x0, 0x0}};
  // -0.28821045180284434
  s21_decimal dec_2 = {{0x8006be12, 0x666496, 0x0, 0x80110000}};
  // -135.31778516720367672293248837
  s21_decimal dec_check = {{0x8186cf45, 0x45633405, 0x2bb9398f, 0x801a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_div_23) {
  // 86080527930707095
  s21_decimal dec_1 = {{0xb9634c97, 0x131d1c8, 0x0, 0x0}};
  // -0.81474057
  s21_decimal dec_2 = {{0x4db3209, 0x0, 0x0, 0x80080000}};
  // -105653911318920935.77713946416
  s21_decimal dec_check = {{0xf9980f30, 0xeaf68c5c, 0x22237c98, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_div_24) {
  // -237882547664092164.802577081
  s21_decimal dec_1 = {{0xe81982b9, 0xbfaa21e3, 0xc4c596, 0x80090000}};
  // 14.944909225342701652
  s21_decimal dec_2 = {{0x49029054, 0xcf66fbc2, 0x0, 0x120000}};
  // -15917296256353626.736742609932
  s21_decimal dec_check = {{0xd49fb40c, 0xfcb88d8, 0x336e7a97, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_div_25) {
  // 582870155602414
  s21_decimal dec_1 = {{0x89329ee, 0x2121e, 0x0, 0x0}};
  // -29.3
  s21_decimal dec_2 = {{0x125, 0x0, 0x0, 0x80010000}};
  // -19893179372096.040955631399317
  s21_decimal dec_check = {{0x407c7195, 0xa4bd9097, 0x40474096, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_div_26) {
  // -59644.95461490144280
  s21_decimal dec_1 = {{0x5e8cb418, 0x52c62505, 0x0, 0x800e0000}};
  // 15468.1029060825475878056291
  s21_decimal dec_2 = {{0xbaf57163, 0x6333551c, 0x7ff2fb, 0x160000}};
  // -3.8559967551966026188054756110
  s21_decimal dec_check = {{0x5c567b0e, 0x8a652ab9, 0x7c980ebd, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_div_27) {
  // -668817483664734
  s21_decimal dec_1 = {{0x34888d5e, 0x26049, 0x0, 0x80000000}};
  // -8.7
  s21_decimal dec_2 = {{0x57, 0x0, 0x0, 0x80010000}};
  // 76875572835026.896551724137931
  s21_decimal dec_check = {{0x6df3dcb, 0xf0b042a8, 0xf865fbc1, 0xf0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_div_28) {
  // -11269905.08778
  s21_decimal dec_1 = {{0x65de72ea, 0x106, 0x0, 0x80050000}};
  // -7.7612583955829
  s21_decimal dec_2 = {{0x967f2d75, 0x4696, 0x0, 0x800d0000}};
  // 1452071.8823372697797913743401
  s21_decimal dec_check = {{0x6c741029, 0xb7b41935, 0x2eeb41d0, 0x160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_div_29) {
  // -688707556.98264235
  s21_decimal dec_1 = {{0x60cec8ab, 0xf4ad96, 0x0, 0x80080000}};
  // 222
  s21_decimal dec_2 = {{0xde, 0x0, 0x0, 0x0}};
  // -3102286.2927146051801801801802
  s21_decimal dec_check = {{0xb50fc04a, 0x1dd8b9f1, 0x643d82c1, 0x80160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_div_30) {
  // -8605
  s21_decimal dec_1 = {{0x219d, 0x0, 0x0, 0x80FF0000}};
  // 513003427291221000
  s21_decimal dec_2 = {{0x2c404c08, 0x71e8de6, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, _ERR_NUMBER);
}
END_TEST

START_TEST(test_div_31) {
  // -8605
  s21_decimal dec_1 = {{0x219d, 0x0, 0x0, 0x80000000}};
  // 513003427291221000
  s21_decimal dec_2 = {{0x2c404c08, 0x71e8de6, 0x0, 0x801D0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, _ERR_NUMBER);
}
END_TEST

START_TEST(test_div_32) {
  // -8605
  s21_decimal dec_1 = {{0x219d, 0x0, 0x0, 0x80000000}};
  s21_decimal dec_2 = {{0x2c404c08, 0x71e8de6, 0x0, 0x0}};
  int return_value = s21_div(dec_1, dec_2, NULL);
  ck_assert_int_eq(return_value, _ERR_NUMBER);
}
END_TEST

Suite *test_s21_div(void) {
  Suite *s = suite_create("\033[45m-=S21_div=-\033[0m");
  TCase *tc = tcase_create("S21 decimal div");

  tcase_add_test(tc, test_div_1);
  tcase_add_test(tc, test_div_2);
  tcase_add_test(tc, test_div_3);
  tcase_add_test(tc, test_div_4);
  tcase_add_test(tc, test_div_5);
  tcase_add_test(tc, test_div_6);
  tcase_add_test(tc, test_div_7);
  tcase_add_test(tc, test_div_8);
  tcase_add_test(tc, test_div_9);
  tcase_add_test(tc, test_div_10);
  tcase_add_test(tc, test_div_11);
  tcase_add_test(tc, test_div_12);
  tcase_add_test(tc, test_div_13);
  tcase_add_test(tc, test_div_14);
  tcase_add_test(tc, test_div_15);
  tcase_add_test(tc, test_div_16);
  tcase_add_test(tc, test_div_17);
  tcase_add_test(tc, test_div_18);
  tcase_add_test(tc, test_div_19);
  tcase_add_test(tc, test_div_20);
  tcase_add_test(tc, test_div_21);
  tcase_add_test(tc, test_div_22);
  tcase_add_test(tc, test_div_23);
  tcase_add_test(tc, test_div_24);
  tcase_add_test(tc, test_div_25);
  tcase_add_test(tc, test_div_26);
  tcase_add_test(tc, test_div_27);
  tcase_add_test(tc, test_div_28);
  tcase_add_test(tc, test_div_29);
  tcase_add_test(tc, test_div_30);
  tcase_add_test(tc, test_div_31);
  tcase_add_test(tc, test_div_32);

  suite_add_tcase(s, tc);
  return s;
}
