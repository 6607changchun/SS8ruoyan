/*******************************************************************************
* FileName:         LinkList.cpp
* Author:           Your_Name
* Student Number:   3019244xxx
* Date:             2020/02/26 11:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #2
*                   ä½œä¸šåœ¨è¿™ä¸ªæ–‡ä»¶ä¸­å®Œæˆï¼Œéœ€è¦è¡¥å…¨LinkListç±»çš„å®ç°ï¼Œ
*                   å†™æ˜å¿…è¦çš„æ³¨é‡Š
*******************************************************************************/

#include "LinkList.h"

LinkList::LinkList(){
	len = 0;
	head = 0;
}

LinkList::~LinkList(){
	int k = 0;
	while(k < len){
		node * p = head;
		head = p -> next;
		p -> next = 0;
		delete p;
		k++;
	}
}

int LinkList::length() const{
	return len;
}

int LinkList::getData(const int& location) const{
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

void LinkList::insert(const int& data, const int& location){
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
	//ÒÑ¶¨Î»ÖÁLocationµÄÇ°Ò»Î»
	 q -> next = p -> next;
	 p -> next = q;
	 len++;
}

bool LinkList::remove(const int& location){
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
	while(p != 0 && k < location - 1){
		p = p -> next;
		k++;
	}
	//ºÏ·¨Î»ÖÃ 
	if(p != 0 && p -> next != 0){
		node *q = p -> next;
		p -> next = q -> next;
		q -> next = 0;
		delete q;
		len--;
		return 1;
	}
	return 0;
}

void LinkList::converse(){
	node * head2 = 0;
	int k = 0;
	node * p = head;
	//Á´±íÖØ¹¹ 
	while(k < len){
		node * newNode = new node;
		newNode -> value = p ->value;
		newNode -> next = head2;
		head2 = newNode;
		k++;
		p = p -> next;
	}
	//Çå¿ÕÔ­ÓĞÁ´±í 
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

void LinkList::append(const LinkList& append_list){
    int l = append_list.length();
    int k = 0;
	while(k < l){
		insert(append_list.getData(k),len);	
		k++;}
}
