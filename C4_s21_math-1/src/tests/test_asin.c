#include "s21_test.h"

START_TEST(s21_asin_test_1) {
  ck_assert_ldouble_eq_tol(s21_asin(0.0), asin(0.0), 0.0000001);
}
END_TEST
START_TEST(s21_asin_test_2) {
  ck_assert_ldouble_eq_tol(s21_asin(1.0), asin(1.0), 0.0000001);
}
END_TEST
START_TEST(s21_asin_test_3) {
  ck_assert_ldouble_nan(s21_asin(S21_NAN));
  ck_assert_msg(isnan(s21_asin(S21_NAN)) == isnan(asin(NAN)),
                "func return value failed");
}
END_TEST
START_TEST(s21_asin_test_4) { ck_assert_ldouble_nan(s21_asin(S21_INF)); }
END_TEST
START_TEST(s21_asin_test_5) { ck_assert_ldouble_nan(s21_asin(-S21_INF)); }
END_TEST
START_TEST(s21_asin_test_6) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.5), asin(-0.5), 0.0000001);
}
END_TEST
START_TEST(s21_asin_test_7) {
  ck_assert_ldouble_eq_tol(s21_asin(0.809), asin(0.809), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_8) {
  ck_assert_ldouble_nan(s21_asin(1248246129586125.0));
}
END_TEST
START_TEST(s21_asin_test_9) {
  ck_assert_ldouble_eq_tol(s21_asin(0.00000000000000123),
                           asin(0.00000000000000123), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_10) { ck_assert_ldouble_eq(s21_asin(-1), asin(-1)); }
END_TEST

START_TEST(s21_asin_test_11) {
  ck_assert_ldouble_eq_tol(s21_asin(s21_sqrt(2) / 2), asin(sqrt(2) / 2),
                           0.0000001);
}
END_TEST

START_TEST(s21_asin_test_12) {
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_13) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.9887640449438202),
                           asin(-0.9887640449438202), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_14) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.945285784074255),
                           asin(-0.945285784074255), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_15) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.8976667364552073),
                           asin(-0.8976667364552073), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_16) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.8794849182733891),
                           asin(-0.8794849182733891), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_17) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.8649921646502008),
                           asin(-0.8649921646502008), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_18) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.8265306261886624),
                           asin(-0.8265306261886624), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_19) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.8076627016603605),
                           asin(-0.8076627016603605), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_20) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.7965515905492494),
                           asin(-0.7965515905492494), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_21) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.7489325429302018),
                           asin(-0.7489325429302018), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_22) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.7375689065665655),
                           asin(-0.7375689065665655), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_23) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.7226435334322371),
                           asin(-0.7226435334322371), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_24) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.7108788275498842),
                           asin(-0.7108788275498842), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_25) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.6988306347787998),
                           asin(-0.6988306347787998), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_26) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.6854973014454665),
                           asin(-0.6854973014454665), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_27) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.6521639681121332),
                           asin(-0.6521639681121332), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_28) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.6388306347787999),
                           asin(-0.6388306347787999), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_29) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.6221639681121331),
                           asin(-0.6221639681121331), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_30) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.603982149930315),
                           asin(-0.603982149930315), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_31) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.5875887073073641),
                           asin(-0.5875887073073641), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_32) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.5687207827790622),
                           asin(-0.5687207827790622), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_33) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.5430797571380366),
                           asin(-0.5430797571380366), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_34) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.5248979389562184),
                           asin(-0.5248979389562184), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_35) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.4772788913371708),
                           asin(-0.4772788913371708), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_36) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.46445837851665794),
                           asin(-0.46445837851665794), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_37) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.452693672634305),
                           asin(-0.452693672634305), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_38) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.40921541176473974),
                           asin(-0.40921541176473974), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_39) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.3758820784314064),
                           asin(-0.3758820784314064), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_40) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.33042753297686095),
                           asin(-0.33042753297686095), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_41) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.29196599451532246),
                           asin(-0.29196599451532246), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_42) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.246511449060777),
                           asin(-0.246511449060777), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_43) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.2276435245324751),
                           asin(-0.2276435245324751), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_44) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.1963935245324751),
                           asin(-0.1963935245324751), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_45) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.18357301171196228),
                           asin(-0.18357301171196228), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_46) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.15725722223827807),
                           asin(-0.15725722223827807), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_47) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.14317271519602454),
                           asin(-0.14317271519602454), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_48) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.12729969932300866),
                           asin(-0.12729969932300866), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_49) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.10457242659573593),
                           asin(-0.10457242659573593), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_50) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.08844339433767141),
                           asin(-0.08844339433767141), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_51) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.0773322832265603),
                           asin(-0.0773322832265603), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_52) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.06218076807504515),
                           asin(-0.06218076807504515), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_53) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.012180768075045145),
                           asin(-0.012180768075045145), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_54) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.00041606219269220424),
                           asin(-0.00041606219269220424), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_55) {
  ck_assert_ldouble_eq_tol(s21_asin(0.0395839378073078),
                           asin(0.0395839378073078), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_56) {
  ck_assert_ldouble_eq_tol(s21_asin(0.05428982016024897),
                           asin(0.05428982016024897), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_57) {
  ck_assert_ldouble_eq_tol(s21_asin(0.06694804800835023),
                           asin(0.06694804800835023), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_58) {
  ck_assert_ldouble_eq_tol(s21_asin(0.09920611252447926),
                           asin(0.09920611252447926), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_59) {
  ck_assert_ldouble_eq_tol(s21_asin(0.13920611252447926),
                           asin(0.13920611252447926), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_60) {
  ck_assert_ldouble_eq_tol(s21_asin(0.15615526506685215),
                           asin(0.15615526506685215), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_61) {
  ck_assert_ldouble_eq_tol(s21_asin(0.17502318959515403),
                           asin(0.17502318959515403), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_62) {
  ck_assert_ldouble_eq_tol(s21_asin(0.1962997853398349),
                           asin(0.1962997853398349), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_63) {
  ck_assert_ldouble_eq_tol(s21_asin(0.2107925389630233),
                           asin(0.2107925389630233), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_64) {
  ck_assert_ldouble_eq_tol(s21_asin(0.2283363986121461),
                           asin(0.2283363986121461), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_65) {
  ck_assert_ldouble_eq_tol(s21_asin(0.2505586208343683),
                           asin(0.2505586208343683), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_66) {
  ck_assert_ldouble_eq_tol(s21_asin(0.2652645031873095),
                           asin(0.2652645031873095), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_67) {
  ck_assert_ldouble_eq_tol(s21_asin(0.3128835508063571),
                           asin(0.3128835508063571), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_68) {
  ck_assert_ldouble_eq_tol(s21_asin(0.3255417786544584),
                           asin(0.3255417786544584), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_69) {
  ck_assert_ldouble_eq_tol(s21_asin(0.3482690513817311),
                           asin(0.3482690513817311), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_70) {
  ck_assert_ldouble_eq_tol(s21_asin(0.35963268774536744),
                           asin(0.35963268774536744), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_71) {
  ck_assert_ldouble_eq_tol(s21_asin(0.39534697345965314),
                           asin(0.39534697345965314), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_72) {
  ck_assert_ldouble_eq_tol(s21_asin(0.40983972708284155),
                           asin(0.40983972708284155), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_73) {
  ck_assert_ldouble_eq_tol(s21_asin(0.42107568213902136),
                           asin(0.42107568213902136), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_74) {
  ck_assert_ldouble_eq_tol(s21_asin(0.44281481257380395),
                           asin(0.44281481257380395), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_75) {
  ck_assert_ldouble_eq_tol(s21_asin(0.46913060204748813),
                           asin(0.46913060204748813), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_76) {
  ck_assert_ldouble_eq_tol(s21_asin(0.4817888298955894),
                           asin(0.4817888298955894), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_77) {
  ck_assert_ldouble_eq_tol(s21_asin(0.5217888298955894),
                           asin(0.5217888298955894), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_78) {
  ck_assert_ldouble_eq_tol(s21_asin(0.5354874600325756),
                           asin(0.5354874600325756), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_79) {
  ck_assert_ldouble_eq_tol(s21_asin(0.550412833166904), asin(0.550412833166904),
                           0.0000001);
}
END_TEST

START_TEST(s21_asin_test_80) {
  ck_assert_ldouble_eq_tol(s21_asin(0.5696436023976733),
                           asin(0.5696436023976733), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_81) {
  ck_assert_ldouble_eq_tol(s21_asin(0.5881621209161918),
                           asin(0.5881621209161918), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_82) {
  ck_assert_ldouble_eq_tol(s21_asin(0.6357811685352395),
                           asin(0.6357811685352395), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_83) {
  ck_assert_ldouble_eq_tol(s21_asin(0.654299687053758), asin(0.654299687053758),
                           0.0000001);
}
END_TEST

START_TEST(s21_asin_test_84) {
  ck_assert_ldouble_eq_tol(s21_asin(0.6662044489585198),
                           asin(0.6662044489585198), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_85) {
  ck_assert_ldouble_eq_tol(s21_asin(0.6884266711807421),
                           asin(0.6884266711807421), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_86) {
  ck_assert_ldouble_eq_tol(s21_asin(0.7268882096422805),
                           asin(0.7268882096422805), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_87) {
  ck_assert_ldouble_eq_tol(s21_asin(0.7477215429756139),
                           asin(0.7477215429756139), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_88) {
  ck_assert_ldouble_eq_tol(s21_asin(0.7740373324492981),
                           asin(0.7740373324492981), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_89) {
  ck_assert_ldouble_eq_tol(s21_asin(0.8194918779038435),
                           asin(0.8194918779038435), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_90) {
  ck_assert_ldouble_eq_tol(s21_asin(0.8312565837861964),
                           asin(0.8312565837861964), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_91) {
  ck_assert_ldouble_eq_tol(s21_asin(0.8635146483023254),
                           asin(0.8635146483023254), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_92) {
  ck_assert_ldouble_eq_tol(s21_asin(0.8879048922047644),
                           asin(0.8879048922047644), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_93) {
  ck_assert_ldouble_eq_tol(s21_asin(0.9129048922047645),
                           asin(0.9129048922047645), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_94) {
  ck_assert_ldouble_eq_tol(s21_asin(0.9399319192317914),
                           asin(0.9399319192317914), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_95) {
  ck_assert_ldouble_eq_tol(s21_asin(0.9607652525651248),
                           asin(0.9607652525651248), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_96) {
  ck_assert_ldouble_eq_tol(s21_asin(0.972259505438688), asin(0.972259505438688),
                           0.0000001);
}
END_TEST

START_TEST(s21_asin_test_97) {
  ck_assert_ldouble_eq_tol(s21_asin(0.9857730189522015),
                           asin(0.9857730189522015), 0.0000001);
}
END_TEST

START_TEST(s21_asin_test_98) {
  ck_assert_ldouble_eq_tol(s21_asin(0.999286532465715), asin(0.999286532465715),
                           0.0000001);
}
END_TEST
START_TEST(s21_asin_test_99) {
  ck_assert_ldouble_nan(s21_asin(S21_MAX_DOUBLE));
}
END_TEST
START_TEST(s21_asin_test_100) {
  ck_assert_ldouble_eq_tol(s21_asin(S21_MIN_DOUBLE), asin(S21_MIN_DOUBLE),
                           0.0000001);
}
END_TEST
START_TEST(s21_asin_test_101) {
  ck_assert_ldouble_eq_tol(s21_asin(-1.0), asin(-1.0), 0.0000001);
}
END_TEST

Suite *s21_asin_test_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_asin_test_suite");
  tc = tcase_create("s21_asin_test_suite");
  tcase_add_test(tc, s21_asin_test_1);
  tcase_add_test(tc, s21_asin_test_2);
  tcase_add_test(tc, s21_asin_test_3);
  tcase_add_test(tc, s21_asin_test_4);
  tcase_add_test(tc, s21_asin_test_5);
  tcase_add_test(tc, s21_asin_test_6);
  tcase_add_test(tc, s21_asin_test_7);
  tcase_add_test(tc, s21_asin_test_8);
  tcase_add_test(tc, s21_asin_test_9);
  tcase_add_test(tc, s21_asin_test_10);
  tcase_add_test(tc, s21_asin_test_11);
  tcase_add_test(tc, s21_asin_test_12);
  tcase_add_test(tc, s21_asin_test_13);
  tcase_add_test(tc, s21_asin_test_14);
  tcase_add_test(tc, s21_asin_test_15);
  tcase_add_test(tc, s21_asin_test_16);
  tcase_add_test(tc, s21_asin_test_17);
  tcase_add_test(tc, s21_asin_test_18);
  tcase_add_test(tc, s21_asin_test_19);
  tcase_add_test(tc, s21_asin_test_20);
  tcase_add_test(tc, s21_asin_test_21);
  tcase_add_test(tc, s21_asin_test_22);
  tcase_add_test(tc, s21_asin_test_23);
  tcase_add_test(tc, s21_asin_test_24);
  tcase_add_test(tc, s21_asin_test_25);
  tcase_add_test(tc, s21_asin_test_26);
  tcase_add_test(tc, s21_asin_test_27);
  tcase_add_test(tc, s21_asin_test_28);
  tcase_add_test(tc, s21_asin_test_29);
  tcase_add_test(tc, s21_asin_test_30);
  tcase_add_test(tc, s21_asin_test_31);
  tcase_add_test(tc, s21_asin_test_32);
  tcase_add_test(tc, s21_asin_test_33);
  tcase_add_test(tc, s21_asin_test_34);
  tcase_add_test(tc, s21_asin_test_35);
  tcase_add_test(tc, s21_asin_test_36);
  tcase_add_test(tc, s21_asin_test_37);
  tcase_add_test(tc, s21_asin_test_38);
  tcase_add_test(tc, s21_asin_test_39);
  tcase_add_test(tc, s21_asin_test_40);
  tcase_add_test(tc, s21_asin_test_41);
  tcase_add_test(tc, s21_asin_test_42);
  tcase_add_test(tc, s21_asin_test_43);
  tcase_add_test(tc, s21_asin_test_44);
  tcase_add_test(tc, s21_asin_test_45);
  tcase_add_test(tc, s21_asin_test_46);
  tcase_add_test(tc, s21_asin_test_47);
  tcase_add_test(tc, s21_asin_test_48);
  tcase_add_test(tc, s21_asin_test_49);
  tcase_add_test(tc, s21_asin_test_50);
  tcase_add_test(tc, s21_asin_test_51);
  tcase_add_test(tc, s21_asin_test_52);
  tcase_add_test(tc, s21_asin_test_53);
  tcase_add_test(tc, s21_asin_test_54);
  tcase_add_test(tc, s21_asin_test_55);
  tcase_add_test(tc, s21_asin_test_56);
  tcase_add_test(tc, s21_asin_test_57);
  tcase_add_test(tc, s21_asin_test_58);
  tcase_add_test(tc, s21_asin_test_59);
  tcase_add_test(tc, s21_asin_test_60);
  tcase_add_test(tc, s21_asin_test_61);
  tcase_add_test(tc, s21_asin_test_62);
  tcase_add_test(tc, s21_asin_test_63);
  tcase_add_test(tc, s21_asin_test_64);
  tcase_add_test(tc, s21_asin_test_65);
  tcase_add_test(tc, s21_asin_test_66);
  tcase_add_test(tc, s21_asin_test_67);
  tcase_add_test(tc, s21_asin_test_68);
  tcase_add_test(tc, s21_asin_test_69);
  tcase_add_test(tc, s21_asin_test_70);
  tcase_add_test(tc, s21_asin_test_71);
  tcase_add_test(tc, s21_asin_test_72);
  tcase_add_test(tc, s21_asin_test_73);
  tcase_add_test(tc, s21_asin_test_74);
  tcase_add_test(tc, s21_asin_test_75);
  tcase_add_test(tc, s21_asin_test_76);
  tcase_add_test(tc, s21_asin_test_77);
  tcase_add_test(tc, s21_asin_test_78);
  tcase_add_test(tc, s21_asin_test_79);
  tcase_add_test(tc, s21_asin_test_80);
  tcase_add_test(tc, s21_asin_test_81);
  tcase_add_test(tc, s21_asin_test_82);
  tcase_add_test(tc, s21_asin_test_83);
  tcase_add_test(tc, s21_asin_test_84);
  tcase_add_test(tc, s21_asin_test_85);
  tcase_add_test(tc, s21_asin_test_86);
  tcase_add_test(tc, s21_asin_test_87);
  tcase_add_test(tc, s21_asin_test_88);
  tcase_add_test(tc, s21_asin_test_89);
  tcase_add_test(tc, s21_asin_test_90);
  tcase_add_test(tc, s21_asin_test_91);
  tcase_add_test(tc, s21_asin_test_92);
  tcase_add_test(tc, s21_asin_test_93);
  tcase_add_test(tc, s21_asin_test_94);
  tcase_add_test(tc, s21_asin_test_95);
  tcase_add_test(tc, s21_asin_test_96);
  tcase_add_test(tc, s21_asin_test_97);
  tcase_add_test(tc, s21_asin_test_98);
  tcase_add_test(tc, s21_asin_test_99);
  tcase_add_test(tc, s21_asin_test_100);
  tcase_add_test(tc, s21_asin_test_101);

  suite_add_tcase(s, tc);
  return s;
}
