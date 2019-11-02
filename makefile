ifeq ($(DEBUG).true)
	CC = gcc -g
else
	CC = gcc
all: Song_Node.h main.c
	$(CC) -o exec main.o Song_Node.o

run:
	./exec

main.o: main.c Song_Node.h
	$(CC) -c main.c

Song_Node.o: Song_Node.c Song_Node.h
	$(CC) -c Song_Node.c Song_Node.h

clean:
	rm *.o program
