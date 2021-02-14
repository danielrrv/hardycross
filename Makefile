CC = gcc


default: main.o file.o
	$(CC) main.o file.o $(CFLAGS) -std=c11 -Wall -Werror -o output

main.o: main.c 
	$(CC) -c main.c 
file.o: file.c 
	$(CC) -c file.c

clean:
	rm output *.o 2> /dev/null