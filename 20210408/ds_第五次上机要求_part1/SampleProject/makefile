CC = g++
CFLAGS = -O -Wall -m64 -std=gnu11
LIBS = -lm


DBLPro: main.cpp MyString.o
	$(CC) main.cpp MyString.o -o MyStringPro

MyString.o: MyString.h MyString.cpp
	$(CC) -c MyString.h MyString.cpp

clean:
	rm *.o *.gch MyStringPro
