CC = g++
CFLAGS = -O -Wall -m64 -std=gnu11
LIBS = -lm

StackPro: main.cpp LinkList.o
	$(CC) main.cpp LinkList.o -o LinkProgram

LinkList.o: LinkList.h LinkList.cpp
	$(CC) -c LinkList.h LinkList.cpp

clean:
	rm *.o *.gch LinkProgram
