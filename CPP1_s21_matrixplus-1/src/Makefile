CFLAGS = -std=c++17 -Wall -Wextra -Werror -lm -lstdc++
BIBL = lib/*.cpp
TEST_DIR = $(shell find tests -name '*.cpp')
STYLEFILE = $(shell find ../src -name '*.cpp' -o -name  '*.h')
TESTFLAGS = -lgtest -lgcov -lpthread -Bstatic -lm -Bdynamic

all: clean test

s21_matrix_oop.a: clean
	$(CC) $(CFLAGS) -c $(BIBL)
	ar rcs s21_matrix_oop.a *.o
	ranlib s21_matrix_oop.a

test: clean s21_matrix_oop.a
	$(CC) -c $(TEST_DIR) $(CFLAGS)
	$(CC) $(TEST_DIR) -o test -L. -l:s21_matrix_oop.a $(CFLAGS)  $(TESTFLAGS)
	./test

gcov_report: clean
	$(CC) $(TEST_DIR) $(BIBL) -o test $(TESTFLAGS) $(CFLAGS) -coverage
	./test

	# mkdir html_report
	# python3 -m gcovr -r . --html --html-details -o html_report/coverage_report.html --exclude test   
	# open html_report/coverage_report.html 
	# lcov --rc lcov_branch_coverage=1 -t "report" -o report.info -c -d .
	# genhtml --rc lcov_branch_coverage=1 -o report report.info
	lcov -t "report" -o report.info -c --directory . --exclude */tests/* --exclude */usr/include/*
	genhtml -o report report.info
	open report/index.html


clang:
	clang-format-18 -style="{BasedOnStyle: Google}" -i $(STYLEFILE)

control: test
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all -s ./test
	-cppcheck --error-exitcode=1 --enable=all --suppress=missingIncludeSystem --error-exitcode=1  lib/*.cpp tests/*.cpp

rebuild: clean all

clean:
	$(RM) test *.o *.a *.gcda *.gcno *.info
	rm -rf html_report 
	rm -rf report
	rm -rf latex 
	rm -rf doc_doxygen


