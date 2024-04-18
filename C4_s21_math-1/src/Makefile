CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -std=c11 
OBJ_DIR = objects/
SOURCE = $(wildcard lib/*.c common/*.c) # get list all *.c
OBJECT = $(patsubst %.c, %.o, $(SOURCE))  # replace .c -> .o (making object files)
SOURCE_TEST = $(wildcard tests/*.c)
SOURCE_LIBRARY = $(filter-out s21_test.c, $(filter-out test%, $(SOURCE)))
OBJECT_LIBRARY = $(patsubst %.c, %.o, $(SOURCE_LIBRARY))
EXECUTABLE = s21_test
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	CFLAGS += -DLinux
	GFLAGS = -lcheck -lm -lsubunit
	RM_COMMAND = rm -rf test*.gcda test*.gcno
endif

ifeq ($(UNAME), Darwin)
	CFLAGS += -DDarwin
	GFLAGS = -I/opt/homebrew/include -L/opt/homebrew/lib -lcheck -lm
	RM_COMMAND = rm test*.gcda test*.gcno
endif

.PHONY: all s21_math.a test gcov_report style clang clean rebuild valgrind_test cppcheck_test


s21_math.a: clean $(OBJECT_LIBRARY)
	@ar rc s21_math.a $(OBJECT_LIBRARY)
	@ranlib s21_math.a
	@rm -rf *.o lib/*.o common/*.o

all: clean s21_math.a test gcov_report

test: clean s21_math.a
	@$(CC) $(CFLAGS) $(SOURCE_TEST) s21_math.a -o $(EXECUTABLE) $(GFLAGS)
	@./$(EXECUTABLE)

gcov_report: clean
	@$(CC) $(CFLAGS) $(SOURCE) $(SOURCE_TEST) -o $(EXECUTABLE) $(GFLAGS) --coverage 
	@./$(EXECUTABLE)
	@lcov -t "s21_tests" -o s21_tests.info -c -d . -rc lcov_branch_coverage=1 --exclude "$(PWD)/tests/*"
	@genhtml -o report s21_tests.info -rc lcov_branch_coverage=1
	@rm -rf *.gcno *.gcda *.gcov

style: clean
	@find . -type f \( -name "*.c" -o -name "*.h" \) -exec clang-format -n -style=file:../materials/linters/.clang-format {} \;

clang:
	@find . -type f \( -name "*.c" -o -name "*.h" \) -exec clang-format -i -style=file:../materials/linters/.clang-format {} \;


clean:
	@rm -f lib/*.o common/*.o *.o *.a *.gcno *.gcda *.info $(EXECUTABLE) valgrind_out.txt main
	@rm -rf report $(OBJ_DIR)

rebuild: clean s21_math.a test

valgrind_test: rebuild
	valgrind -s -q --tool=memcheck --leak-check=yes --track-origins=yes --show-leak-kinds=all --verbose --log-file=valgrind_out.txt ./$(EXECUTABLE)

cppcheck_test:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h tests/*.c tests/*.h common/*.c lib/*.c
