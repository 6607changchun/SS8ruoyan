CC = g++
CFLAGS = -O -Wall -m64 -std=gnu11
LIBS = -lm


BinTreeProgram: main.cpp BinTree.o
	$(CC) main.cpp BinTree.o -o BinTreeProgram

BinTree.o: BinTree.h BinTree.cpp
	$(CC) -c BinTree.h BinTree.cpp

clean:
	rm *.o *.gch BinTreeProgram
