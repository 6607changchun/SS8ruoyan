/*******************************************************************************
* FileName:         SeqQueue.h
* Author:           your_name
* Student Number:   3019244xxx
* Date:             2020/03/11 11:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #5
*                   需要完成的SeqQeuue.h，
*******************************************************************************/

#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include "MyQueue.h"

class LinkQueue: public MyQueue{
private:
	struct node{
		int value;
		node* next;
	};
	node * head;
	node * last;
	int length;
public:
    LinkQueue();
    virtual ~LinkQueue();
    void push_back(int data);
    void pop_front();
    int front() const;
};

#endif
