CFLAGS := -I inc -std=c11 -Wall -Werror -Wextra
OBJS := brick_game/tetris/*.c gui/cli/*.c  
FILES := $(shell find . -name '*.c' -o -name '*.h' | grep -v 'inc/type.h')
TESTFLAGS=-lcheck -lsubunit -lm
INSTALL_DIR ?= ~/dir_for_tetris



all: make_for_pir  run
	
run:
	./tetris

make_for_pir:	
	$(CC) $(CFLAGS) -o tetris $(OBJS) s21_tetris.c -lncurses

mac:
	$(CC) $(CFLAGS) -o tetris $(OBJS) s21_tetris.c -lncurses -DMACOS
	./tetris

install: 
	mkdir -p $(INSTALL_DIR)
	$(CC) $(CFLAGS) -o $(INSTALL_DIR)/tetris $(OBJS) s21_tetris.c -lncurses
	$(INSTALL_DIR)/tetris

uninstall:
	rm -rf $(INSTALL_DIR)

dvi: 
	doxygen Doxyfile
	open doc_doxygen/html/index.html

dist: clean make_for_pir 
	tar -cvzf tetris.tar.gz tetris

test: clean tetris.a
	$(CC) $(CFLAGS) -c  tests/*.c
	$(CC) $(CFLAGS) tests/*.c -o run_test -L. -l:tetris.a $(TESTFLAGS) -lncurses
	./run_test

tetris.a: 
	$(CC) $(CFLAGS) -c  $(OBJS)
	ar rcs tetris.a *.o 
	ranlib tetris.a

gcov_report: 
	$(CC) $(CFLAGS) -c  $(OBJS) tests/*.c
	$(CC) $(CFLAGS) tests/*.c $(OBJS) -o run_test  $(TESTFLAGS) -lncurses -coverage
	./run_test
	find . -type f -name "*test.g*" -exec rm {} \; 
	find . -type f -name "*front.g*" -exec rm {} \;
	find . -type f -name "*signal.g*" -exec rm {} \;

	# mkdir html_report
	# python3 -m gcovr -r . --html --html-details -o html_report/coverage_report.html --exclude test   
	# open html_report/coverage_report.html 
	# lcov --rc lcov_branch_coverage=1 -t "report" -o report.info -c -d .
	# genhtml --rc lcov_branch_coverage=1 -o report report.info
	lcov -t "report" -o report.info -c -d .
	genhtml -o report report.info
	open report/index.html

clang:
	cp ./../materials/linters/.clang-format ./
	clang-format -i $(FILES)
	rm -f .clang-format

control: make_for_pir
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all -s ./tetris 
	-cppcheck --error-exitcode=1 --enable=all --suppress=missingIncludeSystem --error-exitcode=1  brick_game/tetris/*.c  gui/cli/*.c *.c 


rebuild: clean all 


clean: 
	$(RM) tetris *.o *.a *.gcda *.gcno *.info run_test high_score.txt *.gz
	rm -rf html_report 
	rm -rf report
	rm -rf latex 
	rm -rf doc_doxygen

