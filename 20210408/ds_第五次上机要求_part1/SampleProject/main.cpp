#include <iostream>
#include<cstring>
#include "MyString.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	MyString a("hello world");

	if(strcmp(a.c_string(), "hello world") == 0) cout << "pass check point 1!" << endl;
	
	if(a.find("l") == 2) cout << "pass check point 2!" << endl;

	a.replace("data structure", 6);
	if(strcmp(a.c_string(), "hello data structure") == 0) cout << "pass check point 3!" << endl;

	if(a.length() == 20) cout << "pass check point 4!" << endl;
	return 0;
}
