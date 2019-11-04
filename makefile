ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

all: Song_Node.o main.o Song_Lib.o
	$(CC) -o exec main.o Song_Node.o Song_Lib.o

run:
	./exec

main.o: main.c Song_Node.h Song_Lib.h
	$(CC) -c main.c

Song_Node.o: Song_Node.c Song_Node.h
	$(CC) -c Song_Node.c Song_Node.h
	
Song_Lib.o: Song_Lib.c Song_Lib.h
	$(CC) -c Song_Lib.c Song_Lib.h

clean:
	rm *.o exec
