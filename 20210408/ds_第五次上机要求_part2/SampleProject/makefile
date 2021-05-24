CC = g++
CFLAGS = -O -Wall -m64 -std=gnu11
LIBS = -lm


SPMatrixProgram: main.cpp SPMatrix.o
	$(CC) main.cpp SPMatrix.o -o SPMatrixProgram

SPMatrix.o: SPMatrix.h SPMatrix.cpp
	$(CC) -c SPMatrix.h SPMatrix.cpp

clean:
	rm *.o *.gch SPMatrixProgram
