#include <iostream>
#include <cstdio>

#include "Graph.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Graph g(5);

    g.addedge(1, 2, 10);
    g.addedge(1, 3, 10);
    g.addedge(1, 4, 10);
    g.addedge(1, 5, 10);
    g.addedge(2, 3, 1);

    if(g.prim() == 31) cout << "pass check point 1!" << endl;
	if(g.kruskal() == 31) cout << "pass check point 2!" << endl;
    return 0;
}
