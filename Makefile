CC = gcc


default: main.o
	$(CC) main.o $(CFLAGS) -std=c11 -Wall -Werror  -o output.o

main.o: main.c

clean:
	rm -f *.out *.o 2> /dev/null