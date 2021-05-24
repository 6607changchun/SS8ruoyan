#include "LinkQueue.h"

LinkQueue::LinkQueue(){
	head = 0;
	length = 0;
	last = 0;
}

LinkQueue::~LinkQueue(){
	while(head != 0){
		node *p = head;
		head = head -> next;
		delete p;
		length--;
	}
	last = 0;
}

void LinkQueue::push_back(int data){
	node * newNode = new node;
	newNode -> value = data;
	if(!length){
		head = newNode;
		last = newNode;
	}
	else{
		last -> next = newNode;
		last = last -> next;
	}
	length++;
}

void LinkQueue::pop_front(){
	if(length == 0) return;
	if(length == 1){
		delete head;
		head = 0;
		last = 0;
		length--;
		return;
	}
	node *p = head;
	head = head -> next;
	p -> next = 0;
	delete p;
	length--;
}


int LinkQueue::front() const{
	if(!length) return -1;
	return head -> value;
}
