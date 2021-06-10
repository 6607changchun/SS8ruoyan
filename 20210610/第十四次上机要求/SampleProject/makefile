CC = g++
CFLAGS = -O -Wall -m64 -std=gnu11
LIBS = -lm


HashProgram: main.cpp MyHash.o
	$(CC) main.cpp MyHash.o -o HashProgram

MyHash.o: MyHash.h MyHash.cpp
	$(CC) -c MyHash.h MyHash.cpp

clean:
	rm *.o *.gch HashProgram
