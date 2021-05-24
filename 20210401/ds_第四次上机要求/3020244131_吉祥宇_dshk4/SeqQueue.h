/*******************************************************************************
* FileName:         SeqStack.h
* Author:           your_name
* Student Number:   3019244xxx
* Date:             2020/03/11 11:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #5
*                   待完成的SeqQueue.h文件
*******************************************************************************/

#ifndef SEQQUEUE_H
#define SEQQUEUE_H

#include "MyQueue.h"

class SeqQueue: public MyQueue{
private:
	const int MAX_SIZE = 1000;
	int first;
	int back;
	int * queue;
public:
    SeqQueue();
    virtual ~SeqQueue();
    void pop_front();
    void push_back(int data);
    int front() const;
};
#endif
