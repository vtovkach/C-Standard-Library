main: main.o my_string.o
	gcc main.o my_string.o -o main

main.o: main.c
	gcc -c main.c -o main.o

my_string.o: my_string.c 
	gcc -c my_string.c -o my_string.o

clean:
	rm *.o main
