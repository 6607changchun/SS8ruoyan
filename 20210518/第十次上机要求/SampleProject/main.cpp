#include <iostream>
#include <cstdio>
#include <cmath>
#include "Graph.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Graph g(5);

    g.addedge(1, 2, 10);
    g.addedge(1, 3, 10);
    g.addedge(2, 3, 10);
    g.addedge(3, 1, 10);

    int len = g.getV();
    if(len == 3){
        cout << "Pass check point 1!" << endl;
    }

    // 在这里进行了10次PR迭代
    for(int i = 0; i < 10; i++){
        g.PRIter();
    }
	
    if(fabs(g.getPR(1) - 1.076923) < 1e-3)
        cout << "Pass check point 2!" << endl;

    if(fabs(g.getPR(2) - 0.76923077) < 1e-3)
        cout << "Pass check point 2!" << endl;

    if(fabs(g.getPR(3) - 1.15384615) < 1e-3)
        cout << "Pass check point 2!" << endl;

    return 0;
}
