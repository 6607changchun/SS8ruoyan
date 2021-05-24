#include <cstdio>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;


#include "SeqList.h"

// complie commond: g++ main.cpp main.cpp SeqList.h SeqList.cpp -o SeqProgram

int main()
{
	// empty list
	SeqList mylist(100);

	// list -> [20, 43, 50]

	// insert(20, 0)  [20];   s.length() = 1
	// insert(21, 0)  [21, 20];  s.length() = 2;

	mylist.insert(20, 0);
	mylist.insert(43, 1);
	mylist.insert(50, 2);
//	mylist.insert(50, 3);

	if(mylist.getData(0) == 20) cout << "pass check point 1!" << endl;
	if(mylist.getData(1) == 43) cout << "pass check point 2!" << endl;
	if(mylist.getData(2) == 50) cout << "pass check point 3!" << endl;

	if(mylist.length() == 3) cout << "pass check point 4!" << endl;


	//因为只能remove  0-2的元素，所以是false
	if(mylist.remove(3) == false) cout << "pass check point 5!" << endl; 
	if(mylist.remove(1) == true) cout << "pass check point 6!" << endl; 

	if(mylist.length() == 2 && mylist.getData(0) == 20 && mylist.getData(1) == 50)  cout << "pass check point 7!" << endl;

	if(mylist.isIn(20) && mylist.isIn(50) && !mylist.isIn(43)) cout << "pass check point 8!" << endl;
	return 0;
}
