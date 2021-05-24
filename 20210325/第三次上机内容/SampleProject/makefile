CC = g++
CFLAGS = -O -Wall -m64 -std=gnu11
LIBS = -lm

StackPro: main.cpp MyStack.o SeqStack.o LinkStack.o
	$(CC) main.cpp MyStack.o SeqStack.o LinkStack.o -o StackProgram

MyStack.o: MyStack.h MyStack.cpp
	$(CC) -c MyStack.h MyStack.cpp

SeqStack.o: SeqStack.h SeqStack.cpp
	$(CC) -c SeqStack.h SeqStack.cpp

LinkStack.o: LinkStack.h LinkStack.cpp
	$(CC) -c LinkStack.h LinkStack.cpp

clean:
	rm *.o *.gch StackProgram
