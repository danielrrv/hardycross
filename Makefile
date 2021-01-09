CC = cc


default: main.o
	$(CC) main.o -std=c11 -Wall -Werror  -o output.o

main.o: main.c

clean:
	rm *.out *.o 2> /dev/null