NAME=s21_string

AUTORS=latinato@student.21-school.ru \
saandahl@student.21-school.ru \
armenale@student.21-school.ru \
leffordk@student.21-school.ru \
pennytrg@student.21-school.ru

DATE=26/02/2024

CFLAGS=-Wall -Wextra -Werror -std=c11
TESTFLAGS= -lcheck -lsubunit -lm
LIB=s21_insert.c s21_memchr.c s21_memcmp.c s21_memcpy.c s21_memmove.c s21_memset.c s21_sprintf.c \
 s21_sprintf_convert.c s21_strrchr.c s21_sscanf.c s21_strcat.c s21_strchr.c  s21_strcmp.c \
 s21_strcpy.c s21_strcspn.c s21_strerror.c s21_strlen.c s21_strncat.c s21_strncmp.c s21_strncpy.c \
 s21_strpbrk.c s21_strstr.c s21_strtok.c s21_to_lower.c s21_to_upper.c s21_trim.c

all: clean s21_string.a

test: s21_string.a
	gcc $(CFLAGS) -c ./test/*.c s21_main.c 
	gcc $(CFLAGS) s21_main.c ./test/*.c -o main -L. -l:s21_string.a $(TESTFLAGS) 
	./main

gcov_report:
	gcc $(CFLAGS) -c ./test/*.c *.c 
	gcc $(CFLAGS) ./test/*.c *.c -o main $(TESTFLAGS) -coverage
	./main
	find . -type f -name "*test.g*" -exec rm {} \; -o -name "*main.g*" -exec rm {} \;
	find . -type f -name "*sprintf_convert.g*" -exec rm {} \;
	find . -type f -name "*memmove.g*" -exec rm {} \; -o -name "*strcat.g*" -exec rm {} \;
	find . -type f -name "*strcmp.g*" -exec rm {} \;
	# mkdir html_report
	# python3 -m gcovr -r . --html --html-details -o html_report/coverage_report.html --exclude test   
	# open html_report/coverage_report.html 
	lcov -t "report" -o report.info -c -d .
	genhtml -o report report.info

s21_string.a: 
	gcc $(CFLAGS) -c $(LIB)
	ar rcs s21_string.a *.o 
	ranlib s21_string.a

clang:
	cp ./../materials/linters/.clang-format ./
	clang-format -i *.c *.h test/*.c test/*.h
	rm -f .clang-format

control: 
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all -s ./main


rebuild: clean all

clean: 
	rm -f *.o *.a *.gcda *.gcno *.info main
	rm -rf html_report 
	rm -rf report