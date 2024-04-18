#include "s21_test.h"

START_TEST(s21_log_test_1) { ck_assert_ldouble_infinite(s21_log(0)); }
END_TEST
START_TEST(s21_log_test_2) {
  ck_assert_ldouble_eq_tol(s21_log(1.0), log(1.0), 0.000001);
}
END_TEST
START_TEST(s21_log_test_3) { ck_assert_ldouble_nan(s21_log(S21_NAN)); }
END_TEST
START_TEST(s21_log_test_4) { ck_assert_ldouble_infinite(s21_log(S21_INF)); }
END_TEST
START_TEST(s21_log_test_5) { ck_assert_ldouble_nan(s21_log(-S21_INF)); }
END_TEST
START_TEST(s21_log_test_6) {
  ck_assert_ldouble_eq_tol(s21_log(25), log(25), 0.000001);
}
END_TEST
START_TEST(s21_log_test_7) {
  ck_assert_ldouble_eq_tol(s21_log(0.123456), log(0.123456), 0.000001);
}
END_TEST

START_TEST(s21_log_test_8) { ck_assert_ldouble_nan(s21_log(-1)); }
END_TEST

START_TEST(s21_log_test_9) {
  ck_assert_ldouble_nan(s21_log(-19284612984612984.1223));
}
END_TEST

START_TEST(s21_log_test_10) {
  ck_assert_ldouble_eq_tol(s21_log(100), log(100), 0.000001);
}
END_TEST

START_TEST(s21_log_test_11) {
  ck_assert_ldouble_eq_tol(s21_log(1.1), log(1.1), 0.000001);
}
END_TEST

START_TEST(s21_log_test_12) {
  ck_assert_ldouble_eq_tol(s21_log(960.9687), log(960.9687), 0.000001);
}
END_TEST

START_TEST(s21_log_test_13) {
  ck_assert_ldouble_eq_tol(s21_log(1998.4720000000002), log(1998.4720000000002),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_14) {
  ck_assert_ldouble_eq_tol(s21_log(2978.0714000000003), log(2978.0714000000003),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_15) {
  ck_assert_ldouble_eq_tol(s21_log(4114.4258), log(4114.4258), 0.000001);
}
END_TEST

START_TEST(s21_log_test_16) {
  ck_assert_ldouble_eq_tol(s21_log(5099.6756000000005), log(5099.6756000000005),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_17) {
  ck_assert_ldouble_eq_tol(s21_log(6194.8388), log(6194.8388), 0.000001);
}
END_TEST

START_TEST(s21_log_test_18) {
  ck_assert_ldouble_eq_tol(s21_log(7218.982), log(7218.982), 0.000001);
}
END_TEST

START_TEST(s21_log_test_19) {
  ck_assert_ldouble_eq_tol(s21_log(8397.2411), log(8397.2411), 0.000001);
}
END_TEST

START_TEST(s21_log_test_20) {
  ck_assert_ldouble_eq_tol(s21_log(9532.948799999998), log(9532.948799999998),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_21) {
  ck_assert_ldouble_eq_tol(s21_log(10540.240099999999), log(10540.240099999999),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_22) {
  ck_assert_ldouble_eq_tol(s21_log(11707.567799999999), log(11707.567799999999),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_23) {
  ck_assert_ldouble_eq_tol(s21_log(12876.585799999999), log(12876.585799999999),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_24) {
  ck_assert_ldouble_eq_tol(s21_log(14052.517499999998), log(14052.517499999998),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_25) {
  ck_assert_ldouble_eq_tol(s21_log(15172.655099999998), log(15172.655099999998),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_26) {
  ck_assert_ldouble_eq_tol(s21_log(16154.595599999999), log(16154.595599999999),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_27) {
  ck_assert_ldouble_eq_tol(s21_log(17329.4145), log(17329.4145), 0.000001);
}
END_TEST

START_TEST(s21_log_test_28) {
  ck_assert_ldouble_eq_tol(s21_log(18426.493199999997), log(18426.493199999997),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_29) {
  ck_assert_ldouble_eq_tol(s21_log(19364.263499999997), log(19364.263499999997),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_30) {
  ck_assert_ldouble_eq_tol(s21_log(20540.94), log(20540.94), 0.000001);
}
END_TEST

START_TEST(s21_log_test_31) {
  ck_assert_ldouble_eq_tol(s21_log(21667.9299), log(21667.9299), 0.000001);
}
END_TEST

START_TEST(s21_log_test_32) {
  ck_assert_ldouble_eq_tol(s21_log(22678.5719), log(22678.5719), 0.000001);
}
END_TEST

START_TEST(s21_log_test_33) {
  ck_assert_ldouble_eq_tol(s21_log(23843.8802), log(23843.8802), 0.000001);
}
END_TEST

START_TEST(s21_log_test_34) {
  ck_assert_ldouble_eq_tol(s21_log(24988.1165), log(24988.1165), 0.000001);
}
END_TEST

START_TEST(s21_log_test_35) {
  ck_assert_ldouble_eq_tol(s21_log(26100.8022), log(26100.8022), 0.000001);
}
END_TEST

START_TEST(s21_log_test_36) {
  ck_assert_ldouble_eq_tol(s21_log(27232.951399999998), log(27232.951399999998),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_37) {
  ck_assert_ldouble_eq_tol(s21_log(28300.957499999997), log(28300.957499999997),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_38) {
  ck_assert_ldouble_eq_tol(s21_log(29381.574599999996), log(29381.574599999996),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_39) {
  ck_assert_ldouble_eq_tol(s21_log(30412.263399999996), log(30412.263399999996),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_40) {
  ck_assert_ldouble_eq_tol(s21_log(31523.197899999996), log(31523.197899999996),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_41) {
  ck_assert_ldouble_eq_tol(s21_log(32622.892199999995), log(32622.892199999995),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_42) {
  ck_assert_ldouble_eq_tol(s21_log(33632.43719999999), log(33632.43719999999),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_43) {
  ck_assert_ldouble_eq_tol(s21_log(34841.29379999999), log(34841.29379999999),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_44) {
  ck_assert_ldouble_eq_tol(s21_log(35842.90969999999), log(35842.90969999999),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_45) {
  ck_assert_ldouble_eq_tol(s21_log(36944.37289999999), log(36944.37289999999),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_46) {
  ck_assert_ldouble_eq_tol(s21_log(38063.52749999999), log(38063.52749999999),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_47) {
  ck_assert_ldouble_eq_tol(s21_log(39127.86849999999), log(39127.86849999999),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_48) {
  ck_assert_ldouble_eq_tol(s21_log(40232.06279999999), log(40232.06279999999),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_49) {
  ck_assert_ldouble_eq_tol(s21_log(41384.66799999999), log(41384.66799999999),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_50) {
  ck_assert_ldouble_eq_tol(s21_log(42452.01669999999), log(42452.01669999999),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_51) {
  ck_assert_ldouble_eq_tol(s21_log(43508.239499999996), log(43508.239499999996),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_52) {
  ck_assert_ldouble_eq_tol(s21_log(44471.296299999995), log(44471.296299999995),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_53) {
  ck_assert_ldouble_eq_tol(s21_log(45561.700099999995), log(45561.700099999995),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_54) {
  ck_assert_ldouble_eq_tol(s21_log(46679.85279999999), log(46679.85279999999),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_55) {
  ck_assert_ldouble_eq_tol(s21_log(47724.99999999999), log(47724.99999999999),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_56) {
  ck_assert_ldouble_eq_tol(s21_log(48876.001099999994), log(48876.001099999994),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_57) {
  ck_assert_ldouble_eq_tol(s21_log(50058.58639999999), log(50058.58639999999),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_58) {
  ck_assert_ldouble_eq_tol(s21_log(51026.68349999999), log(51026.68349999999),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_59) {
  ck_assert_ldouble_eq_tol(s21_log(52191.89629999999), log(52191.89629999999),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_60) {
  ck_assert_ldouble_eq_tol(s21_log(53146.803799999994), log(53146.803799999994),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_61) {
  ck_assert_ldouble_eq_tol(s21_log(54230.988099999995), log(54230.988099999995),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_62) {
  ck_assert_ldouble_eq_tol(s21_log(55352.48129999999), log(55352.48129999999),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_63) {
  ck_assert_ldouble_eq_tol(s21_log(56261.62499999999), log(56261.62499999999),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_64) {
  ck_assert_ldouble_eq_tol(s21_log(57284.12309999999), log(57284.12309999999),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_65) {
  ck_assert_ldouble_eq_tol(s21_log(58306.23429999999), log(58306.23429999999),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_66) {
  ck_assert_ldouble_eq_tol(s21_log(59348.81519999999), log(59348.81519999999),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_67) {
  ck_assert_ldouble_eq_tol(s21_log(60495.85899999999), log(60495.85899999999),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_68) {
  ck_assert_ldouble_eq_tol(s21_log(61656.30039999999), log(61656.30039999999),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_69) {
  ck_assert_ldouble_eq_tol(s21_log(62626.59539999999), log(62626.59539999999),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_70) {
  ck_assert_ldouble_eq_tol(s21_log(63811.31119999999), log(63811.31119999999),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_71) {
  ck_assert_ldouble_eq_tol(s21_log(64846.12999999999), log(64846.12999999999),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_72) {
  ck_assert_ldouble_eq_tol(s21_log(66031.27389999999), log(66031.27389999999),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_73) {
  ck_assert_ldouble_eq_tol(s21_log(67060.81389999998), log(67060.81389999998),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_74) {
  ck_assert_ldouble_eq_tol(s21_log(68064.88889999998), log(68064.88889999998),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_75) {
  ck_assert_ldouble_eq_tol(s21_log(69036.05499999998), log(69036.05499999998),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_76) {
  ck_assert_ldouble_eq_tol(s21_log(70131.82869999998), log(70131.82869999998),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_77) {
  ck_assert_ldouble_eq_tol(s21_log(71162.46739999998), log(71162.46739999998),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_78) {
  ck_assert_ldouble_eq_tol(s21_log(72079.90109999997), log(72079.90109999997),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_79) {
  ck_assert_ldouble_eq_tol(s21_log(73017.11129999998), log(73017.11129999998),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_80) {
  ck_assert_ldouble_eq_tol(s21_log(74025.62649999997), log(74025.62649999997),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_81) {
  ck_assert_ldouble_eq_tol(s21_log(75131.88449999997), log(75131.88449999997),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_82) {
  ck_assert_ldouble_eq_tol(s21_log(76324.57499999997), log(76324.57499999997),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_83) {
  ck_assert_ldouble_eq_tol(s21_log(77492.41399999996), log(77492.41399999996),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_84) {
  ck_assert_ldouble_eq_tol(s21_log(78400.69089999996), log(78400.69089999996),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_85) {
  ck_assert_ldouble_eq_tol(s21_log(79581.19009999996), log(79581.19009999996),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_86) {
  ck_assert_ldouble_eq_tol(s21_log(80708.72559999996), log(80708.72559999996),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_87) {
  ck_assert_ldouble_eq_tol(s21_log(81815.57569999996), log(81815.57569999996),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_88) {
  ck_assert_ldouble_eq_tol(s21_log(82886.17439999996), log(82886.17439999996),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_89) {
  ck_assert_ldouble_eq_tol(s21_log(83810.26519999997), log(83810.26519999997),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_90) {
  ck_assert_ldouble_eq_tol(s21_log(84862.51539999996), log(84862.51539999996),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_91) {
  ck_assert_ldouble_eq_tol(s21_log(86025.26049999996), log(86025.26049999996),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_92) {
  ck_assert_ldouble_eq_tol(s21_log(87089.02769999996), log(87089.02769999996),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_93) {
  ck_assert_ldouble_eq_tol(s21_log(88130.16639999996), log(88130.16639999996),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_94) {
  ck_assert_ldouble_eq_tol(s21_log(89032.67959999996), log(89032.67959999996),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_95) {
  ck_assert_ldouble_eq_tol(s21_log(90203.81699999997), log(90203.81699999997),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_96) {
  ck_assert_ldouble_eq_tol(s21_log(91364.34299999996), log(91364.34299999996),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_97) {
  ck_assert_ldouble_eq_tol(s21_log(92356.66429999996), log(92356.66429999996),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_98) {
  ck_assert_ldouble_eq_tol(s21_log(93522.78919999996), log(93522.78919999996),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_99) {
  ck_assert_ldouble_eq_tol(s21_log(94454.72599999995), log(94454.72599999995),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_100) {
  ck_assert_ldouble_eq_tol(s21_log(95506.80899999995), log(95506.80899999995),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_101) {
  ck_assert_ldouble_eq_tol(s21_log(96474.92979999995), log(96474.92979999995),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_102) {
  ck_assert_ldouble_eq_tol(s21_log(97612.67179999995), log(97612.67179999995),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_103) {
  ck_assert_ldouble_eq_tol(s21_log(98700.30089999996), log(98700.30089999996),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_104) {
  ck_assert_ldouble_eq_tol(s21_log(99749.19819999996), log(99749.19819999996),
                           0.000001);
}
END_TEST

START_TEST(s21_log_test_105) {
  ck_assert_ldouble_eq_tol(s21_log(12876412468712415812765.0),
                           log(12876412468712415812765.0), 0.000001);
}
END_TEST
START_TEST(s21_log_test_106) {
  ck_assert_ldouble_eq_tol(s21_log(12784582175.127645), log(12784582175.127645),
                           0.000001);
}
END_TEST
START_TEST(s21_log_test_107) {
  ck_assert_ldouble_eq_tol(s21_log(0.000000000000000123),
                           log(0.000000000000000123), 0.000001);
}
END_TEST

START_TEST(s21_log_test_108) {
  ck_assert_double_eq_tol(s21_log(26941.289), log(26941.289), EPSILON);
}
END_TEST

START_TEST(s21_log_test_109) { ck_assert_double_nan(s21_log(-12.36)); }
END_TEST

START_TEST(s21_log_test_110) {
  ck_assert_double_eq(s21_log(INFINITY), log(INFINITY));
}
END_TEST

START_TEST(s21_log_test_111) {
  ck_assert_double_nan(s21_log(NAN));
  ck_assert_double_nan(log(NAN));
}
END_TEST

START_TEST(s21_log_test_112) {
  ck_assert_double_nan(s21_log(-INFINITY));
  ck_assert_double_nan(log(-INFINITY));
}
END_TEST

START_TEST(s21_log_test_113) {
  ck_assert_msg(S21_IS_INF(s21_log(0)), "func return value failed");
}
END_TEST

START_TEST(s21_log_test_114) { ck_assert_double_eq(s21_log(1), log(1)); }
END_TEST

START_TEST(s21_log_test_115) {
  double a = S21_INF;
  ck_assert_ldouble_infinite(log(a));
  ck_assert_ldouble_infinite(s21_log(a));
}

START_TEST(s21_log_test_116) {
  double a = S21_NAN;
  ck_assert_ldouble_nan(log(a));
  ck_assert_ldouble_nan(s21_log(a));
}
END_TEST

START_TEST(s21_log_test_117) {
  double a = -0.000003;
  ck_assert_ldouble_nan(s21_log(a));
}
END_TEST

START_TEST(s21_log_test_118) {
  double a = 131223;
  ck_assert_ldouble_eq_tol(log(a), s21_log(a), EPSILON);
}
END_TEST

START_TEST(s21_log_test_119) {
  double a = 0.000123;
  ck_assert_ldouble_eq_tol(log(a), s21_log(a), EPSILON);
}
END_TEST

START_TEST(s21_log_test_120) {
  double a = 123.123123;
  ck_assert_ldouble_eq_tol(log(a), s21_log(a), EPSILON);
}
END_TEST

START_TEST(s21_log_test_121) {
  for (double k = 1; k < 100; k += 13.2) {
    long double a = s21_log(k);
    long double b = log(k);
    ck_assert_ldouble_eq_tol(a, b, EPSILON);
  }
}
END_TEST

START_TEST(s21_log_test_122) {
  for (double k = 0.1; k < 4; k += 0.24) {
    long double a = s21_log(k);
    long double b = log(k);
    ck_assert_ldouble_eq_tol(a, b, EPSILON);
  }
}
END_TEST

START_TEST(s21_log_test_123) {
  for (double k = 0.1; k < 10000; k += 123) {
    long double a = s21_log(k);
    long double b = log(k);
    ck_assert_ldouble_eq_tol(a, b, EPSILON);
  }
}
END_TEST

START_TEST(s21_log_test_124) {
  for (double k = 0.000005; k < 1; k *= 5) {
    ck_assert_ldouble_eq_tol(s21_log(k), log(k), EPSILON);
  }
}
END_TEST
Suite *s21_log_test_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_log_test_suite");
  tc = tcase_create("s21_log_test_suite");
  tcase_add_test(tc, s21_log_test_1);
  tcase_add_test(tc, s21_log_test_2);
  tcase_add_test(tc, s21_log_test_3);
  tcase_add_test(tc, s21_log_test_4);
  tcase_add_test(tc, s21_log_test_5);
  tcase_add_test(tc, s21_log_test_6);
  tcase_add_test(tc, s21_log_test_7);
  tcase_add_test(tc, s21_log_test_8);
  tcase_add_test(tc, s21_log_test_9);
  tcase_add_test(tc, s21_log_test_10);
  tcase_add_test(tc, s21_log_test_11);
  tcase_add_test(tc, s21_log_test_12);
  tcase_add_test(tc, s21_log_test_13);
  tcase_add_test(tc, s21_log_test_14);
  tcase_add_test(tc, s21_log_test_15);
  tcase_add_test(tc, s21_log_test_16);
  tcase_add_test(tc, s21_log_test_17);
  tcase_add_test(tc, s21_log_test_18);
  tcase_add_test(tc, s21_log_test_19);
  tcase_add_test(tc, s21_log_test_20);
  tcase_add_test(tc, s21_log_test_21);
  tcase_add_test(tc, s21_log_test_22);
  tcase_add_test(tc, s21_log_test_23);
  tcase_add_test(tc, s21_log_test_24);
  tcase_add_test(tc, s21_log_test_25);
  tcase_add_test(tc, s21_log_test_26);
  tcase_add_test(tc, s21_log_test_27);
  tcase_add_test(tc, s21_log_test_28);
  tcase_add_test(tc, s21_log_test_29);
  tcase_add_test(tc, s21_log_test_30);
  tcase_add_test(tc, s21_log_test_31);
  tcase_add_test(tc, s21_log_test_32);
  tcase_add_test(tc, s21_log_test_33);
  tcase_add_test(tc, s21_log_test_34);
  tcase_add_test(tc, s21_log_test_35);
  tcase_add_test(tc, s21_log_test_36);
  tcase_add_test(tc, s21_log_test_37);
  tcase_add_test(tc, s21_log_test_38);
  tcase_add_test(tc, s21_log_test_39);
  tcase_add_test(tc, s21_log_test_40);
  tcase_add_test(tc, s21_log_test_41);
  tcase_add_test(tc, s21_log_test_42);
  tcase_add_test(tc, s21_log_test_43);
  tcase_add_test(tc, s21_log_test_44);
  tcase_add_test(tc, s21_log_test_45);
  tcase_add_test(tc, s21_log_test_46);
  tcase_add_test(tc, s21_log_test_47);
  tcase_add_test(tc, s21_log_test_48);
  tcase_add_test(tc, s21_log_test_49);
  tcase_add_test(tc, s21_log_test_50);
  tcase_add_test(tc, s21_log_test_51);
  tcase_add_test(tc, s21_log_test_52);
  tcase_add_test(tc, s21_log_test_53);
  tcase_add_test(tc, s21_log_test_54);
  tcase_add_test(tc, s21_log_test_55);
  tcase_add_test(tc, s21_log_test_56);
  tcase_add_test(tc, s21_log_test_57);
  tcase_add_test(tc, s21_log_test_58);
  tcase_add_test(tc, s21_log_test_59);
  tcase_add_test(tc, s21_log_test_60);
  tcase_add_test(tc, s21_log_test_61);
  tcase_add_test(tc, s21_log_test_62);
  tcase_add_test(tc, s21_log_test_63);
  tcase_add_test(tc, s21_log_test_64);
  tcase_add_test(tc, s21_log_test_65);
  tcase_add_test(tc, s21_log_test_66);
  tcase_add_test(tc, s21_log_test_67);
  tcase_add_test(tc, s21_log_test_68);
  tcase_add_test(tc, s21_log_test_69);
  tcase_add_test(tc, s21_log_test_70);
  tcase_add_test(tc, s21_log_test_71);
  tcase_add_test(tc, s21_log_test_72);
  tcase_add_test(tc, s21_log_test_73);
  tcase_add_test(tc, s21_log_test_74);
  tcase_add_test(tc, s21_log_test_75);
  tcase_add_test(tc, s21_log_test_76);
  tcase_add_test(tc, s21_log_test_77);
  tcase_add_test(tc, s21_log_test_78);
  tcase_add_test(tc, s21_log_test_79);
  tcase_add_test(tc, s21_log_test_80);
  tcase_add_test(tc, s21_log_test_81);
  tcase_add_test(tc, s21_log_test_82);
  tcase_add_test(tc, s21_log_test_83);
  tcase_add_test(tc, s21_log_test_84);
  tcase_add_test(tc, s21_log_test_85);
  tcase_add_test(tc, s21_log_test_86);
  tcase_add_test(tc, s21_log_test_87);
  tcase_add_test(tc, s21_log_test_88);
  tcase_add_test(tc, s21_log_test_89);
  tcase_add_test(tc, s21_log_test_90);
  tcase_add_test(tc, s21_log_test_91);
  tcase_add_test(tc, s21_log_test_92);
  tcase_add_test(tc, s21_log_test_93);
  tcase_add_test(tc, s21_log_test_94);
  tcase_add_test(tc, s21_log_test_95);
  tcase_add_test(tc, s21_log_test_96);
  tcase_add_test(tc, s21_log_test_97);
  tcase_add_test(tc, s21_log_test_98);
  tcase_add_test(tc, s21_log_test_99);
  tcase_add_test(tc, s21_log_test_100);
  tcase_add_test(tc, s21_log_test_101);
  tcase_add_test(tc, s21_log_test_102);
  tcase_add_test(tc, s21_log_test_103);
  tcase_add_test(tc, s21_log_test_104);
  tcase_add_test(tc, s21_log_test_105);
  tcase_add_test(tc, s21_log_test_106);
  tcase_add_test(tc, s21_log_test_107);
  tcase_add_test(tc, s21_log_test_108);
  tcase_add_test(tc, s21_log_test_109);
  tcase_add_test(tc, s21_log_test_110);
  tcase_add_test(tc, s21_log_test_111);
  tcase_add_test(tc, s21_log_test_112);
  tcase_add_test(tc, s21_log_test_113);
  tcase_add_test(tc, s21_log_test_114);
  tcase_add_test(tc, s21_log_test_115);
  tcase_add_test(tc, s21_log_test_116);
  tcase_add_test(tc, s21_log_test_117);
  tcase_add_test(tc, s21_log_test_118);
  tcase_add_test(tc, s21_log_test_119);
  tcase_add_test(tc, s21_log_test_120);
  tcase_add_test(tc, s21_log_test_121);
  tcase_add_test(tc, s21_log_test_122);
  tcase_add_test(tc, s21_log_test_123);
  tcase_add_test(tc, s21_log_test_124);

  suite_add_tcase(s, tc);
  return s;
}
