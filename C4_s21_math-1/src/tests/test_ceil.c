#include "s21_test.h"

START_TEST(s21_ceil_test_1) {
  double x = 33.6;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_2) {
  double x = -456789525.5555554;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_3) {
  double x = 98652147.25;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_4) {
  double x = 9999999.999999;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_5) {
  double x = 98.0;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_6) {
  double x = NAN;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_7) {
  double x = INFINITY;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_8) {
  double x = -INFINITY;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_9) {
  double x = 0;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_10) {
  double x = 900.5;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_11) {
  double x = -1400.7941176470588;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_12) {
  double x = 2001.1691176470588;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_13) {
  double x = -2501.835784313725;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_14) {
  double x = 2802.285784313725;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_15) {
  double x = -3202.9780920060325;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_16) {
  double x = 3703.4517762165588;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_17) {
  double x = -4203.618442883226;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_18) {
  double x = 4903.868442883226;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_19) {
  double x = -5304.0684428832255;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_20) {
  double x = 6104.489495514805;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_21) {
  double x = -6804.700021830594;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_22) {
  double x = 7305.3923295229015;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_23) {
  double x = -7906.1196022501745;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_24) {
  double x = 8506.269602250175;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_25) {
  double x = -8906.996874977447;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_26) {
  double x = 9707.46746321274;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_27) {
  double x = -10607.86746321274;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_28) {
  double x = 11408.200796546074;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_29) {
  double x = -11808.431565776844;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_30) {
  double x = 12208.831565776843;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_31) {
  double x = -13109.164899110177;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_32) {
  double x = 13409.857206802486;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_33) {
  double x = -14110.657206802485;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_34) {
  double x = 14411.127795037779;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_35) {
  double x = -14911.877795037779;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_36) {
  double x = 15412.044461704445;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_37) {
  double x = -16112.258747418731;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_38) {
  double x = 16912.50874741873;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_39) {
  double x = -17712.842080752063;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_40) {
  double x = 18013.342080752063;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_41) {
  double x = -18513.649773059755;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_42) {
  double x = 19314.034388444372;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_43) {
  double x = -20114.488933898916;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_44) {
  double x = 20614.93337834336;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_45) {
  double x = -21015.37087834336;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_46) {
  double x = 21916.070878343362;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_47) {
  double x = -22216.491930974942;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_48) {
  double x = 22716.95859764161;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_49) {
  double x = -23017.75859764161;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_50) {
  double x = 23818.09193097494;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_51) {
  double x = -24618.89193097494;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_52) {
  double x = 25419.39193097494;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_53) {
  double x = -26119.69193097494;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_54) {
  double x = 26920.09193097494;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_55) {
  double x = -27720.637385520396;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_56) {
  double x = 28220.949885520396;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_57) {
  double x = -28621.366552187064;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_58) {
  double x = 29221.58083790135;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_59) {
  double x = -29622.18083790135;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_60) {
  double x = 30522.76417123468;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_61) {
  double x = -30923.06417123468;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_62) {
  double x = 31223.349885520394;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_63) {
  double x = -31823.724885520394;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_64) {
  double x = 32624.2542972851;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_65) {
  double x = -33324.5542972851;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_66) {
  double x = 34224.99874172955;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_67) {
  double x = -35125.53720326801;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_68) {
  double x = 35525.69509800485;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_69) {
  double x = -36125.84509800485;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_70) {
  double x = 36426.289542449296;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_71) {
  double x = -37026.653178812936;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_72) {
  double x = 37527.01032167008;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_73) {
  double x = -38227.48400588061;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_74) {
  double x = 38927.92845032505;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_75) {
  double x = -39528.59511699172;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_76) {
  double x = 39928.948058168186;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_77) {
  double x = -40429.09805816819;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_78) {
  double x = 40829.34805816819;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_79) {
  double x = -41529.68139150152;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_80) {
  double x = 42030.32424864438;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_81) {
  double x = -42830.82424864438;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_82) {
  double x = 43731.21313753327;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_83) {
  double x = -44531.64170896184;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_84) {
  double x = 44932.459890780025;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_85) {
  double x = -45332.65989078002;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_86) {
  double x = 45932.87041709581;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_87) {
  double x = -46833.27041709581;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_88) {
  double x = 47733.7410053311;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_89) {
  double x = -48134.041005331106;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_90) {
  double x = 49034.198900067946;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_91) {
  double x = -49334.698900067946;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_92) {
  double x = 50035.011400067946;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_93) {
  double x = -50435.37982112058;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_94) {
  double x = 50935.91315445391;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_95) {
  double x = -51336.41315445391;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_96) {
  double x = 51636.6236807697;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_97) {
  double x = -52237.04473340128;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_98) {
  double x = 53137.29473340128;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_99) {
  double x = -54037.602425708974;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_100) {
  double x = 54937.91011801667;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_101) {
  double x = -55438.376784683336;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_102) {
  double x = 55838.649511956064;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_103) {
  double x = -56639.10405741061;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_104) {
  double x = 57039.5746456459;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_105) {
  double x = -57639.84737291863;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_106) {
  double x = 58140.23198830325;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_107) {
  double x = -58540.38198830325;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_108) {
  double x = 59440.64865496992;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_109) {
  double x = -60040.981988303254;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_110) {
  double x = 60641.345624666894;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_111) {
  double x = -61241.96100928228;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_112) {
  double x = 62142.46100928228;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_113) {
  double x = -62443.07639389766;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_114) {
  double x = 63043.35417167544;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_115) {
  double x = -63443.68750500878;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_116) {
  double x = 64244.07212039339;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_117) {
  double x = -64844.45673577801;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_118) {
  double x = 65444.85673577801;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_119) {
  double x = -66045.21387863516;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_120) {
  double x = 66345.54721196849;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_121) {
  double x = -66646.24721196848;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_122) {
  double x = 67246.52498974626;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_123) {
  double x = -68046.81070403197;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_124) {
  double x = 68347.16070403198;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_125) {
  double x = -68947.51784688912;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_126) {
  double x = 69247.82553919681;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_127) {
  double x = -69548.2255391968;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_128) {
  double x = 70048.69922340733;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_129) {
  double x = -70349.19922340733;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_130) {
  double x = 71249.69922340733;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_131) {
  double x = -72049.99922340733;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_132) {
  double x = 72550.24922340733;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_133) {
  double x = -72850.915890074;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_134) {
  double x = 73351.33255674067;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_135) {
  double x = -74251.7940952022;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_136) {
  double x = 74952.36552377364;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_137) {
  double x = -75352.76552377363;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_138) {
  double x = 76153.58370559181;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_139) {
  double x = -76653.74160032865;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_140) {
  double x = 77254.27101209335;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_141) {
  double x = -77554.87101209335;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_142) {
  double x = 78455.48639670874;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_143) {
  double x = -78855.66286729698;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_144) {
  double x = 79555.86286729698;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_145) {
  double x = -80256.19620063031;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_146) {
  double x = 80656.92347335759;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_147) {
  double x = -80957.42347335759;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_148) {
  double x = 81457.92347335759;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_149) {
  double x = -82358.22347335759;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_150) {
  double x = 82858.76892790305;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_151) {
  double x = -83759.04670568083;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_152) {
  double x = 84059.45847038671;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_153) {
  double x = -84960.05847038672;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_154) {
  double x = 85460.85847038672;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_155) {
  double x = -86361.38788215142;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_156) {
  double x = 87161.69557445911;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_157) {
  double x = -87662.22890779245;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_158) {
  double x = 88262.62890779244;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_159) {
  double x = -88962.91462207815;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_160) {
  double x = 89863.21462207816;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_161) {
  double x = -90463.74403384286;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_162) {
  double x = 91264.44403384285;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_163) {
  double x = -92064.91771805337;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_164) {
  double x = 92665.46317259883;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_165) {
  double x = -93165.66317259883;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_166) {
  double x = 94066.06317259882;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_167) {
  double x = -94366.43159365145;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_168) {
  double x = 94966.6668877691;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_169) {
  double x = -95867.2668877691;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_170) {
  double x = 96567.67865247499;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_171) {
  double x = -97267.92865247499;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_172) {
  double x = 97568.20643025277;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_173) {
  double x = -98268.5748513054;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_174) {
  double x = 99069.1748513054;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_175) {
  double x = -99369.55946669001;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_176) {
  double x = -0.55946669001;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_177) {
  double x = 0.55946669001;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_178) {
  double x = 124412512151251.99;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_179) {
  double x = -124412512151251.99;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_180) {
  double x = 1244125121512513.99;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_181) {
  double x = -1244125121512513.99;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_182) {
  double x = 2140971240971204712894128.99;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_183) {
  double x = -0.0;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_ceil_test_184) {
  double x = S21_MAX_DOUBLE;
  long double result = s21_ceil(x);
  long double expected = ceil(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

Suite *s21_ceil_test_suite(void) {
  Suite *suite = suite_create("s21_ceil");
  TCase *tcase_core = tcase_create("s21_ceil");
  tcase_add_test(tcase_core, s21_ceil_test_1);
  tcase_add_test(tcase_core, s21_ceil_test_2);
  tcase_add_test(tcase_core, s21_ceil_test_3);
  tcase_add_test(tcase_core, s21_ceil_test_4);
  tcase_add_test(tcase_core, s21_ceil_test_5);
  tcase_add_test(tcase_core, s21_ceil_test_6);
  tcase_add_test(tcase_core, s21_ceil_test_7);
  tcase_add_test(tcase_core, s21_ceil_test_8);
  tcase_add_test(tcase_core, s21_ceil_test_9);
  tcase_add_test(tcase_core, s21_ceil_test_10);
  tcase_add_test(tcase_core, s21_ceil_test_11);
  tcase_add_test(tcase_core, s21_ceil_test_12);
  tcase_add_test(tcase_core, s21_ceil_test_13);
  tcase_add_test(tcase_core, s21_ceil_test_14);
  tcase_add_test(tcase_core, s21_ceil_test_15);
  tcase_add_test(tcase_core, s21_ceil_test_16);
  tcase_add_test(tcase_core, s21_ceil_test_17);
  tcase_add_test(tcase_core, s21_ceil_test_18);
  tcase_add_test(tcase_core, s21_ceil_test_19);
  tcase_add_test(tcase_core, s21_ceil_test_20);
  tcase_add_test(tcase_core, s21_ceil_test_21);
  tcase_add_test(tcase_core, s21_ceil_test_22);
  tcase_add_test(tcase_core, s21_ceil_test_23);
  tcase_add_test(tcase_core, s21_ceil_test_24);
  tcase_add_test(tcase_core, s21_ceil_test_25);
  tcase_add_test(tcase_core, s21_ceil_test_26);
  tcase_add_test(tcase_core, s21_ceil_test_27);
  tcase_add_test(tcase_core, s21_ceil_test_28);
  tcase_add_test(tcase_core, s21_ceil_test_29);
  tcase_add_test(tcase_core, s21_ceil_test_30);
  tcase_add_test(tcase_core, s21_ceil_test_31);
  tcase_add_test(tcase_core, s21_ceil_test_32);
  tcase_add_test(tcase_core, s21_ceil_test_33);
  tcase_add_test(tcase_core, s21_ceil_test_34);
  tcase_add_test(tcase_core, s21_ceil_test_35);
  tcase_add_test(tcase_core, s21_ceil_test_36);
  tcase_add_test(tcase_core, s21_ceil_test_37);
  tcase_add_test(tcase_core, s21_ceil_test_38);
  tcase_add_test(tcase_core, s21_ceil_test_39);
  tcase_add_test(tcase_core, s21_ceil_test_40);
  tcase_add_test(tcase_core, s21_ceil_test_41);
  tcase_add_test(tcase_core, s21_ceil_test_42);
  tcase_add_test(tcase_core, s21_ceil_test_43);
  tcase_add_test(tcase_core, s21_ceil_test_44);
  tcase_add_test(tcase_core, s21_ceil_test_45);
  tcase_add_test(tcase_core, s21_ceil_test_46);
  tcase_add_test(tcase_core, s21_ceil_test_47);
  tcase_add_test(tcase_core, s21_ceil_test_48);
  tcase_add_test(tcase_core, s21_ceil_test_49);
  tcase_add_test(tcase_core, s21_ceil_test_50);
  tcase_add_test(tcase_core, s21_ceil_test_51);
  tcase_add_test(tcase_core, s21_ceil_test_52);
  tcase_add_test(tcase_core, s21_ceil_test_53);
  tcase_add_test(tcase_core, s21_ceil_test_54);
  tcase_add_test(tcase_core, s21_ceil_test_55);
  tcase_add_test(tcase_core, s21_ceil_test_56);
  tcase_add_test(tcase_core, s21_ceil_test_57);
  tcase_add_test(tcase_core, s21_ceil_test_58);
  tcase_add_test(tcase_core, s21_ceil_test_59);
  tcase_add_test(tcase_core, s21_ceil_test_60);
  tcase_add_test(tcase_core, s21_ceil_test_61);
  tcase_add_test(tcase_core, s21_ceil_test_62);
  tcase_add_test(tcase_core, s21_ceil_test_63);
  tcase_add_test(tcase_core, s21_ceil_test_64);
  tcase_add_test(tcase_core, s21_ceil_test_65);
  tcase_add_test(tcase_core, s21_ceil_test_66);
  tcase_add_test(tcase_core, s21_ceil_test_67);
  tcase_add_test(tcase_core, s21_ceil_test_68);
  tcase_add_test(tcase_core, s21_ceil_test_69);
  tcase_add_test(tcase_core, s21_ceil_test_70);
  tcase_add_test(tcase_core, s21_ceil_test_71);
  tcase_add_test(tcase_core, s21_ceil_test_72);
  tcase_add_test(tcase_core, s21_ceil_test_73);
  tcase_add_test(tcase_core, s21_ceil_test_74);
  tcase_add_test(tcase_core, s21_ceil_test_75);
  tcase_add_test(tcase_core, s21_ceil_test_76);
  tcase_add_test(tcase_core, s21_ceil_test_77);
  tcase_add_test(tcase_core, s21_ceil_test_78);
  tcase_add_test(tcase_core, s21_ceil_test_79);
  tcase_add_test(tcase_core, s21_ceil_test_80);
  tcase_add_test(tcase_core, s21_ceil_test_81);
  tcase_add_test(tcase_core, s21_ceil_test_82);
  tcase_add_test(tcase_core, s21_ceil_test_83);
  tcase_add_test(tcase_core, s21_ceil_test_84);
  tcase_add_test(tcase_core, s21_ceil_test_85);
  tcase_add_test(tcase_core, s21_ceil_test_86);
  tcase_add_test(tcase_core, s21_ceil_test_87);
  tcase_add_test(tcase_core, s21_ceil_test_88);
  tcase_add_test(tcase_core, s21_ceil_test_89);
  tcase_add_test(tcase_core, s21_ceil_test_90);
  tcase_add_test(tcase_core, s21_ceil_test_91);
  tcase_add_test(tcase_core, s21_ceil_test_92);
  tcase_add_test(tcase_core, s21_ceil_test_93);
  tcase_add_test(tcase_core, s21_ceil_test_94);
  tcase_add_test(tcase_core, s21_ceil_test_95);
  tcase_add_test(tcase_core, s21_ceil_test_96);
  tcase_add_test(tcase_core, s21_ceil_test_97);
  tcase_add_test(tcase_core, s21_ceil_test_98);
  tcase_add_test(tcase_core, s21_ceil_test_99);
  tcase_add_test(tcase_core, s21_ceil_test_100);
  tcase_add_test(tcase_core, s21_ceil_test_101);
  tcase_add_test(tcase_core, s21_ceil_test_102);
  tcase_add_test(tcase_core, s21_ceil_test_103);
  tcase_add_test(tcase_core, s21_ceil_test_104);
  tcase_add_test(tcase_core, s21_ceil_test_105);
  tcase_add_test(tcase_core, s21_ceil_test_106);
  tcase_add_test(tcase_core, s21_ceil_test_107);
  tcase_add_test(tcase_core, s21_ceil_test_108);
  tcase_add_test(tcase_core, s21_ceil_test_109);
  tcase_add_test(tcase_core, s21_ceil_test_110);
  tcase_add_test(tcase_core, s21_ceil_test_111);
  tcase_add_test(tcase_core, s21_ceil_test_112);
  tcase_add_test(tcase_core, s21_ceil_test_113);
  tcase_add_test(tcase_core, s21_ceil_test_114);
  tcase_add_test(tcase_core, s21_ceil_test_115);
  tcase_add_test(tcase_core, s21_ceil_test_116);
  tcase_add_test(tcase_core, s21_ceil_test_117);
  tcase_add_test(tcase_core, s21_ceil_test_118);
  tcase_add_test(tcase_core, s21_ceil_test_119);
  tcase_add_test(tcase_core, s21_ceil_test_120);
  tcase_add_test(tcase_core, s21_ceil_test_121);
  tcase_add_test(tcase_core, s21_ceil_test_122);
  tcase_add_test(tcase_core, s21_ceil_test_123);
  tcase_add_test(tcase_core, s21_ceil_test_124);
  tcase_add_test(tcase_core, s21_ceil_test_125);
  tcase_add_test(tcase_core, s21_ceil_test_126);
  tcase_add_test(tcase_core, s21_ceil_test_127);
  tcase_add_test(tcase_core, s21_ceil_test_128);
  tcase_add_test(tcase_core, s21_ceil_test_129);
  tcase_add_test(tcase_core, s21_ceil_test_130);
  tcase_add_test(tcase_core, s21_ceil_test_131);
  tcase_add_test(tcase_core, s21_ceil_test_132);
  tcase_add_test(tcase_core, s21_ceil_test_133);
  tcase_add_test(tcase_core, s21_ceil_test_134);
  tcase_add_test(tcase_core, s21_ceil_test_135);
  tcase_add_test(tcase_core, s21_ceil_test_136);
  tcase_add_test(tcase_core, s21_ceil_test_137);
  tcase_add_test(tcase_core, s21_ceil_test_138);
  tcase_add_test(tcase_core, s21_ceil_test_139);
  tcase_add_test(tcase_core, s21_ceil_test_140);
  tcase_add_test(tcase_core, s21_ceil_test_141);
  tcase_add_test(tcase_core, s21_ceil_test_142);
  tcase_add_test(tcase_core, s21_ceil_test_143);
  tcase_add_test(tcase_core, s21_ceil_test_144);
  tcase_add_test(tcase_core, s21_ceil_test_145);
  tcase_add_test(tcase_core, s21_ceil_test_146);
  tcase_add_test(tcase_core, s21_ceil_test_147);
  tcase_add_test(tcase_core, s21_ceil_test_148);
  tcase_add_test(tcase_core, s21_ceil_test_149);
  tcase_add_test(tcase_core, s21_ceil_test_150);
  tcase_add_test(tcase_core, s21_ceil_test_151);
  tcase_add_test(tcase_core, s21_ceil_test_152);
  tcase_add_test(tcase_core, s21_ceil_test_153);
  tcase_add_test(tcase_core, s21_ceil_test_154);
  tcase_add_test(tcase_core, s21_ceil_test_155);
  tcase_add_test(tcase_core, s21_ceil_test_156);
  tcase_add_test(tcase_core, s21_ceil_test_157);
  tcase_add_test(tcase_core, s21_ceil_test_158);
  tcase_add_test(tcase_core, s21_ceil_test_159);
  tcase_add_test(tcase_core, s21_ceil_test_160);
  tcase_add_test(tcase_core, s21_ceil_test_161);
  tcase_add_test(tcase_core, s21_ceil_test_162);
  tcase_add_test(tcase_core, s21_ceil_test_163);
  tcase_add_test(tcase_core, s21_ceil_test_164);
  tcase_add_test(tcase_core, s21_ceil_test_165);
  tcase_add_test(tcase_core, s21_ceil_test_166);
  tcase_add_test(tcase_core, s21_ceil_test_167);
  tcase_add_test(tcase_core, s21_ceil_test_168);
  tcase_add_test(tcase_core, s21_ceil_test_169);
  tcase_add_test(tcase_core, s21_ceil_test_170);
  tcase_add_test(tcase_core, s21_ceil_test_171);
  tcase_add_test(tcase_core, s21_ceil_test_172);
  tcase_add_test(tcase_core, s21_ceil_test_173);
  tcase_add_test(tcase_core, s21_ceil_test_174);
  tcase_add_test(tcase_core, s21_ceil_test_175);
  tcase_add_test(tcase_core, s21_ceil_test_176);
  tcase_add_test(tcase_core, s21_ceil_test_177);
  tcase_add_test(tcase_core, s21_ceil_test_178);
  tcase_add_test(tcase_core, s21_ceil_test_179);
  tcase_add_test(tcase_core, s21_ceil_test_180);
  tcase_add_test(tcase_core, s21_ceil_test_181);
  tcase_add_test(tcase_core, s21_ceil_test_182);
  tcase_add_test(tcase_core, s21_ceil_test_183);
  tcase_add_test(tcase_core, s21_ceil_test_184);

  suite_add_tcase(suite, tcase_core);
  return suite;
}