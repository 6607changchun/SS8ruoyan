/*******************************************************************************
* FileName:         MyQueue.h
* Author:           田原
* Student Number:   3015218126
* Date:             2020/03/11 11:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #5
*                   这个是助教完成的 MyQueue.h 文件，请不要更改里面的内容
*******************************************************************************/

#ifndef MYQUEUE_H
#define MYQUEUE_H

class MyQueue{
private:

public:
    MyQueue(){}
    virtual ~MyQueue(){}
    /**
    插入队列，将data插入到队尾。
    @name vritual void push_back(dpname&);
    @param arg1 需要插入的数据
    @return void
    */
    virtual void push_back(int data) = 0;


    /**
    获得队首元素 如果队列空则返回 0
    @name virtual dpname front() const;
    @return datatype 返回栈顶元素
    */
    virtual int front() const = 0;


    /**
    队首元素出队。如果队列为空直接return。
    @name virtual void pop_front();
    @return void
    */
    virtual void pop_front() = 0;
};

#endif
