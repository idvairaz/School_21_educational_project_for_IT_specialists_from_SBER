#include "../s21_string.h"
#include "test.h"

START_TEST(d_simple_int) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  int s21 = 5;
  int system = 5;
  s21_sprintf(s21_buffer, "This is %d", s21);
  sprintf(buff, "This is %d", system);

  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(d_negative_int) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  int s21 = -19;
  int system = -19;
  s21_sprintf(s21_buffer, "This is %d", s21);
  sprintf(buff, "This is %d", system);

  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(d_int_in_middle_of_str) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  int s21 = 1024;
  int system = 1024;
  s21_sprintf(s21_buffer, "This is %d number", s21);
  sprintf(buff, "This is %d number", system);

  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(s_simple_test) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  char* s21 = "Hello str";
  char* system = "Hello str";
  s21_sprintf(s21_buffer, "This is %s", s21);
  sprintf(buff, "This is %s", system);

  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(s_empty_test) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  char* s21 = "";
  char* system = "";
  s21_sprintf(s21_buffer, "This is %s", s21);
  sprintf(buff, "This is %s", system);

  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(s_int_str_test) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  char* s21 = "12345";
  char* system = "12345";
  s21_sprintf(s21_buffer, "This is %s", s21);
  sprintf(buff, "This is %s", system);

  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(s_str_in_middle_of_str) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  char* s21 = "my";
  char* system = "my";
  s21_sprintf(s21_buffer, "This is %s stringg", s21);
  sprintf(buff, "This is %s stringg", system);

  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(f_simple) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  float s21 = 4.3;
  float system = 4.3;
  s21_sprintf(s21_buffer, "This is %f number", s21);
  sprintf(buff, "This is %f number", system);

  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(f_simple_zero) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  float s21 = 0.34;
  float system = 0.34;
  s21_sprintf(s21_buffer, "This is %f number", s21);
  sprintf(buff, "This is %f number", system);

  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(f_big_number) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  float s21 = 9.3425789;
  float system = 9.3425789;
  s21_sprintf(s21_buffer, "This is %f number", s21);
  sprintf(buff, "This is %f number", system);

  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(f_big_int_part) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  float s21 = 10.3;
  float system = 10.3;
  s21_sprintf(s21_buffer, "This is %f number", s21);
  sprintf(buff, "This is %f number", system);

  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(f_big_int_part2) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  float s21 = pow(2, 100);
  float system = pow(2, 100);
  s21_sprintf(s21_buffer, "This is %f number", s21);
  sprintf(buff, "This is %f number", system);

  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(f_big_int_part3) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  float number = pow(2, 100);

  s21_sprintf(s21_buffer, "This is %f number", number);
  sprintf(buff, "This is %f number", number);

  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(f_big_int_part4) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  float number = pow(2, 1024) * -1;

  s21_sprintf(s21_buffer, "This is %f number", number);
  sprintf(buff, "This is %f number", number);

  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(f_zero) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  float s21 = 0;
  float system = 0;
  s21_sprintf(s21_buffer, "This is %f number", s21);
  sprintf(buff, "This is %f number", system);

  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(f_exactness_simple) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  float s21 = 2.322;
  float system = 2.322;
  s21_sprintf(s21_buffer, "This is %.2f number", s21);
  sprintf(buff, "This is %.2f number", system);

  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(f_exactness_with_simple_rounding) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  float s21 = 2.3228;
  float system = 2.3228;
  s21_sprintf(s21_buffer, "This is %.3f number", s21);
  sprintf(buff, "This is %.3f number", system);

  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(f_exactness_with_hard_rounding) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  float s21 = 2.3228324234;
  float system = 2.3228324234;
  s21_sprintf(s21_buffer, "This is %.3f number", s21);
  sprintf(buff, "This is %.3f number", system);

  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(c_simple_char) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buffer, "%c", 'c');
  sprintf(buff, "%c", 'c');

  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(c_number_ASCII) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buffer, "%c", 67);
  sprintf(buff, "%c", 67);

  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(c_number_char) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buffer, "%c", '8');
  sprintf(buff, "%c", '8');
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(c_space_char) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buffer, "%c", ' ');
  sprintf(buff, "%c", ' ');
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(c_negative_char) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buffer, "%-7c", '6');
  sprintf(buff, "%-7c", '6');
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(flag_plus_simple_test) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buffer, "%+d", 21);
  sprintf(buff, "%+d", 21);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(flag_plus_negative_number) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buffer, "%+d", -250);
  sprintf(buff, "%+d", -250);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(flag_plus_zero) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buffer, "result: %+d", 0);
  sprintf(buff, "result: %+d", 0);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(flag_space_simple_test) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buffer, "result: % d", 25);
  sprintf(buff, "result: % d", 25);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(flag_space_negative_number) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buffer, "% d", -1000);
  sprintf(buff, "% d", -1000);

  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(flag_space_zero) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buffer, "% d", 0);
  sprintf(buff, "% d", 0);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(u_negative_number) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  int number = -100;
  s21_sprintf(s21_buffer, "%u", number);
  sprintf(buff, "%u", number);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(u_with_zero) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  int number = 0;
  s21_sprintf(s21_buffer, "%u", number);
  sprintf(buff, "%u", number);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(u_simple_test) {
  char s21_buffer[100] = "";
  unsigned int number = 01234;
  ck_assert_int_eq(s21_sprintf(s21_buffer, "%u", number),
                   sprintf(s21_buffer, "%u", number));
}
END_TEST

START_TEST(d_width) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buffer, "%5d", 1568);
  sprintf(buff, "%5d", 1568);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(f_width) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buffer, "%4f", 15.15);
  sprintf(buff, "%4f", 15.15);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(c_width) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buffer, "%10c", 'z');
  sprintf(buff, "%10c", 'z');
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(s_width) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buffer, "%3s", "Hello, world!");
  sprintf(buff, "%3s", "Hello, world!");
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(u_width) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buffer, "%8u", 15678940);
  sprintf(buff, "%8u", 15678940);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(percent_one) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buffer, "%% %d", 1);
  sprintf(buff, "%% %d", 1);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(percent_some) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buffer, "%%%%%% %f", 1.0);
  sprintf(buff, "%%%%%% %f", 1.0);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(l_d) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  long int d = 1234567890;
  s21_sprintf(s21_buffer, "%ld", d);
  sprintf(buff, "%ld", d);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(l_u) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  unsigned long int u = 1234567890;
  s21_sprintf(s21_buffer, "%lu", u);
  sprintf(buff, "%lu", u);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(left_justify) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  int x = 15;
  s21_sprintf(s21_buffer, "%-10d %-5d %-7d %-2d", x, x, x, x);
  sprintf(buff, "%-10d %-5d %-7d %-2d", x, x, x, x);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(left_justify_plus_short) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  short int y = 16;
  unsigned short int x = 15;
  s21_sprintf(s21_buffer, "%-10hd %-5hu %-7ho %-2hx", y, x, x, x);
  sprintf(buff, "%-10hd %-5hu %-7ho %-2hx", y, x, x, x);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(short_int_uns_oct_value) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  short int y = 16;
  unsigned short int x = 15;
  s21_sprintf(s21_buffer, "%hd %hu %ho %hx", y, x, x, x);
  sprintf(buff, "%hd %hu %ho %hx", y, x, x, x);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(x_simple_test) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buffer, "%x", 15);
  sprintf(buff, "%x", 15);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(X_simple_test) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buffer, "%X", 11);
  sprintf(buff, "%X", 11);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(x_big_number) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buffer, "%x", 1505);
  sprintf(buff, "%x", 1505);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(X_big_number) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buffer, "%X", 12345678);
  sprintf(buff, "%X", 12345678);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(x_zero) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buffer, "%x", 0);
  sprintf(buff, "%x", 0);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(X_zero) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buffer, "%X", 0);
  sprintf(buff, "%X", 0);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(o_simple_test) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buffer, "%o", 10);
  sprintf(buff, "%o", 10);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(o_before_eight) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buffer, "%o", 7);
  sprintf(buff, "%o", 7);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(o_zero) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buffer, "%o", 0);
  sprintf(buff, "%o", 0);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(o_big_number) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buffer, "%o", 12345678);
  sprintf(buff, "%o", 12345678);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(o_width) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buffer, "%4o", 256);
  sprintf(buff, "%4o", 256);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(x_width) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buffer, "%15x", 15);
  sprintf(buff, "%15x", 15);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(l_o) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  long int o = 84518;
  s21_sprintf(s21_buffer, "%lo", o);
  sprintf(buff, "%lo", o);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(l_x) {
  char s21_buffer[100] = "";
  char buff[100] = "";
  long int x = 15;
  s21_sprintf(s21_buffer, "%lx", x);
  sprintf(buff, "%lx", x);
  ck_assert_pstr_eq(s21_buffer, buff);
}
END_TEST

START_TEST(e_simple_test) {
  double number = 9.765625e-05;
  char s21_buffer[100] = "";
  ck_assert_int_eq(s21_sprintf(s21_buffer, "%.4e", number),
                   sprintf(s21_buffer, "%.4e", number));
}
END_TEST

START_TEST(E_with_L) {
  char s21_buffer[512];
  char s21_buffer2[512];
  char* format = "%.17LE";
  long double value = 544774;
  ck_assert_int_eq(s21_sprintf(s21_buffer, format, value),
                   sprintf(s21_buffer2, format, value));

  ck_assert_str_eq(s21_buffer, s21_buffer2);
}
END_TEST

START_TEST(E_simple_test) {
  double number = 9.765625e-05;
  char s21_buffer[100] = "";
  ck_assert_int_eq(s21_sprintf(s21_buffer, "%.4E", number),
                   sprintf(s21_buffer, "%.4E", number));
}
END_TEST

START_TEST(g_simple_test) {
  float number = 1.111111;
  char s21_buffer[100] = "";
  ck_assert_int_eq(s21_sprintf(s21_buffer, "%g", number),
                   sprintf(s21_buffer, "%g", number));
}
END_TEST

START_TEST(G_with_L) {
  char s21_buffer[512];
  char s21_buffer2[512];
  char format[] = "%LG";
  long double value = 0.1;

  ck_assert_int_eq(s21_sprintf(s21_buffer, format, value),
                   sprintf(s21_buffer2, format, value));

  ck_assert_str_eq(s21_buffer, s21_buffer2);
}
END_TEST
START_TEST(g_with_L) {
  char s21_buffer[512];
  char s21_buffer2[512];
  char format[] = "%Lg";
  long double value = 0.1;

  ck_assert_int_eq(s21_sprintf(s21_buffer, format, value),
                   sprintf(s21_buffer2, format, value));

  ck_assert_str_eq(s21_buffer, s21_buffer2);
}
END_TEST

START_TEST(G_simple_test) {
  float number = 1.111111;
  char s21_buffer[100] = "";
  ck_assert_int_eq(s21_sprintf(s21_buffer, "%G", number),
                   sprintf(s21_buffer, "%G", number));
}
END_TEST

START_TEST(ptr) {
  char s21_buffer[512];
  char s21_buffer2[512];
  int num = 1;
  int s21 = s21_sprintf(s21_buffer, "%p", &num);
  int string = sprintf(s21_buffer2, "%p", &num);

  ck_assert_int_eq(s21, string);
  ck_assert_str_eq(s21_buffer, s21_buffer2);
}

START_TEST(null_ptr) {
  char s21_buffer[512];
  char s21_buffer2[512];
  char* format = "%p";
  char* ptr = NULL;
  ck_assert_int_eq(s21_sprintf(s21_buffer, format, ptr),
                   sprintf(s21_buffer2, format, ptr));

  ck_assert_str_eq(s21_buffer, s21_buffer2);
}
END_TEST

START_TEST(ptr_precision) {
  char s21_buffer[512];
  char s21_buffer2[512];
  char* format = "%.5p";
  ck_assert_int_eq(s21_sprintf(s21_buffer, format, format),
                   sprintf(s21_buffer2, format, format));

  ck_assert_str_eq(s21_buffer, s21_buffer2);
}

START_TEST(many_spec) {
  char s21_buffer[512];
  char s21_buffer2[512];
  char* format = "%#-10x%x%X%#x%#X%5.5x";
  unsigned value = 674545678;
  ck_assert_int_eq(
      s21_sprintf(s21_buffer, format, value, value, value, value, value, value),
      sprintf(s21_buffer2, format, value, value, value, value, value, value));

  ck_assert_str_eq(s21_buffer, s21_buffer2);
}
END_TEST

//Сдвиги
START_TEST(with_shift) {
  char s21_buffer[20];
  char s21_buffer_more[100];
  int number = -696;
  double st_d = 9.765625;
  float st_f = 1.111111;
  unsigned int st_u = 1234;

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%d", number),
                   sprintf(s21_buffer, "%d", number));
  ck_assert_int_eq(s21_sprintf(s21_buffer, "%16d", number),
                   sprintf(s21_buffer, "%16d", number));
  ck_assert_int_eq(s21_sprintf(s21_buffer, "%+16d", number),
                   sprintf(s21_buffer, "%+16d", number));
  ck_assert_int_eq(s21_sprintf(s21_buffer, "%-16d", number),
                   sprintf(s21_buffer, "%-16d", number));
  ck_assert_int_eq(s21_sprintf(s21_buffer, "%016d", number),
                   sprintf(s21_buffer, "%016d", number));
  ck_assert_int_eq(s21_sprintf(s21_buffer, "% 16d", number),
                   sprintf(s21_buffer, "% 16d", number));
  ck_assert_int_eq(s21_sprintf(s21_buffer, "%#16o", number),
                   sprintf(s21_buffer, "%#16o", number));

  number = 0x123;

  ck_assert_int_eq(s21_sprintf(s21_buffer_more, "%+16e", st_d),
                   sprintf(s21_buffer_more, "%+16e", st_d));
  ck_assert_int_eq(s21_sprintf(s21_buffer_more, "%-16e", st_d),
                   sprintf(s21_buffer_more, "%-16e", st_d));
  ck_assert_int_eq(s21_sprintf(s21_buffer_more, "%016e", st_d),
                   sprintf(s21_buffer_more, "%016e", st_d));
  ck_assert_int_eq(s21_sprintf(s21_buffer_more, "% 16e", st_d),
                   sprintf(s21_buffer_more, "% 16e", st_d));
  ck_assert_int_eq(s21_sprintf(s21_buffer_more, "%#16e", st_d),
                   sprintf(s21_buffer_more, "%#16e", st_d));

  st_d = -78.8;
  ck_assert_int_eq(s21_sprintf(s21_buffer, "%16f", st_d),
                   sprintf(s21_buffer, "%16f", st_d));
  ck_assert_int_eq(s21_sprintf(s21_buffer, "%+16f", st_d),
                   sprintf(s21_buffer, "%+16f", st_d));
  ck_assert_int_eq(s21_sprintf(s21_buffer, "%-16f", st_d),
                   sprintf(s21_buffer, "%-16f", st_d));
  ck_assert_int_eq(s21_sprintf(s21_buffer, "%016f", st_d),
                   sprintf(s21_buffer, "%016f", st_d));
  ck_assert_int_eq(s21_sprintf(s21_buffer, "% 16f", st_d),
                   sprintf(s21_buffer, "% 16f", st_d));
  ck_assert_int_eq(s21_sprintf(s21_buffer, "%#16f", st_d),
                   sprintf(s21_buffer, "%#16f", st_d));

  ck_assert_int_eq(s21_sprintf(s21_buffer_more, "%16g", st_f),
                   sprintf(s21_buffer_more, "%16g", st_f));
  ck_assert_int_eq(s21_sprintf(s21_buffer_more, "%+16g", st_f),
                   sprintf(s21_buffer_more, "%+16g", st_f));
  ck_assert_int_eq(s21_sprintf(s21_buffer_more, "%-16g", st_f),
                   sprintf(s21_buffer_more, "%-16g", st_f));
  ck_assert_int_eq(s21_sprintf(s21_buffer_more, "%016g", st_f),
                   sprintf(s21_buffer_more, "%016g", st_f));
  ck_assert_int_eq(s21_sprintf(s21_buffer_more, "% 16g", st_f),
                   sprintf(s21_buffer_more, "% 16g", st_f));
  ck_assert_int_eq(s21_sprintf(s21_buffer_more, "%#16g", st_f),
                   sprintf(s21_buffer_more, "%#16g", st_f));

  ck_assert_int_eq(s21_sprintf(s21_buffer_more, "%16u", st_u),
                   sprintf(s21_buffer_more, "%16u", st_u));
  ck_assert_int_eq(s21_sprintf(s21_buffer_more, "%-16u", st_u),
                   sprintf(s21_buffer_more, "%-16u", st_u));

  ck_assert_int_eq(s21_sprintf(s21_buffer_more, "%16x", number),
                   sprintf(s21_buffer_more, "%16x", number));
  ck_assert_int_eq(s21_sprintf(s21_buffer_more, "%-16x", number),
                   sprintf(s21_buffer_more, "%-16x", number));
  ck_assert_int_eq(s21_sprintf(s21_buffer_more, "%#16x", number),
                   sprintf(s21_buffer_more, "%#16x", number));

  number = 01234;
  ck_assert_int_eq(s21_sprintf(s21_buffer_more, "%o", number),
                   sprintf(s21_buffer_more, "%o", number));
  ck_assert_int_eq(s21_sprintf(s21_buffer_more, "%16o", number),
                   sprintf(s21_buffer_more, "%16o", number));
  ck_assert_int_eq(s21_sprintf(s21_buffer_more, "%+16d", number),
                   sprintf(s21_buffer_more, "%+16d", number));
  ck_assert_int_eq(s21_sprintf(s21_buffer_more, "%-16d", number),
                   sprintf(s21_buffer_more, "%-16d", number));
  ck_assert_int_eq(s21_sprintf(s21_buffer_more, "% 16d", number),
                   sprintf(s21_buffer_more, "% 16d", number));
}
END_TEST

Suite* s21_sprintf_suite(void) {
  Suite* suite = suite_create("s21_sprintf");
  TCase* tcase_core = tcase_create("s21_sprintf");
  tcase_add_test(tcase_core, d_simple_int);
  tcase_add_test(tcase_core, d_negative_int);
  tcase_add_test(tcase_core, d_int_in_middle_of_str);
  tcase_add_test(tcase_core, s_simple_test);
  tcase_add_test(tcase_core, s_empty_test);
  tcase_add_test(tcase_core, s_int_str_test);
  tcase_add_test(tcase_core, s_str_in_middle_of_str);
  tcase_add_test(tcase_core, f_simple);
  tcase_add_test(tcase_core, f_simple_zero);
  tcase_add_test(tcase_core, f_big_number);
  tcase_add_test(tcase_core, f_big_int_part);
  tcase_add_test(tcase_core, f_big_int_part2);
  tcase_add_test(tcase_core, f_big_int_part3);
  tcase_add_test(tcase_core, f_big_int_part4);
  tcase_add_test(tcase_core, f_zero);
  tcase_add_test(tcase_core, f_exactness_simple);
  tcase_add_test(tcase_core, f_exactness_with_simple_rounding);
  tcase_add_test(tcase_core, f_exactness_with_hard_rounding);
  tcase_add_test(tcase_core, c_simple_char);
  tcase_add_test(tcase_core, c_number_ASCII);
  tcase_add_test(tcase_core, c_number_char);
  tcase_add_test(tcase_core, c_space_char);
  tcase_add_test(tcase_core, c_negative_char);
  tcase_add_test(tcase_core, flag_plus_simple_test);
  tcase_add_test(tcase_core, flag_plus_negative_number);
  tcase_add_test(tcase_core, flag_plus_zero);
  tcase_add_test(tcase_core, flag_space_simple_test);
  tcase_add_test(tcase_core, flag_space_negative_number);
  tcase_add_test(tcase_core, flag_space_zero);
  tcase_add_test(tcase_core, d_width);
  tcase_add_test(tcase_core, f_width);
  tcase_add_test(tcase_core, c_width);
  tcase_add_test(tcase_core, s_width);
  tcase_add_test(tcase_core, u_width);
  tcase_add_test(tcase_core, percent_one);
  tcase_add_test(tcase_core, percent_some);
  tcase_add_test(tcase_core, l_d);
  tcase_add_test(tcase_core, l_u);
  tcase_add_test(tcase_core, u_negative_number);
  tcase_add_test(tcase_core, u_with_zero);
  tcase_add_test(tcase_core, u_simple_test);
  tcase_add_test(tcase_core, left_justify);
  tcase_add_test(tcase_core, left_justify_plus_short);
  tcase_add_test(tcase_core, short_int_uns_oct_value);
  tcase_add_test(tcase_core, x_simple_test);
  tcase_add_test(tcase_core, X_simple_test);
  tcase_add_test(tcase_core, x_big_number);
  tcase_add_test(tcase_core, X_big_number);
  tcase_add_test(tcase_core, x_zero);
  tcase_add_test(tcase_core, X_zero);
  tcase_add_test(tcase_core, o_simple_test);
  tcase_add_test(tcase_core, o_before_eight);
  tcase_add_test(tcase_core, o_zero);
  tcase_add_test(tcase_core, o_big_number);
  tcase_add_test(tcase_core, o_width);
  tcase_add_test(tcase_core, x_width);
  tcase_add_test(tcase_core, l_o);
  tcase_add_test(tcase_core, l_x);
  tcase_add_test(tcase_core, e_simple_test);
  tcase_add_test(tcase_core, E_with_L);
  tcase_add_test(tcase_core, E_simple_test);
  tcase_add_test(tcase_core, g_simple_test);
  tcase_add_test(tcase_core, G_with_L);
  tcase_add_test(tcase_core, g_with_L);
  tcase_add_test(tcase_core, G_simple_test);
  tcase_add_test(tcase_core, ptr);
  tcase_add_test(tcase_core, null_ptr);
  tcase_add_test(tcase_core, ptr_precision);
  tcase_add_test(tcase_core, many_spec);
  tcase_add_test(tcase_core, with_shift);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
