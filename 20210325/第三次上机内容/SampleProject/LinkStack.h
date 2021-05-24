/*******************************************************************************
* FileName:         LinkStack.h
* Author:           田原
* Student Number:   3015218126
* Date:             2020/03/03 11:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #4
*******************************************************************************/
#ifndef LINKSTACK_H
#define LINKSTACK_H

#include "MyStack.h"

class LinkStack: public MyStack{
    private:
    struct StackNode{
        StackNode* next;
        int value;
    };
    StackNode* head;
    int length;
    public:
        LinkStack();
        virtual ~LinkStack(); 
        void push_back(int data);
        int top() const;
        void pop();
};

#endif