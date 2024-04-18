
#include "s21_test.h"

START_TEST(s21_fmod_test_1) {
  double x = -123.123;
  double y = 0.0;
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_test_2) {
  double x = S21_NAN;
  double y = 0.0;

  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_test_3) {
  double x = S21_NAN;
  double y = S21_NAN;

  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_test_4) {
  double x = -123.123;
  double y = S21_NAN;

  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_test_5) {
  double x = S21_NAN;
  double y = 4.5;

  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_test_6) {
  double x = INFINITY;
  double y = 4.5;

  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_test_7) {
  double x = -INFINITY;
  double y = 4.5;

  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_test_8) {
  double x = 456.456;
  double y = 123.123;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_9) {
  double x = 123.123;
  double y = 456.456;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST
START_TEST(s21_fmod_test_10) {
  double x = 123.123;
  double y = 123.123;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_11) {
  double x = -123.123;
  double y = -123.123;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_12) {
  double x = -123.123;
  double y = -456.456;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_13) {
  double x = -456.456;
  double y = 123.123;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_14) {
  double x = 456.456;
  double y = -123.123;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_15) {
  double x = -456.456;
  double y = -123.123;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_16) {
  double x = 123.123;
  double y = INFINITY;

  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_test_17) {
  double x = 0.0;
  double y = 123.123;

  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_test_18) {
  double x = 12948124.12313;
  double y = 0;

  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_test_19) {
  double x = 0;
  double y = 0;

  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST
START_TEST(s21_fmod_test_20) {
  double x = 1.1;
  double y = 1.1;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_21) {
  double x = 1130.7756;
  double y = 8.2155;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_22) {
  double x = 2280.8925;
  double y = 13.4271;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_23) {
  double x = 3204.8046999999997;
  double y = 20.366;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_24) {
  double x = 4196.535199999999;
  double y = 27.8355;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_25) {
  double x = 5239.271599999999;
  double y = 36.1555;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_26) {
  double x = 6291.900299999999;
  double y = 46.0647;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_27) {
  double x = 7408.421899999999;
  double y = 52.7258;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_28) {
  double x = 8585.9121;
  double y = 55.2941;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_29) {
  double x = 9670.302899999999;
  double y = 58.6815;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_30) {
  double x = 10788.352499999999;
  double y = 67.9021;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_31) {
  double x = 11739.4219;
  double y = 77.054;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_32) {
  double x = 12706.620799999999;
  double y = 81.8781;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_33) {
  double x = 13860.319599999999;
  double y = 83.2973;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_34) {
  double x = 14893.771999999999;
  double y = 87.42060000000001;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_35) {
  double x = 15910.576799999999;
  double y = 90.84440000000001;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_36) {
  double x = 16867.342099999998;
  double y = 92.6452;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_37) {
  double x = 17859.699299999997;
  double y = 99.6867;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_38) {
  double x = 18811.827999999998;
  double y = 105.1832;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_39) {
  double x = 19776.805399999997;
  double y = 114.8085;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_40) {
  double x = 20766.871499999997;
  double y = 116.5251;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_41) {
  double x = 21895.445299999996;
  double y = 125.27749999999999;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_42) {
  double x = 22818.413299999997;
  double y = 131.45839999999998;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_43) {
  double x = 23792.377599999996;
  double y = 132.7831;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_44) {
  double x = 24991.003799999995;
  double y = 139.9714;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_45) {
  double x = 26111.476399999996;
  double y = 148.00709999999998;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_46) {
  double x = 27306.261099999996;
  double y = 153.30739999999997;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_47) {
  double x = 28362.838499999994;
  double y = 163.01549999999997;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_48) {
  double x = 29393.204699999995;
  double y = 167.02839999999998;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_49) {
  double x = 30325.526699999995;
  double y = 169.6067;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_50) {
  double x = 31528.038699999994;
  double y = 178.2087;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_51) {
  double x = 32466.109599999992;
  double y = 186.4316;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_52) {
  double x = 33506.85239999999;
  double y = 192.5413;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_53) {
  double x = 34489.02759999999;
  double y = 199.9768;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_54) {
  double x = 35467.02959999999;
  double y = 209.6619;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_55) {
  double x = 36641.18389999999;
  double y = 217.0401;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_56) {
  double x = 37613.06429999999;
  double y = 223.4478;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_57) {
  double x = 38817.61319999999;
  double y = 224.8974;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_58) {
  double x = 39996.22209999999;
  double y = 233.28900000000002;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_59) {
  double x = 40969.337199999994;
  double y = 237.6399;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_60) {
  double x = 42068.71689999999;
  double y = 245.63580000000002;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_61) {
  double x = 43179.23679999999;
  double y = 252.45960000000002;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_62) {
  double x = 44143.77949999999;
  double y = 259.9753;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_63) {
  double x = 45322.74659999999;
  double y = 269.3602;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_64) {
  double x = 46350.73919999999;
  double y = 274.8;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_65) {
  double x = 47483.03399999999;
  double y = 276.9087;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_66) {
  double x = 48607.72479999999;
  double y = 283.7624;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_67) {
  double x = 49755.78119999999;
  double y = 286.3711;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_68) {
  double x = 50961.92319999999;
  double y = 292.2749;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_69) {
  double x = 52044.38409999999;
  double y = 294.2891;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_70) {
  double x = 53056.029399999985;
  double y = 299.8548;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_71) {
  double x = 54158.286599999985;
  double y = 306.6123;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_72) {
  double x = 55353.78839999998;
  double y = 311.3186;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_73) {
  double x = 56487.44739999998;
  double y = 320.3781;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_74) {
  double x = 57425.76029999998;
  double y = 323.9931;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_75) {
  double x = 58531.94779999998;
  double y = 326.5846;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_76) {
  double x = 59563.09199999998;
  double y = 332.547;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_77) {
  double x = 60566.700499999984;
  double y = 334.7765;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_78) {
  double x = 61743.97389999998;
  double y = 336.1322;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_79) {
  double x = 62917.07499999998;
  double y = 339.2633;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_80) {
  double x = 63915.46679999998;
  double y = 344.54970000000003;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_81) {
  double x = 64912.09139999998;
  double y = 353.3804;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_82) {
  double x = 66090.51799999998;
  double y = 357.9272;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_83) {
  double x = 67238.70449999998;
  double y = 364.2386;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_84) {
  double x = 68367.22419999998;
  double y = 366.6501;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_85) {
  double x = 69520.35569999999;
  double y = 368.6435;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_86) {
  double x = 70698.64469999999;
  double y = 376.55920000000003;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_87) {
  double x = 71770.21199999998;
  double y = 384.69530000000003;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_88) {
  double x = 72718.91519999999;
  double y = 388.23380000000003;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_89) {
  double x = 73734.69389999998;
  double y = 394.6143;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_90) {
  double x = 74825.67739999999;
  double y = 404.01410000000004;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_91) {
  double x = 75813.00849999998;
  double y = 409.51370000000003;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_92) {
  double x = 76962.25449999998;
  double y = 418.62230000000005;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_93) {
  double x = 78007.50609999998;
  double y = 420.24760000000003;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_94) {
  double x = 79080.10319999998;
  double y = 422.76370000000003;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_95) {
  double x = 80268.53339999999;
  double y = 432.3718;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_96) {
  double x = 81204.32029999999;
  double y = 438.35360000000003;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_97) {
  double x = 82246.222;
  double y = 443.50230000000005;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_98) {
  double x = 83205.8302;
  double y = 449.30190000000005;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_99) {
  double x = 84116.0529;
  double y = 456.77900000000005;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_100) {
  double x = 85050.5716;
  double y = 465.2216000000001;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_101) {
  double x = 86032.28839999999;
  double y = 473.9512000000001;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_102) {
  double x = 87001.5428;
  double y = 475.61390000000006;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_103) {
  double x = 87998.7139;
  double y = 482.68210000000005;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_104) {
  double x = 88980.806;
  double y = 485.27320000000003;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_105) {
  double x = 89951.2377;
  double y = 486.7653;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_106) {
  double x = 91002.5918;
  double y = 491.9035;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_107) {
  double x = 91971.65909999999;
  double y = 499.9716;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_108) {
  double x = 92876.65079999999;
  double y = 504.43330000000003;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_109) {
  double x = 93832.64989999999;
  double y = 510.1797;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_110) {
  double x = 95014.20219999999;
  double y = 518.7832000000001;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_111) {
  double x = 96036.99849999999;
  double y = 525.2355000000001;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_112) {
  double x = 97105.32469999998;
  double y = 533.2737000000001;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_113) {
  double x = 98297.87339999998;
  double y = 538.1621000000001;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_114) {
  double x = 99217.25009999998;
  double y = 543.9272000000001;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_115) {
  double x = 12874612749219476.0;
  double y = 12412412.0;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.000001);
}
END_TEST

START_TEST(s21_fmod_test_116) {
  double x = 0.000000000000123;
  double y = 0.00000000000000123;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.0000001);
}
END_TEST

START_TEST(s21_fmod_test_117) {
  double x = 1287461274921947.0;
  double y = 12412412.0;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.000001);
}
END_TEST

START_TEST(s21_fmod_test_118) {
  double x = S21_MAX_DOUBLE;
  double y = 2.0;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.000001);
}
END_TEST

START_TEST(s21_fmod_test_119) {
  double x = 212312.2;
  double y = S21_MAX_DOUBLE;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.000001);
}
END_TEST

START_TEST(s21_fmod_test_120) {
  double x = S21_MAX_DOUBLE;
  double y = S21_MAX_DOUBLE;

  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 0.000001);
}
END_TEST

Suite *s21_fmod_test_suite(void) {
  Suite *suite = suite_create("s21_fmod");
  TCase *tcase_core = tcase_create("s21_fmod");

  tcase_add_test(tcase_core, s21_fmod_test_1);
  tcase_add_test(tcase_core, s21_fmod_test_2);
  tcase_add_test(tcase_core, s21_fmod_test_3);
  tcase_add_test(tcase_core, s21_fmod_test_4);
  tcase_add_test(tcase_core, s21_fmod_test_5);
  tcase_add_test(tcase_core, s21_fmod_test_6);
  tcase_add_test(tcase_core, s21_fmod_test_7);
  tcase_add_test(tcase_core, s21_fmod_test_8);
  tcase_add_test(tcase_core, s21_fmod_test_9);
  tcase_add_test(tcase_core, s21_fmod_test_10);
  tcase_add_test(tcase_core, s21_fmod_test_11);
  tcase_add_test(tcase_core, s21_fmod_test_12);
  tcase_add_test(tcase_core, s21_fmod_test_13);
  tcase_add_test(tcase_core, s21_fmod_test_14);
  tcase_add_test(tcase_core, s21_fmod_test_15);
  tcase_add_test(tcase_core, s21_fmod_test_16);
  tcase_add_test(tcase_core, s21_fmod_test_17);
  tcase_add_test(tcase_core, s21_fmod_test_18);
  tcase_add_test(tcase_core, s21_fmod_test_19);
  tcase_add_test(tcase_core, s21_fmod_test_20);
  tcase_add_test(tcase_core, s21_fmod_test_21);
  tcase_add_test(tcase_core, s21_fmod_test_22);
  tcase_add_test(tcase_core, s21_fmod_test_23);
  tcase_add_test(tcase_core, s21_fmod_test_24);
  tcase_add_test(tcase_core, s21_fmod_test_25);
  tcase_add_test(tcase_core, s21_fmod_test_26);
  tcase_add_test(tcase_core, s21_fmod_test_27);
  tcase_add_test(tcase_core, s21_fmod_test_28);
  tcase_add_test(tcase_core, s21_fmod_test_29);
  tcase_add_test(tcase_core, s21_fmod_test_30);
  tcase_add_test(tcase_core, s21_fmod_test_31);
  tcase_add_test(tcase_core, s21_fmod_test_32);
  tcase_add_test(tcase_core, s21_fmod_test_33);
  tcase_add_test(tcase_core, s21_fmod_test_34);
  tcase_add_test(tcase_core, s21_fmod_test_35);
  tcase_add_test(tcase_core, s21_fmod_test_36);
  tcase_add_test(tcase_core, s21_fmod_test_37);
  tcase_add_test(tcase_core, s21_fmod_test_38);
  tcase_add_test(tcase_core, s21_fmod_test_39);
  tcase_add_test(tcase_core, s21_fmod_test_40);
  tcase_add_test(tcase_core, s21_fmod_test_41);
  tcase_add_test(tcase_core, s21_fmod_test_42);
  tcase_add_test(tcase_core, s21_fmod_test_43);
  tcase_add_test(tcase_core, s21_fmod_test_44);
  tcase_add_test(tcase_core, s21_fmod_test_45);
  tcase_add_test(tcase_core, s21_fmod_test_46);
  tcase_add_test(tcase_core, s21_fmod_test_47);
  tcase_add_test(tcase_core, s21_fmod_test_48);
  tcase_add_test(tcase_core, s21_fmod_test_49);
  tcase_add_test(tcase_core, s21_fmod_test_50);
  tcase_add_test(tcase_core, s21_fmod_test_51);
  tcase_add_test(tcase_core, s21_fmod_test_52);
  tcase_add_test(tcase_core, s21_fmod_test_53);
  tcase_add_test(tcase_core, s21_fmod_test_54);
  tcase_add_test(tcase_core, s21_fmod_test_55);
  tcase_add_test(tcase_core, s21_fmod_test_56);
  tcase_add_test(tcase_core, s21_fmod_test_57);
  tcase_add_test(tcase_core, s21_fmod_test_58);
  tcase_add_test(tcase_core, s21_fmod_test_59);
  tcase_add_test(tcase_core, s21_fmod_test_60);
  tcase_add_test(tcase_core, s21_fmod_test_61);
  tcase_add_test(tcase_core, s21_fmod_test_62);
  tcase_add_test(tcase_core, s21_fmod_test_63);
  tcase_add_test(tcase_core, s21_fmod_test_64);
  tcase_add_test(tcase_core, s21_fmod_test_65);
  tcase_add_test(tcase_core, s21_fmod_test_66);
  tcase_add_test(tcase_core, s21_fmod_test_67);
  tcase_add_test(tcase_core, s21_fmod_test_68);
  tcase_add_test(tcase_core, s21_fmod_test_69);
  tcase_add_test(tcase_core, s21_fmod_test_70);
  tcase_add_test(tcase_core, s21_fmod_test_71);
  tcase_add_test(tcase_core, s21_fmod_test_72);
  tcase_add_test(tcase_core, s21_fmod_test_73);
  tcase_add_test(tcase_core, s21_fmod_test_74);
  tcase_add_test(tcase_core, s21_fmod_test_75);
  tcase_add_test(tcase_core, s21_fmod_test_76);
  tcase_add_test(tcase_core, s21_fmod_test_77);
  tcase_add_test(tcase_core, s21_fmod_test_78);
  tcase_add_test(tcase_core, s21_fmod_test_79);
  tcase_add_test(tcase_core, s21_fmod_test_80);
  tcase_add_test(tcase_core, s21_fmod_test_81);
  tcase_add_test(tcase_core, s21_fmod_test_82);
  tcase_add_test(tcase_core, s21_fmod_test_83);
  tcase_add_test(tcase_core, s21_fmod_test_84);
  tcase_add_test(tcase_core, s21_fmod_test_85);
  tcase_add_test(tcase_core, s21_fmod_test_86);
  tcase_add_test(tcase_core, s21_fmod_test_87);
  tcase_add_test(tcase_core, s21_fmod_test_88);
  tcase_add_test(tcase_core, s21_fmod_test_89);
  tcase_add_test(tcase_core, s21_fmod_test_90);
  tcase_add_test(tcase_core, s21_fmod_test_91);
  tcase_add_test(tcase_core, s21_fmod_test_92);
  tcase_add_test(tcase_core, s21_fmod_test_93);
  tcase_add_test(tcase_core, s21_fmod_test_94);
  tcase_add_test(tcase_core, s21_fmod_test_95);
  tcase_add_test(tcase_core, s21_fmod_test_96);
  tcase_add_test(tcase_core, s21_fmod_test_97);
  tcase_add_test(tcase_core, s21_fmod_test_98);
  tcase_add_test(tcase_core, s21_fmod_test_99);
  tcase_add_test(tcase_core, s21_fmod_test_100);
  tcase_add_test(tcase_core, s21_fmod_test_101);
  tcase_add_test(tcase_core, s21_fmod_test_102);
  tcase_add_test(tcase_core, s21_fmod_test_103);
  tcase_add_test(tcase_core, s21_fmod_test_104);
  tcase_add_test(tcase_core, s21_fmod_test_105);
  tcase_add_test(tcase_core, s21_fmod_test_106);
  tcase_add_test(tcase_core, s21_fmod_test_107);
  tcase_add_test(tcase_core, s21_fmod_test_108);
  tcase_add_test(tcase_core, s21_fmod_test_109);
  tcase_add_test(tcase_core, s21_fmod_test_110);
  tcase_add_test(tcase_core, s21_fmod_test_111);
  tcase_add_test(tcase_core, s21_fmod_test_112);
  tcase_add_test(tcase_core, s21_fmod_test_113);
  tcase_add_test(tcase_core, s21_fmod_test_114);
  tcase_add_test(tcase_core, s21_fmod_test_115);
  tcase_add_test(tcase_core, s21_fmod_test_116);
  tcase_add_test(tcase_core, s21_fmod_test_117);
  tcase_add_test(tcase_core, s21_fmod_test_118);
  tcase_add_test(tcase_core, s21_fmod_test_119);
  tcase_add_test(tcase_core, s21_fmod_test_120);

  suite_add_tcase(suite, tcase_core);

  return suite;
}