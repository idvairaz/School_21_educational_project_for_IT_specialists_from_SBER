CFLAGS=-Wall -Wextra -Werror
 
s21_cat : cat.o
	gcc -o s21_cat cat.o

cat.o :  
	gcc $(CFLAGS) -c cat.c 

clean : 
	rm -f *.o s21_cat 1 2 3

rebuild : clean s21_cat
