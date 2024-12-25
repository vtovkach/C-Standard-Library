test: test.o my_ctype.o
	gcc test.o my_ctype.o -o test

test.o: test.c
	gcc -c test.c -o test.o

my_ctype.o: my_ctype.c
	gcc -c my_ctype.c -o my_ctype.o

clean:
	rm *.o test