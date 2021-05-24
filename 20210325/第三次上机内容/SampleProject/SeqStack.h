/*******************************************************************************
* FileName:         SeqStack.h
* Author:           田原
* Student Number:   3015218126
* Date:             2020/03/20 11:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #4
*                   这个是助教完成的 SeqList.h 文件，请不要更改里面的内容
*******************************************************************************/
#ifndef SEQSTACK_H
#define SEQSTACK_H

#include "MyStack.h"

class SeqStack: public MyStack{
    private:
        const static int MAX_ELEMENTS = 100;
        int* SeqList;   // 顺序栈
        int data_top;    // 栈顶
    public:
        SeqStack();
        virtual ~SeqStack(); 
        void push_back(int data);
        int top() const;
        void pop();
};

#endif