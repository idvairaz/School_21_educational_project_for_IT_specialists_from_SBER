SHELL = /bin/sh

# Linux, Darwin or Windows_NT
OS=$(shell uname -s)

CC=gcc
ifeq ($(OS),Darwin)
FLAGS=-Wall -Wextra -std=c11 -Werror
else
FLAGS=-Wall -Wextra -std=c11 -Werror -lm
endif

CFLAGS:=$(FLAGS)
GCOV:=$(FLAGS) -coverage
SRC=$(wildcard *.c)
TEST_SRC=$(wildcard tests/*.c)
OBJS=$(patsubst %.c,%.o,$(TEST_SRC))
TEST_OBJS=$(patsubst %.c,%.o,$(TEST_SRC))
DComp=Comparison/*.c
DConv=Transformation/*.c
DAdd=Additional/*.c
DArith=Arithmetic/*.c
DO=Other/*.c

.PHONY: all clean test gcov_report control run ext1_flag ext2_flag base_flag clang

all: clean s21_decimal.a

clean:
	-rm -rf *.out *.o *.gcno *.gcda *.info report/ s21_decimal.a ./test_s21_decimal tests/*.o

test: $(TEST_OBJS) s21_decimal.a
ifeq ($(OS),Darwin)
	$(CC) $(CFLAGS) $^ -o test_s21_decimal -lcheck -L/opt/homebrew/lib -L.
else
	$(CC) $(CFLAGS) $^ -o test_s21_decimal -lcheck -lm -lsubunit -L.
endif
	-make run

$(TEST_OBJS): $(TEST_SRC) tests/test_s21_decimal.h

s21_decimal.a:
	$(CC) $(CFLAGS) -c $(DComp) $(DConv) $(DArith) $(DO)
	$(CC) $(FLAGS) -c $(DAdd)
	ar r s21_decimal.a *.o
	ranlib s21_decimal.a

gcov_report: clean ext1_flag s21_decimal.a base_flag $(TEST_OBJS) ext2_flag test
	lcov -t "s21_decimal_report" -o s21_decimal_report.info -c -d .
	genhtml -o report s21_decimal_report.info
	open report/index.html

control:
	-cppcheck --error-exitcode=1 --enable=all --suppress=missingIncludeSystem --error-exitcode=1 *.c *.h tests/*.c tests/*.h Additional/*.c Arithmetic/*.c Comparison/*.c Transformation/*.c Other/*.c
	-find . -type f \( -name "*.c" -o -name "*.h" \) -exec clang-format -n {} \;
	-cd ../materials/build/ && ./run.sh
	-valgrind --tool=memcheck --leak-check=yes ./test_s21_decimal

run:
	-./test_s21_decimal

ext1_flag:
	$(eval CFLAGS:=$(GCOV))
ext2_flag:
	$(eval CFLAGS:=$(GCOV))
base_flag:
	$(eval CFLAGS:=$(FLAGS))

clang:
	find . -type f \( -name "*.c" -o -name "*.h" \) -exec clang-format -i {} \;