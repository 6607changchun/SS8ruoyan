#include <cstdio>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#include "MyQueue.h"
#include "SeqQueue.h"
#include "LinkQueue.h"

int main()
{
    
    MyQueue* que = new LinkQueue();
    que -> push_back(1);
    que -> push_back(2);
    que -> push_back(6);

    if(que -> front() == 1) cout << "pass check point 1!" << endl;
    que -> pop_front();

    if(que -> front() == 2) cout << "pass check point 2!" << endl;
    que -> pop_front();

    if(que -> front() == 6) cout << "pass check point 3!" << endl;
    que -> pop_front();

    delete que;

    que = new SeqQueue();
    que -> push_back(1);
    que -> push_back(2);
    que -> push_back(6);


    if(que -> front() == 1) cout << "pass check point 4!" << endl;
    que -> pop_front();

    if(que -> front() == 2) cout << "pass check point 5!" << endl;
    que -> pop_front();

    if(que -> front() == 6) cout << "pass check point 6!" << endl;
    que -> pop_front();
	delete que;
    return 0;
}
