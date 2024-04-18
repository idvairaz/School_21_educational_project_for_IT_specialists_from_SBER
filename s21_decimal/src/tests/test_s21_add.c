#include "test_s21_decimal.h"

START_TEST(test_add_1) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal answer = {0};

  int error = s21_add(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_add_2) {
  s21_decimal value_1 = {0};
  value_1.bits[0] = 1;

  s21_decimal value_2 = {0};
  value_2.bits[0] = 1;

  s21_decimal answer = {0};
  answer.bits[0] = 2;

  s21_decimal result = {0};

  int error = s21_add(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_add_3) {
  s21_decimal value_1 = {0};
  value_1.bits[2] = 0xFFFFFFFF;
  value_1.bits[1] = 0xFFFFFFFF;
  value_1.bits[0] = 0xFFFFFFFF;

  s21_decimal value_2 = {0};
  value_2.bits[0] = 1;
  set_sign(&value_2, 1);

  s21_decimal answer = {0};
  answer.bits[2] = 0xFFFFFFFF;
  answer.bits[1] = 0xFFFFFFFF;
  answer.bits[0] = 0xFFFFFFFE;

  s21_decimal result = {0};

  int error = s21_add(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_add_4) {
  s21_decimal value_1 = {0};
  value_1.bits[2] = 0xFFFFFFFF;
  value_1.bits[1] = 0xFFFFFFFF;
  value_1.bits[0] = 0xFFFFFFFF;

  s21_decimal value_2 = {0};
  value_2.bits[2] = 0xFFFFFFFF;
  value_2.bits[1] = 0xFFFFFFFF;
  value_2.bits[0] = 0xFFFFFFFF;

  s21_decimal answer = {0};
  s21_decimal result = {0};

  int error = s21_add(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _ERR_BIG_NUM);
}
END_TEST

START_TEST(test_add_5) {
  s21_decimal value_1 = {0};
  value_1.bits[0] = 1;
  set_exp(&value_1, 28);

  s21_decimal value_2 = {0};
  value_2.bits[0] = 3;
  set_exp(&value_2, 27);

  s21_decimal answer = {0};
  answer.bits[0] = 31;
  set_exp(&answer, 28);

  s21_decimal result = {0};

  int error = s21_add(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_add_6) {
  s21_decimal value_1 = {0};
  value_1.bits[0] = 3999999999;

  s21_decimal value_2 = {0};
  value_2.bits[0] = 3999999999;

  s21_decimal answer = {0};
  answer.bits[1] = 1;
  answer.bits[0] = 0xDCD64FFE;

  s21_decimal result = {0};

  int error = s21_add(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_add_7) {
  s21_decimal value_1 = {0};
  value_1.bits[1] = 0xFFFFFFFF;
  value_1.bits[0] = 0xFFFFFFFF;

  s21_decimal value_2 = {0};
  value_2.bits[1] = 0xFFFFFFFF;
  value_2.bits[0] = 0xFFFFFFFF;

  s21_decimal answer = {0};
  answer.bits[2] = 1;
  answer.bits[1] = 0xFFFFFFFF;
  answer.bits[0] = 0xFFFFFFFE;

  s21_decimal result = {0};

  int error = s21_add(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  // 123
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_add_8) {
  s21_decimal value_1 = {0};
  value_1.bits[1] = 0xFFFFFFFF;
  value_1.bits[0] = 0xFFFFFFFF;
  set_sign(&value_1, _MINUS);

  s21_decimal value_2 = {0};
  value_2.bits[1] = 0xFFFFFFFF;
  value_2.bits[0] = 0xFFFFFFFE;

  s21_decimal answer = {0};
  answer.bits[0] = 1;
  set_sign(&answer, _MINUS);

  s21_decimal result = {0};

  int error = s21_add(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_add_9) {
  s21_decimal value_1 = {0};
  set_sign(&value_1, 1);
  value_1.bits[1] = 0xFFFFFFFF;
  value_1.bits[0] = 0xFFFFFFFF;

  s21_decimal value_2 = {0};
  value_2.bits[1] = 0xFFFFFFFF;
  value_2.bits[0] = 0xFFFFFFFF;

  s21_decimal answer = {0};

  s21_decimal result = {0};

  int error = s21_add(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

// 79228162514264337593543950334 + 0,51
// 79228162514264337593543950334,51 -> 79228162514264337593543950335
START_TEST(test_add_10) {  // no_bank_round
  s21_decimal value_1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {0};
  value_2.bits[0] = 51;
  set_exp(&value_2, 2);

  s21_decimal answer = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal result = {0};

  int error = s21_add(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

// 79228162514264337593543950334 + 0,50
// 79228162514264337593543950334,50 -> 79228162514264337593543950334
START_TEST(test_add_11) {  // no_bank_round
  s21_decimal value_1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0}};

  s21_decimal value_2 = {0};
  value_2.bits[0] = 50;
  set_exp(&value_2, 2);

  s21_decimal answer = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0}};

  s21_decimal result = {0};

  int error = s21_add(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_add_12) {
  // 32606685671708.2566992
  s21_decimal dec_1 = {{0xa1e62150, 0xad162e9b, 0x11, 0x70000}};
  // -5043278230917649531065147.624
  s21_decimal dec_2 = {{0xb00920e8, 0xb871ecc5, 0x104bb3b4, 0x80030000}};
  // -5043278230885042845393439.3673
  s21_decimal dec_check = {{0xc0b4e949, 0x2fecd3a4, 0xa2f5050f, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_add_13) {
  // -79333
  s21_decimal dec_1 = {{0x135e5, 0x0, 0x0, 0x80000000}};
  // 52.5574649235
  s21_decimal dec_2 = {{0x5eb0b593, 0x7a, 0x0, 0xa0000}};
  // -79280.4425350765
  s21_decimal dec_check = {{0x2a263e6d, 0x2d10d, 0x0, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_add_14) {
  // 98367241701435031587312.67
  s21_decimal dec_1 = {{0x6cede203, 0xe2c1db38, 0x82301, 0x20000}};
  // 2
  s21_decimal dec_2 = {{0x2, 0x0, 0x0, 0x0}};
  // 98367241701435031587314.67
  s21_decimal dec_check = {{0x6cede2cb, 0xe2c1db38, 0x82301, 0x20000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_add_15) {
  // 2707259692140625175385
  s21_decimal dec_1 = {{0x4758a359, 0xc2c68a53, 0x92, 0x0}};
  // -914484228223124766715289
  s21_decimal dec_2 = {{0x598fed99, 0x4a12a7d6, 0xc1a6, 0x80000000}};
  // -911776968530984141539904
  s21_decimal dec_check = {{0x12374a40, 0x874c1d83, 0xc113, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_add_16) {
  // -0.249309218945110
  s21_decimal dec_1 = {{0xd36f3856, 0xe2be, 0x0, 0x800f0000}};
  // 831710087.3
  s21_decimal dec_2 = {{0xefbce349, 0x1, 0x0, 0x10000}};
  // 831710087.050690781054890
  s21_decimal dec_check = {{0x462d07aa, 0x181b0fb4, 0xb01f, 0xf0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_add_17) {
  // 92462114
  s21_decimal dec_1 = {{0x582dc22, 0x0, 0x0, 0x0}};
  // -2952485286051158614421759
  s21_decimal dec_2 = {{0xa64130ff, 0x8c4e360e, 0x27136, 0x80000000}};
  // -2952485286051158521959645
  s21_decimal dec_check = {{0xa0be54dd, 0x8c4e360e, 0x27136, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_add_18) {
  // 79937.002413009730204888
  s21_decimal dec_1 = {{0xfc32f4d8, 0x64c1ea3d, 0x10ed, 0x120000}};
  // 7650.9322310444639382
  s21_decimal dec_2 = {{0xfebe496, 0x25c7b747, 0x4, 0x100000}};
  // 87587.934644054194143088
  s21_decimal dec_check = {{0x34583f70, 0x26c58200, 0x128c, 0x120000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_add_19) {
  // 1386
  s21_decimal dec_1 = {{0x56a, 0x0, 0x0, 0x0}};
  // 903003998921484
  s21_decimal dec_2 = {{0x96230c, 0x33547, 0x0, 0x0}};
  // 903003998922870
  s21_decimal dec_check = {{0x962876, 0x33547, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_add_20) {
  // 730047754282702801116772026
  s21_decimal dec_1 = {{0x237ab6ba, 0xf81bec7, 0x25be1a0, 0x0}};
  // 422
  s21_decimal dec_2 = {{0x1a6, 0x0, 0x0, 0x0}};
  // 730047754282702801116772448
  s21_decimal dec_check = {{0x237ab860, 0xf81bec7, 0x25be1a0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_add_21) {
  // 316789961717725838.316
  s21_decimal dec_1 = {{0xd2a4bbec, 0x2c5807c1, 0x11, 0x30000}};
  // 9140074507528684
  s21_decimal dec_2 = {{0x6e3de9ec, 0x2078d9, 0x0, 0x0}};
  // 325930036225254522.316
  s21_decimal dec_check = {{0x747e7dcc, 0xab301918, 0x11, 0x30000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_add_22) {
  // -51618736412898907722772172
  s21_decimal dec_1 = {{0x33b66ecc, 0x4ed880e2, 0x2ab2b1, 0x80000000}};
  // 536207.245621330792981
  s21_decimal dec_2 = {{0xe20d5215, 0x115ed0f1, 0x1d, 0xf0000}};
  // -51618736412898907722235964.754
  s21_decimal dec_check = {{0xe0aaed52, 0xfdb77399, 0xa6ca049b, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_add_23) {
  // -91123571
  s21_decimal dec_1 = {{0x56e6f73, 0x0, 0x0, 0x80000000}};
  // -2.8759717650
  s21_decimal dec_2 = {{0xb2367712, 0x6, 0x0, 0x800a0000}};
  // -91123573.8759717650
  s21_decimal dec_check = {{0x9369e312, 0xca55c13, 0x0, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_add_24) {
  // -9557649.338691622223108485
  s21_decimal dec_1 = {{0xcea65985, 0x3576bf8f, 0x7e7e9, 0x80120000}};
  // 644690926470586
  s21_decimal dec_2 = {{0xcda985ba, 0x24a57, 0x0, 0x0}};
  // 644690916912936.66130837777689
  s21_decimal dec_check = {{0x2df22d19, 0x7e4eba9f, 0xd04f952f, 0xe0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_add_25) {
  // -31063
  s21_decimal dec_1 = {{0x7957, 0x0, 0x0, 0x80000000}};
  // -6257919902
  s21_decimal dec_2 = {{0x7500479e, 0x1, 0x0, 0x80000000}};
  // -6257950965
  s21_decimal dec_check = {{0x7500c0f5, 0x1, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_add_26) {
  // -0.996632089913
  s21_decimal dec_1 = {{0xbe6d539, 0xe8, 0x0, 0x800c0000}};
  // -9424382392765725.7000
  s21_decimal dec_2 = {{0x7a785828, 0x1be55289, 0x5, 0x80040000}};
  // -9424382392765726.696632089913
  s21_decimal dec_check = {{0xf7a9fd39, 0x3a816470, 0x1e73aa99, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_add_27) {
  // 0.72
  s21_decimal dec_1 = {{0x48, 0x0, 0x0, 0x20000}};
  // 46713211
  s21_decimal dec_2 = {{0x2c8c97b, 0x0, 0x0, 0x0}};
  // 46713211.72
  s21_decimal dec_check = {{0x166eb454, 0x1, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_add_28) {
  // 44
  s21_decimal dec_1 = {{0x2c, 0x0, 0x0, 0x0}};
  // 65422059.219857
  s21_decimal dec_2 = {{0x4299ab91, 0x3b80, 0x0, 0x60000}};
  // 65422103.219857
  s21_decimal dec_check = {{0x45390e91, 0x3b80, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_add_29) {
  // -5
  s21_decimal dec_1 = {{0x5, 0x0, 0x0, 0x80000000}};
  // 10034033329679
  s21_decimal dec_2 = {{0x3afe060f, 0x920, 0x0, 0x0}};
  // 10034033329674
  s21_decimal dec_check = {{0x3afe060a, 0x920, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_add_30) {
  // 7231520773770592654617334486
  s21_decimal dec_1 = {{0x9f1d2d6, 0xaa30c46b, 0x175dc616, 0x0}};
  // -729533463332.3
  s21_decimal dec_2 = {{0x93d44f6b, 0x6a2, 0x0, 0x80010000}};
  // 7231520773770591925083871153.7
  s21_decimal dec_check = {{0xcf9decf1, 0xa5e7a58b, 0xe9a9bce2, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_add_31) {
  // -16917840070350828444
  s21_decimal dec_1 = {{0xd021739c, 0xeac83de8, 0x0, 0x80000000}};
  // 4716121309573563425300091563
  s21_decimal dec_2 = {{0xae7f12ab, 0x7a2c87d6, 0xf3d1588, 0x0}};
  // 4716121292655723354949263119
  s21_decimal dec_check = {{0xde5d9f0f, 0x8f6449ed, 0xf3d1587, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_add_32) {
  // -634797.4779890127
  s21_decimal dec_1 = {{0xdcc69cf, 0x168d73, 0x0, 0x800a0000}};
  // 944771381092125
  s21_decimal dec_2 = {{0xba905f1d, 0x35b43, 0x0, 0x0}};
  // 944771380457327.5220109873
  s21_decimal dec_check = {{0x21286a31, 0x9772e659, 0x7d0a1, 0xa0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_add_33) {
  // 7918399807
  s21_decimal dec_1 = {{0xd7f9313f, 0x1, 0x0, 0x0}};
  // 0.657
  s21_decimal dec_2 = {{0x291, 0x0, 0x0, 0x30000}};
  // 7918399807.657
  s21_decimal dec_check = {{0xa56860a9, 0x733, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_add_34) {
  // 93063015.28359685
  s21_decimal dec_1 = {{0x2cc54305, 0x211008, 0x0, 0x80000}};
  // 0.5754914235724288
  s21_decimal dec_2 = {{0x62bbb200, 0x147210, 0x0, 0x100000}};
  // 93063015.8590882735724288
  s21_decimal dec_check = {{0xff6c1700, 0x8fde5481, 0xc511, 0x100000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_add_35) {
  // -51236118022179191735
  s21_decimal dec_1 = {{0x6dfafbb7, 0xc70b41e1, 0x2, 0x80000000}};
  // 7
  s21_decimal dec_2 = {{0x7, 0x0, 0x0, 0x0}};
  // -51236118022179191728
  s21_decimal dec_check = {{0x6dfafbb0, 0xc70b41e1, 0x2, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_add_36) {
  // -396164056.67979
  s21_decimal dec_1 = {{0xe9c9808b, 0x2407, 0x0, 0x80050000}};
  // 34699.52262611
  s21_decimal dec_2 = {{0xe945a1d3, 0x327, 0x0, 0x80000}};
  // -396129357.15716389
  s21_decimal dec_check = {{0x51d87d25, 0x8cbbc1, 0x0, 0x80080000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_add_37) {
  // -8605
  s21_decimal dec_1 = {{0x219d, 0x0, 0x0, 0x80FF0000}};
  // 513003427291221000
  s21_decimal dec_2 = {{0x2c404c08, 0x71e8de6, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, _ERR_NUMBER);
}
END_TEST

START_TEST(test_add_38) {
  // -8605
  s21_decimal dec_1 = {{0x219d, 0x0, 0x0, 0x80000000}};
  // 513003427291221000
  s21_decimal dec_2 = {{0x2c404c08, 0x71e8de6, 0x0, 0x801D0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, _ERR_NUMBER);
}
END_TEST

START_TEST(test_add_39) {
  // -8605
  s21_decimal dec_1 = {{0x219d, 0x0, 0x0, 0x80000000}};
  s21_decimal dec_2 = {{0x2c404c08, 0x71e8de6, 0x0, 0x0}};
  int return_value = s21_add(dec_1, dec_2, NULL);
  ck_assert_int_eq(return_value, _ERR_NUMBER);
}
END_TEST

Suite *test_s21_add(void) {
  Suite *s = suite_create("\033[45m-=S21_add=-\033[0m");
  TCase *tc = tcase_create("S21 decimal add");

  tcase_add_test(tc, test_add_1);
  tcase_add_test(tc, test_add_2);
  tcase_add_test(tc, test_add_3);
  tcase_add_test(tc, test_add_4);
  tcase_add_test(tc, test_add_5);
  tcase_add_test(tc, test_add_6);
  tcase_add_test(tc, test_add_7);
  tcase_add_test(tc, test_add_8);
  tcase_add_test(tc, test_add_9);
  tcase_add_test(tc, test_add_10);
  tcase_add_test(tc, test_add_11);
  tcase_add_test(tc, test_add_12);
  tcase_add_test(tc, test_add_13);
  tcase_add_test(tc, test_add_14);
  tcase_add_test(tc, test_add_15);
  tcase_add_test(tc, test_add_16);
  tcase_add_test(tc, test_add_17);
  tcase_add_test(tc, test_add_18);
  tcase_add_test(tc, test_add_19);
  tcase_add_test(tc, test_add_20);
  tcase_add_test(tc, test_add_21);
  tcase_add_test(tc, test_add_22);
  tcase_add_test(tc, test_add_23);
  tcase_add_test(tc, test_add_24);
  tcase_add_test(tc, test_add_25);
  tcase_add_test(tc, test_add_26);
  tcase_add_test(tc, test_add_27);
  tcase_add_test(tc, test_add_28);
  tcase_add_test(tc, test_add_29);
  tcase_add_test(tc, test_add_30);
  tcase_add_test(tc, test_add_31);
  tcase_add_test(tc, test_add_32);
  tcase_add_test(tc, test_add_33);
  tcase_add_test(tc, test_add_34);
  tcase_add_test(tc, test_add_35);
  tcase_add_test(tc, test_add_36);
  tcase_add_test(tc, test_add_37);
  tcase_add_test(tc, test_add_38);
  tcase_add_test(tc, test_add_39);

  suite_add_tcase(s, tc);
  return s;
}
