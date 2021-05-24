CC = g++
CFLAGS = -O -Wall -m64 -std=gnu11
LIBS = -lm


GraphProgram: main.cpp Graph.o
	$(CC) main.cpp Graph.o -o GraphProgram

Graph.o: Graph.h Graph.cpp
	$(CC) -c Graph.h Graph.cpp

clean:
	rm *.o *.gch GraphProgram
