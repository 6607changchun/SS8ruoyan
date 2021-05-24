/*******************************************************************************
* FileName:         Haffman.cpp
* Author:           Your_name
* Student Number:   Student_Number
* Date:             2020/04/08 09:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #10
*******************************************************************************/

#include "Huffman.h"
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

bool operator<(const HuffmanTree::cmpnode& a, const HuffmanTree::cmpnode& b){
	int af = a.fre;
	int bf = b.fre;
	if(af <= bf) return true;
	else return false;
}
HuffmanTree::HuffmanTree(const int* Table){
	for(int i = 0;i < 26;i++){
		if(!Table[i]) continue;
		node * t = new node;
		t->left = 0;
		t->right = 0;
		t->parent = 0;
		t->message = "";
		nodes[nnum] = t;
		nnum++;
		cmpnode* temp = new cmpnode;
		cmpnode tc = *temp;
		tc.rawnode = t;
		tc.fre = Table[i];
		cmpnodes[cnum] = tc;
		cnum++;
	}
//		std::cout<<"i:"<<i<<"cmpnodes:"<<cmpnodes[i].fre<<std::endl;
	initnum = nnum;
	for(int i = 1;i <= initnum-1;i++){
		std::sort(cmpnodes,cmpnodes+cnum);
//		std::cout<<"i:"<<i<<std::endl;
//		for(int i = 0;i < cnum;i++){
//			std::cout<<"fre:"<<cmpnodes[i].fre<<std::endl;
//			std::cout<<cmpnodes[i].rawnode -> parent<<std::endl;
//		}
		int j = 0;
		while((cmpnodes[j].rawnode)->parent)
			j++;
		int k = j+1;
		while((cmpnodes[k].rawnode)->parent)
			k++;
		node* min1 = cmpnodes[j].rawnode;
		node* min2 = cmpnodes[k].rawnode;
		node* newNode = new node;
		newNode->left = min1;
		newNode->right = min2;
		newNode->parent = 0;
		newNode->message = "";
		min1->parent = newNode;
		min2->parent = newNode;
		nodes[nnum] = newNode;
		nnum++;
		cmpnode* newCmpt = new cmpnode;
		cmpnode newCmp = *newCmpt;
		newCmp.rawnode = newNode;
		newCmp.fre = cmpnodes[j].fre + cmpnodes[k].fre;
		cmpnodes[cnum] = newCmp;
		cnum++;
	}
	for(int i = 0;i < nnum;i++)
		if(!nodes[i]->parent){
			root = nodes[i];
			break;
		}
//	std::cout<<"success\n";
	visit(root);
}

HuffmanTree::~HuffmanTree(){
	for(int i = 0;i < nnum;i++)
		delete nodes[i];
	for(int i = 0;i < cnum;i++)
		delete &cmpnodes[i];
}
void HuffmanTree::visit(node* root){
	
//	std::cout<<"root:"<<root<<std::endl;
//	std::cout<<"message:"<<root->message<<std::endl;
//	std::cout<<"left:"<<root->left<<std::endl;
//	std::cout<<"right:"<<root->right<<std::endl;
	if(!root->left&&!root->right){
//		std::cout<<"success"<<initnum<<std::endl;
//		std::cout<<nodes[i]<<std::endl;
		for(int i = 0;i < initnum;i++){
			if(nodes[i] == root)
				cset[i] = root->message;
			
//				std::cout<<"i:"<<i<<" cset:"<<cset[i]<<std::endl;
		}
		return;
	}
	if(root->left){
		string pending = "0";
//		char pending[] = "0";
//		char s[40];
//		int l;
//		for(l = 0;l < root->message.length();l++)
//			s[l] = (root->message)[l];
//		s[++l] = '\0';
		(root->left)->message = root->message+pending;
		visit(root->left);
	} 
	if(root->right){
		string pending = "1";
//		char s[40];
//		int l;
//		for(l = 0;l < root->message.length();l++)
//			s[l] = (root->message)[l];
//		s[++l] = '\0';
		(root->right)->message = root->message+pending;
		visit(root->right);
	} 
	
}
string HuffmanTree::Encode(string mess){
//	std::cout<<"success\n";
	string result = "";
	for(int i = 0;i < mess.length();i++){
		result = result.append(cset[mess[i]-'a']);
	}
//	for(int i = 0;i < initnum;i++){
//		std::cout<<(char)(i+'a')<<" "<<cset[i]<<std::endl;
//	}
//	std::cout<<result<<std::endl;
	return result;
}

string HuffmanTree::Decode(string message){
	string result = "";
	while(!message.empty()){
		for(int i = 0;i < initnum;i++){
			if(!message.find(cset[i])){
				char s[] = {i+'a','\0'};
				result.append(s);
				message = message.substr(cset[i].length());
				break;
			}
//		std::cout<<"message:"<<message<<"\n";
		}
	}
	return result;
}
