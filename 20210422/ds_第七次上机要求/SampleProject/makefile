CC = g++
CFLAGS = -O -Wall -m64 -std=gnu11
LIBS = -lm


HuffmanProgram: main.cpp Huffman.o
	$(CC) main.cpp Huffman.o -o HuffmanProgram

Huffman.o: Huffman.h Huffman.cpp
	$(CC) -c Huffman.h Huffman.cpp

clean:
	rm *.o *.gch HuffmanProgram