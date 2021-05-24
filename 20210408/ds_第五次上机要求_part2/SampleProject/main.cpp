#include <iostream>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;

#include "SPMatrix.h"


int main()
{
    SPMatrix mat1(1000, 1000);
    SPMatrix mat2(1000, 1000);

    mat1.set(1, 2, 10);
    mat1.set(2, 3, 4);

    mat2.set(1, 2, 20);
    mat2.set(1, 5, 30);
    mat2.set(2, 3, 1);
    SPMatrix mat3 = mat1 + mat2;
    if(mat3.get(1, 2) == 30)  cout << "pass check point 1!" << endl;
    if(mat1.get(1, 2) == 10)  cout << "pass check point 2!" << endl;
    if(mat3.get(1, 5) == 30)  cout << "pass check point 3!" << endl;


    SPMatrix mat4 = mat1 - mat2;

    if(mat4.get(2, 3) == 3) cout << "pass check point 4!" << endl;
    if(mat4.get(1, 5) == -30) cout << "pass check point 5!" << endl;

    mat1.rotate();
    if(mat1.get(2, 1) == 10)  cout << "pass check point 6!" << endl;
    
    return 0;
}
