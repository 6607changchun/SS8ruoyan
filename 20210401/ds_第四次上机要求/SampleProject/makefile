CC = g++
CFLAGS = -O -Wall -m64 -std=gnu11
LIBS = -lm

QueueProgram: main.cpp MyQueue.o SeqQueue.o LinkQueue.o
	$(CC) main.cpp MyQueue.o SeqQueue.o LinkQueue.o -o QueueProgram

MyQueue.o: MyQueue.h MyQueue.cpp
	$(CC) -c MyQueue.h MyQueue.cpp

SeqQueue.o: SeqQueue.h SeqQueue.cpp
	$(CC) -c SeqQueue.h SeqQueue.cpp

LinkQueue.o: LinkQueue.h LinkQueue.cpp
	$(CC) -c LinkQueue.h LinkQueue.cpp

clean:
	rm *.o *.gch QueueProgram
