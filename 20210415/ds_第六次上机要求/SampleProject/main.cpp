#include <iostream>
#include <cstdio>

#include "BinTree.h"

using namespace std;

bool judge_array(const int* a, const int* b, int len){
    for(int i = 0; i < len; i++){
        if(a[i] != b[i]) return false;
    }
    return true;
}


int main()
{
    int *p;
    p = new int[10];
    int *p_tra, *m_tra;
    BinTree bst;
    bst.insert(2, 0, 0);
    
    p_tra = bst.p_traversal();
    m_tra = bst.m_traversal();
    p[0] = 2;
    if(judge_array(p, p_tra, 1)) cout << "pass check point 1!" << endl;
    if(judge_array(p, m_tra, 1)) cout << "pass check point 2!" << endl;

    delete []p_tra;
    delete []m_tra;

    bst.insert(3, 1, 1);
    bst.insert(1, 1, -1);
    p_tra = bst.p_traversal();
    m_tra = bst.m_traversal();
    p[0] = 2;
    p[1] = 1;
    p[2] = 3;
    if(judge_array(p, p_tra, 3)) cout << "pass check point 3!" << endl;
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    if(judge_array(p, m_tra, 3)) cout << "pass check point 4!" << endl;


    if(bst.height() == 2) cout << "pass check point 5!" << endl;
    if(bst.countNode() == 3) cout << "pass check point 6!" << endl;
    delete []p_tra;
    delete []m_tra;
    delete []p;

    return 0;
}
