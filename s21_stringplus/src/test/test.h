#ifndef test_h
#define test_h

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void run_testcase(Suite* testscase, int counter_testcase);
void run_tests();

Suite* s21_memchr_suite(void);
Suite* s21_memcmp_suite(void);
Suite* s21_memcpy_suite(void);
Suite* s21_memset_suite(void);
Suite* s21_strncat_suite(void);
Suite* s21_strchr_suite(void);
Suite* s21_strncmp_suite(void);
Suite* s21_strncpy_suite(void);
Suite* s21_strcspn_suite(void);
Suite* s21_strlen_suite(void);
Suite* s21_sprintf_suite(void);
Suite* s21_to_upper_suite(void);
Suite* s21_to_lower_suite(void);
Suite* s21_insert_suite(void);
Suite* s21_trim_suite(void);
Suite* s21_strpbrk_suite(void);
Suite* s21_strrchr_suite(void);
Suite* s21_strerror_suite(void);
Suite* s21_strstr_suite(void);
Suite* s21_strtok_suite(void);
Suite* s21_sscanf_suite(void);

#endif  // test_h