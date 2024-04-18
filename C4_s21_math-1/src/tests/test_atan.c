#include "s21_test.h"

START_TEST(s21_atan_test_1) {
  ck_assert_ldouble_eq_tol(s21_atan(0.0), atan(0.0), 0.0000001);
}
END_TEST
START_TEST(s21_atan_test_2) {
  ck_assert_ldouble_eq_tol(s21_atan(1.0), atan(1.0), 0.0000001);
}
END_TEST
START_TEST(s21_atan_test_3) { ck_assert_ldouble_nan(s21_atan(NAN)); }
END_TEST
START_TEST(s21_atan_test_4) {
  ck_assert_ldouble_eq_tol(s21_atan(S21_INF), atan(INFINITY), 0.0000001);
}
END_TEST
START_TEST(s21_atan_test_5) {
  ck_assert_ldouble_eq_tol(s21_atan(-S21_INF), atan(-INFINITY), 0.0000001);
}
END_TEST
START_TEST(s21_atan_test_6) {
  ck_assert_ldouble_eq_tol(s21_atan(-s21_sqrt(3)), atan(-sqrt(3)),
                           0.0000001);  // S21_PI/6
}
END_TEST
START_TEST(s21_atan_test_7) {
  ck_assert_ldouble_eq_tol(s21_atan(s21_sqrt(3) / 3), atan(sqrt(3) / 3),
                           0.0000001);  //-S21_PI/3
}
END_TEST

START_TEST(s21_atan_test_8) {
  ck_assert_ldouble_eq_tol(s21_atan(900.0), atan(900.0), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_9) {
  ck_assert_ldouble_eq_tol(s21_atan(-1800.0), atan(-1800.0), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_10) {
  ck_assert_ldouble_eq_tol(s21_atan(2700.0), atan(2700.), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_11) {
  ck_assert_ldouble_eq_tol(s21_atan(-3400.0), atan(-3400.), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_12) {
  ck_assert_ldouble_eq_tol(s21_atan(4000), atan(4000), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_13) {
  ck_assert_ldouble_eq_tol(s21_atan(-4600), atan(-4600), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_14) {
  ck_assert_ldouble_eq_tol(s21_atan(5200), atan(5200), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_15) {
  ck_assert_ldouble_eq_tol(s21_atan(-6000), atan(-6000), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_16) {
  ck_assert_ldouble_eq_tol(s21_atan(6300), atan(6300), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_17) {
  ck_assert_ldouble_eq_tol(s21_atan(-6900), atan(-6900), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_18) {
  ck_assert_ldouble_eq_tol(s21_atan(7600), atan(7600), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_19) {
  ck_assert_ldouble_eq_tol(s21_atan(-8500), atan(-8500), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_20) {
  ck_assert_ldouble_eq_tol(s21_atan(8800), atan(8800), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_21) {
  ck_assert_ldouble_eq_tol(s21_atan(-9400), atan(-9400), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_22) {
  ck_assert_ldouble_eq_tol(s21_atan(9800), atan(9800), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_23) {
  ck_assert_ldouble_eq_tol(s21_atan(-10300), atan(-10300), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_24) {
  ck_assert_ldouble_eq_tol(s21_atan(11200), atan(11200), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_25) {
  ck_assert_ldouble_eq_tol(s21_atan(-11800), atan(-11800), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_26) {
  ck_assert_ldouble_eq_tol(s21_atan(12200), atan(12200), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_27) {
  ck_assert_ldouble_eq_tol(s21_atan(-12800), atan(-12800), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_28) {
  ck_assert_ldouble_eq_tol(s21_atan(13600), atan(13600), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_29) {
  ck_assert_ldouble_eq_tol(s21_atan(-14200), atan(-14200), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_30) {
  ck_assert_ldouble_eq_tol(s21_atan(14600), atan(14600), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_31) {
  ck_assert_ldouble_eq_tol(s21_atan(-15400), atan(-15400), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_32) {
  ck_assert_ldouble_eq_tol(s21_atan(16000), atan(16000), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_33) {
  ck_assert_ldouble_eq_tol(s21_atan(-16500), atan(-16500), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_34) {
  ck_assert_ldouble_eq_tol(s21_atan(16900), atan(16900), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_35) {
  ck_assert_ldouble_eq_tol(s21_atan(-17200), atan(-17200), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_36) {
  ck_assert_ldouble_eq_tol(s21_atan(17500), atan(17500), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_37) {
  ck_assert_ldouble_eq_tol(s21_atan(-17800), atan(-17800), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_38) {
  ck_assert_ldouble_eq_tol(s21_atan(18100), atan(18100), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_39) {
  ck_assert_ldouble_eq_tol(s21_atan(-18800), atan(-18800), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_40) {
  ck_assert_ldouble_eq_tol(s21_atan(19200), atan(19200), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_41) {
  ck_assert_ldouble_eq_tol(s21_atan(-19800), atan(-19800), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_42) {
  ck_assert_ldouble_eq_tol(s21_atan(20300), atan(20300), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_43) {
  ck_assert_ldouble_eq_tol(s21_atan(-20800), atan(-20800), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_44) {
  ck_assert_ldouble_eq_tol(s21_atan(21200), atan(21200), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_45) {
  ck_assert_ldouble_eq_tol(s21_atan(-21800), atan(-21800), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_46) {
  ck_assert_ldouble_eq_tol(s21_atan(22100), atan(22100), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_47) {
  ck_assert_ldouble_eq_tol(s21_atan(-22400), atan(-22400), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_48) {
  ck_assert_ldouble_eq_tol(s21_atan(23300), atan(23300), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_49) {
  ck_assert_ldouble_eq_tol(s21_atan(-24000), atan(-24000), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_50) {
  ck_assert_ldouble_eq_tol(s21_atan(24300), atan(24300), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_51) {
  ck_assert_ldouble_eq_tol(s21_atan(-25000), atan(-25000), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_52) {
  ck_assert_ldouble_eq_tol(s21_atan(25700), atan(25700), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_53) {
  ck_assert_ldouble_eq_tol(s21_atan(-26600), atan(-26600), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_54) {
  ck_assert_ldouble_eq_tol(s21_atan(27300), atan(27300), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_55) {
  ck_assert_ldouble_eq_tol(s21_atan(-27800), atan(-27800), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_56) {
  ck_assert_ldouble_eq_tol(s21_atan(28300), atan(28300), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_57) {
  ck_assert_ldouble_eq_tol(s21_atan(-29100), atan(-29100), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_58) {
  ck_assert_ldouble_eq_tol(s21_atan(29600), atan(29600), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_59) {
  ck_assert_ldouble_eq_tol(s21_atan(-30300), atan(-30300), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_60) {
  ck_assert_ldouble_eq_tol(s21_atan(31000), atan(31000), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_61) {
  ck_assert_ldouble_eq_tol(s21_atan(-31500), atan(-31500), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_62) {
  ck_assert_ldouble_eq_tol(s21_atan(31800), atan(31800), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_63) {
  ck_assert_ldouble_eq_tol(s21_atan(-32200), atan(-32200), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_64) {
  ck_assert_ldouble_eq_tol(s21_atan(32900), atan(32900), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_65) {
  ck_assert_ldouble_eq_tol(s21_atan(-33500), atan(-33500), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_66) {
  ck_assert_ldouble_eq_tol(s21_atan(34300), atan(34300), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_67) {
  ck_assert_ldouble_eq_tol(s21_atan(-35000), atan(-35000), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_68) {
  ck_assert_ldouble_eq_tol(s21_atan(35300), atan(35300), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_69) {
  ck_assert_ldouble_eq_tol(s21_atan(-35900), atan(-35900), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_70) {
  ck_assert_ldouble_eq_tol(s21_atan(36300), atan(36300), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_71) {
  ck_assert_ldouble_eq_tol(s21_atan(-37100), atan(-37100), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_72) {
  ck_assert_ldouble_eq_tol(s21_atan(37600), atan(37600), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_73) {
  ck_assert_ldouble_eq_tol(s21_atan(-38000), atan(-38000), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_74) {
  ck_assert_ldouble_eq_tol(s21_atan(38600), atan(38600), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_75) {
  ck_assert_ldouble_eq_tol(s21_atan(-39200), atan(-39200), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_76) {
  ck_assert_ldouble_eq_tol(s21_atan(39700), atan(39700), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_77) {
  ck_assert_ldouble_eq_tol(s21_atan(-40000), atan(-40000), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_78) {
  ck_assert_ldouble_eq_tol(s21_atan(40800), atan(40800), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_79) {
  ck_assert_ldouble_eq_tol(s21_atan(-41100), atan(-41100), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_80) {
  ck_assert_ldouble_eq_tol(s21_atan(41700), atan(41700), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_81) {
  ck_assert_ldouble_eq_tol(s21_atan(-42500), atan(-42500), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_82) {
  ck_assert_ldouble_eq_tol(s21_atan(43000), atan(43000), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_83) {
  ck_assert_ldouble_eq_tol(s21_atan(-43800), atan(-43800), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_84) {
  ck_assert_ldouble_eq_tol(s21_atan(44600), atan(44600), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_85) {
  ck_assert_ldouble_eq_tol(s21_atan(-45400), atan(-45400), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_86) {
  ck_assert_ldouble_eq_tol(s21_atan(46300), atan(46300), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_87) {
  ck_assert_ldouble_eq_tol(s21_atan(-47200), atan(-47200), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_88) {
  ck_assert_ldouble_eq_tol(s21_atan(47900), atan(47900), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_89) {
  ck_assert_ldouble_eq_tol(s21_atan(-48800), atan(-48800), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_90) {
  ck_assert_ldouble_eq_tol(s21_atan(49200), atan(49200), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_91) {
  ck_assert_ldouble_eq_tol(s21_atan(-50000), atan(-50000), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_92) {
  ck_assert_ldouble_eq_tol(s21_atan(50800), atan(50800), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_93) {
  ck_assert_ldouble_eq_tol(s21_atan(-51500), atan(-51500), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_94) {
  ck_assert_ldouble_eq_tol(s21_atan(52200), atan(52200), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_95) {
  ck_assert_ldouble_eq_tol(s21_atan(-52500), atan(-52500), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_96) {
  ck_assert_ldouble_eq_tol(s21_atan(52900), atan(52900), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_97) {
  ck_assert_ldouble_eq_tol(s21_atan(-53300), atan(-53300), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_98) {
  ck_assert_ldouble_eq_tol(s21_atan(53600), atan(53600), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_99) {
  ck_assert_ldouble_eq_tol(s21_atan(-53900), atan(-53900), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_100) {
  ck_assert_ldouble_eq_tol(s21_atan(54700), atan(54700), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_101) {
  ck_assert_ldouble_eq_tol(s21_atan(-55000), atan(-55000), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_102) {
  ck_assert_ldouble_eq_tol(s21_atan(55800), atan(55800), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_103) {
  ck_assert_ldouble_eq_tol(s21_atan(-56300), atan(-56300), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_104) {
  ck_assert_ldouble_eq_tol(s21_atan(56700), atan(56700), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_105) {
  ck_assert_ldouble_eq_tol(s21_atan(-57600), atan(-57600), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_106) {
  ck_assert_ldouble_eq_tol(s21_atan(57900), atan(57900), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_107) {
  ck_assert_ldouble_eq_tol(s21_atan(-58400), atan(-58400), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_108) {
  ck_assert_ldouble_eq_tol(s21_atan(59300), atan(59300), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_109) {
  ck_assert_ldouble_eq_tol(s21_atan(-60200), atan(-60200), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_110) {
  ck_assert_ldouble_eq_tol(s21_atan(60900), atan(60900), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_111) {
  ck_assert_ldouble_eq_tol(s21_atan(-61500), atan(-61500), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_112) {
  ck_assert_ldouble_eq_tol(s21_atan(62400), atan(62400), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_113) {
  ck_assert_ldouble_eq_tol(s21_atan(-63300), atan(-63300), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_114) {
  ck_assert_ldouble_eq_tol(s21_atan(63800), atan(63800), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_115) {
  ck_assert_ldouble_eq_tol(s21_atan(-64600), atan(-64600), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_116) {
  ck_assert_ldouble_eq_tol(s21_atan(65100), atan(65100), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_117) {
  ck_assert_ldouble_eq_tol(s21_atan(-65600), atan(-65600), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_118) {
  ck_assert_ldouble_eq_tol(s21_atan(65900), atan(65900), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_119) {
  ck_assert_ldouble_eq_tol(s21_atan(-66800), atan(-66800), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_120) {
  ck_assert_ldouble_eq_tol(s21_atan(67200), atan(67200), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_121) {
  ck_assert_ldouble_eq_tol(s21_atan(-67700), atan(-67700), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_122) {
  ck_assert_ldouble_eq_tol(s21_atan(68100), atan(68100), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_123) {
  ck_assert_ldouble_eq_tol(s21_atan(-68400), atan(-68400), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_124) {
  ck_assert_ldouble_eq_tol(s21_atan(68700), atan(68700), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_125) {
  ck_assert_ldouble_eq_tol(s21_atan(-69600), atan(-69600), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_126) {
  ck_assert_ldouble_eq_tol(s21_atan(70100), atan(70100), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_127) {
  ck_assert_ldouble_eq_tol(s21_atan(-70.500), atan(-70.500), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_128) {
  ck_assert_ldouble_eq_tol(s21_atan(7.0800), atan(7.0800), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_129) {
  ck_assert_ldouble_eq_tol(s21_atan(-71200), atan(-71200), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_130) {
  ck_assert_ldouble_eq_tol(s21_atan(71.700), atan(71.700), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_131) {
  ck_assert_ldouble_eq_tol(s21_atan(-72300), atan(-72300), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_132) {
  ck_assert_ldouble_eq_tol(s21_atan(72800), atan(72800), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_133) {
  ck_assert_ldouble_eq_tol(s21_atan(-73100), atan(-73100), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_134) {
  ck_assert_ldouble_eq_tol(s21_atan(74000), atan(74000), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_135) {
  ck_assert_ldouble_eq_tol(s21_atan(-74500.123), atan(-74500.123), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_136) {
  ck_assert_ldouble_eq_tol(s21_atan(75400), atan(75400), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_137) {
  ck_assert_ldouble_eq_tol(s21_atan(-76300), atan(-76300), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_138) {
  ck_assert_ldouble_eq_tol(s21_atan(77200), atan(77200), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_139) {
  ck_assert_ldouble_eq_tol(s21_atan(-77900), atan(-77900), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_140) {
  ck_assert_ldouble_eq_tol(s21_atan(78200), atan(78200), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_141) {
  ck_assert_ldouble_eq_tol(s21_atan(-78500), atan(-78500), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_142) {
  ck_assert_ldouble_eq_tol(s21_atan(79300), atan(79300), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_143) {
  ck_assert_ldouble_eq_tol(s21_atan(-80100), atan(-80100), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_144) {
  ck_assert_ldouble_eq_tol(s21_atan(81000), atan(81000), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_145) {
  ck_assert_ldouble_eq_tol(s21_atan(-81800), atan(-81800), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_146) {
  ck_assert_ldouble_eq_tol(s21_atan(82100), atan(82100), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_147) {
  ck_assert_ldouble_eq_tol(s21_atan(-82900), atan(-82900), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_148) {
  ck_assert_ldouble_eq_tol(s21_atan(83500), atan(83500), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_149) {
  ck_assert_ldouble_eq_tol(s21_atan(-84300), atan(-84300), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_150) {
  ck_assert_ldouble_eq_tol(s21_atan(84900), atan(84900), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_151) {
  ck_assert_ldouble_eq_tol(s21_atan(-85600), atan(-85600), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_152) {
  ck_assert_ldouble_eq_tol(s21_atan(86000), atan(86000), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_153) {
  ck_assert_ldouble_eq_tol(s21_atan(-86300), atan(-86300), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_154) {
  ck_assert_ldouble_eq_tol(s21_atan(86800), atan(86800), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_155) {
  ck_assert_ldouble_eq_tol(s21_atan(-87600), atan(-87600), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_156) {
  ck_assert_ldouble_eq_tol(s21_atan(87900), atan(87900), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_157) {
  ck_assert_ldouble_eq_tol(s21_atan(-88800), atan(-88800), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_158) {
  ck_assert_ldouble_eq_tol(s21_atan(89300), atan(89300), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_159) {
  ck_assert_ldouble_eq_tol(s21_atan(-89600), atan(-89600), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_160) {
  ck_assert_ldouble_eq_tol(s21_atan(90300), atan(90300), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_161) {
  ck_assert_ldouble_eq_tol(s21_atan(-91200), atan(-91200), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_162) {
  ck_assert_ldouble_eq_tol(s21_atan(91800), atan(91800), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_163) {
  ck_assert_ldouble_eq_tol(s21_atan(-92400), atan(-92400), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_164) {
  ck_assert_ldouble_eq_tol(s21_atan(92700), atan(92700), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_165) {
  ck_assert_ldouble_eq_tol(s21_atan(-93400), atan(-93400), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_166) {
  ck_assert_ldouble_eq_tol(s21_atan(94100), atan(94100), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_167) {
  ck_assert_ldouble_eq_tol(s21_atan(-94700), atan(-94700), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_168) {
  ck_assert_ldouble_eq_tol(s21_atan(95300), atan(95300), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_169) {
  ck_assert_ldouble_eq_tol(s21_atan(-95600), atan(-95600), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_170) {
  ck_assert_ldouble_eq_tol(s21_atan(96200), atan(96200), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_171) {
  ck_assert_ldouble_eq_tol(s21_atan(-96800), atan(-96800), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_172) {
  ck_assert_ldouble_eq_tol(s21_atan(97500), atan(97500), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_173) {
  ck_assert_ldouble_eq_tol(s21_atan(-97800), atan(-97800), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_174) {
  ck_assert_ldouble_eq_tol(s21_atan(98600), atan(98600), 0.0000001);
}
END_TEST

START_TEST(s21_atan_test_175) {
  ck_assert_ldouble_eq_tol(s21_atan(-99200), atan(-99200), 0.0000001);
}
END_TEST
START_TEST(s21_atan_test_176) {
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), 0.0000001);
}
END_TEST
START_TEST(s21_atan_test_177) {
  ck_assert_ldouble_eq_tol(s21_atan(-0), atan(-0), 0.0000001);
}
END_TEST
START_TEST(s21_atan_test_178) {
  ck_assert_ldouble_eq_tol(s21_atan(s21_sqrt(2) / 2), atan(s21_sqrt(2) / 2),
                           0.0000001);
}
END_TEST
START_TEST(s21_atan_test_179) {
  ck_assert_ldouble_eq_tol(s21_atan(1.000005), atan(1.000005), 0.0000001);
}
END_TEST
START_TEST(s21_atan_test_180) {
  ck_assert_ldouble_eq_tol(s21_atan(1.0000005), atan(1.0000005), 0.0000001);
}
END_TEST
START_TEST(s21_atan_test_181) {
  ck_assert_ldouble_eq_tol(s21_atan(1248246129586125.0),
                           atan(1248246129586125.0), 0.0000001);
}
END_TEST
START_TEST(s21_atan_test_182) {
  ck_assert_ldouble_eq_tol(s21_atan(0.00000000000000123),
                           atan(0.00000000000000123), 0.0000001);
}
END_TEST
START_TEST(s21_atan_test_183) {
  ck_assert_ldouble_eq_tol(s21_atan(S21_MAX_DOUBLE), atan(S21_MAX_DOUBLE),
                           0.0000001);
}
END_TEST
START_TEST(s21_atan_test_184) {
  ck_assert_ldouble_eq_tol(s21_atan(S21_MIN_DOUBLE), atan(S21_MIN_DOUBLE),
                           0.0000001);
}
END_TEST

Suite *s21_atan_test_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_atan_test_suite");
  tc = tcase_create("s21_atan_test_suite");
  tcase_add_test(tc, s21_atan_test_1);
  tcase_add_test(tc, s21_atan_test_2);
  tcase_add_test(tc, s21_atan_test_3);
  tcase_add_test(tc, s21_atan_test_4);
  tcase_add_test(tc, s21_atan_test_5);
  tcase_add_test(tc, s21_atan_test_6);
  tcase_add_test(tc, s21_atan_test_7);
  tcase_add_test(tc, s21_atan_test_8);
  tcase_add_test(tc, s21_atan_test_9);
  tcase_add_test(tc, s21_atan_test_10);
  tcase_add_test(tc, s21_atan_test_11);
  tcase_add_test(tc, s21_atan_test_12);
  tcase_add_test(tc, s21_atan_test_13);
  tcase_add_test(tc, s21_atan_test_14);
  tcase_add_test(tc, s21_atan_test_15);
  tcase_add_test(tc, s21_atan_test_16);
  tcase_add_test(tc, s21_atan_test_17);
  tcase_add_test(tc, s21_atan_test_18);
  tcase_add_test(tc, s21_atan_test_19);
  tcase_add_test(tc, s21_atan_test_20);
  tcase_add_test(tc, s21_atan_test_21);
  tcase_add_test(tc, s21_atan_test_22);
  tcase_add_test(tc, s21_atan_test_23);
  tcase_add_test(tc, s21_atan_test_24);
  tcase_add_test(tc, s21_atan_test_25);
  tcase_add_test(tc, s21_atan_test_26);
  tcase_add_test(tc, s21_atan_test_27);
  tcase_add_test(tc, s21_atan_test_28);
  tcase_add_test(tc, s21_atan_test_29);
  tcase_add_test(tc, s21_atan_test_30);
  tcase_add_test(tc, s21_atan_test_31);
  tcase_add_test(tc, s21_atan_test_32);
  tcase_add_test(tc, s21_atan_test_33);
  tcase_add_test(tc, s21_atan_test_34);
  tcase_add_test(tc, s21_atan_test_35);
  tcase_add_test(tc, s21_atan_test_36);
  tcase_add_test(tc, s21_atan_test_37);
  tcase_add_test(tc, s21_atan_test_38);
  tcase_add_test(tc, s21_atan_test_39);
  tcase_add_test(tc, s21_atan_test_40);
  tcase_add_test(tc, s21_atan_test_41);
  tcase_add_test(tc, s21_atan_test_42);
  tcase_add_test(tc, s21_atan_test_43);
  tcase_add_test(tc, s21_atan_test_44);
  tcase_add_test(tc, s21_atan_test_45);
  tcase_add_test(tc, s21_atan_test_46);
  tcase_add_test(tc, s21_atan_test_47);
  tcase_add_test(tc, s21_atan_test_48);
  tcase_add_test(tc, s21_atan_test_49);
  tcase_add_test(tc, s21_atan_test_50);
  tcase_add_test(tc, s21_atan_test_51);
  tcase_add_test(tc, s21_atan_test_52);
  tcase_add_test(tc, s21_atan_test_53);
  tcase_add_test(tc, s21_atan_test_54);
  tcase_add_test(tc, s21_atan_test_55);
  tcase_add_test(tc, s21_atan_test_56);
  tcase_add_test(tc, s21_atan_test_57);
  tcase_add_test(tc, s21_atan_test_58);
  tcase_add_test(tc, s21_atan_test_59);
  tcase_add_test(tc, s21_atan_test_60);
  tcase_add_test(tc, s21_atan_test_61);
  tcase_add_test(tc, s21_atan_test_62);
  tcase_add_test(tc, s21_atan_test_63);
  tcase_add_test(tc, s21_atan_test_64);
  tcase_add_test(tc, s21_atan_test_65);
  tcase_add_test(tc, s21_atan_test_66);
  tcase_add_test(tc, s21_atan_test_67);
  tcase_add_test(tc, s21_atan_test_68);
  tcase_add_test(tc, s21_atan_test_69);
  tcase_add_test(tc, s21_atan_test_70);
  tcase_add_test(tc, s21_atan_test_71);
  tcase_add_test(tc, s21_atan_test_72);
  tcase_add_test(tc, s21_atan_test_73);
  tcase_add_test(tc, s21_atan_test_74);
  tcase_add_test(tc, s21_atan_test_75);
  tcase_add_test(tc, s21_atan_test_76);
  tcase_add_test(tc, s21_atan_test_77);
  tcase_add_test(tc, s21_atan_test_78);
  tcase_add_test(tc, s21_atan_test_79);
  tcase_add_test(tc, s21_atan_test_80);
  tcase_add_test(tc, s21_atan_test_81);
  tcase_add_test(tc, s21_atan_test_82);
  tcase_add_test(tc, s21_atan_test_83);
  tcase_add_test(tc, s21_atan_test_84);
  tcase_add_test(tc, s21_atan_test_85);
  tcase_add_test(tc, s21_atan_test_86);
  tcase_add_test(tc, s21_atan_test_87);
  tcase_add_test(tc, s21_atan_test_88);
  tcase_add_test(tc, s21_atan_test_89);
  tcase_add_test(tc, s21_atan_test_90);
  tcase_add_test(tc, s21_atan_test_91);
  tcase_add_test(tc, s21_atan_test_92);
  tcase_add_test(tc, s21_atan_test_93);
  tcase_add_test(tc, s21_atan_test_94);
  tcase_add_test(tc, s21_atan_test_95);
  tcase_add_test(tc, s21_atan_test_96);
  tcase_add_test(tc, s21_atan_test_97);
  tcase_add_test(tc, s21_atan_test_98);
  tcase_add_test(tc, s21_atan_test_99);
  tcase_add_test(tc, s21_atan_test_100);
  tcase_add_test(tc, s21_atan_test_101);
  tcase_add_test(tc, s21_atan_test_102);
  tcase_add_test(tc, s21_atan_test_103);
  tcase_add_test(tc, s21_atan_test_104);
  tcase_add_test(tc, s21_atan_test_105);
  tcase_add_test(tc, s21_atan_test_106);
  tcase_add_test(tc, s21_atan_test_107);
  tcase_add_test(tc, s21_atan_test_108);
  tcase_add_test(tc, s21_atan_test_109);
  tcase_add_test(tc, s21_atan_test_110);
  tcase_add_test(tc, s21_atan_test_111);
  tcase_add_test(tc, s21_atan_test_112);
  tcase_add_test(tc, s21_atan_test_113);
  tcase_add_test(tc, s21_atan_test_114);
  tcase_add_test(tc, s21_atan_test_115);
  tcase_add_test(tc, s21_atan_test_116);
  tcase_add_test(tc, s21_atan_test_117);
  tcase_add_test(tc, s21_atan_test_118);
  tcase_add_test(tc, s21_atan_test_119);
  tcase_add_test(tc, s21_atan_test_120);
  tcase_add_test(tc, s21_atan_test_121);
  tcase_add_test(tc, s21_atan_test_122);
  tcase_add_test(tc, s21_atan_test_123);
  tcase_add_test(tc, s21_atan_test_124);
  tcase_add_test(tc, s21_atan_test_125);
  tcase_add_test(tc, s21_atan_test_126);
  tcase_add_test(tc, s21_atan_test_127);
  tcase_add_test(tc, s21_atan_test_128);
  tcase_add_test(tc, s21_atan_test_129);
  tcase_add_test(tc, s21_atan_test_130);
  tcase_add_test(tc, s21_atan_test_131);
  tcase_add_test(tc, s21_atan_test_132);
  tcase_add_test(tc, s21_atan_test_133);
  tcase_add_test(tc, s21_atan_test_134);
  tcase_add_test(tc, s21_atan_test_135);
  tcase_add_test(tc, s21_atan_test_136);
  tcase_add_test(tc, s21_atan_test_137);
  tcase_add_test(tc, s21_atan_test_138);
  tcase_add_test(tc, s21_atan_test_139);
  tcase_add_test(tc, s21_atan_test_140);
  tcase_add_test(tc, s21_atan_test_141);
  tcase_add_test(tc, s21_atan_test_142);
  tcase_add_test(tc, s21_atan_test_143);
  tcase_add_test(tc, s21_atan_test_144);
  tcase_add_test(tc, s21_atan_test_145);
  tcase_add_test(tc, s21_atan_test_146);
  tcase_add_test(tc, s21_atan_test_147);
  tcase_add_test(tc, s21_atan_test_148);
  tcase_add_test(tc, s21_atan_test_149);
  tcase_add_test(tc, s21_atan_test_150);
  tcase_add_test(tc, s21_atan_test_151);
  tcase_add_test(tc, s21_atan_test_152);
  tcase_add_test(tc, s21_atan_test_153);
  tcase_add_test(tc, s21_atan_test_154);
  tcase_add_test(tc, s21_atan_test_155);
  tcase_add_test(tc, s21_atan_test_156);
  tcase_add_test(tc, s21_atan_test_157);
  tcase_add_test(tc, s21_atan_test_158);
  tcase_add_test(tc, s21_atan_test_159);
  tcase_add_test(tc, s21_atan_test_160);
  tcase_add_test(tc, s21_atan_test_161);
  tcase_add_test(tc, s21_atan_test_162);
  tcase_add_test(tc, s21_atan_test_163);
  tcase_add_test(tc, s21_atan_test_164);
  tcase_add_test(tc, s21_atan_test_165);
  tcase_add_test(tc, s21_atan_test_166);
  tcase_add_test(tc, s21_atan_test_167);
  tcase_add_test(tc, s21_atan_test_168);
  tcase_add_test(tc, s21_atan_test_169);
  tcase_add_test(tc, s21_atan_test_170);
  tcase_add_test(tc, s21_atan_test_171);
  tcase_add_test(tc, s21_atan_test_172);
  tcase_add_test(tc, s21_atan_test_173);
  tcase_add_test(tc, s21_atan_test_174);
  tcase_add_test(tc, s21_atan_test_175);
  tcase_add_test(tc, s21_atan_test_176);
  tcase_add_test(tc, s21_atan_test_177);
  tcase_add_test(tc, s21_atan_test_178);
  tcase_add_test(tc, s21_atan_test_179);
  tcase_add_test(tc, s21_atan_test_180);
  tcase_add_test(tc, s21_atan_test_181);
  tcase_add_test(tc, s21_atan_test_182);
  tcase_add_test(tc, s21_atan_test_183);
  tcase_add_test(tc, s21_atan_test_184);

  suite_add_tcase(s, tc);
  return s;
}
