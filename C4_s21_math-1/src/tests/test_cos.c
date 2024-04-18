#include "s21_test.h"

START_TEST(cos_test_1) {
  double x = 0;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_2) {
  double x = NAN;
  ck_assert_msg(isnan(s21_cos(x)), "computed cos value failed");
}
END_TEST

START_TEST(cos_test_3) {
  double x = INFINITY;
  ck_assert_msg(isnan(s21_cos(x)), "computed cos value failed");
}
END_TEST

START_TEST(cos_test_4) {
  double x = 0;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_5) {
  double x = 0.03;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_6) {
  double x = 0.12;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_7) {
  double x = 0.15;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_8) {
  double x = 0.19;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_9) {
  double x = 0.28;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_10) {
  double x = 0.35000000000000003;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_11) {
  double x = 0.42000000000000004;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_12) {
  double x = 0.5;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_13) {
  double x = 0.59;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_14) {
  double x = 0.6799999999999999;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_15) {
  double x = 0.72;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_16) {
  double x = 0.79;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_17) {
  double x = 0.88;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_18) {
  double x = 0.93;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_19) {
  double x = 0;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_20) {
  double x = -0.05;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_21) {
  double x = -0.09;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_22) {
  double x = -0.12;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_23) {
  double x = -0.13999999999999999;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_24) {
  double x = -0.22999999999999998;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_25) {
  double x = -0.31;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_26) {
  double x = -0.35;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_27) {
  double x = -0.38999999999999996;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_28) {
  double x = -0.44999999999999996;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_29) {
  double x = -0.48999999999999994;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_30) {
  double x = -0.5499999999999999;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_31) {
  double x = -0.57;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_32) {
  double x = -0.6;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_33) {
  double x = -0.6699999999999999;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_34) {
  double x = -0.7599999999999999;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_35) {
  double x = -0.7799999999999999;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_36) {
  double x = -0.83;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_37) {
  double x = -0.86;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_38) {
  double x = -0.95;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_39) {
  double x = 0;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_40) {
  double x = 600;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_41) {
  double x = -1300;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_42) {
  double x = 2100;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_43) {
  double x = -2900;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_44) {
  double x = 3700;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_45) {
  double x = -4500;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_46) {
  double x = 4900;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_47) {
  double x = -5500;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_48) {
  double x = 6100;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_49) {
  double x = -6500;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_50) {
  double x = 7100;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_51) {
  double x = -7600;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_52) {
  double x = 8500;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_53) {
  double x = -9200;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_54) {
  double x = 9800;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_55) {
  double x = -10700;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_56) {
  double x = 11300;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_57) {
  double x = -12200;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_58) {
  double x = 12600;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_59) {
  double x = -13200;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_60) {
  double x = 13800;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_61) {
  double x = -14300;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_62) {
  double x = 15000;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_63) {
  double x = -15400;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_64) {
  double x = 15900;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_65) {
  double x = -16500;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_66) {
  double x = 17300;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_67) {
  double x = -18200;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_68) {
  double x = 18700;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_69) {
  double x = -19300;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_70) {
  double x = 19600;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_71) {
  double x = -20200;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_72) {
  double x = 21000;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_73) {
  double x = -21800;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_74) {
  double x = 22400;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_75) {
  double x = -23200;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_76) {
  double x = 23800;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_77) {
  double x = -24400;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_78) {
  double x = 24800;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_79) {
  double x = -25200;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_80) {
  double x = 25500;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_81) {
  double x = -26200;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_82) {
  double x = 26500;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_83) {
  double x = -26900;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_84) {
  double x = 27600;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_85) {
  double x = -28100;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_86) {
  double x = 28600;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_87) {
  double x = -29400;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_88) {
  double x = 29700;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_89) {
  double x = -30100;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_90) {
  double x = 30400;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_91) {
  double x = -31000;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_92) {
  double x = 31900;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_93) {
  double x = -32400;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_94) {
  double x = 32900;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_95) {
  double x = -33600;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_96) {
  double x = 34000;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_97) {
  double x = -34700;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_98) {
  double x = 35600;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_99) {
  double x = -35900;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_100) {
  double x = 36400;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_101) {
  double x = -36800;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_102) {
  double x = 37700;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_103) {
  double x = -38600;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_104) {
  double x = 38900;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_105) {
  double x = -39200;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_106) {
  double x = 39700;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_107) {
  double x = -40200;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_108) {
  double x = 40900;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_109) {
  double x = -41200;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_110) {
  double x = 41800;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_111) {
  double x = -42300;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_112) {
  double x = 42700;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_113) {
  double x = -43200;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_114) {
  double x = 44000;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_115) {
  double x = -44700;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_116) {
  double x = 45000;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_117) {
  double x = -45400;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_118) {
  double x = 45800;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_119) {
  double x = -46600;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_120) {
  double x = 47000;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_121) {
  double x = -47300;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_122) {
  double x = 47600;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_123) {
  double x = -47900;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_124) {
  double x = 48400;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_125) {
  double x = -49000;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_126) {
  double x = 49500;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_127) {
  double x = -50300;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_128) {
  double x = 51000;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_129) {
  double x = -51900;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_130) {
  double x = 52800;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_131) {
  double x = -53500;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_132) {
  double x = 54300;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_133) {
  double x = -55100;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_134) {
  double x = 56000;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_135) {
  double x = -56300;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_136) {
  double x = 57000;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_137) {
  double x = -57400;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_138) {
  double x = 58300;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_139) {
  double x = -58600;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_140) {
  double x = 59200;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_141) {
  double x = -59800;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_142) {
  double x = 60600;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_143) {
  double x = -61500;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_144) {
  double x = 62200;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_145) {
  double x = -62500;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_146) {
  double x = 63200;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_147) {
  double x = -63500;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_148) {
  double x = 64100;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_149) {
  double x = -64700;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_150) {
  double x = 65200;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_151) {
  double x = -65500;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_152) {
  double x = 65900;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_153) {
  double x = -66200;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_154) {
  double x = 66500;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_155) {
  double x = -67400;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_156) {
  double x = 68200;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_157) {
  double x = -69000;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_158) {
  double x = 69400;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_159) {
  double x = -70200;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_160) {
  double x = 70700;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_161) {
  double x = -71200;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_162) {
  double x = 71500;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_163) {
  double x = -72200;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_164) {
  double x = 72900;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_165) {
  double x = -73500;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_166) {
  double x = 74400;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_167) {
  double x = -75100;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_168) {
  double x = 75900;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_169) {
  double x = -76800;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_170) {
  double x = 77700;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_171) {
  double x = -78200;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_172) {
  double x = 78600;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_173) {
  double x = -79400;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_174) {
  double x = 79900;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_175) {
  double x = -80400;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_176) {
  double x = 81200;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_177) {
  double x = -82100;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_178) {
  double x = 82800;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_179) {
  double x = -83600;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_180) {
  double x = 84400;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_181) {
  double x = -84900;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_182) {
  double x = 85200;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_183) {
  double x = -85900;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_184) {
  double x = 86400;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_185) {
  double x = -87300;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_186) {
  double x = 88000;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_187) {
  double x = -88800;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_188) {
  double x = 89700;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_189) {
  double x = -90300;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_190) {
  double x = 90700;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_191) {
  double x = -91600;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_192) {
  double x = 92400;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_193) {
  double x = -93200;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_194) {
  double x = 93700;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_195) {
  double x = -94200;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_196) {
  double x = 94500;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_197) {
  double x = -95200;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_198) {
  double x = 95800;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_199) {
  double x = -96100;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_200) {
  double x = 96800;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_201) {
  double x = -97200;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_202) {
  double x = 98100;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_203) {
  double x = -98600;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_204) {
  double x = 99500;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_205) {
  double x = -100200;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_206) {
  double x = 12874612749.0;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_207) {
  double x = -1;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_208) {
  double x = 1;
  ck_assert_msg(fabsl((long double)cos(x) - s21_cos(x)) < EPSILON,
                "computed cos value failed");
}
END_TEST

START_TEST(cos_test_209) {
  ck_assert_double_eq_tol(s21_cos(1200000), cos(1200000), EPSILON);
}
END_TEST

START_TEST(cos_test_210) {
  ck_assert_double_eq_tol(s21_cos(-14.96), cos(-14.96), EPSILON);
}
END_TEST

START_TEST(cos_test_211) {
  ck_assert_double_nan(s21_cos(INFINITY));
  ck_assert_double_nan(cos(INFINITY));
}
END_TEST

START_TEST(cos_test_212) {
  ck_assert_double_nan(s21_cos(NAN));
  ck_assert_double_nan(cos(NAN));
}
END_TEST

START_TEST(cos_test_213) {
  ck_assert_double_nan(s21_cos(-INFINITY));
  ck_assert_double_nan(cos(-INFINITY));
}
END_TEST

START_TEST(cos_test_214) {
  ck_assert_double_eq_tol(s21_cos(0), cos(0), EPSILON);
}
END_TEST

START_TEST(cos_test_215) {
  ck_assert_double_eq_tol(s21_cos(S21_PI * 2), cos(S21_PI * 2), EPSILON);
}
END_TEST

START_TEST(cos_test_216) {
  ck_assert_double_eq_tol(s21_cos(-S21_PI * 2), cos(-S21_PI * 2), EPSILON);
}
END_TEST

START_TEST(cos_test_217) {
  ck_assert_double_eq_tol(s21_cos(S21_PI), cos(S21_PI), EPSILON);
}
END_TEST

START_TEST(cos_test_218) {
  ck_assert_double_eq_tol(s21_cos(-S21_PI), cos(-S21_PI), EPSILON);
}
END_TEST

Suite *s21_cos_test_suite() {
  Suite *suite = suite_create("s21_cos_test");
  TCase *tcase = tcase_create("tcase_cos_test");

  tcase_add_test(tcase, cos_test_1);
  tcase_add_test(tcase, cos_test_2);
  tcase_add_test(tcase, cos_test_3);
  tcase_add_test(tcase, cos_test_4);
  tcase_add_test(tcase, cos_test_5);
  tcase_add_test(tcase, cos_test_6);
  tcase_add_test(tcase, cos_test_7);
  tcase_add_test(tcase, cos_test_8);
  tcase_add_test(tcase, cos_test_9);
  tcase_add_test(tcase, cos_test_10);
  tcase_add_test(tcase, cos_test_11);
  tcase_add_test(tcase, cos_test_12);
  tcase_add_test(tcase, cos_test_13);
  tcase_add_test(tcase, cos_test_14);
  tcase_add_test(tcase, cos_test_15);
  tcase_add_test(tcase, cos_test_16);
  tcase_add_test(tcase, cos_test_17);
  tcase_add_test(tcase, cos_test_18);
  tcase_add_test(tcase, cos_test_19);
  tcase_add_test(tcase, cos_test_20);
  tcase_add_test(tcase, cos_test_21);
  tcase_add_test(tcase, cos_test_22);
  tcase_add_test(tcase, cos_test_23);
  tcase_add_test(tcase, cos_test_24);
  tcase_add_test(tcase, cos_test_25);
  tcase_add_test(tcase, cos_test_26);
  tcase_add_test(tcase, cos_test_27);
  tcase_add_test(tcase, cos_test_28);
  tcase_add_test(tcase, cos_test_29);
  tcase_add_test(tcase, cos_test_30);
  tcase_add_test(tcase, cos_test_31);
  tcase_add_test(tcase, cos_test_32);
  tcase_add_test(tcase, cos_test_33);
  tcase_add_test(tcase, cos_test_34);
  tcase_add_test(tcase, cos_test_35);
  tcase_add_test(tcase, cos_test_36);
  tcase_add_test(tcase, cos_test_37);
  tcase_add_test(tcase, cos_test_38);
  tcase_add_test(tcase, cos_test_39);
  tcase_add_test(tcase, cos_test_40);
  tcase_add_test(tcase, cos_test_41);
  tcase_add_test(tcase, cos_test_42);
  tcase_add_test(tcase, cos_test_43);
  tcase_add_test(tcase, cos_test_44);
  tcase_add_test(tcase, cos_test_45);
  tcase_add_test(tcase, cos_test_46);
  tcase_add_test(tcase, cos_test_47);
  tcase_add_test(tcase, cos_test_48);
  tcase_add_test(tcase, cos_test_49);
  tcase_add_test(tcase, cos_test_50);
  tcase_add_test(tcase, cos_test_51);
  tcase_add_test(tcase, cos_test_52);
  tcase_add_test(tcase, cos_test_53);
  tcase_add_test(tcase, cos_test_54);
  tcase_add_test(tcase, cos_test_55);
  tcase_add_test(tcase, cos_test_56);
  tcase_add_test(tcase, cos_test_57);
  tcase_add_test(tcase, cos_test_58);
  tcase_add_test(tcase, cos_test_59);
  tcase_add_test(tcase, cos_test_60);
  tcase_add_test(tcase, cos_test_61);
  tcase_add_test(tcase, cos_test_62);
  tcase_add_test(tcase, cos_test_63);
  tcase_add_test(tcase, cos_test_64);
  tcase_add_test(tcase, cos_test_65);
  tcase_add_test(tcase, cos_test_66);
  tcase_add_test(tcase, cos_test_67);
  tcase_add_test(tcase, cos_test_68);
  tcase_add_test(tcase, cos_test_69);
  tcase_add_test(tcase, cos_test_70);
  tcase_add_test(tcase, cos_test_71);
  tcase_add_test(tcase, cos_test_72);
  tcase_add_test(tcase, cos_test_73);
  tcase_add_test(tcase, cos_test_74);
  tcase_add_test(tcase, cos_test_75);
  tcase_add_test(tcase, cos_test_76);
  tcase_add_test(tcase, cos_test_77);
  tcase_add_test(tcase, cos_test_78);
  tcase_add_test(tcase, cos_test_79);
  tcase_add_test(tcase, cos_test_80);
  tcase_add_test(tcase, cos_test_81);
  tcase_add_test(tcase, cos_test_82);
  tcase_add_test(tcase, cos_test_83);
  tcase_add_test(tcase, cos_test_84);
  tcase_add_test(tcase, cos_test_85);
  tcase_add_test(tcase, cos_test_86);
  tcase_add_test(tcase, cos_test_87);
  tcase_add_test(tcase, cos_test_88);
  tcase_add_test(tcase, cos_test_89);
  tcase_add_test(tcase, cos_test_90);
  tcase_add_test(tcase, cos_test_91);
  tcase_add_test(tcase, cos_test_92);
  tcase_add_test(tcase, cos_test_93);
  tcase_add_test(tcase, cos_test_94);
  tcase_add_test(tcase, cos_test_95);
  tcase_add_test(tcase, cos_test_96);
  tcase_add_test(tcase, cos_test_97);
  tcase_add_test(tcase, cos_test_98);
  tcase_add_test(tcase, cos_test_99);
  tcase_add_test(tcase, cos_test_100);
  tcase_add_test(tcase, cos_test_101);
  tcase_add_test(tcase, cos_test_102);
  tcase_add_test(tcase, cos_test_103);
  tcase_add_test(tcase, cos_test_104);
  tcase_add_test(tcase, cos_test_105);
  tcase_add_test(tcase, cos_test_106);
  tcase_add_test(tcase, cos_test_107);
  tcase_add_test(tcase, cos_test_108);
  tcase_add_test(tcase, cos_test_109);
  tcase_add_test(tcase, cos_test_110);
  tcase_add_test(tcase, cos_test_111);
  tcase_add_test(tcase, cos_test_112);
  tcase_add_test(tcase, cos_test_113);
  tcase_add_test(tcase, cos_test_114);
  tcase_add_test(tcase, cos_test_115);
  tcase_add_test(tcase, cos_test_116);
  tcase_add_test(tcase, cos_test_117);
  tcase_add_test(tcase, cos_test_118);
  tcase_add_test(tcase, cos_test_119);
  tcase_add_test(tcase, cos_test_120);
  tcase_add_test(tcase, cos_test_121);
  tcase_add_test(tcase, cos_test_122);
  tcase_add_test(tcase, cos_test_123);
  tcase_add_test(tcase, cos_test_124);
  tcase_add_test(tcase, cos_test_125);
  tcase_add_test(tcase, cos_test_126);
  tcase_add_test(tcase, cos_test_127);
  tcase_add_test(tcase, cos_test_128);
  tcase_add_test(tcase, cos_test_129);
  tcase_add_test(tcase, cos_test_130);
  tcase_add_test(tcase, cos_test_131);
  tcase_add_test(tcase, cos_test_132);
  tcase_add_test(tcase, cos_test_133);
  tcase_add_test(tcase, cos_test_134);
  tcase_add_test(tcase, cos_test_135);
  tcase_add_test(tcase, cos_test_136);
  tcase_add_test(tcase, cos_test_137);
  tcase_add_test(tcase, cos_test_138);
  tcase_add_test(tcase, cos_test_139);
  tcase_add_test(tcase, cos_test_140);
  tcase_add_test(tcase, cos_test_141);
  tcase_add_test(tcase, cos_test_142);
  tcase_add_test(tcase, cos_test_143);
  tcase_add_test(tcase, cos_test_144);
  tcase_add_test(tcase, cos_test_145);
  tcase_add_test(tcase, cos_test_146);
  tcase_add_test(tcase, cos_test_147);
  tcase_add_test(tcase, cos_test_148);
  tcase_add_test(tcase, cos_test_149);
  tcase_add_test(tcase, cos_test_150);
  tcase_add_test(tcase, cos_test_151);
  tcase_add_test(tcase, cos_test_152);
  tcase_add_test(tcase, cos_test_153);
  tcase_add_test(tcase, cos_test_154);
  tcase_add_test(tcase, cos_test_155);
  tcase_add_test(tcase, cos_test_156);
  tcase_add_test(tcase, cos_test_157);
  tcase_add_test(tcase, cos_test_158);
  tcase_add_test(tcase, cos_test_159);
  tcase_add_test(tcase, cos_test_160);
  tcase_add_test(tcase, cos_test_161);
  tcase_add_test(tcase, cos_test_162);
  tcase_add_test(tcase, cos_test_163);
  tcase_add_test(tcase, cos_test_164);
  tcase_add_test(tcase, cos_test_165);
  tcase_add_test(tcase, cos_test_166);
  tcase_add_test(tcase, cos_test_167);
  tcase_add_test(tcase, cos_test_168);
  tcase_add_test(tcase, cos_test_169);
  tcase_add_test(tcase, cos_test_170);
  tcase_add_test(tcase, cos_test_171);
  tcase_add_test(tcase, cos_test_172);
  tcase_add_test(tcase, cos_test_173);
  tcase_add_test(tcase, cos_test_174);
  tcase_add_test(tcase, cos_test_175);
  tcase_add_test(tcase, cos_test_176);
  tcase_add_test(tcase, cos_test_177);
  tcase_add_test(tcase, cos_test_178);
  tcase_add_test(tcase, cos_test_179);
  tcase_add_test(tcase, cos_test_180);
  tcase_add_test(tcase, cos_test_181);
  tcase_add_test(tcase, cos_test_182);
  tcase_add_test(tcase, cos_test_183);
  tcase_add_test(tcase, cos_test_184);
  tcase_add_test(tcase, cos_test_185);
  tcase_add_test(tcase, cos_test_186);
  tcase_add_test(tcase, cos_test_187);
  tcase_add_test(tcase, cos_test_188);
  tcase_add_test(tcase, cos_test_189);
  tcase_add_test(tcase, cos_test_190);
  tcase_add_test(tcase, cos_test_191);
  tcase_add_test(tcase, cos_test_192);
  tcase_add_test(tcase, cos_test_193);
  tcase_add_test(tcase, cos_test_194);
  tcase_add_test(tcase, cos_test_195);
  tcase_add_test(tcase, cos_test_196);
  tcase_add_test(tcase, cos_test_197);
  tcase_add_test(tcase, cos_test_198);
  tcase_add_test(tcase, cos_test_199);
  tcase_add_test(tcase, cos_test_200);
  tcase_add_test(tcase, cos_test_201);
  tcase_add_test(tcase, cos_test_202);
  tcase_add_test(tcase, cos_test_203);
  tcase_add_test(tcase, cos_test_204);
  tcase_add_test(tcase, cos_test_205);
  tcase_add_test(tcase, cos_test_206);
  tcase_add_test(tcase, cos_test_207);
  tcase_add_test(tcase, cos_test_208);
  tcase_add_test(tcase, cos_test_209);
  tcase_add_test(tcase, cos_test_210);
  tcase_add_test(tcase, cos_test_211);
  tcase_add_test(tcase, cos_test_212);
  tcase_add_test(tcase, cos_test_213);
  tcase_add_test(tcase, cos_test_214);
  tcase_add_test(tcase, cos_test_215);
  tcase_add_test(tcase, cos_test_216);
  tcase_add_test(tcase, cos_test_217);
  tcase_add_test(tcase, cos_test_218);

  suite_add_tcase(suite, tcase);

  return suite;
}