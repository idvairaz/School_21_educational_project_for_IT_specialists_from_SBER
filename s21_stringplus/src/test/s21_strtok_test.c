#include "../s21_string.h"
#include "test.h"

START_TEST(test_s21_strtok_1) {
  char str1[] = "This is - www.tutorialspoint.com - website?";
  const char delim[] = "-";
  char* result = s21_strtok(str1, delim);
  char* expected = strtok(str1, delim);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strtok_2) {
  char str[] = "This is - www.tutorialspoint.com - website?";
  const char delim[] = "?";
  char* result = s21_strtok(str, delim);
  char* expected = strtok(str, delim);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strtok_3) {
  char str1[] = "This is - www.tutorialspoint.com - website?";
  const char delim[] = "&";
  char* result = s21_strtok(str1, delim);
  char* expected = strtok(str1, delim);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strtok_4) {
  char str1[] = "This is - www.tutorialspoint.com - website?";
  const char delim[] = "-";
  char* result = s21_strtok(str1, delim);
  char* expected = strtok(str1, delim);
  while (expected != NULL && result != NULL) {
    ck_assert_ptr_eq(result, expected);
    expected = strtok(NULL, delim);
    result = s21_strtok(NULL, delim);
  }
}
END_TEST

START_TEST(test_s21_strtok_5) {
  char str1[] = "Hello, World! How are you?";
  const char delim[] = ",!?";
  char* result = s21_strtok(str1, delim);
  char* expected = strtok(str1, delim);
  while (expected != NULL && result != NULL) {
    ck_assert_ptr_eq(result, expected);
    expected = strtok(NULL, delim);
    result = s21_strtok(NULL, delim);
  }
}
END_TEST

START_TEST(test_s21_strtok_6) {
  char str1[] = "Aboba++Floppa_! Kotya====!Shleppa";
  char str2[] = "Aboba++Floppa_! Kotya====!Shleppa";
  const char delims[] = "+_! =";

  char* result = s21_strtok(str1, delims);
  char* expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(result), s21_strlen(expected));
  ck_assert_str_eq(result, expected);

  while (expected != NULL && result != NULL) {
    result = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);
    if (expected != NULL && result != NULL) {
      ck_assert_uint_eq(s21_strlen(result), s21_strlen(expected));
      ck_assert_str_eq(result, expected);
    } else {
      ck_assert_ptr_null(result);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_7) {
  char str1[] = "++Aboba++Floppa_! Kotya===!Shleppa+++ A +";
  char str2[] = "++Aboba++Floppa_! Kotya===!Shleppa+++ A +";
  const char delims[] = "+_! =";

  char* result = s21_strtok(str1, delims);
  char* expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(result), s21_strlen(expected));
  ck_assert_str_eq(result, expected);

  while (expected != NULL && result != NULL) {
    result = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);
    if (expected != NULL && result != NULL) {
      ck_assert_uint_eq(s21_strlen(result), s21_strlen(expected));
      ck_assert_str_eq(result, expected);
    } else {
      ck_assert_ptr_null(result);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_8) {
  char str1[] = "Aboba+Anuroba_Floppa!Kotya_Kekus";
  char str2[] = "Aboba+Anuroba_Floppa!Kotya_Kekus";
  const char delims[] = "+_! =";

  char* result = s21_strtok(str1, delims);
  char* expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(result), s21_strlen(expected));
  ck_assert_str_eq(result, expected);

  while (expected != NULL && result != NULL) {
    result = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);
    if (expected != NULL && result != NULL) {
      ck_assert_uint_eq(s21_strlen(result), s21_strlen(expected));
      ck_assert_str_eq(result, expected);
    } else {
      ck_assert_ptr_null(result);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_9) {
  char str1[] = "AbobaHasNoDelims";
  char str2[] = "AbobaHasNoDelims";
  const char delims[] = "+_! =";

  char* result = s21_strtok(str1, delims);
  char* expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(result), s21_strlen(expected));
  ck_assert_str_eq(result, expected);

  while (expected != NULL && result != NULL) {
    result = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);
    if (expected != NULL && result != NULL) {
      ck_assert_uint_eq(s21_strlen(result), s21_strlen(expected));
      ck_assert_str_eq(result, expected);
    } else {
      ck_assert_ptr_null(result);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_10) {
  char str1[] = "++++++++";
  char str2[] = "++++++++";
  const char delims[] = "+_! =";

  char* result = s21_strtok(str1, delims);
  char* expected = strtok(str2, delims);

  ck_assert_ptr_null(result);
  ck_assert_ptr_null(expected);
}
END_TEST

START_TEST(test_s21_strtok_11) {
  char str1[] = "AbobaHasNoDelims";
  char str2[] = "AbobaHasNoDelims";
  const char delims[] = "+_! =";

  char* result = s21_strtok(str1, delims);
  char* expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(result), s21_strlen(expected));
  ck_assert_str_eq(result, expected);

  while (expected != NULL && result != NULL) {
    result = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);
    if (expected != NULL && result != NULL) {
      ck_assert_uint_eq(s21_strlen(result), s21_strlen(expected));
      ck_assert_str_eq(result, expected);
    } else {
      ck_assert_ptr_null(result);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_12) {
  char str1[] = "Roba++++Kepa++A++++B__V";
  char str2[] = "Roba++++Kepa++A++++B__V";
  const char delims[] = "+_! =";

  char* result = s21_strtok(str1, delims);
  char* expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(result), s21_strlen(expected));
  ck_assert_str_eq(result, expected);

  while (expected != NULL && result != NULL) {
    result = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);
    if (expected != NULL && result != NULL) {
      ck_assert_uint_eq(s21_strlen(result), s21_strlen(expected));
      ck_assert_str_eq(result, expected);
    } else {
      ck_assert_ptr_null(result);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_13) {
  char str1[] = "Aboba__+Floppa_  Roba";
  char str2[] = "Aboba__+Floppa_  Roba";
  const char delims[] = "+_! =";

  char* result = s21_strtok(str1, delims);
  char* expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(result), s21_strlen(expected));
  ck_assert_str_eq(result, expected);

  while (expected != NULL && result != NULL) {
    result = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);
    if (expected != NULL && result != NULL) {
      ck_assert_uint_eq(s21_strlen(result), s21_strlen(expected));
      ck_assert_str_eq(result, expected);
    } else {
      ck_assert_ptr_null(result);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_14) {
  char str1[] = "Aboba__Floppa_+++Roba_Kepa";
  char str2[] = "Aboba__Floppa_+++Roba_Kepa";
  const char delims[] = "+_! =";

  char* result = s21_strtok(str1, delims);
  char* expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(result), s21_strlen(expected));
  ck_assert_str_eq(result, expected);

  while (expected != NULL && result != NULL) {
    result = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);
    if (expected != NULL && result != NULL) {
      ck_assert_uint_eq(s21_strlen(result), s21_strlen(expected));
      ck_assert_str_eq(result, expected);
    } else {
      ck_assert_ptr_null(result);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_15) {
  char str1[] = "     Aboba__+ Flo!ppa_   Roba+";
  char str2[] = "     Aboba__+ Flo!ppa_   Roba+";
  const char delims[] = "+_! =";

  char* result = s21_strtok(str1, delims);
  char* expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(result), s21_strlen(expected));
  ck_assert_str_eq(result, expected);

  while (expected != NULL && result != NULL) {
    result = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);
    if (expected != NULL && result != NULL) {
      ck_assert_uint_eq(s21_strlen(result), s21_strlen(expected));
      ck_assert_str_eq(result, expected);
    } else {
      ck_assert_ptr_null(result);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_16) {
  char str1[] = "!Stepa__ !M!ish a____Anton+An!!!drey";
  char str2[] = "!Stepa__ !M!ish a____Anton+An!!!drey";
  const char delims[] = "+_! =";

  char* result = s21_strtok(str1, delims);
  char* expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(result), s21_strlen(expected));
  ck_assert_str_eq(result, expected);

  while (expected != NULL && result != NULL) {
    result = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);
    if (expected != NULL && result != NULL) {
      ck_assert_uint_eq(s21_strlen(result), s21_strlen(expected));
      ck_assert_str_eq(result, expected);
    } else {
      ck_assert_ptr_null(result);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_17) {
  char str1[] = "!       A!B!C!D!E!!F!!G";
  char str2[] = "!       A!B!C!D!E!!F!!G";
  const char delims[] = "+_! =";

  char* result = s21_strtok(str1, delims);
  char* expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(result), s21_strlen(expected));
  ck_assert_str_eq(result, expected);

  while (expected != NULL && result != NULL) {
    result = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);
    if (expected != NULL && result != NULL) {
      ck_assert_uint_eq(s21_strlen(result), s21_strlen(expected));
      ck_assert_str_eq(result, expected);
    } else {
      ck_assert_ptr_null(result);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_18) {
  char str1[] = "AbobaHasNoDelims";
  char str2[] = "AbobaHasNoDelims";
  const char delims[] = "$";

  char* result = s21_strtok(str1, delims);
  char* expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(result), s21_strlen(expected));
  ck_assert_str_eq(result, expected);

  while (expected != NULL && result != NULL) {
    result = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);
    if (expected != NULL && result != NULL) {
      ck_assert_uint_eq(s21_strlen(result), s21_strlen(expected));
      ck_assert_str_eq(result, expected);
    } else {
      ck_assert_ptr_null(result);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_19) {
  char str1[] = "";
  char str2[] = "";
  const char delim[] = "&";
  char* result = s21_strtok(str1, delim);
  char* expected = strtok(str2, delim);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

Suite* s21_strtok_suite(void) {
  Suite* suite = suite_create("s21_strtok");
  TCase* tcase_core = tcase_create("s21_strtok");
  tcase_add_test(tcase_core, test_s21_strtok_1);
  tcase_add_test(tcase_core, test_s21_strtok_2);
  tcase_add_test(tcase_core, test_s21_strtok_3);
  tcase_add_test(tcase_core, test_s21_strtok_4);
  tcase_add_test(tcase_core, test_s21_strtok_5);
  tcase_add_test(tcase_core, test_s21_strtok_6);
  tcase_add_test(tcase_core, test_s21_strtok_7);
  tcase_add_test(tcase_core, test_s21_strtok_8);
  tcase_add_test(tcase_core, test_s21_strtok_9);
  tcase_add_test(tcase_core, test_s21_strtok_10);
  tcase_add_test(tcase_core, test_s21_strtok_11);
  tcase_add_test(tcase_core, test_s21_strtok_12);
  tcase_add_test(tcase_core, test_s21_strtok_13);
  tcase_add_test(tcase_core, test_s21_strtok_14);
  tcase_add_test(tcase_core, test_s21_strtok_15);
  tcase_add_test(tcase_core, test_s21_strtok_16);
  tcase_add_test(tcase_core, test_s21_strtok_17);
  tcase_add_test(tcase_core, test_s21_strtok_18);
  tcase_add_test(tcase_core, test_s21_strtok_19);

  suite_add_tcase(suite, tcase_core);
  return suite;
}