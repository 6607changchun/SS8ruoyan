/*******************************************************************************
* FileName:         LinkStack.cpp
* Author:           Your_Name
* Student Number:   3019244xxx
* Date:             2020/03/04 11:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #4
*******************************************************************************/


#include "LinkStack.h"


LinkStack::LinkStack(){
	length = 0;
	head = 0;
}
LinkStack::~LinkStack(){
	int cnt = 0;
	int len = length;
	StackNode *p = head;
	while(cnt<len){
		StackNode *q = p;
		p = p -> next;
		delete q;
		cnt++;
	}
}

void LinkStack::push_back(int data){
	StackNode *newNode = new StackNode;
	newNode -> value = data;
	newNode -> next = head;
	head = newNode;
	length++;
}

int LinkStack::top() const{
	if(!length) return -1;
	return head->value;
}

void LinkStack::pop(){
	if(!length) return;
	StackNode *p = head;
	head = head -> next;
	p -> next = 0;
	delete p;
	length--;
}
