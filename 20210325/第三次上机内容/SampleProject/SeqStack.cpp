/*******************************************************************************
* FileName:         SeqStack.cpp
* Author:           Your_Name
* Student Number:   3019244xxx
* Date:             2020/03/04 11:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #4
*******************************************************************************/
#include "SeqStack.h"

SeqStack::SeqStack(){
	SeqList = new int[MAX_ELEMENTS];
	data_top = 0;
}
SeqStack::~SeqStack(){
	delete[] SeqList; 
}
void SeqStack::push_back(int data){
	if(data_top > MAX_ELEMENTS) return;
	SeqList[data_top++] = data;
}
int SeqStack::top() const{
	if(data_top) return SeqList[data_top-1];
	else return -1;
}
void SeqStack::pop(){
	if(!data_top) return;
	SeqList[--data_top] = 0;
}
