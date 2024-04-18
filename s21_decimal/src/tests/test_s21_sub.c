#include "test_s21_decimal.h"

START_TEST(test_sub_1) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal answer = {0};

  int error = s21_sub(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_sub_2) {
  s21_decimal value_1 = {0};
  value_1.bits[0] = 1;

  s21_decimal value_2 = {0};
  value_2.bits[0] = 1;
  set_sign(&value_2, _MINUS);

  s21_decimal answer = {0};
  answer.bits[0] = 2;

  s21_decimal result = {0};

  int error = s21_sub(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_sub_3) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0, 0}};
  set_sign(&value_1, _MINUS);

  s21_decimal value_2 = {0};
  value_2.bits[2] = 0xFFFFFFFF;
  set_sign(&value_2, _MINUS);

  s21_decimal answer = {{1, 0, 0xFFFFFFFE, 0}};

  s21_decimal result = {0};

  int error = s21_sub(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_sub_4) {
  s21_decimal value_1 = {0};
  value_1.bits[0] = 1;
  set_sign(&value_1, _MINUS);
  // set_exp(&value_1, 1);

  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_sign(&value_2, _MINUS);

  s21_decimal answer = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal result = {0};

  int error = s21_sub(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_sub_5) {
  //  -0,000005-(-792281625142643375935439,50333) =
  //              792281625142643375935439,503325
  //  =>792281625142643375935439,50332
  s21_decimal value_1 = {0};
  value_1.bits[0] = 5;
  set_sign(&value_1, _MINUS);
  set_exp(&value_1, 6);

  s21_decimal value_2 = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_sign(&value_2, _MINUS);
  set_exp(&value_2, 5);

  s21_decimal answer = {{0xFFFFFFFC, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_exp(&answer, 5);

  s21_decimal result = {0};

  int error = s21_sub(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_sub_6) {
  s21_decimal value_1 = {0};
  value_1.bits[0] = 4;
  set_sign(&value_1, _MINUS);
  set_exp(&value_1, 1);

  s21_decimal value_2 = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_sign(&value_2, _MINUS);

  s21_decimal answer = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0}};

  s21_decimal result = {0};

  int error = s21_sub(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_sub_7) {
  s21_decimal value_1 = {0};
  value_1.bits[0] = 1;
  set_exp(&value_1, 28);
  set_sign(&value_1, _MINUS);  //-0.0 000 000 000 000 000 000 000 000 001

  s21_decimal value_2 = {0};
  value_2.bits[0] = 3;  //   00 000 000 000 000 000 000 000 000 003

  s21_decimal answer = {0};  // -3.0 000 000 000 000 000 000 000 000 001
                             // ...60EF6B1A BA6F0723 30000001
  answer.bits[2] = 0x60EF6B1A;
  answer.bits[1] = 0xBA6F0723;
  answer.bits[0] = 0x30000001;
  set_exp(&answer, 28);
  set_sign(&answer, _MINUS);

  s21_decimal result = {0};

  int error = s21_sub(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_sub_8) {
  s21_decimal value_1 = {{0, 0XFFFFFFFF, 0, 0}};
  value_1.bits[0] = 0;

  s21_decimal value_2 = {0};

  s21_decimal answer = {{0, 0XFFFFFFFF, 0, 0}};

  s21_decimal result = {0};

  int error = s21_sub(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_sub_9) {
  s21_decimal value_1 = {0};
  value_1.bits[0] = 1;
  set_sign(&value_1, _MINUS);

  s21_decimal value_2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0}};

  s21_decimal answer = {0};

  s21_decimal result = {0};

  int error = s21_sub(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _ERR_SMALL_NUM);
}
END_TEST

START_TEST(test_sub_10) {
  // -79228162514264337593543950335 - (-1) = -792281625142643375935439503354
  s21_decimal value_1 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0}};
  set_sign(&value_1, _MINUS);

  s21_decimal value_2 = {0};
  value_2.bits[0] = 1;
  set_sign(&value_2, _MINUS);

  s21_decimal answer = {{0XFFFFFFFE, 0XFFFFFFFF, 0XFFFFFFFF, 0}};
  set_sign(&answer, _MINUS);
  s21_decimal result = {0};

  int error = s21_sub(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_sub_11) {
  // -7.9228162514264337593543950335 - (-107.923) =
  // 100.0001837485735662406456049665 => 100.00018374857356624064560497
  s21_decimal value_1 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0}};
  set_exp(&value_1, 28);
  set_sign(&value_1, _MINUS);

  s21_decimal value_2 = {0};
  value_2.bits[0] = 107923;
  set_exp(&value_2, 3);
  set_sign(&value_2, _MINUS);
  s21_decimal answer = {{0xE28A3D71, 0x5884160F, 0x204FD242, 0}};
  set_exp(&answer, 26);
  s21_decimal result = {0};

  int error = s21_sub(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_sub_12) {
  s21_decimal value_1 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0}};
  set_sign(&value_1, _MINUS);

  s21_decimal value_2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0}};

  s21_decimal answer = {0};
  s21_decimal result = {0};

  int error = s21_sub(value_1, value_2, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _ERR_SMALL_NUM);
}
END_TEST

START_TEST(test_sub_13) {
  // 39538152722.07156
  s21_decimal dec_1 = {{0x5aceb334, 0xe0bf9, 0x0, 0x50000}};
  // 2.5
  s21_decimal dec_2 = {{0x19, 0x0, 0x0, 0x10000}};
  // 39538152719.57156
  s21_decimal dec_check = {{0x5acae2a4, 0xe0bf9, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_sub_14) {
  // 57326414491733218434771186
  s21_decimal dec_1 = {{0xcd8868f2, 0x28195e2c, 0x2f6b57, 0x0}};
  // -7185591800186246894101655427
  s21_decimal dec_2 = {{0xf852ef83, 0x48e652b, 0x1737c840, 0x80000000}};
  // 7242918214677980112536426613
  s21_decimal dec_check = {{0xc5db5875, 0x2ca7c358, 0x17673397, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_sub_15) {
  // 247148
  s21_decimal dec_1 = {{0x3c56c, 0x0, 0x0, 0x0}};
  // -4995934
  s21_decimal dec_2 = {{0x4c3b5e, 0x0, 0x0, 0x80000000}};
  // 5243082
  s21_decimal dec_check = {{0x5000ca, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_sub_16) {
  // 23249577018908624
  s21_decimal dec_1 = {{0xfb63dfd0, 0x52995d, 0x0, 0x0}};
  // -1809142771135731
  s21_decimal dec_2 = {{0xe038b4f3, 0x66d67, 0x0, 0x80000000}};
  // 25058719790044355
  s21_decimal dec_check = {{0xdb9c94c3, 0x5906c5, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_sub_17) {
  // 523623517882
  s21_decimal dec_1 = {{0xea64ceba, 0x79, 0x0, 0x0}};
  // -8798782944.83129405458
  s21_decimal dec_2 = {{0x93791012, 0xb2c3a709, 0x2f, 0x800b0000}};
  // 532422300826.83129405458
  s21_decimal dec_check = {{0x888da012, 0x445f1ac6, 0xb46, 0xb0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_sub_18) {
  // 373530182660369590340
  s21_decimal dec_1 = {{0xf61aa844, 0x3fc5ca14, 0x14, 0x0}};
  // 29954.03723364
  s21_decimal dec_2 = {{0x6bf99264, 0x2b9, 0x0, 0x80000}};
  // 373530182660369560385.96276636
  s21_decimal dec_check = {{0x5efe319c, 0xa57a7660, 0x78b1b149, 0x80000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_sub_19) {
  // 47367998787980816802
  s21_decimal dec_1 = {{0x66baf1a2, 0x915cefee, 0x2, 0x0}};
  // -591213585142749773
  s21_decimal dec_2 = {{0x90d19a4d, 0x834699f, 0x0, 0x80000000}};
  // 47959212373123566575
  s21_decimal dec_check = {{0xf78c8bef, 0x9991598d, 0x2, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_sub_20) {
  // 1148675210.49759
  s21_decimal dec_1 = {{0xadc9d49f, 0x6878, 0x0, 0x50000}};
  // -4857735551421514159117887.6
  s21_decimal dec_2 = {{0x7af75e7c, 0xb8174e9c, 0x282ea7, 0x80010000}};
  // 4857735551421515307793098.0976
  s21_decimal dec_check = {{0xce107670, 0x1b0b1db2, 0x9cf63f27, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_sub_21) {
  // -8357218553.437313661
  s21_decimal dec_1 = {{0xf3ef5a7d, 0x73facdfe, 0x0, 0x80090000}};
  // 2020124758285800167071
  s21_decimal dec_2 = {{0xccf7d69f, 0x82dcdc94, 0x6d, 0x0}};
  // -2020124758294157385624.4373137
  s21_decimal dec_check = {{0xe1f59691, 0xd130161c, 0x41461491, 0x80070000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_sub_22) {
  // -75199340587439296
  s21_decimal dec_1 = {{0xdf0ed4c0, 0x10b2966, 0x0, 0x80000000}};
  // -0.99
  s21_decimal dec_2 = {{0x63, 0x0, 0x0, 0x80020000}};
  // -75199340587439295.01
  s21_decimal dec_check = {{0x21cb1a9d, 0x685c2c2f, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_sub_23) {
  // -4016975290237484861
  s21_decimal dec_1 = {{0x5e207f3d, 0x37bf29be, 0x0, 0x80000000}};
  // 98988188370874417974928.0
  s21_decimal dec_2 = {{0xd50191a0, 0x9abca61b, 0xd19d, 0x10000}};
  // -98992205346164655459789.0
  s21_decimal dec_check = {{0x82468a02, 0xc834478b, 0xd19f, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_sub_24) {
  // 3357256.937030566626092
  s21_decimal dec_1 = {{0x3ee5432c, 0xff4ca4b8, 0xb5, 0xf0000}};
  // 38287698
  s21_decimal dec_2 = {{0x2483952, 0x0, 0x0, 0x0}};
  // -34930441.062969433373908
  s21_decimal dec_check = {{0xbb2fbcd4, 0x953fc55c, 0x765, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_sub_25) {
  // 27842214260895980765288502026
  s21_decimal dec_1 = {{0x65ea930a, 0x6c6b87a0, 0x59f68a33, 0x0}};
  // 823.0
  s21_decimal dec_2 = {{0x2026, 0x0, 0x0, 0x10000}};
  // 27842214260895980765288501203
  s21_decimal dec_check = {{0x65ea8fd3, 0x6c6b87a0, 0x59f68a33, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_sub_26) {
  // -30555.230529503
  s21_decimal dec_1 = {{0x31a967df, 0x1bca, 0x0, 0x80090000}};
  // -72578364.418
  s21_decimal dec_2 = {{0xe601f402, 0x10, 0x0, 0x80030000}};
  // 72547809.187470497
  s21_decimal dec_check = {{0x1bda1ca1, 0x101bdd9, 0x0, 0x90000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_sub_27) {
  // -505
  s21_decimal dec_1 = {{0x1f9, 0x0, 0x0, 0x80000000}};
  // -6015968972.4114459033
  s21_decimal dec_2 = {{0x7b8f5999, 0x42e22710, 0x3, 0x800a0000}};
  // 6015968467.4114459033
  s21_decimal dec_check = {{0xb01a9599, 0x42e22278, 0x3, 0xa0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_sub_28) {
  // 9528250855462
  s21_decimal dec_1 = {{0x7801f026, 0x8aa, 0x0, 0x0}};
  // 4438.827134382226
  s21_decimal dec_2 = {{0xfa907092, 0xfc516, 0x0, 0xc0000}};
  // 9528250851023.172865617774
  s21_decimal dec_check = {{0x64efef6e, 0x837d78f8, 0x7e1af, 0xc0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_sub_29) {
  // 52036425
  s21_decimal dec_1 = {{0x31a0349, 0x0, 0x0, 0x0}};
  // 6488211029622885338547
  s21_decimal dec_2 = {{0x3b8a4db3, 0xba04136d, 0x15f, 0x0}};
  // -6488211029622833302122
  s21_decimal dec_check = {{0x38704a6a, 0xba04136d, 0x15f, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_sub_30) {
  // 51
  s21_decimal dec_1 = {{0x33, 0x0, 0x0, 0x0}};
  // 3208655640327990.033982647
  s21_decimal dec_2 = {{0x1f9324b7, 0x921ff421, 0x2a775, 0x90000}};
  // -3208655640327939.033982647
  s21_decimal dec_check = {{0x3fbce6b7, 0x921ff415, 0x2a775, 0x80090000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_sub_31) {
  // 8043034697760995.6
  s21_decimal dec_1 = {{0x74c308e4, 0x11dbef9, 0x0, 0x10000}};
  // 4209085493752245325
  s21_decimal dec_2 = {{0xb45a2c4d, 0x3a69acf4, 0x0, 0x0}};
  // -4201042459054484329.4
  s21_decimal dec_check = {{0x96c2b21e, 0x47030295, 0x2, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_sub_32) {
  // -77313
  s21_decimal dec_1 = {{0x12e01, 0x0, 0x0, 0x80000000}};
  // 0.21241839146631
  s21_decimal dec_2 = {{0xc046d687, 0x1351, 0x0, 0xe0000}};
  // -77313.21241839146631
  s21_decimal dec_check = {{0x8411687, 0x6b4b2bb5, 0x0, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_sub_33) {
  // 1109161067.68596181
  s21_decimal dec_1 = {{0x87cfbcd5, 0x18a0d9c, 0x0, 0x80000}};
  // 708235092943373606869182
  s21_decimal dec_2 = {{0xdb5c58be, 0x805681a7, 0x95f9, 0x0}};
  // -708235092943372497708114.31404
  s21_decimal dec_check = {{0x1dc419ec, 0xff965c37, 0xe4d7d573, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_sub_34) {
  // 896.09
  s21_decimal dec_1 = {{0x15e09, 0x0, 0x0, 0x20000}};
  // 726785
  s21_decimal dec_2 = {{0xb1701, 0x0, 0x0, 0x0}};
  // -725888.91
  s21_decimal dec_check = {{0x4539e5b, 0x0, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_sub_35) {
  // -0.518378883
  s21_decimal dec_1 = {{0x1ee5d583, 0x0, 0x0, 0x80090000}};
  // -83608686084486.57
  s21_decimal dec_2 = {{0x6b6b9891, 0x1db42a, 0x0, 0x80020000}};
  // 83608686084486.051621117
  s21_decimal dec_check = {{0x386368fd, 0x6f9ab809, 0x11b4, 0x90000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_sub_36) {
  // 2
  s21_decimal dec_1 = {{0x2, 0x0, 0x0, 0x0}};
  // -23714420404.935267260755321276
  s21_decimal dec_2 = {{0x99afa1bc, 0x1cff3cff, 0x4ca01bda, 0x80120000}};
  // 23714420406.935267260755321276
  s21_decimal dec_check = {{0xe877a1bc, 0x38c0aa66, 0x4ca01bda, 0x120000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_sub_37) {
  // -8605
  s21_decimal dec_1 = {{0x219d, 0x0, 0x0, 0x80000000}};
  // 513003427291221000
  s21_decimal dec_2 = {{0x2c404c08, 0x71e8de6, 0x0, 0x0}};
  // -513003427291229605
  s21_decimal dec_check = {{0x2c406da5, 0x71e8de6, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_sub_38) {
  // -8605
  s21_decimal dec_1 = {{0x219d, 0x0, 0x0, 0x80000000}};
  // 513003427291221000
  s21_decimal dec_2 = {{0x2c404c08, 0x71e8de6, 0x0, 0x0}};
  int return_value = s21_sub(dec_1, dec_2, NULL);
  ck_assert_int_eq(return_value, _ERR_NUMBER);
}
END_TEST

START_TEST(test_sub_39) {
  // -8605
  s21_decimal dec_1 = {{0x219d, 0x0, 0x0, 0x80FF0000}};
  // 513003427291221000
  s21_decimal dec_2 = {{0x2c404c08, 0x71e8de6, 0x0, 0x0}};
  // -513003427291229605
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, _ERR_NUMBER);
}
END_TEST

START_TEST(test_sub_40) {
  // -8605
  s21_decimal dec_1 = {{0x219d, 0x0, 0x0, 0x80000000}};
  // 513003427291221000
  s21_decimal dec_2 = {{0x2c404c08, 0x71e8de6, 0x0, 0x801D0000}};
  // -513003427291229605
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, _ERR_NUMBER);
}
END_TEST

Suite *test_s21_sub(void) {
  Suite *s = suite_create("\033[45m-=S21_sub=-\033[0m");
  TCase *tc = tcase_create("S21 decimal SUB");

  tcase_add_test(tc, test_sub_1);
  tcase_add_test(tc, test_sub_2);
  tcase_add_test(tc, test_sub_3);
  tcase_add_test(tc, test_sub_4);
  tcase_add_test(tc, test_sub_5);
  tcase_add_test(tc, test_sub_6);
  tcase_add_test(tc, test_sub_7);
  tcase_add_test(tc, test_sub_8);
  tcase_add_test(tc, test_sub_9);
  tcase_add_test(tc, test_sub_10);
  tcase_add_test(tc, test_sub_11);
  tcase_add_test(tc, test_sub_12);
  tcase_add_test(tc, test_sub_13);
  tcase_add_test(tc, test_sub_14);
  tcase_add_test(tc, test_sub_15);
  tcase_add_test(tc, test_sub_16);
  tcase_add_test(tc, test_sub_17);
  tcase_add_test(tc, test_sub_18);
  tcase_add_test(tc, test_sub_19);
  tcase_add_test(tc, test_sub_20);
  tcase_add_test(tc, test_sub_21);
  tcase_add_test(tc, test_sub_22);
  tcase_add_test(tc, test_sub_23);
  tcase_add_test(tc, test_sub_24);
  tcase_add_test(tc, test_sub_25);
  tcase_add_test(tc, test_sub_26);
  tcase_add_test(tc, test_sub_27);
  tcase_add_test(tc, test_sub_28);
  tcase_add_test(tc, test_sub_29);
  tcase_add_test(tc, test_sub_30);
  tcase_add_test(tc, test_sub_31);
  tcase_add_test(tc, test_sub_32);
  tcase_add_test(tc, test_sub_33);
  tcase_add_test(tc, test_sub_34);
  tcase_add_test(tc, test_sub_35);
  tcase_add_test(tc, test_sub_36);
  tcase_add_test(tc, test_sub_37);
  tcase_add_test(tc, test_sub_38);
  tcase_add_test(tc, test_sub_39);
  tcase_add_test(tc, test_sub_40);

  suite_add_tcase(s, tc);
  return s;
}