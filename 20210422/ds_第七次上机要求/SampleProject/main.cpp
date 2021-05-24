#include <iostream>
#include <cstdio>
#include<cstring>
#include "Huffman.h"
using namespace std;

int main()
{
    int table[26];
    memset(table, 0, sizeof(table));
    table[0] = 4;
    table[1] = 2;
    table[2] = 1;
    HuffmanTree hf(table);
    if(hf.Encode("abc") == "10100") cout << "pass check point 1!" << endl;
    
	if(hf.Decode("10100") == "abc") cout << "pass check point 2!" << endl;
//	cout<<"success\n";
    return 0;
}
