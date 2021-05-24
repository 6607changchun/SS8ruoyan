#include "SeqQueue.h"

SeqQueue::SeqQueue(){
	first = 0;
	back = 0;
	queue = new int[MAX_SIZE];
}
SeqQueue::~SeqQueue(){
	delete[] queue;
}
void SeqQueue::pop_front(){
	if(first == back) return;
	first = (first+1)%MAX_SIZE;
}
void SeqQueue::push_back(int data){
	if((back+1)%MAX_SIZE == first) return;
	queue[back] = data;
	back = (back+1)%MAX_SIZE;
}
int SeqQueue::front() const{
	if(first == back) return -1;
	return queue[first];
}
