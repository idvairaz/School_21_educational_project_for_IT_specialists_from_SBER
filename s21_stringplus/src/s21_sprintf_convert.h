#ifndef SPRINTF_CONVERT_H
#define SPRINTF_CONVERT_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void s21_ushorttostring(unsigned short number, char** str);
void s21_longuinttostring(unsigned long number, char** str);
void s21_longinttostring(long long int number, char** str);
void s21_doubletostring(double number, char** str, int fillZero, int maxO,
                        int precision, int sharp, int e, int longD,
                        long double numberLong);
void s21_longdoubletostring(long double number, char** str, int fillZero,
                            int maxO);
void s21_uinttostring(unsigned int number, char** str);
void s21_intostring(int number, char** str);
void s21_convertpointertostring(char* str, void* pointer);
void s21_insertcharatindex(char** str, int index, char ch);
void s21_converttoo(unsigned int number, char** str);
void s21_convertox(unsigned int number, char** str, int XSpec);
int s21_infinitycheck(double number, char** str);

/*Внутренние функции*/

void s21_getintegerstring(double number, char** numString, int lf);
int s21_getfloatafterdotstring(long double number, char** floatString,
                               int fillZero, int maxO, int precision, int e);
int s21_convertdoublestringtoprecision(int precison, char* str);
int s21_countnine(char* str, int i);
void s21_get_double_string_before_dot(long double number, char** str);

#endif
