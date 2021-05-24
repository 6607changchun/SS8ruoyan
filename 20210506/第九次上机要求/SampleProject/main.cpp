#include <iostream>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;

#include "Graph.h"


int main()
{
    Graph G(10000);


    if(G.access(1, 10000) == -1) cout << "Pass check point 1!" << endl;

    G.addedge(1, 100, 20);
    if(G.access(1, 100) == 20) cout << "Pass check point 2!" << endl;


    G.addedge(1, 20, 3);
    G.addedge(2, 20, 13);
    G.addedge(3, 20, 30);
    G.addedge(4, 20, 33);
    if(G.getInDegree(1) == 0) cout << "Pass check point 3!" << endl;
    if(G.getInDegree(20) == 4) cout << "Pass check point 4!" << endl;
    if(G.getOutDegree(1) == 2) cout << "Pass check point 5!" << endl;
    if(G.getOutDegree(5) == 0) cout << "Pass check point 6!" << endl;
    if(G.getDist(1, 20) == 1) cout << "Pass check point 7!" << endl;

    return 0;
}
