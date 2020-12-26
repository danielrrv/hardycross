CC = g++

default: main.o
	$(CC) main.o -o output

main.o: main.c

clean:
	rm *.out *.o 2> /dev/null