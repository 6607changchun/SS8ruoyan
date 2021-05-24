#include <cstdio>
#include <iostream>

#include "MyStack.h"
#include "SeqStack.h"
#include "LinkStack.h"

using std::cin;
using std::cout;
using std::endl;

// complie commond: g++ main.cpp LinkStack.cpp LinkStack.h MyStack.h MyStack.cpp SeqStack.h SeqStack.cpp -o StackProgram

int main()
{
	MyStack *stk = new SeqStack;

	stk->push_back(1);
	stk->push_back(2);
	stk->push_back(4);
	// stack: 1 2 4

	if(stk -> top() == 4) cout << "pass check point 1!" << endl;
	stk->pop();
	if(stk -> top() == 2) cout << "pass check point 2!" << endl;
	stk->pop();
	if(stk -> top() == 1) cout << "pass check point 3!" << endl;


	delete stk;
	stk = new LinkStack;
	stk->push_back(1);
	stk->push_back(2);
	stk->push_back(4);
	// stack: 1 2 4

	if(stk -> top() == 4) cout << "pass check point 4!" << endl;
	stk->pop();
	if(stk -> top() == 2) cout << "pass check point 5!" << endl;
	stk->pop();
	if(stk -> top() == 1) cout << "pass check point 6!" << endl;


	return 0;
}