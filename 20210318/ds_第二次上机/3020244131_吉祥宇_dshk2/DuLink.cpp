/*******************************************************************************
* FileName:         DuLink.cpp
* Author:           Your_Name
* Student Number:   3019244xxx
* Date:             2020/02/26 11:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #2
*                   ä½œä¸šåœ¨è¿™ä¸ªæ–‡ä»¶ä¸­å®Œæˆï¼Œéœ€è¦è¡¥å…¨DuLinkç±»çš„å®ç°ï¼Œ
*                   å†™æ˜å¿…è¦çš„æ³¨é‡Š
*******************************************************************************/

#include "DuLink.h"
#include<iostream>

DuLink::DuLink(){
	len = 0;
	head = 0;
}

DuLink::~DuLink(){
	int k = 0;
	while(k < len){
		node * p = head;
		head = p -> next;
		p -> next = 0;
		delete p;
		k++;
	}
}

int DuLink::length() const{
	return len;
}

int DuLink::getData(const int& location) const{
	if(!location) return head -> value;
	node* p = head;
	int k = 0;
	while(p != 0 && k < location - 1){
		p = p -> next;
		k++;
	}
	if(p != 0 && p -> next != 0){
//		std::cout<<"pvalue:"<<p -> value <<std::endl;
		return (p -> next) -> value;
	}
	else return -1;
}

void DuLink::insert(const int& data, const int& location){
	//std::cout<<"location:"<<location<<" data:"<<data<<std::endl;
	node* q = new node;
	q -> value = data;
	//Í·½áµã 
	if(len == 0){
		q -> prev = 0;
		q -> next = 0;
		head = q;
		len++;
		return;
	}
	if(!location){
		q -> prev = 0;
		q -> next = head;
		head -> prev = q;
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
//	std::cout<<"p:"<<p -> value<<std::endl;
	//ÒÑ¶¨Î»ÖÁLocationµÄÇ°Ò»Î»
	//Î²²åÈë 
	if(k == len - 1){
		q -> next = 0;
		q -> prev = p;
		p -> next = q;
		len++;
		return;
	}
	q -> next = p -> next;
	q -> prev = p;
	(p -> next) -> prev = q;
	p -> next = q;
	len++;
}

bool DuLink::remove(const int& location){
	//ºÏ·¨Î»ÖÃ 
	if(location >= len || location < 0) return false;
	//Í·½áµã 
	if(!location){
		node * q = head;
		(head -> next) -> prev = 0;
		head = head -> next;
		q -> next = 0;
		delete q;
		len--; 
		return true;
	}
	
	node * p = head;
	int k = 0;
	
	while(p != 0 && k < location - 1){
		p = p -> next;
		k++;
	}
	//¶¨Î»ÖÁLocation-1Î» 
	node * q = p -> next;
	//Î²É¾³ı
	if(k == len - 2){
		p -> next = 0;
		q -> prev = 0;
		delete q;
		len--;
		return true;
	} 
	p -> next = q -> next;
	(q -> next) -> prev = q -> prev;
	q -> next = 0;
	q -> prev = 0;
	delete q;
	len--;
	return true;
}

void DuLink::converse(){
	if(len == 1 || len == 0) return;
	//ÖØ¹¹ 
	node * head2 = 0;
	int k = 0;
	node * p = head;
	while(k < len){
		node * newNode = new node;
		newNode -> value = p -> value;
		if(k == 0){
			head2 = newNode;
			newNode -> prev = 0;
			newNode -> next = 0;
		}
		else{
			newNode -> next = head2;
			newNode -> prev = 0;
			head2 -> prev = newNode;
			head2 = newNode;
		}
		k++;
		p = p -> next;
	}
	//Çå¿ÕÔ­ÓĞÁ´±í 
	k = 0;
	p = head;
	while(k < len - 1){
		node * q = p;
		p = p -> next;
		q -> next = 0;
		p -> prev = 0;
		delete q;
		k++;
	}
	delete p;
	head = head2;
}

void DuLink::append(const DuLink& append_list){
    int l = append_list.length();
    int k = 0;
	while(k < l){
		insert(append_list.getData(k),len);	
		k++;}
}
