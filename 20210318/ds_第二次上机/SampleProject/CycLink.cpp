/*******************************************************************************
* FileName:         CycLink.cpp
* Author:           Your_Name
* Student Number:   3019244xxx
* Date:             2020/02/26 11:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #2
*                   作业在这个文件中完成，需要补全CycLink类的实现，
*                   写明必要的注释
*******************************************************************************/

#include "CycLink.h"

CycLink::CycLink(){
	len = 0;
	head = 0;
}

CycLink::~CycLink(){
	int k = 0;
	while(k < len){
		node * p = head;
		head = p -> next;
		p -> next = 0;
		delete p;
		k++;
	}
}

int CycLink::length() const{
	return len;
}

int CycLink::getData(const int& location) const{
	if(!location) return head -> value;
	node* p = head;
	int k = 0;
	while(p != 0 && k < location - 1){
		p = p -> next;
		k++;
	}
	if(p != 0 || p -> next != 0)
		return (p -> next) -> value;
	else return -1;
}

void CycLink::insert(const int& data, const int& location){
	if(len == 1){
		head -> next = head;
	}
	node* q = new node;
	q -> value = data;
	if(!location){
		q -> next = head;
		head = q;
		len++;
		return;
	}
	node* p = head;
	int k = 0;
	while(k < location - 1){
		p = p -> next;
		k++;
	}
	//�Ѷ�λ��Location��ǰһλ
	 q -> next = p -> next;
	 p -> next = q;
	 len++;
}

bool CycLink::remove(const int& location){
	if(!location){
		node * q = head;
		head = head -> next;
		q -> next = 0;
		delete q;
		len--;
		return 1;
	}
	node * p = head;
	int k = 0;
	//�Ϸ�λ�� 
	if(location >= len) return 0;
	while(p != 0 && k < location - 1){
		p = p -> next;
		k++;
	}
	node *q = p -> next;
	p -> next = q -> next;
	q -> next = 0;
	delete q;
	len--;
	return 1;
}

void CycLink::converse(){
	node * head2 = 0;
	int k = 0;
	node * p = head;
	//�����ع� 
	while(k < len){
		node * newNode = new node;
		newNode -> value = p ->value;
		newNode -> next = head2;
		head2 = newNode;
		k++;
		p = p -> next;
	}
	//���ԭ������ 
	k = 0;
	while(k < len){
		p = head;
		head = p -> next;
		p -> next = 0;
		delete p;
		k++;
	}
	head = head2;
}

void CycLink::append(const CycLink& append_list){
    int l = append_list.length();
    int k = 0;
	while(k < l){
		insert(append_list.getData(k),len);	
		k++;}
}
