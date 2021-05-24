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
    g.addedge(3, 4, 1);
    g.addedge(4, 5, 1);

    int len = g.getV();
    int *arr = g.topological();

    int r_arr[5] = {1, 2, 3, 4, 5};
    
    if(len == 5){
        cout << "Pass check point 1!" << endl;
    }

    int i;
    for(i = 0; i < len; i++){
        if(arr[i] != r_arr[i]) break;
    }
    if(i == len) cout << "Pass check point 2!" << endl;

    delete arr;
    arr = g.ka();

    for(i = 0; i < len; i++){
        if(arr[i] != r_arr[i]) break;
    }
    if(i == len) cout << "Pass check point 3!" << endl;

    return 0;
}
