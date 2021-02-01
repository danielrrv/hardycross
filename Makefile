CC = gcc


output: main.o
	$(CC) main.o $(CFLAGS) -std=c11 -Wall -Werror -o output

main.o: main.c
	#$(CC) -c main.c

clean:
	rm output *.o 2> /dev/null