CFLAGS=-Wall -Wextra -Werror
 
s21_cat : 
	cd src/cat && $(MAKE)

s21_grep : 
	cd src/grep && $(MAKE)

clean : 
	cd src/cat && $(MAKE) clean
	cd src/grep && $(MAKE) clean

rebuild : clean s21_cat s21_grep