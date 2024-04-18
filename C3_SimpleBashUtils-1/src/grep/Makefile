CFLAGS=-Wall -Wextra -Werror
 
s21_grep : grep.o
	gcc -o s21_grep grep.o
	
grep.o :  
	gcc $(CFLAGS) -c grep.c 

clean : 
	rm -f *.o s21_grep 1 2 3

rebuild : clean s21_grep