CC = g++
CFLAGS = -O -Wall -m64 -std=gnu11
LIBS = -lm

StackPro: main.cpp SeqList.o
	$(CC) main.cpp SeqList.o -o SeqProgram

SeqList.o: SeqList.h SeqList.cpp
	$(CC) -c SeqList.h SeqList.cpp

clean:
	rm *.o *.gch StackPro
