/*******************************************************************************
* FileName:         MyStack.h
* Author:           田原
* Student Number:   3015218126
* Date:             2020/03/03 11:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #4
*                   这个是助教完成的 MyStack.h 文件，请不要更改里面的内容
*******************************************************************************/

#ifndef MYSTACK_H
#define MYSTACK_H

class MyStack{
    private:
    public:
        MyStack() {}
        virtual ~MyStack(){}

        /**
            入栈函数，将data插入到栈的最后一个。
            @name vritual void push_back(int);
            @param arg1 需要插入的数据
            @return void
        */
        virtual void push_back(int data) = 0;
        /**
            获得栈顶元素 如果栈空则返回 0
            @name virtual datatype top() const;
            @return datatype 返回栈顶元素
        */
        virtual int top() const = 0;
        
        /**
            将栈顶元素弹出。如果没有元素直接返回
            @name virtual void pop();
            @return void
        */
        virtual void pop() = 0;
};

#endif    //MYSTACK_H