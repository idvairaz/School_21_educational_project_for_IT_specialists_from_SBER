NAME=s21_matrix

AUTORS=pennytrg@student.21-school.ru

DATE=06/03/2024

CFLAGS=-Wall -Wextra -Werror -std=c11
TESTFLAGS=-lcheck -lsubunit -lm
FILES=*.c ./lib/functions/*.c *.h ./tests/*.c ./tests/*.h ./additional/*.c ./additional/*.h

all: clean s21_matrix.a

test: s21_matrix.a
	gcc $(CFLAGS) -c tests/*.c s21_main.c 
	gcc $(CFLAGS) s21_main.c tests/*.c -o main -L. -l:s21_matrix.a $(TESTFLAGS) 
	./main

gcov_report:
	gcc $(CFLAGS) -c ./tests/*.c ./additional/*.c s21_main.c 
	gcc $(CFLAGS) ./lib/functions/*.c ./tests/*.c ./additional/*.c *.c -o main $(TESTFLAGS) -coverage
	./main
	find . -type f -name "*test.g*" -exec rm {} \; -o -name "*main.g*" -exec rm {} \;
	find . -type f -name "*additional.g*" -exec rm {} \;
	# mkdir html_report
	# python3 -m gcovr -r . --html --html-details -o html_report/coverage_report.html --exclude test   
	# open html_report/coverage_report.html 
	# lcov --rc lcov_branch_coverage=1 -t "report" -o report.info -c -d .
	# genhtml --rc lcov_branch_coverage=1 -o report report.info
	lcov --rc lcov_branch_coverage=1 -t "report" -o report.info -c -d .
	genhtml --rc lcov_branch_coverage=1 -o report report.info
	open report/index.html

s21_matrix.a: 
	gcc $(CFLAGS) -c lib/functions/*.c additional/*.c
	ar rcs s21_matrix.a *.o 
	ranlib s21_matrix.a

clang:
	cp ./../materials/linters/.clang-format ./
	clang-format -i $(FILES)
	rm -f .clang-format

control:
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all -s ./main
	-cppcheck --error-exitcode=1 --enable=all --suppress=missingIncludeSystem --error-exitcode=1 ./lib/functions/*.c ./tests/*.c ./additional/*.c *.c

docker:
	cd ../materials/build/ && sudo ./run.sh

rebuild: clean all

clean: 
	rm -f *.o *.a *.gcda *.gcno *.info main s21_main
	rm -rf html_report 
	rm -rf report