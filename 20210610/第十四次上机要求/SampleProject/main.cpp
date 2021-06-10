#include <iostream>
#include <cstdio>
#include "myHash.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	MyHash hashtable(1000);


	hashtable.setvalue(19244121, 6);
	hashtable.setvalue(19244122, 7);
	hashtable.setvalue(19244123, 8);
	hashtable.setvalue(19244124, 9);

	if(hashtable.getvalue(19244121) == 6) cout << "Pass check point 1!" << endl;
	if(hashtable.getvalue(19244122) == 7) cout << "Pass check point 2!" << endl;
	if(hashtable.getvalue(19244123) == 8) cout << "Pass check point 3!" << endl;
	if(hashtable.getvalue(19244124) == 9) cout << "Pass check point 4!" << endl;


	hashtable.setvalue(19260817, 10);
	if(hashtable.getvalue(19260817) == 10) cout << "Pass check point 5!" << endl;
	hashtable.setvalue(19260817, 11);
	if(hashtable.getvalue(19260817) == 11) cout << "Pass check point 6!" << endl;

    return 0;
}