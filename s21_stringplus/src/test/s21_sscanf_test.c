#include "../s21_string.h"
#include "test.h"

///// char "c" /////
START_TEST(ch) {
  char c1_std = 0, c2_std = 0, c3_std = 0;
  char c1_s21 = 0, c2_s21 = 0, c3_s21 = 0;

  const char* str = "abc def ghi";
  const char* format = "%c%c%c";

  int int_std = sscanf(str, format, &c1_std, &c2_std, &c3_std);
  int int_s21 = s21_sscanf(str, format, &c1_s21, &c2_s21, &c3_s21);

  ck_assert_int_eq(c1_std, c1_s21);
  ck_assert_int_eq(c2_std, c2_s21);
  ck_assert_int_eq(c3_std, c3_s21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(ch_1) {
  char c1_std[3] = {'\0', '\0', '\0'};
  char c1_s21[3] = {'\0', '\0', '\0'};

  const char* str = "abc def ghi";
  const char* format = "%2c";

  int int_std = sscanf(str, format, c1_std);
  int int_s21 = s21_sscanf(str, format, c1_s21);

  ck_assert_str_eq(c1_std, c1_s21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(ch_2) {
  char c1_std = 0;
  char c1_s21 = 0;

  const char* str = " ";
  const char* format = "%c";

  int int_std = sscanf(str, format, &c1_std);
  int int_s21 = s21_sscanf(str, format, &c1_s21);

  ck_assert_int_eq(c1_std, c1_s21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(ch_3) {
  char c1_std = 0;
  char c1_s21 = 0;

  const char* str = "\t";
  const char* format = "%c";

  int int_std = sscanf(str, format, &c1_std);
  int int_s21 = s21_sscanf(str, format, &c1_s21);

  ck_assert_int_eq(c1_std, c1_s21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(ch_4) {
  char c1_std = 0;
  char c1_s21 = 0;

  const char* str = " \t\ng";
  const char* format = " %c";

  int int_std = sscanf(str, format, &c1_std);
  int int_s21 = s21_sscanf(str, format, &c1_s21);

  ck_assert_int_eq(c1_std, c1_s21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(ch_5) {
  char c1_std = 0, c2_std = 0;
  char c1_s21 = 0, c2_s21 = 0;

  const char* str = " \t\ng q";
  const char* format = " %c %c";

  int int_std = sscanf(str, format, &c1_std, &c2_std);
  int int_s21 = s21_sscanf(str, format, &c1_s21, &c2_s21);

  ck_assert_int_eq(c1_std, c1_s21);
  ck_assert_int_eq(c2_std, c2_s21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(ch_6) {
  char c1_std = 0, c2_std = 0, c3_std = 0;
  char c1_s21 = 0, c2_s21 = 0, c3_s21 = 0;

  const char* str = "ab";
  const char* format = "%c%c%c";

  int int_std = sscanf(str, format, &c1_std, &c2_std, &c3_std);
  int int_s21 = s21_sscanf(str, format, &c1_s21, &c2_s21, &c3_s21);

  ck_assert_int_eq(c1_std, c1_s21);
  ck_assert_int_eq(c2_std, c2_s21);
  ck_assert_int_eq(c3_std, c3_s21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(ch_7) {
  char c1_std[6] = {'\0', '\0', '\0', '\0', '\0', '\0'};
  char c1_s21[6] = {'\0', '\0', '\0', '\0', '\0', '\0'};
  int d2_std = 0;
  int d2_s21 = 0;

  const char* str = "hello 123";
  const char* format = "%5c%2d";

  int int_std = sscanf(str, format, c1_std, &d2_std);
  int int_s21 = s21_sscanf(str, format, c1_s21, &d2_s21);

  ck_assert_str_eq(c1_std, c1_s21);
  ck_assert_int_eq(d2_std, d2_s21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(ch_8) {
  char c1_std = 0, c2_std = 0;
  char c1_s21 = 0, c2_s21 = 0;

  const char* str = "hello Verter";
  const char* format = "%0c%c";

  int int_std = sscanf(str, format, &c1_std, &c2_std);
  int int_s21 = s21_sscanf(str, format, &c1_s21, &c2_s21);

  ck_assert_int_eq(c1_std, c1_s21);
  ck_assert_int_eq(c2_std, c2_s21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(ch_9) {
  char c1_std = 0;
  char c1_s21 = 0;

  const char* str = "hello Verter";
  const char* format = "%*c%c";

  int int_std = sscanf(str, format, &c1_std);
  int int_s21 = s21_sscanf(str, format, &c1_s21);

  ck_assert_int_eq(c1_std, c1_s21);

  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(ch_10) {
  char c1_std[6] = {'\0', '\0', '\0', '\0', '\0', '\0'};
  char c1_s21[6] = {'\0', '\0', '\0', '\0', '\0', '\0'};

  const char* str = "hello";
  const char* format = "%3c";

  int int_std = sscanf(str, format, c1_std);
  int int_s21 = s21_sscanf(str, format, c1_s21);

  ck_assert_str_eq(c1_std, c1_s21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(ch_11) {
  wchar_t c1_std = L'0';
  wchar_t c1_s21 = L'0';

  const char* str = "hello";
  const char* format = "%lc";

  int int_std = sscanf(str, format, &c1_std);
  int int_s21 = s21_sscanf(str, format, &c1_s21);

  ck_assert_int_eq(c1_std, c1_s21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(ch_12) {
  wchar_t c1_std = L'0';
  wchar_t c1_s21 = L'0';

  const char* str = "123245";
  const char* format = "%lc";

  int int_std = sscanf(str, format, &c1_std);
  int int_s21 = s21_sscanf(str, format, &c1_s21);

  ck_assert_int_eq(c1_std, c1_s21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
///// END CHAR /////

///// START % PERCENT  /////
// %% "%"
START_TEST(symbol_percent) {
  const char str[50] = "%%testString";
  const char format[] = "%%";
  int int_std = sscanf(str, format);
  int int_s21 = s21_sscanf(str, format);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(symbol_percent_1) {
  const char str[50] = "testString";
  const char format[] = "%c%%";
  char c1 = '\0';
  char c2 = '\0';
  int int_std = sscanf(str, format, &c1);
  int int_s21 = s21_sscanf(str, format, &c2);

  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(symbol_percent_2) {
  const char str[50] = "testString";
  char c1[30] = {'\0'};
  char c2[30] = {'\0'};
  const char format[] = "%s%%";
  int int_std = sscanf(str, format, c1);
  int int_s21 = s21_sscanf(str, format, c2);
  ck_assert_str_eq(c1, c2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(symbol_percent_3) {
  const char str[50] = "%% testString";
  char c1 = '\0';
  char c2 = '\0';
  const char format[] = "%%%% %c";
  int int_std = sscanf(str, format, &c1);
  int int_s21 = s21_sscanf(str, format, &c2);

  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(symbol_percent_4) {
  const char str[50] = "%% testString";
  char c1[30] = {'\0'};
  char c2[30] = {'\0'};
  const char format[] = "%%%%%s";
  int int_std = sscanf(str, format, c1);
  int int_s21 = s21_sscanf(str, format, c2);
  ck_assert_str_eq(c1, c2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(symbol_percent_5) {
  const char str[50] = "%% testString % 123";
  char c1[30] = {'\0'};
  char c2[30] = {'\0'};
  int n1 = -2, n2 = -2;
  const char format[] = "%%%%%s %% %d";
  int int_std = sscanf(str, format, c1, &n1);
  int int_s21 = s21_sscanf(str, format, c2, &n2);
  ck_assert_str_eq(c1, c2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
///// END % PERCENT /////

///// START S STRING /////
// string "s"
START_TEST(string) {
  char str_std[30] = {'\0'};
  char str_s21[30] = {'\0'};
  const char* str = "abcdefgh";
  const char format[] = "%s";
  int int_std = sscanf(str, format, str_std);
  int int_s21 = s21_sscanf(str, format, str_s21);
  ck_assert_str_eq(str_std, str_s21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(string_1) {
  char str_std[30] = {'\0'};
  char str_s21[30] = {'\0'};
  const char* str = "     abcdefgh";
  const char format[] = "%s";
  int int_std = sscanf(str, format, str_std);
  int int_s21 = s21_sscanf(str, format, str_s21);
  ck_assert_str_eq(str_std, str_s21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(string_2) {
  char str_std[30] = {'\0'};
  char str_s21[30] = {'\0'};
  const char* str = "\tabcdefgh";
  const char format[] = "%s";
  int int_std = sscanf(str, format, str_std);
  int int_s21 = s21_sscanf(str, format, str_s21);
  ck_assert_str_eq(str_std, str_s21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(string_3) {
  char str_std[30] = {'\0'};
  char str_s21[30] = {'\0'};
  const char* str = "\nabcdefgh";
  const char format[] = "%s";
  int int_std = sscanf(str, format, str_std);
  int int_s21 = s21_sscanf(str, format, str_s21);
  ck_assert_str_eq(str_std, str_s21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(string_4) {
  char str_std[30] = {'\0'};
  char str_s21[30] = {'\0'};
  const char* str = "      \v\n\tabcdefgh";
  const char format[] = "%s";
  int int_std = sscanf(str, format, str_std);
  int int_s21 = s21_sscanf(str, format, str_s21);
  ck_assert_str_eq(str_std, str_s21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(string_5) {
  char str_std[30] = {'\0'};
  char str_s21[30] = {'\0'};
  const char* str = "      \n\tabcdefgh\n\t";
  const char format[] = " %s";
  int int_std = sscanf(str, format, str_std);
  int int_s21 = s21_sscanf(str, format, str_s21);
  ck_assert_str_eq(str_std, str_s21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(string_6) {
  char str_std[30] = {'\0'};
  char str_s21[30] = {'\0'};
  const char* str = "      \n\tabc\0defgh";
  const char format[] = "%s";
  int int_std = sscanf(str, format, str_std);
  int int_s21 = s21_sscanf(str, format, str_s21);
  ck_assert_str_eq(str_std, str_s21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(string_7) {
  char str_std[30] = {'\0'};
  char str_s21[30] = {'\0'};
  const char* str = "abcd\nefgh";
  const char format[] = "%s";
  int int_std = sscanf(str, format, str_std);
  int int_s21 = s21_sscanf(str, format, str_s21);
  ck_assert_str_eq(str_std, str_s21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(string_8) {
  char str_std[30] = {'\0'};
  char str_s21[30] = {'\0'};
  const char* str = "abcd e f g h";
  const char format[] = "%s";
  int int_std = sscanf(str, format, str_std);
  int int_s21 = s21_sscanf(str, format, str_s21);
  ck_assert_str_eq(str_std, str_s21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(string_9) {
  char str_std[30] = {'\0'};
  char str_s21[30] = {'\0'};
  const char* str = "     abcd e f g h";
  const char format[] = "%s";
  int int_std = sscanf(str, format, str_std);
  int int_s21 = s21_sscanf(str, format, str_s21);
  ck_assert_str_eq(str_std, str_s21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(string_10) {
  char str_std[30] = {'\0'};
  char str_s21[30] = {'\0'};
  const char* str = "     abc\0d e f g h";
  const char format[] = "%s";
  int int_std = sscanf(str, format, str_std);
  int int_s21 = s21_sscanf(str, format, str_s21);
  ck_assert_str_eq(str_std, str_s21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(string_11) {
  char str_std[30] = {'\0'};
  char str_s21[30] = {'\0'};
  const char* str = "a b c d e f g h";
  const char format[] = "%s";
  int int_std = sscanf(str, format, str_std);
  int int_s21 = s21_sscanf(str, format, str_s21);
  ck_assert_str_eq(str_std, str_s21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(string_12) {
  char str_std[30] = {'\0'};
  char str_s21[30] = {'\0'};
  const char* str = "abcdefgh123456789";
  const char format[] = "%s";
  int int_std = sscanf(str, format, str_std);
  int int_s21 = s21_sscanf(str, format, str_s21);
  ck_assert_str_eq(str_std, str_s21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(string_13) {
  char str_std[30] = {'\0'};
  char str_s21[30] = {'\0'};
  const char* str = "";
  const char format[] = "%s";
  int int_std = sscanf(str, format, str_std);
  int int_s21 = s21_sscanf(str, format, str_s21);
  ck_assert_str_eq(str_std, str_s21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(string_14) {
  char str_std[30] = {'\0'};
  char str_s21[30] = {'\0'};
  const char* str = "\0";
  const char format[] = "%s";
  int int_std = sscanf(str, format, str_std);
  int int_s21 = s21_sscanf(str, format, str_s21);
  ck_assert_str_eq(str_std, str_s21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(string_15) {
  char str_std[30] = {'\0'};
  char str_s21[30] = {'\0'};
  const char* str = "\v\t\r\n\f ";
  const char format[] = "%s";
  int int_std = sscanf(str, format, str_std);
  int int_s21 = s21_sscanf(str, format, str_s21);
  ck_assert_str_eq(str_std, str_s21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(string_16) {
  char str_std[30] = {'\0'};
  char str_s21[30] = {'\0'};
  const char* str = "Verter";
  const char format[] = "%4s";
  int int_std = sscanf(str, format, str_std);
  int int_s21 = s21_sscanf(str, format, str_s21);
  ck_assert_str_eq(str_std, str_s21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(string_17) {
  char str_std[30] = {'\0'};
  char str_std_2[30] = {'\0'};
  char str_s21[30] = {'\0'};
  char str_s21_2[30] = {'\0'};
  const char* str = "hello Verter";
  const char format[] = "%s%s";
  int int_std = sscanf(str, format, str_std, str_std_2);
  int int_s21 = s21_sscanf(str, format, str_s21, str_s21_2);
  ck_assert_str_eq(str_std, str_s21);
  ck_assert_str_eq(str_std_2, str_s21_2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(string_18) {
  char str_std[30] = {'\0'};
  char str_std_2[30] = {'\0'};
  char str_s21[30] = {'\0'};
  char str_s21_2[30] = {'\0'};
  const char* str = "helloVerter";
  const char format[] = "%6s%3s";
  int int_std = sscanf(str, format, str_std, str_std_2);
  int int_s21 = s21_sscanf(str, format, str_s21, str_s21_2);
  ck_assert_str_eq(str_std, str_s21);
  ck_assert_str_eq(str_std_2, str_s21_2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(string_19) {
  wchar_t s1[100] = {'\0'};
  wchar_t s2[100] = {'\0'};
  wchar_t s3[100] = {'\0'};
  wchar_t s4[100] = {'\0'};
  wchar_t s5[100] = {'\0'};
  wchar_t s6[100] = {'\0'};
  wchar_t s7[100] = {'\0'};
  wchar_t s8[100] = {'\0'};

  const char str[] = "abc\r\tdef\v\n \t \nabc\r \t\f\v\r123\f  -   456";
  const char fstr[] = "%ls%ls%*s%ls - %ls";

  int16_t int_s21 = sscanf(str, fstr, s5, s6, s7, s8);
  int16_t int_std = s21_sscanf(str, fstr, s1, s2, s3, s4);

  ck_assert_mem_eq(s1, s5, sizeof(wchar_t) * 100);
  ck_assert_mem_eq(s2, s6, sizeof(wchar_t) * 100);
  ck_assert_mem_eq(s3, s7, sizeof(wchar_t) * 100);
  ck_assert_mem_eq(s4, s8, sizeof(wchar_t) * 100);
  ck_assert_int_eq(int_s21, int_std);
}
END_TEST
///// END S STRING /////

///// START signed SHORT INT /////
START_TEST(short_int) {
  char str[100] = "123";
  const char format[] = "%hd";
  short int n1 = -2, n2 = -2;
  int int_std = s21_sscanf(str, format, &n1);
  int int_s21 = sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(short_int_1) {
  char str[100] = "32765";
  const char format[] = "%hd";
  short int n1 = -2, n2 = -2;
  int int_std = s21_sscanf(str, format, &n1);
  int int_s21 = sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(short_int_2) {
  char str[100] = "     32765";
  const char format[] = "%hd";
  short int n1 = -2, n2 = -2;

  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);

  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(short_int_3) {
  char str[100] = "     \n32765";
  const char format[] = "%hd";
  short int n1 = -2, n2 = -2;
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(short_int_4) {
  char str[100] = "     \n\t32768";
  const char format[] = "%hd";
  short int n1 = -2, n2 = -2;
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);

  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(short_int_5) {
  char str[100] = "32768";
  const char format[] = "%hi";
  short int n1 = -2, n2 = -2;
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(short_int_6) {
  char str[100] = "1111111111";
  const char format[] = "%hi";
  short int n1 = -2, n2 = -2;
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);

  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(short_int_7) {
  char str[100] = "-12345";
  const char format[] = "%hi";
  short int n1 = -2, n2 = -2;

  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);

  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(short_int_8) {
  char str[100] = "-32768";
  const char format[] = "%hd";
  short int n1 = -2, n2 = -2;
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(short_int_9) {
  char str[100] = "-32769";
  const char format[] = "%1hd";
  short int n1 = -2, n2 = -2;
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
///// END signed SHORT INT (d) /////

///// START signed INTEGER (d) /////
// integer
START_TEST(integer) {
  const char str[50] = "      1234567";
  int n1 = -2, n2 = -2;
  const char format[] = "%d";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(integer_1) {
  const char str[50] = "      -1234567";
  int n1 = -2, n2 = -2;
  const char format[] = "%d";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(integer_2) {
  const char str[50] = "-1234567";
  int n1 = -2, n2 = -2;
  const char format[] = "%d";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(integer_3) {
  const char str[50] = "999999999999999999999999999999999";
  int n1 = -2, n2 = -2;
  const char format[] = "%d";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(integer_4) {
  const char str[50] = "";
  int n1 = -2, n2 = -2;
  const char format[] = "%d";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(integer_5) {
  const char str[50] = "0";
  int n1 = -2, n2 = -2;
  const char format[] = "%d";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(integer_6) {
  const char str[50] = "0123456789";
  int n1 = -2, n2 = -2;
  const char format[] = "%d";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(integer_7) {
  const char str[50] = "-0";
  int n1 = -2, n2 = -2;
  const char format[] = "%d";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(integer_8) {
  const char str[50] = "11111111111111111111";
  int n1 = -2, n2 = -2;
  const char format[] = "%5d";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(integer_9) {
  const char str[50] = "123456789";
  int n1 = -2, n2 = -2;
  const char format[] = "%3d";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(integer_10) {
  const char str[50] = "777";
  short int n1 = -2, n2 = -2;
  const char format[] = "%hd";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(integer_11) {
  const char str[50] = "2147483647";
  int n1 = -2, n2 = -2, number3 = 0, number4 = 0;
  const char format[] = "%4d%4d";
  int int_std = sscanf(str, format, &n1, &number3);
  int int_s21 = s21_sscanf(str, format, &n2, &number4);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(number3, number4);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(integer_12) {
  const char str[50] = "2147483647";
  short int n1 = -2, n2 = -2;
  const char format[] = "%3hd";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(integer_13) {
  const char str[50] = "-214";
  short int n1 = -2, n2 = -2;
  const char format[] = "%4hd";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(integer_14) {
  const char str[50] = "1000abcd";
  int n1 = -2, n2 = -2;
  const char format[] = "%d";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(integer_15) {
  const char str[50] = "-981241";
  int n1 = -2, n2 = -2;
  const char format[] = "%1d";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(integer_16) {
  const char str[50] = "-99999999999999";
  int n1 = -2, n2 = -2;
  const char format[] = "%d";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
///// END signed INTEGER (d) /////

///// START  signed LONG INTEGER /////
// long integer "%ld"
START_TEST(long_integer) {
  const char str[50] = "1111111111111111111";
  long int n1 = -2, n2 = -2;
  const char format[] = "%ld";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(long_integer_1) {
  const char str[50] = "-9223372036854775808";
  long int n1 = -2, n2 = -2;
  const char format[] = "%ld";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(long_integer_2) {
  const char str[50] = "2147483647";
  long int n1 = -2, n2 = -2;
  const char format[] = "%9ld";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(long_integer_3) {
  const char str[50] = "";
  long int n1 = -2, n2 = -2;
  const char format[] = "%ld";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(long_integer_4) {
  const char str[50] = "0";
  long int n1 = -2, n2 = -2;
  const char format[] = "%ld";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(long_integer_5) {
  const char str[50] = "-123456789101112125124";
  long int n1 = -2, n2 = -2;
  const char format[] = "%16ld";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(long_integer_6) {
  const char str[50] = "     2147483647";
  long int n1 = -2, n2 = -2;
  const char format[] = "%ld";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(long_integer_7) {
  const char str[50] = "92233720368 54775807";
  long int n1 = -2, n2 = -2, number3 = 0, number4 = 0;
  const char format[] = "%ld %ld";
  int int_std = sscanf(str, format, &n1, &number3);
  int int_s21 = s21_sscanf(str, format, &n2, &number4);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(number3, number4);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(long_integer_8) {
  const char str[50] = "9223372036854775807";
  long int n1 = -2, n2 = -2;
  const char format[] = "%ld";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(long_integer_9) {
  const char str[50] = "-922337203685";
  long int n1 = -2, n2 = -2;
  const char format[] = "%ld";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(long_integer_10) {
  const char str[50] = "\n \t\v-777\n \t\v";
  long int n1 = -2, n2 = -2;
  const char format[] = "%ld";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
///// END signed LONG INTEGER /////

///// START unsigned OCTAL /////
// unsigned octal number "o"
START_TEST(unsigned_octal) {
  const char str[30] = "651651351";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%o";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_octal_1) {
  const char str[30] = "    651651351";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%o";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_octal_2) {
  const char str[30] = "16516516516     ";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%o";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_octal_3) {
  const char str[30] = "77777777777777777777777777";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%o";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_octal_4) {
  const char str[40] = "777777777777777777777777777777777777777";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%o";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_octal_5) {
  const char str[30] = "777888899";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%o";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_octal_6) {
  const char str[30] = "";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%o";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_octal_7) {
  const char str[30] = " ";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%o";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_octal_8) {
  const char str[30] = "321161511616s";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%o";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_octal_9) {
  const char str[30] = "s5161596516";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%o";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_octal_10) {
  const char str[30] = "0";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%o";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_octal_11) {
  const char str[30] = "0000";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%o";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_octal_12) {
  const char str[30] = "7777777777777777777777777";
  unsigned long int n1 = 0, n2 = 0;
  const char format[] = "%lo";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_octal_13) {
  const char str[30] = "7777777777777777777777777";
  unsigned short int n1 = 0;
  unsigned short int n2 = 0;
  const char format[] = "%ho";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_octal_14) {
  const char str[30] = "12345678912345";
  unsigned long int n1 = 0, n2 = 0;
  const char format[] = "%lo";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_octal_15) {
  const char str[30] = "1298";
  unsigned short int n1 = 0;
  unsigned short int n2 = 0;
  const char format[] = "%ho";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_octal_16) {
  const char str[30] = "128746";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%4o";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_octal_17) {
  const char str[30] = "285714187412";
  unsigned int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
  const char format[] = "%2o%4o";
  int int_std = sscanf(str, format, &n1, &n3);
  int int_s21 = s21_sscanf(str, format, &n2, &n4);
  ck_assert_uint_eq(n1, n2);
  ck_assert_uint_eq(n3, n4);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_octal_18) {
  const char str[30] = "-2";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%o";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_octal_19) {
  const char str[30] = "-128746";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%o";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_octal_20) {
  const char str[30] = "-087";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%o";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_octal_21) {
  const char str[30] = "+087";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%o";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_octal_22) {
  const char str[30] = "087";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%o";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
///// END unsigned OCTAL /////

///// START unsignex HEXIMAL /////
// hexadecimal integer "x"
START_TEST(hexadecimal) {
  const char str[30] = "651651351";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%x";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(hexadecimal_1) {
  const char str[30] = "    651651351";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%x";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(hexadecimal_2) {
  const char str[30] = "\n\t16516516516     ";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%x";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(hexadecimal_3) {
  const char str[30] = "fedcbafff";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%x";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(hexadecimal_4) {
  const char str[40] = "123456789abcdef";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%x";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(hexadecimal_5) {
  const char str[30] = "ffffffffffffffff";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%x";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(hexadecimal_6) {
  const char str[30] = "";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%x";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(hexadecimal_7) {
  const char str[30] = " ";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%x";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(hexadecimal_8) {
  const char str[40] = "abcffffffffffffffacbffffffffffffffffff";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%x";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(hexadecimal_9) {
  const char str[30] = "sabfffff";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%x";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(hexadecimal_10) {
  const char str[30] = "0";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%x";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(hexadecimal_11) {
  const char str[30] = "0000";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%x";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(hexadecimal_12) {
  const char str[30] = "0xffff";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%x";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(hexadecimal_13) {
  const char str[30] = "fffffffffffffffffffffffffff";
  long unsigned int n1 = 0, n2 = 0;
  const char format[] = "%lx";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(hexadecimal_14) {
  const char str[30] = "fffffffffffffffffffffffffff";
  short unsigned int n1 = 0, n2 = 0;
  const char format[] = "%hx";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(hexadecimal_15) {
  const char str[30] = "0xffffff";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%5x";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(hexadecimal_16) {
  const char str[30] = "0xffffff";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%15x";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(hexadecimal_17) {
  const char str[30] = " 0xfff 0xFFFF";
  unsigned int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
  const char format[] = "%x%x";
  int int_std = sscanf(str, format, &n1, &n3);
  int int_s21 = s21_sscanf(str, format, &n2, &n4);
  ck_assert_uint_eq(n1, n2);
  ck_assert_uint_eq(n3, n4);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(hexadecimal_18) {
  const char str[30] = "0xfffplt";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%x";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(hexadecimal_19) {
  const char str[30] = "-0xffff";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%x";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(hexadecimal_20) {
  const char str[40] = "0xffffffffffffffffffffffffffff";
  unsigned long int n1 = 0, n2 = 0;
  const char format[] = "%lx";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
///// END unsigned HEXIMAL  /////

///// START CAPITAL unsigned HEXIMAL  /////
// capital hexadecimal integer "X"
START_TEST(capital_hexadecimal) {
  const char str[30] = "651651351";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%X";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(capital_hexadecimal_1) {
  const char str[30] = "    0X651651351";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%X";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(capital_hexadecimal_2) {
  const char str[30] = "\n\t16516516516     ";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%X";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(capital_hexadecimal_3) {
  const char str[30] = "ABCDEFFFF";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%X";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(capital_hexadecimal_4) {
  const char str[40] = "123456789ABcdef";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%X";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(capital_hexadecimal_5) {
  const char str[30] = "ffffffffffffffff";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%X";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(capital_hexadecimal_6) {
  const char str[30] = "";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%X";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(capital_hexadecimal_7) {
  const char str[30] = " ";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%X";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(capital_hexadecimal_8) {
  const char str[40] = "abcffffffffffffffacbffffffffffffffffff";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%X";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(capital_hexadecimal_9) {
  const char str[30] = "sabfffff";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%X";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(capital_hexadecimal_10) {
  const char str[30] = "0";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%X";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(capital_hexadecimal_11) {
  const char str[30] = "0000";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%X";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(capital_hexadecimal_12) {
  const char str[30] = "0xffff";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%X";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(capital_hexadecimal_13) {
  const char str[30] = "fffffffffffffffffffffffffff";
  unsigned long int n1 = 0, n2 = 0;
  const char format[] = "%lX";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(capital_hexadecimal_14) {
  const char str[30] = "fffffffffffffffffffffffffff";
  short unsigned int n1 = 0, n2 = 0;
  const char format[] = "%hX";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(capital_hexadecimal_15) {
  const char str[30] = "0xffffff";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%5X";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(capital_hexadecimal_16) {
  const char str[30] = "0xffffff";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%15X";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(capital_hexadecimal_17) {
  const char str[30] = " 0xfff 0xFFFF";
  unsigned int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
  const char format[] = "%X%X";
  int int_std = sscanf(str, format, &n1, &n3);
  int int_s21 = s21_sscanf(str, format, &n2, &n4);
  ck_assert_uint_eq(n1, n2);
  ck_assert_uint_eq(n3, n4);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(capital_hexadecimal_18) {
  const char str[30] = "0xfffplt";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%X";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(capital_hexadecimal_19) {
  const char str[30] = "-0xffff";
  unsigned int n1 = 0, n2 = 0;
  const char format[] = "%X";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
///// END CAPITAL unsigned HEXIMAL /////

///// START unsigned DECIMAL (u) /////
// unsigned decimal "u"
START_TEST(unsigned_decimal) {
  const char str[30] = "651651351";
  unsigned int n1 = -2, n2 = -2;
  const char format[] = "%u";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_decimal_1) {
  const char str[30] = "    651651351";
  unsigned int n1 = -2, n2 = -2;
  const char format[] = "%u";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_decimal_2) {
  const char str[30] = "16516516516     ";
  unsigned int n1 = -2, n2 = -2;
  const char format[] = "%u";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_decimal_3) {
  const char str[30] = "9999999999999";
  unsigned int n1 = -2, n2 = -2;
  const char format[] = "%u";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_decimal_4) {
  const char str[40] = "99999999999";
  unsigned int n1 = -2, n2 = -2;
  const char format[] = "%u";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_decimal_5) {
  const char str[30] = "999999999";
  unsigned int n1 = -2, n2 = -2;
  const char format[] = "%u";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_decimal_6) {
  const char str[30] = "";
  unsigned int n1 = -2, n2 = -2;
  const char format[] = "%u";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_decimal_7) {
  const char str[30] = " ";
  unsigned int n1 = -2, n2 = -2;
  const char format[] = "%u";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_decimal_8) {
  const char str[30] = "161551891196561s";
  unsigned int n1 = -2, n2 = -2;
  const char format[] = "%u";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_decimal_9) {
  const char str[30] = "s5161596516";
  unsigned int n1 = -2, n2 = -2;
  const char format[] = "%u";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_decimal_10) {
  const char str[30] = "0";
  unsigned int n1 = -2, n2 = -2;
  const char format[] = "%u";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_decimal_11) {
  const char str[30] = "0000";
  unsigned int n1 = -2, n2 = -2;
  const char format[] = "%u";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_decimal_12) {
  const char str[35] = "999999999999999999";
  unsigned long int n1 = -2, n2 = -2;
  const char format[] = "%lu";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_decimal_13) {
  const char str[35] = "999999999999999999999999999999";
  unsigned short int n1 = -2, n2 = -2;
  const char format[] = "%hu";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_decimal_14) {
  const char str[35] = "1";
  unsigned short n1 = -2, n2 = -2;
  const char format[] = "%hu";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_decimal_15) {
  const char str[35] = "18274612";
  unsigned long int n1 = -2, n2 = -2;
  const char format[] = "%lu";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_decimal_16) {
  const char str[35] = "18274611241241242151245122";
  unsigned long int n1 = -2, n2 = -2;
  const char format[] = "%15lu";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_decimal_17) {
  const char str[35] = "99";
  unsigned short int n1 = -2, n2 = -2;
  const char format[] = "%hu";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_decimal_18) {
  const char str[35] = "9911";
  unsigned short int n1 = -2, n2 = -2, n3 = -2, n4 = -2;
  const char format[] = "%2hu%1hu";
  int int_std = sscanf(str, format, &n1, &n3);
  int int_s21 = s21_sscanf(str, format, &n2, &n4);
  ck_assert_uint_eq(n1, n2);
  ck_assert_uint_eq(n3, n4);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_decimal_19) {
  const char str[35] = "1248912124";
  unsigned int n1 = -2, n2 = -2, n3 = -2, n4 = -2;
  const char format[] = "%5u%10u";
  int int_std = sscanf(str, format, &n1, &n3);
  int int_s21 = s21_sscanf(str, format, &n2, &n4);
  ck_assert_uint_eq(n1, n2);
  ck_assert_uint_eq(n3, n4);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(unsigned_decimal_20) {
  const char str[35] = "-12515";
  unsigned int n1 = -2, n2 = -2;
  const char format[] = "%u";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_uint_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
///// END unsigned DECIMAL (u) /////

///// START signed INTEGER (i) /////
// signed_integer "i"
START_TEST(signed_integer) {
  const char str[50] = "+02337203";
  short n1 = -2, n2 = -2;
  const char format[] = "%hi";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(signed_integer_1) {
  const char str[50] = "-2337203";
  short n1 = -2, n2 = -2;
  const char format[] = "%hi";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(signed_integer_2) {
  const char str[50] = "0x2337203";
  short n1 = -2, n2 = -2;
  const char format[] = "%hi";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST

START_TEST(signed_integer_3) {
  const char str[50] = "+013206561";
  int n1 = -2, n2 = -2;
  const char format[] = "%i";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(signed_integer_4) {
  const char str[50] = "-13206561";
  int n1 = -2, n2 = -2;
  const char format[] = "%i";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(signed_integer_5) {
  char str[50] = "0x13206561";
  int n1 = -2, n2 = -2;
  const char format[] = "%i";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST

START_TEST(signed_integer_6) {
  const char str[50] = "-084949488948494948894";
  long int n1 = -2, n2 = -2;
  const char format[] = "%li";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(signed_integer_7) {
  const char str[50] = "-849494889484";
  long int n1 = -2, n2 = -2;
  const char format[] = "%li";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(signed_integer_8) {
  const char str[50] = "-0x84949488948";
  long int n1 = -2, n2 = -2;
  const char format[] = "%li";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST

START_TEST(signed_integer_9) {
  const char str[50] = "-044444431111111111";
  int n1 = -2, n2 = -2;
  const char format[] = "%5i";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(signed_integer_10) {
  const char str[50] = "-0xfff";
  int n1 = -2, n2 = -2;
  const char format[] = "%5i";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(signed_integer_11) {
  const char str[50] = "123";
  int n1 = -2, n2 = -2;
  const char format[] = "%5i";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST

START_TEST(signed_integer_12) {
  const char str[50] = "0xC61F3C 0x5D712C4";
  int n1 = -2, n2 = -2, number3 = 0, number4 = 0;
  const char format[] = "%i%i";
  int int_std = sscanf(str, format, &n1, &number3);
  int int_s21 = s21_sscanf(str, format, &n2, &number4);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(number3, number4);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(signed_integer_13) {
  const char str[50] = "5D712C4";
  int n1 = -2, n2 = -2;
  const char format[] = "%5i";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(signed_integer_14) {
  const char str[50] = "99";
  short int n1 = -2, n2 = -2;
  const char format[] = "%hi";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(signed_integer_15) {
  const char str[50] = "99";
  short n1 = -2, n2 = -2;
  const char format[] = "%hi";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(signed_integer_16) {
  const char str[50] = "\n \t9918239\t ";
  int n1 = -2, n2 = -2;
  const char format[] = " %i ";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(signed_integer_17) {
  const char str[50] = "0";
  int n1 = -2, n2 = -2;
  const char format[] = "%i";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(signed_integer_18) {
  const char str[50] = "1284";
  int n1 = -2, n2 = -2;
  const char format[] = "%5i";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(signed_integer_19) {
  const char str[50] = "-01284";
  int n1 = -2, n2 = -2;
  const char format[] = "%1i";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(signed_integer_20) {
  const char str[50] = "-1284";
  int n1 = -2, n2 = -2;
  const char format[] = "%1i";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(signed_integer_21) {
  const char str[50] = "-0x1284";
  int n1 = -2, n2 = -2;
  const char format[] = "%1i";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST

START_TEST(signed_integer_22) {
  const char str[50] = "046514165";
  short int n1 = -2, n2 = -2;
  const char format[] = "%hi";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(signed_integer_23) {
  const char str[50] = "0xffffffffffffff";
  short n1 = -2, n2 = -2;
  const char format[] = "%hi";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(signed_integer_24) {
  const char str[50] = "9999999999999999999999999999";
  short n1 = -2, n2 = -2;
  const char format[] = "%hi";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(signed_integer_25) {
  const char str[50] = "-53 +53";
  int n1 = -2, n2 = -2, n3 = -2, n4 = -2;
  const char format[] = "%i. %i";
  int int_std = sscanf(str, format, &n1, &n3);
  int int_s21 = s21_sscanf(str, format, &n2, &n4);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(n3, n4);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(signed_integer_26) {
  const char str[50] = "-53 +53";
  int n1 = -2, n2 = -2, n3 = -2, n4 = -2;
  const char format[] = "%i. %i";
  int int_std = sscanf(str, format, &n1, &n3);
  int int_s21 = s21_sscanf(str, format, &n2, &n4);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(n3, n4);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(signed_integer_27) {
  const char str[50] = "-0xAB53 +0xAB53";
  int n1 = -2, n2 = -2, n3 = -2, n4 = -2;
  const char format[] = "%i. %i";
  int int_std = sscanf(str, format, &n1, &n3);
  int int_s21 = s21_sscanf(str, format, &n2, &n4);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(n3, n4);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
///// END signed INTEGER (i) /////

///// START count char (n) /////
// n_symbols "%n"
START_TEST(n_symbols) {
  char str_std_1[30] = {'\0'};
  char str_s21_1[30] = {'\0'};
  char str_std_2[30] = {'\0'};
  char str_s21_2[30] = {'\0'};
  const char* str = "abc de fgh";
  int n = -2, n21 = -2;
  const char format[] = "%s%n%s";
  int int_std = sscanf(str, format, str_std_1, &n, str_std_2);
  int int_s21 = s21_sscanf(str, format, str_s21_1, &n21, str_s21_2);
  ck_assert_int_eq(n, n21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(n_symbols_1) {
  char str_std_1[30] = {'\0'};
  char str_s21_1[30] = {'\0'};
  char str_std_2[30] = {'\0'};
  char str_s21_2[30] = {'\0'};
  const char* str = "abc de fgh";
  int n = -2, n21 = -2;
  const char format[] = "%s %n %s";
  int int_std = sscanf(str, format, str_std_1, &n, str_std_2);
  int int_s21 = s21_sscanf(str, format, str_s21_1, &n21, str_s21_2);
  ck_assert_int_eq(n, n21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(n_symbols_2) {
  char str_std_1[30] = {'\0'};
  char str_s21_1[30] = {'\0'};
  char str_std_2[30] = {'\0'};
  char str_s21_2[30] = {'\0'};
  const char* str = "abc de fgh";
  int n = -2, n21 = -2;
  const char format[] = "%n%s%s";
  int int_std = sscanf(str, format, &n, str_std_1, str_std_2);
  int int_s21 = s21_sscanf(str, format, &n21, str_s21_1, str_s21_2);
  ck_assert_int_eq(n, n21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(n_symbols_3) {
  char str_std_1[30] = {'\0'};
  char str_s21_1[30] = {'\0'};
  char str_std_2[30] = {'\0'};
  char str_s21_2[30] = {'\0'};
  const char* str = "     abc\n\t def gh";
  int n = -2, n21 = -2;
  const char format[] = "%s%n%s";
  int int_std = sscanf(str, format, str_std_1, &n, str_std_2);
  int int_s21 = s21_sscanf(str, format, str_s21_1, &n21, str_s21_2);
  ck_assert_int_eq(n, n21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(n_symbols_4) {
  char str_std_1[30] = {'\0'};
  char str_s21_1[30] = {'\0'};
  char str_std_2[30] = {'\0'};
  char str_s21_2[30] = {'\0'};
  const char* str = "     abc\n\t def gh";
  int n = -2, n21 = -2;
  const char format[] = "%s %n %s";
  int int_std = sscanf(str, format, str_std_1, &n, str_std_2);
  int int_s21 = s21_sscanf(str, format, str_s21_1, &n21, str_s21_2);
  ck_assert_int_eq(n, n21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(n_symbols_5) {
  char ch1 = 'a', ch2 = 'a';
  const char* str = "\n \tabc\n\t def gh";
  int n = -2, n21 = -2;
  const char format[] = " %c%n";
  int int_std = sscanf(str, format, &ch1, &n);
  int int_s21 = s21_sscanf(str, format, &ch2, &n21);
  ck_assert_int_eq(n, n21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(n_symbols_6) {
  char ch1 = 'a', ch2 = 'a';
  int i1 = 0, i2 = 0;
  float f1 = 0, f2 = 0;
  void* p1 = NULL;
  void* p2 = NULL;
  const char* str = "a 123 213 0x7ffd44";
  int n = -2, n21 = -2;
  const char format[] = "%c%d%f%p%n";
  int int_std = sscanf(str, format, &ch1, &i1, &f1, &p1, &n);
  int int_s21 = s21_sscanf(str, format, &ch2, &i2, &f2, &p2, &n21);
  ck_assert_int_eq(n, n21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(n_symbols_7) {
  char ch1 = 'a', ch2 = 'a';
  const char* str = "\n \tabc\n\t def gh";
  int n = -2, n21 = -2;
  const char format[] = " %c%n";
  int int_std = sscanf(str, format, &ch1, &n);
  int int_s21 = s21_sscanf(str, format, &ch2, &n21);
  ck_assert_int_eq(n, n21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(n_symbols_8) {
  char ch1 = 'a', ch2 = 'a';
  const char* str = "\n \tabc\n\t def gh";
  int n = -2, n21 = -2;
  const char format[] = " %c%n";
  int int_std = sscanf(str, format, &ch1, &n);
  int int_s21 = s21_sscanf(str, format, &ch2, &n21);
  ck_assert_int_eq(n, n21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(n_symbols_9) {
  char ch1 = 'a', ch2 = 'a';
  const char* str = "\n \tabc\n\t def gh";
  int n = -2, n21 = -2;
  const char format[] = " %c%n";
  int int_std = sscanf(str, format, &ch1, &n);
  int int_s21 = s21_sscanf(str, format, &ch2, &n21);
  ck_assert_int_eq(n, n21);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
///// END count char (n) /////

///// START pointer (p) /////
// pointer "p"
START_TEST(pointer) {
  const char str[40] = "165165fff";
  void* n1 = NULL;
  void* n2 = s21_NULL;
  const char format[] = "%p";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_ptr_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST

START_TEST(pointer_1) {
  const char str[40] = "0xffafafafaf";
  void* n1 = NULL;
  void* n2 = s21_NULL;
  const char format[] = "%p";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_ptr_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(pointer_2) {
  const char str[40] = "0fffffff";
  void* n1 = NULL;
  void* n2 = s21_NULL;
  const char format[] = "%p";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_ptr_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(pointer_3) {
  const char str[40] = "fffffffffffffffffffffffffffff";
  void* n1 = NULL;
  void* n2 = s21_NULL;
  const char format[] = "%p";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_ptr_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(pointer_4) {
  const char str[40] = "        165155";
  void* n1 = NULL;
  void* n2 = s21_NULL;
  const char format[] = "%p";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_ptr_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(pointer_5) {
  const char str[40] = "";
  void* n1 = NULL;
  void* n2 = s21_NULL;
  const char format[] = "%p";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_ptr_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(pointer_6) {
  const char str[40] = " ";
  void* n1 = NULL;
  void* n2 = s21_NULL;
  const char format[] = "%p";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_ptr_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(pointer_7) {
  const char str[40] = "ddddfffff";
  void* n1 = NULL;
  void* n2 = s21_NULL;
  const char format[] = "%p";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_ptr_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(pointer_8) {
  const char str[40] = "ghghgh";
  void* n1 = NULL;
  void* n2 = s21_NULL;
  const char format[] = "%p";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_ptr_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(pointer_9) {
  const char str[40] = "x7777";
  void* n1 = NULL;
  void* n2 = s21_NULL;
  const char format[] = "%p";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_ptr_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(pointer_10) {
  const char str[40] = "-0x7777";
  void* n1 = NULL;
  void* n2 = s21_NULL;
  const char format[] = "%p";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_ptr_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(pointer_11) {
  const char str[40] = "0";
  void* n1 = NULL;
  void* n2 = s21_NULL;
  const char format[] = "%p";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_ptr_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(pointer_12) {
  const char str[40] = "0xffafa";
  void* n1 = NULL;
  void* n2 = s21_NULL;
  const char format[] = "%5p";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_ptr_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(pointer_13) {
  const char str[40] = "-0xffafa";
  void* n1 = NULL;
  void* n2 = s21_NULL;
  const char format[] = "%5p";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_ptr_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
///// END pointer (p)  /////

///// START format /////
// skip in format test
START_TEST(format_str_0) {
  char str[100] = "33 hello 34";
  const char format[] = "%d hello %d";
  int n1 = -2, n2 = -2;
  int n3 = -2, n4 = -2;
  int int_std = s21_sscanf(str, format, &n1, &n3);
  int int_s21 = sscanf(str, format, &n2, &n4);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(n3, n4);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(format_str_1) {
  char str[100] = "33hello34";
  const char format[] = "%dhello%d";
  int n1 = -2, n2 = -2;
  int n3 = -2, n4 = -2;
  int int_std = s21_sscanf(str, format, &n1, &n3);
  int int_s21 = sscanf(str, format, &n2, &n4);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(n3, n4);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(format_str_2) {
  char str[100] = "33\n \v\thello 34";
  const char format[] = "%d hello %d";
  int n1 = -2, n2 = -2;
  int n3 = -2, n4 = -2;
  int int_std = sscanf(str, format, &n1, &n3);
  int int_s21 = s21_sscanf(str, format, &n2, &n4);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(n3, n4);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(format_str_3) {
  char str[100] = "33\n \v\thello34";
  const char format[] = "%d hello%d";
  int n1 = -2, n2 = -2;
  int n3 = -2, n4 = -2;
  int int_std = sscanf(str, format, &n1, &n3);
  int int_s21 = s21_sscanf(str, format, &n2, &n4);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(n3, n4);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(format_str_4) {
  char str[100] = "33hello\n \v34";
  const char format[] = "%dhello%d";
  int n1 = -2, n2 = -2;
  int n3 = -2, n4 = -2;
  int int_std = s21_sscanf(str, format, &n1, &n3);
  int int_s21 = sscanf(str, format, &n2, &n4);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(n3, n4);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(format_str_5) {
  char str[100] = "33hello!@a34";
  const char format[] = "%dhello!@a%d %n";
  int n1 = -2, n2 = -2;
  int n3 = -2, n4 = -2;
  int n5 = -2, n6 = -2;
  int int_std = s21_sscanf(str, format, &n1, &n3, &n5);
  int int_s21 = sscanf(str, format, &n2, &n4, &n6);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(n3, n4);
  ck_assert_int_eq(n5, n6);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
///// END format /////

///// START float (f) /////
// float "f"
START_TEST(float_) {
  const char* str = "778.342";
  float n1 = -2, n2 = -2;
  const char* format = "%f";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(float_1) {
  char* str = "10.000005";
  float n1 = -2, n2 = -2;
  const char* format = "%f";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(float_2) {
  char* str = "0.000005";
  float n1 = -2, n2 = -2;
  const char* format = "%f";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(float_3) {
  char* str = "778.342";
  float n1 = -2, n2 = -2;
  const char* format = "%5f";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(float_4) {
  char* str = "   778.342";
  float n1 = -2, n2 = -2;
  const char* format = "%f";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(float_5) {
  char* str = "340282346638528859811704183484516925440.000000";
  float n1 = -2, n2 = -2;
  const char* format = "%f";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(float_6) {
  char* str = "340282346638528859811704183484516925445.000000";
  float n1 = -2, n2 = -2;
  const char* format = "%5f";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(float_7) {
  char* str = "0.000000";
  float n1 = -2, n2 = -2;
  const char* format = "%f";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(float_8) {
  char* str = "-778.342";
  float n1 = -2, n2 = -2;
  const char* format = "%f";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(float_9) {
  char* str = "-0.000000";
  float n1 = -2, n2 = -2;
  const char* format = "%f";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(float_10) {
  char* str = "0.99999";
  float n1 = -2, n2 = -2;
  const char* format = "%f";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(float_11) {
  char* str = "-340282346638528859811704183484516925440.000000";
  float n1 = -2, n2 = -2;
  const char* format = "%f";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(float_12) {
  char* str = "-340282346638528859811704183484516925440.000000";
  float n1 = -2, n2 = -2;
  const char* format = "%10f";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(float_13) {
  char* str = "1234567890.123000000";
  float n1 = -2, n2 = -2;
  const char* format = "%5f";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(float_14) {
  char* str = "0.0999999";
  float n1 = -2, n2 = -2;
  const char* format = "%f";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);

  int res = (n1 - n2 > -0.0000001 && n1 - n2 < 0.0000001) ? 0 : 1;
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(float_15) {
  char* str = "-1245.12345";
  float n1 = -2, n2 = -2;
  const char* format = "%1f";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(float_16) {
  char* str = "9.99999 0.999999";
  float n1 = -2, n2 = -2, n3 = -2, n4 = -2;
  const char* format = "%f%f";
  int int_std = sscanf(str, format, &n1, &n3);
  int int_s21 = s21_sscanf(str, format, &n2, &n4);

  ck_assert_float_eq(n1, n2);
  ck_assert_float_eq(n3, n4);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(float_17) {
  char* str = "19.99999 23.999999";
  float n1 = -2, n2 = -2, n3 = -2, n4 = -2;
  const char* format = "%4f%3f";
  int int_std = sscanf(str, format, &n1, &n3);
  int int_s21 = s21_sscanf(str, format, &n2, &n4);
  ck_assert_float_eq(n1, n2);
  ck_assert_float_eq(n3, n4);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST

START_TEST(float_18) {
  char* str = "+.0- 321";
  float n1 = -2, n2 = -2;
  const char* format = "%f";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_int_eq(isnan(n1), isnan(n2));
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
///// END float /////

///// START double (lf) /////
// double "%lf"
START_TEST(double_) {
  const char* str = "7781291.191919";
  double n1 = -2, n2 = -2;
  const char* format = "%lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(double_1) {
  char* str = "10000.000005";
  double n1 = -2, n2 = -2;
  const char* format = "%lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(double_2) {
  char* str = "0.0000000005";
  double n1 = -2, n2 = -2;
  const char* format = "%lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(double_3) {
  char* str = "123456789.11111";
  double n1 = -2, n2 = -2;
  const char* format = "%5lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(double_4) {
  char* str = "   778.342";
  double n1 = -2, n2 = -2;
  const char* format = "%lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(double_5) {
  char str[500];
  sprintf(str, "%lf", DBL_MAX);
  double n1 = -2, n2 = -2;
  const char* format = "%lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  // ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(double_6) {
  char str[500];
  sprintf(str, "%lf", DBL_MIN);
  double n1 = -2, n2 = -2;
  const char* format = "%5lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(double_7) {
  char* str = "0.000000";
  double n1 = -2, n2 = -2;
  const char* format = "%lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(double_8) {
  char* str = "-99999999999999991.778";
  double n1 = -2, n2 = -2;
  const char* format = "%lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  // ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(double_9) {
  char* str = "-0.000000";
  double n1 = -2, n2 = -2;
  const char* format = "%lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(double_10) {
  char* str = "0.99999";
  double n1 = -2, n2 = -2;
  const char* format = "%lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(double_11) {
  char* str = "-340282346638528859811704183484516925440.000000";
  double n1 = -2, n2 = -2;
  const char* format = "%lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(double_12) {
  char* str = "-340282346638528859811704183484516925440.000000";
  double n1 = -2, n2 = -2;
  const char* format = "%10lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(double_13) {
  char* str = "1234567890.123000000";
  double n1 = -2, n2 = -2;
  const char* format = "%15lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(double_14) {
  char* str = "0.0999999";
  double n1 = -2, n2 = -2;
  const char* format = "%lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(double_15) {
  char* str = "-1245.12345";
  double n1 = -2, n2 = -2;
  const char* format = "%1lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(double_16) {
  char* str = "9.99999 0.999999";
  double n1 = -2, n2 = -2, n3 = -2, n4 = -2;
  const char* format = "%lf%lf";
  int int_std = sscanf(str, format, &n1, &n3);
  int int_s21 = s21_sscanf(str, format, &n2, &n4);
  ck_assert_double_eq(n1, n2);
  ck_assert_double_eq(n3, n4);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(double_17) {
  char* str = "19.99999 23.999999";
  double n1 = -2, n2 = -2, n3 = -2, n4 = -2;
  const char* format = "%4lf%3lf";
  int int_std = sscanf(str, format, &n1, &n3);
  int int_s21 = s21_sscanf(str, format, &n2, &n4);
  ck_assert_double_eq(n1, n2);
  ck_assert_double_eq(n3, n4);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(double_18) {
  char* str = "4.32112e+05";
  double n1 = -2, n2 = -2;
  const char* format = "%lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  // ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(double_19) {
  char* str = "4.32112e-10";
  double n1 = -2, n2 = -2;
  const char* format = "%lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  // ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(double_20) {
  char* str = "-4.32112e-007";
  double n1 = -2, n2 = -2;
  const char* format = "%lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  // ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(double_21) {
  char* str = "\n4.32112E-00.E";
  double n1 = -2, n2 = -2;
  const char* format = "%lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
///// END double (lf) /////

///// START long double (lf) /////

// long double "Lf"
START_TEST(long_double) {
  const char* str = "7781291201497124071.124124191919";
  long double n1 = -2, n2 = -2;
  const char* format = "%Lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_ldouble_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(long_double_1) {
  char* str = "10000000.0000000005";
  long double n1 = -2, n2 = -2;
  const char* format = "%Lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_ldouble_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(long_double_2) {
  char* str = "0.0000000000000005";
  long double n1 = -2, n2 = -2;
  const char* format = "%Lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(long_double_3) {
  char* str = "123456789.11111";
  long double n1 = -2, n2 = -2;
  const char* format = "%5Lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_ldouble_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(long_double_4) {
  char* str = "   778.342";
  long double n1 = -2, n2 = -2;
  const char* format = "%Lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_ldouble_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST

START_TEST(long_double_5) {
  char* str = "0.000000000";
  long double n1 = -2, n2 = -2;
  const char* format = "%Lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_ldouble_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(long_double_6) {
  char* str = "-9999999999999999124.778";
  long double n1 = -2, n2 = -2;
  const char* format = "%Lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_ldouble_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(long_double_7) {
  char* str = "-0.000000";
  long double n1 = -2, n2 = -2;
  const char* format = "%Lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_ldouble_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(long_double_8) {
  char* str = "0.99999";
  long double n1 = -2, n2 = -2;
  const char* format = "%Lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(long_double_9) {
  char* str = "-340282346638528859811704183484516925440.000000";
  long double n1 = -2, n2 = -2;
  const char* format = "%Lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_ldouble_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(long_double_10) {
  char* str = "-340282346638528859811704183484516925440.000000";
  long double n1 = -2, n2 = -2;
  const char* format = "%10Lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_ldouble_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(long_double_11) {
  char* str = "1234567890.123000000";
  long double n1 = -2, n2 = -2;
  const char* format = "%12Lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_ldouble_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(long_double_12) {
  char* str = "-1245.12345";
  long double n1 = -2, n2 = -2;
  const char* format = "%1Lf";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_ldouble_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(long_double_13) {
  char* str = "9.5 0.5";
  long double n1 = -2, n2 = -2, n3 = -2, n4 = -2;
  const char* format = "%Lf%Lf";
  int int_std = sscanf(str, format, &n1, &n3);
  int int_s21 = s21_sscanf(str, format, &n2, &n4);
  ck_assert_ldouble_eq(n1, n2);
  ck_assert_ldouble_eq(n3, n4);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(long_double_14) {
  char* str = "19912764912846.99999 23981264981264.999999";
  long double n1 = -2, n2 = -2, n3 = -2, n4 = -2;
  const char* format = "%4Lf%3Lf";
  int int_std = sscanf(str, format, &n1, &n3);
  int int_s21 = s21_sscanf(str, format, &n2, &n4);
  ck_assert_ldouble_eq(n1, n2);
  ck_assert_ldouble_eq(n3, n4);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
///// END long double (lf) /////

///// START scientific /////
// scientific notation "e"
START_TEST(scientific_notation) {
  char str[] = "778.342e-03";
  const char* format = "number: %e";
  float n1 = -2, n2 = -2;
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(scientific_notation_1) {
  char str[] = "778.342e-03";
  const char* format = "number: %10e";
  float n1 = -2, n2 = -2;
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(scientific_notation_2) {
  char str[] = "778342.0e+03";
  const char* format = "number: %e";
  float n1 = -2, n2 = -2;
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(scientific_notation_3) {
  char str[] = "778342.0e-04";
  const char* format = "number: %e";
  float n1 = -2, n2 = -2;
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(scientific_notation_4) {
  char str[] = "0.00778342e-04";
  const char* format = "number: %e";
  float n1 = -2, n2 = -2;
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(scientific_notation_5) {
  char str[] = "0.00778342e-00";
  const char* format = "number: %e";
  float n1 = -2, n2 = -2;
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(scientific_notation_6) {
  char str[] = "7.9e-2";
  const char* format = "number: %e";
  float n1 = -2, n2 = -2;
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(scientific_notation_7) {
  char str[] = "7.0777e+5";
  const char* format = "number: %e";
  float n1 = -2, n2 = -2;
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(scientific_notation_8) {
  char str[] = "5.5e+5";
  const char* format = "number: %e";
  float n1 = -2, n2 = -2;
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(scientific_notation_9) {
  char str[] = "0.9999E-0";
  const char* format = "number: %e";
  float n1 = -2, n2 = -2;
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(scientific_notation_10) {
  char str[] = "9.9999e-05";
  const char* format = "number: %e";
  float n1 = -2, n2 = -2;
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(scientific_notation_11) {
  char str[] = "9.9999E-05";
  const char* format = "number: %e";
  float n1 = -2, n2 = -2;
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(scientific_notation_12) {
  char str[] = "9.9999E+2";
  const char* format = "number: %10e";
  float n1 = -2, n2 = -2;
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(scientific_notation_13) {
  char str[] = "0.99999 1.99999";
  const char* format = "number: %4E %5e";
  float n1 = -2, n2 = -2, n3 = -2, n4 = -2;
  int int_std = sscanf(str, format, &n1, &n3);
  int int_s21 = s21_sscanf(str, format, &n2, &n4);
  ck_assert_float_eq(n1, n2);
  ck_assert_float_eq(n3, n4);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(scientific_notation_14) {
  char str[] = "-1.23456E+4";
  const char* format = "number: %e";
  float n1 = -2, n2 = -2;
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(scientific_notation_15) {
  char str[] = "-1.23456E+2";
  const char* format = "number: %1e";
  float n1 = -2, n2 = -2;
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(scientific_notation_16) {
  char str[] = "778.342e-07";
  const char* format = "number: %le";
  double n1 = 0, n2 = 0;
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(scientific_notation_17) {
  char str[] = "999.999e+07";
  const char* format = "number: %lE";
  double n1 = 0, n2 = 0;
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(scientific_notation_18) {
  char str[] = "778.342E-8";
  const char* format = "number: %10le";
  double n1 = 0, n2 = 0;
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST

// shortest_decimal "gG"
START_TEST(shortest_decimal_1) {
  char* str = "10000.000005";
  double n1 = -2, n2 = -2;
  const char* format = "%lg";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(shortest_decimal_2) {
  char* str = "0.0000000005";
  long double n1 = -2, n2 = -2;
  const char* format = "%LG";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(shortest_decimal_3) {
  char* str = "123456789.11111";
  double n1 = -2, n2 = -2;
  const char* format = "%5lg";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(shortest_decimal_4) {
  char* str = "   778.342";
  float n1 = -2, n2 = -2;
  const char* format = "%g";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(shortest_decimal_5) {
  char str[500];
  sprintf(str, "%lf", DBL_MAX);
  double n1 = -2, n2 = -2;
  const char* format = "%lG";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  // ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(shortest_decimal_6) {
  char str[500];
  sprintf(str, "%lf", DBL_MIN);
  double n1 = -2, n2 = -2;
  const char* format = "%5lg";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(shortest_decimal_7) {
  char* str = "0.000000";
  float n1 = -2, n2 = -2;
  const char* format = "%g";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(shortest_decimal_8) {
  char* str = "-99999999999999991.778";
  long double n1 = -2, n2 = -2;
  const char* format = "%Lg";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  // ck_assert_ldouble_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(shortest_decimal_9) {
  char* str = "-0.000000";
  double n1 = -2, n2 = -2;
  const char* format = "%4lg";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(shortest_decimal_10) {
  char* str = "0.99999";
  double n1 = -2, n2 = -2;
  const char* format = "%lg";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(shortest_decimal_11) {
  char* str = "-340282346638528859811704183484516925440.000000";
  double n1 = -2, n2 = -2;
  const char* format = "%lg";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(shortest_decimal_12) {
  char* str = "-340282346638528859811704183484516925440.000000";
  double n1 = -2, n2 = -2;
  const char* format = "%10lg";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(shortest_decimal_13) {
  char* str = "1234567890.123000000";
  double n1 = -2, n2 = -2;
  const char* format = "%12lg";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(shortest_decimal_14) {
  char* str = "0.0999999";
  float n1 = -2, n2 = -2;
  const char* format = "%20G";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_float_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(shortest_decimal_15) {
  char* str = "-1245.12345";
  double n1 = -2, n2 = -2;
  const char* format = "%1lg";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(shortest_decimal_16) {
  char* str = "9.99999 9.9e-00";
  double n1 = -2, n2 = -2, n3 = -2, n4 = -2;
  const char* format = "%lg%lG";
  int int_std = sscanf(str, format, &n1, &n3);
  int int_s21 = s21_sscanf(str, format, &n2, &n4);
  ck_assert_double_eq(n1, n2);
  ck_assert_double_eq(n3, n4);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(shortest_decimal_17) {
  char* str = "19.99999 23.999999";
  double n1 = -2, n2 = -2, n3 = -2, n4 = -2;
  const char* format = "%4lg%3lg";
  int int_std = sscanf(str, format, &n1, &n3);
  int int_s21 = s21_sscanf(str, format, &n2, &n4);
  ck_assert_double_eq(n1, n2);
  ck_assert_double_eq(n3, n4);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
START_TEST(shortest_decimal_18) {
  char* str = "4.32112e+05";
  double n1 = -2, n2 = -2;
  const char* format = "%lg";
  int int_std = sscanf(str, format, &n1);
  int int_s21 = s21_sscanf(str, format, &n2);
  // ck_assert_double_eq(n1, n2);
  ck_assert_int_eq(int_std, int_s21);
}
END_TEST

// mixed test
START_TEST(mixed_0) {
  char str[1000] =
      "  \vhelloVerter999 0.99999 1.003E-05 0x7a123 0600 %% 800 "
      "0xfffffffopxieua123jd\n";
  const char format[] = "%s%hd%f%E%i%o %2c %u%n%p %*s";
  char s[30] = {'\0'};
  char s_21[30] = {'\0'};
  short int n1 = -2;
  short int n1_s21 = -2;
  float n2 = -2;
  float n2_s21 = -2;
  float n3 = -2;
  float n3_s21 = -2;
  int n4 = 2;
  int n4_s21 = 2;
  unsigned int n5 = 2;
  unsigned int n5_s21 = 2;
  char c = 'a';
  char c_s21 = 'a';
  unsigned int n6 = 2;
  unsigned int n6_s21 = 2;
  int n7 = -2;
  int n7_s21 = -2;
  void* p = s21_NULL;
  void* p_s21 = s21_NULL;
  int int_std = s21_sscanf(str, format, s_21, &n1_s21, &n2_s21, &n3_s21,
                           &n4_s21, &n5_s21, &c_s21, &n6_s21, &n7_s21, &p_s21);
  int int_s21 =
      sscanf(str, format, s, &n1, &n2, &n3, &n4, &n5, &c, &n6, &n7, &p);
  ck_assert_str_eq(s, s_21);
  ck_assert_int_eq(n1, n1_s21);
  ck_assert_float_eq(n2, n2_s21);
  ck_assert_double_eq(n3, n3_s21);
  ck_assert_uint_eq(n4, n4_s21);
  ck_assert_uint_eq(n5, n5_s21);
  ck_assert_int_eq(c, c_s21);
  ck_assert_uint_eq(n6, n6_s21);
  ck_assert_int_eq(n7, n7_s21);
  ck_assert_ptr_eq(p, p_s21);

  ck_assert_int_eq(int_std, int_s21);
}
END_TEST
///// END scientific /////

Suite* s21_sscanf_suite(void) {
  Suite* suite = suite_create("s21_sscanf_test");
  TCase* tcase_core = tcase_create("s21_sscanf");

  tcase_add_test(tcase_core, ch);
  tcase_add_test(tcase_core, ch_1);
  tcase_add_test(tcase_core, ch_2);
  tcase_add_test(tcase_core, ch_3);
  tcase_add_test(tcase_core, ch_4);
  tcase_add_test(tcase_core, ch_5);
  tcase_add_test(tcase_core, ch_6);
  tcase_add_test(tcase_core, ch_7);
  tcase_add_test(tcase_core, ch_8);
  tcase_add_test(tcase_core, ch_9);
  tcase_add_test(tcase_core, ch_10);
  tcase_add_test(tcase_core, ch_11);
  tcase_add_test(tcase_core, ch_12);

  tcase_add_test(tcase_core, symbol_percent);
  tcase_add_test(tcase_core, symbol_percent_1);
  tcase_add_test(tcase_core, symbol_percent_2);
  tcase_add_test(tcase_core, symbol_percent_3);
  tcase_add_test(tcase_core, symbol_percent_4);
  tcase_add_test(tcase_core, symbol_percent_5);

  tcase_add_test(tcase_core, string);
  tcase_add_test(tcase_core, string_1);
  tcase_add_test(tcase_core, string_2);
  tcase_add_test(tcase_core, string_3);
  tcase_add_test(tcase_core, string_4);
  tcase_add_test(tcase_core, string_5);
  tcase_add_test(tcase_core, string_6);
  tcase_add_test(tcase_core, string_7);
  tcase_add_test(tcase_core, string_8);
  tcase_add_test(tcase_core, string_9);
  tcase_add_test(tcase_core, string_10);
  tcase_add_test(tcase_core, string_11);
  tcase_add_test(tcase_core, string_12);
  tcase_add_test(tcase_core, string_13);
  tcase_add_test(tcase_core, string_14);
  tcase_add_test(tcase_core, string_15);
  tcase_add_test(tcase_core, string_16);
  tcase_add_test(tcase_core, string_17);
  tcase_add_test(tcase_core, string_18);
  tcase_add_test(tcase_core, string_19);

  tcase_add_test(tcase_core, short_int);
  tcase_add_test(tcase_core, short_int_1);
  tcase_add_test(tcase_core, short_int_2);
  tcase_add_test(tcase_core, short_int_3);
  tcase_add_test(tcase_core, short_int_4);
  tcase_add_test(tcase_core, short_int_5);
  tcase_add_test(tcase_core, short_int_6);
  tcase_add_test(tcase_core, short_int_7);
  tcase_add_test(tcase_core, short_int_8);
  tcase_add_test(tcase_core, short_int_9);

  tcase_add_test(tcase_core, integer);
  tcase_add_test(tcase_core, integer_1);
  tcase_add_test(tcase_core, integer_2);
  tcase_add_test(tcase_core, integer_3);
  tcase_add_test(tcase_core, integer_4);
  tcase_add_test(tcase_core, integer_5);
  tcase_add_test(tcase_core, integer_6);
  tcase_add_test(tcase_core, integer_7);
  tcase_add_test(tcase_core, integer_8);
  tcase_add_test(tcase_core, integer_9);
  tcase_add_test(tcase_core, integer_10);
  tcase_add_test(tcase_core, integer_11);
  tcase_add_test(tcase_core, integer_12);
  tcase_add_test(tcase_core, integer_13);
  tcase_add_test(tcase_core, integer_14);
  tcase_add_test(tcase_core, integer_15);
  tcase_add_test(tcase_core, integer_16);

  tcase_add_test(tcase_core, long_integer);
  tcase_add_test(tcase_core, long_integer_1);
  tcase_add_test(tcase_core, long_integer_2);
  tcase_add_test(tcase_core, long_integer_3);
  tcase_add_test(tcase_core, long_integer_4);
  tcase_add_test(tcase_core, long_integer_5);
  tcase_add_test(tcase_core, long_integer_6);
  tcase_add_test(tcase_core, long_integer_7);
  tcase_add_test(tcase_core, long_integer_8);
  tcase_add_test(tcase_core, long_integer_9);
  tcase_add_test(tcase_core, long_integer_10);

  tcase_add_test(tcase_core, unsigned_octal);
  tcase_add_test(tcase_core, unsigned_octal_1);
  tcase_add_test(tcase_core, unsigned_octal_2);
  tcase_add_test(tcase_core, unsigned_octal_3);
  tcase_add_test(tcase_core, unsigned_octal_4);
  tcase_add_test(tcase_core, unsigned_octal_5);
  tcase_add_test(tcase_core, unsigned_octal_6);
  tcase_add_test(tcase_core, unsigned_octal_7);
  tcase_add_test(tcase_core, unsigned_octal_8);
  tcase_add_test(tcase_core, unsigned_octal_9);
  tcase_add_test(tcase_core, unsigned_octal_10);
  tcase_add_test(tcase_core, unsigned_octal_11);
  tcase_add_test(tcase_core, unsigned_octal_12);
  tcase_add_test(tcase_core, unsigned_octal_13);
  tcase_add_test(tcase_core, unsigned_octal_14);
  tcase_add_test(tcase_core, unsigned_octal_15);
  tcase_add_test(tcase_core, unsigned_octal_16);
  tcase_add_test(tcase_core, unsigned_octal_17);
  tcase_add_test(tcase_core, unsigned_octal_18);
  tcase_add_test(tcase_core, unsigned_octal_19);
  tcase_add_test(tcase_core, unsigned_octal_20);
  tcase_add_test(tcase_core, unsigned_octal_21);
  tcase_add_test(tcase_core, unsigned_octal_22);

  tcase_add_test(tcase_core, unsigned_decimal);
  tcase_add_test(tcase_core, unsigned_decimal_1);
  tcase_add_test(tcase_core, unsigned_decimal_2);
  tcase_add_test(tcase_core, unsigned_decimal_3);
  tcase_add_test(tcase_core, unsigned_decimal_4);
  tcase_add_test(tcase_core, unsigned_decimal_5);
  tcase_add_test(tcase_core, unsigned_decimal_6);
  tcase_add_test(tcase_core, unsigned_decimal_7);
  tcase_add_test(tcase_core, unsigned_decimal_8);
  tcase_add_test(tcase_core, unsigned_decimal_9);
  tcase_add_test(tcase_core, unsigned_decimal_10);
  tcase_add_test(tcase_core, unsigned_decimal_11);
  tcase_add_test(tcase_core, unsigned_decimal_12);
  tcase_add_test(tcase_core, unsigned_decimal_13);
  tcase_add_test(tcase_core, unsigned_decimal_14);
  tcase_add_test(tcase_core, unsigned_decimal_15);
  tcase_add_test(tcase_core, unsigned_decimal_16);
  tcase_add_test(tcase_core, unsigned_decimal_17);
  tcase_add_test(tcase_core, unsigned_decimal_18);
  tcase_add_test(tcase_core, unsigned_decimal_19);
  tcase_add_test(tcase_core, unsigned_decimal_20);

  tcase_add_test(tcase_core, hexadecimal);
  tcase_add_test(tcase_core, hexadecimal_1);
  tcase_add_test(tcase_core, hexadecimal_2);
  tcase_add_test(tcase_core, hexadecimal_3);
  tcase_add_test(tcase_core, hexadecimal_4);
  tcase_add_test(tcase_core, hexadecimal_5);
  tcase_add_test(tcase_core, hexadecimal_6);
  tcase_add_test(tcase_core, hexadecimal_7);
  tcase_add_test(tcase_core, hexadecimal_8);
  tcase_add_test(tcase_core, hexadecimal_9);
  tcase_add_test(tcase_core, hexadecimal_10);
  tcase_add_test(tcase_core, hexadecimal_11);
  tcase_add_test(tcase_core, hexadecimal_12);
  tcase_add_test(tcase_core, hexadecimal_13);
  tcase_add_test(tcase_core, hexadecimal_14);
  tcase_add_test(tcase_core, hexadecimal_15);
  tcase_add_test(tcase_core, hexadecimal_16);
  tcase_add_test(tcase_core, hexadecimal_17);
  tcase_add_test(tcase_core, hexadecimal_18);
  tcase_add_test(tcase_core, hexadecimal_19);
  tcase_add_test(tcase_core, hexadecimal_20);

  tcase_add_test(tcase_core, capital_hexadecimal);
  tcase_add_test(tcase_core, capital_hexadecimal_1);
  tcase_add_test(tcase_core, capital_hexadecimal_2);
  tcase_add_test(tcase_core, capital_hexadecimal_3);
  tcase_add_test(tcase_core, capital_hexadecimal_4);
  tcase_add_test(tcase_core, capital_hexadecimal_5);
  tcase_add_test(tcase_core, capital_hexadecimal_6);
  tcase_add_test(tcase_core, capital_hexadecimal_7);
  tcase_add_test(tcase_core, capital_hexadecimal_8);
  tcase_add_test(tcase_core, capital_hexadecimal_9);
  tcase_add_test(tcase_core, capital_hexadecimal_10);
  tcase_add_test(tcase_core, capital_hexadecimal_11);
  tcase_add_test(tcase_core, capital_hexadecimal_12);
  tcase_add_test(tcase_core, capital_hexadecimal_13);
  tcase_add_test(tcase_core, capital_hexadecimal_14);
  tcase_add_test(tcase_core, capital_hexadecimal_15);
  tcase_add_test(tcase_core, capital_hexadecimal_16);
  tcase_add_test(tcase_core, capital_hexadecimal_17);
  tcase_add_test(tcase_core, capital_hexadecimal_18);
  tcase_add_test(tcase_core, capital_hexadecimal_19);

  tcase_add_test(tcase_core, signed_integer);
  tcase_add_test(tcase_core, signed_integer_1);
  tcase_add_test(tcase_core, signed_integer_2);
  tcase_add_test(tcase_core, signed_integer_3);
  tcase_add_test(tcase_core, signed_integer_4);
  tcase_add_test(tcase_core, signed_integer_5);
  tcase_add_test(tcase_core, signed_integer_6);
  tcase_add_test(tcase_core, signed_integer_7);
  tcase_add_test(tcase_core, signed_integer_8);
  tcase_add_test(tcase_core, signed_integer_9);
  tcase_add_test(tcase_core, signed_integer_10);
  tcase_add_test(tcase_core, signed_integer_11);
  tcase_add_test(tcase_core, signed_integer_12);
  tcase_add_test(tcase_core, signed_integer_13);
  tcase_add_test(tcase_core, signed_integer_14);
  tcase_add_test(tcase_core, signed_integer_15);
  tcase_add_test(tcase_core, signed_integer_16);
  tcase_add_test(tcase_core, signed_integer_17);
  tcase_add_test(tcase_core, signed_integer_18);
  tcase_add_test(tcase_core, signed_integer_19);
  tcase_add_test(tcase_core, signed_integer_20);
  tcase_add_test(tcase_core, signed_integer_21);
  tcase_add_test(tcase_core, signed_integer_22);
  tcase_add_test(tcase_core, signed_integer_23);
  tcase_add_test(tcase_core, signed_integer_24);
  tcase_add_test(tcase_core, signed_integer_25);
  tcase_add_test(tcase_core, signed_integer_26);
  tcase_add_test(tcase_core, signed_integer_27);

  tcase_add_test(tcase_core, n_symbols);
  tcase_add_test(tcase_core, n_symbols_1);
  tcase_add_test(tcase_core, n_symbols_2);
  tcase_add_test(tcase_core, n_symbols_3);
  tcase_add_test(tcase_core, n_symbols_4);
  tcase_add_test(tcase_core, n_symbols_5);
  tcase_add_test(tcase_core, n_symbols_6);
  tcase_add_test(tcase_core, n_symbols_7);
  tcase_add_test(tcase_core, n_symbols_8);
  tcase_add_test(tcase_core, n_symbols_9);

  tcase_add_test(tcase_core, pointer);
  tcase_add_test(tcase_core, pointer_1);
  tcase_add_test(tcase_core, pointer_2);
  tcase_add_test(tcase_core, pointer_3);
  tcase_add_test(tcase_core, pointer_4);
  tcase_add_test(tcase_core, pointer_5);
  tcase_add_test(tcase_core, pointer_6);
  tcase_add_test(tcase_core, pointer_7);
  tcase_add_test(tcase_core, pointer_8);
  tcase_add_test(tcase_core, pointer_9);
  tcase_add_test(tcase_core, pointer_10);
  tcase_add_test(tcase_core, pointer_11);
  tcase_add_test(tcase_core, pointer_12);
  tcase_add_test(tcase_core, pointer_13);

  tcase_add_test(tcase_core, format_str_0);
  tcase_add_test(tcase_core, format_str_1);
  tcase_add_test(tcase_core, format_str_2);
  tcase_add_test(tcase_core, format_str_3);
  tcase_add_test(tcase_core, format_str_4);
  tcase_add_test(tcase_core, format_str_5);

  tcase_add_test(tcase_core, float_);
  tcase_add_test(tcase_core, float_1);
  tcase_add_test(tcase_core, float_2);
  tcase_add_test(tcase_core, float_3);
  tcase_add_test(tcase_core, float_4);
  tcase_add_test(tcase_core, float_5);
  tcase_add_test(tcase_core, float_6);
  tcase_add_test(tcase_core, float_7);
  tcase_add_test(tcase_core, float_8);
  tcase_add_test(tcase_core, float_9);
  tcase_add_test(tcase_core, float_10);
  tcase_add_test(tcase_core, float_11);
  tcase_add_test(tcase_core, float_12);
  tcase_add_test(tcase_core, float_13);
  tcase_add_test(tcase_core, float_14);
  tcase_add_test(tcase_core, float_15);
  tcase_add_test(tcase_core, float_16);
  tcase_add_test(tcase_core, float_17);
  tcase_add_test(tcase_core, float_18);

  tcase_add_test(tcase_core, double_);
  tcase_add_test(tcase_core, double_1);
  tcase_add_test(tcase_core, double_2);
  tcase_add_test(tcase_core, double_3);
  tcase_add_test(tcase_core, double_4);
  tcase_add_test(tcase_core, double_5);
  tcase_add_test(tcase_core, double_6);
  tcase_add_test(tcase_core, double_7);
  tcase_add_test(tcase_core, double_8);
  tcase_add_test(tcase_core, double_9);
  tcase_add_test(tcase_core, double_10);
  tcase_add_test(tcase_core, double_11);
  tcase_add_test(tcase_core, double_12);
  tcase_add_test(tcase_core, double_13);
  tcase_add_test(tcase_core, double_14);
  tcase_add_test(tcase_core, double_15);
  tcase_add_test(tcase_core, double_16);
  tcase_add_test(tcase_core, double_17);
  tcase_add_test(tcase_core, double_18);
  tcase_add_test(tcase_core, double_19);
  tcase_add_test(tcase_core, double_20);
  tcase_add_test(tcase_core, double_21);

  tcase_add_test(tcase_core, long_double);
  tcase_add_test(tcase_core, long_double_1);
  tcase_add_test(tcase_core, long_double_2);
  tcase_add_test(tcase_core, long_double_3);
  tcase_add_test(tcase_core, long_double_4);
  tcase_add_test(tcase_core, long_double_5);
  tcase_add_test(tcase_core, long_double_6);
  tcase_add_test(tcase_core, long_double_7);
  tcase_add_test(tcase_core, long_double_8);
  tcase_add_test(tcase_core, long_double_9);
  tcase_add_test(tcase_core, long_double_10);
  tcase_add_test(tcase_core, long_double_11);
  tcase_add_test(tcase_core, long_double_12);
  tcase_add_test(tcase_core, long_double_13);
  tcase_add_test(tcase_core, long_double_14);

  tcase_add_test(tcase_core, scientific_notation);
  tcase_add_test(tcase_core, scientific_notation_1);
  tcase_add_test(tcase_core, scientific_notation_2);
  tcase_add_test(tcase_core, scientific_notation_3);
  tcase_add_test(tcase_core, scientific_notation_4);
  tcase_add_test(tcase_core, scientific_notation_5);
  tcase_add_test(tcase_core, scientific_notation_6);
  tcase_add_test(tcase_core, scientific_notation_7);
  tcase_add_test(tcase_core, scientific_notation_8);
  tcase_add_test(tcase_core, scientific_notation_9);
  tcase_add_test(tcase_core, scientific_notation_10);
  tcase_add_test(tcase_core, scientific_notation_11);
  tcase_add_test(tcase_core, scientific_notation_12);
  tcase_add_test(tcase_core, scientific_notation_13);
  tcase_add_test(tcase_core, scientific_notation_14);
  tcase_add_test(tcase_core, scientific_notation_15);
  tcase_add_test(tcase_core, scientific_notation_16);
  tcase_add_test(tcase_core, scientific_notation_17);
  tcase_add_test(tcase_core, scientific_notation_18);

  tcase_add_test(tcase_core, shortest_decimal_1);
  tcase_add_test(tcase_core, shortest_decimal_2);
  tcase_add_test(tcase_core, shortest_decimal_3);
  tcase_add_test(tcase_core, shortest_decimal_4);
  tcase_add_test(tcase_core, shortest_decimal_5);
  tcase_add_test(tcase_core, shortest_decimal_6);
  tcase_add_test(tcase_core, shortest_decimal_7);
  tcase_add_test(tcase_core, shortest_decimal_8);
  tcase_add_test(tcase_core, shortest_decimal_9);
  tcase_add_test(tcase_core, shortest_decimal_10);
  tcase_add_test(tcase_core, shortest_decimal_11);
  tcase_add_test(tcase_core, shortest_decimal_12);
  tcase_add_test(tcase_core, shortest_decimal_13);
  tcase_add_test(tcase_core, shortest_decimal_14);
  tcase_add_test(tcase_core, shortest_decimal_15);
  tcase_add_test(tcase_core, shortest_decimal_16);
  tcase_add_test(tcase_core, shortest_decimal_17);
  tcase_add_test(tcase_core, shortest_decimal_18);

  tcase_add_test(tcase_core, mixed_0);

  suite_add_tcase(suite, tcase_core);

  return suite;
}